#ifndef BUILDER_IF_H
#define BUILDER_IF_H

#include "ast.h"

// ========== BUILDERS PARA SENTENCIAS IF ==========

/**
 * Construye un IF simple (solo if) con SCOPE
 *
 * @param condicion_node - Nodo de la expresión de condición
 * @param instrucciones_node - Nodo de las instrucciones del if
 * @param line - Línea del token
 * @param column - Columna del token
 * @return ASTNode* - Nodo IF_SIMPLE creado con SCOPE
 */
ASTNode* build_if_simple(ASTNode* condicion_node, ASTNode* instrucciones_node, int line, int column);

/**
 * Construye un IF con ELSE, ambos con SCOPEs separados
 *
 * @param condicion_node - Nodo de la expresión de condición
 * @param instrucciones_if_node - Nodo de las instrucciones del if
 * @param instrucciones_else_node - Nodo de las instrucciones del else
 * @param line - Línea del token
 * @param column - Columna del token
 * @return ASTNode* - Nodo IF_CON_ELSE creado con SCOPEs
 */
ASTNode* build_if_con_else(ASTNode* condicion_node, ASTNode* instrucciones_if_node, ASTNode* instrucciones_else_node, int line, int column);

/**
 * Construye un IF con ELSE IF y ELSE final, todos con SCOPEs separados
 *
 * @param condicion_node - Nodo de la expresión de condición inicial
 * @param instrucciones_if_node - Nodo de las instrucciones del if inicial
 * @param lista_else_if_node - Nodo de la lista de else if (cada uno con SCOPE)
 * @param instrucciones_else_node - Nodo de las instrucciones del else final
 * @param line - Línea del token
 * @param column - Columna del token
 * @return ASTNode* - Nodo IF_CON_ELSE_IF creado con SCOPEs
 */
ASTNode* build_if_con_else_if(ASTNode* condicion_node, ASTNode* instrucciones_if_node, ASTNode* lista_else_if_node, ASTNode* instrucciones_else_node, int line, int column);

/**
 * Construye un nodo ELSE_IF individual con SCOPE
 *
 * @param condicion_node - Nodo de la expresión de condición
 * @param instrucciones_node - Nodo de las instrucciones del else if
 * @param line - Línea del token
 * @param column - Columna del token
 * @return ASTNode* - Nodo ELSE_IF creado con SCOPE
 */
ASTNode* build_else_if(ASTNode* condicion_node, ASTNode* instrucciones_node, int line, int column);

/**
 * Construye una lista de ELSE IF con un solo elemento
 *
 * @param else_if_node - Nodo ELSE_IF inicial
 * @param line - Línea del token
 * @param column - Columna del token
 * @return ASTNode* - Nodo LISTA_ELSE_IF creado
 */
ASTNode* build_lista_else_if_single(ASTNode* else_if_node, int line, int column);

/**
 * Agrega un ELSE IF a una lista existente
 *
 * @param lista_existente - Lista ELSE_IF existente
 * @param nuevo_else_if - Nuevo nodo ELSE_IF a agregar
 * @return ASTNode* - Lista ELSE_IF actualizada
 */
ASTNode* build_lista_else_if_add(ASTNode* lista_existente, ASTNode* nuevo_else_if);

#endif // BUILDER_IF_H