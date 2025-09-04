//
// Created by lightdemon on 4/09/25.
//

#ifndef PROCESADOR_FUNCIONES_H
#define PROCESADOR_FUNCIONES_H

#include "node_processor.h"
#include "FuncionInfo.h" // Incluir la definición de FuncionInfo
#include "ast.h"
#include "scope_utils.h"

// ===== PROTOTIPOS DE FUNCIONES =====
int procesar_declaracion_funcion(NodeProcessorContext* context, ASTNode* node);
char* procesar_llamada_funcion(NodeProcessorContext* context, ASTNode* node);
FuncionInfo* buscar_funcion(TablaSimbolos* tabla, const char* nombre);
int verificar_compatibilidad_parametros(FuncionInfo* funcion, ASTNode* argumentos_node, NodeProcessorContext* context);
int procesar_return_funcion(NodeProcessorContext* context, ASTNode* return_node, TipoDato tipo_esperado);
TipoDato obtener_tipo_retorno_funcion(ASTNode* funcion_node);
int obtener_numero_parametros(ASTNode* parametros_node);
Simbolo crear_simbolo_parametro(const char* nombre, TipoDato tipo, int posicion, const char* ambito_funcion);

#endif // PROCESADOR_FUNCIONES_H