//
// Created by lightdemon on 3/09/25.
//

#ifndef PROCESADOR_ASIGNACIONES_COMPUESTAS_H
#define PROCESADOR_ASIGNACIONES_COMPUESTAS_H

#include "ast.h"
#include "node_processor.h"

/* FUNCIONES DE PROCESAMIENTO */
int procesar_asignacion_compuesta(NodeProcessorContext* context, ASTNode* node);
int realizar_operacion_compuesta_int(int valor_actual, char* operador, int valor_expresion);

#endif