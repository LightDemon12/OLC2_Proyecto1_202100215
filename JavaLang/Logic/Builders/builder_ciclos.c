//
// Created by lightdemon on 31/08/25.
//

#include "../../Headers/builder_ciclos.h"
#include "../../Headers/builder_scope.h"
#include <stdio.h>
#include <stdlib.h>

// ========== BUILDERS PARA CICLOS ==========

ASTNode* build_while(ASTNode* condicion_node, ASTNode* instrucciones_node, int line, int column) {
    ASTNode* while_node = create_node("WHILE", line, column);

    // Crear nodo explícito para la condición
    ASTNode* condicion_wrapper = create_node("CONDICION_WHILE", line, column);
    add_child(condicion_wrapper, condicion_node);
    add_child(while_node, condicion_wrapper);

    // Crear nodo explícito para el bloque del while CON SCOPE
    ASTNode* bloque_while = create_node("BLOQUE_WHILE", line, column);
    ASTNode* scope_while = build_scope_bloque(instrucciones_node, "WHILE", line, column);
    add_child(bloque_while, scope_while);
    add_child(while_node, bloque_while);

    printf("DEBUG CICLOS: WHILE creado con CONDICION_WHILE y BLOQUE_WHILE con SCOPE\n");

    return while_node;
}

ASTNode* build_do_while(ASTNode* instrucciones_node, ASTNode* condicion_node, int line, int column) {
    ASTNode* do_while_node = create_node("DO_WHILE", line, column);

    // Crear nodo explícito para el bloque del do CON SCOPE
    ASTNode* bloque_do = create_node("BLOQUE_DO", line, column);
    ASTNode* scope_do = build_scope_bloque(instrucciones_node, "DO", line, column);
    add_child(bloque_do, scope_do);
    add_child(do_while_node, bloque_do);

    // Crear nodo explícito para la condición del while
    ASTNode* condicion_wrapper = create_node("CONDICION_DO_WHILE", line, column);
    add_child(condicion_wrapper, condicion_node);
    add_child(do_while_node, condicion_wrapper);

    printf("DEBUG CICLOS: DO_WHILE creado con BLOQUE_DO con SCOPE y CONDICION_DO_WHILE\n");

    return do_while_node;
}