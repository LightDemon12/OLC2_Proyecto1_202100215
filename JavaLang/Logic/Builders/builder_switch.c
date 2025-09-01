//
// Created by lightdemon on 31/08/25.
//

#include "../../Headers/builder_switch.h"
#include "../../Headers/builder_scope.h"
#include <stdio.h>
#include <stdlib.h>

// ========== BUILDERS PARA SENTENCIA SWITCH ==========

ASTNode* build_switch(ASTNode* expresion_node, ASTNode* lista_casos_node, int line, int column) {
    ASTNode* switch_node = create_node("SWITCH", line, column);

    // Crear nodo explícito para la expresión del switch
    ASTNode* expresion_switch = create_node("EXPRESION_SWITCH", line, column);
    add_child(expresion_switch, expresion_node);
    add_child(switch_node, expresion_switch);

    // Crear nodo explícito para el bloque del switch CON SCOPE
    ASTNode* bloque_switch = create_node("BLOQUE_SWITCH", line, column);
    ASTNode* scope_switch = build_scope_bloque(lista_casos_node, "SWITCH", line, column);
    add_child(bloque_switch, scope_switch);
    add_child(switch_node, bloque_switch);

    printf("DEBUG SWITCH: SWITCH creado con expresión, SCOPE y %d casos\n",
           lista_casos_node ? lista_casos_node->child_count : 0);

    return switch_node;
}

ASTNode* build_caso(ASTNode* valor_node, ASTNode* instrucciones_node, ASTNode* sentencia_node, int line, int column) {
    ASTNode* caso_node = create_node("CASO", line, column);

    // Crear nodo explícito para el valor del caso
    ASTNode* valor_caso = create_node("VALOR_CASO", line, column);
    add_child(valor_caso, valor_node);
    add_child(caso_node, valor_caso);

    // Crear nodo explícito para las instrucciones del caso CON SCOPE
    ASTNode* instrucciones_caso = create_node("INSTRUCCIONES_CASO", line, column);
    ASTNode* scope_caso = build_scope_bloque(instrucciones_node, "CASE", line, column);
    add_child(instrucciones_caso, scope_caso);
    add_child(caso_node, instrucciones_caso);

    // Crear nodo explícito para la sentencia de control
    ASTNode* sentencia_caso = create_node("SENTENCIA_CASO", line, column);
    add_child(sentencia_caso, sentencia_node);
    add_child(caso_node, sentencia_caso);

    printf("DEBUG SWITCH: CASO creado con valor, instrucciones con SCOPE y sentencia\n");

    return caso_node;
}

ASTNode* build_caso_con_default(ASTNode* valor_node, ASTNode* instrucciones_node, ASTNode* sentencia_node, ASTNode* instrucciones_default_node, int line, int column) {
    ASTNode* caso_con_default_node = create_node("CASO_CON_DEFAULT", line, column);

    // Crear nodo explícito para el valor del caso
    ASTNode* valor_caso = create_node("VALOR_CASO", line, column);
    add_child(valor_caso, valor_node);
    add_child(caso_con_default_node, valor_caso);

    // Crear nodo explícito para las instrucciones del caso CON SCOPE
    ASTNode* instrucciones_caso = create_node("INSTRUCCIONES_CASO", line, column);
    ASTNode* scope_caso = build_scope_bloque(instrucciones_node, "CASE", line, column);
    add_child(instrucciones_caso, scope_caso);
    add_child(caso_con_default_node, instrucciones_caso);

    // Crear nodo explícito para la sentencia de control
    ASTNode* sentencia_caso = create_node("SENTENCIA_CASO", line, column);
    add_child(sentencia_caso, sentencia_node);
    add_child(caso_con_default_node, sentencia_caso);

    // Crear nodo explícito para el DEFAULT CON SCOPE
    ASTNode* bloque_default = create_node("BLOQUE_DEFAULT", line, column);
    ASTNode* scope_default = build_scope_bloque(instrucciones_default_node, "DEFAULT", line, column);
    add_child(bloque_default, scope_default);
    add_child(caso_con_default_node, bloque_default);

    printf("DEBUG SWITCH: CASO_CON_DEFAULT creado con valor, instrucciones con SCOPE, sentencia y DEFAULT con SCOPE\n");

    return caso_con_default_node;
}

ASTNode* build_lista_casos_single(ASTNode* caso_node, int line, int column) {
    ASTNode* lista_node = create_node("LISTA_CASOS", line, column);

    // Agregar el primer caso
    add_child(lista_node, caso_node);

    printf("DEBUG SWITCH: LISTA_CASOS creada con 1 caso\n");

    return lista_node;
}

ASTNode* build_lista_casos_add(ASTNode* lista_existente, ASTNode* nuevo_caso) {
    // Agregar el nuevo caso a la lista existente
    add_child(lista_existente, nuevo_caso);

    printf("DEBUG SWITCH: CASO agregado a LISTA_CASOS (total: %d)\n",
           lista_existente->child_count);

    return lista_existente;
}