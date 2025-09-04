//
// Created by lightdemon on 3/09/25.
//

//
// Created by lightdemon on 3/09/25.
//

#ifndef PROCESADOR_WHILE_H
#define PROCESADOR_WHILE_H

#include "ast.h"
#include "node_processor.h"
#include "../../Headers/Procesador_If.h"


/* FUNCIONES DE PROCESAMIENTO WHILE */
char* process_while_node(NodeProcessorContext* context, ASTNode* node);
ResultadoCondicion evaluar_condicion_while(NodeProcessorContext* context, ASTNode* condicion_node);
int ejecutar_bloque_while(NodeProcessorContext* context, ASTNode* bloque_node);

#endif //PROCESADOR_WHILE_H