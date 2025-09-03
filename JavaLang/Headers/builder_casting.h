//
// Created by lightdemon on 2/09/25.
//

#ifndef BUILDER_CASTING_H
#define BUILDER_CASTING_H

#include "ast.h"

// ========== BUILDER DE CASTING ==========

/**
 * Construye un nodo de casting explícito
 * @param tipo_destino - Nodo con el tipo al que se quiere convertir
 * @param expresion - Nodo con la expresión a convertir
 * @param line - Línea del casting
 * @param column - Columna del casting
 * @return Nodo AST de tipo CAST
 */
ASTNode* build_cast_node(ASTNode* tipo_destino, ASTNode* expresion, int line, int column);

/**
 * Construye un nodo de casting implícito (para promociones automáticas)
 * @param tipo_origen - Tipo original
 * @param tipo_destino - Tipo de destino
 * @param expresion - Expresión a convertir
 * @param line - Línea
 * @param column - Columna
 * @return Nodo AST de tipo CAST_IMPLICIT
 */
ASTNode* build_cast_implicit_node(const char* tipo_origen, const char* tipo_destino,
                                  ASTNode* expresion, int line, int column);

#endif // BUILDER_CASTING_H