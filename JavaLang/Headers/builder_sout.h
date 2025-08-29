//
// Created by lightdemon on 29/08/25.
//

#ifndef BUILDER_SOUT_H
#define BUILDER_SOUT_H

#include "ast.h"

/**
 * Construye el nodo SOUT con un string literal
 *
 * @param string_value - Valor del string (incluyendo comillas)
 * @param line - Línea del token
 * @param column - Columna del token
 * @return ASTNode* - Nodo SOUT creado con su STRING_LITERAL
 */
ASTNode* build_sout_node(const char* string_value, int line, int column);

#endif // BUILDER_SOUT_H