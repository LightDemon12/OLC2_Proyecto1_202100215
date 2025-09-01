//
// Created by lightdemon on 31/08/25.
//

#include "../../Headers/builder_expresion.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ========== BUILDERS PARA EXPRESIONES ==========

ASTNode* build_expresion_binaria(ASTNode* izquierda, const char* operador, ASTNode* derecha, int line, int column) {
    ASTNode* expr_node = create_node("EXPRESION_BINARIA", line, column);
    set_value(expr_node, operador);

    add_child(expr_node, izquierda);
    add_child(expr_node, derecha);

    printf("DEBUG EXPRESION: EXPRESION_BINARIA creada - operador:%s\n", operador ? operador : "null");

    return expr_node;
}

ASTNode* build_expresion_unaria(const char* operador, ASTNode* expresion, int line, int column) {
    ASTNode* expr_node = create_node("EXPRESION_UNARIA", line, column);
    set_value(expr_node, operador);

    add_child(expr_node, expresion);

    printf("DEBUG EXPRESION: EXPRESION_UNARIA creada - operador:%s\n", operador ? operador : "null");

    return expr_node;
}

ASTNode* build_expresion_postfijo(ASTNode* expresion, const char* operador, int line, int column) {
    ASTNode* expr_node = create_node("EXPRESION_POSTFIJO", line, column);
    set_value(expr_node, operador);

    add_child(expr_node, expresion);

    printf("DEBUG EXPRESION: EXPRESION_POSTFIJO creada - operador:%s\n", operador ? operador : "null");

    return expr_node;
}

ASTNode* build_expresion_acceso(ASTNode* objeto_node, ASTNode* acceso_node, int line, int column) {
    ASTNode* expr_node = create_node("EXPRESION_ACCESO", line, column);
    set_value(expr_node, ".");

    add_child(expr_node, objeto_node);
    add_child(expr_node, acceso_node);

    printf("DEBUG EXPRESION: EXPRESION_ACCESO creada\n");

    return expr_node;
}

ASTNode* build_expresion_parentesis(ASTNode* expresion, int line, int column) {
    // Los paréntesis solo afectan la precedencia, devolvemos la expresión tal como está
    printf("DEBUG EXPRESION: EXPRESION_PARENTESIS procesada\n");

    return expresion;
}