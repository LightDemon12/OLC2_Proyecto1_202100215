#include "../../Headers/Procesador_Declaraciones.h"
#include "../../Headers/mainview.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int process_declaracion_node(NodeProcessorContext* context, ASTNode* node) {
    if (!context || !node) {
        printf("ERROR PROCESADOR_DECLARACIONES: Contexto o nodo NULL\n");
        return 1;
    }

    if (context->modo_debug) {
        printf("DEBUG PROCESADOR_DECLARACIONES: Procesando '%s' en línea %d (hijos: %d)\n",
               node->type, node->line, node->child_count);
    }

    if (node->child_count < 2) {
        printf("DEBUG PROCESADOR_DECLARACIONES: Nodo con pocos hijos (%d), saltando\n",
               node->child_count);
        return 0;
    }

    // El primer hijo siempre es TIPO
    ASTNode* tipo_nodo = node->children[0];
    if (!tipo_nodo || !tipo_nodo->value) {
        printf("ERROR PROCESADOR_DECLARACIONES: Nodo tipo inválido\n");
        return 1;
    }

    const char* tipo_str = tipo_nodo->value;
    TipoDato tipo_dato = string_to_tipo_dato(tipo_str);
    if (tipo_dato == TIPO_DESCONOCIDO) {
        printf("ERROR PROCESADOR_DECLARACIONES: Tipo de dato desconocido '%s'\n", tipo_str);
        return 1;
    }

    if (context->modo_debug) {
        printf("DEBUG PROCESADOR_DECLARACIONES: Tipo detectado: '%s'\n", tipo_str);
    }

    // Delegar según el tipo específico de declaración
    if (strcmp(node->type, "DECLARACION_MULTIPLE") == 0) {
        return process_declaracion_multiple(context, tipo_dato, node->children[1], node);
    }
    else if (strcmp(node->type, "DECLARACION_CON_INICIALIZACION") == 0) {
        return process_declaracion_con_inicializacion(context, tipo_dato,
                                                     node->children[1], node->children[2], node);
    }
    else if (strcmp(node->type, "DECLARACION_SIN_INICIALIZACION") == 0) {
        return process_declaracion_sin_inicializacion(context, tipo_dato, node->children[1], node);
    }
    else {
        printf("ERROR PROCESADOR_DECLARACIONES: Tipo desconocido: '%s'\n", node->type);
        return 1;
    }
}

int process_declaracion_con_inicializacion(NodeProcessorContext* context, TipoDato tipo, 
                                          ASTNode* id_nodo, ASTNode* valor_nodo, ASTNode* parent) {
    if (!id_nodo || !id_nodo->value) {
        printf("ERROR PROCESADOR_DECLARACIONES: Identificador inválido\n");
        return 1;
    }

    const char* id_str = id_nodo->value;

    if (context->modo_debug) {
        printf("DEBUG PROCESADOR_DECLARACIONES: Declaración con inicialización - id:'%s', tipo:'%s'\n",
               id_str, tipo_dato_to_string(tipo));
    }

    // Crear símbolo
    Simbolo simbolo = crear_simbolo_default(id_str, SIMBOLO_VARIABLE, tipo);
    simbolo.linea = parent->line;
    simbolo.columna = parent->column;
    simbolo.visibilidad = VIS_PUBLIC;
    simbolo.inicializado = 1;
    simbolo.timestamp_creacion = time(NULL);

    // Extraer valor de la expresión
    char* valor_extraido = extract_dato_value(valor_nodo);
    if (valor_extraido) {
        strncpy(simbolo.valor, valor_extraido, MAX_VALUE_LENGTH - 1);
        simbolo.valor[MAX_VALUE_LENGTH - 1] = '\0';
        free(valor_extraido);
    } else {
        strncpy(simbolo.valor, "expresion_compleja", MAX_VALUE_LENGTH - 1);
    }

    // Insertar en tabla de símbolos
    if (!insertar_simbolo(context->tabla_simbolos, simbolo)) {
        printf("ERROR PROCESADOR_DECLARACIONES: No se pudo insertar símbolo '%s'\n", id_str);
        return 1;
    }

    if (context->modo_debug) {
        printf("DEBUG PROCESADOR_DECLARACIONES:   Variable '%s' = '%s' agregada exitosamente\n",
               simbolo.id, simbolo.valor);
    }

    return 0;
}

