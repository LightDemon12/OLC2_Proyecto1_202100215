//
// Created by lightdemon on 4/09/25.
//

#ifndef PROCESADOR_FUNCIONES_H
#define PROCESADOR_FUNCIONES_H

#include "node_utils.h"
#include "Tabla_Simbolos.h"

// Procesa la declaración de una función y la agrega a la tabla de símbolos
int procesar_declaracion_funcion(NodeProcessorContext* context, ASTNode* node);

// Procesa una llamada a una función, ejecutando su cuerpo
char* procesar_llamada_funcion(NodeProcessorContext* context, ASTNode* node);

#endif // PROCESADOR_FUNCIONES_H