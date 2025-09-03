//
// Created by lightdemon on 2/09/25.
//
#include "../../Headers/Procesador_casting.h"
#include "../../Headers/node_utils.h"
#include "../../Headers/globals.h"
#include "../../Headers/error_manager.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// ========== PROCESADOR PRINCIPAL DE CASTING ==========

char* process_cast_node(NodeProcessorContext* context, ASTNode* node) {
    if (!context || !node) {
        procesador_error_output(context, "Contexto o nodo NULL en casting");
        return NULL;
    }

    if (node->child_count < 2) {
        procesador_error_output(context, "Nodo CAST con estructura incorrecta");
        return NULL;
    }

    // Obtener tipo de destino del casting
    ASTNode* tipo_destino_node = node->children[0];
    ASTNode* expresion_node = node->children[1];

    if (!tipo_destino_node || !tipo_destino_node->value) {
        procesador_error_output(context, "Tipo de destino inválido en casting");
        return NULL;
    }

    const char* tipo_destino_str = tipo_destino_node->value;
    TipoDato tipo_destino = string_to_tipo_dato(tipo_destino_str);

    if (tipo_destino == TIPO_DESCONOCIDO) {
        char error_msg[256];
        snprintf(error_msg, sizeof(error_msg),
                "Tipo de casting desconocido: '%s'", tipo_destino_str);
        procesador_error_output(context, error_msg);
        return NULL;
    }

    // Obtener tipo y valor de la expresión origen
    TipoDato tipo_origen = obtener_tipo_desde_nodo(expresion_node, context);
    char* valor_origen = obtener_valor_desde_nodo(expresion_node, context);

    if (!valor_origen) {
        procesador_error_output(context, "No se pudo obtener valor de la expresión a castear");
        return NULL;
    }

    char debug_msg[256];
    snprintf(debug_msg, sizeof(debug_msg),
            "🎭 CASTING: (%s) %s → %s",
            tipo_destino_str, valor_origen, tipo_dato_to_string(tipo_destino));
    procesador_debug_output(context, debug_msg);

    // Verificar si el cast es válido
    if (!validar_cast(tipo_origen, tipo_destino)) {
        char error_msg[512];
        snprintf(error_msg, sizeof(error_msg),
                "Cast inválido: no se puede convertir %s a %s",
                tipo_dato_to_string(tipo_origen), tipo_dato_to_string(tipo_destino));

        // Registrar error semántico
        if (global_error_manager) {
            const char* scope_actual = "global";
            if (context->scope_actual && context->scope_actual->nombre) {
                scope_actual = context->scope_actual->nombre;
            }

            error_manager_add_semantico(global_error_manager,
                                      node->line, node->column,
                                      error_msg, tipo_destino_str,
                                      scope_actual);
        }

        procesador_error_output(context, error_msg);
        free(valor_origen);
        return NULL;
    }

    // Realizar la conversión
    char* valor_convertido = convertir_valor_cast(valor_origen, tipo_origen, tipo_destino);
    free(valor_origen);

    if (!valor_convertido) {
        procesador_error_output(context, "Error en la conversión de tipo");
        return NULL;
    }

    snprintf(debug_msg, sizeof(debug_msg),
            "✅ CASTING EXITOSO: %s → %s = %s",
            tipo_dato_to_string(tipo_origen), tipo_dato_to_string(tipo_destino), valor_convertido);
    procesador_debug_output(context, debug_msg);

    return valor_convertido;
}

// ========== VALIDACIÓN DE CASTING ==========

int validar_cast(TipoDato tipo_origen, TipoDato tipo_destino) {
    // Mismo tipo - siempre válido
    if (tipo_origen == tipo_destino) {
        return 1;
    }

    // Null a cualquier tipo de referencia - válido
    if (tipo_origen == TIPO_NULL && tipo_destino == TIPO_STRING) {
        return 1;
    }

    // Conversiones numéricas - todas permitidas con casting explícito
    if (es_tipo_numerico(tipo_origen) && es_tipo_numerico(tipo_destino)) {
        return 1;
    }

    // String a tipos primitivos (parseo) - válido
    if (tipo_origen == TIPO_STRING && es_tipo_numerico(tipo_destino)) {
        return 1;
    }

    // Cualquier tipo a String - válido
    if (tipo_destino == TIPO_STRING) {
        return 1;
    }

    // Boolean a tipos numéricos - válido (true=1, false=0)
    if (tipo_origen == TIPO_BOOLEAN && es_tipo_numerico(tipo_destino)) {
        return 1;
    }

    // Tipos numéricos a boolean - válido (0=false, no_cero=true)
    if (es_tipo_numerico(tipo_origen) && tipo_destino == TIPO_BOOLEAN) {
        return 1;
    }

    // Char es compatible con enteros
    if ((tipo_origen == TIPO_CHAR && es_tipo_numerico(tipo_destino)) ||
        (es_tipo_numerico(tipo_origen) && tipo_destino == TIPO_CHAR)) {
        return 1;
    }

    // Cast no válido
    return 0;
}

