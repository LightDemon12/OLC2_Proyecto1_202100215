//
// Created by lightdemon on 31/08/25.
//

#ifndef BUILDER_CICLOS_H
#define BUILDER_CICLOS_H

#include "ast.h"

// ========== BUILDERS PARA CICLOS ==========

/**
 * Construye un nodo WHILE con SCOPE
 *
 * @param condicion_node - Nodo de la expresión de condición
 * @param instrucciones_node - Nodo de las instrucciones del ciclo
 * @param line - Línea del token
 * @param column - Columna del token
 * @return ASTNode* - Nodo WHILE creado con SCOPE
 */
ASTNode* build_while(ASTNode* condicion_node, ASTNode* instrucciones_node, int line, int column);

/**
 * Construye un nodo DO_WHILE con SCOPE
 *
 * @param instrucciones_node - Nodo de las instrucciones del ciclo
 * @param condicion_node - Nodo de la expresión de condición
 * @param line - Línea del token
 * @param column - Columna del token
 * @return ASTNode* - Nodo DO_WHILE creado con SCOPE
 */
ASTNode* build_do_while(ASTNode* instrucciones_node, ASTNode* condicion_node, int line, int column);

/**
 * Construye un nodo FOR con SCOPE
 *
 * @param inicializacion_node - Nodo de inicialización del for (puede ser NULL)
 * @param condicion_node - Nodo de la condición del for (puede ser NULL)
 * @param actualizacion_node - Nodo de actualización del for (puede ser NULL)
 * @param instrucciones_node - Nodo de las instrucciones del ciclo
 * @param line - Línea del token
 * @param column - Columna del token
 * @return ASTNode* - Nodo FOR creado con SCOPE
 */
ASTNode* build_for(ASTNode* inicializacion_node, ASTNode* condicion_node, ASTNode* actualizacion_node, ASTNode* instrucciones_node, int line, int column);

/**
 * Construye una inicialización simple de FOR (declaración)
 *
 * @param tipo_node - Nodo del tipo de variable
 * @param identifier - Nombre del identificador
 * @param expresion_node - Nodo de la expresión de inicialización
 * @param line - Línea del token
 * @param column - Columna del token
 * @return ASTNode* - Nodo INICIALIZACION_FOR creado
 */
ASTNode* build_inicializacion_for_declaracion(ASTNode* tipo_node, const char* identifier, ASTNode* expresion_node, int line, int column);

/**
 * Construye una inicialización de FOR con expresión
 *
 * @param expresion_node - Nodo de la expresión
 * @param line - Línea del token
 * @param column - Columna del token
 * @return ASTNode* - Nodo INICIALIZACION_FOR creado
 */
ASTNode* build_inicializacion_for_expresion(ASTNode* expresion_node, int line, int column);

/**
 * Construye una inicialización vacía de FOR
 *
 * @param line - Línea del token
 * @param column - Columna del token
 * @return ASTNode* - Nodo INICIALIZACION_FOR_VACIA creado
 */
ASTNode* build_inicializacion_for_vacia(int line, int column);

/**
 * Construye una actualización de FOR
 *
 * @param expresion_node - Nodo de la expresión de actualización
 * @param line - Línea del token
 * @param column - Columna del token
 * @return ASTNode* - Nodo ACTUALIZACION_FOR creado
 */
ASTNode* build_actualizacion_for(ASTNode* expresion_node, int line, int column);

/**
 * Construye una actualización vacía de FOR
 *
 * @param line - Línea del token
 * @param column - Columna del token
 * @return ASTNode* - Nodo ACTUALIZACION_FOR_VACIA creado
 */
ASTNode* build_actualizacion_for_vacia(int line, int column);

/**
 * Construye una inicialización de FOR con asignación (sin declaración)
 * Para casos como: j += 10, i *= 2, etc. en for(j += 10; ...)
 *
 * @param identifier - Nombre de la variable
 * @param operador_node - Nodo del operador de asignación
 * @param expresion_node - Expresión del valor a asignar
 * @param line - Línea del token
 * @param column - Columna del token
 * @return ASTNode* - Nodo INICIALIZACION_FOR_ASIGNACION creado
 */
ASTNode* build_inicializacion_for_asignacion(const char* identifier, ASTNode* operador_node, ASTNode* expresion_node, int line, int column);
#endif // BUILDER_CICLOS_H