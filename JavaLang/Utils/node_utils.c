//
// Created by lightdemon on 2/09/25.
//

#include "../Headers/node_utils.h"
#include "../Headers/globals.h"
#include "../Headers/error_manager.h"
#include "../Headers/Tabla_Simbolos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Procesador_casting.h"

// ===== DECLARACIONES FORWARD PARA EVITAR DEPENDENCIAS CIRCULARES =====
extern char* process_expresion_node(NodeProcessorContext* context, ASTNode* node);

// ===== FUNCIONES PRINCIPALES =====

TipoDato obtener_tipo_desde_nodo(ASTNode* node, NodeProcessorContext* context) {
    if (!node) return TIPO_DESCONOCIDO;

    // Navegar hasta el dato real
    if (strcmp(node->type, "DATO") == 0 && node->children && node->child_count > 0) {
        ASTNode* literal_node = node->children[0];

        if (strcmp(literal_node->type, "INT_LITERAL") == 0) {
            return TIPO_INT;
        } else if (strcmp(literal_node->type, "LONG_LITERAL") == 0) {
            return TIPO_LONG;  // NUEVO TIPO
        } else if (strcmp(literal_node->type, "FLOAT_LITERAL") == 0) {
            return TIPO_FLOAT;
        } else if (strcmp(literal_node->type, "DOUBLE_LITERAL") == 0) {
            return TIPO_DOUBLE;
        } else if (strcmp(literal_node->type, "STRING_LITERAL") == 0) {
            return TIPO_STRING;
        } else if (strcmp(literal_node->type, "CHAR_LITERAL") == 0) {
            return TIPO_CHAR;
        } else if (strcmp(literal_node->type, "BOOLEAN_LITERAL") == 0) {
            return TIPO_BOOLEAN;
        } else if (strcmp(literal_node->type, "NULL_LITERAL") == 0) {
            return TIPO_NULL;
        }
    }

    // === MANEJAR LITERALES DIRECTOS ===
    if (strcmp(node->type, "LONG_LITERAL") == 0) {
        return TIPO_LONG;  // NUEVO CASO
    }

    // Si es directamente un literal NULL (sin nodo DATO intermedio)
    if (strcmp(node->type, "NULL_LITERAL") == 0) {
        return TIPO_NULL;
    }

    // ===== MANEJO PARA EXPRESIONES UNARIAS =====
    if (strcmp(node->type, "EXPRESION_UNARIA") == 0) {
        if (node->value && node->child_count > 0) {
            // Para operadores unarios aritméticos, el tipo es el del operando
            if (strcmp(node->value, "-") == 0 || strcmp(node->value, "+") == 0) {
                TipoDato tipo_operando = obtener_tipo_desde_nodo(node->children[0], context);
                // Verificar que el operando sea numérico
                if (es_tipo_numerico(tipo_operando)) {
                    return tipo_operando; // El tipo se preserva: -int = int, -float = float
                }
                return TIPO_DESCONOCIDO; // Error: operador unario en tipo no numérico
            }
            // Para otros operadores unarios (!expr, ++expr, --expr)
            else if (strcmp(node->value, "!") == 0) {
                return TIPO_BOOLEAN; // !expr siempre es boolean
            }
            else if (strcmp(node->value, "++") == 0 || strcmp(node->value, "--") == 0) {
                // ++var, --var mantienen el tipo de la variable
                return obtener_tipo_desde_nodo(node->children[0], context);
            }
        }
        return TIPO_DESCONOCIDO;
    }

    // Si es directamente un identificador, buscar en tabla de símbolos
    if (strcmp(node->type, "IDENTIFIER") == 0 && node->value && context && context->tabla_simbolos) {
        Simbolo* simbolo = buscar_simbolo(context->tabla_simbolos, node->value);
        if (simbolo) {
            if (context->modo_debug) {
                printf("DEBUG NODE_UTILS: Identificador '%s' encontrado - tipo: %s, valor: %s\n",
                       node->value, tipo_dato_to_string(simbolo->tipo_dato), simbolo->valor);
            }
            return simbolo->tipo_dato;
        } else {
            if (context->modo_debug) {
                printf("DEBUG NODE_UTILS: Identificador '%s' NO encontrado en tabla de símbolos\n", node->value);
            }
            return TIPO_DESCONOCIDO;
        }
    }
    if (strcmp(node->type, "CAST") == 0 && node->child_count >= 1) {
        // El tipo del cast es el tipo de destino (primer hijo)
        ASTNode* tipo_destino = node->children[0];
        if (tipo_destino && tipo_destino->value) {
            return string_to_tipo_dato(tipo_destino->value);
        }
    }
    // Si es una expresión binaria, evaluar recursivamente
    if (strcmp(node->type, "EXPRESION_BINARIA") == 0 && node->child_count >= 2) {
        TipoDato tipo_izq = obtener_tipo_desde_nodo(node->children[0], context);
        TipoDato tipo_der = obtener_tipo_desde_nodo(node->children[1], context);

        // Aplicar reglas de promoción de tipos para la expresión
        if (node->value) {
            if (strcmp(node->value, "+") == 0) {
                // Para suma: string + cualquier_cosa = string, sino promoción numérica
                if (tipo_izq == TIPO_STRING || tipo_der == TIPO_STRING) {
                    return TIPO_STRING;
                }
                return promocionar_tipos(tipo_izq, tipo_der);
            }
            else if (strcmp(node->value, "-") == 0 || strcmp(node->value, "*") == 0 || strcmp(node->value, "/") == 0) {
                // Para resta, multiplicación, división: solo numéricos
                if (tipos_compatibles_aritmetica(tipo_izq, tipo_der)) {
                    return promocionar_tipos(tipo_izq, tipo_der);
                }
                return TIPO_DESCONOCIDO;
            }
            // Agregar más operadores según sea necesario
        }
        return TIPO_DESCONOCIDO;
    }

    return TIPO_DESCONOCIDO;
}

