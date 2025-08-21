/* filepath: Logic/Analyzer/lexer.l */
/*
 * Analizador Léxico para JavaLang
 * Created by lightdemon on 18/08/25
 */

%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../Headers/tokens.h"

/* Variables para tracking de posición */
int yyline = 1;
int yycolumn = 1;

/* Actualizar posición */
#define YY_USER_ACTION yycolumn += yyleng;
%}

/* Opciones de Flex */
%option noyywrap
%option yylineno

/* Definiciones de patrones */
DIGIT       [0-9]
LETTER      [a-zA-Z]
IDENTIFIER  {LETTER}({LETTER}|{DIGIT}|_)*
INTEGER     {DIGIT}+
FLOAT       {DIGIT}+\.{DIGIT}+
WHITESPACE  [ \t]+

%%

/* === TIPOS DE DATOS === */
"int"           { return TOKEN_INT; }
"float"         { return TOKEN_FLOAT; }
"String"        { return TOKEN_STRING; }
"char"          { return TOKEN_CHAR; }
"boolean"       { return TOKEN_BOOLEAN; }

/* === PALABRAS CLAVE === */
"null"          { return TOKEN_NULL; }
"if"            { return TOKEN_IF; }
"else"          { return TOKEN_ELSE; }
"switch"        { return TOKEN_SWITCH; }
"case"          { return TOKEN_CASE; }
"while"         { return TOKEN_WHILE; }
"do"            { return TOKEN_DO; }
"for"           { return TOKEN_FOR; }
"break"         { return TOKEN_BREAK; }
"continue"      { return TOKEN_CONTINUE; }
"return"        { return TOKEN_RETURN; }
"new"           { return TOKEN_NEW; }

/* === FUNCIONES EMBEBIDAS === */
"System.out.println"    { return TOKEN_SOUT; }
"parseInt"              { return TOKEN_PARSEINT; }
"parseFloat"            { return TOKEN_PARSEFLOAT; }
"parseDouble"           { return TOKEN_PARSEDOUBLE; }
"valueOf"               { return TOKEN_VALUEOF; }
"String.join"           { return TOKEN_STRINGJOIN; }
"indexOf"               { return TOKEN_INDEXOF; }
"length"                { return TOKEN_LENGTH; }
"add"                   { return TOKEN_ADD; }

/* === OPERADORES ARITMÉTICOS === */
"+"             { return TOKEN_PLUS; }
"-"             { return TOKEN_MINUS; }
"*"             { return TOKEN_MULTIPLICATION; }
"/"             { return TOKEN_DIVISION; }
"%"             { return TOKEN_MODULE; }

/* === OPERADORES DE ASIGNACIÓN === */
"+="            { return TOKEN_PLUS_ASSIGN; }
"-="            { return TOKEN_MINUS_ASSIGN; }
"*="            { return TOKEN_MULT_ASSIGN; }
"/="            { return TOKEN_DIV_ASSIGN; }
"%="            { return TOKEN_MOD_ASSIGN; }
"&="            { return TOKEN_AND_ASSIGN; }
"|="            { return TOKEN_OR_ASSIGN; }
"^="            { return TOKEN_XOR_ASSIGN; }
"<<="           { return TOKEN_SHIFT_LEFT_ASSIGN; }
">>="           { return TOKEN_SHIFT_RIGHT_ASSIGN; }

/* === OPERADORES DE COMPARACIÓN === */
"=="            { return TOKEN_EQUAL; }
"!="            { return TOKEN_UNEQUAL; }
">"             { return TOKEN_GREATER; }
"<"             { return TOKEN_LESS; }
">="            { return TOKEN_GREATER_EQUAL; }
"<="            { return TOKEN_LESS_EQUAL; }

/* === OPERADORES LÓGICOS === */
"&&"            { return TOKEN_AND; }
"||"            { return TOKEN_OR; }
"!"             { return TOKEN_NOT; }

/* === OPERADORES UNARIOS === */
"++"            { return TOKEN_PLUSPLUS; }
"--"            { return TOKEN_MINUSMINUS; }

/* === DELIMITADORES === */
"("             { return TOKEN_PAREN_LEFT; }
")"             { return TOKEN_PAREN_RIGHT; }
";"             { return TOKEN_SEMICOLON; }
"."             { return TOKEN_DOT; }
","             { return TOKEN_COMMA; }
"{"             { return TOKEN_BRACE_LEFT; }
"}"             { return TOKEN_BRACE_RIGHT; }
"["             { return TOKEN_BRACKET_LEFT; }
"]"             { return TOKEN_BRACKET_RIGHT; }

/* === LITERALES === */
{INTEGER}       { return TOKEN_IDENTIFIER; /* Números van como tokens especiales */ }
{FLOAT}         { return TOKEN_IDENTIFIER; /* Números van como tokens especiales */ }
{IDENTIFIER}    { return TOKEN_IDENTIFIER; }

/* === STRINGS === */
\"([^\"\\\\]|\\\\.)*\"  { return TOKEN_QUOTE_DOUBLE; }
\'([^\'\\\\]|\\\\.)*\'  { return TOKEN_QUOTE_SINGLE; }

/* === ESPACIOS Y LÍNEAS === */
{WHITESPACE}    { /* Ignorar espacios */ }
\n              { yyline++; yycolumn = 1; }

/* === COMENTARIOS === */
"//".*          { /* Ignorar comentarios de línea */ }
"/*"([^*]|\*+[^*/])*\*+"/"  { /* Ignorar comentarios de bloque */ }

/* === FIN DE ARCHIVO === */
<<EOF>>         { return TOKEN_EOF; }

/* === ERROR === */
.               { 
                    printf("ERROR LÉXICO: Carácter no reconocido '%s' en línea %d, columna %d\n", 
                           yytext, yyline, yycolumn);
                    return TOKEN_ERROR;
                }

%%

/* === FUNCIONES AUXILIARES === */

/* Función principal para probar el lexer */
int main(int argc, char** argv) {
    if (argc > 1) {
        yyin = fopen(argv[1], "r");
        if (!yyin) {
            printf("Error: No se pudo abrir el archivo %s\n", argv[1]);
            return 1;
        }
    }
    
    int token;
    printf("=== ANÁLISIS LÉXICO ===\n");
    
    while ((token = yylex()) != TOKEN_EOF) {
        printf("Token: %d, Texto: '%s', Línea: %d, Columna: %d\n", 
               token, yytext, yyline, yycolumn - yyleng);
    }
    
    printf("=== FIN DEL ANÁLISIS ===\n");
    
    if (yyin != stdin) {
        fclose(yyin);
    }
    
    return 0;
}