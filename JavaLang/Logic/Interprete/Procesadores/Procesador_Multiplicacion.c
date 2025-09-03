//
// Created by lightdemon on 2/09/25.
//

#include "../../../Headers/Procesador_Multiplicacion.h"
#include "../../../Headers/node_utils.h"  // ← USAR LAS UTILIDADES
#include "../../../Headers/node_processor.h"
#include "../../Headers/mainview.h"
#include "../../../Headers/globals.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Función para verificar si dos tipos son compatibles para multiplicación
int tipos_compatibles_multiplicacion(TipoDato tipo1, TipoDato tipo2) {
    // ===== NULL NO ES COMPATIBLE CON NADA EN OPERACIONES ARITMÉTICAS =====
    if (tipo1 == TIPO_NULL || tipo2 == TIPO_NULL) {
        return 0; // NULL * cualquier_cosa = ERROR
    }

    // ===== LA MULTIPLICACIÓN SOLO ES VÁLIDA ENTRE TIPOS NUMÉRICOS =====
    // En Java: int * int, float * double, char * int, etc.
    // NO hay "multiplicación" de strings como "abc" * 3 (eso sería Python)
    if (tipos_compatibles_aritmetica(tipo1, tipo2)) {
        return 1;
    }

    // ===== STRING NO ES COMPATIBLE CON MULTIPLICACIÓN =====
    // En Java: "Hello" * 3 = ERROR (no hay repetición de strings)
    if (tipo1 == TIPO_STRING || tipo2 == TIPO_STRING) {
        return 0;
    }

    // ===== BOOLEAN NO ES COMPATIBLE CON OPERACIONES ARITMÉTICAS =====
    if (tipo1 == TIPO_BOOLEAN || tipo2 == TIPO_BOOLEAN) {
        return 0;
    }

    return 0; // Otros tipos no compatibles
}

// Función para determinar el tipo resultante de una multiplicación
TipoDato tipo_resultado_multiplicacion(TipoDato tipo1, TipoDato tipo2) {
    // ===== NULL PRODUCE TIPO DESCONOCIDO (ERROR) =====
    if (tipo1 == TIPO_NULL || tipo2 == TIPO_NULL) {
        return TIPO_DESCONOCIDO;
    }

    // ===== STRINGS NO SOPORTAN MULTIPLICACIÓN =====
    if (tipo1 == TIPO_STRING || tipo2 == TIPO_STRING) {
        return TIPO_DESCONOCIDO; // Error - no se puede multiplicar strings
    }

    // ===== BOOLEAN NO ES NUMÉRICO =====
    if (tipo1 == TIPO_BOOLEAN || tipo2 == TIPO_BOOLEAN) {
        return TIPO_DESCONOCIDO;
    }

    // ===== PROMOCIÓN NUMÉRICA SEGÚN JAVA =====
    // Usar la función de utilidades para promoción estándar
    return promocionar_tipos(tipo1, tipo2);
}

char* process_multiplicacion_node(NodeProcessorContext* context, ASTNode* node) {
    if (!context || !node) {
        procesador_error_output(context, "Contexto o nodo NULL en multiplicación");
        return NULL;
    }

    // DEBUG VISIBLE EN GUI
    char debug_msg[256];
    snprintf(debug_msg, sizeof(debug_msg), "🔢 ANÁLISIS SEMÁNTICO: Multiplicación en línea %d", node->line);
    procesador_debug_output(context, debug_msg);

    // Verificar que es una multiplicación válida
    if (!node->value || strcmp(node->value, "*") != 0) {
        procesador_error_output(context, "Nodo no es una multiplicación válida");
        return NULL;
    }

    if (node->child_count < 2) {
        procesador_error_output(context, "Multiplicación con menos de 2 operandos");
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

    snprintf(debug_msg, sizeof(debug_msg), "🔍 TIPOS DETECTADOS: '%s'(%s) * '%s'(%s)",
             left_value, tipo_dato_to_string(tipo_izq),
             right_value, tipo_dato_to_string(tipo_der));
    procesador_debug_output(context, debug_msg);

    // Verificar compatibilidad de tipos
    if (!tipos_compatibles_multiplicacion(tipo_izq, tipo_der)) {
        // ===== ERROR SEMÁNTICO =====
        char error_msg[512];
        snprintf(error_msg, sizeof(error_msg),
                "Operación multiplicación incompatible: %s * %s",
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
                                      error_msg, "*",
                                      scope_actual);
        }

        procesador_error_output(context, error_msg);
        free(left_value);
        free(right_value);
        return NULL;
    }

    // Determinar tipo resultado
    TipoDato tipo_resultado = tipo_resultado_multiplicacion(tipo_izq, tipo_der);

    snprintf(debug_msg, sizeof(debug_msg), "✅ TIPOS COMPATIBLES → Resultado: %s",
             tipo_dato_to_string(tipo_resultado));
    procesador_debug_output(context, debug_msg);

    // ===== REALIZAR LA OPERACIÓN ARITMÉTICA =====
    // La multiplicación SIEMPRE es aritmética (no hay casos especiales como en suma)

    // Operación aritmética usando las utilidades
    double left_num = convertir_a_numero(left_value, tipo_izq);
    double right_num = convertir_a_numero(right_value, tipo_der);
    double resultado = evaluar_multiplicacion(left_num, right_num);

    char* resultado_str = convertir_numero_a_string(resultado, tipo_resultado);
    snprintf(debug_msg, sizeof(debug_msg), "✖️ MULTIPLICACIÓN ARITMÉTICA: %s", resultado_str);
    procesador_debug_output(context, debug_msg);

    free(left_value);
    free(right_value);
    return resultado_str;
}

// Función auxiliar para evaluar multiplicación
double evaluar_multiplicacion(double left, double right) {
    return left * right;
}