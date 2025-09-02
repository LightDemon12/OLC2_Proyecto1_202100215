//
// Created by lightdemon on 1/09/25.
//

#ifndef BUILDER_EXPRESION_ARRAYS_H
#define BUILDER_EXPRESION_ARRAYS_H

#include "ast.h"

// ========== BUILDERS PARA ACCESO A ARRAYS EN EXPRESIONES ==========

/**
 * Construye un nodo ASIGNACION_COMPUESTA_ARRAY_1D
 * Para casos como: datos[i] += 5
 */
ASTNode* build_asignacion_compuesta_array_1d(const char* nombre_array, ASTNode* indice_node, ASTNode* operador_node, ASTNode* expresion_node, int line, int column);

/**
 * Construye un nodo ASIGNACION_COMPUESTA_ARRAY_MULTIDIMENSIONAL
 * Para casos como: matriz[i][j] *= 2
 */
ASTNode* build_asignacion_compuesta_array_multidimensional(const char* nombre_array, ASTNode* brackets_indices_node, ASTNode* operador_node, ASTNode* expresion_node, int line, int column);

#endif // BUILDER_EXPRESION_ARRAYS_H