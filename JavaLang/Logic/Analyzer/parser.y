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
#include "../../Headers/builder_sentencias.h"  
#include "../../Headers/builder_switch.h"      
#include "../../Headers/builder_scope.h" 
#include "../../Headers/builder_ciclos.h" 
#include "../../Headers/builder_datos.h" 
#include "../../Headers/builder_vectores.h" 
#include "../../Headers/builder_matrices.h" 
#include "../../Headers/builder_arrays_acceso.h" 
#include "../../Headers/builder_arrays_multidimensional.h"
#include "../../Headers/builder_funciones.h"
#include "../../Headers/builder_expresion_arrays.h"
#include "../../Headers/builder_llamadas_funciones.h"
#include "../../Headers/builder_embebidas.h" 

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
%token TOKEN_DOUBLE       // double
%token TOKEN_LONG         // long
%token TOKEN_SHORT       // short
%token TOKEN_BYTE        // byte
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
%token TOKEN_COLON        // :  
/*SENTENCIAS DE CONTROL DE FLUJO */
%token TOKEN_IF           // if
%token TOKEN_ELSE         // else
%token TOKEN_SWITCH       // switch
%token TOKEN_CASE         // case
%token TOKEN_DEFAULT      // default
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
/* Funciones embebidas (alta precedencia) */
%right TOKEN_PARSEINT TOKEN_PARSEFLOAT TOKEN_PARSEDOUBLE TOKEN_VALUEOF TOKEN_STRINGJOIN TOKEN_INDEXOF TOKEN_LENGTH TOKEN_ADD

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
%type <node> sentencias sentencia_switch lista_case case  ciclo_while  ciclo_do ciclo_for inicializacion_for actualizar_for 
%type <node> arrays  contenido_vector  lista_expresiones arrays_acceso arrays_asignacion brackets_indices
%type <node>  brackets brackets_new TOKEN_brace_block brace_elements brace_element  funcion bloque_funcion parametros
%type <node>  parametro  cuerpo_funcion elemento_funcion argumentos lista_else_if_sin_llaves else_if_sin_llaves
%type <node>  embebidas parseint_embebida parsedouble_embebida parsefloat_embebida valueof_embebida indexof_embebida
%type <node> length_embebida add_embebida join_embebida

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
    | expresion TOKEN_SEMICOLON
    {
        $$ = $1;
    }
    | sentencia_if  
    {
        $$ = $1;
    }
    | sentencia_switch 
    {
        $$ = $1;
    }
    | ciclo_while      
    {
        $$ = $1;
    }
    | ciclo_do         
    {
        $$ = $1;
    }
    | ciclo_for        
    {
        $$ = $1;
    }
    | arrays
    {
        $$ = $1;
    }
    | arrays_acceso
    {
        $$ = $1;
    }
    | arrays_asignacion
    {
        $$ = $1;
    }
    | funcion         
    {
        $$ = $1;
    }
    | sentencias
    {
        $$ = $1;
    }
    | embebidas
    {
        $$ = $1;
    }
    ;

