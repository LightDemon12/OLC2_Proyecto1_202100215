#include "../../Headers/Procesador_Multidimensional.h"
#include "../../Headers/globals.h"
#include "../../Headers/node_utils.h"
#include "../../Headers/node_utils.h"
#include "../../Headers/Procesador_Declaraciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Función auxiliar para extraer dimensiones de NEW_DECLARATION_MULTIDIMENSIONAL
int* extraer_dimensiones(ASTNode* new_decl, int* num_dimensiones) {
    if (!new_decl || strcmp(new_decl->type, "NEW_DECLARATION_MULTIDIMENSIONAL") != 0) return NULL;

    ASTNode* brackets_new = new_decl->children[1]; // BRACKETS_NEW
    if (!brackets_new) return NULL;

    *num_dimensiones = brackets_new->child_count;
    int* dimensiones = malloc(*num_dimensiones * sizeof(int));

    for (int i = 0; i < *num_dimensiones; i++) {
        ASTNode* dimension = brackets_new->children[i]; // DIMENSION
        if (dimension && dimension->child_count > 0) {
            ASTNode* dato = dimension->children[0]; // DATO
            char* val = extract_dato_value(dato);
            dimensiones[i] = val ? atoi(val) : 0;
            free(val);
        } else {
            dimensiones[i] = 0;
        }
    }

    return dimensiones;
}

