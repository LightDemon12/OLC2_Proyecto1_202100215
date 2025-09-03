//
// Created by lightdemon on 2/09/25.
//

#ifndef PROCESADOR_IF_H
#define PROCESADOR_IF_H

#include "ast.h"
#include "Tabla_Simbolos.h"
#include "node_processor.h"

/**
 * Tipos de estructuras IF detectadas en el AST
 */
typedef enum {
    IF_TYPE_SIMPLE,                 // if (condicion) { ... }
    IF_TYPE_SIMPLE_SIN_LLAVES,      // if (condicion) instruccion;
    IF_TYPE_CON_ELSE,               // if (condicion) { ... } else { ... }
    IF_TYPE_CON_ELSE_MIXTO_1,       // if + else if + else
    IF_TYPE_CON_ELSE_IF,            // if + else if (sin else final)
    IF_TYPE_DESCONOCIDO
} TipoIF;

/**
 * Resultado de evaluación de condición IF
 */
typedef enum {
    CONDICION_TRUE,
    CONDICION_FALSE,
    CONDICION_ERROR
} ResultadoCondicion;

/**
 * Procesa un nodo IF principal (todos los tipos)
 * @param context - Contexto del procesador con tabla de símbolos
 * @param node - Nodo AST de tipo IF_*
 * @return 0 si éxito, 1 si error
 */
int process_if_node(NodeProcessorContext* context, ASTNode* node);

/**
 * Procesa IF simple con scope
 * @param context - Contexto del procesador
 * @param node - Nodo IF_SIMPLE
 * @return 0 si éxito, 1 si error
 */
int process_if_simple(NodeProcessorContext* context, ASTNode* node);

/**
 * Procesa IF simple sin llaves (sin scope)
 * @param context - Contexto del procesador
 * @param node - Nodo IF_SIMPLE_SIN_LLAVES
 * @return 0 si éxito, 1 si error
 */
int process_if_simple_sin_llaves(NodeProcessorContext* context, ASTNode* node);

/**
 * Procesa IF con ELSE
 * @param context - Contexto del procesador
 * @param node - Nodo IF_CON_ELSE
 * @return 0 si éxito, 1 si error
 */
int process_if_con_else(NodeProcessorContext* context, ASTNode* node);

/**
 * Procesa IF con ELSE mixto (else if + else)
 * @param context - Contexto del procesador
 * @param node - Nodo IF_CON_ELSE_MIXTO_1
 * @return 0 si éxito, 1 si error
 */
int process_if_con_else_mixto(NodeProcessorContext* context, ASTNode* node);

/**
 * Evalúa una condición IF y determina si es verdadera o falsa
 * @param context - Contexto del procesador
 * @param condicion_node - Nodo CONDICION_IF
 * @return Resultado de la evaluación (TRUE/FALSE/ERROR)
 */
ResultadoCondicion evaluar_condicion_if(NodeProcessorContext* context, ASTNode* condicion_node);

/**
 * Procesa el scope/instrucciones de un bloque IF
 * @param context - Contexto del procesador
 * @param bloque_node - Nodo SCOPE o INSTRUCCION_IF
 * @param nombre_scope - Nombre del scope para debug
 * @param crear_scope - 1 si debe crear scope, 0 si no
 * @return 0 si éxito, 1 si error
 */
int process_bloque_if(NodeProcessorContext* context, ASTNode* bloque_node,
                      const char* nombre_scope, int crear_scope);

/**
 * Determina el tipo de IF desde el string del nodo
 * @param node_type - Tipo del nodo AST
 * @return Tipo de IF correspondiente
 */
TipoIF get_tipo_if(const char* node_type);

/**
 * Valida que una condición sea de tipo boolean
 * @param context - Contexto del procesador
 * @param valor_condicion - Valor string de la condición
 * @param tipo_condicion - Tipo de dato de la condición
 * @return 1 si es válida, 0 si no
 */
int validar_condicion_boolean(NodeProcessorContext* context, const char* valor_condicion, TipoDato tipo_condicion);

#endif // PROCESADOR_IF_H