char* obtener_valor_desde_nodo(ASTNode* node, NodeProcessorContext* context) {
    if (!node) return NULL;

    printf("🔍 DEBUG obtener_valor_desde_nodo: procesando '%s' con valor '%s'\n",
           node->type, node->value ? node->value : "NULL");

    // Si es un DATO, extraer el valor del literal
    if (strcmp(node->type, "DATO") == 0 && node->children && node->child_count > 0) {
        ASTNode* literal_node = node->children[0];
        if (literal_node->value) {
            printf("   → DATO encontrado: %s = %s\n", literal_node->type, literal_node->value);
            return strdup(literal_node->value);
        }
    }

    // ===== MANEJO ESPECIAL PARA CASTING =====
    if (strcmp(node->type, "CAST") == 0) {
        printf("   → CAST detectado, delegando al procesador\n");
        // Para casting, usar el procesador especializado
        return process_cast_node(context, node);
    }

    // ===== MANEJO ESPECIAL PARA NULL =====
    if (strcmp(node->type, "NULL_LITERAL") == 0) {
        return strdup("null");
    }

    // Si es un identificador, buscar en tabla de símbolos
    if (strcmp(node->type, "IDENTIFIER") == 0 && node->value && context && context->tabla_simbolos) {
        printf("   → IDENTIFIER '%s' - buscando en tabla de símbolos\n", node->value);

        Simbolo* simbolo = buscar_simbolo(context->tabla_simbolos, node->value);
        if (simbolo) {
            printf("   → ✅ Variable '%s' encontrada con valor: '%s'\n", node->value, simbolo->valor);
            // Incrementar uso del símbolo
            incrementar_uso_simbolo(context->tabla_simbolos, node->value);
            return strdup(simbolo->valor);
        } else {
            printf("   → ❌ Variable '%s' NO encontrada en tabla de símbolos\n", node->value);

            // Registrar error semántico por variable no declarada
            if (global_error_manager) {
                char error_msg[256];
                snprintf(error_msg, sizeof(error_msg), "Variable '%s' no ha sido declarada", node->value);

                const char* scope_actual = "global";
                if (context->scope_actual && context->scope_actual->nombre) {
                    scope_actual = context->scope_actual->nombre;
                } else if (context->tabla_simbolos && context->tabla_simbolos->ambito_actual) {
                    scope_actual = context->tabla_simbolos->ambito_actual;
                }

                error_manager_add_semantico(global_error_manager,
                                          node->line, node->column,
                                          error_msg, node->value,
                                          scope_actual);
            }
            return NULL;
        }
    }

    // ===== MANEJO PARA EXPRESIONES BINARIAS =====
    if (strcmp(node->type, "EXPRESION_BINARIA") == 0) {
        printf("   → EXPRESION_BINARIA detectada, delegando al procesador\n");
        // Para expresiones binarias, usar el procesador de expresiones
        return process_expresion_node(context, node);
    }

    // Si tiene valor directo (SOLO para nodos que NO son expresiones)
    if (node->value && strcmp(node->type, "EXPRESION_BINARIA") != 0) {
        printf("   → Valor directo encontrado: %s\n", node->value);
        return strdup(node->value);
    }

    printf("   → ❌ No se pudo obtener valor del nodo\n");
    return NULL;
}

