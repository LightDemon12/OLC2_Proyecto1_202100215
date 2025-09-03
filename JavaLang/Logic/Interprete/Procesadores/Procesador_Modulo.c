//
// Created by lightdemon on 2/09/25.
//
#include "../../../Headers/Procesador_Modulo.h"
#include "../../../Headers/node_processor.h"
#include "../../Headers/mainview.h"
#include "../../../Headers/globals.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "node_utils.h"

// Función para verificar si dos tipos son compatibles para módulo
int tipos_compatibles_modulo(TipoDato tipo1, TipoDato tipo2) {
    // ===== NULL NO ES COMPATIBLE CON NADA EN OPERACIONES ARITMÉTICAS =====
    if (tipo1 == TIPO_NULL || tipo2 == TIPO_NULL) {
        return 0; // NULL % cualquier_cosa = ERROR
    }

    // ===== EL MÓDULO SOLO ES VÁLIDO ENTRE TIPOS NUMÉRICOS =====
    // En Java: int % int, float % float, double % double, etc.
    if ((tipo1 == TIPO_INT || tipo1 == TIPO_FLOAT || tipo1 == TIPO_DOUBLE ||
         tipo1 == TIPO_LONG || tipo1 == TIPO_BYTE || tipo1 == TIPO_SHORT || tipo1 == TIPO_CHAR) &&
        (tipo2 == TIPO_INT || tipo2 == TIPO_FLOAT || tipo2 == TIPO_DOUBLE ||
         tipo2 == TIPO_LONG || tipo2 == TIPO_BYTE || tipo2 == TIPO_SHORT || tipo2 == TIPO_CHAR)) {
        return 1;
    }

    // ===== STRING NO ES COMPATIBLE CON MÓDULO =====
    // En Java: "Hello" % "World" = ERROR
    if (tipo1 == TIPO_STRING || tipo2 == TIPO_STRING) {
        return 0;
    }

    // ===== BOOLEAN NO ES COMPATIBLE CON OPERACIONES ARITMÉTICAS =====
    if (tipo1 == TIPO_BOOLEAN || tipo2 == TIPO_BOOLEAN) {
        return 0;
    }

    return 0; // Otros tipos no compatibles
}

// Función para determinar el tipo resultante de un módulo
TipoDato tipo_resultado_modulo(TipoDato tipo1, TipoDato tipo2) {
    // ===== NULL PRODUCE TIPO DESCONOCIDO (ERROR) =====
    if (tipo1 == TIPO_NULL || tipo2 == TIPO_NULL) {
        return TIPO_DESCONOCIDO;
    }

    // ===== STRINGS NO SOPORTAN MÓDULO =====
    if (tipo1 == TIPO_STRING || tipo2 == TIPO_STRING) {
        return TIPO_DESCONOCIDO; // Error - no se puede módulo con strings
    }

    // ===== PROMOCIÓN NUMÉRICA SEGÚN JAVA =====
    // double > float > long > int > short > byte > char
    if (tipo1 == TIPO_DOUBLE || tipo2 == TIPO_DOUBLE) {
        return TIPO_DOUBLE;
    }
    if (tipo1 == TIPO_FLOAT || tipo2 == TIPO_FLOAT) {
        return TIPO_FLOAT;
    }
    if (tipo1 == TIPO_LONG || tipo2 == TIPO_LONG) {
        return TIPO_LONG;
    }
    if (tipo1 == TIPO_INT || tipo2 == TIPO_INT) {
        return TIPO_INT;
    }
    if ((tipo1 == TIPO_SHORT || tipo1 == TIPO_BYTE || tipo1 == TIPO_CHAR) &&
        (tipo2 == TIPO_SHORT || tipo2 == TIPO_BYTE || tipo2 == TIPO_CHAR)) {
        return TIPO_INT; // Promoción automática en operaciones
    }

    return TIPO_INT; // Valor por defecto para operaciones numéricas
}

