//
// Created by lightdemon on 2/09/25.
//
#include "../../../Headers/Procesador_Logico.h"
#include "../../../Headers/node_processor.h"
#include "../../Headers/mainview.h"
#include "../../../Headers/globals.h"
#include "../../../Headers/node_utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Función para determinar el tipo de operador lógico
TipoOperadorLogico get_tipo_operador_logico(const char* operador) {
    if (!operador) return LOGICO_DESCONOCIDO;

    if (strcmp(operador, "&&") == 0) return LOGICO_AND;
    if (strcmp(operador, "||") == 0) return LOGICO_OR;
    if (strcmp(operador, "!") == 0) return LOGICO_NOT;

    return LOGICO_DESCONOCIDO;
}

// Función para verificar si un valor es boolean válido
int es_valor_boolean_valido(const char* valor) {
    if (!valor) return 0;
    return (strcmp(valor, "true") == 0 || strcmp(valor, "false") == 0);
}

// Función para convertir string a boolean
int string_to_boolean(const char* valor) {
    if (!valor) return -1;
    if (strcmp(valor, "true") == 0) return 1;
    if (strcmp(valor, "false") == 0) return 0;
    return -1; // Error
}

// Función para convertir boolean a string
const char* boolean_to_string(int valor) {
    return (valor != 0) ? "true" : "false";
}

// Función para verificar compatibilidad de tipos
int tipo_compatible_logico(TipoDato tipo) {
    return (tipo == TIPO_BOOLEAN);
}

// Operaciones lógicas
int realizar_and_logico(int izq, int der) {
    // En Java: false && X = false (evaluación perezosa)
    // true && X = X
    return (izq != 0) && (der != 0);
}

int realizar_or_logico(int izq, int der) {
    // En Java: true || X = true (evaluación perezosa)
    // false || X = X
    return (izq != 0) || (der != 0);
}

int realizar_not_logico(int valor) {
    // En Java: !true = false, !false = true
    return (valor == 0) ? 1 : 0;
}

// Procesador principal para operaciones lógicas binarias
char* process_logico_binario_node(NodeProcessorContext* context, ASTNode* node) {
    if (!context || !node) {
        procesador_error_output(context, "Contexto o nodo NULL en operación lógica");
        return NULL;
    }

    char debug_msg[256];
    snprintf(debug_msg, sizeof(debug_msg), "🧠 ANÁLISIS SEMÁNTICO: Operación lógica en línea %d", node->line);
    procesador_debug_output(context, debug_msg);

    // Verificar que es una operación lógica válida
    if (!node->value) {
        procesador_error_output(context, "Nodo sin operador lógico");
        return NULL;
    }

    TipoOperadorLogico tipo_op = get_tipo_operador_logico(node->value);
    if (tipo_op == LOGICO_DESCONOCIDO || tipo_op == LOGICO_NOT) {
        procesador_error_output(context, "Operador lógico binario desconocido");
        return NULL;
    }

    if (node->child_count < 2) {
        procesador_error_output(context, "Operación lógica con menos de 2 operandos");
        return NULL;
    }

    // Obtener operandos
    ASTNode* left_node = node->children[0];
    ASTNode* right_node = node->children[1];

    // ===== ANÁLISIS SEMÁNTICO DE TIPOS =====
    TipoDato tipo_izq = obtener_tipo_desde_nodo(left_node, context);
    TipoDato tipo_der = obtener_tipo_desde_nodo(right_node, context);

    // Obtener valores
    char* left_value = obtener_valor_desde_nodo(left_node, context);
    char* right_value = obtener_valor_desde_nodo(right_node, context);

    if (!left_value || !right_value) {
        procesador_error_output(context, "No se pudieron obtener los valores de los operandos lógicos");
        if (left_value) free(left_value);
        if (right_value) free(right_value);
        return NULL;
    }

    snprintf(debug_msg, sizeof(debug_msg), "🔍 TIPOS DETECTADOS: '%s'(%s) %s '%s'(%s)",
             left_value, tipo_dato_to_string(tipo_izq),
             node->value,
             right_value, tipo_dato_to_string(tipo_der));
    procesador_debug_output(context, debug_msg);

    // ===== VERIFICAR QUE AMBOS OPERANDOS SEAN BOOLEAN =====
    if (!tipo_compatible_logico(tipo_izq) || !tipo_compatible_logico(tipo_der)) {
        char error_msg[512];
        snprintf(error_msg, sizeof(error_msg),
                "Operación lógica incompatible: %s %s %s (requiere operandos boolean)",
                tipo_dato_to_string(tipo_izq),
                node->value,
                tipo_dato_to_string(tipo_der));

        const char* scope_actual = "global";
        if (context->scope_actual && context->scope_actual->nombre) {
            scope_actual = context->scope_actual->nombre;
        }

        if (global_error_manager) {
            error_manager_add_semantico(global_error_manager,
                                      node->line, node->column,
                                      error_msg, node->value,
                                      scope_actual);
        }

        procesador_error_output(context, error_msg);
        free(left_value);
        free(right_value);
        return NULL;
    }

    // ===== VERIFICAR QUE LOS VALORES SEAN BOOLEAN VÁLIDOS =====
    if (!es_valor_boolean_valido(left_value) || !es_valor_boolean_valido(right_value)) {
        char error_msg[512];
        snprintf(error_msg, sizeof(error_msg),
                "Valores no válidos para operación lógica: '%s' %s '%s'",
                left_value, node->value, right_value);

        procesador_error_output(context, error_msg);
        free(left_value);
        free(right_value);
        return NULL;
    }

    snprintf(debug_msg, sizeof(debug_msg), "✅ OPERANDOS BOOLEAN VÁLIDOS para %s", node->value);
    procesador_debug_output(context, debug_msg);

    // ===== REALIZAR LA OPERACIÓN LÓGICA =====
    int valor_izq = string_to_boolean(left_value);
    int valor_der = string_to_boolean(right_value);
    int resultado_bool = 0;

    if (tipo_op == LOGICO_AND) {
        resultado_bool = realizar_and_logico(valor_izq, valor_der);
        snprintf(debug_msg, sizeof(debug_msg), "🧠 AND LÓGICO: %s && %s = %s",
                left_value, right_value, boolean_to_string(resultado_bool));
    } else if (tipo_op == LOGICO_OR) {
        resultado_bool = realizar_or_logico(valor_izq, valor_der);
        snprintf(debug_msg, sizeof(debug_msg), "🧠 OR LÓGICO: %s || %s = %s",
                left_value, right_value, boolean_to_string(resultado_bool));
    }

    procesador_debug_output(context, debug_msg);

    // Crear resultado
    char* resultado_str = malloc(8);
    strcpy(resultado_str, boolean_to_string(resultado_bool));

    snprintf(debug_msg, sizeof(debug_msg), "✅ RESULTADO OPERACIÓN LÓGICA: %s", resultado_str);
    procesador_debug_output(context, debug_msg);

    free(left_value);
    free(right_value);
    return resultado_str;
}

