//
// Created by lightdemon on 29/08/25.
//

#include "../../Headers/builder_bloque_main.h"
#include <stdio.h>

ASTNode* build_bloque_main_node(ASTNode* instrucciones, int line, int column) {
    ASTNode* bloque_main_node = create_node("bloque_main", line, column);
    add_child(bloque_main_node, instrucciones);
    printf("DEBUG: Nodo bloque_main creado\n");
    return bloque_main_node;
}