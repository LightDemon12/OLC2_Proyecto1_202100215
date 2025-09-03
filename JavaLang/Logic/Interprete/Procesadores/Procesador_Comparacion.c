//
// Created by lightdemon on 2/09/25.
//
#include "../../../Headers/Procesador_Comparacion.h"
#include "../../../Headers/node_processor.h"
#include "../../Headers/mainview.h"
#include "../../../Headers/globals.h"
#include "../../../Headers/node_utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// Función para determinar el tipo de comparación
TipoComparacion get_tipo_comparacion(const char* operador) {
    if (!operador) return COMP_DESCONOCIDO;

    if (strcmp(operador, "==") == 0) return COMP_IGUAL;
    if (strcmp(operador, "!=") == 0) return COMP_DIFERENTE;
    if (strcmp(operador, ">") == 0) return COMP_MAYOR;
    if (strcmp(operador, "<") == 0) return COMP_MENOR;
    if (strcmp(operador, ">=") == 0) return COMP_MAYOR_IGUAL;
    if (strcmp(operador, "<=") == 0) return COMP_MENOR_IGUAL;

    return COMP_DESCONOCIDO;
}

// Función para verificar compatibilidad de tipos en comparación
int tipos_compatibles_comparacion(TipoDato tipo1, TipoDato tipo2, const char* operador) {
    // ===== NULL SOLO COMPATIBLE CON IGUALDAD/DESIGUALDAD =====
    if (tipo1 == TIPO_NULL || tipo2 == TIPO_NULL) {
        return (strcmp(operador, "==") == 0 || strcmp(operador, "!=") == 0);
    }

    // ===== TIPOS NUMÉRICOS SON COMPATIBLES ENTRE SÍ =====
    int es_num1 = es_tipo_numerico(tipo1);
    int es_num2 = es_tipo_numerico(tipo2);
    if (es_num1 && es_num2) {
        return 1; // Todos los operadores son válidos entre números
    }

    // ===== CARACTERES SON COMPATIBLES ENTRE SÍ Y CON NÚMEROS =====
    if ((tipo1 == TIPO_CHAR && tipo2 == TIPO_CHAR) ||
        (tipo1 == TIPO_CHAR && es_num2) ||
        (es_num1 && tipo2 == TIPO_CHAR)) {
        return 1;
    }

    // ===== BOOLEANOS SOLO CON IGUALDAD/DESIGUALDAD =====
    if (tipo1 == TIPO_BOOLEAN || tipo2 == TIPO_BOOLEAN) {
        // Boolean solo puede usar == y !=
        return (strcmp(operador, "==") == 0 || strcmp(operador, "!=") == 0);
    }

    // ===== STRINGS SOLO CON IGUALDAD/DESIGUALDAD =====
    if (tipo1 == TIPO_STRING || tipo2 == TIPO_STRING) {
        // String solo puede usar == y != (en esta implementación básica)
        return (strcmp(operador, "==") == 0 || strcmp(operador, "!=") == 0);
    }

    return 0; // Tipos incompatibles
}

