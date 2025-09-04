//
// Created by lightdemon on 3/09/25.
//

#ifndef JAVALANG_PROCESADOR_FOR_H
#define JAVALANG_PROCESADOR_FOR_H

#include "node_processor.h"
#include "Procesador_If.h"  // Para ResultadoCondicion

char* process_for_node(NodeProcessorContext* context, ASTNode* node);

int procesar_inicializacion_for(NodeProcessorContext* context, ASTNode* inicializacion_node);
ResultadoCondicion evaluar_condicion_for(NodeProcessorContext* context, ASTNode* condicion_node);
int procesar_actualizacion_for(NodeProcessorContext* context, ASTNode* actualizacion_node);
int ejecutar_bloque_for(NodeProcessorContext* context, ASTNode* bloque_node);

#endif //JAVALANG_PROCESADOR_FOR_H