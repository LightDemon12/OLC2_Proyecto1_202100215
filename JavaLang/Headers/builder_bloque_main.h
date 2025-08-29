//
// Created by lightdemon on 29/08/25.
//

#ifndef BLOQUE_MAIN_BUILDER_H
#define BLOQUE_MAIN_BUILDER_H

#include "ast.h"

/**
 * Construye el nodo bloque_main
 *
 * @param instrucciones - Nodo de instrucciones
 * @param line - Línea del token
 * @param column - Columna del token
 * @return ASTNode* - Nodo bloque_main creado
 */
ASTNode* build_bloque_main_node(ASTNode* instrucciones, int line, int column);

#endif // BLOQUE_MAIN_BUILDER_H