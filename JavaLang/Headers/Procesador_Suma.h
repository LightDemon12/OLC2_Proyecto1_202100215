//
// Created by lightdemon on 2/09/25.
//

#ifndef PROCESADOR_SUMA_H
#define PROCESADOR_SUMA_H

#include "node_processor.h"
#include "Tabla_Simbolos.h"
#include "globals.h"
#include "ast.h"

// Función principal
char* process_suma_node(NodeProcessorContext* context, ASTNode* node);

// Funciones auxiliares de análisis semántico mejoradas
TipoDato obtener_tipo_desde_nodo(ASTNode* node, NodeProcessorContext* context);  // ← ACTUALIZADA
char* obtener_valor_desde_nodo(ASTNode* node, NodeProcessorContext* context);    // ← NUEVA
int tipos_compatibles_suma(TipoDato tipo1, TipoDato tipo2);
TipoDato tipo_resultado_suma(TipoDato tipo1, TipoDato tipo2);
double convertir_a_numero(const char* valor, TipoDato tipo);

// Función matemática
double evaluar_suma(double left, double right);

#endif // PROCESADOR_SUMA_H