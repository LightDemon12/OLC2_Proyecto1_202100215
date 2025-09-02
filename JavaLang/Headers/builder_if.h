#ifndef BUILDER_IF_H
#define BUILDER_IF_H

#include "ast.h"

// ========== BUILDERS PARA IF CON LLAVES ==========

/**
 * Construye un nodo IF_SIMPLE con llaves
 */
ASTNode* build_if_simple(ASTNode* condicion_node, ASTNode* instrucciones_node, int line, int column);

/**
 * Construye un nodo IF_CON_ELSE con llaves en ambos bloques
 */
ASTNode* build_if_con_else(ASTNode* condicion_node, ASTNode* instrucciones_if_node, ASTNode* instrucciones_else_node, int line, int column);

/**
 * Construye un nodo IF_CON_ELSE_IF con llaves
 */
ASTNode* build_if_con_else_if(ASTNode* condicion_node, ASTNode* instrucciones_if_node, ASTNode* lista_else_if_node, ASTNode* instrucciones_else_node, int line, int column);

// ========== BUILDERS PARA IF SIN LLAVES ==========

/**
 * Construye un nodo IF_SIMPLE sin llaves (instrucción única)
 */
ASTNode* build_if_simple_sin_llaves(ASTNode* condicion_node, ASTNode* instruccion_node, int line, int column);

/**
 * Construye un nodo IF_CON_ELSE sin llaves (instrucciones únicas)
 */
ASTNode* build_if_con_else_sin_llaves(ASTNode* condicion_node, ASTNode* instruccion_if_node, ASTNode* instruccion_else_node, int line, int column);

/**
 * Construye un nodo IF_CON_ELSE mixto 1 (IF con llaves, ELSE sin llaves)
 */
ASTNode* build_if_con_else_mixto_1(ASTNode* condicion_node, ASTNode* instrucciones_if_node, ASTNode* instruccion_else_node, int line, int column);

/**
 * Construye un nodo IF_CON_ELSE mixto 2 (IF sin llaves, ELSE con llaves)
 */
ASTNode* build_if_con_else_mixto_2(ASTNode* condicion_node, ASTNode* instruccion_if_node, ASTNode* instrucciones_else_node, int line, int column);

/**
 * Construye un nodo IF_CON_ELSE_IF sin llaves
 */
ASTNode* build_if_con_else_if_sin_llaves(ASTNode* condicion_node, ASTNode* instruccion_if_node, ASTNode* lista_else_if_node, ASTNode* instruccion_else_node, int line, int column);

/**
 * Construye un nodo IF_CON_ELSE_IF sin else final
 */
ASTNode* build_if_con_else_if_sin_else_final(ASTNode* condicion_node, ASTNode* instruccion_if_node, ASTNode* lista_else_if_node, int line, int column);

// ========== BUILDERS PARA ELSE IF ==========

/**
 * Construye un nodo ELSE_IF con llaves
 */
ASTNode* build_else_if(ASTNode* condicion_node, ASTNode* instrucciones_node, int line, int column);

/**
 * Construye un nodo ELSE_IF sin llaves
 */
ASTNode* build_else_if_sin_llaves(ASTNode* condicion_node, ASTNode* instruccion_node, int line, int column);

// ========== BUILDERS PARA LISTAS ELSE IF ==========

/**
 * Construye una lista de ELSE_IF con un solo elemento
 */
ASTNode* build_lista_else_if_single(ASTNode* else_if_node, int line, int column);

/**
 * Agrega un ELSE_IF a una lista existente
 */
ASTNode* build_lista_else_if_add(ASTNode* lista_node, ASTNode* else_if_node);

/**
 * Construye una lista de ELSE_IF sin llaves con un solo elemento
 */
ASTNode* build_lista_else_if_sin_llaves_single(ASTNode* else_if_node, int line, int column);

/**
 * Agrega un ELSE_IF sin llaves a una lista existente
 */
ASTNode* build_lista_else_if_sin_llaves_add(ASTNode* lista_node, ASTNode* else_if_node);

#endif // BUILDER_IF_H