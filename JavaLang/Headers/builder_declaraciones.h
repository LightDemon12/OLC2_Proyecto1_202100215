#ifndef BUILDER_DECLARACIONES_H
#define BUILDER_DECLARACIONES_H

#include "ast.h"

/**
 * Construye una declaración con inicialización
 * Ejemplo: int x = 5;
 */
ASTNode* build_declaracion_single(ASTNode* tipo_node, const char* identifier, ASTNode* expresion_node, int line, int column);

/**
 * Construye una declaración múltiple con inicializaciones
 * Ejemplo: int x = 5, y = 10, z = 15;
 */
ASTNode* build_declaracion_multiple(ASTNode* tipo_node, ASTNode* lista_declaraciones_node, int line, int column);

/**
 * Construye una declaración sin inicialización
 * Ejemplo: int x;
 */
ASTNode* build_declaracion_sin_inicializacion(ASTNode* tipo_node, const char* identifier, int line, int column);

/**
 * Construye una lista de declaraciones (para declaraciones múltiples)
 */
ASTNode* build_lista_declaraciones_single(ASTNode* declaracion_node, int line, int column);

/**
 * Agrega una declaración a una lista existente
 */
ASTNode* build_lista_declaraciones_add(ASTNode* lista_existente, ASTNode* nueva_declaracion);

/**
 * Construye un nodo de declaración individual en una lista
 */
ASTNode* build_lista_declaracion_node(const char* identifier, ASTNode* expresion_node, int line, int column);

#endif // BUILDER_DECLARACIONES_H