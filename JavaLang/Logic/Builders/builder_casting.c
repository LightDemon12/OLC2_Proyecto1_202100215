//
// Created by lightdemon on 2/09/25.
//
#include "../../Headers/builder_casting.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// ========== BUILDER DE CASTING EXPLÍCITO ==========

ASTNode* build_cast_node(ASTNode* tipo_destino, ASTNode* expresion, int line, int column) {
    if (!tipo_destino || !expresion) {
        printf("ERROR CASTING: Parámetros NULL - tipo_destino:%p, expresion:%p\n",
               (void*)tipo_destino, (void*)expresion);
        return NULL;
    }

    ASTNode* cast_node = create_node("CAST", line, column);
    if (!cast_node) {
        printf("ERROR CASTING: No se pudo crear nodo CAST\n");
        return NULL;
    }

    // El tipo de destino como valor del nodo
    if (tipo_destino->value) {
        set_value(cast_node, tipo_destino->value);
        printf("DEBUG CASTING: Cast a tipo '%s' creado en línea %d\n",
               tipo_destino->value, line);
    } else {
        set_value(cast_node, "unknown_type");
        printf("DEBUG CASTING: Cast a tipo desconocido creado en línea %d\n", line);
    }

    // Añadir hijos: [0] = tipo_destino, [1] = expresion
    add_child(cast_node, tipo_destino);
    add_child(cast_node, expresion);

    printf("DEBUG CASTING: Nodo CAST creado exitosamente (hijos: %d)\n", cast_node->child_count);

    return cast_node;
}

// ========== BUILDER DE CASTING IMPLÍCITO ==========

ASTNode* build_cast_implicit_node(const char* tipo_origen, const char* tipo_destino,
                                  ASTNode* expresion, int line, int column) {
    if (!tipo_origen || !tipo_destino || !expresion) {
        printf("ERROR CASTING: Parámetros NULL para cast implícito\n");
        return NULL;
    }

    ASTNode* cast_node = create_node("CAST_IMPLICIT", line, column);
    if (!cast_node) {
        printf("ERROR CASTING: No se pudo crear nodo CAST_IMPLICIT\n");
        return NULL;
    }

    // Crear valor compuesto: "origen->destino"
    char cast_info[128];
    snprintf(cast_info, sizeof(cast_info), "%s->%s", tipo_origen, tipo_destino);
    set_value(cast_node, cast_info);

    // Crear nodo para el tipo de destino
    ASTNode* tipo_destino_node = create_node("TIPO", line, column);
    set_value(tipo_destino_node, tipo_destino);

    // Añadir hijos: [0] = tipo_destino, [1] = expresion
    add_child(cast_node, tipo_destino_node);
    add_child(cast_node, expresion);

    printf("DEBUG CASTING: Cast implícito %s creado\n", cast_info);

    return cast_node;
}