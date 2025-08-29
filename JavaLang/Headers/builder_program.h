//
// Created by lightdemon on 29/08/25.
//

#ifndef PROGRAM_BUILDER_H
#define PROGRAM_BUILDER_H

#include "ast.h"

/**
 * Construye el nodo PROGRAM
 *
 * @param bloque_main - Nodo del bloque main
 * @param line - Línea del token
 * @param column - Columna del token
 * @return ASTNode* - Nodo PROGRAM creado
 */
ASTNode* build_program_node(ASTNode* bloque_main, int line, int column);

#endif // PROGRAM_BUILDER_H