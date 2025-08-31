//
// Created by lightdemon on 31/08/25.
//

#ifndef BUILDER_ASIGNACION_H
#define BUILDER_ASIGNACION_H

#include "ast.h"

// ========== BUILDERS PARA ASIGNACIONES ==========

/**
 * Construye un nodo ASIGNACION_COMPUESTA
 *
 * @param identifier - Nombre de la variable (TOKEN_IDENTIFIER)
 * @param operador_node - Nodo del operador de asignación
 * @param expresion_node - Nodo de la expresión a asignar
 * @param line - Línea del token
 * @param column - Columna del token
 * @return ASTNode* - Nodo ASIGNACION_COMPUESTA creado
 */
ASTNode* build_asignacion_compuesta(const char* identifier, ASTNode* operador_node, ASTNode* expresion_node, int line, int column);

/**
 * Construye un nodo OPERADOR_ASIGNACION
 *
 * @param operador - Operador como string ("+=", "-=", "*=", etc.)
 * @param line - Línea del token
 * @param column - Columna del token
 * @return ASTNode* - Nodo OPERADOR_ASIGNACION creado
 */
ASTNode* build_operador_asignacion(const char* operador, int line, int column);

/**
 * Construye una asignación simple (=)
 *
 * @param identifier - Nombre de la variable
 * @param expresion_node - Expresión a asignar
 * @param line - Línea del token
 * @param column - Columna del token
 * @return ASTNode* - Nodo ASIGNACION_SIMPLE creado
 */
ASTNode* build_asignacion_simple(const char* identifier, ASTNode* expresion_node, int line, int column);

#endif // BUILDER_ASIGNACION_H