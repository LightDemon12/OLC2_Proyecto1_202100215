//
// Created by lightdemon on 2/09/25.
//

#ifndef PROCESADOR_MULTIPLICACION_H
#define PROCESADOR_MULTIPLICACION_H

#include "node_processor.h"
#include "Tabla_Simbolos.h"
#include "ast.h"

// Funciones principales del procesador de multiplicación
char* process_multiplicacion_node(NodeProcessorContext* context, ASTNode* node);

// Funciones auxiliares para análisis semántico de multiplicación
int tipos_compatibles_multiplicacion(TipoDato tipo1, TipoDato tipo2);
TipoDato tipo_resultado_multiplicacion(TipoDato tipo1, TipoDato tipo2);
double evaluar_multiplicacion(double left, double right);

// Funciones compartidas (usando node_utils)
extern TipoDato obtener_tipo_desde_nodo(ASTNode* node, NodeProcessorContext* context);
extern char* obtener_valor_desde_nodo(ASTNode* node, NodeProcessorContext* context);
extern double convertir_a_numero(const char* valor, TipoDato tipo);
extern char* convertir_numero_a_string(double valor, TipoDato tipo);
extern TipoDato promocionar_tipos(TipoDato tipo1, TipoDato tipo2);
extern int tipos_compatibles_aritmetica(TipoDato tipo1, TipoDato tipo2);

#endif // PROCESADOR_MULTIPLICACION_H