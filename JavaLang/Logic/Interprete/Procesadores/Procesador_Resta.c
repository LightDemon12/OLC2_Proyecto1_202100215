#include "../../../Headers/Procesador_Resta.h"
#include "../../../Headers/node_processor.h"
#include "../../Headers/mainview.h"
#include "../../../Headers/globals.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Función para verificar si dos tipos son compatibles para resta
int tipos_compatibles_resta(TipoDato tipo1, TipoDato tipo2) {
    // ===== NULL NO ES COMPATIBLE CON NADA EN OPERACIONES ARITMÉTICAS =====
    if (tipo1 == TIPO_NULL || tipo2 == TIPO_NULL) {
        return 0; // NULL - cualquier_cosa = ERROR
    }

    // ===== LA RESTA SOLO ES VÁLIDA ENTRE TIPOS NUMÉRICOS =====
    // A diferencia de la suma, NO hay concatenación en resta
    if ((tipo1 == TIPO_INT || tipo1 == TIPO_FLOAT || tipo1 == TIPO_DOUBLE || tipo1 == TIPO_CHAR) &&
        (tipo2 == TIPO_INT || tipo2 == TIPO_FLOAT || tipo2 == TIPO_DOUBLE || tipo2 == TIPO_CHAR)) {
        return 1;
    }

    // ===== STRING NO ES COMPATIBLE CON RESTA =====
    // En Java: "Hello" - "World" = ERROR (no hay "substracción" de strings)
    if (tipo1 == TIPO_STRING || tipo2 == TIPO_STRING) {
        return 0;
    }

    // ===== BOOLEAN NO ES COMPATIBLE CON OPERACIONES ARITMÉTICAS =====
    if (tipo1 == TIPO_BOOLEAN || tipo2 == TIPO_BOOLEAN) {
        return 0;
    }

    return 0; // Otros tipos no compatibles
}

// Función para determinar el tipo resultante de una resta
TipoDato tipo_resultado_resta(TipoDato tipo1, TipoDato tipo2) {
    // ===== NULL PRODUCE TIPO DESCONOCIDO (ERROR) =====
    if (tipo1 == TIPO_NULL || tipo2 == TIPO_NULL) {
        return TIPO_DESCONOCIDO;
    }

    // ===== STRINGS NO SOPORTAN RESTA =====
    if (tipo1 == TIPO_STRING || tipo2 == TIPO_STRING) {
        return TIPO_DESCONOCIDO; // Error - no se puede restar strings
    }

    // ===== PROMOCIÓN NUMÉRICA SEGÚN JAVA =====
    // double > float > long > int > char
    if (tipo1 == TIPO_DOUBLE || tipo2 == TIPO_DOUBLE) {
        return TIPO_DOUBLE;
    }
    if (tipo1 == TIPO_FLOAT || tipo2 == TIPO_FLOAT) {
        return TIPO_FLOAT;
    }
    if (tipo1 == TIPO_INT || tipo2 == TIPO_INT) {
        return TIPO_INT;
    }
    if (tipo1 == TIPO_CHAR && tipo2 == TIPO_CHAR) {
        return TIPO_INT; // char - char = int en Java
    }

    return TIPO_INT; // Valor por defecto para operaciones numéricas
}

char* process_resta_node(NodeProcessorContext* context, ASTNode* node) {
    if (!context || !node) {
        procesador_error_output(context, "Contexto o nodo NULL en resta");
        return NULL;
    }

    // DEBUG VISIBLE EN GUI
    char debug_msg[256];
    snprintf(debug_msg, sizeof(debug_msg), "🔢 ANÁLISIS SEMÁNTICO: Resta en línea %d", node->line);
    procesador_debug_output(context, debug_msg);

    // Verificar que es una resta válida
    if (!node->value || strcmp(node->value, "-") != 0) {
        procesador_error_output(context, "Nodo no es una resta válida");
        return NULL;
    }

    if (node->child_count < 2) {
        procesador_error_output(context, "Resta con menos de 2 operandos");
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

    snprintf(debug_msg, sizeof(debug_msg), "🔍 TIPOS DETECTADOS: '%s'(%s) - '%s'(%s)",
             left_value, tipo_dato_to_string(tipo_izq),
             right_value, tipo_dato_to_string(tipo_der));
    procesador_debug_output(context, debug_msg);

    // Verificar compatibilidad de tipos
    if (!tipos_compatibles_resta(tipo_izq, tipo_der)) {
        // ===== ERROR SEMÁNTICO =====
        char error_msg[512];
        snprintf(error_msg, sizeof(error_msg),
                "Operación resta incompatible: %s - %s",
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
                                      error_msg, "-",
                                      scope_actual);
        }

        procesador_error_output(context, error_msg);
        free(left_value);
        free(right_value);
        return NULL;
    }

    // Determinar tipo resultado
    TipoDato tipo_resultado = tipo_resultado_resta(tipo_izq, tipo_der);

    snprintf(debug_msg, sizeof(debug_msg), "✅ TIPOS COMPATIBLES → Resultado: %s",
             tipo_dato_to_string(tipo_resultado));
    procesador_debug_output(context, debug_msg);

    // ===== REALIZAR LA OPERACIÓN ARITMÉTICA =====
    // La resta SIEMPRE es aritmética (no hay "concatenación" como en suma)
    char* resultado_str = malloc(64);

    // Convertir a números y operar
    double left_num = convertir_a_numero(left_value, tipo_izq);
    double right_num = convertir_a_numero(right_value, tipo_der);
    double resultado = evaluar_resta(left_num, right_num);

    // Formatear según el tipo resultado
    if (tipo_resultado == TIPO_INT) {
        snprintf(resultado_str, 64, "%d", (int)resultado);
    } else if (tipo_resultado == TIPO_FLOAT) {
        snprintf(resultado_str, 64, "%.2f", (float)resultado);
    } else if (tipo_resultado == TIPO_DOUBLE) {
        snprintf(resultado_str, 64, "%.6g", resultado);
    } else {
        // Fallback para otros tipos numéricos
        snprintf(resultado_str, 64, "%.6g", resultado);
    }

    snprintf(debug_msg, sizeof(debug_msg), "➖ RESTA ARITMÉTICA: %s", resultado_str);
    procesador_debug_output(context, debug_msg);

    free(left_value);
    free(right_value);
    return resultado_str;
}

// Función auxiliar para evaluar resta
double evaluar_resta(double left, double right) {
    return left - right;
}