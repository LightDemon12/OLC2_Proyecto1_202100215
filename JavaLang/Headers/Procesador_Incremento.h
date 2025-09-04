//
// Created by lightdemon on 3/09/25.
//

#ifndef PROCESADOR_INCREMENTO_H
#define PROCESADOR_INCREMENTO_H

#include "ast.h"
#include "node_processor.h"

/* FUNCIONES DE PROCESAMIENTO INCREMENTO/DECREMENTO */
char* process_pre_incremento_node(NodeProcessorContext* context, ASTNode* node);
char* process_pre_decremento_node(NodeProcessorContext* context, ASTNode* node);
char* process_post_incremento_node(NodeProcessorContext* context, ASTNode* node);
char* process_post_decremento_node(NodeProcessorContext* context, ASTNode* node);

#endif