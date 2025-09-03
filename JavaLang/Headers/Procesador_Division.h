//
// Created by lightdemon on 2/09/25.
//

#ifndef PROCESADOR_DIVISION_H
#define PROCESADOR_DIVISION_H

#include "node_processor.h"
#include "Tabla_Simbolos.h"
#include "ast.h"

// Funciones principales del procesador de división
char* process_division_node(NodeProcessorContext* context, ASTNode* node);

// Funciones auxiliares para análisis semántico de división
int tipos_compatibles_division(TipoDato tipo1, TipoDato tipo2);
TipoDato tipo_resultado_division(TipoDato tipo1, TipoDato tipo2);
double evaluar_division(double left, double right);
int es_division_por_cero(double divisor, TipoDato tipo_divisor);

// Funciones compartidas (usando node_utils)
extern TipoDato obtener_tipo_desde_nodo(ASTNode* node, NodeProcessorContext* context);
extern char* obtener_valor_desde_nodo(ASTNode* node, NodeProcessorContext* context);
extern double convertir_a_numero(const char* valor, TipoDato tipo);
extern char* convertir_numero_a_string(double valor, TipoDato tipo);
extern TipoDato promocionar_tipos(TipoDato tipo1, TipoDato tipo2);
extern int tipos_compatibles_aritmetica(TipoDato tipo1, TipoDato tipo2);

#endif // PROCESADOR_DIVISION_H