int process_declaracion_sin_inicializacion(NodeProcessorContext* context, TipoDato tipo, 
                                          ASTNode* id_nodo, ASTNode* parent) {
    if (!id_nodo || !id_nodo->value) {
        printf("ERROR PROCESADOR_DECLARACIONES: Identificador inválido\n");
        return 1;
    }

    const char* id_str = id_nodo->value;

    if (context->modo_debug) {
        printf("DEBUG PROCESADOR_DECLARACIONES: Declaración sin inicialización - id:'%s', tipo:'%s'\n",
               id_str, tipo_dato_to_string(tipo));
    }

    // Crear símbolo sin valor inicial
    Simbolo simbolo = crear_simbolo_default(id_str, SIMBOLO_VARIABLE, tipo);
    simbolo.linea = parent->line;
    simbolo.columna = parent->column;
    simbolo.visibilidad = VIS_PUBLIC;
    simbolo.inicializado = 0;  // No inicializado
    simbolo.timestamp_creacion = time(NULL);

    // Valor por defecto según el tipo
    switch (tipo) {
        case TIPO_INT:
        case TIPO_FLOAT:
        case TIPO_DOUBLE:
            strncpy(simbolo.valor, "0", MAX_VALUE_LENGTH - 1);
            break;
        case TIPO_BOOLEAN:
            strncpy(simbolo.valor, "false", MAX_VALUE_LENGTH - 1);
            break;
        case TIPO_CHAR:
            strncpy(simbolo.valor, "\\0", MAX_VALUE_LENGTH - 1);
            break;
        case TIPO_STRING:
            strncpy(simbolo.valor, "null", MAX_VALUE_LENGTH - 1);
            break;
        default:
            strncpy(simbolo.valor, "undefined", MAX_VALUE_LENGTH - 1);
            break;
    }

    // Insertar en tabla de símbolos
    if (!insertar_simbolo(context->tabla_simbolos, simbolo)) {
        printf("ERROR PROCESADOR_DECLARACIONES: No se pudo insertar símbolo '%s'\n", id_str);
        return 1;
    }

    if (context->modo_debug) {
        printf("DEBUG PROCESADOR_DECLARACIONES:   Variable '%s' (sin inicializar) agregada\n", simbolo.id);
    }

    return 0;
}

int process_declaracion_multiple(NodeProcessorContext* context, TipoDato tipo,
                                ASTNode* lista_nodo, ASTNode* parent) {
    if (!lista_nodo || lista_nodo->child_count == 0) {
        printf("ERROR PROCESADOR_DECLARACIONES: Lista de declaraciones inválida\n");
        return 1;
    }

    if (context->modo_debug) {
        printf("DEBUG PROCESADOR_DECLARACIONES: Declaración múltiple - tipo:'%s', elementos:%d\n",
               tipo_dato_to_string(tipo), lista_nodo->child_count);
    }

    // Procesar cada elemento de la lista
    for (int i = 0; i < lista_nodo->child_count; i++) {
        ASTNode* elemento = lista_nodo->children[i];
        if (!elemento) continue;

        // Cada elemento puede ser:
        // - IDENTIFICADOR (sin inicialización)
        // - ASIGNACION_ELEMENTO (con inicialización: id = valor)

        if (strcmp(elemento->type, "IDENTIFIER") == 0) {
            // Declaración sin inicialización: int a, b, c;
            if (process_declaracion_sin_inicializacion(context, tipo, elemento, parent) != 0) {
                return 1;
            }
        }
        else if (strstr(elemento->type, "ASIGNACION") != NULL || elemento->child_count >= 2) {
            // Declaración con inicialización: int a = 1, b = 2;
            if (elemento->child_count >= 2) {
                if (process_declaracion_con_inicializacion(context, tipo,
                                                          elemento->children[0],
                                                          elemento->children[1], parent) != 0) {
                    return 1;
                }
            }
        }
        else {
            printf("DEBUG PROCESADOR_DECLARACIONES: Elemento desconocido en lista: '%s'\n",
                   elemento->type);
        }
    }

    if (context->modo_debug) {
        printf("DEBUG PROCESADOR_DECLARACIONES:   Declaración múltiple procesada exitosamente\n");
    }

    return 0;
}

char* extract_dato_value(ASTNode* node) {
    if (!node) return NULL;

    // Si el nodo tiene un valor directo
    if (node->value) {
        char* resultado = malloc(strlen(node->value) + 1);
        strcpy(resultado, node->value);
        return resultado;
    }

    // Si es un nodo DATO que contiene literales
    if (strcmp(node->type, "DATO") == 0 && node->child_count > 0) {
        ASTNode* literal = node->children[0];
        if (literal && literal->value) {
            char* resultado = malloc(strlen(literal->value) + 1);
            strcpy(resultado, literal->value);
            return resultado;
        }
    }

    return NULL;
}