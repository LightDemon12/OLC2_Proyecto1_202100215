%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../Headers/error_manager.h"
#include "../../Headers/ast.h"
#include "../../Headers/builder_program.h"
#include "../../Headers/builder_bloque_main.h"
#include "../../Headers/builder_instrucciones.h"
#include "../../Headers/builder_sout.h"
#include "../../Headers/builder_declaraciones.h" 
#include "../../Headers/builder_tipos_datos.h" 
#include "../../Headers/builder_expresion.h"
#include "../../Headers/builder_asignacion.h" 
#include "../../Headers/builder_if.h" 


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
    char* str; 
}


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
%token <str> TOKEN_IDENTIFIER    // id
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
%token <str> TOKEN_TYPE_INT     // numero
%token <str> TOKEN_TYPE_FLOAT   // decimal
%token <str> TOKEN_TYPE_STRING  // cadena
%token <str> TOKEN_TYPE_CHAR    // char
%token <str> TOKEN_TYPE_TRUE    // verdadero
%token <str> TOKEN_TYPE_FALSE   // false

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

%type <node> program bloque_main instrucciones instruccion sout declaraciones tipo dato lista_declaraciones lista_declaracion
%type <node> expresion operador_asignacion asignacion_compuesta sentencia_if if_simple if_con_else if_con_else_if lista_else_if else_if

%%

program:
    bloque_main
    {
        ast_root = build_program_node($1, @1.first_line, @1.first_column);
        $$ = ast_root;
    }
    ;

bloque_main:
    TOKEN_PUBLIC TOKEN_STATIC TOKEN_VOID TOKEN_MAIN TOKEN_PAREN_LEFT TOKEN_PAREN_RIGHT TOKEN_BRACE_LEFT instrucciones TOKEN_BRACE_RIGHT
    {
        $$ = build_bloque_main_node($8, @1.first_line, @1.first_column);
    }
    ;

instrucciones:
    instruccion
    {
        $$ = build_instrucciones_single($1, @1.first_line, @1.first_column);
    }
    | instrucciones instruccion
    {
        $$ = build_instrucciones_add($1, $2);
    }
    ;

instruccion:
    sout
    {
        $$ = $1;
    }
    | declaraciones
    {
        $$ = $1;
    }
    | asignacion_compuesta
    {
        $$ = $1;
    }
    | expresion
    {
        $$ = $1;
    }
    | sentencia_if  
    {
        $$ = $1;
    }
    ;

expresion:
    /* OPERADORES ARITMÉTICOS */
    expresion TOKEN_PLUS expresion
    {
        $$ = build_expresion_binaria($1, "+", $3, @2.first_line, @2.first_column);
    }
    | expresion TOKEN_MINUS expresion
    {
        $$ = build_expresion_binaria($1, "-", $3, @2.first_line, @2.first_column);
    }
    | expresion TOKEN_MULTIPLICATION expresion
    {
        $$ = build_expresion_binaria($1, "*", $3, @2.first_line, @2.first_column);
    }
    | expresion TOKEN_DIVISION expresion
    {
        $$ = build_expresion_binaria($1, "/", $3, @2.first_line, @2.first_column);
    }
    | expresion TOKEN_MODULE expresion
    {
        $$ = build_expresion_binaria($1, "%", $3, @2.first_line, @2.first_column);
    }
    
    /* OPERADORES DE COMPARACIÓN */
    | expresion TOKEN_EQUAL expresion
    {
        $$ = build_expresion_binaria($1, "==", $3, @2.first_line, @2.first_column);
    }
    | expresion TOKEN_UNEQUAL expresion
    {
        $$ = build_expresion_binaria($1, "!=", $3, @2.first_line, @2.first_column);
    }
    
    /* OPERADORES RELACIONALES */
    | expresion TOKEN_GREATER expresion
    {
        $$ = build_expresion_binaria($1, ">", $3, @2.first_line, @2.first_column);
    }
    | expresion TOKEN_LESS expresion
    {
        $$ = build_expresion_binaria($1, "<", $3, @2.first_line, @2.first_column);
    }
    | expresion TOKEN_GREATER_EQUAL expresion
    {
        $$ = build_expresion_binaria($1, ">=", $3, @2.first_line, @2.first_column);
    }
    | expresion TOKEN_LESS_EQUAL expresion
    {
        $$ = build_expresion_binaria($1, "<=", $3, @2.first_line, @2.first_column);
    }
    
    /* OPERADORES LÓGICOS */
    | expresion TOKEN_AND expresion
    {
        $$ = build_expresion_binaria($1, "&&", $3, @2.first_line, @2.first_column);
    }
    | expresion TOKEN_OR expresion
    {
        $$ = build_expresion_binaria($1, "||", $3, @2.first_line, @2.first_column);
    }
    
    /* OPERADOR UNARIO */
    | TOKEN_NOT expresion
    {
        $$ = build_expresion_unaria("!", $2, @1.first_line, @1.first_column);
    }
    
    /* PARÉNTESIS */
    | TOKEN_PAREN_LEFT expresion TOKEN_PAREN_RIGHT
    {
        $$ = build_expresion_parentesis($2, @1.first_line, @1.first_column);
    }
    
    /* DATOS PRIMITIVOS */
    | dato
    {
        $$ = $1;
    }
    /* IDENTIFICADORES */
    | TOKEN_IDENTIFIER
    {
        $$ = build_identifier_node($1, @1.first_line, @1.first_column);
    }
    ;


