//
// Created by lightdemon on 18/08/25.
//

#include "../Headers/tokens.h"

const char* token_name(TokenType type) {
    switch(type) {
        // RESERVADAS
        case TOKEN_INT: return "TOKEN_INT";
        case TOKEN_FLOAT: return "TOKEN_FLOAT";
        case TOKEN_STRING: return "TOKEN_STRING";
        case TOKEN_CHAR: return "TOKEN_CHAR";
        case TOKEN_BOOLEAN: return "TOKEN_BOOLEAN";
        case TOKEN_EQUALS: return "TOKEN_EQUALS";
        case TONEK_NEW: return "TOKEN_NEW";
        case TOKEN_NULL: return "TOKEN_NULL";

        // Identificadores
        case TOKEN_IDENTIFIER: return "TOKEN_IDENTIFIER";

        // Operaciones aritméticas
        case TOKEN_PLUS: return "TOKEN_PLUS";
        case TOKEN_MINUS: return "TOKEN_MINUS";
        case TOKEN_MULTIPLICATION: return "TOKEN_MULTIPLICATION";
        case TOKEN_DIVISION: return "TOKEN_DIVISION";
        case TOKEN_MODULE: return "TOKEN_MODULE";

        // Operadores de asignación
        case TOKEN_PLUS_ASSIGN: return "TOKEN_PLUS_ASSIGN";
        case TOKEN_MINUS_ASSIGN: return "TOKEN_MINUS_ASSIGN";
        case TOKEN_MULT_ASSIGN: return "TOKEN_MULT_ASSIGN";
        case TOKEN_DIV_ASSIGN: return "TOKEN_DIV_ASSIGN";
        case TOKEN_MOD_ASSIGN: return "TOKEN_MOD_ASSIGN";
        case TOKEN_AND_ASSIGN: return "TOKEN_AND_ASSIGN";
        case TOKEN_OR_ASSIGN: return "TOKEN_OR_ASSIGN";
        case TOKEN_XOR_ASSIGN: return "TOKEN_XOR_ASSIGN";
        case TOKEN_SHIFT_LEFT_ASSIGN: return "TOKEN_SHIFT_LEFT_ASSIGN";
        case TOKEN_SHIFT_RIGHT_ASSIGN: return "TOKEN_SHIFT_RIGHT_ASSIGN";
        case TOKEN_ASSIGN: return "TOKEN_ASSIGN";

        // Operaciones de comparación
        case TOKEN_EQUAL: return "TOKEN_EQUAL";
        case TOKEN_UNEQUAL: return "TOKEN_UNEQUAL";

        // Relaciones
        case TOKEN_GREATER: return "TOKEN_GREATER";
        case TOKEN_LESS: return "TOKEN_LESS";
        case TOKEN_GREATER_EQUAL: return "TOKEN_GREATER_EQUAL";
        case TOKEN_LESS_EQUAL: return "TOKEN_LESS_EQUAL";

        // Operadores lógicos
        case TOKEN_AND: return "TOKEN_AND";
        case TOKEN_OR: return "TOKEN_OR";
        case TOKEN_NOT: return "TOKEN_NOT";

        // Agrupadores
        case TOKEN_PAREN_LEFT: return "TOKEN_PAREN_LEFT";
        case TOKEN_PAREN_RIGHT: return "TOKEN_PAREN_RIGHT";
        case TOKEN_SEMICOLON: return "TOKEN_SEMICOLON";
        case TOKEN_DOT: return "TOKEN_DOT";
        case TOKEN_COMMA: return "TOKEN_COMMA";
        case TOKEN_BRACE_LEFT: return "TOKEN_BRACE_LEFT";
        case TOKEN_BRACE_RIGHT: return "TOKEN_BRACE_RIGHT";
        case TOKEN_BRACKET_LEFT: return "TOKEN_BRACKET_LEFT";
        case TOKEN_BRACKET_RIGHT: return "TOKEN_BRACKET_RIGHT";
        case TOKEN_QUOTE_DOUBLE: return "TOKEN_QUOTE_DOUBLE";
        case TOKEN_QUOTE_SINGLE: return "TOKEN_QUOTE_SINGLE";

        // Sentencias de control
        case TOKEN_IF: return "TOKEN_IF";
        case TOKEN_ELSE: return "TOKEN_ELSE";
        case TOKEN_SWITCH: return "TOKEN_SWITCH";
        case TOKEN_CASE: return "TOKEN_CASE";
        case TOKEN_WHILE: return "TOKEN_WHILE";
        case TOKEN_DO: return "TOKEN_DO";
        case TOKEN_FOR: return "TOKEN_FOR";

        // Sentencias de transferencia
        case TOKEN_BREAK: return "TOKEN_BREAK";
        case TOKEN_CONTINUE: return "TOKEN_CONTINUE";
        case TOKEN_RETURN: return "TOKEN_RETURN";

        // Funciones embebidas
        case TOKEN_SOUT: return "TOKEN_SOUT";
        case TOKEN_PARSEINT: return "TOKEN_PARSEINT";
        case TOKEN_PARSEFLOAT: return "TOKEN_PARSEFLOAT";
        case TOKEN_PARSEDOUBLE: return "TOKEN_PARSEDOUBLE";
        case TOKEN_VALUEOF: return "TOKEN_VALUEOF";
        case TOKEN_STRINGJOIN: return "TOKEN_STRINGJOIN";
        case TOKEN_INDEXOF: return "TOKEN_INDEXOF";
        case TOKEN_LENGTH: return "TOKEN_LENGTH";
        case TOKEN_ADD: return "TOKEN_ADD";

        // Escape
        case TOKEN_ESCAPE: return "TOKEN_ESCAPE";

        // Operadores unarios
        case TOKEN_INCREMENT: return "TOKEN_INCREMENT";
        case TOKEN_DECREMENT: return "TOKEN_DECREMENT";

        // Tipos de datos primitivos
        case TOKEN_TYPE_INT: return "TOKEN_TYPE_INT";
        case TOKEN_TYPE_FLOAT: return "TOKEN_TYPE_FLOAT";
        case TOKEN_TYPE_STRING: return "TOKEN_TYPE_STRING";
        case TOKEN_TYPE_CHAR: return "TOKEN_TYPE_CHAR";
        case TOKEN_TYPE_TRUE: return "TOKEN_TYPE_TRUE";
        case TOKEN_TYPE_FALSE: return "TOKEN_TYPE_FALSE";

        // Especiales
        case TOKEN_EOF: return "TOKEN_EOF";
        case TOKEN_ERROR: return "TOKEN_ERROR";

        default: return "TOKEN_UNKNOWN";
    }
}