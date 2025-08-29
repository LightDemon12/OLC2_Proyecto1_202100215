//
// Created by lightdemon on 29/08/25.
//

#ifndef BUILDER_DECLARACIONES_H
#define BUILDER_DECLARACIONES_H

#include "ast.h"

// ========== BUILDERS PARA DECLARACIONES DE VARIABLES ==========

/**
 * Construye el nodo DECLARACIONES con una sola variable
 *
 * @param tipo_node - Nodo del tipo (string, int, etc.)
 * @param identifier - Nombre de la variable
 * @param dato_node - Nodo del valor asignado
 * @param line - Línea del token
 * @param column - Columna del token
 * @return ASTNode* - Nodo DECLARACIONES creado
 */
ASTNode* build_declaracion_single(ASTNode* tipo_node, const char* identifier, ASTNode* dato_node, int line, int column);

/**
 * Construye el nodo DECLARACIONES con múltiples variables
 *
 * @param tipo_node - Nodo del tipo (string, int, etc.)
 * @param lista_declaraciones_node - Nodo con la lista de variables
 * @param line - Línea del token
 * @param column - Columna del token
 * @return ASTNode* - Nodo DECLARACIONES creado
 */
ASTNode* build_declaracion_multiple(ASTNode* tipo_node, ASTNode* lista_declaraciones_node, int line, int column);

/**
 * Construye el nodo TIPO
 *
 * @param tipo_token - Tipo como string ("string", "int", etc.)
 * @param line - Línea del token
 * @param column - Columna del token
 * @return ASTNode* - Nodo TIPO creado
 */
ASTNode* build_tipo_node(const char* tipo_token, int line, int column);

/**
 * Construye el nodo DATO (valor de la variable)
 *
 * @param valor - Valor como string
 * @param line - Línea del token
 * @param column - Columna del token
 * @return ASTNode* - Nodo DATO creado
 */
ASTNode* build_dato_node(const char* valor, int line, int column);

/**
 * Construye el nodo LISTA_DECLARACIONES con una sola declaración
 *
 * @param declaracion_node - Nodo de una declaración individual
 * @param line - Línea del token
 * @param column - Columna del token
 * @return ASTNode* - Nodo LISTA_DECLARACIONES creado
 */
ASTNode* build_lista_declaraciones_single(ASTNode* declaracion_node, int line, int column);

/**
 * Agrega una declaración a una lista existente
 *
 * @param lista_existente - Nodo LISTA_DECLARACIONES existente
 * @param nueva_declaracion - Nueva declaración a agregar
 * @return ASTNode* - El mismo nodo LISTA_DECLARACIONES actualizado
 */
ASTNode* build_lista_declaraciones_add(ASTNode* lista_existente, ASTNode* nueva_declaracion);

/**
 * Construye el nodo LISTA_DECLARACION (una variable individual en la lista)
 *
 * @param identifier - Nombre de la variable
 * @param dato_node - Nodo del valor asignado
 * @param line - Línea del token
 * @param column - Columna del token
 * @return ASTNode* - Nodo LISTA_DECLARACION creado
 */
ASTNode* build_lista_declaracion_node(const char* identifier, ASTNode* dato_node, int line, int column);

#endif // BUILDER_DECLARACIONES_H