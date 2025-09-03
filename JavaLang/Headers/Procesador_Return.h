//
// Created by lightdemon on 3/09/25.
//

#ifndef PROCESADOR_RETURN_H
#define PROCESADOR_RETURN_H

#include "ast.h"
#include "node_processor.h"

/* FUNCIONES DE PROCESAMIENTO RETURN */
int procesar_return(NodeProcessorContext* context, ASTNode* node);
int procesar_return_con_valor(NodeProcessorContext* context, ASTNode* node);
int procesar_return_vacio(NodeProcessorContext* context, ASTNode* node);

#endif