// Función para inicializar array multidimensional con valores por defecto (expandida para tipos y dimensiones)
void inicializar_array_multidimensional(Simbolo* simbolo, int* dimensiones, int num_dimensiones) {
    if (num_dimensiones < 1 || num_dimensiones > 4) return; // Soporte desde 1D hasta 4D

    switch (simbolo->tipo_dato) {
        case TIPO_INT:
            if (num_dimensiones == 1) {
                simbolo->valores_int = malloc(dimensiones[0] * sizeof(int));
                memset(simbolo->valores_int, 0, dimensiones[0] * sizeof(int));
            } else if (num_dimensiones == 2) {
                simbolo->valores_int_2d = malloc(dimensiones[0] * sizeof(int*));
                for (int i = 0; i < dimensiones[0]; i++) {
                    simbolo->valores_int_2d[i] = malloc(dimensiones[1] * sizeof(int));
                    for (int j = 0; j < dimensiones[1]; j++) simbolo->valores_int_2d[i][j] = 0;
                }
            } else if (num_dimensiones == 3) {
                simbolo->valores_int_3d = malloc(dimensiones[0] * sizeof(int**));
                for (int i = 0; i < dimensiones[0]; i++) {
                    simbolo->valores_int_3d[i] = malloc(dimensiones[1] * sizeof(int*));
                    for (int j = 0; j < dimensiones[1]; j++) {
                        simbolo->valores_int_3d[i][j] = malloc(dimensiones[2] * sizeof(int));
                        for (int k = 0; k < dimensiones[2]; k++) simbolo->valores_int_3d[i][j][k] = 0;
                    }
                }
            } else if (num_dimensiones == 4) {
                simbolo->valores_int_nd = malloc(dimensiones[0] * dimensiones[1] * dimensiones[2] * dimensiones[3] * sizeof(int));
                memset(simbolo->valores_int_nd, 0, dimensiones[0] * dimensiones[1] * dimensiones[2] * dimensiones[3] * sizeof(int));
            }
            break;
        case TIPO_FLOAT:
            if (num_dimensiones == 1) {
                simbolo->valores_float = malloc(dimensiones[0] * sizeof(float));
                memset(simbolo->valores_float, 0, dimensiones[0] * sizeof(float));
            } else if (num_dimensiones == 2) {
                simbolo->valores_float_2d = malloc(dimensiones[0] * sizeof(float*));
                for (int i = 0; i < dimensiones[0]; i++) {
                    simbolo->valores_float_2d[i] = malloc(dimensiones[1] * sizeof(float));
                    for (int j = 0; j < dimensiones[1]; j++) simbolo->valores_float_2d[i][j] = 0.0f;
                }
            } else if (num_dimensiones == 3) {
                simbolo->valores_float_3d = malloc(dimensiones[0] * sizeof(float**));
                for (int i = 0; i < dimensiones[0]; i++) {
                    simbolo->valores_float_3d[i] = malloc(dimensiones[1] * sizeof(float*));
                    for (int j = 0; j < dimensiones[1]; j++) {
                        simbolo->valores_float_3d[i][j] = malloc(dimensiones[2] * sizeof(float));
                        for (int k = 0; k < dimensiones[2]; k++) simbolo->valores_float_3d[i][j][k] = 0.0f;
                    }
                }
            } else if (num_dimensiones == 4) {
                simbolo->valores_float_nd = malloc(dimensiones[0] * dimensiones[1] * dimensiones[2] * dimensiones[3] * sizeof(float));
                memset(simbolo->valores_float_nd, 0, dimensiones[0] * dimensiones[1] * dimensiones[2] * dimensiones[3] * sizeof(float));
            }
            break;
        case TIPO_DOUBLE:
            if (num_dimensiones == 1) {
                simbolo->valores_double = malloc(dimensiones[0] * sizeof(double));
                memset(simbolo->valores_double, 0, dimensiones[0] * sizeof(double));
            } else if (num_dimensiones == 2) {
                simbolo->valores_double_2d = malloc(dimensiones[0] * sizeof(double*));
                for (int i = 0; i < dimensiones[0]; i++) {
                    simbolo->valores_double_2d[i] = malloc(dimensiones[1] * sizeof(double));
                    for (int j = 0; j < dimensiones[1]; j++) simbolo->valores_double_2d[i][j] = 0.0;
                }
            } else if (num_dimensiones == 3) {
                simbolo->valores_double_3d = malloc(dimensiones[0] * sizeof(double**));
                for (int i = 0; i < dimensiones[0]; i++) {
                    simbolo->valores_double_3d[i] = malloc(dimensiones[1] * sizeof(double*));
                    for (int j = 0; j < dimensiones[1]; j++) {
                        simbolo->valores_double_3d[i][j] = malloc(dimensiones[2] * sizeof(double));
                        for (int k = 0; k < dimensiones[2]; k++) simbolo->valores_double_3d[i][j][k] = 0.0;
                    }
                }
            } else if (num_dimensiones == 4) {
                simbolo->valores_double_nd = malloc(dimensiones[0] * dimensiones[1] * dimensiones[2] * dimensiones[3] * sizeof(double));
                memset(simbolo->valores_double_nd, 0, dimensiones[0] * dimensiones[1] * dimensiones[2] * dimensiones[3] * sizeof(double));
            }
            break;
        case TIPO_CHAR:
            if (num_dimensiones == 1) {
                simbolo->valores_char = malloc(dimensiones[0] * sizeof(char));
                memset(simbolo->valores_char, '\0', dimensiones[0] * sizeof(char));
            } else if (num_dimensiones == 2) {
                simbolo->valores_char_2d = malloc(dimensiones[0] * sizeof(char*));
                for (int i = 0; i < dimensiones[0]; i++) {
                    simbolo->valores_char_2d[i] = malloc(dimensiones[1] * sizeof(char));
                    memset(simbolo->valores_char_2d[i], '\0', dimensiones[1] * sizeof(char));
                }
            } else if (num_dimensiones == 3) {
                simbolo->valores_char_3d = malloc(dimensiones[0] * sizeof(char**));
                for (int i = 0; i < dimensiones[0]; i++) {
                    simbolo->valores_char_3d[i] = malloc(dimensiones[1] * sizeof(char*));
                    for (int j = 0; j < dimensiones[1]; j++) {
                        simbolo->valores_char_3d[i][j] = malloc(dimensiones[2] * sizeof(char));
                        memset(simbolo->valores_char_3d[i][j], '\0', dimensiones[2] * sizeof(char));
                    }
                }
            } else if (num_dimensiones == 4) {
                simbolo->valores_char_nd = malloc(dimensiones[0] * dimensiones[1] * dimensiones[2] * dimensiones[3] * sizeof(char));
                memset(simbolo->valores_char_nd, '\0', dimensiones[0] * dimensiones[1] * dimensiones[2] * dimensiones[3] * sizeof(char));
            }
            break;
        case TIPO_STRING:
            if (num_dimensiones == 1) {
                simbolo->valores_str = malloc(dimensiones[0] * sizeof(char*));
                memset(simbolo->valores_str, 0, dimensiones[0] * sizeof(char*));
            } else if (num_dimensiones == 2) {
                simbolo->valores_str_2d = malloc(dimensiones[0] * sizeof(char*));
                for (int i = 0; i < dimensiones[0]; i++) {
                    simbolo->valores_str_2d[i] = malloc(dimensiones[1] * sizeof(char*));
                    for (int j = 0; j < dimensiones[1]; j++) simbolo->valores_str_2d[i][j] = NULL;
                }
            } else if (num_dimensiones == 3) {
                simbolo->valores_str_3d = malloc(dimensiones[0] * sizeof(char**));
                for (int i = 0; i < dimensiones[0]; i++) {
                    simbolo->valores_str_3d[i] = malloc(dimensiones[1] * sizeof(char*));
                    for (int j = 0; j < dimensiones[1]; j++) {
                        simbolo->valores_str_3d[i][j] = malloc(dimensiones[2] * sizeof(char*));
                        for (int k = 0; k < dimensiones[2]; k++) simbolo->valores_str_3d[i][j][k] = NULL;
                    }
                }
            } else if (num_dimensiones == 4) {
                simbolo->valores_str_nd = malloc(dimensiones[0] * dimensiones[1] * dimensiones[2] * dimensiones[3] * sizeof(char*));
                memset(simbolo->valores_str_nd, 0, dimensiones[0] * dimensiones[1] * dimensiones[2] * dimensiones[3] * sizeof(char*));
            }
            break;
        case TIPO_BOOLEAN:
            if (num_dimensiones == 1) {
                simbolo->valores_bool = malloc(dimensiones[0] * sizeof(int));
                memset(simbolo->valores_bool, 0, dimensiones[0] * sizeof(int));
            } else if (num_dimensiones == 2) {
                simbolo->valores_bool_2d = malloc(dimensiones[0] * sizeof(int*));
                for (int i = 0; i < dimensiones[0]; i++) {
                    simbolo->valores_bool_2d[i] = malloc(dimensiones[1] * sizeof(int));
                    memset(simbolo->valores_bool_2d[i], 0, dimensiones[1] * sizeof(int));
                }
            } else if (num_dimensiones == 3) {
                simbolo->valores_bool_3d = malloc(dimensiones[0] * sizeof(int**));
                for (int i = 0; i < dimensiones[0]; i++) {
                    simbolo->valores_bool_3d[i] = malloc(dimensiones[1] * sizeof(int*));
                    for (int j = 0; j < dimensiones[1]; j++) {
                        simbolo->valores_bool_3d[i][j] = malloc(dimensiones[2] * sizeof(int));
                        memset(simbolo->valores_bool_3d[i][j], 0, dimensiones[2] * sizeof(int));
                    }
                }
            } else if (num_dimensiones == 4) {
                simbolo->valores_bool_nd = malloc(dimensiones[0] * dimensiones[1] * dimensiones[2] * dimensiones[3] * sizeof(int));
                memset(simbolo->valores_bool_nd, 0, dimensiones[0] * dimensiones[1] * dimensiones[2] * dimensiones[3] * sizeof(int));
            }
            break;
        default:
            break;
    }
}

