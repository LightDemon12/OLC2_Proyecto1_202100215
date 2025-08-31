//
// Created by lightdemon on 31/08/25.
//

#ifndef BUILDER_SENTENCIAS_H
#define BUILDER_SENTENCIAS_H

#include "ast.h"

// ========== BUILDERS PARA SENTENCIAS DE CONTROL ==========

/**
 * Construye un nodo BREAK
 *
 * @param line - Línea del token
 * @param column - Columna del token
 * @return ASTNode* - Nodo BREAK creado
 */
ASTNode* build_break(int line, int column);

/**
 * Construye un nodo CONTINUE
 *
 * @param line - Línea del token
 * @param column - Columna del token
 * @return ASTNode* - Nodo CONTINUE creado
 */
ASTNode* build_continue(int line, int column);

/**
 * Construye un nodo RETURN con expresión
 *
 * @param expresion_node - Nodo de la expresión a retornar
 * @param line - Línea del token
 * @param column - Columna del token
 * @return ASTNode* - Nodo RETURN_CON_VALOR creado
 */
ASTNode* build_return_con_valor(ASTNode* expresion_node, int line, int column);

/**
 * Construye un nodo RETURN sin expresión (void)
 *
 * @param line - Línea del token
 * @param column - Columna del token
 * @return ASTNode* - Nodo RETURN_VACIO creado
 */
ASTNode* build_return_vacio(int line, int column);

#endif // BUILDER_SENTENCIAS_H