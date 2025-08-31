//
// Created by lightdemon on 31/08/25.
//

#include "../../Headers/builder_expresion.h"
#include <stdio.h>
#include <string.h>

ASTNode* build_expresion_binaria(ASTNode* izquierda, const char* operador, ASTNode* derecha, int line, int column) {
    ASTNode* expr_node = create_node("EXPRESION_BINARIA", line, column);
    set_value(expr_node, operador);

    // Agregar expresiones como hijos
    add_child(expr_node, izquierda);
    add_child(expr_node, derecha);

    printf("DEBUG EXPRESION: EXPRESION_BINARIA creada con operador '%s'\n", operador);

    return expr_node;
}

ASTNode* build_expresion_unaria(const char* operador, ASTNode* expresion, int line, int column) {
    ASTNode* expr_node = create_node("EXPRESION_UNARIA", line, column);
    set_value(expr_node, operador);

    // Agregar expresión como hijo
    add_child(expr_node, expresion);

    printf("DEBUG EXPRESION: EXPRESION_UNARIA creada con operador '%s'\n", operador);

    return expr_node;
}

ASTNode* build_expresion_parentesis(ASTNode* expresion, int line, int column) {
    // Los paréntesis solo afectan la precedencia, no crean un nodo nuevo
    // Simplemente devolvemos la expresión original
    printf("DEBUG EXPRESION: Expresión con paréntesis procesada\n");

    return expresion;
}