// ========== CONVERSIÓN DE VALORES ==========

char* convertir_valor_cast(const char* valor, TipoDato tipo_origen, TipoDato tipo_destino) {
    if (!valor) return NULL;

    char* resultado = malloc(64);
    if (!resultado) return NULL;

    // Mismo tipo - copia directa
    if (tipo_origen == tipo_destino) {
        strcpy(resultado, valor);
        return resultado;
    }

    // ===== CONVERSIONES DESDE CHAR - CASO ESPECIAL =====
    if (tipo_origen == TIPO_CHAR) {
        // Extraer el valor ASCII del carácter
        int ascii_value = extraer_valor_ascii_char(valor);

        switch (tipo_destino) {
            case TIPO_INT:
                snprintf(resultado, 64, "%d", ascii_value);
                return resultado;
            case TIPO_LONG:
                snprintf(resultado, 64, "%ld", (long)ascii_value);
                return resultado;
            case TIPO_FLOAT:
                snprintf(resultado, 64, "%.1f", (float)ascii_value);
                return resultado;
            case TIPO_DOUBLE:
                snprintf(resultado, 64, "%.1f", (double)ascii_value);
                return resultado;
            case TIPO_STRING:
                // Convertir el carácter a string (sin las comillas)
                if (ascii_value >= 32 && ascii_value <= 126) {
                    snprintf(resultado, 64, "%c", (char)ascii_value);
                } else {
                    snprintf(resultado, 64, "\\u%04X", ascii_value);
                }
                return resultado;
            case TIPO_BOOLEAN:
                // Cualquier carácter no-nulo es true
                strcpy(resultado, (ascii_value != 0) ? "true" : "false");
                return resultado;
            default:
                break;
        }
    }

    // Conversiones a String
    if (tipo_destino == TIPO_STRING) {
        if (tipo_origen == TIPO_NULL) {
            strcpy(resultado, "null");
        } else {
            strcpy(resultado, valor);
        }
        return resultado;
    }

    // Conversiones desde String
    if (tipo_origen == TIPO_STRING) {
        switch (tipo_destino) {
            case TIPO_INT:
                snprintf(resultado, 64, "%d", (int)atof(valor));
                return resultado;
            case TIPO_LONG:
                snprintf(resultado, 64, "%ld", (long)atof(valor));
                return resultado;
            case TIPO_FLOAT:
                snprintf(resultado, 64, "%.1f", (float)atof(valor));
                return resultado;
            case TIPO_DOUBLE:
                snprintf(resultado, 64, "%.1f", atof(valor));
                return resultado;
            case TIPO_CHAR:
                if (strlen(valor) > 0) {
                    snprintf(resultado, 64, "%c", valor[0]);
                } else {
                    strcpy(resultado, "\\0");
                }
                return resultado;
            case TIPO_BOOLEAN:
                if (strcmp(valor, "0") == 0 || strcmp(valor, "") == 0) {
                    strcpy(resultado, "false");
                } else {
                    strcpy(resultado, "true");
                }
                return resultado;
            default:
                break;
        }
    }

    // Conversiones numéricas (excluyendo char que ya se manejó arriba)
    if (es_tipo_numerico(tipo_origen) && es_tipo_numerico(tipo_destino) && tipo_origen != TIPO_CHAR) {
        double valor_num = convertir_a_decimal(valor);

        switch (tipo_destino) {
            case TIPO_BYTE:                                           // ← AÑADIR
                snprintf(resultado, 64, "%d", (signed char)valor_num);
                return resultado;
            case TIPO_SHORT:                                          // ← AÑADIR
                snprintf(resultado, 64, "%d", (short)valor_num);
                return resultado;
            case TIPO_INT:
                snprintf(resultado, 64, "%d", (int)valor_num);
                return resultado;
            case TIPO_LONG:
                snprintf(resultado, 64, "%ld", (long)valor_num);
                return resultado;
            case TIPO_FLOAT:
                snprintf(resultado, 64, "%.1f", (float)valor_num);
                return resultado;
            case TIPO_DOUBLE:
                if (valor_num == (long)valor_num) {
                    snprintf(resultado, 64, "%.1f", valor_num);
                } else {
                    snprintf(resultado, 64, "%.6g", valor_num);
                }
                return resultado;
            case TIPO_CHAR:
                snprintf(resultado, 64, "%c", (char)((int)valor_num));
                return resultado;
            default:
                break;
        }
    }

    // ===== CONVERSIONES A CHAR DESDE TIPOS NUMÉRICOS =====
    if (tipo_destino == TIPO_CHAR && es_tipo_numerico(tipo_origen)) {
        double valor_num = convertir_a_decimal(valor);
        int ascii_val = (int)valor_num;

        // Asegurar que esté en rango ASCII válido
        if (ascii_val >= 0 && ascii_val <= 127) {
            snprintf(resultado, 64, "'%c'", (char)ascii_val);
        } else {
            snprintf(resultado, 64, "'\\u%04X'", ascii_val);
        }
        return resultado;
    }

    // Conversiones Boolean
    if (tipo_origen == TIPO_BOOLEAN) {
        int bool_val = (strcmp(valor, "true") == 0) ? 1 : 0;

        switch (tipo_destino) {
            case TIPO_INT:
                snprintf(resultado, 64, "%d", bool_val);
                return resultado;
            case TIPO_LONG:
                snprintf(resultado, 64, "%ld", (long)bool_val);
                return resultado;
            case TIPO_FLOAT:
                snprintf(resultado, 64, "%.1f", (float)bool_val);
                return resultado;
            case TIPO_DOUBLE:
                snprintf(resultado, 64, "%.1f", (double)bool_val);
                return resultado;
            case TIPO_CHAR:
                snprintf(resultado, 64, "'%c'", bool_val ? '1' : '0');
                return resultado;
            default:
                break;
        }
    }

    // Conversiones a Boolean
    if (tipo_destino == TIPO_BOOLEAN) {
        if (es_tipo_numerico(tipo_origen)) {
            double num_val = convertir_a_decimal(valor);
            strcpy(resultado, (num_val != 0.0) ? "true" : "false");
            return resultado;
        }
    }

    // Si llegamos aquí, la conversión falló
    free(resultado);
    return NULL;
}