// ===== FUNCIONES AUXILIARES =====

double convertir_a_numero(const char* valor, TipoDato tipo) {
    if (!valor) return 0.0;

    // Crear copia para manipular
    char* valor_limpio = strdup(valor);
    int len = strlen(valor_limpio);

    // === REMOVER SUFIJOS ===
    if (len > 1) {
        char ultimo = valor_limpio[len-1];
        if (ultimo == 'f' || ultimo == 'F' ||
            ultimo == 'd' || ultimo == 'D' ||
            ultimo == 'l' || ultimo == 'L') {
            valor_limpio[len-1] = '\0';  // Remover sufijo
            }
    }

    double resultado = atof(valor_limpio);
    free(valor_limpio);

    return resultado;
}

char* convertir_numero_a_string(double valor, TipoDato tipo) {
    char* resultado = malloc(64);

    switch (tipo) {
        case TIPO_BYTE:
            snprintf(resultado, 64, "%d", (signed char)valor);
            break;
        case TIPO_SHORT:
            snprintf(resultado, 64, "%d", (short)valor);
            break;
        case TIPO_INT:
            snprintf(resultado, 64, "%d", (int)valor);
            break;
        case TIPO_LONG:
            snprintf(resultado, 64, "%ld", (long)valor);
            break;
        case TIPO_FLOAT:
            snprintf(resultado, 64, "%.1f", (float)valor);
            break;
        case TIPO_DOUBLE:
            if (valor == (long)valor) {
                snprintf(resultado, 64, "%.1f", valor);
            } else {
                snprintf(resultado, 64, "%.6g", valor);
            }
            break;
        case TIPO_CHAR:
            snprintf(resultado, 64, "%c", (char)((int)valor));
            break;
        default:
            snprintf(resultado, 64, "%.6g", valor);
            break;
    }

    return resultado;
}

int es_tipo_numerico(TipoDato tipo) {
    return (tipo == TIPO_INT ||
            tipo == TIPO_LONG ||
            tipo == TIPO_SHORT ||
            tipo == TIPO_BYTE ||
            tipo == TIPO_FLOAT ||
            tipo == TIPO_DOUBLE ||
            tipo == TIPO_CHAR);
}