// Procesar ARRAY_MULTIDIMENSIONAL_NEW
int process_array_multidimensional_new(NodeProcessorContext* context, ASTNode* node) {
    if (!context || !node || node->child_count < 3) return 1;

    // Extraer tipo multidimensional
    ASTNode* tipo_multi = node->children[0]; // TIPO_MULTIDIMENSIONAL
    ASTNode* id_node = node->children[1]; // IDENTIFIER
    ASTNode* new_decl = node->children[2]; // NEW_DECLARATION_MULTIDIMENSIONAL

    if (!tipo_multi || !id_node || !new_decl || !id_node->value) return 1;

    // Extraer tipo base
    ASTNode* tipo_node = tipo_multi->children[0]; // TIPO
    const char* tipo_str = tipo_node->value;
    TipoDato tipo_dato = string_to_tipo_dato(tipo_str);
    const char* id_str = id_node->value;

    // Extraer dimensiones
    int num_dimensiones = 0;
    int* dimensiones = extraer_dimensiones(new_decl, &num_dimensiones);
    if (!dimensiones || num_dimensiones == 0) {
        free(dimensiones);
        return 1;
    }

    // Verificar redeclaración
    const char* scope_actual = context->scope_actual ? context->scope_actual->nombre : "global";
    if (verificar_simbolo_existe_en_scope_especifico(context->tabla_simbolos, id_str, scope_actual)) {
        char error_msg[256];
        snprintf(error_msg, sizeof(error_msg), "Array multidimensional '%s' ya declarado en scope '%s'", id_str, scope_actual);
        procesador_error_output(context, error_msg);
        free(dimensiones);
        return 1;
    }

    // Crear símbolo
    Simbolo simbolo = crear_simbolo_default(id_str, SIMBOLO_VECTOR, tipo_dato);
    simbolo.linea = node->line;
    simbolo.columna = node->column;
    simbolo.visibilidad = VIS_PUBLIC;
    simbolo.inicializado = 1;
    simbolo.timestamp_creacion = time(NULL);
    simbolo.dimensiones = num_dimensiones;
    memcpy(simbolo.tamaños_dimensiones, dimensiones, num_dimensiones * sizeof(int));

    // Inicializar con valores por defecto (asigna memoria para valores_int_2d/valores_int_3d)
    inicializar_array_multidimensional(&simbolo, dimensiones, num_dimensiones);

    // Insertar símbolo
    if (!insertar_simbolo_en_scope_combinado(context, simbolo)) {
        procesador_error_output(context, "No se pudo insertar array multidimensional");
        free(dimensiones);
        return 1;
    }

    free(dimensiones);
    return 0;
}

