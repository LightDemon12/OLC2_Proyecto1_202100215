#include "../../Headers/builder_declaraciones.h"
#include "../../Headers/builder_datos.h"
#include "../../Headers/builder_tipos_datos.h"
#include <stdio.h>
#include <stdlib.h>

/* ===== DECLARACIONES DE VARIABLES ===== */

ASTNode* build_declaracion_single(ASTNode* tipo_node, const char* identifier, ASTNode* expresion_node, int line, int column) {
    ASTNode* declaraciones_node = create_node("DECLARACION_CON_INICIALIZACION", line, column);

    add_child(declaraciones_node, tipo_node);

    ASTNode* id_node = build_identifier(identifier, line, column);
    add_child(declaraciones_node, id_node);

    add_child(declaraciones_node, expresion_node);

    printf("DEBUG DECLARACIONES: Declaración con inicialización - tipo:%s, var:%s\n",
           tipo_node->value ? tipo_node->value : "null",
           identifier ? identifier : "null");

    return declaraciones_node;
}

ASTNode* build_declaracion_multiple(ASTNode* tipo_node, ASTNode* lista_declaraciones_node, int line, int column) {
    ASTNode* declaraciones_node = create_node("DECLARACION_MULTIPLE", line, column);

    add_child(declaraciones_node, tipo_node);
    add_child(declaraciones_node, lista_declaraciones_node);

    printf("DEBUG DECLARACIONES: Declaración múltiple - tipo:%s, variables:%d\n",
           tipo_node->value ? tipo_node->value : "null",
           lista_declaraciones_node->child_count);

    return declaraciones_node;
}

ASTNode* build_declaracion_sin_inicializacion(ASTNode* tipo_node, const char* identifier, int line, int column) {
    ASTNode* declaraciones_node = create_node("DECLARACION_SIN_INICIALIZACION", line, column);

    add_child(declaraciones_node, tipo_node);

    ASTNode* id_node = build_identifier(identifier, line, column);
    add_child(declaraciones_node, id_node);

    printf("DEBUG DECLARACIONES: Declaración sin inicialización - tipo:%s, var:%s\n",
           tipo_node->value ? tipo_node->value : "null",
           identifier ? identifier : "null");

    return declaraciones_node;
}

/* ===== DECLARACIONES DE CONSTANTES (FINAL) ===== */

ASTNode* build_constante_single(ASTNode* tipo_node, const char* identifier, ASTNode* expresion_node, int line, int column) {
    ASTNode* constante_node = create_node("CONSTANTE_CON_INICIALIZACION", line, column);

    add_child(constante_node, tipo_node);

    ASTNode* id_node = build_identifier(identifier, line, column);
    add_child(constante_node, id_node);

    add_child(constante_node, expresion_node);

    printf("DEBUG DECLARACIONES: Constante con inicialización - tipo:%s, const:%s\n",
           tipo_node->value ? tipo_node->value : "null",
           identifier ? identifier : "null");

    return constante_node;
}

ASTNode* build_constante_multiple(ASTNode* tipo_node, ASTNode* lista_declaraciones_node, int line, int column) {
    ASTNode* constante_node = create_node("CONSTANTE_MULTIPLE", line, column);

    add_child(constante_node, tipo_node);
    add_child(constante_node, lista_declaraciones_node);

    printf("DEBUG DECLARACIONES: Constante múltiple - tipo:%s, constantes:%d\n",
           tipo_node->value ? tipo_node->value : "null",
           lista_declaraciones_node->child_count);

    return constante_node;
}

/* ===== LISTAS DE DECLARACIONES ===== */

ASTNode* build_lista_declaraciones_single(ASTNode* declaracion_node, int line, int column) {
    ASTNode* lista_node = create_node("LISTA_DECLARACIONES", line, column);
    add_child(lista_node, declaracion_node);

    printf("DEBUG DECLARACIONES: LISTA_DECLARACIONES creada con 1 elemento\n");

    return lista_node;
}

ASTNode* build_lista_declaraciones_add(ASTNode* lista_existente, ASTNode* nueva_declaracion) {
    add_child(lista_existente, nueva_declaracion);

    printf("DEBUG DECLARACIONES: Elemento agregado a LISTA_DECLARACIONES (total: %d)\n",
           lista_existente->child_count);

    return lista_existente;
}

ASTNode* build_lista_declaracion_node(const char* identifier, ASTNode* expresion_node, int line, int column) {
    ASTNode* lista_declaracion_node = create_node("LISTA_DECLARACION", line, column);

    ASTNode* id_node = build_identifier(identifier, line, column);
    add_child(lista_declaracion_node, id_node);

    add_child(lista_declaracion_node, expresion_node);

    printf("DEBUG DECLARACIONES: LISTA_DECLARACION creada - elemento:%s\n",
           identifier ? identifier : "null");

    return lista_declaracion_node;
}