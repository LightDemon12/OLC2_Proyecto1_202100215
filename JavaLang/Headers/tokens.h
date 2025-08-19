//
// Created by lightdemon on 18/08/25.
//

#ifndef JAVALANG_TOKENS_H
#define JAVALANG_TOKENS_H
typedef enum {
    // Tipos de datos primitivos
    TOKEN_INT = 256,
    TOKEN_FLOAT,
    TOKEN_STRING,
    TOKEN_CHAR,
    TOKEN_BOOLEAN,
    // Valor nulo
    TOKEN_NULL,
    // Identificadores
    TOKEN_IDENTIFIER,
    // Operaciones aritméticas
    TOKEN_PLUS,               // +
    TOKEN_MINUS,              // -
    TOKEN_MULTIPLICATION,     // *
    TOKEN_DIVISION,           //  /
    TOKEN_MODULE,             // %
    // Operador de asignación
    TOKEN_PLUS_ASSIGN,        // +=
    TOKEN_MINUS_ASSIGN,       // -=
    TOKEN_MULT_ASSIGN,        // *=
    TOKEN_DIV_ASSIGN,         // /=
    TOKEN_MOD_ASSIGN,         // %=
    TOKEN_AND_ASSIGN,         // &=
    TOKEN_OR_ASSIGN,          // |=
    TOKEN_XOR_ASSIGN,         // ^=
    TOKEN_SHIFT_LEFT_ASSIGN,  // <<=
    TOKEN_SHIFT_RIGHT_ASSIGN, // >>=
    //  Operaciones de comparación
    TOKEN_EQUAL,              // ==
    TOKEN_UNEQUAL,            // !=
    // Relaciones
    TOKEN_GREATER,            // >
    TOKEN_LESS,               // <
    TOKEN_GREATER_EQUAL,      // >=
    TOKEN_LESS_EQUAL,         // <=
    // Operadores lógicos
    TOKEN_AND,                // &&
    TOKEN_OR,                 // ||
    TOKEN_NOT,                // !
    // Agrupadores
    TOKEN_PAREN_LEFT,         // (
    TOKEN_PAREN_RIGHT,        // )
    TOKEN_SEMICOLON,          // ;
    TOKEN_DOT,                // .
    TOKEN_COMMA,              // ,
    TOKEN_BRACE_LEFT,         // {
    TOKEN_BRACE_RIGHT,        // }
    TOKEN_BRACKET_LEFT,       // [
    TOKEN_BRACKET_RIGHT,      // ]
    TOKEN_QUOTE_DOUBLE,       // " "
    TOKEN_QUOTE_SINGLE,       // ' '
    // Sentencias de control de flujo
    TOKEN_IF,
    TOKEN_ELSE,
    TOKEN_SWITCH,
    TOKEN_CASE,
    TOKEN_WHILE,
    TOKEN_DO,
    TOKEN_FOR,
    // Sentencias de transferencia
    TOKEN_BREAK,
    TOKEN_CONTINUE,
    TOKEN_RETURN,
    // Funciones embebidas
    TOKEN_SOUT,
    TOKEN_PARSEINT,
    TOKEN_PARSEFLOAT,
    TOKEN_PARSEDOUBLE,
    TOKEN_VALUEOF,
    TOKEN_STRINGJOIN,
    TOKEN_INDEXOF,
    TOKEN_LENGTH,
    TOKEN_ADD,
    // Secuencias de escape
    TOKEN_ESCAPE,
    // RESERVADAS
    TOKEN_EQUALS,
    TONEK_NEW,
    // operadores sentencias
    TOKEN_PLUSPLUS,         // ++
    TOKEN_MINUSMINUS,       // --
    // Especiales
    TOKEN_EOF,
    TOKEN_ERROR

} TokenType;

const char* token_name(TokenType type);
#endif //JAVALANG_TOKENS_H