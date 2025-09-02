//
// Created by lightdemon on 1/09/25.
//

#ifndef BUILDER_ARRAYS_MULTIDIMENSIONAL_H
#define BUILDER_ARRAYS_MULTIDIMENSIONAL_H

#include "ast.h"

// ========== BUILDERS PARA ARRAYS MULTIDIMENSIONALES ==========

/**
 * Construye un nodo ARRAY_MULTIDIMENSIONAL_NEW para declaración con new
 * Para casos como: int[][][] array = new int[2][3][4];
 *
 * @param tipo_node - Nodo del tipo base del array
 * @param brackets_node - Nodo con la secuencia de corchetes del tipo
 * @param nombre_array - Nombre de la variable del array
 * @param tipo_new_node - Nodo del tipo en el new
 * @param brackets_new_node - Nodo con las dimensiones del array
 * @param line - Línea del token
 * @param column - Columna del token
 * @return ASTNode* - Nodo ARRAY_MULTIDIMENSIONAL_NEW creado
 */
ASTNode* build_array_multidimensional_new(ASTNode* tipo_node, ASTNode* brackets_node, const char* nombre_array, ASTNode* tipo_new_node, ASTNode* brackets_new_node, int line, int column);

/**
 * Construye un nodo ARRAY_MULTIDIMENSIONAL_INICIALIZADO para declaración con valores
 * Para casos como: int[][][] array = {{{1, 2}, {3, 4}}, {{5, 6}, {7, 8}}};
 *
 * @param tipo_node - Nodo del tipo base del array
 * @param brackets_node - Nodo con la secuencia de corchetes del tipo
 * @param nombre_array - Nombre de la variable del array
 * @param brace_block_node - Nodo con el contenido del array
 * @param line - Línea del token
 * @param column - Columna del token
 * @return ASTNode* - Nodo ARRAY_MULTIDIMENSIONAL_INICIALIZADO creado
 */
ASTNode* build_array_multidimensional_inicializado(ASTNode* tipo_node, ASTNode* brackets_node, const char* nombre_array, ASTNode* brace_block_node, int line, int column);

/**
 * Construye un nodo BRACKETS con un solo par de corchetes
 *
 * @param line - Línea del token
 * @param column - Columna del token
 * @return ASTNode* - Nodo BRACKETS creado
 */
ASTNode* build_brackets_single(int line, int column);

/**
 * Agrega un par de corchetes a un nodo BRACKETS existente
 *
 * @param brackets_node - Nodo BRACKETS existente
 * @param line - Línea del token
 * @param column - Columna del token
 * @return ASTNode* - Nodo BRACKETS actualizado
 */
ASTNode* build_brackets_add(ASTNode* brackets_node, int line, int column);

/**
 * Construye un nodo BRACKETS_NEW con una sola dimensión
 *
 * @param expresion_node - Expresión de la primera dimensión
 * @param line - Línea del token
 * @param column - Columna del token
 * @return ASTNode* - Nodo BRACKETS_NEW creado
 */
ASTNode* build_brackets_new_single(ASTNode* expresion_node, int line, int column);

/**
 * Agrega una dimensión a un nodo BRACKETS_NEW existente
 *
 * @param brackets_new_node - Nodo BRACKETS_NEW existente
 * @param expresion_node - Nueva expresión de dimensión a agregar
 * @return ASTNode* - Nodo BRACKETS_NEW actualizado
 */
ASTNode* build_brackets_new_add(ASTNode* brackets_new_node, ASTNode* expresion_node);

/**
 * Construye un nodo BRACE_BLOCK
 *
 * @param brace_elements_node - Nodo con los elementos del bloque
 * @param line - Línea del token
 * @param column - Columna del token
 * @return ASTNode* - Nodo BRACE_BLOCK creado
 */
ASTNode* build_brace_block(ASTNode* brace_elements_node, int line, int column);

/**
 * Construye un nodo BRACE_ELEMENTS con un solo elemento
 *
 * @param brace_element_node - Primer elemento del bloque
 * @param line - Línea del token
 * @param column - Columna del token
 * @return ASTNode* - Nodo BRACE_ELEMENTS creado
 */
ASTNode* build_brace_elements_single(ASTNode* brace_element_node, int line, int column);

/**
 * Agrega un elemento a un nodo BRACE_ELEMENTS existente
 *
 * @param brace_elements_node - Nodo BRACE_ELEMENTS existente
 * @param brace_element_node - Nuevo elemento a agregar
 * @return ASTNode* - Nodo BRACE_ELEMENTS actualizado
 */
ASTNode* build_brace_elements_add(ASTNode* brace_elements_node, ASTNode* brace_element_node);

#endif // BUILDER_ARRAYS_MULTIDIMENSIONAL_H