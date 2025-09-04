//
// Created by lightdemon on 3/09/25.
//
#include "../../Headers/Procesador_Vectores.h"
#include "../../Headers/globals.h"
#include "../../Headers/node_utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "Procesador_Declaraciones.h"
#include "../../Headers/error_manager.h"



int process_vector_node(NodeProcessorContext* context, ASTNode* node) {
    if (!context || !node) return 1;

    // Extraer tipo base y nombre
    ASTNode* tipo_multi = node->children[0];
    ASTNode* id_nodo = node->children[1];
    if (!tipo_multi || !id_nodo || !id_nodo->value) return 1;

    ASTNode* tipo_nodo = tipo_multi->children[0];
    const char* tipo_str = tipo_nodo->value;
    TipoDato tipo_dato = string_to_tipo_dato(tipo_str);
    const char* id_str = id_nodo->value;

    // Verificar redeclaración en el scope actual
    const char* scope_actual_nombre = context->scope_actual ? context->scope_actual->nombre : "global";
    if (verificar_simbolo_existe_en_scope_especifico(context->tabla_simbolos, id_str, scope_actual_nombre)) {
        char error_msg[256];
        snprintf(error_msg, sizeof(error_msg), "Vector '%s' ya declarado en scope '%s'", id_str, scope_actual_nombre);
        procesador_error_output(context, error_msg);
        return 1;
    }

    // === SOPORTE PARA VECTOR_NEW ===
    if (strcmp(node->type, "VECTOR_NEW") == 0) {
        ASTNode* new_decl = node->children[2];
        ASTNode* dim_vector = new_decl->children[1];
        ASTNode* dato_dim = dim_vector->children[0]->children[0];
        char* dim_str = extract_dato_value(dato_dim);

        Simbolo simbolo = crear_simbolo_default(id_str, SIMBOLO_VECTOR, tipo_dato);
        simbolo.linea = node->line;
        simbolo.columna = node->column;
        simbolo.visibilidad = VIS_PUBLIC;
        simbolo.inicializado = 1;
        simbolo.timestamp_creacion = time(NULL);
        simbolo.tamano = dim_str ? atoi(dim_str) : 0;
        snprintf(simbolo.valor, MAX_VALUE_LENGTH, "new[%s]", dim_str ? dim_str : "0");

        // Inicialización real
        if (tipo_dato == TIPO_INT) {
            simbolo.valores_int = malloc(simbolo.tamano * sizeof(int));
            for (int i = 0; i < simbolo.tamano; i++) simbolo.valores_int[i] = 0;
        } else if (tipo_dato == TIPO_STRING) {
            simbolo.valores_str = malloc(simbolo.tamano * sizeof(char*));
            for (int i = 0; i < simbolo.tamano; i++) simbolo.valores_str[i] = NULL;
        }

        free(dim_str);

        if (!insertar_simbolo_en_scope_combinado(context, simbolo)) {
            procesador_error_output(context, "No se pudo insertar vector");
            if (tipo_dato == TIPO_INT && simbolo.valores_int) free(simbolo.valores_int);
            if (tipo_dato == TIPO_STRING && simbolo.valores_str) free(simbolo.valores_str);
            return 1;
        }
        return 0;
    }

    // === SOPORTE PARA VECTOR_INICIALIZADO ===
    if (strcmp(node->type, "VECTOR_INICIALIZADO") == 0) {
        ASTNode* contenido_vector = node->children[2];

        int cantidad = contenido_vector->child_count;
        char valores[MAX_VALUE_LENGTH] = "{";
        Simbolo simbolo = crear_simbolo_default(id_str, SIMBOLO_VECTOR, tipo_dato);
        simbolo.linea = node->line;
        simbolo.columna = node->column;
        simbolo.visibilidad = VIS_PUBLIC;
        simbolo.inicializado = 1;
        simbolo.timestamp_creacion = time(NULL);
        simbolo.tamano = cantidad;

        // Inicialización real
        if (tipo_dato == TIPO_INT) {
            simbolo.valores_int = malloc(cantidad * sizeof(int));
            for (int i = 0; i < cantidad; i++) {
                ASTNode* dato = contenido_vector->children[i];
                char* val = extract_dato_value(dato->children[0]);
                simbolo.valores_int[i] = val ? atoi(val) : 0;
                strcat(valores, val);
                if (i < cantidad - 1) strcat(valores, ",");
                free(val);
            }
        } else if (tipo_dato == TIPO_STRING) {
            simbolo.valores_str = malloc(cantidad * sizeof(char*));
            for (int i = 0; i < cantidad; i++) {
                ASTNode* dato = contenido_vector->children[i];
                char* val = extract_dato_value(dato->children[0]);
                simbolo.valores_str[i] = val ? strdup(val) : NULL;
                strcat(valores, val);
                if (i < cantidad - 1) strcat(valores, ",");
                free(val);
            }
        }
        strcat(valores, "}");
        strncpy(simbolo.valor, valores, MAX_VALUE_LENGTH - 1);

        if (!insertar_simbolo_en_scope_combinado(context, simbolo)) {
            procesador_error_output(context, "No se pudo insertar vector");
            if (tipo_dato == TIPO_INT && simbolo.valores_int) free(simbolo.valores_int);
            if (tipo_dato == TIPO_STRING && simbolo.valores_str) {
                for (int i = 0; i < cantidad; i++) free(simbolo.valores_str[i]);
                free(simbolo.valores_str);
            }
            return 1;
        }
        return 0;
    }

    // Solo vectores soportados
    procesador_error_output(context, "Tipo de nodo de vector no soportado");
    return 1;
}