int es_nodo_expresion(const char* node_type) {
    if (!node_type) return 0;

    return (strcmp(node_type, "EXPRESION_BINARIA") == 0 ||
            strcmp(node_type, "EXPRESION_UNARIA") == 0 ||
            strcmp(node_type, "EXPRESION_POSTFIJO") == 0 ||
            strcmp(node_type, "EXPRESION_PARENTESIS") == 0 ||
            strcmp(node_type, "DATO") == 0 ||
            strcmp(node_type, "IDENTIFIER") == 0);
}

TipoDato promocionar_tipos(TipoDato tipo1, TipoDato tipo2) {
    // ===== NULL PRODUCE TIPO DESCONOCIDO =====
    if (tipo1 == TIPO_NULL || tipo2 == TIPO_NULL) {
        return TIPO_DESCONOCIDO;
    }

    // ===== PROMOCIÓN NUMÉRICA SEGÚN JAVA =====
    // double > float > long > int > char
    if (tipo1 == TIPO_DOUBLE || tipo2 == TIPO_DOUBLE) {
        return TIPO_DOUBLE;
    }
    if (tipo1 == TIPO_FLOAT || tipo2 == TIPO_FLOAT) {
        return TIPO_FLOAT;
    }
    if (tipo1 == TIPO_LONG || tipo2 == TIPO_LONG) {      // ← AÑADIR ESTA LÍNEA
        return TIPO_LONG;
    }
    if (tipo1 == TIPO_INT || tipo2 == TIPO_INT) {
        return TIPO_INT;
    }
    if (tipo1 == TIPO_CHAR && tipo2 == TIPO_CHAR) {
        return TIPO_INT; // char + char = int en Java
    }

    return TIPO_INT; // Valor por defecto
}

int tipos_compatibles_aritmetica(TipoDato tipo1, TipoDato tipo2) {
    // ===== NULL NO ES COMPATIBLE =====
    if (tipo1 == TIPO_NULL || tipo2 == TIPO_NULL) {
        return 0;
    }

    // ===== SOLO TIPOS NUMÉRICOS SON COMPATIBLES =====
    return (es_tipo_numerico(tipo1) && es_tipo_numerico(tipo2));
}


int es_promocion_automatica(TipoDato tipo_origen, TipoDato tipo_destino) {
    // Promociones automáticas válidas en Java:
    // byte -> short -> int -> long -> float -> double
    // char -> int -> long -> float -> double

    if (tipo_origen == tipo_destino) return 0; // No hay promoción

    // byte -> short, int, long, float, double
    if (tipo_origen == TIPO_BYTE &&
        (tipo_destino == TIPO_SHORT || tipo_destino == TIPO_INT ||
         tipo_destino == TIPO_LONG || tipo_destino == TIPO_FLOAT ||
         tipo_destino == TIPO_DOUBLE)) {
        return 1;
         }

    // short -> int, long, float, double
    if (tipo_origen == TIPO_SHORT &&
        (tipo_destino == TIPO_INT || tipo_destino == TIPO_LONG ||
         tipo_destino == TIPO_FLOAT || tipo_destino == TIPO_DOUBLE)) {
        return 1;
         }

    // char -> int, long, float, double
    if (tipo_origen == TIPO_CHAR &&
        (tipo_destino == TIPO_INT || tipo_destino == TIPO_LONG ||
         tipo_destino == TIPO_FLOAT || tipo_destino == TIPO_DOUBLE)) {
        return 1;
         }

    // int -> long, float, double
    if (tipo_origen == TIPO_INT &&
        (tipo_destino == TIPO_LONG || tipo_destino == TIPO_FLOAT ||
         tipo_destino == TIPO_DOUBLE)) {
        return 1;
         }

    // long -> float, double
    if (tipo_origen == TIPO_LONG &&
        (tipo_destino == TIPO_FLOAT || tipo_destino == TIPO_DOUBLE)) {
        return 1;
        }

    // float -> double
    if (tipo_origen == TIPO_FLOAT && tipo_destino == TIPO_DOUBLE) {
        return 1;
    }

    return 0;
}