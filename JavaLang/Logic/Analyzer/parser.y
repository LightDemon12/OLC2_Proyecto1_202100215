%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../Headers/error_manager.h"
#include "../../Headers/ast.h"

/* DECLARAR COMO EXTERNAS - NO DEFINIR AQUÍ */
extern ASTNode* ast_root;
extern ErrorManager* global_error_manager;

/* DECLARACIONES MÍNIMAS */
extern int yylex();
extern int yylineno;
extern char* yytext;
extern FILE* yyin;

/* FUNCIÓN DE ERROR */
void yyerror(const char* s);
%}

%code requires {
    typedef struct ASTNode ASTNode;
}

%union {
    ASTNode* node;
}

%type <node> program main_method instrucciones instruccion sout

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

/* PRECEDENCIA Y ASOCIATIVIDAD - De menor a mayor precedencia */

/*
Asignación (=, +=, -=, etc.)
OR lógico (||)
AND lógico (&&)
Igualdad (==, !=)
Relacionales (>, <, >=, <=)
Suma/Resta (+, -)
Multiplicación/División/Módulo (*, /, %)
Unarios (!, ++, --)
Paréntesis ((, ))
*/

/* Operadores de asignación (menor precedencia) */
%right TOKEN_ASSIGN TOKEN_PLUS_ASSIGN TOKEN_MINUS_ASSIGN TOKEN_MULT_ASSIGN TOKEN_DIV_ASSIGN TOKEN_MOD_ASSIGN TOKEN_AND_ASSIGN TOKEN_OR_ASSIGN TOKEN_XOR_ASSIGN TOKEN_SHIFT_LEFT_ASSIGN TOKEN_SHIFT_RIGHT_ASSIGN

/* Operadores lógicos OR */
%left TOKEN_OR           // ||

/* Operadores lógicos AND */
%left TOKEN_AND          // &&

/* Operadores de igualdad */
%left TOKEN_EQUAL TOKEN_UNEQUAL

/* Operadores relacionales */
%left TOKEN_GREATER TOKEN_LESS TOKEN_GREATER_EQUAL TOKEN_LESS_EQUAL

/* Operadores aritméticos de suma y resta */
%left TOKEN_PLUS TOKEN_MINUS

/* Operadores aritméticos de multiplicación, división y módulo */
%left TOKEN_MULTIPLICATION TOKEN_DIVISION TOKEN_MODULE

/* Operadores unarios (mayor precedencia) */
%right TOKEN_NOT TOKEN_INCREMENT TOKEN_DECREMENT

/* Agrupadores de expresiones */
%left TOKEN_PAREN_LEFT TOKEN_PAREN_RIGHT

%%

program:
    main_method
    {
        ast_root = create_node("PROGRAM", @1.first_line, @1.first_column);
        add_child(ast_root, $1);
        printf("AST construido exitosamente\n");
        $$ = ast_root;
    }
    ;

main_method:
    TOKEN_PUBLIC TOKEN_STATIC TOKEN_VOID TOKEN_MAIN TOKEN_PAREN_LEFT TOKEN_PAREN_RIGHT TOKEN_BRACE_LEFT instrucciones TOKEN_BRACE_RIGHT
    {
        $$ = create_node("MAIN_METHOD", @1.first_line, @1.first_column);
        add_child($$, $8);
    }
    ;

instrucciones:
    instruccion
    {
        $$ = create_node("INSTRUCTIONS", @1.first_line, @1.first_column);
        add_child($$, $1);
    }
    | instrucciones instruccion
    {
        $$ = $1;
        add_child($$, $2);
    }
    ;

instruccion:
    sout
    {
        $$ = $1;
    }
    ;

sout:
    TOKEN_SOUT TOKEN_PAREN_LEFT TOKEN_TYPE_STRING TOKEN_PAREN_RIGHT TOKEN_SEMICOLON
    {
        $$ = create_node("PRINT_STATEMENT", @1.first_line, @1.first_column);
        ASTNode* string_literal = create_node("STRING_LITERAL", @3.first_line, @3.first_column);
        set_value(string_literal, yytext);
        add_child($$, string_literal);
    }
    ;

%%

void yyerror(const char* s) {
    printf("ERROR SINTACTICO en linea %d: %s (token actual: '%s')\n",
           yylineno, s, yytext ? yytext : "NULL");
    
    if (!global_error_manager) {
        global_error_manager = error_manager_create();
    }
    
    char simple_message[256];
    char token_display[64];
    
    if (yytext && strlen(yytext) > 0) {
        snprintf(token_display, sizeof(token_display), "'%s'", yytext);
    } else {
        strcpy(token_display, "desconocido");
    }
    
    snprintf(simple_message, sizeof(simple_message),
            "Error de sintaxis en el token %s", token_display);
    
    error_manager_add_sintactico(global_error_manager, yylineno, 0, simple_message, yytext);
}

/* FUNCIÓN DEL PARSER PARA SER LLAMADA DESDE CONTROL.C */
int parse_java_code(const char* filename) {
    printf("=== ANALIZADOR LEXICO-SINTACTICO JAVA ===\n");

    if (filename) {
        yyin = fopen(filename, "r");
        if (!yyin) {
            printf("Error: No se pudo abrir %s\n", filename);
            return 1;
        }
        printf("DEBUG: Archivo %s abierto correctamente\n", filename);
    } else {
        printf("DEBUG: Leyendo desde stdin\n");
    }

    printf("DEBUG: Iniciando analisis sintactico...\n");
    int result = yyparse();
    printf("DEBUG: yyparse() termino con codigo: %d\n", result);

    /* IMPRIMIR EL AST SI SE GENERÓ CORRECTAMENTE */
    if (result == 0 && ast_root != NULL) {
        printf("\n=== ÁRBOL SINTÁCTICO ABSTRACTO ===\n");
        print_node(ast_root, 0);
        printf("=== FIN AST ===\n\n");
    }

    /* IMPRIMIR ERRORES */
    if (global_error_manager && error_manager_has_errors(global_error_manager)) {
        printf("=== ERRORES DETECTADOS ===\n");
        ErrorNode* current = global_error_manager->head;
        
        while (current) {
            printf("[ERROR_%s] %d|%d|%s|%s\n",
                   error_type_name(current->type),
                   current->line,
                   current->column,
                   current->message ? current->message : "",
                   current->token_text ? current->token_text : "");
            current = current->next;
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
    }

    return result;
}