// Procesador para operaciones lógicas unarias (!)
char* process_logico_unario_node(NodeProcessorContext* context, ASTNode* node) {
    if (!context || !node) {
        procesador_error_output(context, "Contexto o nodo NULL en operación lógica unaria");
        return NULL;
    }

    char debug_msg[256];
    snprintf(debug_msg, sizeof(debug_msg), "🧠 ANÁLISIS SEMÁNTICO: NOT lógico en línea %d", node->line);
    procesador_debug_output(context, debug_msg);

    // Verificar que es NOT lógico
    if (!node->value || strcmp(node->value, "!") != 0) {
        procesador_error_output(context, "Operador unario no es NOT lógico");
        return NULL;
    }

    if (node->child_count < 1) {
        procesador_error_output(context, "Operación NOT sin operando");
        return NULL;
    }

    // Obtener operando
    ASTNode* operand_node = node->children[0];

    // ===== ANÁLISIS SEMÁNTICO DE TIPO =====
    TipoDato tipo_operando = obtener_tipo_desde_nodo(operand_node, context);
    char* valor_operando = obtener_valor_desde_nodo(operand_node, context);

    if (!valor_operando) {
        procesador_error_output(context, "No se pudo obtener el valor del operando");
        return NULL;
    }

    snprintf(debug_msg, sizeof(debug_msg), "🔍 TIPO DETECTADO: !%s(%s)",
             valor_operando, tipo_dato_to_string(tipo_operando));
    procesador_debug_output(context, debug_msg);

    // ===== VERIFICAR QUE EL OPERANDO SEA BOOLEAN =====
    if (!tipo_compatible_logico(tipo_operando)) {
        char error_msg[512];
        snprintf(error_msg, sizeof(error_msg),
                "Operación NOT incompatible: !%s (requiere operando boolean)",
                tipo_dato_to_string(tipo_operando));

        const char* scope_actual = "global";
        if (context->scope_actual && context->scope_actual->nombre) {
            scope_actual = context->scope_actual->nombre;
        }

        if (global_error_manager) {
            error_manager_add_semantico(global_error_manager,
                                      node->line, node->column,
                                      error_msg, "!",
                                      scope_actual);
        }

        procesador_error_output(context, error_msg);
        free(valor_operando);
        return NULL;
    }

    // ===== VERIFICAR QUE EL VALOR SEA BOOLEAN VÁLIDO =====
    if (!es_valor_boolean_valido(valor_operando)) {
        char error_msg[512];
        snprintf(error_msg, sizeof(error_msg),
                "Valor no válido para operación NOT: '%s'", valor_operando);

        procesador_error_output(context, error_msg);
        free(valor_operando);
        return NULL;
    }

    snprintf(debug_msg, sizeof(debug_msg), "✅ OPERANDO BOOLEAN VÁLIDO para NOT");
    procesador_debug_output(context, debug_msg);

    // ===== REALIZAR LA OPERACIÓN NOT =====
    int valor_bool = string_to_boolean(valor_operando);
    int resultado_bool = realizar_not_logico(valor_bool);

    snprintf(debug_msg, sizeof(debug_msg), "🧠 NOT LÓGICO: !%s = %s",
            valor_operando, boolean_to_string(resultado_bool));
    procesador_debug_output(context, debug_msg);

    // Crear resultado
    char* resultado_str = malloc(8);
    strcpy(resultado_str, boolean_to_string(resultado_bool));

    snprintf(debug_msg, sizeof(debug_msg), "✅ RESULTADO NOT LÓGICO: %s", resultado_str);
    procesador_debug_output(context, debug_msg);

    free(valor_operando);
    return resultado_str;
}