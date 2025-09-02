#ifndef BUILDER_FUNCIONES_H
#define BUILDER_FUNCIONES_H

#include "ast.h"

// ========== BUILDERS PARA FUNCIONES ==========

/**
 * Construye un nodo FUNCION
 */
ASTNode* build_funcion(ASTNode* tipo_retorno_node, const char* nombre_funcion, ASTNode* parametros_node, ASTNode* bloque_funcion_node, int line, int column);

/**
 * Construye un nodo PARAMETROS con un solo parámetro
 */
ASTNode* build_parametros_single(ASTNode* parametro_node, int line, int column);

/**
 * Agrega un parámetro a un nodo PARAMETROS existente
 */
ASTNode* build_parametros_add(ASTNode* parametros_node, ASTNode* parametro_node);

/**
 * Construye un nodo PARAMETROS vacío (sin parámetros)
 */
ASTNode* build_parametros_vacio(int line, int column);

/**
 * Construye un nodo PARAMETRO simple (tipo primitivo)
 */
ASTNode* build_parametro_simple(ASTNode* tipo_node, const char* nombre_parametro, int line, int column);

/**
 * Construye un nodo PARAMETRO de array
 */
ASTNode* build_parametro_array(ASTNode* tipo_node, const char* nombre_parametro, ASTNode* brackets_node, int line, int column);

/**
 * Construye un nodo BLOQUE_FUNCION con scope
 */
ASTNode* build_bloque_funcion(ASTNode* cuerpo_funcion_node, int line, int column);

// ========== BUILDERS PARA CUERPO DE FUNCIÓN ==========

/**
 * Construye un nodo CUERPO_FUNCION con un solo elemento
 */
ASTNode* build_cuerpo_funcion_single(ASTNode* elemento_node, int line, int column);

/**
 * Agrega un elemento a un nodo CUERPO_FUNCION existente
 */
ASTNode* build_cuerpo_funcion_add(ASTNode* cuerpo_node, ASTNode* elemento_node);

/**
 * Construye un nodo CUERPO_FUNCION vacío
 */
ASTNode* build_cuerpo_funcion_vacio(int line, int column);

#endif // BUILDER_FUNCIONES_H