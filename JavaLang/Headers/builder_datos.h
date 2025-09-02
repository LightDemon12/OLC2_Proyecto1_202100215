//
// Created by lightdemon on 29/08/25.
//

#ifndef BUILDER_DATOS_H
#define BUILDER_DATOS_H

#include "ast.h"

// ========== BUILDERS PARA TIPOS DE DATOS PRIMITIVOS ==========

/**
 * Construye un nodo STRING_LITERAL
 *
 * @param value - Valor del string (con o sin comillas)
 * @param line - Línea del token
 * @param column - Columna del token
 * @return ASTNode* - Nodo STRING_LITERAL creado
 */
ASTNode* build_string_literal(const char* value, int line, int column);

/**
 * Construye un nodo INT_LITERAL
 *
 * @param value - Valor del entero como string ("42")
 * @param line - Línea del token
 * @param column - Columna del token
 * @return ASTNode* - Nodo INT_LITERAL creado
 */
ASTNode* build_int_literal(const char* value, int line, int column);

/**
 * Construye un nodo FLOAT_LITERAL
 *
 * @param value - Valor del float como string ("3.14")
 * @param line - Línea del token
 * @param column - Columna del token
 * @return ASTNode* - Nodo FLOAT_LITERAL creado
 */
ASTNode* build_float_literal(const char* value, int line, int column);

/**
 * Construye un nodo CHAR_LITERAL
 *
 * @param value - Valor del char como string ("'a'")
 * @param line - Línea del token
 * @param column - Columna del token
 * @return ASTNode* - Nodo CHAR_LITERAL creado
 */
ASTNode* build_char_literal(const char* value, int line, int column);

/**
 * Construye un nodo BOOLEAN_LITERAL
 *
 * @param value - "true" o "false"
 * @param line - Línea del token
 * @param column - Columna del token
 * @return ASTNode* - Nodo BOOLEAN_LITERAL creado
 */
ASTNode* build_boolean_literal(const char* value, int line, int column);

/**
 * Construye un nodo IDENTIFIER
 *
 * @param name - Nombre del identificador
 * @param line - Línea del token
 * @param column - Columna del token
 * @return ASTNode* - Nodo IDENTIFIER creado
 */
ASTNode* build_identifier(const char* name, int line, int column);

/**
 * Construye un nodo NULL_LITERAL
 *
 * @param line - Línea del token
 * @param column - Columna del token
 * @return ASTNode* - Nodo NULL_LITERAL creado
 */
ASTNode* build_null_literal(int line, int column);

#endif // BUILDER_DATOS_H