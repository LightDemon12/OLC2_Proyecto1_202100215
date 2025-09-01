//
// Created by lightdemon on 31/08/25.
//

#ifndef BUILDER_SCOPE_H
#define BUILDER_SCOPE_H

#include "ast.h"

// ========== BUILDERS PARA MANEJO DE SCOPES ==========

/**
 * Construye un nodo SCOPE que envuelve instrucciones
 *
 * @param instrucciones_node - Nodo de instrucciones dentro del scope
 * @param scope_type - Tipo de scope ("GLOBAL", "MAIN", "IF", "SWITCH", "CASE", "WHILE", "FOR", "FUNCTION")
 * @param line - Línea del token
 * @param column - Columna del token
 * @return ASTNode* - Nodo SCOPE creado
 */
ASTNode* build_scope(ASTNode* instrucciones_node, const char* scope_type, int line, int column);

/**
 * Construye un scope para el main
 *
 * @param instrucciones_node - Instrucciones del main
 * @param line - Línea del token
 * @param column - Columna del token
 * @return ASTNode* - Nodo SCOPE_MAIN creado
 */
ASTNode* build_scope_main(ASTNode* instrucciones_node, int line, int column);

/**
 * Construye un scope para bloques de control (if, while, etc.)
 *
 * @param instrucciones_node - Instrucciones del bloque
 * @param control_type - Tipo de control ("IF", "ELSE", "ELSE_IF", "WHILE", "FOR", "SWITCH", "CASE")
 * @param line - Línea del token
 * @param column - Columna del token
 * @return ASTNode* - Nodo SCOPE_BLOQUE creado
 */
ASTNode* build_scope_bloque(ASTNode* instrucciones_node, const char* control_type, int line, int column);

#endif // BUILDER_SCOPE_H