expresion:
    embebidas
    {
        $$ = $1;
    }
    /* OPERADORES ARITMÉTICOS */
    |expresion TOKEN_PLUS expresion
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
    
    /* OPERADOR UNARIO PREFIJO */
    | TOKEN_NOT expresion
    {
        $$ = build_expresion_unaria("!", $2, @1.first_line, @1.first_column);
    }
    | TOKEN_INCREMENT expresion 
    {
        $$ = build_expresion_unaria("++", $2, @1.first_line, @1.first_column);
    }
    | TOKEN_DECREMENT expresion 
    {
        $$ = build_expresion_unaria("--", $2, @1.first_line, @1.first_column);
    }
    
    /* OPERADORES POSTFIJO */
    | TOKEN_IDENTIFIER TOKEN_INCREMENT 
    {
        ASTNode* id_node = build_identifier($1, @1.first_line, @1.first_column);
        $$ = build_expresion_postfijo(id_node, "++", @2.first_line, @2.first_column);
    }
    | TOKEN_IDENTIFIER TOKEN_DECREMENT 
    {
        ASTNode* id_node = build_identifier($1, @1.first_line, @1.first_column);
        $$ = build_expresion_postfijo(id_node, "--", @2.first_line, @2.first_column);
    }
    
    /* LLAMADAS A FUNCIONES - NUEVO */
    | TOKEN_IDENTIFIER TOKEN_PAREN_LEFT argumentos TOKEN_PAREN_RIGHT
    {
        $$ = build_llamada_funcion($1, $3, @1.first_line, @1.first_column);
    }
    
    /* ACCESO A ARRAYS MULTIDIMENSIONAL */
    | TOKEN_IDENTIFIER brackets_indices
    {
        $$ = build_array_acceso_multidimensional($1, $2, @1.first_line, @1.first_column);
    }
    
    /* ACCESO A PROPIEDADES/MÉTODOS */
    | TOKEN_IDENTIFIER TOKEN_DOT expresion
    {
        ASTNode* id_node = build_identifier($1, @1.first_line, @1.first_column);
        $$ = build_expresion_acceso(id_node, $3, @2.first_line, @2.first_column);
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
        $$ = build_identifier($1, @1.first_line, @1.first_column);
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
    // ASIGNACIÓN COMPUESTA A ARRAY 1D - NUEVO
    | TOKEN_IDENTIFIER TOKEN_BRACKET_LEFT expresion TOKEN_BRACKET_RIGHT operador_asignacion expresion TOKEN_SEMICOLON
    {
        $$ = build_asignacion_compuesta_array_1d($1, $3, $5, $6, @1.first_line, @1.first_column);
    }
    // ASIGNACIÓN COMPUESTA A ARRAY MULTIDIMENSIONAL - NUEVO
    | TOKEN_IDENTIFIER brackets_indices operador_asignacion expresion TOKEN_SEMICOLON
    {
        $$ = build_asignacion_compuesta_array_multidimensional($1, $2, $3, $4, @1.first_line, @1.first_column);
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
    | TOKEN_DOUBLE
    {
        $$ = build_tipo_node("double", @1.first_line, @1.first_column);
    }
    | TOKEN_LONG
    {
        $$ = build_tipo_node("long", @1.first_line, @1.first_column);
    }
    | TOKEN_SHORT
    {
        $$ = build_tipo_node("short", @1.first_line, @1.first_column);
    }
    | TOKEN_BYTE
    {
        $$ = build_tipo_node("byte", @1.first_line, @1.first_column);
    }
    | TOKEN_VOID
    {
        $$ = build_tipo_node("void", @1.first_line, @1.first_column);
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
    | TOKEN_NULL
    {
        $$ = build_dato_null(@1.first_line, @1.first_column);
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
    // IF con llaves (múltiples instrucciones)
    TOKEN_IF TOKEN_PAREN_LEFT expresion TOKEN_PAREN_RIGHT TOKEN_BRACE_LEFT instrucciones TOKEN_BRACE_RIGHT
    {
        $$ = build_if_simple($3, $6, @1.first_line, @1.first_column);
    }
    // IF sin llaves (instrucción única) - NUEVO
    | TOKEN_IF TOKEN_PAREN_LEFT expresion TOKEN_PAREN_RIGHT instruccion
    {
        $$ = build_if_simple_sin_llaves($3, $5, @1.first_line, @1.first_column);
    }
    ;

if_con_else:
    // IF-ELSE con llaves (múltiples instrucciones)
    TOKEN_IF TOKEN_PAREN_LEFT expresion TOKEN_PAREN_RIGHT TOKEN_BRACE_LEFT instrucciones TOKEN_BRACE_RIGHT TOKEN_ELSE TOKEN_BRACE_LEFT instrucciones TOKEN_BRACE_RIGHT
    {
        $$ = build_if_con_else($3, $6, $10, @1.first_line, @1.first_column);
    }
    // IF con llaves, ELSE sin llaves - NUEVO
    | TOKEN_IF TOKEN_PAREN_LEFT expresion TOKEN_PAREN_RIGHT TOKEN_BRACE_LEFT instrucciones TOKEN_BRACE_RIGHT TOKEN_ELSE instruccion
    {
        $$ = build_if_con_else_mixto_1($3, $6, $9, @1.first_line, @1.first_column);
    }
    // IF sin llaves, ELSE con llaves - NUEVO
    | TOKEN_IF TOKEN_PAREN_LEFT expresion TOKEN_PAREN_RIGHT instruccion TOKEN_ELSE TOKEN_BRACE_LEFT instrucciones TOKEN_BRACE_RIGHT
    {
        $$ = build_if_con_else_mixto_2($3, $5, $8, @1.first_line, @1.first_column);
    }
    // IF-ELSE sin llaves (instrucciones únicas) - NUEVO
    | TOKEN_IF TOKEN_PAREN_LEFT expresion TOKEN_PAREN_RIGHT instruccion TOKEN_ELSE instruccion
    {
        $$ = build_if_con_else_sin_llaves($3, $5, $7, @1.first_line, @1.first_column);
    }
    ;

if_con_else_if:
    // IF-ELSE IF-ELSE con llaves (múltiples instrucciones)
    TOKEN_IF TOKEN_PAREN_LEFT expresion TOKEN_PAREN_RIGHT TOKEN_BRACE_LEFT instrucciones TOKEN_BRACE_RIGHT lista_else_if TOKEN_ELSE TOKEN_BRACE_LEFT instrucciones TOKEN_BRACE_RIGHT
    {
        $$ = build_if_con_else_if($3, $6, $8, $11, @1.first_line, @1.first_column);
    }
    // IF-ELSE IF-ELSE sin llaves (instrucciones únicas) - NUEVO
    | TOKEN_IF TOKEN_PAREN_LEFT expresion TOKEN_PAREN_RIGHT instruccion lista_else_if_sin_llaves TOKEN_ELSE instruccion
    {
        $$ = build_if_con_else_if_sin_llaves($3, $5, $6, $8, @1.first_line, @1.first_column);
    }
    // IF-ELSE IF sin llaves (sin else final) - NUEVO
    | TOKEN_IF TOKEN_PAREN_LEFT expresion TOKEN_PAREN_RIGHT instruccion lista_else_if_sin_llaves
    {
        $$ = build_if_con_else_if_sin_else_final($3, $5, $6, @1.first_line, @1.first_column);
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

// Nueva lista para else if sin llaves
lista_else_if_sin_llaves:
    lista_else_if_sin_llaves else_if_sin_llaves
    {
        $$ = build_lista_else_if_sin_llaves_add($1, $2);
    }
    | else_if_sin_llaves
    {
        $$ = build_lista_else_if_sin_llaves_single($1, @1.first_line, @1.first_column);
    }
    ;

else_if:
    // ELSE IF con llaves (múltiples instrucciones)
    TOKEN_ELSE TOKEN_IF TOKEN_PAREN_LEFT expresion TOKEN_PAREN_RIGHT TOKEN_BRACE_LEFT instrucciones TOKEN_BRACE_RIGHT
    {
        $$ = build_else_if($4, $7, @1.first_line, @1.first_column);
    }
    ;

// Nueva regla para else if sin llaves
else_if_sin_llaves:
    TOKEN_ELSE TOKEN_IF TOKEN_PAREN_LEFT expresion TOKEN_PAREN_RIGHT instruccion
    {
        $$ = build_else_if_sin_llaves($4, $6, @1.first_line, @1.first_column);
    }
    ;

sentencias:
    TOKEN_BREAK TOKEN_SEMICOLON
    {
        $$ = build_break(@1.first_line, @1.first_column);
    }
    | TOKEN_CONTINUE TOKEN_SEMICOLON
    {
        $$ = build_continue(@1.first_line, @1.first_column);
    }
    | TOKEN_RETURN expresion TOKEN_SEMICOLON
    {
        $$ = build_return_con_valor($2, @1.first_line, @1.first_column);
    }
    | TOKEN_RETURN TOKEN_SEMICOLON
    {
        $$ = build_return_vacio(@1.first_line, @1.first_column);
    }
    ;

sentencia_switch:
    TOKEN_SWITCH TOKEN_PAREN_LEFT expresion TOKEN_PAREN_RIGHT TOKEN_BRACE_LEFT lista_case TOKEN_BRACE_RIGHT
    {
        $$ = build_switch($3, $6, @1.first_line, @1.first_column);
    }
    ;

lista_case:
    lista_case case
    {
        $$ = build_lista_casos_add($1, $2);
    }
    | case
    {
        $$ = build_lista_casos_single($1, @1.first_line, @1.first_column);
    }
    ;

case:
    TOKEN_CASE dato TOKEN_COLON instrucciones sentencias
    {
        $$ = build_caso($2, $4, $5, @1.first_line, @1.first_column);
    }
    | TOKEN_CASE dato TOKEN_COLON instrucciones sentencias TOKEN_DEFAULT TOKEN_COLON instrucciones
    {
        $$ = build_caso_con_default($2, $4, $5, $8, @1.first_line, @1.first_column);
    }
    ;

ciclo_while:
    TOKEN_WHILE TOKEN_PAREN_LEFT expresion TOKEN_PAREN_RIGHT TOKEN_BRACE_LEFT instrucciones TOKEN_BRACE_RIGHT
    {
        $$ = build_while($3, $6, @1.first_line, @1.first_column);
    }
    ;

ciclo_do:
    TOKEN_DO TOKEN_BRACE_LEFT instrucciones TOKEN_BRACE_RIGHT TOKEN_WHILE TOKEN_PAREN_LEFT expresion TOKEN_PAREN_RIGHT TOKEN_SEMICOLON
    {
        $$ = build_do_while($3, $7, @1.first_line, @1.first_column);
    }
    ;

ciclo_for:
    TOKEN_FOR TOKEN_PAREN_LEFT inicializacion_for TOKEN_SEMICOLON expresion TOKEN_SEMICOLON actualizar_for TOKEN_PAREN_RIGHT TOKEN_BRACE_LEFT instrucciones TOKEN_BRACE_RIGHT
    {
        $$ = build_for($3, $5, $7, $10, @1.first_line, @1.first_column);  
    }
    | TOKEN_FOR TOKEN_PAREN_LEFT tipo TOKEN_IDENTIFIER TOKEN_COLON TOKEN_IDENTIFIER TOKEN_PAREN_RIGHT TOKEN_BRACE_LEFT instrucciones TOKEN_BRACE_RIGHT
    {
        $$ = build_for_each($3, $4, $6, $9, @1.first_line, @1.first_column);
    }
    ;

inicializacion_for:
    tipo TOKEN_IDENTIFIER TOKEN_ASSIGN expresion
    {
        $$ = build_inicializacion_for_declaracion($1, $2, $4, @1.first_line, @1.first_column);
    }
    | TOKEN_IDENTIFIER operador_asignacion expresion
    {
        $$ = build_inicializacion_for_asignacion($1, $2, $3, @1.first_line, @1.first_column);
    }
    | expresion
    {
        $$ = build_inicializacion_for_expresion($1, @1.first_line, @1.first_column);
    }
    | /* vacío */
    {
        $$ = build_inicializacion_for_vacia(0, 0);
    }
    ;
    
actualizar_for:
    expresion
    {
        $$ = build_actualizacion_for($1, @1.first_line, @1.first_column);
    }
    | /* vacío */
    {
        $$ = build_actualizacion_for_vacia(0, 0);  // ← USAR 0, 0 en lugar de @1
    }
    ;

arrays:
    // VECTOR CON NEW (1D)
    tipo TOKEN_BRACKET_LEFT TOKEN_BRACKET_RIGHT TOKEN_IDENTIFIER TOKEN_ASSIGN TOKEN_NEW tipo TOKEN_BRACKET_LEFT expresion TOKEN_BRACKET_RIGHT TOKEN_SEMICOLON
    {
        $$ = build_vector_new($1, $4, $7, $9, @1.first_line, @1.first_column);
    }
    // VECTOR INICIALIZADO (1D)
    | tipo TOKEN_BRACKET_LEFT TOKEN_BRACKET_RIGHT TOKEN_IDENTIFIER TOKEN_ASSIGN TOKEN_BRACE_LEFT contenido_vector TOKEN_BRACE_RIGHT TOKEN_SEMICOLON
    {
        $$ = build_vector_inicializado($1, $4, $7, @1.first_line, @1.first_column);
    }
    // ARRAY MULTIDIMENSIONAL CON NEW (2D, 3D, 4D, nD)
    | tipo TOKEN_IDENTIFIER brackets TOKEN_ASSIGN TOKEN_NEW tipo brackets_new TOKEN_SEMICOLON
    {
        $$ = build_array_multidimensional_new($1, $3, $2, $6, $7, @1.first_line, @1.first_column);
        //                                          ^^^ $3 = brackets, $2 = TOKEN_IDENTIFIER
    }
    // ARRAY MULTIDIMENSIONAL INICIALIZADO (2D, 3D, 4D, nD)
    | tipo TOKEN_IDENTIFIER brackets TOKEN_ASSIGN TOKEN_brace_block TOKEN_SEMICOLON
    {
        $$ = build_array_multidimensional_inicializado($1, $3, $2, $5, @1.first_line, @1.first_column);
        //                                                   ^^^ $3 = brackets, $2 = TOKEN_IDENTIFIER
    }
    ;

contenido_vector:
    contenido_vector TOKEN_COMMA expresion
    {
        $$ = build_contenido_vector_add($1, $3);
    }
    | expresion
    {
        $$ = build_contenido_vector_single($1, @1.first_line, @1.first_column);
    }
    ;

lista_expresiones:
    lista_expresiones TOKEN_COMMA expresion
    {
        $$ = build_lista_expresiones_add($1, $3);
    }
    | expresion
    {
        $$ = build_lista_expresiones_single($1, @1.first_line, @1.first_column);
    }
    ;

arrays_acceso:
    TOKEN_IDENTIFIER TOKEN_BRACKET_LEFT expresion TOKEN_BRACKET_RIGHT TOKEN_SEMICOLON
    {
        $$ = build_array_acceso_1d($1, $3, @1.first_line, @1.first_column);
    }
    | TOKEN_IDENTIFIER brackets_indices TOKEN_SEMICOLON
    {
        $$ = build_array_acceso_multidimensional($1, $2, @1.first_line, @1.first_column);
    }
    ;

brackets_indices:
    brackets_indices TOKEN_BRACKET_LEFT expresion TOKEN_BRACKET_RIGHT
    {
        $$ = build_brackets_indices_add($1, $3);
    }
    | TOKEN_BRACKET_LEFT expresion TOKEN_BRACKET_RIGHT
    {
        $$ = build_brackets_indices_single($2, @1.first_line, @1.first_column);
    }
    ;

arrays_asignacion:
    tipo TOKEN_IDENTIFIER TOKEN_ASSIGN TOKEN_IDENTIFIER TOKEN_BRACKET_LEFT expresion TOKEN_BRACKET_RIGHT TOKEN_SEMICOLON
    {
        $$ = build_array_asignacion_1d($1, $2, $4, $6, @1.first_line, @1.first_column);
    }
    | tipo TOKEN_IDENTIFIER TOKEN_ASSIGN TOKEN_IDENTIFIER brackets_indices TOKEN_SEMICOLON
    {
        $$ = build_array_asignacion_multidimensional($1, $2, $4, $5, @1.first_line, @1.first_column);
    }
    | TOKEN_IDENTIFIER brackets_indices TOKEN_ASSIGN expresion TOKEN_SEMICOLON
    {
        $$ = build_array_asignacion_elemento($1, $2, $4, @1.first_line, @1.first_column);
    }
    ;


// Secuencia de corchetes para la declaración del tipo (ej: [][][])
brackets:
    brackets TOKEN_BRACKET_LEFT TOKEN_BRACKET_RIGHT
    {
        $$ = build_brackets_add($1, @2.first_line, @2.first_column);
    }
    | TOKEN_BRACKET_LEFT TOKEN_BRACKET_RIGHT
    {
        $$ = build_brackets_single(@1.first_line, @1.first_column);
    }
    ;

// Secuencia de corchetes con expresiones para la creación con 'new' (ej: [2][3][4])
brackets_new:
    brackets_new TOKEN_BRACKET_LEFT expresion TOKEN_BRACKET_RIGHT
    {
        $$ = build_brackets_new_add($1, $3);
    }
    | TOKEN_BRACKET_LEFT expresion TOKEN_BRACKET_RIGHT
    {
        $$ = build_brackets_new_single($2, @1.first_line, @1.first_column);
    }
    ;

// Bloque de inicialización con llaves anidadas
TOKEN_brace_block:
    TOKEN_BRACE_LEFT brace_elements TOKEN_BRACE_RIGHT
    {
        $$ = build_brace_block($2, @1.first_line, @1.first_column);
    }
    ;

// Elementos internos recursivos para llaves anidadas
brace_elements:
    brace_elements TOKEN_COMMA brace_element
    {
        $$ = build_brace_elements_add($1, $3);
    }
    | brace_element
    {
        $$ = build_brace_elements_single($1, @1.first_line, @1.first_column);
    }
    ;

brace_element:
    TOKEN_brace_block // una dimensión más interna
    {
        $$ = $1;
    }
    | lista_expresiones // dimensión más interna (los valores)
    {
        $$ = $1;
    }
    ;

funcion:
    tipo TOKEN_IDENTIFIER TOKEN_PAREN_LEFT parametros TOKEN_PAREN_RIGHT bloque_funcion
    {
        $$ = build_funcion($1, $2, $4, $6, @1.first_line, @1.first_column);
    }
    ;

// Permite cero, uno o más parámetros separados por comas
parametros:
    parametro
    {
        $$ = build_parametros_single($1, @1.first_line, @1.first_column);
    }
    | parametros TOKEN_COMMA parametro
    {
        $$ = build_parametros_add($1, $3);
    }
    | /* vacío */
    {
        $$ = build_parametros_vacio(0, 0);  // ← Usar 0, 0 como en otras reglas vacías
    }
    ;

// Permite tipo normal o tipo array de cualquier dimensión
parametro:
    tipo TOKEN_IDENTIFIER
    {
        $$ = build_parametro_simple($1, $2, @1.first_line, @1.first_column);
    }
    | tipo TOKEN_IDENTIFIER brackets
    {
        $$ = build_parametro_array($1, $2, $3, @1.first_line, @1.first_column);
    }
    ;

bloque_funcion:
    TOKEN_BRACE_LEFT cuerpo_funcion TOKEN_BRACE_RIGHT
    {
        $$ = build_bloque_funcion($2, @1.first_line, @1.first_column);
    }
    ;

cuerpo_funcion:
    cuerpo_funcion elemento_funcion
    {
        $$ = build_cuerpo_funcion_add($1, $2);
    }
    | elemento_funcion
    {
        $$ = build_cuerpo_funcion_single($1, @1.first_line, @1.first_column);
    }
    | /* vacío */
    {
        $$ = build_cuerpo_funcion_vacio(0, 0);
    }
    ;

elemento_funcion:
    instruccion
    {
        $$ = $1;
    }
    | sentencias
    {
        $$ = $1;
    }
    ;

// Argumentos de llamadas a funciones
argumentos:
    argumentos TOKEN_COMMA expresion
    {
        $$ = build_argumentos_add($1, $3);
    }
    | expresion
    {
        $$ = build_argumentos_single($1, @1.first_line, @1.first_column);
    }
    | /* vacío */
    {
        $$ = build_argumentos_vacio(0, 0);
    }
    ;

embebidas:
    parseint_embebida
    {
        $$ = $1;
    }
    | parsefloat_embebida
    {
        $$ = $1;
    }
    | parsedouble_embebida
    {
        $$ = $1;
    }
    | valueof_embebida
    {
        $$ = $1;
    }
    | indexof_embebida
    {
        $$ = $1;
    }
    |length_embebida
    {
        $$ = $1;
    }
    |add_embebida
    {
        $$ = $1;
    }
    | join_embebida
    {
        $$ = $1;
    }
    ;

// Embebida: Integer.parseInt(<expresion>)
parseint_embebida:
    TOKEN_PARSEINT TOKEN_PAREN_LEFT expresion TOKEN_PAREN_RIGHT
    {
        $$ = build_parseint_embebida($3, @1.first_line, @1.first_column);
    }
    // Variante con base/radix: Integer.parseInt(<expresion>, <expresion>)
    | TOKEN_PARSEINT TOKEN_PAREN_LEFT expresion TOKEN_COMMA expresion TOKEN_PAREN_RIGHT
    {
        $$ = build_parseint_embebida_radix($3, $5, @1.first_line, @1.first_column);
    }
    ;

parsedouble_embebida:
    TOKEN_PARSEDOUBLE TOKEN_PAREN_LEFT expresion TOKEN_PAREN_RIGHT
    {
        $$ = build_parsedouble_embebida($3, @1.first_line, @1.first_column);
    }
    ;

parsefloat_embebida:
    TOKEN_PARSEFLOAT TOKEN_PAREN_LEFT expresion TOKEN_PAREN_RIGHT
    {
        $$ = build_parsefloat_embebida($3, @1.first_line, @1.first_column);
    }
    ;

valueof_embebida:
    TOKEN_VALUEOF TOKEN_PAREN_LEFT expresion TOKEN_PAREN_RIGHT
    {
        $$ = build_valueof_embebida($3, @1.first_line, @1.first_column);
    }
    ;

indexof_embebida:
    TOKEN_INDEXOF TOKEN_PAREN_LEFT expresion TOKEN_COMMA expresion TOKEN_PAREN_RIGHT
    {
        $$ = build_indexof_embebida($3, $5, @1.first_line, @1.first_column);
    }
    ;

length_embebida:
    expresion TOKEN_LENGTH
    {
        $$ = build_length_embebida($1, @2.first_line, @2.first_column);
    }
    ;

add_embebida:
    expresion TOKEN_ADD TOKEN_PAREN_LEFT expresion TOKEN_PAREN_RIGHT
    {
        $$ = build_add_embebida($1, $4, @2.first_line, @2.first_column);
    }
    ;


join_embebida:
    TOKEN_STRINGJOIN TOKEN_PAREN_LEFT expresion TOKEN_COMMA contenido_vector TOKEN_PAREN_RIGHT
    {
        $$ = build_join_embebida($3, $5, @1.first_line, @1.first_column);
    }
    | TOKEN_STRINGJOIN TOKEN_PAREN_LEFT expresion TOKEN_COMMA expresion TOKEN_PAREN_RIGHT
    {
        $$ = build_join_embebida($3, $5, @1.first_line, @1.first_column);
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