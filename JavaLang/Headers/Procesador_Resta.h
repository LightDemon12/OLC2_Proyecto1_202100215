//
// Created by lightdemon on 2/09/25.
//

#ifndef PROCESADOR_RESTA_H
#define PROCESADOR_RESTA_H

#include "node_processor.h"
#include "Tabla_Simbolos.h"
#include "ast.h"

// Funciones principales del procesador de resta
char* process_resta_node(NodeProcessorContext* context, ASTNode* node);

// Funciones auxiliares para análisis semántico de resta
int tipos_compatibles_resta(TipoDato tipo1, TipoDato tipo2);
TipoDato tipo_resultado_resta(TipoDato tipo1, TipoDato tipo2);
double evaluar_resta(double left, double right);

// Funciones compartidas (declaradas como externas)
extern TipoDato obtener_tipo_desde_nodo(ASTNode* node, NodeProcessorContext* context);
extern char* obtener_valor_desde_nodo(ASTNode* node, NodeProcessorContext* context);
extern double convertir_a_numero(const char* valor, TipoDato tipo);

#endif // PROCESADOR_RESTA_H