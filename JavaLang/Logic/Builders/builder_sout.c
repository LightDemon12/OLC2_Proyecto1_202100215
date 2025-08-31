#include "../../Headers/builder_sout.h"
#include "../../Headers/builder_datos.h"
#include <stdio.h>

ASTNode* build_sout_node(ASTNode* expresion_node, int line, int column) {
    ASTNode* sout_node = create_node("SOUT", line, column);

    if (expresion_node) {
        add_child(sout_node, expresion_node);
        printf("DEBUG SOUT: Nodo SOUT creado con expresión\n");
    } else {
        printf("ADVERTENCIA SOUT: Expresión nula en SOUT\n");
    }

    return sout_node;
}

ASTNode* build_sout_string(const char* string_value, int line, int column) {
    ASTNode* sout_node = create_node("SOUT", line, column);

    if (string_value) {
        ASTNode* string_node = build_string_literal(string_value, line, column);
        add_child(sout_node, string_node);
        printf("DEBUG SOUT: Nodo SOUT creado con string literal: %s\n", string_value);
    } else {
        printf("ADVERTENCIA SOUT: String nulo en SOUT\n");
    }

    return sout_node;
}