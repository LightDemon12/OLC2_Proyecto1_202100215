//
// Created by lightdemon on 29/08/25.
//

#ifndef BUILDER_TIPOS_DATOS_H
#define BUILDER_TIPOS_DATOS_H

#include "ast.h"

// ========== BUILDERS REUTILIZABLES PARA TIPOS Y DATOS ==========

/**
 * Construye un nodo TIPO reutilizable
 *
 * @param tipo_token - Tipo como string ("string", "int", "float", etc.)
 * @param line - Línea del token
 * @param column - Columna del token
 * @return ASTNode* - Nodo TIPO creado
 */
ASTNode* build_tipo_node(const char* tipo_token, int line, int column);

/**
 * Construye un nodo DATO reutilizable (auto-detecta el tipo)
 *
 * @param valor - Valor como string
 * @param tipo_esperado - Tipo esperado ("string", "int", "float", etc.) - opcional
 * @param line - Línea del token
 * @param column - Columna del token
 * @return ASTNode* - Nodo DATO creado con el tipo correcto de literal
 */
ASTNode* build_dato_node(const char* valor, const char* tipo_esperado, int line, int column);

/**
 * Construye un nodo DATO específico para strings
 *
 * @param valor - Valor del string
 * @param line - Línea del token
 * @param column - Columna del token
 * @return ASTNode* - Nodo DATO con STRING_LITERAL
 */
ASTNode* build_dato_string(const char* valor, int line, int column);

/**
 * Construye un nodo DATO específico para enteros
 *
 * @param valor - Valor del entero como string
 * @param line - Línea del token
 * @param column - Columna del token
 * @return ASTNode* - Nodo DATO con INT_LITERAL
 */
ASTNode* build_dato_int(const char* valor, int line, int column);

/**
 * Construye un nodo DATO específico para floats
 *
 * @param valor - Valor del float como string
 * @param line - Línea del token
 * @param column - Columna del token
 * @return ASTNode* - Nodo DATO con FLOAT_LITERAL
 */
ASTNode* build_dato_float(const char* valor, int line, int column);

/**
 * Construye un nodo DATO específico para chars
 *
 * @param valor - Valor del char como string
 * @param line - Línea del token
 * @param column - Columna del token
 * @return ASTNode* - Nodo DATO con CHAR_LITERAL
 */
ASTNode* build_dato_char(const char* valor, int line, int column);

/**
 * Construye un nodo DATO específico para booleanos
 *
 * @param valor - "true" o "false"
 * @param line - Línea del token
 * @param column - Columna del token
 * @return ASTNode* - Nodo DATO con BOOLEAN_LITERAL
 */
ASTNode* build_dato_boolean(const char* valor, int line, int column);

#endif // BUILDER_TIPOS_DATOS_H