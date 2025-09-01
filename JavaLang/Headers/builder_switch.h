#ifndef BUILDER_SWITCH_H
#define BUILDER_SWITCH_H

#include "ast.h"

// ========== BUILDERS PARA SENTENCIA SWITCH ==========

/**
 * Construye un nodo SWITCH completo con SCOPE
 *
 * @param expresion_node - Nodo de la expresión a evaluar
 * @param lista_casos_node - Nodo de la lista de casos
 * @param line - Línea del token
 * @param column - Columna del token
 * @return ASTNode* - Nodo SWITCH creado con SCOPE
 */
ASTNode* build_switch(ASTNode* expresion_node, ASTNode* lista_casos_node, int line, int column);

/**
 * Construye un nodo CASO individual con SCOPE
 *
 * @param valor_node - Nodo del valor del caso (dato)
 * @param instrucciones_node - Nodo de las instrucciones del caso
 * @param sentencia_node - Nodo de la sentencia de control (break, continue, return)
 * @param line - Línea del token
 * @param column - Columna del token
 * @return ASTNode* - Nodo CASO creado con SCOPE
 */
ASTNode* build_caso(ASTNode* valor_node, ASTNode* instrucciones_node, ASTNode* sentencia_node, int line, int column);

/**
 * Construye un nodo CASO con DEFAULT
 *
 * @param valor_node - Nodo del valor del caso (dato)
 * @param instrucciones_node - Nodo de las instrucciones del caso
 * @param sentencia_node - Nodo de la sentencia de control
 * @param instrucciones_default_node - Nodo de las instrucciones del default
 * @param line - Línea del token
 * @param column - Columna del token
 * @return ASTNode* - Nodo CASO_CON_DEFAULT creado con SCOPEs
 */
ASTNode* build_caso_con_default(ASTNode* valor_node, ASTNode* instrucciones_node, ASTNode* sentencia_node, ASTNode* instrucciones_default_node, int line, int column);

/**
 * Construye una lista de casos con un solo elemento
 *
 * @param caso_node - Nodo CASO inicial
 * @param line - Línea del token
 * @param column - Columna del token
 * @return ASTNode* - Nodo LISTA_CASOS creado
 */
ASTNode* build_lista_casos_single(ASTNode* caso_node, int line, int column);

/**
 * Agrega un caso a una lista existente
 *
 * @param lista_existente - Lista CASOS existente
 * @param nuevo_caso - Nuevo nodo CASO a agregar
 * @return ASTNode* - Lista CASOS actualizada
 */
ASTNode* build_lista_casos_add(ASTNode* lista_existente, ASTNode* nuevo_caso);

#endif // BUILDER_SWITCH_H