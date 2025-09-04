//
// Created by lightdemon on 3/09/25.
//
#include "../../../Headers/Procesador_Sout.h"
#include "../../../Headers/Procesador_Expresion.h"
#include "../../../Headers/node_utils.h"
#include "../../../Headers/mainview.h"
#include "../../Headers/Procesador_Vectores.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ===== FUNCIÓN PRINCIPAL =====
char* process_sout_node(NodeProcessorContext* context, ASTNode* node) {
    if (!context || !node) {
        printf("❌ ERROR SOUT: Contexto o nodo nulo\n");
        return NULL;
    }

    debug_sout_inicio(context, node);

    // Validar estructura del nodo
    if (!validar_nodo_sout(node)) {
        debug_sout_error(context, "Estructura de nodo SOUT inválida");
        return NULL;
    }

    // Evaluar el SOUT completo
    ResultadoSout resultado = evaluar_sout_completo(context, node);

    if (!resultado.exitoso) {
        debug_sout_error(context, "Error evaluando expresión SOUT");
        liberar_resultado_sout(&resultado);
        return NULL;
    }

    // ===== IMPRIMIR EN CONSOLA (SIMULACIÓN DE JAVA) =====
    printf("🖨️  SOUT OUTPUT: %s\n", resultado.contenido_impreso);

    // ===== ENVIAR A GUI SI ESTÁ DISPONIBLE =====
    if (context->mainview) {
        // CAMBIO: Enviar a CONSOLA en lugar de output
        char console_output[1024];
        snprintf(console_output, sizeof(console_output), "%s", resultado.contenido_impreso);
        mainview_append_console(context->mainview, console_output);

        // TAMBIÉN mantener el output para debug
        char gui_output[1024];
        snprintf(gui_output, sizeof(gui_output), "[SOUT] %s", resultado.contenido_impreso);
        mainview_append_output(context->mainview, gui_output);
    }

    debug_sout_resultado(context, resultado.contenido_impreso);

    // Retornar copia del resultado
    char* retorno = strdup(resultado.contenido_impreso);
    liberar_resultado_sout(&resultado);

    return retorno;
}

// ===== EVALUACIÓN COMPLETA DEL SOUT =====
ResultadoSout evaluar_sout_completo(NodeProcessorContext* context, ASTNode* node) {
    ResultadoSout resultado = {0};
    resultado.linea = node->line;
    resultado.tipo_final = TIPO_STRING;

    // El SOUT debe tener exactamente 1 hijo (la expresión a imprimir)
    if (node->child_count != 1) {
        printf("❌ ERROR SOUT: Se esperaba 1 expresión, encontradas %d\n", node->child_count);
        return resultado;
    }

    ASTNode* expresion = node->children[0];
    if (!expresion) {
        printf("❌ ERROR SOUT: Expresión nula\n");
        return resultado;
    }

    // Evaluar la expresión para SOUT
    char* contenido = evaluar_expresion_para_sout(context, expresion);
    if (!contenido) {
        printf("❌ ERROR SOUT: No se pudo evaluar la expresión\n");
        return resultado;
    }

    resultado.contenido_impreso = contenido;
    resultado.exitoso = 1;

    if (context->modo_debug) {
        printf("🔍 DEBUG SOUT: Expresión evaluada exitosamente\n");
        printf("   → Tipo expresión: %s\n", expresion->type);
        printf("   → Contenido: '%s'\n", contenido);
    }

    return resultado;
}

// ===== EVALUACIÓN DE EXPRESIONES PARA SOUT =====
char* evaluar_expresion_para_sout(NodeProcessorContext* context, ASTNode* expresion) {
    if (!expresion) return NULL;

    if (context->modo_debug) {
        printf("🔍 DEBUG SOUT: Evaluando expresión tipo '%s'\n", expresion->type);
    }

    // ===== CASO 1: DATO SIMPLE =====
    if (strcmp(expresion->type, "DATO") == 0) {
        // CORREGIR: pasar context en lugar de &tipo_dato
        char* valor = obtener_valor_desde_nodo(expresion, context);
        if (valor) {
            // Obtener el tipo usando la función correcta
            TipoDato tipo_dato = obtener_tipo_desde_nodo(expresion, context);
            char* resultado = convertir_a_string_para_sout(valor, tipo_dato);
            free(valor);
            return resultado;
        }
    }

    // ===== CASO 2: IDENTIFICADOR (VARIABLE) =====
    else if (strcmp(expresion->type, "IDENTIFIER") == 0) {
        // CORREGIR: pasar context en lugar de &tipo_variable
        char* valor = obtener_valor_desde_nodo(expresion, context);
        if (valor) {
            // Obtener el tipo usando la función correcta
            TipoDato tipo_variable = obtener_tipo_desde_nodo(expresion, context);
            char* resultado = convertir_a_string_para_sout(valor, tipo_variable);
            free(valor);
            return resultado;
        }
    }

    // ===== CASO 3: EXPRESIÓN BINARIA (CONCATENACIÓN U OPERACIÓN) =====
    else if (strcmp(expresion->type, "EXPRESION_BINARIA") == 0) {
        return procesar_concatenacion_sout(context, expresion);
    }

    // ===== CASO 4: ACCESO A ARRAY =====
    else if (strcmp(expresion->type, "ARRAY_ACCESO_MULTIDIMENSIONAL") == 0) {
        return procesar_array_acceso_sout(context, expresion);
    }

    // ===== CASO 5: EXPRESIÓN COMPLEJA - DELEGAR AL PROCESADOR GENERAL =====
    else {
        printf("🔍 DEBUG SOUT: Delegando expresión '%s' al procesador general\n", expresion->type);
        char* resultado_expresion = process_expresion_node(context, expresion);
        if (resultado_expresion) {
            // Asegurar que el resultado sea una cadena válida para imprimir
            char* resultado_final = convertir_a_string_para_sout(resultado_expresion, TIPO_STRING);
            free(resultado_expresion);
            return resultado_final;
        }
    }

    printf("❌ ERROR SOUT: No se pudo evaluar expresión tipo '%s'\n", expresion->type);
    return NULL;
}

