#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Procesador_Declaraciones.h"
#include "../../../Headers/ast.h"
#include "../../../Headers/node_processor.h"
#include "../../../Headers/Tabla_Simbolos.h"
#include "../../../Headers/error_manager.h"
#include "../../../Headers/Procesador_Expresion.h"
#include "../../../Headers/node_utils.h"
#include "../../../Headers/Procesador_casting.h"  // ← AGREGAR PARA CONVERSIONES

extern ErrorManager* global_error_manager;

// ===== FUNCIÓN UNIFICADA QUE MANEJA TODOS LOS TIPOS =====
int realizar_operacion_compuesta_universal(const char* valor_actual_str, TipoDato tipo_variable,
                                          char* operador, const char* valor_expresion_str,
                                          TipoDato tipo_expresion, char** resultado_str) {

    printf("DEBUG OP_COMP: %s(%s) %s %s(%s) = ",
           valor_actual_str, tipo_dato_to_string(tipo_variable),
           operador,
           valor_expresion_str, tipo_dato_to_string(tipo_expresion));

    // 1. CONVERTIR VALORES A DOUBLE PARA CÁLCULOS
    double valor_actual = convertir_a_numero(valor_actual_str, tipo_variable);
    double valor_expresion = convertir_a_numero(valor_expresion_str, tipo_expresion);

    double resultado_numerico;

    // 2. REALIZAR OPERACIÓN
    if (strcmp(operador, "+") == 0) {
        resultado_numerico = valor_actual + valor_expresion;
    } else if (strcmp(operador, "-") == 0) {
        resultado_numerico = valor_actual - valor_expresion;
    } else if (strcmp(operador, "*") == 0) {
        resultado_numerico = valor_actual * valor_expresion;
    } else if (strcmp(operador, "/") == 0) {
        if (valor_expresion == 0.0) {
            printf("ERROR: División por cero\n");
            return 0;
        }
        resultado_numerico = valor_actual / valor_expresion;
    } else if (strcmp(operador, "%") == 0) {
        if (valor_expresion == 0.0) {
            printf("ERROR: Módulo por cero\n");
            return 0;
        }
        resultado_numerico = (double)((int)valor_actual % (int)valor_expresion);
    } else if (strcmp(operador, "&") == 0) {
        resultado_numerico = (double)((int)valor_actual & (int)valor_expresion);
    } else if (strcmp(operador, "|") == 0) {
        resultado_numerico = (double)((int)valor_actual | (int)valor_expresion);
    } else if (strcmp(operador, "^") == 0) {
        resultado_numerico = (double)((int)valor_actual ^ (int)valor_expresion);
    } else if (strcmp(operador, ">>") == 0) {
        resultado_numerico = (double)((int)valor_actual >> (int)valor_expresion);
    } else if (strcmp(operador, "<<") == 0) {
        resultado_numerico = (double)((int)valor_actual << (int)valor_expresion);
    } else {
        printf("ERROR: Operador '%s' no soportado\n", operador);
        return 0;
    }

    // 3. CONVERTIR RESULTADO AL TIPO DE LA VARIABLE
    *resultado_str = convertir_numero_a_string(resultado_numerico, tipo_variable);

    printf("%s\n", *resultado_str);
    return 1;
}

