//
// Created by lightdemon on 1/09/25.
//

#ifndef BUILDER_VECTORES_H
#define BUILDER_VECTORES_H

#include "ast.h"

// ========== BUILDERS PARA VECTORES/ARRAYS ==========

/**
 * Construye un nodo VECTOR_NEW para declaración con new
 * Para casos como: int[] array = new int[10];
 *
 * @param tipo_array_node - Nodo del tipo del array (ej: int)
 * @param nombre_array - Nombre de la variable del array
 * @param tipo_new_node - Nodo del tipo en el new (ej: int)
 * @param tamano_node - Expresión del tamaño del array
 * @param line - Línea del token
 * @param column - Columna del token
 * @return ASTNode* - Nodo VECTOR_NEW creado
 */
ASTNode* build_vector_new(ASTNode* tipo_array_node, const char* nombre_array, ASTNode* tipo_new_node, ASTNode* tamano_node, int line, int column);

/**
 * Construye un nodo VECTOR_INICIALIZADO para declaración con valores
 * Para casos como: int[] array = {1, 2, 3, 4, 5};
 *
 * @param tipo_array_node - Nodo del tipo del array (ej: int)
 * @param nombre_array - Nombre de la variable del array
 * @param contenido_node - Nodo del contenido del vector
 * @param line - Línea del token
 * @param column - Columna del token
 * @return ASTNode* - Nodo VECTOR_INICIALIZADO creado
 */
ASTNode* build_vector_inicializado(ASTNode* tipo_array_node, const char* nombre_array, ASTNode* contenido_node, int line, int column);

/**
 * Construye un nodo CONTENIDO_VECTOR con una sola expresión
 *
 * @param expresion_node - Primera expresión del contenido
 * @param line - Línea del token
 * @param column - Columna del token
 * @return ASTNode* - Nodo CONTENIDO_VECTOR creado
 */
ASTNode* build_contenido_vector_single(ASTNode* expresion_node, int line, int column);

/**
 * Agrega una expresión a un nodo CONTENIDO_VECTOR existente
 *
 * @param contenido_node - Nodo CONTENIDO_VECTOR existente
 * @param expresion_node - Nueva expresión a agregar
 * @return ASTNode* - Nodo CONTENIDO_VECTOR actualizado
 */
ASTNode* build_contenido_vector_add(ASTNode* contenido_node, ASTNode* expresion_node);

#endif // BUILDER_VECTORES_H