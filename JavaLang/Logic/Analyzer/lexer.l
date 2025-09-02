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

/* Variables globales correctas */
int yycolumn = 1;
extern ErrorManager* global_error_manager;
/* MACRO PARA DEBUG DE TOKENS */
#define DEBUG_TOKEN(token_name) \
    printf("DEBUG LEXER: %s reconocido: '%s' en linea %d\n", token_name, yytext, yylineno)
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
{INTEGER}                   { yylval.str = strdup(yytext); DEBUG_TOKEN("TOKEN_TYPE_INT"); return TOKEN_TYPE_INT; }
{FLOAT}                     { yylval.str = strdup(yytext); DEBUG_TOKEN("TOKEN_TYPE_FLOAT"); return TOKEN_TYPE_FLOAT; }
{STRING}                    { yylval.str = strdup(yytext); DEBUG_TOKEN("TOKEN_TYPE_STRING"); return TOKEN_TYPE_STRING; }
{CHARACTER}                 { yylval.str = strdup(yytext); DEBUG_TOKEN("TOKEN_TYPE_CHAR"); return TOKEN_TYPE_CHAR; }
"public"                    { DEBUG_TOKEN("TOKEN_PUBLIC"); return TOKEN_PUBLIC; }
"static"                    { DEBUG_TOKEN("TOKEN_STATIC"); return TOKEN_STATIC; }
"void"                      { DEBUG_TOKEN("TOKEN_VOID"); return TOKEN_VOID; }
"main"                      { DEBUG_TOKEN("TOKEN_MAIN"); return TOKEN_MAIN; }
"System.out.println"        { DEBUG_TOKEN("TOKEN_SOUT"); return TOKEN_SOUT; }
"Integer.parseInt"          { DEBUG_TOKEN("TOKEN_PARSEINT"); return TOKEN_PARSEINT; }
"Float.parseFloat"          { DEBUG_TOKEN("TOKEN_PARSEFLOAT"); return TOKEN_PARSEFLOAT; }
"Double.parseDouble"        { DEBUG_TOKEN("TOKEN_PARSEDOUBLE"); return TOKEN_PARSEDOUBLE; }
"String.join"               { DEBUG_TOKEN("TOKEN_STRINGJOIN"); return TOKEN_STRINGJOIN; }
"true"                      { yylval.str = strdup(yytext); DEBUG_TOKEN("TOKEN_TYPE_TRUE"); return TOKEN_TYPE_TRUE; }
"false"                     { yylval.str = strdup(yytext); DEBUG_TOKEN("TOKEN_TYPE_FALSE"); return TOKEN_TYPE_FALSE; }
"boolean"                   { DEBUG_TOKEN("TOKEN_BOOLEAN"); return TOKEN_BOOLEAN; }
"string"                    { DEBUG_TOKEN("TOKEN_STRING"); return TOKEN_STRING; }
"String"                    { DEBUG_TOKEN("TOKEN_STRING"); return TOKEN_STRING; }
"float"                     { DEBUG_TOKEN("TOKEN_FLOAT"); return TOKEN_FLOAT; }
"char"                      { DEBUG_TOKEN("TOKEN_CHAR"); return TOKEN_CHAR; }
"int"                       { DEBUG_TOKEN("TOKEN_INT"); return TOKEN_INT; }
"double"                    { DEBUG_TOKEN("TOKEN_DOUBLE"); return TOKEN_DOUBLE; }
"long"                      { DEBUG_TOKEN("TOKEN_LONG"); return TOKEN_LONG; }
"short"                     { DEBUG_TOKEN("TOKEN_SHORT"); return TOKEN_SHORT; }
"byte"                      { DEBUG_TOKEN("TOKEN_BYTE"); return TOKEN_BYTE; }
"null"                      { DEBUG_TOKEN("TOKEN_NULL"); return TOKEN_NULL; }
"continue"                  { DEBUG_TOKEN("TOKEN_CONTINUE"); return TOKEN_CONTINUE; }
"return"                    { DEBUG_TOKEN("TOKEN_RETURN"); return TOKEN_RETURN; }
"switch"                    { DEBUG_TOKEN("TOKEN_SWITCH"); return TOKEN_SWITCH; }
"default"                   { DEBUG_TOKEN("TOKEN_DEFAULT"); return TOKEN_DEFAULT; }
"break"                     { DEBUG_TOKEN("TOKEN_BREAK"); return TOKEN_BREAK; }
"while"                     { DEBUG_TOKEN("TOKEN_WHILE"); return TOKEN_WHILE; }
"else"                      { DEBUG_TOKEN("TOKEN_ELSE"); return TOKEN_ELSE; }
"case"                      { DEBUG_TOKEN("TOKEN_CASE"); return TOKEN_CASE; }
"for"                       { DEBUG_TOKEN("TOKEN_FOR"); return TOKEN_FOR; }
"if"                        { DEBUG_TOKEN("TOKEN_IF"); return TOKEN_IF; }
"do"                        { DEBUG_TOKEN("TOKEN_DO"); return TOKEN_DO; }
"String.valueOf"            { DEBUG_TOKEN("TOKEN_VALUEOF"); return TOKEN_VALUEOF; }
"Arrays.indexOf"            { DEBUG_TOKEN("TOKEN_INDEXOF"); return TOKEN_INDEXOF; }
".length"                   { DEBUG_TOKEN("TOKEN_LENGTH"); return TOKEN_LENGTH; }
".add"                      { DEBUG_TOKEN("TOKEN_ADD"); return TOKEN_ADD; }
".equals"                   { DEBUG_TOKEN("TOKEN_EQUALS"); return TOKEN_EQUALS; }
"new"                       { DEBUG_TOKEN("TOKEN_NEW"); return TOKEN_NEW; }
"<<="                       { DEBUG_TOKEN("TOKEN_SHIFT_LEFT_ASSIGN"); return TOKEN_SHIFT_LEFT_ASSIGN; }
">>="                       { DEBUG_TOKEN("TOKEN_SHIFT_RIGHT_ASSIGN"); return TOKEN_SHIFT_RIGHT_ASSIGN; }
"++"                        { DEBUG_TOKEN("TOKEN_INCREMENT"); return TOKEN_INCREMENT; }
"--"                        { DEBUG_TOKEN("TOKEN_DECREMENT"); return TOKEN_DECREMENT; }
"+="                        { DEBUG_TOKEN("TOKEN_PLUS_ASSIGN"); return TOKEN_PLUS_ASSIGN; }
"-="                        { DEBUG_TOKEN("TOKEN_MINUS_ASSIGN"); return TOKEN_MINUS_ASSIGN; }
"*="                        { DEBUG_TOKEN("TOKEN_MULT_ASSIGN"); return TOKEN_MULT_ASSIGN; }
"/="                        { DEBUG_TOKEN("TOKEN_DIV_ASSIGN"); return TOKEN_DIV_ASSIGN; }
"%="                        { DEBUG_TOKEN("TOKEN_MOD_ASSIGN"); return TOKEN_MOD_ASSIGN; }
"&="                        { DEBUG_TOKEN("TOKEN_AND_ASSIGN"); return TOKEN_AND_ASSIGN; }
"|="                        { DEBUG_TOKEN("TOKEN_OR_ASSIGN"); return TOKEN_OR_ASSIGN; }
"^="                        { DEBUG_TOKEN("TOKEN_XOR_ASSIGN"); return TOKEN_XOR_ASSIGN; }
"=="                        { DEBUG_TOKEN("TOKEN_EQUAL"); return TOKEN_EQUAL; }
"!="                        { DEBUG_TOKEN("TOKEN_UNEQUAL"); return TOKEN_UNEQUAL; }
">="                        { DEBUG_TOKEN("TOKEN_GREATER_EQUAL"); return TOKEN_GREATER_EQUAL; }
"<="                        { DEBUG_TOKEN("TOKEN_LESS_EQUAL"); return TOKEN_LESS_EQUAL; }
"&&"                        { DEBUG_TOKEN("TOKEN_AND"); return TOKEN_AND; }
"||"                        { DEBUG_TOKEN("TOKEN_OR"); return TOKEN_OR; }
"+"                         { DEBUG_TOKEN("TOKEN_PLUS"); return TOKEN_PLUS; }
"-"                         { DEBUG_TOKEN("TOKEN_MINUS"); return TOKEN_MINUS; }
"*"                         { DEBUG_TOKEN("TOKEN_MULTIPLICATION"); return TOKEN_MULTIPLICATION; }
"/"                         { DEBUG_TOKEN("TOKEN_DIVISION"); return TOKEN_DIVISION; }
"%"                         { DEBUG_TOKEN("TOKEN_MODULE"); return TOKEN_MODULE; }
"="                         { DEBUG_TOKEN("TOKEN_ASSIGN"); return TOKEN_ASSIGN; }
">"                         { DEBUG_TOKEN("TOKEN_GREATER"); return TOKEN_GREATER; }
"<"                         { DEBUG_TOKEN("TOKEN_LESS"); return TOKEN_LESS; }
"!"                         { DEBUG_TOKEN("TOKEN_NOT"); return TOKEN_NOT; }
"("                         { DEBUG_TOKEN("TOKEN_PAREN_LEFT"); return TOKEN_PAREN_LEFT; }
")"                         { DEBUG_TOKEN("TOKEN_PAREN_RIGHT"); return TOKEN_PAREN_RIGHT; }
"{"                         { DEBUG_TOKEN("TOKEN_BRACE_LEFT"); return TOKEN_BRACE_LEFT; }
"}"                         { DEBUG_TOKEN("TOKEN_BRACE_RIGHT"); return TOKEN_BRACE_RIGHT; }
"["                         { DEBUG_TOKEN("TOKEN_BRACKET_LEFT"); return TOKEN_BRACKET_LEFT; }
"]"                         { DEBUG_TOKEN("TOKEN_BRACKET_RIGHT"); return TOKEN_BRACKET_RIGHT; }
";"                         { DEBUG_TOKEN("TOKEN_SEMICOLON"); return TOKEN_SEMICOLON; }
","                         { DEBUG_TOKEN("TOKEN_COMMA"); return TOKEN_COMMA; }
":"                         { DEBUG_TOKEN("TOKEN_COLON"); return TOKEN_COLON; }
"."                         { DEBUG_TOKEN("TOKEN_DOT"); return TOKEN_DOT; }
{WHITESPACE}                { /* Ignorar */ }
\n                          { yycolumn = 1; }
{IDENTIFIER}                { yylval.str = strdup(yytext); DEBUG_TOKEN("TOKEN_IDENTIFIER"); return TOKEN_IDENTIFIER; }
.                           {
                            /* DEBUG PARA ERROR */
                            printf("DEBUG LEXER: TOKEN_ERROR reconocido: '%s' (ASCII: %d) en linea %d\n", 
                                yytext, (unsigned char)yytext[0], yylineno);
                            
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
                            
                            return TOKEN_ERROR;
                            }
<<EOF>>                     {
                            printf("DEBUG LEXER: TOKEN_EOF encontrado en linea %d\n", yylineno);
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
}extern ErrorManager* global_error_manager;