// Función principal para procesar comparación
char* process_comparacion_node(NodeProcessorContext* context, ASTNode* node) {
    if (!context || !node) {
        procesador_error_output(context, "Contexto o nodo NULL en comparación");
        return NULL;
    }

    // DEBUG VISIBLE EN GUI
    char debug_msg[256];
    snprintf(debug_msg, sizeof(debug_msg), "🔍 ANÁLISIS SEMÁNTICO: Comparación en línea %d", node->line);
    procesador_debug_output(context, debug_msg);

    // Verificar que es una comparación válida
    if (!node->value) {
        procesador_error_output(context, "Nodo sin operador de comparación");
        return NULL;
    }

    TipoComparacion tipo_comp = get_tipo_comparacion(node->value);
    if (tipo_comp == COMP_DESCONOCIDO) {
        procesador_error_output(context, "Operador de comparación desconocido");
        return NULL;
    }

    if (node->child_count < 2) {
        procesador_error_output(context, "Comparación con menos de 2 operandos");
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
        procesador_error_output(context, "No se pudieron obtener los valores de los operandos");
        if (left_value) free(left_value);
        if (right_value) free(right_value);
        return NULL;
    }

    snprintf(debug_msg, sizeof(debug_msg), "🔍 TIPOS DETECTADOS: '%s'(%s) %s '%s'(%s)",
             left_value, tipo_dato_to_string(tipo_izq),
             node->value,
             right_value, tipo_dato_to_string(tipo_der));
    procesador_debug_output(context, debug_msg);

    // ===== VERIFICAR COMPATIBILIDAD DE TIPOS =====
    if (!tipos_compatibles_comparacion(tipo_izq, tipo_der, node->value)) {
        char error_msg[512];
        snprintf(error_msg, sizeof(error_msg),
                "Comparación incompatible: %s %s %s",
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

    snprintf(debug_msg, sizeof(debug_msg), "✅ TIPOS COMPATIBLES para comparación %s", node->value);
    procesador_debug_output(context, debug_msg);

    // ===== REALIZAR LA COMPARACIÓN =====
    int resultado_bool = 0;
    char* resultado_str = malloc(8);

    // ===== COMPARACIÓN SEGÚN TIPOS =====
    // ===== COMPARACIÓN SEGÚN TIPOS =====
    if (tipo_izq == TIPO_CHAR && tipo_der == TIPO_CHAR) {
        // ===== COMPARACIÓN DE CARACTERES - CORREGIR EXTRACCIÓN =====
        char char1, char2;

        // Extraer carácter desde string con comillas: 'A' -> A
        if (left_value[0] == '\'' && strlen(left_value) >= 3) {
            char1 = left_value[1]; // Carácter entre comillas
        } else {
            char1 = left_value[0]; // Sin comillas
        }

        if (right_value[0] == '\'' && strlen(right_value) >= 3) {
            char2 = right_value[1]; // Carácter entre comillas
        } else {
            char2 = right_value[0]; // Sin comillas
        }

        resultado_bool = realizar_comparacion_char(char1, char2, tipo_comp);

        snprintf(debug_msg, sizeof(debug_msg), "🔤 COMPARACIÓN CHAR: '%c'(%d) %s '%c'(%d) = %s",
                char1, (int)char1, node->value, char2, (int)char2, resultado_bool ? "true" : "false");
        procesador_debug_output(context, debug_msg);
    }
    else if (es_tipo_numerico(tipo_izq) && es_tipo_numerico(tipo_der)) {
        // COMPARACIÓN NUMÉRICA
        double left_num = convertir_a_numero(left_value, tipo_izq);
        double right_num = convertir_a_numero(right_value, tipo_der);

        resultado_bool = realizar_comparacion_numerica(left_num, right_num, tipo_comp);

        snprintf(debug_msg, sizeof(debug_msg), "🔢 COMPARACIÓN NUMÉRICA: %.6g %s %.6g = %s",
                left_num, node->value, right_num, resultado_bool ? "true" : "false");
        procesador_debug_output(context, debug_msg);
    }
    else if ((tipo_izq == TIPO_CHAR && es_tipo_numerico(tipo_der)) ||
             (es_tipo_numerico(tipo_izq) && tipo_der == TIPO_CHAR)) {
        // ===== COMPARACIÓN CHAR CON NÚMERO - PROMOCIÓN A ASCII =====
        double valor1, valor2;

        if (tipo_izq == TIPO_CHAR) {
            // Extraer valor ASCII del char
            char char1 = (left_value[0] == '\'') ? left_value[1] : left_value[0];
            valor1 = (double)(int)char1;
            valor2 = convertir_a_numero(right_value, tipo_der);
        } else {
            valor1 = convertir_a_numero(left_value, tipo_izq);
            char char2 = (right_value[0] == '\'') ? right_value[1] : right_value[0];
            valor2 = (double)(int)char2;
        }

        resultado_bool = realizar_comparacion_numerica(valor1, valor2, tipo_comp);

        snprintf(debug_msg, sizeof(debug_msg), "🔤🔢 COMPARACIÓN CHAR-NÚMERO: %.0f %s %.0f = %s",
                valor1, node->value, valor2, resultado_bool ? "true" : "false");
        procesador_debug_output(context, debug_msg);
    }
    else if (tipo_izq == TIPO_BOOLEAN && tipo_der == TIPO_BOOLEAN) {
        // COMPARACIÓN DE BOOLEANOS
        int bool1 = (strcmp(left_value, "true") == 0) ? 1 : 0;
        int bool2 = (strcmp(right_value, "true") == 0) ? 1 : 0;

        resultado_bool = realizar_comparacion_boolean(bool1, bool2, tipo_comp);

        snprintf(debug_msg, sizeof(debug_msg), "🔘 COMPARACIÓN BOOLEAN: %s %s %s = %s",
                left_value, node->value, right_value, resultado_bool ? "true" : "false");
        procesador_debug_output(context, debug_msg);
    }
    else if (tipo_izq == TIPO_STRING && tipo_der == TIPO_STRING) {
        // COMPARACIÓN DE STRINGS
        resultado_bool = realizar_comparacion_string(left_value, right_value, tipo_comp);

        snprintf(debug_msg, sizeof(debug_msg), "📝 COMPARACIÓN STRING: %s %s %s = %s",
                left_value, node->value, right_value, resultado_bool ? "true" : "false");
        procesador_debug_output(context, debug_msg);
    }
    else {
        // OTROS CASOS (incluyendo NULL)
        if (tipo_comp == COMP_IGUAL) {
            resultado_bool = (strcmp(left_value, right_value) == 0);
        } else if (tipo_comp == COMP_DIFERENTE) {
            resultado_bool = (strcmp(left_value, right_value) != 0);
        }

        snprintf(debug_msg, sizeof(debug_msg), "🔍 COMPARACIÓN GENERAL: %s %s %s = %s",
                left_value, node->value, right_value, resultado_bool ? "true" : "false");
        procesador_debug_output(context, debug_msg);
    }

    // Formatear resultado
    strcpy(resultado_str, resultado_bool ? "true" : "false");

    snprintf(debug_msg, sizeof(debug_msg), "✅ RESULTADO COMPARACIÓN: %s", resultado_str);
    procesador_debug_output(context, debug_msg);

    free(left_value);
    free(right_value);
    return resultado_str;
}

// Funciones auxiliares para realizar comparaciones específicas
int realizar_comparacion_numerica(double valor1, double valor2, TipoComparacion tipo_comp) {
    switch (tipo_comp) {
        case COMP_IGUAL:        return fabs(valor1 - valor2) < 1e-10; // Igualdad con tolerancia
        case COMP_DIFERENTE:    return fabs(valor1 - valor2) >= 1e-10;
        case COMP_MAYOR:        return valor1 > valor2;
        case COMP_MENOR:        return valor1 < valor2;
        case COMP_MAYOR_IGUAL:  return valor1 >= valor2;
        case COMP_MENOR_IGUAL:  return valor1 <= valor2;
        default:                return 0;
    }
}

int realizar_comparacion_char(char char1, char char2, TipoComparacion tipo_comp) {
    switch (tipo_comp) {
        case COMP_IGUAL:        return char1 == char2;
        case COMP_DIFERENTE:    return char1 != char2;
        case COMP_MAYOR:        return char1 > char2;
        case COMP_MENOR:        return char1 < char2;
        case COMP_MAYOR_IGUAL:  return char1 >= char2;
        case COMP_MENOR_IGUAL:  return char1 <= char2;
        default:                return 0;
    }
}

int realizar_comparacion_boolean(int bool1, int bool2, TipoComparacion tipo_comp) {
    switch (tipo_comp) {
        case COMP_IGUAL:        return bool1 == bool2;
        case COMP_DIFERENTE:    return bool1 != bool2;
        // Otros operadores no válidos para boolean
        default:                return 0;
    }
}

int realizar_comparacion_string(const char* str1, const char* str2, TipoComparacion tipo_comp) {
    int comparacion = strcmp(str1, str2);

    switch (tipo_comp) {
        case COMP_IGUAL:        return comparacion == 0;
        case COMP_DIFERENTE:    return comparacion != 0;
        // En Java básico, strings no usan >, <, >=, <= (requiere .compareTo())
        default:                return 0;
    }
}