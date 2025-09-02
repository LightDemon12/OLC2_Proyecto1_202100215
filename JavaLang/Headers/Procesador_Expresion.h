//
// Created by lightdemon on 2/09/25.
//

#ifndef PROCESADOR_EXPRESION_H
#define PROCESADOR_EXPRESION_H

#include "node_processor.h"
#include "ast.h"

/**
 * Procesador principal de expresiones - DELEGADOR
 * Recibe cualquier tipo de expresión y la delega al procesador especializado
 */
char* process_expresion_node(NodeProcessorContext* context, ASTNode* node);

/**
 * Función para determinar si un nodo es una expresión
 */
int is_expresion_node(const char* node_type);

#endif // PROCESADOR_EXPRESION_H