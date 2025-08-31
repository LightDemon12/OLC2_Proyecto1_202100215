//
// Created by lightdemon on 31/08/25.
//

#include "../../Headers/builder_sentencias.h"
#include <stdio.h>
#include <stdlib.h>

// ========== BUILDERS PARA SENTENCIAS DE CONTROL ==========

ASTNode* build_break(int line, int column) {
    ASTNode* break_node = create_node("BREAK", line, column);

    printf("DEBUG SENTENCIAS: BREAK creado\n");

    return break_node;
}

ASTNode* build_continue(int line, int column) {
    ASTNode* continue_node = create_node("CONTINUE", line, column);

    printf("DEBUG SENTENCIAS: CONTINUE creado\n");

    return continue_node;
}

ASTNode* build_return_con_valor(ASTNode* expresion_node, int line, int column) {
    ASTNode* return_node = create_node("RETURN_CON_VALOR", line, column);

    // Crear nodo explícito para el valor de retorno
    ASTNode* valor_retorno = create_node("VALOR_RETORNO", line, column);
    add_child(valor_retorno, expresion_node);
    add_child(return_node, valor_retorno);

    printf("DEBUG SENTENCIAS: RETURN_CON_VALOR creado con expresión\n");

    return return_node;
}

ASTNode* build_return_vacio(int line, int column) {
    ASTNode* return_node = create_node("RETURN_VACIO", line, column);

    printf("DEBUG SENTENCIAS: RETURN_VACIO creado\n");

    return return_node;
}