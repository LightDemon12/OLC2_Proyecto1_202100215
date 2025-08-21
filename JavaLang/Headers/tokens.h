//
// Created by lightdemon on 18/08/25.
//

#ifndef JAVALANG_TOKENS_H
#define JAVALANG_TOKENS_H
typedef enum {
    // RESERVADAS
    TOKEN_INT = 256, // int
    TOKEN_FLOAT,     // float
    TOKEN_STRING,   // string
    TOKEN_CHAR,     // char
    TOKEN_BOOLEAN,  // boolean
    TOKEN_EQUALS,   // equals
    TONEK_NEW,      // new
    // Valor nulo
    TOKEN_NULL,     // null
    // Identificadores
    TOKEN_IDENTIFIER,         // id
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
    TOKEN_ASSIGN,             // =
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
    TOKEN_IF,                 // if
    TOKEN_ELSE,               // else
    TOKEN_SWITCH,             // switch
    TOKEN_CASE,               // case
    TOKEN_WHILE,              // case
    TOKEN_DO,                 // do
    TOKEN_FOR,                // for
    // Sentencias de transferencia
    TOKEN_BREAK,              // break
    TOKEN_CONTINUE,           // continue
    TOKEN_RETURN,             // return
    // Funciones embebidas
    TOKEN_SOUT,               // System.out.println
    TOKEN_PARSEINT,           // Integer.parseInt
    TOKEN_PARSEFLOAT,         // Float.parseFloat
    TOKEN_PARSEDOUBLE,        // Double.parseDouble
    TOKEN_VALUEOF,            // String.valueOf
    TOKEN_STRINGJOIN,         // String.join
    TOKEN_INDEXOF,            // Arrays.indexOf
    TOKEN_LENGTH,             // .length
    TOKEN_ADD,                // .add
    // Secuencias de escape
    TOKEN_ESCAPE,
    // operadores sentencias
    TOKEN_INCREMENT,         // ++
    TOKEN_DECREMENT,       // --
    // Especiales
    TOKEN_EOF,          // fin archivo
    TOKEN_ERROR,        // error
    // Tipos de datos primitivos
    TOKEN_TYPE_INT,     // numero
    TOKEN_TYPE_FLOAT,    // decimal
    TOKEN_TYPE_STRING,  // cadena
    TOKEN_TYPE_CHAR,    // char
    TOKEN_TYPE_TRUE,    // verdadero
    TOKEN_TYPE_FALSE    // false

} TokenType;

const char* token_name(TokenType type);
#endif //JAVALANG_TOKENS_H