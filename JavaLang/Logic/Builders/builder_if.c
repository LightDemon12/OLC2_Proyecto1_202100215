//
// Created by lightdemon on 31/08/25.
//

#include "../../Headers/builder_if.h"
#include "../../Headers/builder_scope.h"  // ← YA INCLUIDO
#include <stdio.h>
#include <stdlib.h>

// ========== BUILDERS PARA SENTENCIAS IF ==========

ASTNode* build_if_simple(ASTNode* condicion_node, ASTNode* instrucciones_node, int line, int column) {
    ASTNode* if_node = create_node("IF_SIMPLE", line, column);

    // Crear nodo explícito para la condición
    ASTNode* condicion_wrapper = create_node("CONDICION", line, column);
    add_child(condicion_wrapper, condicion_node);
    add_child(if_node, condicion_wrapper);

    // Crear nodo explícito para el bloque IF con SCOPE
    ASTNode* bloque_if = create_node("BLOQUE_IF", line, column);
    ASTNode* scope_if = build_scope_bloque(instrucciones_node, "IF", line, column);
    add_child(bloque_if, scope_if);
    add_child(if_node, bloque_if);

    printf("DEBUG IF: IF_SIMPLE creado con CONDICION y BLOQUE_IF con SCOPE\n");

    return if_node;
}

ASTNode* build_if_con_else(ASTNode* condicion_node, ASTNode* instrucciones_if_node, ASTNode* instrucciones_else_node, int line, int column) {
    ASTNode* if_else_node = create_node("IF_CON_ELSE", line, column);

    // Condición
    ASTNode* condicion_wrapper = create_node("CONDICION", line, column);
    add_child(condicion_wrapper, condicion_node);
    add_child(if_else_node, condicion_wrapper);

    // Bloque IF con SCOPE
    ASTNode* bloque_if = create_node("BLOQUE_IF", line, column);
    ASTNode* scope_if = build_scope_bloque(instrucciones_if_node, "IF", line, column);
    add_child(bloque_if, scope_if);
    add_child(if_else_node, bloque_if);

    // Bloque ELSE con SCOPE
    ASTNode* bloque_else = create_node("BLOQUE_ELSE", line, column);
    ASTNode* scope_else = build_scope_bloque(instrucciones_else_node, "ELSE", line, column);
    add_child(bloque_else, scope_else);
    add_child(if_else_node, bloque_else);

    printf("DEBUG IF: IF_CON_ELSE creado con SCOPEs separados\n");

    return if_else_node;
}

ASTNode* build_if_con_else_if(ASTNode* condicion_node, ASTNode* instrucciones_if_node, ASTNode* lista_else_if_node, ASTNode* instrucciones_else_node, int line, int column) {
    ASTNode* if_else_if_node = create_node("IF_CON_ELSE_IF", line, column);

    // Crear nodo explícito para la condición inicial
    ASTNode* condicion_wrapper = create_node("CONDICION", line, column);
    add_child(condicion_wrapper, condicion_node);
    add_child(if_else_if_node, condicion_wrapper);

    // Crear nodo explícito para el bloque IF inicial CON SCOPE
    ASTNode* bloque_if = create_node("BLOQUE_IF", line, column);
    ASTNode* scope_if = build_scope_bloque(instrucciones_if_node, "IF", line, column);  // ← AGREGADO
    add_child(bloque_if, scope_if);  // ← CORREGIDO
    add_child(if_else_if_node, bloque_if);

    // Agregar lista de else if (ya contiene nodos explícitos)
    add_child(if_else_if_node, lista_else_if_node);

    // Crear nodo explícito para el bloque ELSE final CON SCOPE
    ASTNode* bloque_else = create_node("BLOQUE_ELSE", line, column);
    ASTNode* scope_else = build_scope_bloque(instrucciones_else_node, "ELSE", line, column);  // ← AGREGADO
    add_child(bloque_else, scope_else);  // ← CORREGIDO
    add_child(if_else_if_node, bloque_else);

    printf("DEBUG IF: IF_CON_ELSE_IF creado con CONDICION, BLOQUE_IF con SCOPE, %d ELSE_IF y BLOQUE_ELSE con SCOPE\n",
           lista_else_if_node ? lista_else_if_node->child_count : 0);

    return if_else_if_node;
}

ASTNode* build_else_if(ASTNode* condicion_node, ASTNode* instrucciones_node, int line, int column) {
    ASTNode* else_if_node = create_node("ELSE_IF", line, column);

    // Crear nodo explícito para la condición del else if
    ASTNode* condicion_else_if = create_node("CONDICION_ELSE_IF", line, column);
    add_child(condicion_else_if, condicion_node);
    add_child(else_if_node, condicion_else_if);

    // Crear nodo explícito para el bloque del else if CON SCOPE
    ASTNode* bloque_else_if = create_node("BLOQUE_ELSE_IF", line, column);
    ASTNode* scope_else_if = build_scope_bloque(instrucciones_node, "ELSE_IF", line, column);  // ← AGREGADO
    add_child(bloque_else_if, scope_else_if);  // ← CORREGIDO
    add_child(else_if_node, bloque_else_if);

    printf("DEBUG IF: ELSE_IF creado con CONDICION_ELSE_IF y BLOQUE_ELSE_IF con SCOPE\n");

    return else_if_node;
}

ASTNode* build_lista_else_if_single(ASTNode* else_if_node, int line, int column) {
    ASTNode* lista_node = create_node("LISTA_ELSE_IF", line, column);

    // Agregar el primer else if
    add_child(lista_node, else_if_node);

    printf("DEBUG IF: LISTA_ELSE_IF creada con 1 elemento\n");

    return lista_node;
}

ASTNode* build_lista_else_if_add(ASTNode* lista_existente, ASTNode* nuevo_else_if) {
    // Agregar el nuevo else if a la lista existente
    add_child(lista_existente, nuevo_else_if);

    printf("DEBUG IF: ELSE_IF agregado a LISTA_ELSE_IF (total: %d)\n",
           lista_existente->child_count);

    return lista_existente;
}