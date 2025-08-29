//
// Created by lightdemon on 29/08/25.
//

#include "../../Headers/builder_declaraciones.h"
#include "../../Headers/builder_datos.h"
#include <stdio.h>
#include <stdlib.h>

// ========== BUILDERS PARA DECLARACIONES ==========

ASTNode* build_declaracion_single(ASTNode* tipo_node, const char* identifier, ASTNode* dato_node, int line, int column) {
    ASTNode* declaraciones_node = create_node("DECLARACIONES", line, column);

    // Agregar el tipo como primer hijo
    add_child(declaraciones_node, tipo_node);

    // Crear y agregar el nodo IDENTIFIER
    ASTNode* id_node = build_identifier(identifier, line, column);
    add_child(declaraciones_node, id_node);

    // Agregar el dato como tercer hijo
    add_child(declaraciones_node, dato_node);

    printf("DEBUG DECLARACIONES: Declaración simple creada - tipo:%s, var:%s\n",
           tipo_node->value ? tipo_node->value : "null",
           identifier ? identifier : "null");

    return declaraciones_node;
}

ASTNode* build_declaracion_multiple(ASTNode* tipo_node, ASTNode* lista_declaraciones_node, int line, int column) {
    ASTNode* declaraciones_node = create_node("DECLARACIONES", line, column);

    // Agregar el tipo como primer hijo
    add_child(declaraciones_node, tipo_node);

    // Agregar la lista de declaraciones como segundo hijo
    add_child(declaraciones_node, lista_declaraciones_node);

    printf("DEBUG DECLARACIONES: Declaración múltiple creada - tipo:%s, variables:%d\n",
           tipo_node->value ? tipo_node->value : "null",
           lista_declaraciones_node->child_count);

    return declaraciones_node;
}

ASTNode* build_tipo_node(const char* tipo_token, int line, int column) {
    ASTNode* tipo_node = create_node("TIPO", line, column);
    set_value(tipo_node, tipo_token);

    printf("DEBUG DECLARACIONES: Nodo TIPO creado: %s\n", tipo_token ? tipo_token : "null");

    return tipo_node;
}

ASTNode* build_dato_node(const char* valor, int line, int column) {
    ASTNode* dato_node = create_node("DATO", line, column);

    // El dato podría ser cualquier tipo, por ahora asumimos que es string
    // En el futuro aquí se podría determinar el tipo automáticamente
    ASTNode* valor_node = build_string_literal(valor, line, column);
    add_child(dato_node, valor_node);

    printf("DEBUG DECLARACIONES: Nodo DATO creado\n");

    return dato_node;
}

ASTNode* build_lista_declaraciones_single(ASTNode* declaracion_node, int line, int column) {
    ASTNode* lista_node = create_node("LISTA_DECLARACIONES", line, column);
    add_child(lista_node, declaracion_node);

    printf("DEBUG DECLARACIONES: LISTA_DECLARACIONES creada con 1 variable\n");

    return lista_node;
}

ASTNode* build_lista_declaraciones_add(ASTNode* lista_existente, ASTNode* nueva_declaracion) {
    add_child(lista_existente, nueva_declaracion);

    printf("DEBUG DECLARACIONES: Variable agregada a LISTA_DECLARACIONES (total: %d)\n",
           lista_existente->child_count);

    return lista_existente;
}

ASTNode* build_lista_declaracion_node(const char* identifier, ASTNode* dato_node, int line, int column) {
    ASTNode* lista_declaracion_node = create_node("LISTA_DECLARACION", line, column);

    // Crear y agregar el nodo IDENTIFIER
    ASTNode* id_node = build_identifier(identifier, line, column);
    add_child(lista_declaracion_node, id_node);

    // Agregar el dato
    add_child(lista_declaracion_node, dato_node);

    printf("DEBUG DECLARACIONES: LISTA_DECLARACION creada - var:%s\n",
           identifier ? identifier : "null");

    return lista_declaracion_node;
}