declaraciones:
    tipo TOKEN_IDENTIFIER TOKEN_ASSIGN expresion TOKEN_SEMICOLON
    {
        $$ = build_declaracion_single($1, $2, $4, @1.first_line, @1.first_column);
    }
    | tipo lista_declaraciones TOKEN_SEMICOLON
    {
        $$ = build_declaracion_multiple($1, $2, @1.first_line, @1.first_column);
    }
    | tipo TOKEN_IDENTIFIER TOKEN_SEMICOLON
    {
        $$ = build_declaracion_sin_inicializacion($1, $2, @1.first_line, @1.first_column);
    }
    ;

asignacion_compuesta:
    TOKEN_IDENTIFIER operador_asignacion expresion TOKEN_SEMICOLON
    {
        $$ = build_asignacion_compuesta($1, $2, $3, @1.first_line, @1.first_column);
    }
    ;


operador_asignacion:
    TOKEN_PLUS_ASSIGN
    {
        $$ = build_operador_asignacion("+=", @1.first_line, @1.first_column);
    }
    | TOKEN_MINUS_ASSIGN
    {
        $$ = build_operador_asignacion("-=", @1.first_line, @1.first_column);
    }
    | TOKEN_MULT_ASSIGN
    {
        $$ = build_operador_asignacion("*=", @1.first_line, @1.first_column);
    }
    | TOKEN_DIV_ASSIGN
    {
        $$ = build_operador_asignacion("/=", @1.first_line, @1.first_column);
    }
    | TOKEN_MOD_ASSIGN
    {
        $$ = build_operador_asignacion("%=", @1.first_line, @1.first_column);
    }
    | TOKEN_AND_ASSIGN
    {
        $$ = build_operador_asignacion("&=", @1.first_line, @1.first_column);
    }
    | TOKEN_OR_ASSIGN
    {
        $$ = build_operador_asignacion("|=", @1.first_line, @1.first_column);
    }
    | TOKEN_XOR_ASSIGN
    {
        $$ = build_operador_asignacion("^=", @1.first_line, @1.first_column);
    }
    | TOKEN_SHIFT_LEFT_ASSIGN
    {
        $$ = build_operador_asignacion("<<=", @1.first_line, @1.first_column);
    }
    | TOKEN_SHIFT_RIGHT_ASSIGN
    {
        $$ = build_operador_asignacion(">>=", @1.first_line, @1.first_column);
    }
    | TOKEN_ASSIGN
    {
        $$ = build_operador_asignacion("=", @1.first_line, @1.first_column);
    }
    ;


