#ifndef BUILDER_TIPOS_DATOS_H
#define BUILDER_TIPOS_DATOS_H

#include "ast.h"

// ========== BUILDERS REUTILIZABLES PARA TIPOS Y DATOS ==========

/**
 * Construye un nodo TIPO reutilizable
 */
ASTNode* build_tipo_node(const char* tipo_token, int line, int column);

/**
 * Construye un nodo DATO específico para strings
 */
ASTNode* build_dato_string(const char* valor, int line, int column);

/**
 * Construye un nodo DATO específico para enteros
 */
ASTNode* build_dato_int(const char* valor, int line, int column);

/**
 * Construye un nodo DATO específico para floats
 */
ASTNode* build_dato_float(const char* valor, int line, int column);

/**
 * Construye un nodo DATO específico para chars
 */
ASTNode* build_dato_char(const char* valor, int line, int column);

/**
 * Construye un nodo DATO específico para booleanos
 */
ASTNode* build_dato_boolean(const char* valor, int line, int column);

/**
 * Construye un nodo DATO específico para null
 */
ASTNode* build_dato_null(int line, int column);
// ========== LITERALES BÁSICOS ==========
ASTNode* build_string_literal(const char* value, int line, int column);
ASTNode* build_int_literal(const char* value, int line, int column);
ASTNode* build_float_literal(const char* value, int line, int column);
ASTNode* build_char_literal(const char* value, int line, int column);
ASTNode* build_boolean_literal(const char* value, int line, int column);
ASTNode* build_identifier(const char* name, int line, int column);
ASTNode* build_null_literal(int line, int column);


#endif // BUILDER_TIPOS_DATOS_H