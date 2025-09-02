//
// Created by lightdemon on 1/09/25.
//

#ifndef BUILDER_LLAMADAS_FUNCIONES_H
#define BUILDER_LLAMADAS_FUNCIONES_H

#include "ast.h"

// ========== BUILDERS PARA LLAMADAS A FUNCIONES ==========

/**
 * Construye un nodo LLAMADA_FUNCION
 * Para casos como: factorial(n), suma(a, b), procesar()
 */
ASTNode* build_llamada_funcion(const char* nombre_funcion, ASTNode* argumentos_node, int line, int column);

/**
 * Construye un nodo ARGUMENTOS con un solo argumento
 */
ASTNode* build_argumentos_single(ASTNode* argumento_node, int line, int column);

/**
 * Agrega un argumento a un nodo ARGUMENTOS existente
 */
ASTNode* build_argumentos_add(ASTNode* argumentos_node, ASTNode* argumento_node);

/**
 * Construye un nodo ARGUMENTOS vacío (sin argumentos)
 */
ASTNode* build_argumentos_vacio(int line, int column);

#endif // BUILDER_LLAMADAS_FUNCIONES_H