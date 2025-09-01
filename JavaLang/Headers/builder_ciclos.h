//
// Created by lightdemon on 31/08/25.
//

#ifndef BUILDER_CICLOS_H
#define BUILDER_CICLOS_H

#include "ast.h"

// ========== BUILDERS PARA CICLOS ==========

/**
 * Construye un nodo WHILE con SCOPE
 *
 * @param condicion_node - Nodo de la expresión de condición
 * @param instrucciones_node - Nodo de las instrucciones del ciclo
 * @param line - Línea del token
 * @param column - Columna del token
 * @return ASTNode* - Nodo WHILE creado con SCOPE
 */
ASTNode* build_while(ASTNode* condicion_node, ASTNode* instrucciones_node, int line, int column);

/**
 * Construye un nodo DO_WHILE con SCOPE
 *
 * @param instrucciones_node - Nodo de las instrucciones del ciclo
 * @param condicion_node - Nodo de la expresión de condición
 * @param line - Línea del token
 * @param column - Columna del token
 * @return ASTNode* - Nodo DO_WHILE creado con SCOPE
 */
ASTNode* build_do_while(ASTNode* instrucciones_node, ASTNode* condicion_node, int line, int column);

#endif // BUILDER_CICLOS_H