// --- FUNCIONES DE ASIGNACIÓN, ACCESO Y ESCRITURA PARA TODOS LOS TIPOS ---

void asignar_vector(NodeProcessorContext* context, Simbolo* simbolo, int indice, void* valor) {
    if (!simbolo || indice < 0 || indice >= simbolo->tamano) return;
    switch (simbolo->tipo_dato) {
        case TIPO_INT:
            if (simbolo->valores_int) simbolo->valores_int[indice] = *((int*)valor);
            break;
        case TIPO_LONG:
            if (simbolo->valores_long) simbolo->valores_long[indice] = *((long*)valor);
            break;
        case TIPO_DOUBLE:
            if (simbolo->valores_double) simbolo->valores_double[indice] = *((double*)valor);
            break;
        case TIPO_FLOAT:
            if (simbolo->valores_float) simbolo->valores_float[indice] = *((float*)valor);
            break;
        case TIPO_CHAR:
            if (simbolo->valores_char) simbolo->valores_char[indice] = *((char*)valor);
            break;
        case TIPO_STRING:
            if (simbolo->valores_str) {
                if (simbolo->valores_str[indice]) free(simbolo->valores_str[indice]);
                simbolo->valores_str[indice] = valor ? strdup((char*)valor) : NULL;
            }
            break;
        default: break;
    }
}

int leer_vector_int(Simbolo* simbolo, int indice) {
    if (!simbolo || !simbolo->valores_int || indice < 0 || indice >= simbolo->tamano) return 0;
    return simbolo->valores_int[indice];
}
long leer_vector_long(Simbolo* simbolo, int indice) {
    if (!simbolo || !simbolo->valores_long || indice < 0 || indice >= simbolo->tamano) return 0;
    return simbolo->valores_long[indice];
}
double leer_vector_double(Simbolo* simbolo, int indice) {
    if (!simbolo || !simbolo->valores_double || indice < 0 || indice >= simbolo->tamano) return 0;
    return simbolo->valores_double[indice];
}
float leer_vector_float(Simbolo* simbolo, int indice) {
    if (!simbolo || !simbolo->valores_float || indice < 0 || indice >= simbolo->tamano) return 0;
    return simbolo->valores_float[indice];
}
char leer_vector_char(Simbolo* simbolo, int indice) {
    if (!simbolo || !simbolo->valores_char || indice < 0 || indice >= simbolo->tamano) return 0;
    return simbolo->valores_char[indice];
}
char* leer_vector_str(Simbolo* simbolo, int indice) {
    if (!simbolo || !simbolo->valores_str || indice < 0 || indice >= simbolo->tamano) return NULL;
    return simbolo->valores_str[indice];
}

