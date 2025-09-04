//
// Created by lightdemon on 3/09/25.
//
//
// Created by lightdemon on 3/09/25.
//
#ifndef JAVALANG_PROCESADOR_DO_WHILE_H
#define JAVALANG_PROCESADOR_DO_WHILE_H

#include "node_processor.h"
#include "Procesador_If.h"  // Para ResultadoCondicion

// ===== FUNCIONES PRINCIPALES =====
char* process_do_while_node(NodeProcessorContext* context, ASTNode* node);

// ===== FUNCIONES AUXILIARES =====
ResultadoCondicion evaluar_condicion_do_while(NodeProcessorContext* context, ASTNode* condicion_node);
int ejecutar_bloque_do_while(NodeProcessorContext* context, ASTNode* bloque_node);

#endif //JAVALANG_PROCESADOR_DO_WHILE_H