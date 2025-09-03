#ifndef PROCESADOR_DECLARACIONES_H
#define PROCESADOR_DECLARACIONES_H

#include "node_processor.h"
#include "Tabla_Simbolos.h"
#include "ast.h"

// Funciones principales
int process_declaracion_node(NodeProcessorContext* context, ASTNode* node);
int process_declaracion_con_inicializacion(NodeProcessorContext* context, TipoDato tipo,
                                          ASTNode* id_nodo, ASTNode* valor_nodo, ASTNode* parent);
int process_declaracion_sin_inicializacion(NodeProcessorContext* context, TipoDato tipo,
                                          ASTNode* id_nodo, ASTNode* parent);
int process_declaracion_multiple(NodeProcessorContext* context, TipoDato tipo,
                                ASTNode* lista_nodo, ASTNode* parent);

// Funciones auxiliares de análisis semántico
int tipos_compatibles_asignacion(TipoDato tipo_variable, TipoDato tipo_valor);
char* extract_dato_value(ASTNode* node);

// ===== DECLARACIONES EXTERNAS DE FUNCIONES DEL PROCESADOR SUMA =====
// Estas funciones están implementadas en Procesador_Suma.c
extern TipoDato obtener_tipo_desde_nodo(ASTNode* node, NodeProcessorContext* context);
extern char* obtener_valor_desde_nodo(ASTNode* node, NodeProcessorContext* context);



#endif // PROCESADOR_DECLARACIONES_H