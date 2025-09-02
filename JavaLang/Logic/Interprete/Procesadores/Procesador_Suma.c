//
// Created by lightdemon on 2/09/25.
//
#include "../../../Headers/Procesador_Suma.h"
#include "../../../Headers/Procesador_Expresion.h"
#include "../../../Headers/node_processor.h"
#include "../../Headers/mainview.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* process_suma_node(NodeProcessorContext* context, ASTNode* node) {
    if (!context || !node) {
        procesador_error_output(context, "Contexto o nodo NULL en suma");
        return NULL;
    }

    // DEBUG VISIBLE EN GUI
    char debug_msg[256];
    snprintf(debug_msg, sizeof(debug_msg), "Iniciando suma en linea %d", node->line);
    procesador_debug_output(context, debug_msg);

    // Verificar que es una suma válida
    if (!node->value || strcmp(node->value, "+") != 0) {
        procesador_error_output(context, "Nodo no es una suma valida");
        return NULL;
    }

    if (node->child_count < 2) {
        procesador_error_output(context, "Suma con menos de 2 operandos");
        return NULL;
    }

    // Obtener operandos izquierdo y derecho
    ASTNode* left_node = node->children[0];
    ASTNode* right_node = node->children[1];

    procesador_debug_output(context, "-> Evaluando operando izquierdo...");

    // Evaluar operando izquierdo (puede ser otra expresión)
    char* left_value = process_expresion_node(context, left_node);
    if (!left_value) {
        procesador_error_output(context, "No se pudo evaluar operando izquierdo");
        return NULL;
    }

    procesador_debug_output(context, "-> Evaluando operando derecho...");

    // Evaluar operando derecho (puede ser otra expresión)
    char* right_value = process_expresion_node(context, right_node);
    if (!right_value) {
        procesador_error_output(context, "No se pudo evaluar operando derecho");
        free(left_value);
        return NULL;
    }

    // MOSTRAR OPERANDOS EN GUI
    snprintf(debug_msg, sizeof(debug_msg), "Operandos detectados: '%s' + '%s'", left_value, right_value);
    procesador_debug_output(context, debug_msg);

    // Convertir a números y sumar
    double left_num = atof(left_value);
    double right_num = atof(right_value);
    double resultado = evaluar_suma(left_num, right_num);

    // Crear string del resultado
    char* resultado_str = malloc(32);
    snprintf(resultado_str, 32, "%.6g", resultado);

    // RESULTADO VISIBLE EN GUI
    snprintf(debug_msg, sizeof(debug_msg), "[OK] SUMA COMPLETADA: %s + %s = %s",
             left_value, right_value, resultado_str);
    procesador_debug_output(context, debug_msg);

    // Limpiar memoria
    free(left_value);
    free(right_value);

    return resultado_str;
}

double evaluar_suma(double left, double right) {
    return left + right;
}