#include "../../../Headers/Procesador_Declaraciones.h"
#include "../../../Headers/Procesador_Suma.h"  // ← IMPORTANTE: Para usar las funciones mejoradas
#include "../../../Headers/node_processor.h"
#include "../../../Headers/mainview.h"
#include "../../../Headers/globals.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "node_utils.h"
#include "Procesador_casting.h"

// ========== ELIMINAR LAS FUNCIONES DUPLICADAS Y USAR LAS DEL PROCESADOR SUMA ==========



int process_declaracion_node(NodeProcessorContext* context, ASTNode* node) {
    if (!context || !node) {
        procesador_error_output(context, "Contexto o nodo NULL en declaracion");
        return 1;
    }

    char debug_msg[256];
    snprintf(debug_msg, sizeof(debug_msg), "Procesando declaracion '%s' en linea %d (hijos: %d)",
            node->type, node->line, node->child_count);
    procesador_debug_output(context, debug_msg);

    if (node->child_count < 2) {
        snprintf(debug_msg, sizeof(debug_msg), "Nodo con pocos hijos (%d), saltando", node->child_count);
        procesador_debug_output(context, debug_msg);
        return 0;
    }

    // El primer hijo siempre es TIPO
    ASTNode* tipo_nodo = node->children[0];
    if (!tipo_nodo || !tipo_nodo->value) {
        procesador_error_output(context, "Nodo tipo invalido");
        return 1;
    }

    const char* tipo_str = tipo_nodo->value;
    TipoDato tipo_dato = string_to_tipo_dato(tipo_str);
    if (tipo_dato == TIPO_DESCONOCIDO) {
        snprintf(debug_msg, sizeof(debug_msg), "Tipo de dato desconocido '%s'", tipo_str);
        procesador_error_output(context, debug_msg);
        return 1;
    }

    snprintf(debug_msg, sizeof(debug_msg), "🔍 ANÁLISIS SEMÁNTICO: Tipo detectado '%s'", tipo_str);
    procesador_debug_output(context, debug_msg);

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
        snprintf(debug_msg, sizeof(debug_msg), "Tipo desconocido: '%s'", node->type);
        procesador_error_output(context, debug_msg);
        return 1;
    }
}

