%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../Headers/tokens.h"
#include "../../Headers/error_manager.h"
/* Variables para tracking de posición */
int yyline = 1;
int yycolumn = 1;
ErrorManager* error_manager = NULL;
/* Actualizar posición */
#define YY_USER_ACTION yycolumn += yyleng;
%}
/* Opciones de Flex */
%option noyywrap
%option yylineno
/* Definiciones de patrones */
DIGIT       [0-9]
LETTER      [a-zA-ZáéíóúÁÉÍÓÚñÑ]
IDENTIFIER  {LETTER}({LETTER}|{DIGIT}|_)*
INTEGER     {DIGIT}+
FLOAT       {DIGIT}+\.{DIGIT}+
WHITESPACE  [ \t]+
CHARACTER   \'[^\\]\'
STRING      \"([^\"\n\r]|(\\.))*\"
COMMENT_LINE    "//".*
COMMENT_BLOCK   "/*"([^*]|\*+[^*/])*\*+"/"
%%
{COMMENT_LINE}              { /* Ignorar comentarios de línea */ }
{COMMENT_BLOCK}             { /* Ignorar comentarios de bloque */ }
{INTEGER}                    { return TOKEN_TYPE_INT; }
{FLOAT}                     { return TOKEN_TYPE_FLOAT; }
{STRING}                    { return TOKEN_TYPE_STRING; }
{CHARACTER}                 { return TOKEN_TYPE_CHAR; }
"public"                    { return TOKEN_PUBLIC; }
"static"                    { return TOKEN_STATIC; }
"void"                      { return TOKEN_VOID; }
"main"                      { return TOKEN_MAIN; }
"System.out.println"        { return TOKEN_SOUT; }
"Integer.parseInt"          { return TOKEN_PARSEINT; }
"Float.parseFloat"          { return TOKEN_PARSEFLOAT; }
"Double.parseDouble"        { return TOKEN_PARSEDOUBLE; }
"String.join"               { return TOKEN_STRINGJOIN; }
"true"                      { return TOKEN_TYPE_TRUE; }
"false"                     { return TOKEN_TYPE_FALSE; }
"boolean"                   { return TOKEN_BOOLEAN; }
"string"                    { return TOKEN_STRING; }
"float"                     { return TOKEN_FLOAT; }
"char"                      { return TOKEN_CHAR; }
"int"                       { return TOKEN_INT; }
"null"                      { return TOKEN_NULL; }
"continue"                  { return TOKEN_CONTINUE; }
"return"                    { return TOKEN_RETURN; }
"switch"                    { return TOKEN_SWITCH; }
"break"                     { return TOKEN_BREAK; }
"while"                     { return TOKEN_WHILE; }
"else"                      { return TOKEN_ELSE; }
"case"                      { return TOKEN_CASE; }
"for"                       { return TOKEN_FOR; }
"if"                        { return TOKEN_IF; }
"do"                        { return TOKEN_DO; }
"String.valueOf"            { return TOKEN_VALUEOF; }
"Arrays.indexOf"            { return TOKEN_INDEXOF; }
".length"                    { return TOKEN_LENGTH; }
".add"                       { return TOKEN_ADD; }
"new"                       { return TOKEN_NEW; }
"<<="                       { return TOKEN_SHIFT_LEFT_ASSIGN; }
">>="                       { return TOKEN_SHIFT_RIGHT_ASSIGN; }
"++"                        { return TOKEN_INCREMENT; }
"--"                        { return TOKEN_DECREMENT; }
"+="                        { return TOKEN_PLUS_ASSIGN; }
"-="                        { return TOKEN_MINUS_ASSIGN; }
"*="                        { return TOKEN_MULT_ASSIGN; }
"/="                        { return TOKEN_DIV_ASSIGN; }
"%="                        { return TOKEN_MOD_ASSIGN; }
"&="                        { return TOKEN_AND_ASSIGN; }
"|="                        { return TOKEN_OR_ASSIGN; }
"^="                        { return TOKEN_XOR_ASSIGN; }
"=="                        { return TOKEN_EQUAL; }
"!="                        { return TOKEN_UNEQUAL; }
">="                        { return TOKEN_GREATER_EQUAL; }
"<="                        { return TOKEN_LESS_EQUAL; }
"&&"                        { return TOKEN_AND; }
"||"                        { return TOKEN_OR; }
"+"                         { return TOKEN_PLUS; }
"-"                         { return TOKEN_MINUS; }
"*"                         { return TOKEN_MULTIPLICATION; }
"/"                         { return TOKEN_DIVISION; }
"%"                         { return TOKEN_MODULE; }
"="                         { return TOKEN_ASSIGN; }
">"                         { return TOKEN_GREATER; }
"<"                         { return TOKEN_LESS; }
"!"                         { return TOKEN_NOT; }
"("                         { return TOKEN_PAREN_LEFT; }
")"                         { return TOKEN_PAREN_RIGHT; }
"{"                         { return TOKEN_BRACE_LEFT; }
"}"                         { return TOKEN_BRACE_RIGHT; }
"["                         { return TOKEN_BRACKET_LEFT; }
"]"                         { return TOKEN_BRACKET_RIGHT; }
";"                         { return TOKEN_SEMICOLON; }
","                         { return TOKEN_COMMA; }
"."                         { return TOKEN_DOT; }
{WHITESPACE}                { /* Ignorar */ }
\n                          { yyline++; yycolumn = 1; }
{IDENTIFIER}                { return TOKEN_IDENTIFIER; }
.                           { 
                            if (error_manager) {
                                char message[128];
                                snprintf(message, sizeof(message),
                                        "Caracter no reconocido: '%c' (ASCII: %d)",
                                        yytext[0], (unsigned char)yytext[0]);
                                error_manager_add_lexico(error_manager, yyline, yycolumn,
                                                        message, yytext);
                            }
                            return TOKEN_ERROR; 
                            }
%%
int main(int argc, char** argv) {
    // CREAR ERROR MANAGER
    error_manager = error_manager_create();
    if (!error_manager) {
        printf("Error: No se pudo crear el manejador de errores\n");
        return 1;
    }

    if (argc > 1) {
        yyin = fopen(argv[1], "r");
        if (!yyin) {
            printf("Error: No se pudo abrir %s\n", argv[1]);
            error_manager_destroy(error_manager);
            return 1;
        }
    }

    int token;
    printf("=== ANALISIS LEXICO ===\n");  // ← Sin tildes

    while ((token = yylex()) != 0) {
        printf("Token: %s, Texto: '%s', Linea: %d\n",  // ← Sin tildes
            token_name(token), yytext, yyline);
    }

    printf("=== FIN ===\n");

    // GUARDAR SI HAY ERRORES ANTES DE DESTRUIR
    int has_errors = error_manager_has_errors(error_manager);

    // MOSTRAR RESUMEN DE ERRORES
    if (has_errors) {
        printf("\n");
        error_manager_print_all(error_manager);
        char* summary = error_manager_get_summary(error_manager);
        printf("%s\n", summary);
        free(summary);
    } else {
        printf("Analisis completado sin errores\n");  // ← Sin tildes
    }

    if (yyin && yyin != stdin) {
        fclose(yyin);
    }

    // LIMPIAR ERROR MANAGER
    error_manager_destroy(error_manager);

    return has_errors ? 1 : 0;
}