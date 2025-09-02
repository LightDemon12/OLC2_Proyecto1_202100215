//
// Created by lightdemon on 01/09/25.
//

#include "../../Headers/builder_if.h"
#include "../../Headers/builder_scope.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// ========== BUILDERS PARA IF CON LLAVES ==========

ASTNode* build_if_simple(ASTNode* condicion_node, ASTNode* instrucciones_node, int line, int column) {
    ASTNode* if_node = create_node("IF_SIMPLE", line, column);

    // Crear wrapper para la condición
    ASTNode* condicion_wrapper = create_node("CONDICION_IF", line, column);
    add_child(condicion_wrapper, condicion_node);
    add_child(if_node, condicion_wrapper);

    // Crear scope para las instrucciones del if
    ASTNode* scope_if = build_scope(instrucciones_node, "IF", line, column);
    add_child(if_node, scope_if);

    printf("DEBUG IF: IF_SIMPLE creado con llaves\n");
    return if_node;
}

ASTNode* build_if_con_else(ASTNode* condicion_node, ASTNode* instrucciones_if_node, ASTNode* instrucciones_else_node, int line, int column) {
    ASTNode* if_else_node = create_node("IF_CON_ELSE", line, column);

    // Condición
    ASTNode* condicion_wrapper = create_node("CONDICION_IF", line, column);
    add_child(condicion_wrapper, condicion_node);
    add_child(if_else_node, condicion_wrapper);

    // Bloque IF con scope
    ASTNode* scope_if = build_scope(instrucciones_if_node, "IF", line, column);
    add_child(if_else_node, scope_if);

    // Bloque ELSE con scope
    ASTNode* scope_else = build_scope(instrucciones_else_node, "ELSE", line, column);
    add_child(if_else_node, scope_else);

    printf("DEBUG IF: IF_CON_ELSE creado con llaves\n");
    return if_else_node;
}

ASTNode* build_if_con_else_if(ASTNode* condicion_node, ASTNode* instrucciones_if_node, ASTNode* lista_else_if_node, ASTNode* instrucciones_else_node, int line, int column) {
    ASTNode* if_else_if_node = create_node("IF_CON_ELSE_IF", line, column);

    // Condición
    ASTNode* condicion_wrapper = create_node("CONDICION_IF", line, column);
    add_child(condicion_wrapper, condicion_node);
    add_child(if_else_if_node, condicion_wrapper);

    // Bloque IF con scope
    ASTNode* scope_if = build_scope(instrucciones_if_node, "IF", line, column);
    add_child(if_else_if_node, scope_if);

    // Lista de ELSE IF
    add_child(if_else_if_node, lista_else_if_node);

    // Bloque ELSE con scope
    ASTNode* scope_else = build_scope(instrucciones_else_node, "ELSE", line, column);
    add_child(if_else_if_node, scope_else);

    printf("DEBUG IF: IF_CON_ELSE_IF creado con llaves\n");
    return if_else_if_node;
}

// ========== BUILDERS PARA IF SIN LLAVES ==========

ASTNode* build_if_simple_sin_llaves(ASTNode* condicion_node, ASTNode* instruccion_node, int line, int column) {
    ASTNode* if_node = create_node("IF_SIMPLE_SIN_LLAVES", line, column);

    // Crear wrapper para la condición
    ASTNode* condicion_wrapper = create_node("CONDICION_IF", line, column);
    add_child(condicion_wrapper, condicion_node);
    add_child(if_node, condicion_wrapper);

    // Instrucción única (sin scope adicional)
    ASTNode* instruccion_wrapper = create_node("INSTRUCCION_IF", line, column);
    add_child(instruccion_wrapper, instruccion_node);
    add_child(if_node, instruccion_wrapper);

    printf("DEBUG IF: IF_SIMPLE_SIN_LLAVES creado\n");
    return if_node;
}

