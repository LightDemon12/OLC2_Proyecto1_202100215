//
// Created by lightdemon on 29/08/25.
//

#include "../../Headers/builder_datos.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// ========== FUNCIÓN AUXILIAR PARA LIMPIAR COMILLAS ==========

/**
 * Limpia comillas de un string ("hello" -> hello)
 */
static char* clean_quotes(const char* value, char quote_char) {
    if (!value) return strdup("");

    char* cleaned = strdup(value);
    size_t len = strlen(cleaned);

    // Si tiene comillas al inicio y final, quitarlas
    if (len >= 2 && cleaned[0] == quote_char && cleaned[len-1] == quote_char) {
        cleaned[len-1] = '\0';  // Quitar comilla final
        memmove(cleaned, cleaned + 1, len);  // Quitar comilla inicial
    }

    return cleaned;
}

// ========== BUILDERS DE TIPOS DE DATOS ==========

ASTNode* build_string_literal(const char* value, int line, int column) {
    ASTNode* string_node = create_node("STRING_LITERAL", line, column);

    char* cleaned_value = clean_quotes(value, '"');
    set_value(string_node, cleaned_value);

    printf("DEBUG DATOS: STRING_LITERAL creado con valor: '%s'\n", cleaned_value);

    free(cleaned_value);        // ← Liberar memoria temporal
    free((char*)value);         // ← AGREGAR: Liberar memoria del lexer

    return string_node;
}

ASTNode* build_int_literal(const char* value, int line, int column) {
    ASTNode* int_node = create_node("INT_LITERAL", line, column);

    if (value) {
        set_value(int_node, value);
        printf("DEBUG DATOS: INT_LITERAL creado con valor: %s\n", value);
        free((char*)value);     // ← AGREGAR: Liberar memoria del lexer
    } else {
        set_value(int_node, "0");
        printf("DEBUG DATOS: INT_LITERAL creado con valor por defecto: 0\n");
    }

    return int_node;
}

ASTNode* build_float_literal(const char* value, int line, int column) {
    ASTNode* float_node = create_node("FLOAT_LITERAL", line, column);

    if (value) {
        set_value(float_node, value);
        printf("DEBUG DATOS: FLOAT_LITERAL creado con valor: %s\n", value);
        free((char*)value);     // ← AGREGAR: Liberar memoria del lexer
    } else {
        set_value(float_node, "0.0");
        printf("DEBUG DATOS: FLOAT_LITERAL creado con valor por defecto: 0.0\n");
    }

    return float_node;
}

ASTNode* build_char_literal(const char* value, int line, int column) {
    ASTNode* char_node = create_node("CHAR_LITERAL", line, column);

    char* cleaned_value = clean_quotes(value, '\'');
    set_value(char_node, cleaned_value);

    printf("DEBUG DATOS: CHAR_LITERAL creado con valor: '%s'\n", cleaned_value);

    free(cleaned_value);        // ← Liberar memoria temporal
    free((char*)value);         // ← AGREGAR: Liberar memoria del lexer

    return char_node;
}

ASTNode* build_boolean_literal(const char* value, int line, int column) {
    ASTNode* bool_node = create_node("BOOLEAN_LITERAL", line, column);

    if (value) {
        set_value(bool_node, value);
        printf("DEBUG DATOS: BOOLEAN_LITERAL creado con valor: %s\n", value);
        free((char*)value);     // ← AGREGAR: Liberar memoria del lexer
    } else {
        set_value(bool_node, "false");
        printf("DEBUG DATOS: BOOLEAN_LITERAL creado con valor por defecto: false\n");
    }

    return bool_node;
}

ASTNode* build_identifier(const char* name, int line, int column) {
    ASTNode* id_node = create_node("IDENTIFIER", line, column);

    if (name) {
        set_value(id_node, name);
        printf("DEBUG DATOS: IDENTIFIER creado con nombre: %s\n", name);
        free((char*)name);      // ← AGREGAR: Liberar memoria del lexer
    } else {
        set_value(id_node, "unnamed");
        printf("DEBUG DATOS: IDENTIFIER creado con nombre por defecto: unnamed\n");
    }

    return id_node;
}

ASTNode* build_null_literal(int line, int column) {
    ASTNode* null_node = create_node("NULL_LITERAL", line, column);
    set_value(null_node, "null");

    printf("DEBUG DATOS: NULL_LITERAL creado\n");

    return null_node;
}