// ========== FUNCIONES AUXILIARES ==========

long convertir_a_entero(const char* valor) {
    if (!valor) return 0;

    // Limpiar sufijos (L, f, d, etc.)
    char* valor_limpio = strdup(valor);
    int len = strlen(valor_limpio);

    if (len > 1) {
        char ultimo = valor_limpio[len-1];
        if (ultimo == 'L' || ultimo == 'l' ||
            ultimo == 'F' || ultimo == 'f' ||
            ultimo == 'D' || ultimo == 'd') {
            valor_limpio[len-1] = '\0';
        }
    }

    long resultado = atol(valor_limpio);
    free(valor_limpio);
    return resultado;
}

double convertir_a_decimal(const char* valor) {
    if (!valor) return 0.0;

    // Limpiar sufijos
    char* valor_limpio = strdup(valor);
    int len = strlen(valor_limpio);

    if (len > 1) {
        char ultimo = valor_limpio[len-1];
        if (ultimo == 'L' || ultimo == 'l' ||
            ultimo == 'F' || ultimo == 'f' ||
            ultimo == 'D' || ultimo == 'd') {
            valor_limpio[len-1] = '\0';
        }
    }

    double resultado = atof(valor_limpio);
    free(valor_limpio);
    return resultado;
}
int extraer_valor_ascii_char(const char* char_str) {
    if (!char_str) return 0;

    int len = strlen(char_str);

    // Caso 1: 'X' (con comillas simples)
    if (len >= 3 && char_str[0] == '\'' && char_str[len-1] == '\'') {
        // Extraer el carácter entre comillas
        char ch = char_str[1];

        // Manejar secuencias de escape básicas
        if (ch == '\\' && len >= 4) {
            char escape = char_str[2];
            switch (escape) {
                case 'n': return 10;  // \n
                case 't': return 9;   // \t
                case 'r': return 13;  // \r
                case '0': return 0;   // \0
                case '\\': return 92; // \\
                case '\'': return 39; // \'
                default: return (int)escape;
            }
        }

        return (int)ch;
    }

    // Caso 2: X (sin comillas - carácter directo)
    if (len == 1) {
        return (int)char_str[0];
    }

    // Caso 3: Secuencia de escape Unicode \uXXXX
    if (len >= 6 && char_str[0] == '\\' && char_str[1] == 'u') {
        // Parsear hexadecimal después de \u
        int unicode_val = 0;
        for (int i = 2; i < 6 && i < len; i++) {
            char hex_digit = char_str[i];
            unicode_val *= 16;
            if (hex_digit >= '0' && hex_digit <= '9') {
                unicode_val += hex_digit - '0';
            } else if (hex_digit >= 'A' && hex_digit <= 'F') {
                unicode_val += hex_digit - 'A' + 10;
            } else if (hex_digit >= 'a' && hex_digit <= 'f') {
                unicode_val += hex_digit - 'a' + 10;
            }
        }
        return unicode_val;
    }

    // Por defecto, retornar el primer carácter
    return (int)char_str[0];
}