// Procesar ARRAY_MULTIDIMENSIONAL_INICIALIZADO
int process_array_multidimensional_inicializado(NodeProcessorContext* context, ASTNode* node) {
    if (!context || !node || node->child_count < 3) return 1;

    // Extraer tipo multidimensional
    ASTNode* tipo_multi = node->children[0]; // TIPO_MULTIDIMENSIONAL
    ASTNode* id_node = node->children[1]; // IDENTIFIER
    ASTNode* brace_block = node->children[2]; // BRACE_BLOCK

    if (!tipo_multi || !id_node || !brace_block || !id_node->value) return 1;

    // Extraer tipo base
    ASTNode* tipo_node = tipo_multi->children[0]; // TIPO
    const char* tipo_str = tipo_node->value;
    TipoDato tipo_dato = string_to_tipo_dato(tipo_str);
    const char* id_str = id_node->value;

    // Detectar número de dimensiones desde BRACKETS
    int num_dimensiones = 0;
    ASTNode* brackets = tipo_multi->children[1]; // BRACKETS
    if (brackets) num_dimensiones = brackets->child_count;

    // Parsear BRACE_BLOCK para obtener valores
    int filas = 0, columnas = 0;
    char*** valores = parse_brace_block(brace_block, &filas, &columnas, tipo_dato);
    if (!valores) return 1;

    // Verificar redeclaración
    const char* scope_actual = context->scope_actual ? context->scope_actual->nombre : "global";
    if (verificar_simbolo_existe_en_scope_especifico(context->tabla_simbolos, id_str, scope_actual)) {
        char error_msg[256];
        snprintf(error_msg, sizeof(error_msg), "Array multidimensional '%s' ya declarado en scope '%s'", id_str, scope_actual);
        procesador_error_output(context, error_msg);
        // Liberar valores
        for (int i = 0; i < filas; i++) {
            for (int j = 0; j < columnas; j++) {
                free(valores[i][j]);
            }
            free(valores[i]);
        }
        free(valores);
        return 1;
    }

    // Crear símbolo
    Simbolo simbolo = crear_simbolo_default(id_str, SIMBOLO_VECTOR, tipo_dato);
    simbolo.linea = node->line;
    simbolo.columna = node->column;
    simbolo.visibilidad = VIS_PUBLIC;
    simbolo.inicializado = 1;
    simbolo.timestamp_creacion = time(NULL);
    simbolo.dimensiones = num_dimensiones;
    if (num_dimensiones == 1) {
        simbolo.tamaños_dimensiones[0] = columnas;
        simbolo.tamano = columnas; // Establecer tamano para arrays 1D
    } else {
        simbolo.tamaños_dimensiones[0] = filas;
        simbolo.tamaños_dimensiones[1] = columnas;
        simbolo.tamano = 0; // Para multidimensional, no usar tamano para validación
    }

    // Inicializar con valores parseados según tipo y dimensiones
    switch (tipo_dato) {
        case TIPO_INT:
            if (num_dimensiones == 1) {
                simbolo.valores_int = malloc(columnas * sizeof(int));
                for (int j = 0; j < columnas; j++) {
                    simbolo.valores_int[j] = atoi(valores[0][j]);
                    free(valores[0][j]);
                }
                free(valores[0]);
            } else if (num_dimensiones == 2) {
                simbolo.valores_int_2d = malloc(filas * sizeof(int*));
                for (int i = 0; i < filas; i++) {
                    simbolo.valores_int_2d[i] = malloc(columnas * sizeof(int));
                    for (int j = 0; j < columnas; j++) {
                        simbolo.valores_int_2d[i][j] = atoi(valores[i][j]);
                        free(valores[i][j]);
                    }
                    free(valores[i]);
                }
            }
            // Agregar casos para 3D y 4D similares
            break;
        case TIPO_FLOAT:
            if (num_dimensiones == 1) {
                simbolo.valores_float = malloc(columnas * sizeof(float));
                for (int j = 0; j < columnas; j++) {
                    simbolo.valores_float[j] = atof(valores[0][j]);
                    free(valores[0][j]);
                }
                free(valores[0]);
            } else if (num_dimensiones == 2) {
                simbolo.valores_float_2d = malloc(filas * sizeof(float*));
                for (int i = 0; i < filas; i++) {
                    simbolo.valores_float_2d[i] = malloc(columnas * sizeof(float));
                    for (int j = 0; j < columnas; j++) {
                        simbolo.valores_float_2d[i][j] = atof(valores[i][j]);
                        free(valores[i][j]);
                    }
                    free(valores[i]);
                }
            }
            // Agregar casos para 3D y 4D similares
            break;
        case TIPO_DOUBLE:
            if (num_dimensiones == 1) {
                simbolo.valores_double = malloc(columnas * sizeof(double));
                for (int j = 0; j < columnas; j++) {
                    simbolo.valores_double[j] = atof(valores[0][j]);
                    free(valores[0][j]);
                }
                free(valores[0]);
            } else if (num_dimensiones == 2) {
                simbolo.valores_double_2d = malloc(filas * sizeof(double*));
                for (int i = 0; i < filas; i++) {
                    simbolo.valores_double_2d[i] = malloc(columnas * sizeof(double));
                    for (int j = 0; j < columnas; j++) {
                        simbolo.valores_double_2d[i][j] = atof(valores[i][j]);
                        free(valores[i][j]);
                    }
                    free(valores[i]);
                }
            }
            // Agregar casos para 3D y 4D similares
            break;
        case TIPO_CHAR:
            if (num_dimensiones == 1) {
                simbolo.valores_char = malloc(columnas * sizeof(char));
                for (int j = 0; j < columnas; j++) {
                    simbolo.valores_char[j] = valores[0][j][0];
                    free(valores[0][j]);
                }
                free(valores[0]);
            } else if (num_dimensiones == 2) {
                simbolo.valores_char_2d = malloc(filas * sizeof(char*));
                for (int i = 0; i < filas; i++) {
                    simbolo.valores_char_2d[i] = malloc(columnas * sizeof(char));
                    for (int j = 0; j < columnas; j++) {
                        simbolo.valores_char_2d[i][j] = valores[i][j][0];
                        free(valores[i][j]);
                    }
                    free(valores[i]);
                }
            }
            // Agregar casos para 3D y 4D similares
            break;
        case TIPO_STRING:
            if (num_dimensiones == 1) {
                simbolo.valores_str = malloc(columnas * sizeof(char*));
                for (int j = 0; j < columnas; j++) {
                    simbolo.valores_str[j] = strdup(valores[0][j]);
                    free(valores[0][j]);
                }
                free(valores[0]);
            } else if (num_dimensiones == 2) {
                simbolo.valores_str_2d = malloc(filas * sizeof(char*));
                for (int i = 0; i < filas; i++) {
                    simbolo.valores_str_2d[i] = malloc(columnas * sizeof(char*));
                    for (int j = 0; j < columnas; j++) {
                        simbolo.valores_str_2d[i][j] = strdup(valores[i][j]);
                        free(valores[i][j]);
                    }
                    free(valores[i]);
                }
            }
            // Agregar casos para 3D y 4D similares
            break;
        case TIPO_BOOLEAN:
            if (num_dimensiones == 1) {
                simbolo.valores_bool = malloc(columnas * sizeof(int));
                for (int j = 0; j < columnas; j++) {
                    simbolo.valores_bool[j] = strcmp(valores[0][j], "true") == 0 ? 1 : 0;
                    free(valores[0][j]);
                }
                free(valores[0]);
            } else if (num_dimensiones == 2) {
                simbolo.valores_bool_2d = malloc(filas * sizeof(int*));
                for (int i = 0; i < filas; i++) {
                    simbolo.valores_bool_2d[i] = malloc(columnas * sizeof(int));
                    for (int j = 0; j < columnas; j++) {
                        simbolo.valores_bool_2d[i][j] = strcmp(valores[i][j], "true") == 0 ? 1 : 0;
                        free(valores[i][j]);
                    }
                    free(valores[i]);
                }
            }
            // Agregar casos para 3D y 4D similares
            break;
        default:
            break;
    }
    free(valores);

    // Insertar símbolo
    if (!insertar_simbolo_en_scope_combinado(context, simbolo)) {
        procesador_error_output(context, "No se pudo insertar array multidimensional inicializado");
        return 1;
    }

    return 0;
}