char* process_modulo_node(NodeProcessorContext* context, ASTNode* node) {
    if (!context || !node) {
        procesador_error_output(context, "Contexto o nodo NULL en módulo");
        return NULL;
    }

    // DEBUG VISIBLE EN GUI
    char debug_msg[256];
    snprintf(debug_msg, sizeof(debug_msg), "🔢 ANÁLISIS SEMÁNTICO: Módulo en línea %d", node->line);
    procesador_debug_output(context, debug_msg);

    // Verificar que es un módulo válido
    if (!node->value || strcmp(node->value, "%") != 0) {
        procesador_error_output(context, "Nodo no es un módulo válido");
        return NULL;
    }

    if (node->child_count < 2) {
        procesador_error_output(context, "Módulo con menos de 2 operandos");
        return NULL;
    }

    // Obtener operandos
    ASTNode* left_node = node->children[0];
    ASTNode* right_node = node->children[1];

    // ===== ANÁLISIS SEMÁNTICO DE TIPOS USANDO AST Y TABLA DE SÍMBOLOS =====
    TipoDato tipo_izq = obtener_tipo_desde_nodo(left_node, context);
    TipoDato tipo_der = obtener_tipo_desde_nodo(right_node, context);

    // Obtener valores (desde literales o tabla de símbolos)
    char* left_value = obtener_valor_desde_nodo(left_node, context);
    char* right_value = obtener_valor_desde_nodo(right_node, context);

    if (!left_value || !right_value) {
        procesador_error_output(context, "No se pudieron obtener los valores de los operandos");
        if (left_value) free(left_value);
        if (right_value) free(right_value);
        return NULL;
    }

    snprintf(debug_msg, sizeof(debug_msg), "🔍 TIPOS DETECTADOS: '%s'(%s) %% '%s'(%s)",
             left_value, tipo_dato_to_string(tipo_izq),
             right_value, tipo_dato_to_string(tipo_der));
    procesador_debug_output(context, debug_msg);

    // ===== VERIFICAR DIVISIÓN POR CERO =====
    double right_num = convertir_a_numero(right_value, tipo_der);
    if (right_num == 0.0) {
        // ===== ERROR SEMÁNTICO: DIVISIÓN POR CERO =====
        char error_msg[512];
        snprintf(error_msg, sizeof(error_msg),
                "Error: División por cero en operación módulo (%s %% %s)",
                left_value, right_value);

        // OBTENER EL SCOPE ACTUAL CORRECTAMENTE
        const char* scope_actual = "global"; // valor por defecto
        if (context->scope_actual && context->scope_actual->nombre) {
            scope_actual = context->scope_actual->nombre;
        } else if (context->tabla_simbolos && context->tabla_simbolos->ambito_actual) {
            scope_actual = context->tabla_simbolos->ambito_actual;
        }

        // Registrar error semántico global
        if (global_error_manager) {
            error_manager_add_semantico(global_error_manager,
                                      node->line, node->column,
                                      error_msg, "%",
                                      scope_actual);
        }

        procesador_error_output(context, error_msg);
        free(left_value);
        free(right_value);
        return NULL;
    }

    // Verificar compatibilidad de tipos
    if (!tipos_compatibles_modulo(tipo_izq, tipo_der)) {
        // ===== ERROR SEMÁNTICO =====
        char error_msg[512];
        snprintf(error_msg, sizeof(error_msg),
                "Operación módulo incompatible: %s %% %s",
                tipo_dato_to_string(tipo_izq),
                tipo_dato_to_string(tipo_der));

        // OBTENER EL SCOPE ACTUAL CORRECTAMENTE
        const char* scope_actual = "global"; // valor por defecto
        if (context->scope_actual && context->scope_actual->nombre) {
            scope_actual = context->scope_actual->nombre;
        } else if (context->tabla_simbolos && context->tabla_simbolos->ambito_actual) {
            scope_actual = context->tabla_simbolos->ambito_actual;
        }

        // Registrar error semántico global
        if (global_error_manager) {
            error_manager_add_semantico(global_error_manager,
                                      node->line, node->column,
                                      error_msg, "%",
                                      scope_actual);
        }

        procesador_error_output(context, error_msg);
        free(left_value);
        free(right_value);
        return NULL;
    }

    // Determinar tipo resultado
    TipoDato tipo_resultado = tipo_resultado_modulo(tipo_izq, tipo_der);

    snprintf(debug_msg, sizeof(debug_msg), "✅ TIPOS COMPATIBLES → Resultado: %s",
             tipo_dato_to_string(tipo_resultado));
    procesador_debug_output(context, debug_msg);

    // ===== REALIZAR LA OPERACIÓN ARITMÉTICA =====
    char* resultado_str = malloc(64);

    // Convertir a números y operar
    double left_num = convertir_a_numero(left_value, tipo_izq);
    double resultado = evaluar_modulo(left_num, right_num, tipo_resultado);

    // Formatear según el tipo resultado
    if (tipo_resultado == TIPO_INT || tipo_resultado == TIPO_LONG ||
        tipo_resultado == TIPO_BYTE || tipo_resultado == TIPO_SHORT) {
        snprintf(resultado_str, 64, "%d", (int)resultado);
    } else if (tipo_resultado == TIPO_FLOAT) {
        snprintf(resultado_str, 64, "%.2f", (float)resultado);
    } else if (tipo_resultado == TIPO_DOUBLE) {
        snprintf(resultado_str, 64, "%.6g", resultado);
    } else {
        // Fallback para otros tipos numéricos
        snprintf(resultado_str, 64, "%.6g", resultado);
    }

    snprintf(debug_msg, sizeof(debug_msg), "🔢 MÓDULO ARITMÉTICO: %s", resultado_str);
    procesador_debug_output(context, debug_msg);

    free(left_value);
    free(right_value);
    return resultado_str;
}

// Función auxiliar para evaluar módulo
double evaluar_modulo(double left, double right, TipoDato tipo_resultado) {
    // ===== COMPORTAMIENTO EXACTO DE JAVA PARA MÓDULO =====
    // En Java: el signo del resultado es igual al signo del dividendo (left)

    if (tipo_resultado == TIPO_INT || tipo_resultado == TIPO_LONG ||
        tipo_resultado == TIPO_BYTE || tipo_resultado == TIPO_SHORT) {
        // ===== MÓDULO ENTERO - COMPORTAMIENTO JAVA =====
        long left_int = (long)left;
        long right_int = (long)right;

        // Java: dividendo % divisor
        // El signo del resultado es igual al signo del dividendo
        long resultado = left_int % right_int;

        return (double)resultado;
        } else {
            // ===== MÓDULO FLOTANTE - USAR FMOD CON AJUSTE =====
            // Para tipos flotantes, fmod() ya tiene el comportamiento correcto de Java
            return fmod(left, right);
        }
}