int process_declaracion_con_inicializacion(NodeProcessorContext* context, TipoDato tipo,
                                          ASTNode* id_nodo, ASTNode* valor_nodo, ASTNode* parent) {
    if (!id_nodo || !id_nodo->value) {
        procesador_error_output(context, "Identificador invalido");
        return 1;
    }

    const char* id_str = id_nodo->value;

    char debug_msg[256];
    snprintf(debug_msg, sizeof(debug_msg),
            "🔢 ANÁLISIS SEMÁNTICO: Declarando '%s' tipo '%s' en scope '%s'",
            id_str, tipo_dato_to_string(tipo),
            context->scope_actual ? context->scope_actual->nombre : "GLOBAL");
    procesador_debug_output(context, debug_msg);

    // ===== VERIFICAR REDECLARACIÓN =====
    if (context->tabla_simbolos) {
        Simbolo* simbolo_existente = buscar_simbolo(context->tabla_simbolos, id_str);
        if (simbolo_existente) {
            char error_msg[512];
            snprintf(error_msg, sizeof(error_msg),
                    "Variable '%s' ya está declarada en el scope '%s' (línea %d)",
                    id_str, simbolo_existente->ambito, simbolo_existente->linea);

            const char* scope_actual = "global";
            if (context->scope_actual && context->scope_actual->nombre) {
                scope_actual = context->scope_actual->nombre;
            }

            if (global_error_manager) {
                error_manager_add_semantico(global_error_manager,
                                          parent->line, parent->column,
                                          error_msg, id_str, scope_actual);
            }

            procesador_error_output(context, error_msg);
            return 1;
        }
    }

    // ===== ANÁLISIS SEMÁNTICO DE TIPOS =====
    TipoDato tipo_valor = obtener_tipo_desde_nodo(valor_nodo, context);
    char* valor_extraido = obtener_valor_desde_nodo(valor_nodo, context);

    const char* valor_display = valor_extraido ? valor_extraido : "expresion_compleja";

    snprintf(debug_msg, sizeof(debug_msg),
            "🔍 TIPOS DETECTADOS: variable '%s'(%s) = valor '%s'(%s)",
            id_str, tipo_dato_to_string(tipo),
            valor_display, tipo_dato_to_string(tipo_valor));
    procesador_debug_output(context, debug_msg);

    // ===== VERIFICAR COMPATIBILIDAD CON PROMOCIÓN AUTOMÁTICA =====
    int es_compatible = 0;
    char* valor_final = valor_extraido;

    if (tipo == tipo_valor) {
        // Tipos exactamente iguales
        es_compatible = 1;
        snprintf(debug_msg, sizeof(debug_msg), "✅ TIPOS IDÉNTICOS - Asignación directa");
        procesador_debug_output(context, debug_msg);
    }
    else if (es_promocion_automatica(tipo_valor, tipo)) {
        // ===== PROMOCIÓN AUTOMÁTICA =====
        es_compatible = 1;

        snprintf(debug_msg, sizeof(debug_msg),
                "🔄 PROMOCIÓN AUTOMÁTICA: %s → %s",
                tipo_dato_to_string(tipo_valor), tipo_dato_to_string(tipo));
        procesador_debug_output(context, debug_msg);

        // Convertir el valor al nuevo formato
        if (valor_extraido) {
            char* valor_promovido = convertir_valor_cast(valor_extraido, tipo_valor, tipo);
            if (valor_promovido) {
                free(valor_extraido);
                valor_final = valor_promovido;

                snprintf(debug_msg, sizeof(debug_msg),
                        "📈 VALOR PROMOVIDO: '%s' → '%s'",
                        valor_display, valor_final);
                procesador_debug_output(context, debug_msg);
            }
        }
    }
    else if (tipos_compatibles_asignacion(tipo, tipo_valor)) {
        // Otras compatibilidades (como String concatenation)
        es_compatible = 1;
        snprintf(debug_msg, sizeof(debug_msg), "✅ TIPOS COMPATIBLES - Asignación válida");
        procesador_debug_output(context, debug_msg);
    }

    if (!es_compatible) {
        // ===== ERROR SEMÁNTICO: TIPOS INCOMPATIBLES =====
        char error_msg[512];
        snprintf(error_msg, sizeof(error_msg),
                "Asignación incompatible: no se puede asignar %s a variable %s de tipo %s",
                tipo_dato_to_string(tipo_valor), id_str, tipo_dato_to_string(tipo));

        const char* scope_actual = "global";
        if (context->scope_actual && context->scope_actual->nombre) {
            scope_actual = context->scope_actual->nombre;
        }

        if (global_error_manager) {
            error_manager_add_semantico(global_error_manager,
                                      parent->line, parent->column,
                                      error_msg, "=", scope_actual);
        }

        procesador_error_output(context, error_msg);
        if (valor_final) free(valor_final);
        return 1;
    }

    // ===== CREAR Y GUARDAR SÍMBOLO =====
    Simbolo simbolo = crear_simbolo_default(id_str, SIMBOLO_VARIABLE, tipo);
    simbolo.linea = parent->line;
    simbolo.columna = parent->column;
    simbolo.visibilidad = VIS_PUBLIC;
    simbolo.inicializado = 1;
    simbolo.timestamp_creacion = time(NULL);

    // Guardar el valor (promovido si fue necesario)
    if (valor_final) {
        strncpy(simbolo.valor, valor_final, MAX_VALUE_LENGTH - 1);
        simbolo.valor[MAX_VALUE_LENGTH - 1] = '\0';
        free(valor_final);
    } else {
        strncpy(simbolo.valor, "expresion_compleja", MAX_VALUE_LENGTH - 1);
    }

    // Insertar símbolo
    if (!insertar_simbolo_en_scope_combinado(context, simbolo)) {
        procesador_error_output(context, "Error interno: No se pudo insertar simbolo");
        return 1;
    }

    snprintf(debug_msg, sizeof(debug_msg),
            "✅ Variable '%s' = '%s' declarada exitosamente",
            simbolo.id, simbolo.valor);
    procesador_debug_output(context, debug_msg);

    return 0;
}

