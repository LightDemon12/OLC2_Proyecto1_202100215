#include "../../Headers/builder_datos.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// ========== FUNCIÓN AUXILIAR PARA LIMPIAR COMILLAS ==========

static char* clean_quotes_new(const char* value, char quote_char) {
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

// ========== FUNCIÓN AUXILIAR PARA LIMPIAR SUFIJOS ==========

static char* clean_numeric_suffix_new(const char* value) {
    if (!value) return strdup("0");

    char* cleaned = strdup(value);
    size_t len = strlen(cleaned);

    // Remover sufijos: f, F, d, D, l, L
    if (len > 1) {
        char last = cleaned[len-1];
        if (last == 'f' || last == 'F' ||
            last == 'd' || last == 'D' ||
            last == 'l' || last == 'L') {
            cleaned[len-1] = '\0';
        }
    }

    return cleaned;
}

// ========== BUILDERS DE LITERALES DIRECTOS (NOMBRES ÚNICOS) ==========

ASTNode* build_string_literal_new(const char* value, int line, int column) {
    ASTNode* string_node = create_node("STRING_LITERAL", line, column);

    char* cleaned_value = clean_quotes_new(value, '"');
    set_value(string_node, cleaned_value);

    printf("DEBUG DATOS NEW: STRING_LITERAL creado con valor: '%s'\n", cleaned_value);

    free(cleaned_value);
    return string_node;
}

ASTNode* build_int_literal_new(const char* value, int line, int column) {
    ASTNode* int_node = create_node("INT_LITERAL", line, column);

    if (value) {
        set_value(int_node, value);
        printf("DEBUG DATOS NEW: INT_LITERAL creado con valor: %s\n", value);
    } else {
        set_value(int_node, "0");
        printf("DEBUG DATOS NEW: INT_LITERAL creado con valor por defecto: 0\n");
    }

    return int_node;
}

ASTNode* build_long_literal_new(const char* value, int line, int column) {
    ASTNode* long_node = create_node("LONG_LITERAL", line, column);

    if (value) {
        // Mantener el sufijo L para identificación del tipo
        set_value(long_node, value);
        printf("DEBUG DATOS NEW: LONG_LITERAL creado con valor: %s\n", value);
    } else {
        set_value(long_node, "0L");
        printf("DEBUG DATOS NEW: LONG_LITERAL creado con valor por defecto: 0L\n");
    }

    return long_node;
}

ASTNode* build_float_literal_new(const char* value, int line, int column) {
    ASTNode* float_node = create_node("FLOAT_LITERAL", line, column);

    if (value) {
        set_value(float_node, value);
        printf("DEBUG DATOS NEW: FLOAT_LITERAL creado con valor: %s\n", value);
    } else {
        set_value(float_node, "0.0f");
        printf("DEBUG DATOS NEW: FLOAT_LITERAL creado con valor por defecto: 0.0f\n");
    }

    return float_node;
}

ASTNode* build_double_literal_new(const char* value, int line, int column) {
    ASTNode* double_node = create_node("DOUBLE_LITERAL", line, column);

    if (value) {
        set_value(double_node, value);
        printf("DEBUG DATOS NEW: DOUBLE_LITERAL creado con valor: %s\n", value);
    } else {
        set_value(double_node, "0.0");
        printf("DEBUG DATOS NEW: DOUBLE_LITERAL creado con valor por defecto: 0.0\n");
    }

    return double_node;
}
ASTNode* build_double_literal(const char* value, int line, int column) {
    ASTNode* double_node = create_node("DOUBLE_LITERAL", line, column);

    if (value) {
        set_value(double_node, value);
        printf("DEBUG DATOS: DOUBLE_LITERAL creado con valor: %s\n", value);
    } else {
        set_value(double_node, "0.0");
        printf("DEBUG DATOS: DOUBLE_LITERAL creado con valor por defecto: 0.0\n");
    }

    return double_node;
}

ASTNode* build_dato_long(const char* value, int line, int column) {
    ASTNode* dato_node = create_node("DATO", line, column);
    ASTNode* long_literal = build_long_literal(value, line, column);

    add_child(dato_node, long_literal);

    printf("DEBUG DATOS: DATO(LONG) creado\n");

    if (value) free((char*)value); // Liberar memoria del lexer
    return dato_node;
}

ASTNode* build_dato_double(const char* value, int line, int column) {
    ASTNode* dato_node = create_node("DATO", line, column);
    ASTNode* double_literal = build_double_literal(value, line, column);

    add_child(dato_node, double_literal);

    printf("DEBUG DATOS: DATO(DOUBLE) creado\n");

    if (value) free((char*)value); // Liberar memoria del lexer
    return dato_node;
}

ASTNode* build_long_literal(const char* value, int line, int column) {
    ASTNode* long_node = create_node("LONG_LITERAL", line, column);

    if (value) {
        // Mantener el sufijo L para identificación del tipo
        set_value(long_node, value);
        printf("DEBUG DATOS: LONG_LITERAL creado con valor: %s\n", value);
    } else {
        set_value(long_node, "0L");
        printf("DEBUG DATOS: LONG_LITERAL creado con valor por defecto: 0L\n");
    }

    return long_node;
}


ASTNode* build_char_literal_new(const char* value, int line, int column) {
    ASTNode* char_node = create_node("CHAR_LITERAL", line, column);

    char* cleaned_value = clean_quotes_new(value, '\'');
    set_value(char_node, cleaned_value);

    printf("DEBUG DATOS NEW: CHAR_LITERAL creado con valor: '%s'\n", cleaned_value);

    free(cleaned_value);
    return char_node;
}

ASTNode* build_boolean_literal_new(const char* value, int line, int column) {
    ASTNode* bool_node = create_node("BOOLEAN_LITERAL", line, column);

    if (value) {
        set_value(bool_node, value);
        printf("DEBUG DATOS NEW: BOOLEAN_LITERAL creado con valor: %s\n", value);
    } else {
        set_value(bool_node, "false");
        printf("DEBUG DATOS NEW: BOOLEAN_LITERAL creado con valor por defecto: false\n");
    }

    return bool_node;
}

ASTNode* build_identifier_new(const char* name, int line, int column) {
    ASTNode* id_node = create_node("IDENTIFIER", line, column);

    if (name) {
        set_value(id_node, name);
        printf("DEBUG DATOS NEW: IDENTIFIER creado con nombre: %s\n", name);
    } else {
        set_value(id_node, "unnamed");
        printf("DEBUG DATOS NEW: IDENTIFIER creado con nombre por defecto: unnamed\n");
    }

    return id_node;
}

ASTNode* build_null_literal_new(int line, int column) {
    ASTNode* null_node = create_node("NULL_LITERAL", line, column);
    set_value(null_node, "null");

    printf("DEBUG DATOS NEW: NULL_LITERAL creado\n");

    return null_node;
}

// ========== BUILDERS DE NODOS DATO (WRAPPER) CON NOMBRES ÚNICOS ==========

ASTNode* build_dato_string_new(const char* value, int line, int column) {
    ASTNode* dato_node = create_node("DATO", line, column);
    ASTNode* string_literal = build_string_literal_new(value, line, column);

    add_child(dato_node, string_literal);

    printf("DEBUG DATOS NEW: DATO(STRING) creado\n");

    if (value) free((char*)value); // Liberar memoria del lexer
    return dato_node;
}

ASTNode* build_dato_int_new(const char* value, int line, int column) {
    ASTNode* dato_node = create_node("DATO", line, column);
    ASTNode* int_literal = build_int_literal_new(value, line, column);

    add_child(dato_node, int_literal);

    printf("DEBUG DATOS NEW: DATO(INT) creado\n");

    if (value) free((char*)value); // Liberar memoria del lexer
    return dato_node;
}

ASTNode* build_dato_long_new(const char* value, int line, int column) {
    ASTNode* dato_node = create_node("DATO", line, column);
    ASTNode* long_literal = build_long_literal_new(value, line, column);

    add_child(dato_node, long_literal);

    printf("DEBUG DATOS NEW: DATO(LONG) creado\n");

    if (value) free((char*)value); // Liberar memoria del lexer
    return dato_node;
}

ASTNode* build_dato_float_new(const char* value, int line, int column) {
    ASTNode* dato_node = create_node("DATO", line, column);
    ASTNode* float_literal = build_float_literal_new(value, line, column);

    add_child(dato_node, float_literal);

    printf("DEBUG DATOS NEW: DATO(FLOAT) creado\n");

    if (value) free((char*)value); // Liberar memoria del lexer
    return dato_node;
}

ASTNode* build_dato_double_new(const char* value, int line, int column) {
    ASTNode* dato_node = create_node("DATO", line, column);
    ASTNode* double_literal = build_double_literal_new(value, line, column);

    add_child(dato_node, double_literal);

    printf("DEBUG DATOS NEW: DATO(DOUBLE) creado\n");

    if (value) free((char*)value); // Liberar memoria del lexer
    return dato_node;
}

ASTNode* build_dato_char_new(const char* value, int line, int column) {
    ASTNode* dato_node = create_node("DATO", line, column);
    ASTNode* char_literal = build_char_literal_new(value, line, column);

    add_child(dato_node, char_literal);

    printf("DEBUG DATOS NEW: DATO(CHAR) creado\n");

    if (value) free((char*)value); // Liberar memoria del lexer
    return dato_node;
}

ASTNode* build_dato_boolean_new(const char* value, int line, int column) {
    ASTNode* dato_node = create_node("DATO", line, column);
    ASTNode* boolean_literal = build_boolean_literal_new(value, line, column);

    add_child(dato_node, boolean_literal);

    printf("DEBUG DATOS NEW: DATO(BOOLEAN) creado\n");

    if (value) free((char*)value); // Liberar memoria del lexer
    return dato_node;
}

ASTNode* build_dato_null_new(int line, int column) {
    ASTNode* dato_node = create_node("DATO", line, column);
    ASTNode* null_literal = build_null_literal_new(line, column);

    add_child(dato_node, null_literal);

    printf("DEBUG DATOS NEW: DATO(NULL) creado\n");

    return dato_node;
}