//
// Created by lightdemon on 29/08/25.
//

#include "../../Headers/builder_tipos_datos.h"
#include "../../Headers/builder_datos.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// ========== BUILDERS REUTILIZABLES ==========

ASTNode* build_tipo_node(const char* tipo_token, int line, int column) {
    ASTNode* tipo_node = create_node("TIPO", line, column);
    set_value(tipo_node, tipo_token);

    printf("DEBUG TIPOS_DATOS: Nodo TIPO creado: %s\n", tipo_token ? tipo_token : "null");

    return tipo_node;
}

ASTNode* build_dato_node(const char* valor, const char* tipo_esperado, int line, int column) {
    ASTNode* dato_node = create_node("DATO", line, column);
    ASTNode* valor_node = NULL;

    // Auto-detectar tipo si no se especifica
    if (!tipo_esperado) {
        // Lógica simple de detección de tipo
        if (valor && strlen(valor) > 0) {
            if (valor[0] == '"') {
                tipo_esperado = "string";
            } else if (valor[0] == '\'') {
                tipo_esperado = "char";
            } else if (strcmp(valor, "true") == 0 || strcmp(valor, "false") == 0) {
                tipo_esperado = "boolean";
            } else if (strchr(valor, '.') != NULL) {
                tipo_esperado = "float";
            } else {
                tipo_esperado = "int";
            }
        } else {
            tipo_esperado = "string"; // Por defecto
        }
    }

    // Crear el literal apropiado según el tipo
    if (strcmp(tipo_esperado, "string") == 0) {
        valor_node = build_string_literal(valor, line, column);
    } else if (strcmp(tipo_esperado, "int") == 0) {
        valor_node = build_int_literal(valor, line, column);
    } else if (strcmp(tipo_esperado, "float") == 0) {
        valor_node = build_float_literal(valor, line, column);
    } else if (strcmp(tipo_esperado, "char") == 0) {
        valor_node = build_char_literal(valor, line, column);
    } else if (strcmp(tipo_esperado, "boolean") == 0) {
        valor_node = build_boolean_literal(valor, line, column);
    } else {
        // Por defecto, tratarlo como string
        valor_node = build_string_literal(valor, line, column);
    }

    add_child(dato_node, valor_node);

    printf("DEBUG TIPOS_DATOS: Nodo DATO creado - tipo:%s\n", tipo_esperado);

    return dato_node;
}

// ========== BUILDERS ESPECÍFICOS ==========

ASTNode* build_dato_string(const char* valor, int line, int column) {
    return build_dato_node(valor, "string", line, column);
}

ASTNode* build_dato_int(const char* valor, int line, int column) {
    return build_dato_node(valor, "int", line, column);
}

ASTNode* build_dato_float(const char* valor, int line, int column) {
    return build_dato_node(valor, "float", line, column);
}

ASTNode* build_dato_char(const char* valor, int line, int column) {
    return build_dato_node(valor, "char", line, column);
}

ASTNode* build_dato_boolean(const char* valor, int line, int column) {
    return build_dato_node(valor, "boolean", line, column);
}