int process_declaracion_sin_inicializacion(NodeProcessorContext* context, TipoDato tipo,
                                          ASTNode* id_nodo, ASTNode* parent) {
    if (!id_nodo || !id_nodo->value) {
        procesador_error_output(context, "Identificador invalido");
        return 1;
    }

    const char* id_str = id_nodo->value;

    char debug_msg[256];
    snprintf(debug_msg, sizeof(debug_msg),
            "🔢 ANÁLISIS SEMÁNTICO: Declarando variable '%s' tipo '%s' con valor por defecto",
            id_str, tipo_dato_to_string(tipo));
    procesador_debug_output(context, debug_msg);

    // ===== VERIFICAR REDECLARACIÓN ANTES DE CONTINUAR =====
    if (context->tabla_simbolos) {
        Simbolo* simbolo_existente = buscar_simbolo(context->tabla_simbolos, id_str);
        if (simbolo_existente) {
            // ===== ERROR SEMÁNTICO: REDECLARACIÓN =====
            char error_msg[512];
            snprintf(error_msg, sizeof(error_msg),
                    "Variable '%s' ya está declarada en el scope '%s' (línea %d)",
                    id_str,
                    simbolo_existente->ambito,
                    simbolo_existente->linea);

            // OBTENER EL SCOPE ACTUAL
            const char* scope_actual = "global";
            if (context->scope_actual && context->scope_actual->nombre) {
                scope_actual = context->scope_actual->nombre;
            } else if (context->tabla_simbolos && context->tabla_simbolos->ambito_actual) {
                scope_actual = context->tabla_simbolos->ambito_actual;
            }

            // Registrar error semántico global
            if (global_error_manager) {
                error_manager_add_semantico(global_error_manager,
                                          parent->line, parent->column,
                                          error_msg, id_str,
                                          scope_actual);
            }

            procesador_error_output(context, error_msg);
            return 1; // Error semántico - no continuar
        }
    }

    // ===== CREAR SÍMBOLO CON VALOR POR DEFECTO =====
    Simbolo simbolo = crear_simbolo_default(id_str, SIMBOLO_VARIABLE, tipo);
    simbolo.linea = parent->line;
    simbolo.columna = parent->column;
    simbolo.visibilidad = VIS_PUBLIC;
    simbolo.inicializado = 1;  // ✅ CAMBIO: Sí está inicializado con valor por defecto
    simbolo.timestamp_creacion = time(NULL);

    // ===== VALORES POR DEFECTO CORREGIDOS DE JAVA =====
    const char* valor_defecto = NULL;
    switch (tipo) {
        case TIPO_BYTE:
        case TIPO_SHORT:
        case TIPO_INT:
        case TIPO_LONG:
            valor_defecto = "0";
            break;
        case TIPO_FLOAT:
            valor_defecto = "0.0f";  // ✅ CORREGIDO: float lleva 'f'
            break;
        case TIPO_DOUBLE:
            valor_defecto = "0.0";
            break;
        case TIPO_BOOLEAN:
            valor_defecto = "false";
            break;
        case TIPO_CHAR:
            valor_defecto = "'\\u0000'";  // ✅ CORREGIDO: formato de char
            break;
        case TIPO_STRING:
            valor_defecto = "null";
            break;
        default:
            valor_defecto = "null";
            break;
    }

    // Asignar valor por defecto
    strncpy(simbolo.valor, valor_defecto, MAX_VALUE_LENGTH - 1);
    simbolo.valor[MAX_VALUE_LENGTH - 1] = '\0';

    // ===== DEBUG DEL VALOR ASIGNADO =====
    snprintf(debug_msg, sizeof(debug_msg),
            "🏗️ VALOR POR DEFECTO: variable '%s' tipo '%s' = '%s'",
            id_str, tipo_dato_to_string(tipo), valor_defecto);
    procesador_debug_output(context, debug_msg);

    // Insertar símbolo
    if (!insertar_simbolo_en_scope_combinado(context, simbolo)) {
        // Si llegamos aquí es un error interno (no debería pasar por la verificación anterior)
        procesador_error_output(context, "Error interno: No se pudo insertar simbolo");
        return 1;
    }

    snprintf(debug_msg, sizeof(debug_msg),
            "✅ Variable '%s' = '%s' declarada exitosamente (valor por defecto)",
            simbolo.id, simbolo.valor);
    procesador_debug_output(context, debug_msg);

    return 0;
}

