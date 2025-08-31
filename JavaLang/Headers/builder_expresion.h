#ifndef BUILDER_EXPRESION_H
#define BUILDER_EXPRESION_H

#include "ast.h"

/**
 * Construye una expresión binaria (operador entre dos expresiones)
 *
 * @param izquierda - Expresión del lado izquierdo
 * @param operador - Operador como string ("+", "-", "*", "/", etc.)
 * @param derecha - Expresión del lado derecho
 * @param line - Línea del token
 * @param column - Columna del token
 * @return ASTNode* - Nodo EXPRESION_BINARIA creado
 */
ASTNode* build_expresion_binaria(ASTNode* izquierda, const char* operador, ASTNode* derecha, int line, int column);

/**
 * Construye una expresión unaria (operador antes de una expresión)
 *
 * @param operador - Operador unario como string ("!", "++", "--")
 * @param expresion - Expresión sobre la que actúa el operador
 * @param line - Línea del token
 * @param column - Columna del token
 * @return ASTNode* - Nodo EXPRESION_UNARIA creado
 */
ASTNode* build_expresion_unaria(const char* operador, ASTNode* expresion, int line, int column);

/**
 * Construye una expresión con paréntesis
 *
 * @param expresion - Expresión dentro de los paréntesis
 * @param line - Línea del token
 * @param column - Columna del token
 * @return ASTNode* - La misma expresión (los paréntesis son solo para precedencia)
 */
ASTNode* build_expresion_parentesis(ASTNode* expresion, int line, int column);

#endif // BUILDER_EXPRESION_H