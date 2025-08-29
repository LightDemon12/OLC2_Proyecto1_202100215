//
// Created by lightdemon on 29/08/25.
//

#ifndef BUILDER_INSTRUCCIONES_H
#define BUILDER_INSTRUCCIONES_H

#include "ast.h"

/**
 * Construye el nodo INSTRUCCIONES con una sola instrucción
 *
 * @param instruccion - Nodo de instrucción
 * @param line - Línea del token
 * @param column - Columna del token
 * @return ASTNode* - Nodo INSTRUCCIONES creado
 */
ASTNode* build_instrucciones_single(ASTNode* instruccion, int line, int column);

/**
 * Agrega una instrucción a un nodo INSTRUCCIONES existente
 *
 * @param instrucciones - Nodo INSTRUCCIONES existente
 * @param instruccion - Nueva instrucción a agregar
 * @return ASTNode* - El mismo nodo INSTRUCCIONES con la nueva instrucción
 */
ASTNode* build_instrucciones_add(ASTNode* instrucciones, ASTNode* instruccion);

#endif // BUILDER_INSTRUCCIONES_H