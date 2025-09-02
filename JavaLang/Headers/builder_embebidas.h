//
// Created by lightdemon on 1/09/25.
//

#ifndef BUILDER_EMBEBIDAS_H
#define BUILDER_EMBEBIDAS_H

#include "ast.h"

// ========== BUILDERS PARA FUNCIONES EMBEBIDAS ==========

/**
 * Construye un nodo PARSEINT_EMBEBIDA simple
 * Para casos como: Integer.parseInt("123")
 */
ASTNode* build_parseint_embebida(ASTNode* expresion_node, int line, int column);

/**
 * Construye un nodo PARSEINT_EMBEBIDA con radix/base
 * Para casos como: Integer.parseInt("1011", 2)
 */
ASTNode* build_parseint_embebida_radix(ASTNode* expresion_node, ASTNode* radix_node, int line, int column);

/**
 * Construye un nodo PARSEFLOAT_EMBEBIDA
 * Para casos como: Float.parseFloat("3.14")
 */
ASTNode* build_parsefloat_embebida(ASTNode* expresion_node, int line, int column);

/**
 * Construye un nodo PARSEDOUBLE_EMBEBIDA
 * Para casos como: Double.parseDouble("3.14159")
 */
ASTNode* build_parsedouble_embebida(ASTNode* expresion_node, int line, int column);

/**
 * Construye un nodo VALUEOF_EMBEBIDA
 * Para casos como: String.valueOf(123), String.valueOf(true)
 */
ASTNode* build_valueof_embebida(ASTNode* expresion_node, int line, int column);

/**
 * Construye un nodo INDEXOF_EMBEBIDA
 * Para casos como: Arrays.indexOf(array, elemento)
 */
ASTNode* build_indexof_embebida(ASTNode* array_expresion_node, ASTNode* elemento_expresion_node, int line, int column);

/**
 * Construye un nodo LENGTH_EMBEBIDA
 * Para casos como: array.length, string.length
 */
ASTNode* build_length_embebida(ASTNode* expresion_node, int line, int column);

/**
 * Construye un nodo ADD_EMBEBIDA
 * Para casos como: lista.add(elemento)
 */
ASTNode* build_add_embebida(ASTNode* lista_expresion_node, ASTNode* elemento_expresion_node, int line, int column);

/**
 * Construye un nodo JOIN_EMBEBIDA con variable de array
 * Para casos como: String.join(",", array)
 */
ASTNode* build_join_embebida(ASTNode* separador_expresion_node, ASTNode* array_node, int line, int column);

/**
 * Construye un nodo JOIN_EMBEBIDA con múltiples argumentos
 * Para casos como: String.join(",", "a", "b", "c")
 */
ASTNode* build_join_embebida_multiple(ASTNode* separador_expresion_node, ASTNode* lista_expresiones_node, int line, int column);

/**
 * Construye un nodo EQUALS_EMBEBIDA
 * Para casos como: string1.equals(string2), objeto1.equals(objeto2)
 */
ASTNode* build_equals_embebida(ASTNode* objeto1_expresion_node, ASTNode* objeto2_expresion_node, int line, int column);

#endif // BUILDER_EMBEBIDAS_H