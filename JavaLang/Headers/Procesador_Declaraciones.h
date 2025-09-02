//
// Created by lightdemon on 2/09/25.
//

#ifndef PROCESADOR_DECLARACIONES_H
#define PROCESADOR_DECLARACIONES_H

#include "node_processor.h"
#include "Tabla_Simbolos.h"
#include "ast.h"

/**
 * Función principal del procesador de declaraciones
 * Maneja los 3 tipos de declaraciones:
 * - DECLARACION_CON_INICIALIZACION: int numero = 42;
 * - DECLARACION_SIN_INICIALIZACION: int contador;
 * - DECLARACION_MULTIPLE: int a = 1, b = 2, c = 3;
 */
int process_declaracion_node(NodeProcessorContext* context, ASTNode* node);

/**
 * Funciones auxiliares para cada tipo específico
 */
int process_declaracion_con_inicializacion(NodeProcessorContext* context, TipoDato tipo,
                                          ASTNode* id_nodo, ASTNode* valor_nodo, ASTNode* parent);

int process_declaracion_sin_inicializacion(NodeProcessorContext* context, TipoDato tipo,
                                          ASTNode* id_nodo, ASTNode* parent);

int process_declaracion_multiple(NodeProcessorContext* context, TipoDato tipo,
                                ASTNode* lista_nodo, ASTNode* parent);

/**
 * Función utilitaria para extraer valores de expresiones
 */
char* extract_dato_value(ASTNode* node);

#endif // PROCESADOR_DECLARACIONES_H