int process_declaracion_multiple(NodeProcessorContext* context, TipoDato tipo,
                                ASTNode* lista_nodo, ASTNode* parent) {
    if (!lista_nodo || lista_nodo->child_count == 0) {
        procesador_error_output(context, "Lista de declaraciones invalida");
        return 1;
    }

    char debug_msg[256];
    snprintf(debug_msg, sizeof(debug_msg),
            "🔢 ANÁLISIS SEMÁNTICO: Declaración múltiple - tipo:'%s', elementos:%d",
            tipo_dato_to_string(tipo), lista_nodo->child_count);
    procesador_debug_output(context, debug_msg);

    // Procesar cada elemento de la lista
    for (int i = 0; i < lista_nodo->child_count; i++) {
        ASTNode* elemento = lista_nodo->children[i];
        if (!elemento) continue;

        if (strcmp(elemento->type, "IDENTIFIER") == 0) {
            if (process_declaracion_sin_inicializacion(context, tipo, elemento, parent) != 0) {
                return 1;
            }
        }
        else if (strstr(elemento->type, "ASIGNACION") != NULL || elemento->child_count >= 2) {
            if (elemento->child_count >= 2) {
                if (process_declaracion_con_inicializacion(context, tipo,
                                                          elemento->children[0],
                                                          elemento->children[1], parent) != 0) {
                    return 1;
                }
            }
        }
        else {
            snprintf(debug_msg, sizeof(debug_msg),
                    "Elemento desconocido en lista: '%s'", elemento->type);
            procesador_debug_output(context, debug_msg);
        }
    }

    procesador_debug_output(context, "✅ Declaración múltiple procesada exitosamente");
    return 0;
}

// Función para verificar compatibilidad de tipos en asignación
int tipos_compatibles_asignacion(TipoDato tipo_variable, TipoDato tipo_valor) {
    // Tipos exactamente iguales
    if (tipo_variable == tipo_valor) {
        return 1;
    }

    // ===== NARROWING IMPLÍCITO DE LITERALES INT A TIPOS MENORES =====
    // En Java, se permite asignar literales int a byte/short si están en rango
    if (tipo_valor == TIPO_INT &&
        (tipo_variable == TIPO_BYTE || tipo_variable == TIPO_SHORT)) {
        return 1; // Permitir, pero verificar rango en el procesamiento
    }

    // Promociones automáticas permitidas en Java:
    // byte -> short -> int -> long -> float -> double
    // char -> int -> long -> float -> double

    // byte puede asignarse a short, int, long, float, double
    if (tipo_valor == TIPO_BYTE &&
        (tipo_variable == TIPO_SHORT || tipo_variable == TIPO_INT ||
         tipo_variable == TIPO_LONG || tipo_variable == TIPO_FLOAT ||
         tipo_variable == TIPO_DOUBLE)) {
        return 1;
    }

    // short puede asignarse a int, long, float, double
    if (tipo_valor == TIPO_SHORT &&
        (tipo_variable == TIPO_INT || tipo_variable == TIPO_LONG ||
         tipo_variable == TIPO_FLOAT || tipo_variable == TIPO_DOUBLE)) {
        return 1;
    }

    // char puede asignarse a int, long, float, double
    if (tipo_valor == TIPO_CHAR &&
        (tipo_variable == TIPO_INT || tipo_variable == TIPO_LONG ||
         tipo_variable == TIPO_FLOAT || tipo_variable == TIPO_DOUBLE)) {
        return 1;
    }

    // int puede asignarse a long, float, double
    if (tipo_valor == TIPO_INT &&
        (tipo_variable == TIPO_LONG || tipo_variable == TIPO_FLOAT ||
         tipo_variable == TIPO_DOUBLE)) {
        return 1;
    }

    // long puede asignarse a float, double
    if (tipo_valor == TIPO_LONG &&
        (tipo_variable == TIPO_FLOAT || tipo_variable == TIPO_DOUBLE)) {
        return 1;
    }

    // float puede asignarse a double
    if (tipo_valor == TIPO_FLOAT && tipo_variable == TIPO_DOUBLE) {
        return 1;
    }

    // String concatenation: cualquier tipo puede convertirse a String
    if (tipo_variable == TIPO_STRING) {
        return 1;
    }

    // No son compatibles
    return 0;
}

// ===== MANTENER ESTA FUNCIÓN PARA CASOS SIMPLES =====
char* extract_dato_value(ASTNode* node) {
    if (!node) return NULL;

    if (node->value) {
        char* resultado = malloc(strlen(node->value) + 1);
        strcpy(resultado, node->value);
        return resultado;
    }

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