void escribir_vector_int(Simbolo* simbolo, int indice, int valor) {
    if (!simbolo || !simbolo->valores_int || indice < 0 || indice >= simbolo->tamano) return;
    simbolo->valores_int[indice] = valor;
}
void escribir_vector_long(Simbolo* simbolo, int indice, long valor) {
    if (!simbolo || !simbolo->valores_long || indice < 0 || indice >= simbolo->tamano) return;
    simbolo->valores_long[indice] = valor;
}
void escribir_vector_double(Simbolo* simbolo, int indice, double valor) {
    if (!simbolo || !simbolo->valores_double || indice < 0 || indice >= simbolo->tamano) return;
    simbolo->valores_double[indice] = valor;
}
void escribir_vector_float(Simbolo* simbolo, int indice, float valor) {
    if (!simbolo || !simbolo->valores_float || indice < 0 || indice >= simbolo->tamano) return;
    simbolo->valores_float[indice] = valor;
}
void escribir_vector_char(Simbolo* simbolo, int indice, char valor) {
    if (!simbolo || !simbolo->valores_char || indice < 0 || indice >= simbolo->tamano) return;
    simbolo->valores_char[indice] = valor;
}
void escribir_vector_str(Simbolo* simbolo, int indice, const char* valor) {
    if (!simbolo || !simbolo->valores_str || indice < 0 || indice >= simbolo->tamano) return;
    if (simbolo->valores_str[indice]) free(simbolo->valores_str[indice]);
    simbolo->valores_str[indice] = valor ? strdup(valor) : NULL;
}

int procesar_acceso_vector(NodeProcessorContext* context, ASTNode* acceso_node) {
    if (!context || !acceso_node) return -1;

    // Espera estructura: ARRAY_ACCESO_MULTIDIMENSIONAL con hijos:
    // [0] IDENTIFIER (nombre del vector)
    // [1] BRACKETS_INDICES (con hijos INDICE -> DATO -> INT_LITERAL)
    if (acceso_node->child_count < 2) return -1;

    ASTNode* id_node = acceso_node->children[0];
    ASTNode* indices_node = acceso_node->children[1];
    if (!id_node || !indices_node || !id_node->value) return -1;

    const char* vector_id = id_node->value;
    int num_indices = indices_node->child_count;

    // Buscar el símbolo en la tabla
    Simbolo* simbolo = buscar_simbolo_en_scopes_combinado(context, vector_id);
    if (!simbolo || simbolo->tipo_simbolo != SIMBOLO_VECTOR) {
        if (global_error_manager) {
            error_manager_add_semantico(global_error_manager,
                acceso_node->line, acceso_node->column,
                "Acceso a variable que no es vector", vector_id,
                context->scope_actual ? context->scope_actual->nombre : "global");
        }
        return -1;
    }

    // Verificar número de índices
    if (num_indices != simbolo->dimensiones) {
        if (global_error_manager) {
            error_manager_add_semantico(global_error_manager,
                acceso_node->line, acceso_node->column,
                "Acceso a vector con número incorrecto de índices", vector_id,
                context->scope_actual ? context->scope_actual->nombre : "global");
        }
        return -1;
    }

    // Extraer índices
    int* indices = malloc(num_indices * sizeof(int));
    for (int i = 0; i < num_indices; i++) {
        ASTNode* indice_node = indices_node->children[i]; // INDICE
        if (!indice_node || indice_node->child_count < 1) {
            free(indices);
            return -1;
        }
        ASTNode* dato_node = indice_node->children[0]; // DATO
        if (!dato_node) {
            free(indices);
            return -1;
        }
        char* indice_str = extract_dato_value(dato_node);
        indices[i] = indice_str ? atoi(indice_str) : -1;
        free(indice_str);
    }

    // Verificar límites
    for (int i = 0; i < num_indices; i++) {
        if (indices[i] < 0 || indices[i] >= simbolo->tamaños_dimensiones[i]) {
            char msg[256];
            snprintf(msg, sizeof(msg),
                "Índice fuera de límites en dimensión %d | Token: '%s'", i, vector_id);
            if (global_error_manager) {
                error_manager_add_semantico(global_error_manager,
                    acceso_node->line, acceso_node->column,
                    msg, vector_id,
                    context->scope_actual ? context->scope_actual->nombre : "global");
            }
            free(indices);
            return -1;
        }
    }

    // Retornar el valor como int si es int, 0 para otros tipos
    int resultado = 0;
    if (simbolo->tipo_dato == TIPO_INT) {
        if (num_indices == 1) {
            resultado = simbolo->valores_int[indices[0]];
        } else if (num_indices == 2) {
            resultado = simbolo->valores_int_2d[indices[0]][indices[1]];
        } else if (num_indices == 3) {
            resultado = simbolo->valores_int_3d[indices[0]][indices[1]][indices[2]];
        }
    }
    // Para otros tipos (float, double, char, string, boolean), retornar 0

    free(indices);
    return resultado;
}