ASTNode* build_if_con_else_sin_llaves(ASTNode* condicion_node, ASTNode* instruccion_if_node, ASTNode* instruccion_else_node, int line, int column) {
    ASTNode* if_else_node = create_node("IF_CON_ELSE_SIN_LLAVES", line, column);

    // Condición
    ASTNode* condicion_wrapper = create_node("CONDICION_IF", line, column);
    add_child(condicion_wrapper, condicion_node);
    add_child(if_else_node, condicion_wrapper);

    // Instrucción IF
    ASTNode* instruccion_if_wrapper = create_node("INSTRUCCION_IF", line, column);
    add_child(instruccion_if_wrapper, instruccion_if_node);
    add_child(if_else_node, instruccion_if_wrapper);

    // Instrucción ELSE
    ASTNode* instruccion_else_wrapper = create_node("INSTRUCCION_ELSE", line, column);
    add_child(instruccion_else_wrapper, instruccion_else_node);
    add_child(if_else_node, instruccion_else_wrapper);

    printf("DEBUG IF: IF_CON_ELSE_SIN_LLAVES creado\n");
    return if_else_node;
}

ASTNode* build_if_con_else_mixto_1(ASTNode* condicion_node, ASTNode* instrucciones_if_node, ASTNode* instruccion_else_node, int line, int column) {
    ASTNode* if_else_node = create_node("IF_CON_ELSE_MIXTO_1", line, column);

    // Condición
    ASTNode* condicion_wrapper = create_node("CONDICION_IF", line, column);
    add_child(condicion_wrapper, condicion_node);
    add_child(if_else_node, condicion_wrapper);

    // Bloque IF con scope (múltiples instrucciones)
    ASTNode* scope_if = build_scope(instrucciones_if_node, "IF", line, column);
    add_child(if_else_node, scope_if);

    // Instrucción ELSE única
    ASTNode* instruccion_else_wrapper = create_node("INSTRUCCION_ELSE", line, column);
    add_child(instruccion_else_wrapper, instruccion_else_node);
    add_child(if_else_node, instruccion_else_wrapper);

    printf("DEBUG IF: IF_CON_ELSE_MIXTO_1 creado (IF con llaves, ELSE sin llaves)\n");
    return if_else_node;
}

ASTNode* build_if_con_else_mixto_2(ASTNode* condicion_node, ASTNode* instruccion_if_node, ASTNode* instrucciones_else_node, int line, int column) {
    ASTNode* if_else_node = create_node("IF_CON_ELSE_MIXTO_2", line, column);

    // Condición
    ASTNode* condicion_wrapper = create_node("CONDICION_IF", line, column);
    add_child(condicion_wrapper, condicion_node);
    add_child(if_else_node, condicion_wrapper);

    // Instrucción IF única
    ASTNode* instruccion_if_wrapper = create_node("INSTRUCCION_IF", line, column);
    add_child(instruccion_if_wrapper, instruccion_if_node);
    add_child(if_else_node, instruccion_if_wrapper);

    // Bloque ELSE con scope (múltiples instrucciones)
    ASTNode* scope_else = build_scope(instrucciones_else_node, "ELSE", line, column);
    add_child(if_else_node, scope_else);

    printf("DEBUG IF: IF_CON_ELSE_MIXTO_2 creado (IF sin llaves, ELSE con llaves)\n");
    return if_else_node;
}

ASTNode* build_if_con_else_if_sin_llaves(ASTNode* condicion_node, ASTNode* instruccion_if_node, ASTNode* lista_else_if_node, ASTNode* instruccion_else_node, int line, int column) {
    ASTNode* if_else_if_node = create_node("IF_CON_ELSE_IF_SIN_LLAVES", line, column);

    // Condición
    ASTNode* condicion_wrapper = create_node("CONDICION_IF", line, column);
    add_child(condicion_wrapper, condicion_node);
    add_child(if_else_if_node, condicion_wrapper);

    // Instrucción IF
    ASTNode* instruccion_if_wrapper = create_node("INSTRUCCION_IF", line, column);
    add_child(instruccion_if_wrapper, instruccion_if_node);
    add_child(if_else_if_node, instruccion_if_wrapper);

    // Lista de ELSE IF
    add_child(if_else_if_node, lista_else_if_node);

    // Instrucción ELSE
    ASTNode* instruccion_else_wrapper = create_node("INSTRUCCION_ELSE", line, column);
    add_child(instruccion_else_wrapper, instruccion_else_node);
    add_child(if_else_if_node, instruccion_else_wrapper);

    printf("DEBUG IF: IF_CON_ELSE_IF_SIN_LLAVES creado\n");
    return if_else_if_node;
}