// Función auxiliar para parsear BRACE_BLOCK (simplificada para 2D)
char*** parse_brace_block(ASTNode* brace_block, int* filas, int* columnas, TipoDato tipo) {
    if (!brace_block || strcmp(brace_block->type, "BRACE_BLOCK") != 0) return NULL;

    ASTNode* brace_elements = brace_block->children[0]; // BRACE_ELEMENTS
    if (!brace_elements) return NULL;

    *filas = brace_elements->child_count;
    char*** valores = malloc(*filas * sizeof(char**));

    for (int i = 0; i < *filas; i++) {
        ASTNode* sub_brace = brace_elements->children[i]; // BRACE_BLOCK o LISTA_EXPRESIONES
        if (!sub_brace) continue;

        ASTNode* sub_elements = NULL;
        int is_1d = 0;

        if (strcmp(sub_brace->type, "LISTA_EXPRESIONES") == 0) {
            // Es 1D: sub_brace es LISTA_EXPRESIONES
            sub_elements = sub_brace;
            is_1d = 1;
            *columnas = sub_elements->child_count;
        } else if (strcmp(sub_brace->type, "BRACE_BLOCK") == 0) {
            // Es 2D+: sub_brace es BRACE_BLOCK
            sub_elements = sub_brace->children[0]; // BRACE_ELEMENTS
            if (!sub_elements) continue;
            *columnas = sub_elements->child_count;
        } else {
            continue;
        }

        valores[i] = malloc(*columnas * sizeof(char*));

        for (int j = 0; j < *columnas; j++) {
            ASTNode* lista = sub_elements->children[j]; // LISTA_EXPRESIONES o DATO
            if (!lista) continue;

            ASTNode* dato = NULL;
            if (is_1d) {
                // Para 1D: lista es DATO
                dato = lista;
            } else {
                // Para 2D+: lista es LISTA_EXPRESIONES, dato es lista->children[0]
                if (lista->child_count > 0) {
                    dato = lista->children[0]; // DATO
                }
            }

            if (dato) {
                valores[i][j] = extract_dato_value(dato);
            } else {
                valores[i][j] = NULL;
            }
        }
    }

    return valores;
}

