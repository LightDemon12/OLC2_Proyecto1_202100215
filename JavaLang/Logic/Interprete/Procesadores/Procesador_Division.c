//
// Created by lightdemon on 2/09/25.
//
#include "../../../Headers/Procesador_Division.h"
#include "../../../Headers/node_utils.h"  // ← USAR LAS UTILIDADES
#include "../../../Headers/node_processor.h"
#include "../../Headers/mainview.h"
#include "../../../Headers/globals.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>  // Para INFINITY y NAN

// Función para verificar si dos tipos son compatibles para división
int tipos_compatibles_division(TipoDato tipo1, TipoDato tipo2) {
    // ===== NULL NO ES COMPATIBLE CON NADA EN OPERACIONES ARITMÉTICAS =====
    if (tipo1 == TIPO_NULL || tipo2 == TIPO_NULL) {
        return 0; // NULL / cualquier_cosa = ERROR
    }

    // ===== LA DIVISIÓN SOLO ES VÁLIDA ENTRE TIPOS NUMÉRICOS =====
    // En Java: int / int, float / double, char / int, etc.
    // NO hay "división" de strings
    if (tipos_compatibles_aritmetica(tipo1, tipo2)) {
        return 1;
    }

    // ===== STRING NO ES COMPATIBLE CON DIVISIÓN =====
    // En Java: "Hello" / 2 = ERROR (no hay división de strings)
    if (tipo1 == TIPO_STRING || tipo2 == TIPO_STRING) {
        return 0;
    }

    // ===== BOOLEAN NO ES COMPATIBLE CON OPERACIONES ARITMÉTICAS =====
    if (tipo1 == TIPO_BOOLEAN || tipo2 == TIPO_BOOLEAN) {
        return 0;
    }

    return 0; // Otros tipos no compatibles
}

// Función para determinar el tipo resultante de una división
TipoDato tipo_resultado_division(TipoDato tipo1, TipoDato tipo2) {
    // ===== NULL PRODUCE TIPO DESCONOCIDO (ERROR) =====
    if (tipo1 == TIPO_NULL || tipo2 == TIPO_NULL) {
        return TIPO_DESCONOCIDO;
    }

    // ===== STRINGS NO SOPORTAN DIVISIÓN =====
    if (tipo1 == TIPO_STRING || tipo2 == TIPO_STRING) {
        return TIPO_DESCONOCIDO; // Error - no se puede dividir strings
    }

    // ===== BOOLEAN NO ES NUMÉRICO =====
    if (tipo1 == TIPO_BOOLEAN || tipo2 == TIPO_BOOLEAN) {
        return TIPO_DESCONOCIDO;
    }

    // ===== REGLAS ESPECIALES DE DIVISIÓN EN JAVA =====
    // En Java, la división tiene reglas específicas:
    // - int / int = int (división entera, trunca decimales)
    // - float / float = float
    // - double / double = double
    // - Si hay promoción, usar promoción estándar

    // Si ambos son enteros, el resultado es entero (división entera)
    if (tipo1 == TIPO_INT && tipo2 == TIPO_INT) {
        return TIPO_INT; // División entera: 7/3 = 2 (no 2.33)
    }

    // Si hay char involucrado con int, promover a int
    if ((tipo1 == TIPO_CHAR && tipo2 == TIPO_INT) ||
        (tipo1 == TIPO_INT && tipo2 == TIPO_CHAR) ||
        (tipo1 == TIPO_CHAR && tipo2 == TIPO_CHAR)) {
        return TIPO_INT;
    }

    // Para otros casos, usar promoción estándar
    return promocionar_tipos(tipo1, tipo2);
}

// Función para verificar división por cero
int es_division_por_cero(double divisor, TipoDato tipo_divisor) {
    // Para tipos enteros, verificar si es exactamente 0
    if (tipo_divisor == TIPO_INT || tipo_divisor == TIPO_CHAR) {
        return (divisor == 0.0);
    }

    // Para tipos flotantes, verificar si es muy cerca de 0
    if (tipo_divisor == TIPO_FLOAT || tipo_divisor == TIPO_DOUBLE) {
        return (fabs(divisor) < 1e-10); // Umbral muy pequeño para flotantes
    }

    return 0;
}

