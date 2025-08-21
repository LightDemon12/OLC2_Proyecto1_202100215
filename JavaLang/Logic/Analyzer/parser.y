%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../Headers/error_manager.h"

/*DECLARACIONES MÍNIMAS */
extern int yylex();
extern int yylineno;
extern char* yytext;
extern FILE* yyin;

ErrorManager* global_error_manager = NULL;

/*FUNCIÓN DE ERROR SIMPLE */
void yyerror(const char* s);
%}
%expect-rr 0
%define parse.error verbose

/*PALABRAS RESERVADAS */
%token TOKEN_INT          // int
%token TOKEN_FLOAT        // float  
%token TOKEN_STRING       // string
%token TOKEN_CHAR         // char
%token TOKEN_BOOLEAN      // boolean
%token TOKEN_EQUALS       // equals
%token TOKEN_NEW          // new
%token TOKEN_PUBLIC       // public
%token TOKEN_STATIC       // static
%token TOKEN_VOID         // void
%token TOKEN_MAIN         // main
/*VALOR NULO */
%token TOKEN_NULL         // null
/*IDENTIFICADORES */
%token TOKEN_IDENTIFIER   // id
/*OPERACIONES ARITMÉTICAS */
%token TOKEN_PLUS         // +
%token TOKEN_MINUS        // -
%token TOKEN_MULTIPLICATION // *
%token TOKEN_DIVISION     // /
%token TOKEN_MODULE       // %
/*OPERADORES DE ASIGNACIÓN */
%token TOKEN_PLUS_ASSIGN  // +=
%token TOKEN_MINUS_ASSIGN // -=
%token TOKEN_MULT_ASSIGN  // *=
%token TOKEN_DIV_ASSIGN   // /=
%token TOKEN_MOD_ASSIGN   // %=
%token TOKEN_AND_ASSIGN   // &=
%token TOKEN_OR_ASSIGN    // |=
%token TOKEN_XOR_ASSIGN   // ^=
%token TOKEN_SHIFT_LEFT_ASSIGN  // <<=
%token TOKEN_SHIFT_RIGHT_ASSIGN // >>=
%token TOKEN_ASSIGN       // =
/*OPERACIONES DE COMPARACIÓN */
%token TOKEN_EQUAL        // ==
%token TOKEN_UNEQUAL      // !=
/*RELACIONES */
%token TOKEN_GREATER      // >
%token TOKEN_LESS         // <
%token TOKEN_GREATER_EQUAL // >=
%token TOKEN_LESS_EQUAL   // <=
/*OPERADORES LÓGICOS */
%token TOKEN_AND          // &&
%token TOKEN_OR           // ||
%token TOKEN_NOT          // !
/*AGRUPADORES */
%token TOKEN_PAREN_LEFT   // (
%token TOKEN_PAREN_RIGHT  // )
%token TOKEN_SEMICOLON    // ;
%token TOKEN_DOT          // .
%token TOKEN_COMMA        // ,
%token TOKEN_BRACE_LEFT   // {
%token TOKEN_BRACE_RIGHT  // }
%token TOKEN_BRACKET_LEFT // [
%token TOKEN_BRACKET_RIGHT // ]
%token TOKEN_QUOTE_DOUBLE // " "
%token TOKEN_QUOTE_SINGLE // ' '
/*SENTENCIAS DE CONTROL DE FLUJO */
%token TOKEN_IF           // if
%token TOKEN_ELSE         // else
%token TOKEN_SWITCH       // switch
%token TOKEN_CASE         // case
%token TOKEN_WHILE        // while
%token TOKEN_DO           // do
%token TOKEN_FOR          // for
/*SENTENCIAS DE TRANSFERENCIA */
%token TOKEN_BREAK        // break
%token TOKEN_CONTINUE     // continue
%token TOKEN_RETURN       // return
/*FUNCIONES EMBEBIDAS */
%token TOKEN_SOUT         // System.out.println
%token TOKEN_PARSEINT     // Integer.parseInt
%token TOKEN_PARSEFLOAT   // Float.parseFloat
%token TOKEN_PARSEDOUBLE  // Double.parseDouble
%token TOKEN_VALUEOF      // String.valueOf
%token TOKEN_STRINGJOIN   // String.join
%token TOKEN_INDEXOF      // Arrays.indexOf
%token TOKEN_LENGTH       // .length
%token TOKEN_ADD          // .add
/*SECUENCIAS DE ESCAPE */
%token TOKEN_ESCAPE       // secuencias de escape
/*OPERADORES UNARIOS */
%token TOKEN_INCREMENT    // ++
%token TOKEN_DECREMENT    // --
/*ESPECIALES */
%token TOKEN_EOF          // fin archivo
%token TOKEN_ERROR        // error
/*TIPOS DE DATOS PRIMITIVOS */
%token TOKEN_TYPE_INT     // numero
%token TOKEN_TYPE_FLOAT   // decimal
%token TOKEN_TYPE_STRING  // cadena
%token TOKEN_TYPE_CHAR    // char
%token TOKEN_TYPE_TRUE    // verdadero
%token TOKEN_TYPE_FALSE   // false
%%

