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
CHARACTER   \'[^\\]\'
STRING      \"([^\"\n\r]|(\\.))*\"
%%
{INTEGER}       { return TOKEN_TYPE_INT; }
{FLOAT}         { return TOKEN_TYPE_FLOAT; }
{STRING}        { return TOKEN_TYPE_STRING; }
{CHARACTER}     { return TOKEN_TYPE_CHAR; }
"true"          { return TOKEN_TYPE_TRUE; }
"false"         { return TOKEN_TYPE_FALSE; }
"null"          { return TOKEN_NULL; }
{WHITESPACE}    { /* Ignorar */ }
"++"            { return TOKEN_INCREMENT; }
"+"             { return TOKEN_PLUS; }
"--"            { return TOKEN_DECREMENT; }
"-"             { return TOKEN_MINUS; }
"*"             { return TOKEN_MULTIPLICATION; }
"/"             { return TOKEN_DIVISION; }
"%"             { return TOKEN_MODULE; }
"="             { return TOKEN_ASSIGN; }
"System.out.println" { return TOKEN_SOUT; }
{IDENTIFIER}    { return TOKEN_IDENTIFIER; }
%%
int main(int argc, char** argv) {
    if (argc > 1) {
        yyin = fopen(argv[1], "r");
        if (!yyin) {
            printf("Error: No se pudo abrir %s\n", argv[1]);
            return 1;
        }
    }
    
    int token;
    printf("=== ANÁLISIS LÉXICO ===\n");
    
    while ((token = yylex()) != 0) {
        printf("Token: %s, Texto: '%s', Línea: %d\n", 
               token_name(token), yytext, yyline);
    }
    
    printf("=== FIN ===\n");
    
    if (yyin && yyin != stdin) {
        fclose(yyin);
    }
    
    return 0;
}