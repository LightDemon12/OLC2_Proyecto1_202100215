//
// Created by lightdemon on 1/09/25.
//

#ifndef BUILDER_ARRAYS_ACCESO_H
#define BUILDER_ARRAYS_ACCESO_H

#include "ast.h"

// ========== BUILDERS PARA ACCESO Y ASIGNACIÓN DE ARRAYS ==========

/**
 * Construye un nodo ARRAY_ACCESO_1D para acceso a vector
 * Para casos como: array[0];
 */
ASTNode* build_array_acceso_1d(const char* nombre_array, ASTNode* indice_node, int line, int column);

/**
 * Construye un nodo ARRAY_ACCESO_MULTIDIMENSIONAL para acceso a arrays nD
 * Para casos como: matriz[0][1]; cubo[0][1][2];
 */
ASTNode* build_array_acceso_multidimensional(const char* nombre_array, ASTNode* brackets_indices_node, int line, int column);

/**
 * Construye un nodo ARRAY_ASIGNACION_1D para asignación desde vector
 * Para casos como: int x = array[0];
 */
ASTNode* build_array_asignacion_1d(ASTNode* tipo_node, const char* nombre_variable, const char* nombre_array, ASTNode* indice_node, int line, int column);

/**
 * Construye un nodo ARRAY_ASIGNACION_MULTIDIMENSIONAL para asignación desde arrays nD
 * Para casos como: float y = matriz[0][1];
 */
ASTNode* build_array_asignacion_multidimensional(ASTNode* tipo_node, const char* nombre_variable, const char* nombre_array, ASTNode* brackets_indices_node, int line, int column);

/**
 * Construye un nodo ARRAY_ASIGNACION_ELEMENTO para asignar valor a un elemento
 * Para casos como: matriz[0][1] = 5;
 */
ASTNode* build_array_asignacion_elemento(const char* nombre_array, ASTNode* brackets_indices_node, ASTNode* expresion_node, int line, int column);

/**
 * Construye un nodo BRACKETS_INDICES con un solo índice
 */
ASTNode* build_brackets_indices_single(ASTNode* expresion_node, int line, int column);

/**
 * Agrega un índice a un nodo BRACKETS_INDICES existente
 */
ASTNode* build_brackets_indices_add(ASTNode* brackets_indices_node, ASTNode* expresion_node);

#endif // BUILDER_ARRAYS_ACCESO_H