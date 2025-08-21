%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.tab.h"
#include "../../Headers/error_manager.h"

/* Variables para tracking de posición */
extern FILE* yyin;
extern char* yytext;
extern int yyleng;
extern int yylineno;
extern ErrorManager* global_error_manager;

/* Variables globales correctas */
int yycolumn = 1;
ErrorManager* error_manager = NULL;

/* DECLARACIONES DE FUNCIONES */
void lexer_print_errors();
void lexer_init_error_manager();
void lexer_cleanup();
/* Actualizar posición segura */
#define YY_USER_ACTION do { \
    yycolumn += yyleng; \
} while(0);
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
{INTEGER}                   { return TOKEN_TYPE_INT; }
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
".length"                   { return TOKEN_LENGTH; }
".add"                      { return TOKEN_ADD; }
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
\n                          { yycolumn = 1; }
{IDENTIFIER}                { return TOKEN_IDENTIFIER; }

.                           {
                            /* USAR GLOBAL_ERROR_MANAGER EN LUGAR DE LOCAL */
                            if (!global_error_manager) {
                                global_error_manager = error_manager_create();
                            }
                            
                            /* AGREGAR ERROR LEXICO AL MANAGER GLOBAL */
                            char message[128];
                            snprintf(message, sizeof(message),
                                    "Caracter no reconocido: '%c' (ASCII: %d)",
                                    yytext[0], (unsigned char)yytext[0]);
                            error_manager_add_lexico(global_error_manager, yylineno, yycolumn,
                                                    message, yytext);
                            
                            /* IMPRIMIR DEBUG INMEDIATO */
                            printf("DEBUG LEXER: Error lexico agregado - Linea %d, Columna %d: %s\n",
                                   yylineno, yycolumn, message);
                            
                            return TOKEN_ERROR;
                            }

<<EOF>>                     {
                            /* IMPRIMIR ERRORES ANTES DE TERMINAR */
                            lexer_print_errors();
                            return 0;
                            }
%%

void lexer_init_error_manager() {
    if (!global_error_manager) {
        global_error_manager = error_manager_create();
        printf("DEBUG: Error manager global inicializado en lexer\n");
    }
}

void lexer_print_errors() {
    if (!global_error_manager) {
        printf("DEBUG: No hay global_error_manager para imprimir\n");
        return;
    }
    
    int total_errors = error_manager_get_total_count(global_error_manager);
    printf("DEBUG: Global error manager tiene %d errores\n", total_errors);
    
    if (total_errors > 0) {
        printf("\n=== ERRORES LEXICOS ===\n");
        error_manager_print_all(global_error_manager);
        char* summary = error_manager_get_summary(global_error_manager);
        if (summary) {
            printf("%s\n", summary);
            free(summary);
        }
    } else {
        printf("DEBUG: No hay errores lexicos para mostrar\n");
    }
}

void lexer_cleanup() {
    /* NO DESTRUIR EL GLOBAL_ERROR_MANAGER AQUÍ */
    printf("DEBUG: Lexer cleanup - global_error_manager preservado\n");
}