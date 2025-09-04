//
// Created by lightdemon on 3/09/25.
//

#ifndef PROCESADOR_MULTIDIMENSIONAL_H
#define PROCESADOR_MULTIDIMENSIONAL_H

#include "node_processor.h"
#include "Tabla_Simbolos.h"

// Procesa declaración de array multidimensional con new (ej. int[][] matriz = new int[3][4];)
int process_array_multidimensional_new(NodeProcessorContext* context, ASTNode* node);

// Procesa declaración de array multidimensional con inicialización (ej. int[][] matriz = {{1,2},{3,4}};)
int process_array_multidimensional_inicializado(NodeProcessorContext* context, ASTNode* node);

// Función auxiliar para parsear BRACE_BLOCK recursivamente y extraer valores
char*** parse_brace_block(ASTNode* brace_block, int* filas, int* columnas, TipoDato tipo);
int process_array_asignacion_elemento(NodeProcessorContext* context, ASTNode* node);

#endif // PROCESADOR_MULTIDIMENSIONAL_H