//
// Created by lightdemon on 2/09/25.
//

#ifndef PROCESADOR_MODULO_H
#define PROCESADOR_MODULO_H

#include "node_processor.h"
#include "ast.h"
#include "Tabla_Simbolos.h"

/**
 * Verifica si dos tipos son compatibles para operación módulo
 * @param tipo1 - Primer tipo
 * @param tipo2 - Segundo tipo
 * @return 1 si son compatibles, 0 si no
 */
int tipos_compatibles_modulo(TipoDato tipo1, TipoDato tipo2);

/**
 * Determina el tipo resultante de una operación módulo
 * @param tipo1 - Primer tipo
 * @param tipo2 - Segundo tipo
 * @return Tipo resultante
 */
TipoDato tipo_resultado_modulo(TipoDato tipo1, TipoDato tipo2);

/**
 * Procesa un nodo de módulo
 * @param context - Contexto del procesador
 * @param node - Nodo de módulo a procesar
 * @return String con el resultado o NULL si hay error
 */
char* process_modulo_node(NodeProcessorContext* context, ASTNode* node);

/**
 * Evalúa la operación módulo entre dos números
 * @param left - Operando izquierdo
 * @param right - Operando derecho
 * @param tipo_resultado - Tipo del resultado para determinar si usar entero o flotante
 * @return Resultado de la operación
 */
double evaluar_modulo(double left, double right, TipoDato tipo_resultado);

#endif // PROCESADOR_MODULO_H