ASTNode* build_if_con_else_if_sin_else_final(ASTNode* condicion_node, ASTNode* instruccion_if_node, ASTNode* lista_else_if_node, int line, int column) {
    ASTNode* if_else_if_node = create_node("IF_CON_ELSE_IF_SIN_ELSE_FINAL", line, column);

    // Condición
    ASTNode* condicion_wrapper = create_node("CONDICION_IF", line, column);
    add_child(condicion_wrapper, condicion_node);
    add_child(if_else_if_node, condicion_wrapper);

    // Instrucción IF
    ASTNode* instruccion_if_wrapper = create_node("INSTRUCCION_IF", line, column);
    add_child(instruccion_if_wrapper, instruccion_if_node);
    add_child(if_else_if_node, instruccion_if_wrapper);

    // Lista de ELSE IF
    add_child(if_else_if_node, lista_else_if_node);

    printf("DEBUG IF: IF_CON_ELSE_IF_SIN_ELSE_FINAL creado\n");
    return if_else_if_node;
}

// ========== BUILDERS PARA ELSE IF ==========

ASTNode* build_else_if(ASTNode* condicion_node, ASTNode* instrucciones_node, int line, int column) {
    ASTNode* else_if_node = create_node("ELSE_IF", line, column);

    // Condición
    ASTNode* condicion_wrapper = create_node("CONDICION_ELSE_IF", line, column);
    add_child(condicion_wrapper, condicion_node);
    add_child(else_if_node, condicion_wrapper);

    // Scope para las instrucciones
    ASTNode* scope_else_if = build_scope(instrucciones_node, "ELSE_IF", line, column);
    add_child(else_if_node, scope_else_if);

    printf("DEBUG IF: ELSE_IF creado con llaves\n");
    return else_if_node;
}

ASTNode* build_else_if_sin_llaves(ASTNode* condicion_node, ASTNode* instruccion_node, int line, int column) {
    ASTNode* else_if_node = create_node("ELSE_IF_SIN_LLAVES", line, column);

    // Condición
    ASTNode* condicion_wrapper = create_node("CONDICION_ELSE_IF", line, column);
    add_child(condicion_wrapper, condicion_node);
    add_child(else_if_node, condicion_wrapper);

    // Instrucción única
    ASTNode* instruccion_wrapper = create_node("INSTRUCCION_ELSE_IF", line, column);
    add_child(instruccion_wrapper, instruccion_node);
    add_child(else_if_node, instruccion_wrapper);

    printf("DEBUG IF: ELSE_IF_SIN_LLAVES creado\n");
    return else_if_node;
}

// ========== BUILDERS PARA LISTAS ELSE IF ==========

ASTNode* build_lista_else_if_single(ASTNode* else_if_node, int line, int column) {
    ASTNode* lista_node = create_node("LISTA_ELSE_IF", line, column);
    add_child(lista_node, else_if_node);

    printf("DEBUG IF: LISTA_ELSE_IF creada con 1 elemento\n");
    return lista_node;
}

ASTNode* build_lista_else_if_add(ASTNode* lista_node, ASTNode* else_if_node) {
    if (lista_node && else_if_node) {
        add_child(lista_node, else_if_node);

        printf("DEBUG IF: ELSE_IF agregado a LISTA_ELSE_IF (total: %d elementos)\n",
               lista_node->child_count);
    }
    return lista_node;
}

ASTNode* build_lista_else_if_sin_llaves_single(ASTNode* else_if_node, int line, int column) {
    ASTNode* lista_node = create_node("LISTA_ELSE_IF_SIN_LLAVES", line, column);
    add_child(lista_node, else_if_node);

    printf("DEBUG IF: LISTA_ELSE_IF_SIN_LLAVES creada con 1 elemento\n");
    return lista_node;
}

ASTNode* build_lista_else_if_sin_llaves_add(ASTNode* lista_node, ASTNode* else_if_node) {
    if (lista_node && else_if_node) {
        add_child(lista_node, else_if_node);

        printf("DEBUG IF: ELSE_IF_SIN_LLAVES agregado a LISTA_ELSE_IF_SIN_LLAVES (total: %d elementos)\n",
               lista_node->child_count);
    }
    return lista_node;
}