char* process_division_node(NodeProcessorContext* context, ASTNode* node) {
    if (!context || !node) {
        procesador_error_output(context, "Contexto o nodo NULL en división");
        return NULL;
    }

    // DEBUG VISIBLE EN GUI
    char debug_msg[256];
    snprintf(debug_msg, sizeof(debug_msg), "🔢 ANÁLISIS SEMÁNTICO: División en línea %d", node->line);
    procesador_debug_output(context, debug_msg);

    // Verificar que es una división válida
    if (!node->value || strcmp(node->value, "/") != 0) {
        procesador_error_output(context, "Nodo no es una división válida");
        return NULL;
    }

    if (node->child_count < 2) {
        procesador_error_output(context, "División con menos de 2 operandos");
        return NULL;
    }

    // Obtener operandos
    ASTNode* left_node = node->children[0];
    ASTNode* right_node = node->children[1];

    // ===== USAR LAS FUNCIONES DE NODE_UTILS =====
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

    snprintf(debug_msg, sizeof(debug_msg), "🔍 TIPOS DETECTADOS: '%s'(%s) / '%s'(%s)",
             left_value, tipo_dato_to_string(tipo_izq),
             right_value, tipo_dato_to_string(tipo_der));
    procesador_debug_output(context, debug_msg);

    // Verificar compatibilidad de tipos
    if (!tipos_compatibles_division(tipo_izq, tipo_der)) {
        // ===== ERROR SEMÁNTICO =====
        char error_msg[512];
        snprintf(error_msg, sizeof(error_msg),
                "Operación división incompatible: %s / %s",
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
                                      error_msg, "/",
                                      scope_actual);
        }

        procesador_error_output(context, error_msg);
        free(left_value);
        free(right_value);
        return NULL;
    }

    // ===== VERIFICACIÓN DE DIVISIÓN POR CERO =====
    double right_num = convertir_a_numero(right_value, tipo_der);

    if (es_division_por_cero(right_num, tipo_der)) {
        // ===== ERROR SEMÁNTICO: DIVISIÓN POR CERO =====
        char error_msg[512];
        snprintf(error_msg, sizeof(error_msg),
                "División por cero detectada: %s / %s",
                left_value, right_value);

        // OBTENER EL SCOPE ACTUAL CORRECTAMENTE
        const char* scope_actual = "global";
        if (context->scope_actual && context->scope_actual->nombre) {
            scope_actual = context->scope_actual->nombre;
        } else if (context->tabla_simbolos && context->tabla_simbolos->ambito_actual) {
            scope_actual = context->tabla_simbolos->ambito_actual;
        }

        // Registrar error semántico global
        if (global_error_manager) {
            error_manager_add_semantico(global_error_manager,
                                      node->line, node->column,
                                      error_msg, "/",
                                      scope_actual);
        }

        procesador_error_output(context, error_msg);
        free(left_value);
        free(right_value);
        return NULL;
    }

    // Determinar tipo resultado
    TipoDato tipo_resultado = tipo_resultado_division(tipo_izq, tipo_der);

    snprintf(debug_msg, sizeof(debug_msg), "✅ TIPOS COMPATIBLES → Resultado: %s",
             tipo_dato_to_string(tipo_resultado));
    procesador_debug_output(context, debug_msg);

    // ===== REALIZAR LA OPERACIÓN ARITMÉTICA =====
    double left_num = convertir_a_numero(left_value, tipo_izq);
    double resultado = evaluar_division(left_num, right_num);

    // ===== FORMATEAR SEGÚN EL TIPO RESULTADO =====
    char* resultado_str;

    if (tipo_resultado == TIPO_INT) {
        // División entera: truncar decimales
        int resultado_entero = (int)resultado;
        resultado_str = malloc(32);
        snprintf(resultado_str, 32, "%d", resultado_entero);
        snprintf(debug_msg, sizeof(debug_msg), "➗ DIVISIÓN ENTERA: %s", resultado_str);
    } else {
        // División con decimales
        resultado_str = convertir_numero_a_string(resultado, tipo_resultado);
        snprintf(debug_msg, sizeof(debug_msg), "➗ DIVISIÓN DECIMAL: %s", resultado_str);
    }

    procesador_debug_output(context, debug_msg);

    free(left_value);
    free(right_value);
    return resultado_str;
}

// Función auxiliar para evaluar división
double evaluar_division(double left, double right) {
    // La verificación de división por cero ya se hizo antes
    return left / right;
}