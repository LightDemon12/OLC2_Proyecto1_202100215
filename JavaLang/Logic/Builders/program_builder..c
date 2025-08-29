//
// Created by lightdemon on 29/08/25.
//

#include "../../Headers/builder_program.h"
#include <stdio.h>

ASTNode* build_program_node(ASTNode* bloque_main, int line, int column) {
    ASTNode* program_node = create_node("PROGRAM", line, column);
    add_child(program_node, bloque_main);
    printf("DEBUG: Nodo PROGRAM creado\n");
    return program_node;
}