char* procesar_string_con_escapes(const char* valor) {
    if (!valor) return strdup("null");

    char* resultado = malloc(1024);
    if (!resultado) return NULL;

    int len = strlen(valor);
    int i = 0, j = 0;

    // Verificar si tiene comillas y saltarlas
    if (len >= 2 && valor[0] == '"' && valor[len-1] == '"') {
        i = 1;           // Empezar después de la primera comilla
        len = len - 1;   // Terminar antes de la última comilla
    }

    // Procesar caracter por caracter
    while (i < len && j < 1023) {
        if (valor[i] == '\\' && i + 1 < len) {
            // Procesar secuencia de escape
            switch (valor[i + 1]) {
                case '"':   // \"
                    resultado[j++] = '"';
                    i += 2;
                    break;
                case '\\':  // \\
                    resultado[j++] = '\\';
                    i += 2;
                    break;
                case 'n':   // \n
                    resultado[j++] = '\n';
                    i += 2;
                    break;
                case 'r':   // \r
                    resultado[j++] = '\r';
                    i += 2;
                    break;
                case 't':   // \t
                    resultado[j++] = '\t';
                    i += 2;
                    break;
                default:
                    // Secuencia desconocida, copiar tal como está
                    resultado[j++] = valor[i++];
                    break;
            }
        } else {
            // Caracter normal
            resultado[j++] = valor[i++];
        }
    }

    resultado[j] = '\0';
    return resultado;
}


// ===== NUEVA FUNCIÓN: PROCESAR CHAR CON SECUENCIAS DE ESCAPE =====
char* procesar_char_con_escapes(const char* valor) {
    if (!valor) return strdup("null");

    char* resultado = malloc(8);  // Suficiente para un char procesado
    if (!resultado) return NULL;

    int len = strlen(valor);

    // Verificar si tiene comillas simples y procesarlo
    if (len >= 3 && valor[0] == '\'' && valor[len-1] == '\'') {
        // Char con comillas: 'a', '\n', etc.
        if (valor[1] == '\\' && len >= 4) {
            // Secuencia de escape
            switch (valor[2]) {
                case 'n':
                    resultado[0] = '\n';
                    break;
                case 't':
                    resultado[0] = '\t';
                    break;
                case 'r':
                    resultado[0] = '\r';
                    break;
                case '\\':
                    resultado[0] = '\\';
                    break;
                case '\'':
                    resultado[0] = '\'';
                    break;
                default:
                    resultado[0] = valor[2];
                    break;
            }
        } else {
            // Char simple
            resultado[0] = valor[1];
        }
        resultado[1] = '\0';
    } else {
        // Sin comillas, copiar tal como está
        strcpy(resultado, valor);
    }

    return resultado;
}

// ===== CONVERSIÓN A STRING PARA SOUT =====
char* convertir_a_string_para_sout(const char* valor, TipoDato tipo) {
    if (!valor) return strdup("null");

    char* resultado = malloc(1024);  // Aumentar tamaño para secuencias de escape
    if (!resultado) return NULL;

    switch (tipo) {
        case TIPO_STRING:
            // Procesar string con secuencias de escape
            return procesar_string_con_escapes(valor);

        case TIPO_CHAR:
            // Procesar char con secuencias de escape
            return procesar_char_con_escapes(valor);

        case TIPO_BOOLEAN:
            // Convertir true/false a string
            strcpy(resultado, valor);
            break;

        case TIPO_NULL:
            strcpy(resultado, "null");
            break;

        case TIPO_INT:
        case TIPO_LONG:
        case TIPO_SHORT:
        case TIPO_BYTE:
        case TIPO_FLOAT:
        case TIPO_DOUBLE:
        default:
            // Para números y otros tipos, copiar tal como están
            strcpy(resultado, valor);
            break;
    }

    return resultado;
}