tipo:
    TOKEN_STRING
    {
        $$ = build_tipo_node("string", @1.first_line, @1.first_column);
    }
    | TOKEN_INT 
    {
        $$ = build_tipo_node("int", @1.first_line, @1.first_column);
    }
    | TOKEN_FLOAT  
    {
        $$ = build_tipo_node("float", @1.first_line, @1.first_column);
    }
    | TOKEN_CHAR
    {
        $$ = build_tipo_node("char", @1.first_line, @1.first_column);
    }
    | TOKEN_BOOLEAN
    {
        $$ = build_tipo_node("boolean", @1.first_line, @1.first_column);
    }
    ;

dato:
    TOKEN_TYPE_STRING
    {
        $$ = build_dato_string($1, @1.first_line, @1.first_column);
    }
    | TOKEN_TYPE_INT  
    {
        $$ = build_dato_int($1, @1.first_line, @1.first_column);
    }
    | TOKEN_TYPE_FLOAT  
    {
        $$ = build_dato_float($1, @1.first_line, @1.first_column);
    }
    | TOKEN_TYPE_CHAR
    {
        $$ = build_dato_char($1, @1.first_line, @1.first_column);
    }
    | TOKEN_TYPE_TRUE
    {
        $$ = build_dato_boolean($1, @1.first_line, @1.first_column);
    }
    | TOKEN_TYPE_FALSE
    {
        $$ = build_dato_boolean($1, @1.first_line, @1.first_column);
    }
    ;

lista_declaraciones:
    lista_declaracion
    {
        $$ = build_lista_declaraciones_single($1, @1.first_line, @1.first_column);
    }
    | lista_declaraciones TOKEN_COMMA lista_declaracion
    {
        $$ = build_lista_declaraciones_add($1, $3);
    }
    ;

lista_declaracion:
    TOKEN_IDENTIFIER TOKEN_ASSIGN expresion
    {
        $$ = build_lista_declaracion_node($1, $3, @1.first_line, @1.first_column);
    }
    ;

sout:
    TOKEN_SOUT TOKEN_PAREN_LEFT expresion TOKEN_PAREN_RIGHT TOKEN_SEMICOLON
    {
        $$ = build_sout_node($3, @1.first_line, @1.first_column);
    }
    ;

sentencia_if:
    if_simple
    {
        $$ = $1;
    }
    | if_con_else
    {
        $$ = $1;
    }
    | if_con_else_if
    {
        $$ = $1;
    }
    ;

if_simple:
    TOKEN_IF TOKEN_PAREN_LEFT expresion TOKEN_PAREN_RIGHT TOKEN_BRACE_LEFT instrucciones TOKEN_BRACE_RIGHT
    {
        $$ = build_if_simple($3, $6, @1.first_line, @1.first_column);
    }
    ;

if_con_else:
    TOKEN_IF TOKEN_PAREN_LEFT expresion TOKEN_PAREN_RIGHT TOKEN_BRACE_LEFT instrucciones TOKEN_BRACE_RIGHT TOKEN_ELSE TOKEN_BRACE_LEFT instrucciones TOKEN_BRACE_RIGHT
    {
        $$ = build_if_con_else($3, $6, $10, @1.first_line, @1.first_column);
    }
    ;

if_con_else_if:
    TOKEN_IF TOKEN_PAREN_LEFT expresion TOKEN_PAREN_RIGHT TOKEN_BRACE_LEFT instrucciones TOKEN_BRACE_RIGHT lista_else_if TOKEN_ELSE TOKEN_BRACE_LEFT instrucciones TOKEN_BRACE_RIGHT
    {
        $$ = build_if_con_else_if($3, $6, $8, $11, @1.first_line, @1.first_column);
    }
    ;

lista_else_if:
    lista_else_if else_if
    {
        $$ = build_lista_else_if_add($1, $2);
    }
    | else_if
    {
        $$ = build_lista_else_if_single($1, @1.first_line, @1.first_column);
    }
    ;

else_if:
    TOKEN_ELSE TOKEN_IF TOKEN_PAREN_LEFT expresion TOKEN_PAREN_RIGHT TOKEN_BRACE_LEFT instrucciones TOKEN_BRACE_RIGHT
    {
        $$ = build_else_if($4, $7, @1.first_line, @1.first_column);
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