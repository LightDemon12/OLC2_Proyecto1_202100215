//
// Created by lightdemon on 31/08/25.
//

#include "../../Headers/builder_asignacion.h"
#include "../../Headers/builder_datos.h"
#include <stdio.h>
#include <stdlib.h>

// ========== BUILDERS PARA ASIGNACIONES ==========

ASTNode* build_asignacion_compuesta(const char* identifier, ASTNode* operador_node, ASTNode* expresion_node, int line, int column) {
    ASTNode* asignacion_node = create_node("ASIGNACION_COMPUESTA", line, column);

    // Crear y agregar el nodo IDENTIFIER
    ASTNode* id_node = build_identifier(identifier, line, column);
    add_child(asignacion_node, id_node);

    // Agregar el operador de asignación
    add_child(asignacion_node, operador_node);

    // Agregar la expresión
    add_child(asignacion_node, expresion_node);

    printf("DEBUG ASIGNACION: ASIGNACION_COMPUESTA creada - var:%s, op:%s\n",
           identifier ? identifier : "null",
           operador_node->value ? operador_node->value : "null");

    return asignacion_node;
}

ASTNode* build_operador_asignacion(const char* operador, int line, int column) {
    ASTNode* operador_node = create_node("OPERADOR_ASIGNACION", line, column);
    set_value(operador_node, operador);

    printf("DEBUG ASIGNACION: OPERADOR_ASIGNACION creado: %s\n", operador ? operador : "null");

    return operador_node;
}

ASTNode* build_asignacion_simple(const char* identifier, ASTNode* expresion_node, int line, int column) {
    ASTNode* asignacion_node = create_node("ASIGNACION_SIMPLE", line, column);

    // Crear y agregar el nodo IDENTIFIER
    ASTNode* id_node = build_identifier(identifier, line, column);
    add_child(asignacion_node, id_node);

    // Agregar la expresión
    add_child(asignacion_node, expresion_node);

    printf("DEBUG ASIGNACION: ASIGNACION_SIMPLE creada - var:%s\n",
           identifier ? identifier : "null");

    return asignacion_node;
}