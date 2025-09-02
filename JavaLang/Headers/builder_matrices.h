//
// Created by lightdemon on 1/09/25.
//

#ifndef BUILDER_MATRICES_H
#define BUILDER_MATRICES_H

#include "ast.h"

// ========== BUILDERS PARA MATRICES (ARRAYS 2D) ==========

/**
 * Construye un nodo MATRIZ_NEW para declaración con new
 * Para casos como: int[][] matriz = new int[3][4];
 *
 * @param tipo_matriz_node - Nodo del tipo de la matriz (ej: int)
 * @param nombre_matriz - Nombre de la variable de la matriz
 * @param tipo_new_node - Nodo del tipo en el new (ej: int)
 * @param filas_node - Expresión del número de filas
 * @param columnas_node - Expresión del número de columnas
 * @param line - Línea del token
 * @param column - Columna del token
 * @return ASTNode* - Nodo MATRIZ_NEW creado
 */
ASTNode* build_matriz_new(ASTNode* tipo_matriz_node, const char* nombre_matriz, ASTNode* tipo_new_node, ASTNode* filas_node, ASTNode* columnas_node, int line, int column);

/**
 * Construye un nodo MATRIZ_INICIALIZADA para declaración con valores
 * Para casos como: int[][] matriz = {{1, 2}, {3, 4}};
 *
 * @param tipo_matriz_node - Nodo del tipo de la matriz (ej: int)
 * @param nombre_matriz - Nombre de la variable de la matriz
 * @param contenido_node - Nodo del contenido de la matriz
 * @param line - Línea del token
 * @param column - Columna del token
 * @return ASTNode* - Nodo MATRIZ_INICIALIZADA creado
 */
ASTNode* build_matriz_inicializada(ASTNode* tipo_matriz_node, const char* nombre_matriz, ASTNode* contenido_node, int line, int column);

/**
 * Construye un nodo CONTENIDO_MATRIZ con una sola fila
 *
 * @param fila_node - Primera fila de la matriz
 * @param line - Línea del token
 * @param column - Columna del token
 * @return ASTNode* - Nodo CONTENIDO_MATRIZ creado
 */
ASTNode* build_contenido_matriz_single(ASTNode* fila_node, int line, int column);

/**
 * Agrega una fila a un nodo CONTENIDO_MATRIZ existente
 *
 * @param contenido_node - Nodo CONTENIDO_MATRIZ existente
 * @param fila_node - Nueva fila a agregar
 * @return ASTNode* - Nodo CONTENIDO_MATRIZ actualizado
 */
ASTNode* build_contenido_matriz_add(ASTNode* contenido_node, ASTNode* fila_node);

/**
 * Construye un nodo FILA_MATRIZ
 *
 * @param lista_expresiones_node - Nodo con las expresiones de la fila
 * @param line - Línea del token
 * @param column - Columna del token
 * @return ASTNode* - Nodo FILA_MATRIZ creado
 */
ASTNode* build_fila_matriz(ASTNode* lista_expresiones_node, int line, int column);

/**
 * Construye un nodo LISTA_EXPRESIONES con una sola expresión
 *
 * @param expresion_node - Primera expresión de la lista
 * @param line - Línea del token
 * @param column - Columna del token
 * @return ASTNode* - Nodo LISTA_EXPRESIONES creado
 */
ASTNode* build_lista_expresiones_single(ASTNode* expresion_node, int line, int column);

/**
 * Agrega una expresión a un nodo LISTA_EXPRESIONES existente
 *
 * @param lista_node - Nodo LISTA_EXPRESIONES existente
 * @param expresion_node - Nueva expresión a agregar
 * @return ASTNode* - Nodo LISTA_EXPRESIONES actualizado
 */
ASTNode* build_lista_expresiones_add(ASTNode* lista_node, ASTNode* expresion_node);

#endif // BUILDER_MATRICES_H