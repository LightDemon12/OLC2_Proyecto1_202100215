#ifndef BUILDER_SOUT_H
#define BUILDER_SOUT_H

#include "ast.h"

/**
 * Construye un nodo SOUT que acepta una expresión
 *
 * @param expresion_node - Nodo de expresión a imprimir
 * @param line - Línea del token
 * @param column - Columna del token
 * @return ASTNode* - Nodo SOUT creado
 */
ASTNode* build_sout_node(ASTNode* expresion_node, int line, int column);

/**
 * Construye un nodo SOUT con string literal (función de compatibilidad)
 *
 * @param string_value - Valor string literal
 * @param line - Línea del token
 * @param column - Columna del token
 * @return ASTNode* - Nodo SOUT creado
 */
ASTNode* build_sout_string(const char* string_value, int line, int column);

#endif // BUILDER_SOUT_H