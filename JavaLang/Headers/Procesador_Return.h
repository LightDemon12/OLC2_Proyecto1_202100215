//
// Created by lightdemon on 3/09/25.
//

// Asegurar que existe y tiene las declaraciones:

#ifndef JAVALANG_PROCESADOR_RETURN_H
#define JAVALANG_PROCESADOR_RETURN_H

#include "node_processor.h"

// ===== FUNCIONES PRINCIPALES =====
int procesar_return(NodeProcessorContext* context, ASTNode* node);
int procesar_return_con_valor(NodeProcessorContext* context, ASTNode* node);
int procesar_return_vacio(NodeProcessorContext* context, ASTNode* node);

// ===== FUNCIONES AUXILIARES =====
int es_contexto_valido_para_return(NodeProcessorContext* context);

#endif //JAVALANG_PROCESADOR_RETURN_H