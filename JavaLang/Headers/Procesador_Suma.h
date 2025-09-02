//
// Created by lightdemon on 2/09/25.
//

#ifndef PROCESADOR_SUMA_H
#define PROCESADOR_SUMA_H

#include "node_processor.h"
#include "ast.h"

/**
 * Procesador especializado para operaciones de suma
 * Maneja EXPRESION_BINARIA con operador "+"
 */
char* process_suma_node(NodeProcessorContext* context, ASTNode* node);

/**
 * Función auxiliar para evaluar suma entre dos valores
 */
double evaluar_suma(double left, double right);

#endif // PROCESADOR_SUMA_H