/* GRAMATICA SUPER SIMPLE CON DEBUG */
program:
    TOKEN_SEMICOLON
    {
        printf("PARSER: Punto y coma detectado\n");
    }
    | /* vacio */
    {
        printf("PARSER: Entrada vacia\n");
    }
    ;

%%

void yyerror(const char* s) {
    printf("ERROR SINTACTICO en linea %d: %s (token actual: '%s')\n",
           yylineno, s, yytext ? yytext : "NULL");
    
    /* AGREGAR ERROR SINTACTICO AL MANAGER GLOBAL */
    if (!global_error_manager) {
        global_error_manager = error_manager_create();
    }
    
    /* MENSAJE GENÉRICO Y SIMPLE */
    char simple_message[256];
    char token_display[64];
    
    /* FORMATEAR TOKEN PARA MOSTRAR */
    if (yytext && strlen(yytext) > 0) {
        snprintf(token_display, sizeof(token_display), "'%s'", yytext);
    } else {
        strcpy(token_display, "desconocido");
    }
    
    /* MENSAJE SIMPLE Y GENÉRICO */
    snprintf(simple_message, sizeof(simple_message),
            "Error de sintaxis en el token %s", token_display);
    
    error_manager_add_sintactico(global_error_manager, yylineno, 0, simple_message, yytext);
}

int parser_main(int argc, char** argv) {
    printf("=== PARSER MINIMO ===\n");

    if (argc > 1) {
        yyin = fopen(argv[1], "r");
        if (!yyin) {
            printf("Error: No se pudo abrir %s\n", argv[1]);
            return 1;
        }
        printf("DEBUG: Archivo %s abierto correctamente\n", argv[1]);
    } else {
        printf("DEBUG: Leyendo desde stdin\n");
    }

    printf("DEBUG: Iniciando analisis sintactico...\n");
    int result = yyparse();
    printf("DEBUG: yyparse() termino con codigo: %d\n", result);

    /* IMPRIMIR ERRORES ACUMULADOS EN FORMATO PARSEABLE */
    if (global_error_manager && error_manager_has_errors(global_error_manager)) {
        printf("=== ERRORES DETECTADOS ===\n");
        ErrorNode* current = global_error_manager->head;
        int count = 1;
        
        while (current) {
            printf("[ERROR_%s] %d|%d|%s|%s\n",
                   error_type_name(current->type),
                   current->line,
                   current->column,
                   current->message ? current->message : "",
                   current->token_text ? current->token_text : "");
            current = current->next;
            count++;
        }
        printf("=== FIN ERRORES ===\n");
    }

    if (result == 0) {
        printf("EXITO: Analisis completado\n");
    } else {
        printf("FALLO: Error en analisis\n");
    }

    if (yyin && yyin != stdin) {
        fclose(yyin);
        printf("DEBUG: Archivo cerrado\n");
    }

    return result;
}

#ifdef STANDALONE_PARSER
int main(int argc, char** argv) {
    return parser_main(argc, argv);
}
#endif