// ===== PROCESAMIENTO DE CONCATENACIÓN =====
char* procesar_concatenacion_sout(NodeProcessorContext* context, ASTNode* expr_binaria) {
    if (!expr_binaria || !expr_binaria->value) return NULL;

    if (context->modo_debug) {
        printf("🔍 DEBUG SOUT: Procesando expresión binaria '%s'\n", expr_binaria->value);
    }

    // Para SOUT, principalmente manejamos concatenación (+) y operaciones aritméticas
    if (strcmp(expr_binaria->value, "+") == 0) {
        // Usar el procesador de expresiones que ya maneja concatenación
        return process_expresion_node(context, expr_binaria);
    } else {
        // Para otras operaciones (-, *, /, etc.), también usar el procesador general
        char* resultado_operacion = process_expresion_node(context, expr_binaria);
        if (resultado_operacion) {
            return convertir_a_string_para_sout(resultado_operacion, TIPO_STRING);
        }
    }

    return NULL;
}

// ===== PROCESAMIENTO DE ACCESO A ARRAYS =====
char* procesar_array_acceso_sout(NodeProcessorContext* context, ASTNode* array_node) {
    if (!array_node) return NULL;

    printf("🔍 DEBUG SOUT: Procesando acceso a array\n");

    // Acceso a vector unidimensional (int[])
    int valor = procesar_acceso_vector(context, array_node);

    // Si hubo error semántico, puedes retornar un mensaje especial
    if (valor == 1) {
        return strdup("[Error de acceso a vector]");
    }

    // Convertir el valor int a string para SOUT
    char* resultado = malloc(32);
    snprintf(resultado, 32, "%d", valor);
    return resultado;
}

// ===== FUNCIONES DE VALIDACIÓN =====
int validar_nodo_sout(ASTNode* node) {
    if (!node) return 0;
    if (strcmp(node->type, "SOUT") != 0) return 0;
    if (node->child_count != 1) return 0;
    return es_expresion_valida_para_sout(node->children[0]);
}

int es_expresion_valida_para_sout(ASTNode* expresion) {
    if (!expresion) return 0;

    // Lista de tipos de expresión válidos para SOUT
    const char* tipos_validos[] = {
        "DATO", "IDENTIFIER", "EXPRESION_BINARIA", "EXPRESION_UNARIA",
        "ARRAY_ACCESO_MULTIDIMENSIONAL", "EXPRESION_PARENTESIS",
        "CAST", NULL
    };

    for (int i = 0; tipos_validos[i] != NULL; i++) {
        if (strcmp(expresion->type, tipos_validos[i]) == 0) {
            return 1;
        }
    }

    return 0;
}

// ===== FUNCIONES DE DEBUG =====
void debug_sout_inicio(NodeProcessorContext* context, ASTNode* node) {
    if (!context || !context->modo_debug) return;

    printf("🖨️  DEBUG SOUT: Iniciando procesamiento en línea %d\n", node->line);
    printf("   → Tipo nodo: %s\n", node->type);
    printf("   → Número de expresiones: %d\n", node->child_count);

    if (context->mainview) {
        char debug_msg[256];
        snprintf(debug_msg, sizeof(debug_msg), "[DEBUG SOUT] Procesando System.out.println en línea %d", node->line);
        mainview_append_output(context->mainview, debug_msg);
    }
}

void debug_sout_resultado(NodeProcessorContext* context, const char* resultado) {
    if (!context || !context->modo_debug) return;

    printf("✅ DEBUG SOUT: Resultado final: '%s'\n", resultado);

    if (context->mainview) {
        char debug_msg[512];
        snprintf(debug_msg, sizeof(debug_msg), "[DEBUG SOUT] Salida generada: %s", resultado);
        mainview_append_output(context->mainview, debug_msg);
    }
}

void debug_sout_error(NodeProcessorContext* context, const char* mensaje) {
    printf("❌ DEBUG SOUT ERROR: %s\n", mensaje);

    if (context && context->mainview) {
        char error_msg[256];
        snprintf(error_msg, sizeof(error_msg), "[ERROR SOUT] %s", mensaje);
        mainview_append_output(context->mainview, error_msg);
    }
}

// ===== LIBERACIÓN DE MEMORIA =====
void liberar_resultado_sout(ResultadoSout* resultado) {
    if (!resultado) return;

    if (resultado->contenido_impreso) {
        free(resultado->contenido_impreso);
        resultado->contenido_impreso = NULL;
    }

    resultado->exitoso = 0;
}