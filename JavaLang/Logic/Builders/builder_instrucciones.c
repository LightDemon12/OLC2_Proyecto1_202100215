//
// Created by lightdemon on 29/08/25.
//

#include "../../Headers/builder_instrucciones.h"
#include <stdio.h>

ASTNode* build_instrucciones_single(ASTNode* instruccion, int line, int column) {
    ASTNode* instrucciones_node = create_node("INSTRUCCIONES", line, column);
    add_child(instrucciones_node, instruccion);
    printf("DEBUG: Nodo INSTRUCCIONES creado con 1 instrucción\n");
    return instrucciones_node;
}

ASTNode* build_instrucciones_add(ASTNode* instrucciones, ASTNode* instruccion) {
    add_child(instrucciones, instruccion);
    printf("DEBUG: Instrucción agregada a INSTRUCCIONES (total: %d)\n", instrucciones->child_count);
    return instrucciones;
}