int procesar_asignacion_compuesta(NodeProcessorContext* context, ASTNode* node) {
    if (!context || !node || node->child_count < 3) {
        printf("ERROR: Parámetros inválidos para asignación compuesta\n");
        return 1;
    }

    // Extraer componentes del AST
    ASTNode* identifier_node = node->children[0];    // IDENTIFIER
    ASTNode* operador_node = node->children[1];      // OPERADOR_ASIGNACION
    ASTNode* expresion_node = node->children[2];     // DATO/EXPRESION

    char* variable = identifier_node->value;
    char* operador_completo = operador_node->value;

    printf("DEBUG PROC_ASIG: Procesando %s %s <expresion>\n", variable, operador_completo);

    // 1. Buscar la variable
    Simbolo* simbolo_actual = buscar_simbolo(context->tabla_simbolos, variable);
    if (!simbolo_actual) {
        char error_msg[256];
        snprintf(error_msg, sizeof(error_msg), "Variable '%s' no está declarada", variable);
        if (global_error_manager) {
            error_manager_add_semantico(global_error_manager, node->line, node->column,
                                      error_msg, variable, context->tabla_simbolos->ambito_actual);
        }
        return 1;
    }

    // 2. EVALUAR LA EXPRESIÓN USANDO EL PROCESADOR
    printf("[DEBUG ASIG] Evaluando expresión del lado derecho...\n");

    char* resultado_expresion_str = process_expresion_node(context, expresion_node);
    if (!resultado_expresion_str) {
        printf("ERROR: No se pudo evaluar la expresión del lado derecho\n");
        return 1;
    }

    // 3. OBTENER TIPOS PARA ANÁLISIS SEMÁNTICO
    TipoDato tipo_variable = simbolo_actual->tipo_dato;
    TipoDato tipo_expresion = obtener_tipo_desde_nodo(expresion_node, context);

    printf("[DEBUG ASIG] Expresión evaluada: '%s' (tipo: %s)\n",
           resultado_expresion_str, tipo_dato_to_string(tipo_expresion));
    printf("[DEBUG ASIG] Variable '%s' tipo: %s, valor actual: '%s'\n",
           variable, tipo_dato_to_string(tipo_variable), simbolo_actual->valor);

    char* resultado_final_str = NULL;

    // 4. DETECTAR TIPO DE ASIGNACIÓN
    if (strcmp(operador_completo, "=") == 0) {
        // ===== ASIGNACIÓN SIMPLE: x = expresión =====
        printf("✅ ASIGNACIÓN SIMPLE detectada\n");

        // VERIFICAR COMPATIBILIDAD DE TIPOS CON PROMOCIÓN AUTOMÁTICA
        int es_compatible = 0;

        if (tipo_variable == tipo_expresion) {
            // Tipos idénticos
            es_compatible = 1;
            resultado_final_str = strdup(resultado_expresion_str);
            printf("   → Tipos idénticos, asignación directa\n");
        }
        else if (es_promocion_automatica(tipo_expresion, tipo_variable)) {
            // Promoción automática permitida
            es_compatible = 1;
            resultado_final_str = convertir_valor_cast(resultado_expresion_str, tipo_expresion, tipo_variable);
            printf("   → Promoción automática: %s → %s\n",
                   tipo_dato_to_string(tipo_expresion), tipo_dato_to_string(tipo_variable));
        }
        else if (tipos_compatibles_asignacion(tipo_variable, tipo_expresion)) {
            // Otras compatibilidades (como String concatenation)
            es_compatible = 1;
            resultado_final_str = strdup(resultado_expresion_str);
            printf("   → Tipos compatibles por asignación\n");
        }

        if (!es_compatible) {
            char error_msg[512];
            snprintf(error_msg, sizeof(error_msg),
                    "Asignación incompatible: no se puede asignar %s a variable %s de tipo %s",
                    tipo_dato_to_string(tipo_expresion), variable, tipo_dato_to_string(tipo_variable));

            if (global_error_manager) {
                error_manager_add_semantico(global_error_manager, node->line, node->column,
                                          error_msg, variable, context->tabla_simbolos->ambito_actual);
            }
            printf("ERROR: %s\n", error_msg);
            free(resultado_expresion_str);
            return 1;
        }

    } else {
        // ===== ASIGNACIÓN COMPUESTA: x += expresión, etc. =====
        printf("✅ ASIGNACIÓN COMPUESTA detectada\n");

        // Verificar que ambos tipos sean numéricos para operaciones compuestas
        if (!es_tipo_numerico(tipo_variable) || !es_tipo_numerico(tipo_expresion)) {
            char error_msg[512];
            snprintf(error_msg, sizeof(error_msg),
                    "Operación compuesta '%s' requiere tipos numéricos. Variable: %s, Expresión: %s",
                    operador_completo, tipo_dato_to_string(tipo_variable), tipo_dato_to_string(tipo_expresion));

            if (global_error_manager) {
                error_manager_add_semantico(global_error_manager, node->line, node->column,
                                          error_msg, operador_completo, context->tabla_simbolos->ambito_actual);
            }
            printf("ERROR: %s\n", error_msg);
            free(resultado_expresion_str);
            return 1;
        }

        // Extraer operador (quitar el '=')
        char operador[3] = {0};
        strncpy(operador, operador_completo, strlen(operador_completo) - 1);

        // Realizar operación compuesta con promoción automática
        if (!realizar_operacion_compuesta_universal(simbolo_actual->valor, tipo_variable,
                                                   operador, resultado_expresion_str, tipo_expresion,
                                                   &resultado_final_str)) {
            char error_msg[256];
            snprintf(error_msg, sizeof(error_msg), "Error en operación compuesta: %s %s", variable, operador_completo);
            if (global_error_manager) {
                error_manager_add_semantico(global_error_manager, node->line, node->column,
                                          error_msg, variable, context->tabla_simbolos->ambito_actual);
            }
            free(resultado_expresion_str);
            return 1;
        }
    }

    // 5. ACTUALIZAR LA VARIABLE
    if (!resultado_final_str) {
        printf("ERROR: No se pudo calcular el resultado final\n");
        free(resultado_expresion_str);
        return 1;
    }

    if (!actualizar_valor_simbolo(context->tabla_simbolos, variable, resultado_final_str)) {
        printf("ERROR: No se pudo actualizar la variable '%s'\n", variable);
        free(resultado_expresion_str);
        free(resultado_final_str);
        return 1;
    }

    printf("📝 Variable '%s' (%s) actualizada a: '%s'\n",
           variable, tipo_dato_to_string(tipo_variable), resultado_final_str);

    // Liberar memoria
    free(resultado_expresion_str);
    free(resultado_final_str);
    return 0;
}