char* procesar_acceso_multidimensional(NodeProcessorContext* context, ASTNode* node) {
    if (!context || !node || strcmp(node->type, "ARRAY_ACCESO_MULTIDIMENSIONAL") != 0) return NULL;

    ASTNode* id_node = node->children[0]; // IDENTIFIER
    ASTNode* brackets_indices = node->children[1]; // BRACKETS_INDICES

    if (!id_node || !brackets_indices || !id_node->value) return NULL;

    const char* id_str = id_node->value;
    int num_indices = brackets_indices->child_count;

    // Buscar símbolo
    Simbolo* simbolo = buscar_simbolo(context->tabla_simbolos, id_str);
    if (!simbolo) {
        procesador_error_output(context, "Array multidimensional no encontrado");
        return NULL;
    }

    if (simbolo->tipo_simbolo != SIMBOLO_VECTOR || simbolo->dimensiones != num_indices) {
        char error_msg[256];
        snprintf(error_msg, sizeof(error_msg), "Acceso a vector con número incorrecto de índices | Token: '%s'", id_str);
        procesador_error_output(context, error_msg);
        return NULL;
    }

    // Extraer índices
    int* indices = malloc(num_indices * sizeof(int));
    for (int i = 0; i < num_indices; i++) {
        ASTNode* indice = brackets_indices->children[i]; // INDICE
        if (indice && indice->child_count > 0) {
            ASTNode* dato = indice->children[0]; // DATO
            char* val = extract_dato_value(dato);
            indices[i] = val ? atoi(val) : 0;
            free(val);
        } else {
            indices[i] = 0;
        }
    }

    // Verificar límites
    for (int i = 0; i < num_indices; i++) {
        if (indices[i] < 0 || indices[i] >= simbolo->tamaños_dimensiones[i]) {
            char error_msg[256];
            snprintf(error_msg, sizeof(error_msg), "Índice fuera de límites en dimensión %d | Token: '%s'", i, id_str);
            procesador_error_output(context, error_msg);
            free(indices);
            return NULL;
        }
    }

    // Obtener valor según tipo y devolver como string
    char* resultado = NULL;
    switch (simbolo->tipo_dato) {
        case TIPO_INT:
            if (num_indices == 1) {
                resultado = malloc(32);
                sprintf(resultado, "%d", simbolo->valores_int[indices[0]]);
            } else if (num_indices == 2) {
                resultado = malloc(32);
                sprintf(resultado, "%d", simbolo->valores_int_2d[indices[0]][indices[1]]);
            } else if (num_indices == 3) {
                resultado = malloc(32);
                sprintf(resultado, "%d", simbolo->valores_int_3d[indices[0]][indices[1]][indices[2]]);
            }
            break;
        case TIPO_FLOAT:
            if (num_indices == 1) {
                resultado = malloc(32);
                sprintf(resultado, "%.2f", simbolo->valores_float[indices[0]]);
            } else if (num_indices == 2) {
                resultado = malloc(32);
                sprintf(resultado, "%.2f", simbolo->valores_float_2d[indices[0]][indices[1]]);
            } else if (num_indices == 3) {
                resultado = malloc(32);
                sprintf(resultado, "%.2f", simbolo->valores_float_3d[indices[0]][indices[1]][indices[2]]);
            }
            break;
        case TIPO_DOUBLE:
            if (num_indices == 1) {
                resultado = malloc(32);
                sprintf(resultado, "%.2f", simbolo->valores_double[indices[0]]);
            } else if (num_indices == 2) {
                resultado = malloc(32);
                sprintf(resultado, "%.2f", simbolo->valores_double_2d[indices[0]][indices[1]]);
            } else if (num_indices == 3) {
                resultado = malloc(32);
                sprintf(resultado, "%.2f", simbolo->valores_double_3d[indices[0]][indices[1]][indices[2]]);
            }
            break;
        case TIPO_CHAR:
            if (num_indices == 1) {
                resultado = malloc(2);
                sprintf(resultado, "%c", simbolo->valores_char[indices[0]]);
            } else if (num_indices == 2) {
                resultado = malloc(2);
                sprintf(resultado, "%c", simbolo->valores_char_2d[indices[0]][indices[1]]);
            } else if (num_indices == 3) {
                resultado = malloc(2);
                sprintf(resultado, "%c", simbolo->valores_char_3d[indices[0]][indices[1]][indices[2]]);
            }
            break;
        case TIPO_STRING:
            if (num_indices == 1) {
                resultado = strdup(simbolo->valores_str[indices[0]]);
            } else if (num_indices == 2) {
                resultado = strdup(simbolo->valores_str_2d[indices[0]][indices[1]]);
            } else if (num_indices == 3) {
                resultado = strdup(simbolo->valores_str_3d[indices[0]][indices[1]][indices[2]]);
            }
            break;
        case TIPO_BOOLEAN:
            if (num_indices == 1) {
                resultado = malloc(6);
                sprintf(resultado, "%s", simbolo->valores_bool[indices[0]] ? "true" : "false");
            } else if (num_indices == 2) {
                resultado = malloc(6);
                sprintf(resultado, "%s", simbolo->valores_bool_2d[indices[0]][indices[1]] ? "true" : "false");
            } else if (num_indices == 3) {
                resultado = malloc(6);
                sprintf(resultado, "%s", simbolo->valores_bool_3d[indices[0]][indices[1]][indices[2]] ? "true" : "false");
            }
            break;
        default:
            break;
    }

    free(indices);
    return resultado;
}

