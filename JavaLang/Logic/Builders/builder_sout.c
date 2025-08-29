//
// Created by lightdemon on 29/08/25.
//


#include "../../Headers/builder_sout.h"
#include "../../Headers/builder_datos.h"
#include <stdio.h>

ASTNode* build_sout_node(const char* string_value, int line, int column) {
    ASTNode* sout_node = create_node("SOUT", line, column);

    // USAR EL BUILDER DE DATOS EN LUGAR DE CÓDIGO DUPLICADO
    ASTNode* string_literal = build_string_literal(string_value, line, column);

    add_child(sout_node, string_literal);
    printf("DEBUG: Nodo SOUT creado usando builder_datos\n");

    return sout_node;
}