int procesar_asignacion_compuesta_array(NodeProcessorContext* context, ASTNode* node) {
    if (!context || !node || node->child_count < 3) return 1;

    ASTNode* acceso_node = node->children[0];  // ACCESO_ARRAY_1D
    ASTNode* operador_node = node->children[1];  // OPERADOR_ASIGNACION
    ASTNode* valor_node = node->children[2];  // VALOR_ASIGNACION

    if (!acceso_node || !operador_node || !valor_node) return 1;

    // Extraer ID del array
    if (acceso_node->child_count < 2) return 1;
    ASTNode* id_node = acceso_node->children[0];
    if (!id_node || !id_node->value) return 1;
    const char* array_id = id_node->value;

    // Buscar el símbolo del array
    Simbolo* simbolo = buscar_simbolo_en_scopes_combinado(context, array_id);
    if (!simbolo || simbolo->tipo_simbolo != SIMBOLO_VECTOR) {
        char error_msg[256];
        snprintf(error_msg, sizeof(error_msg), "Array '%s' no declarado o no es un vector", array_id);
        procesador_error_output(context, error_msg);
        return 1;
    }

    // Extraer índice
    ASTNode* indice_array = acceso_node->children[1];
    if (!indice_array || indice_array->child_count < 1) return 1;
    ASTNode* indice_node = indice_array->children[0];
    if (!indice_node) return 1;
    char* indice_str = extract_dato_value(indice_node);
    int indice = indice_str ? atoi(indice_str) : -1;
    free(indice_str);

    if (indice < 0 || indice >= simbolo->tamano) {
        char error_msg[256];
        snprintf(error_msg, sizeof(error_msg), "Índice %d fuera de rango para array '%s' (tamaño %d)", indice, array_id, simbolo->tamano);
        procesador_error_output(context, error_msg);
        return 1;
    }

    // Extraer valor a asignar
    if (valor_node->child_count < 1) return 1;
    ASTNode* dato_node = valor_node->children[0];
    char* valor_str = extract_dato_value(dato_node);
    if (!valor_str) return 1;

    // Asignar según tipo
    switch (simbolo->tipo_dato) {
        case TIPO_INT:
            escribir_vector_int(simbolo, indice, atoi(valor_str));
            break;
        case TIPO_DOUBLE:
            escribir_vector_double(simbolo, indice, atof(valor_str));
            break;
        case TIPO_FLOAT:
            escribir_vector_float(simbolo, indice, atof(valor_str));
            break;
        case TIPO_LONG:
            escribir_vector_long(simbolo, indice, atol(valor_str));
            break;
        case TIPO_CHAR:
            if (strlen(valor_str) > 0) {
                escribir_vector_char(simbolo, indice, valor_str[0]);
            }
            break;
        case TIPO_STRING:
            escribir_vector_str(simbolo, indice, valor_str);
            break;
        default:
            free(valor_str);
            procesador_error_output(context, "Tipo de array no soportado para asignación");
            return 1;
    }

    free(valor_str);

    char debug_msg[256];
    snprintf(debug_msg, sizeof(debug_msg), "Asignación exitosa: %s[%d] = %s", array_id, indice, valor_str);
    procesador_debug_output(context, debug_msg);

    return 0;
}