int process_array_asignacion_elemento(NodeProcessorContext* context, ASTNode* node) {
    if (!context || !node || node->child_count != 3) return 1;

    // Extraer IDENTIFIER
    ASTNode* id_node = node->children[0];
    if (!id_node || strcmp(id_node->type, "IDENTIFIER") != 0 || !id_node->value) return 1;
    const char* id_str = id_node->value;

    // Buscar símbolo
    Simbolo* simbolo = buscar_simbolo_en_scopes_combinado(context, id_str);
    if (!simbolo || simbolo->tipo_simbolo != SIMBOLO_VECTOR) return 1;

    // Extraer BRACKETS_INDICES
    ASTNode* brackets = node->children[1];
    if (!brackets || strcmp(brackets->type, "BRACKETS_INDICES") != 0) return 1;
    int num_indices = brackets->child_count;
    if (num_indices != simbolo->dimensiones) return 1;

    // Extraer índices
    int indices[3]; // Máximo 3D
    for (int i = 0; i < num_indices; i++) {
        ASTNode* indice_node = brackets->children[i];
        if (!indice_node || strcmp(indice_node->type, "INDICE") != 0 || indice_node->child_count < 1) return 1;
        ASTNode* dato = indice_node->children[0];
        if (!dato || strcmp(dato->type, "DATO") != 0 || dato->child_count < 1) return 1;
        ASTNode* int_lit = dato->children[0];
        if (!int_lit || strcmp(int_lit->type, "INT_LITERAL") != 0 || !int_lit->value) return 1;
        indices[i] = atoi(int_lit->value);
    }

    // Verificar límites
    for (int i = 0; i < num_indices; i++) {
        if (indices[i] < 0 || indices[i] >= simbolo->tamaños_dimensiones[i]) {
            char msg[256];
            snprintf(msg, sizeof(msg), "Índice fuera de límites en dimensión %d | Token: '%s'", i, id_str);
            if (global_error_manager) {
                error_manager_add_semantico(global_error_manager, node->line, node->column, msg, id_str,
                    context->scope_actual ? context->scope_actual->nombre : "global");
            }
            return 1;
        }
    }

    // Extraer VALOR_ASIGNACION
    ASTNode* valor_node = node->children[2];
    if (!valor_node || strcmp(valor_node->type, "VALOR_ASIGNACION") != 0 || valor_node->child_count < 1) return 1;
    ASTNode* dato_valor = valor_node->children[0];
    if (!dato_valor || strcmp(dato_valor->type, "DATO") != 0 || dato_valor->child_count < 1) return 1;
    ASTNode* int_lit_valor = dato_valor->children[0];
    if (!int_lit_valor || strcmp(int_lit_valor->type, "INT_LITERAL") != 0 || !int_lit_valor->value) return 1;
    int value = atoi(int_lit_valor->value);

    // Asignar valor según dimensiones
    if (simbolo->tipo_dato == TIPO_INT) {
        if (num_indices == 2) {
            simbolo->valores_int_2d[indices[0]][indices[1]] = value;
        } else if (num_indices == 3) {
            simbolo->valores_int_3d[indices[0]][indices[1]][indices[2]] = value;
        }
        // Para 1D, usa valores_int si es necesario
    }
    // Para otros tipos, no asignar (retornar 0 por defecto)

    return 0;
}
