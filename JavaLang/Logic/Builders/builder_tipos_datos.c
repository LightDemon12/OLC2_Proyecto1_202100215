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
    ASTNode* dato_node = create_node("DATO", line, column);
    ASTNode* valor_node = build_string_literal(valor, line, column);
    add_child(dato_node, valor_node);

    printf("DEBUG TIPOS_DATOS: Nodo DATO (string) creado\n");

    return dato_node;
}

ASTNode* build_dato_int(const char* valor, int line, int column) {
    ASTNode* dato_node = create_node("DATO", line, column);
    ASTNode* valor_node = build_int_literal(valor, line, column);
    add_child(dato_node, valor_node);

    printf("DEBUG TIPOS_DATOS: Nodo DATO (int) creado\n");

    return dato_node;
}

ASTNode* build_dato_float(const char* valor, int line, int column) {
    ASTNode* dato_node = create_node("DATO", line, column);
    ASTNode* valor_node = build_float_literal(valor, line, column);
    add_child(dato_node, valor_node);

    printf("DEBUG TIPOS_DATOS: Nodo DATO (float) creado\n");

    return dato_node;
}

ASTNode* build_dato_char(const char* valor, int line, int column) {
    ASTNode* dato_node = create_node("DATO", line, column);
    ASTNode* valor_node = build_char_literal(valor, line, column);
    add_child(dato_node, valor_node);

    printf("DEBUG TIPOS_DATOS: Nodo DATO (char) creado\n");

    return dato_node;
}

ASTNode* build_dato_boolean(const char* valor, int line, int column) {
    ASTNode* dato_node = create_node("DATO", line, column);
    ASTNode* valor_node = build_boolean_literal(valor, line, column);
    add_child(dato_node, valor_node);

    printf("DEBUG TIPOS_DATOS: Nodo DATO (boolean) creado\n");

    return dato_node;
}

ASTNode* build_dato_null(int line, int column) {
    ASTNode* dato_node = create_node("DATO", line, column);
    ASTNode* null_node = build_null_literal(line, column);
    add_child(dato_node, null_node);

    printf("DEBUG TIPOS_DATOS: Nodo DATO (null) creado\n");

    return dato_node;
}
// ========== LITERALES BÁSICOS (AGREGAR LAS FALTANTES) ==========

ASTNode* build_string_literal(const char* value, int line, int column) {
    ASTNode* string_node = create_node("STRING_LITERAL", line, column);
    // Limpiar comillas si es necesario...
    set_value(string_node, value ? value : "");
    printf("DEBUG TIPOS_DATOS: STRING_LITERAL creado con valor: %s\n", value ? value : "");
    return string_node;
}

ASTNode* build_int_literal(const char* value, int line, int column) {
    ASTNode* int_node = create_node("INT_LITERAL", line, column);
    set_value(int_node, value ? value : "0");
    printf("DEBUG TIPOS_DATOS: INT_LITERAL creado con valor: %s\n", value ? value : "0");
    return int_node;
}

ASTNode* build_float_literal(const char* value, int line, int column) {
    ASTNode* float_node = create_node("FLOAT_LITERAL", line, column);
    set_value(float_node, value ? value : "0.0f");
    printf("DEBUG TIPOS_DATOS: FLOAT_LITERAL creado con valor: %s\n", value ? value : "0.0f");
    return float_node;
}

ASTNode* build_char_literal(const char* value, int line, int column) {
    ASTNode* char_node = create_node("CHAR_LITERAL", line, column);
    set_value(char_node, value ? value : "'\\0'");
    printf("DEBUG TIPOS_DATOS: CHAR_LITERAL creado con valor: %s\n", value ? value : "'\\0'");
    return char_node;
}

ASTNode* build_boolean_literal(const char* value, int line, int column) {
    ASTNode* bool_node = create_node("BOOLEAN_LITERAL", line, column);
    set_value(bool_node, value ? value : "false");
    printf("DEBUG TIPOS_DATOS: BOOLEAN_LITERAL creado con valor: %s\n", value ? value : "false");
    return bool_node;
}

ASTNode* build_identifier(const char* name, int line, int column) {
    ASTNode* id_node = create_node("IDENTIFIER", line, column);
    set_value(id_node, name ? name : "unnamed");
    printf("DEBUG TIPOS_DATOS: IDENTIFIER creado con nombre: %s\n", name ? name : "unnamed");
    return id_node;
}

ASTNode* build_null_literal(int line, int column) {
    ASTNode* null_node = create_node("NULL_LITERAL", line, column);
    set_value(null_node, "null");
    printf("DEBUG TIPOS_DATOS: NULL_LITERAL creado\n");
    return null_node;
}