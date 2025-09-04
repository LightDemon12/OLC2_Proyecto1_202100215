//
// Created by lightdemon on 3/09/25.
//

#ifndef PROCESADOR_VECTORES_H
#define PROCESADOR_VECTORES_H

#include "node_processor.h"
#include "Tabla_Simbolos.h"

// Procesa nodos de declaración de vectores (arreglos unidimensionales)
int process_vector_node(NodeProcessorContext* context, ASTNode* node);

// Funciones de acceso y escritura para todos los tipos
void asignar_vector(NodeProcessorContext* context, Simbolo* simbolo, int indice, void* valor);

int leer_vector_int(Simbolo* simbolo, int indice);
long leer_vector_long(Simbolo* simbolo, int indice);
double leer_vector_double(Simbolo* simbolo, int indice);
float leer_vector_float(Simbolo* simbolo, int indice);
char leer_vector_char(Simbolo* simbolo, int indice);
char* leer_vector_str(Simbolo* simbolo, int indice);

void escribir_vector_int(Simbolo* simbolo, int indice, int valor);
void escribir_vector_long(Simbolo* simbolo, int indice, long valor);
void escribir_vector_double(Simbolo* simbolo, int indice, double valor);
void escribir_vector_float(Simbolo* simbolo, int indice, float valor);
void escribir_vector_char(Simbolo* simbolo, int indice, char valor);
void escribir_vector_str(Simbolo* simbolo, int indice, const char* valor);

// Procesa el acceso a un vector unidimensional (acceso tipo ARRAY_ACCESO_MULTIDIMENSIONAL)
int procesar_acceso_vector(NodeProcessorContext* context, ASTNode* acceso_node);

// Procesa asignaciones compuestas a arrays (tipo ASIGNACION_COMPUESTA_ARRAY_1D)
int procesar_asignacion_compuesta_array(NodeProcessorContext* context, ASTNode* node);

#endif // PROCESADOR_VECTORES_H