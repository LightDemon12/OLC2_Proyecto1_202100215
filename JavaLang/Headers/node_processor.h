#ifndef NODE_PROCESSOR_H
#define NODE_PROCESSOR_H

#include "ast.h"
#include "Tabla_Simbolos.h"

struct MainView;
typedef struct MainView MainView;

//   TIPOS DE SCOPE SEGÚN TU PARSER
typedef enum {
    SCOPE_GLOBAL,
    SCOPE_MAIN,
    SCOPE_FUNCION,
    SCOPE_IF,
    SCOPE_ELSE,
    SCOPE_WHILE,
    SCOPE_FOR,
    SCOPE_DO_WHILE,
    SCOPE_SWITCH,
    SCOPE_BLOQUE
} ScopeType;

//   NODO DEL STACK DE SCOPES
typedef struct ScopeNode {
    ScopeType tipo;
    char nombre[64];
    int nivel;
    int linea_inicio;
    struct ScopeNode* parent;
} ScopeNode;

/**
 * Contexto para el procesamiento de nodos CON STACK DE SCOPES
 */
typedef struct {
    TablaSimbolos* tabla_simbolos;  //   USAR TU SISTEMA EXISTENTE
    int linea_actual;
    int modo_debug;
    MainView* mainview;
    
    //   AGREGAR SISTEMA DE SCOPES
    ScopeNode* scope_actual;        // Stack de scopes
    int scope_counter;              // Para nombres únicos
} NodeProcessorContext;

/**
 * Enumerar tipos de nodos que procesamos
 */
typedef enum {
    // DECLARACIONES
    NODE_TYPE_DECLARACION_CON_INICIALIZACION,
    NODE_TYPE_DECLARACION_MULTIPLE,
    NODE_TYPE_DECLARACION_SIN_INICIALIZACION,

    // ASIGNACIONES
    NODE_TYPE_ASIGNACION_COMPUESTA,
    NODE_TYPE_ASIGNACION_COMPUESTA_ARRAY_1D,
    NODE_TYPE_ASIGNACION_COMPUESTA_ARRAY_MULTI,

    // ARRAYS Y VECTORES
    NODE_TYPE_VECTOR_NEW,
    NODE_TYPE_VECTOR_INICIALIZADO,
    NODE_TYPE_ARRAY_MULTIDIMENSIONAL_NEW,
    NODE_TYPE_ARRAY_MULTIDIMENSIONAL_INICIALIZADO,
    NODE_TYPE_ARRAY_ACCESO_1D,
    NODE_TYPE_ARRAY_ACCESO_MULTIDIMENSIONAL,
    NODE_TYPE_ARRAY_ASIGNACION_1D,
    NODE_TYPE_ARRAY_ASIGNACION_MULTIDIMENSIONAL,
    NODE_TYPE_ARRAY_ASIGNACION_ELEMENTO,

    // FUNCIONES
    NODE_TYPE_FUNCION,
    NODE_TYPE_PARAMETRO_SIMPLE,
    NODE_TYPE_PARAMETRO_ARRAY,
    NODE_TYPE_LLAMADA_FUNCION,
    NODE_TYPE_ARGUMENTOS,

    // ESTRUCTURAS DE CONTROL
    NODE_TYPE_IF_SIMPLE,
    NODE_TYPE_IF_CON_ELSE,
    NODE_TYPE_IF_CON_ELSE_IF,
    NODE_TYPE_IF_SIMPLE_SIN_LLAVES,
    NODE_TYPE_IF_CON_ELSE_SIN_LLAVES,
    NODE_TYPE_SWITCH,
    NODE_TYPE_CASE,
    NODE_TYPE_CASE_CON_DEFAULT,

    // CICLOS
    NODE_TYPE_WHILE,
    NODE_TYPE_DO_WHILE,
    NODE_TYPE_FOR,
    NODE_TYPE_FOR_EACH,
    NODE_TYPE_INICIALIZACION_FOR_DECLARACION,
    NODE_TYPE_INICIALIZACION_FOR_ASIGNACION,
    NODE_TYPE_INICIALIZACION_FOR_EXPRESION,

    // SENTENCIAS DE CONTROL
    NODE_TYPE_BREAK,
    NODE_TYPE_CONTINUE,
    NODE_TYPE_RETURN_CON_VALOR,
    NODE_TYPE_RETURN_VACIO,

    // FUNCIONES EMBEBIDAS
    NODE_TYPE_PARSEINT,
    NODE_TYPE_PARSEFLOAT,
    NODE_TYPE_PARSEDOUBLE,
    NODE_TYPE_VALUEOF,
    NODE_TYPE_INDEXOF,
    NODE_TYPE_LENGTH,
    NODE_TYPE_ADD,
    NODE_TYPE_JOIN,
    NODE_TYPE_SOUT,
    NODE_TYPE_EQUALS,

    // EXPRESIONES
    NODE_TYPE_EXPRESION_BINARIA,
    NODE_TYPE_EXPRESION_UNARIA,
    NODE_TYPE_EXPRESION_POSTFIJO,
    NODE_TYPE_EXPRESION_PARENTESIS,
    NODE_TYPE_EXPRESION_ACCESO,

    // OTROS NODOS ESTRUCTURALES
    NODE_TYPE_PROGRAM,
    NODE_TYPE_BLOQUE_MAIN,
    NODE_TYPE_BLOQUE_FUNCION,
    NODE_TYPE_INSTRUCCIONES,
    NODE_TYPE_SCOPE,
    NODE_TYPE_TIPO,
    NODE_TYPE_DATO,
    NODE_TYPE_IDENTIFIER,
    NODE_TYPE_LISTA_DECLARACIONES,
    NODE_TYPE_LISTA_EXPRESIONES,
    NODE_TYPE_CONTENIDO_VECTOR,
    NODE_TYPE_BRACKETS,
    NODE_TYPE_BRACKETS_NEW,
    NODE_TYPE_BRACKETS_INDICES,
    NODE_TYPE_BRACE_BLOCK,
    NODE_TYPE_BRACE_ELEMENTS,
    NODE_TYPE_PARAMETROS,
    NODE_TYPE_CUERPO_FUNCION,
    NODE_TYPE_LISTA_CASE,
    NODE_TYPE_LISTA_ELSE_IF,
    NODE_TYPE_OPERADOR_ASIGNACION,
    NODE_TYPE_CAST,
    NODE_TYPE_CONSTANTE_CON_INICIALIZACION,
    NODE_TYPE_CONSTANTE_MULTIPLE,
    NODE_TYPE_UNKNOWN
} NodeProcessorType;

/**
 *   FUNCIONES PARA MANEJO DE SCOPES (COMBINACIÓN A+B)
 */
ScopeNode* crear_scope_node(ScopeType tipo, const char* nombre, int linea);
void entrar_scope_combinado(NodeProcessorContext* context, ScopeType tipo, const char* nombre, int linea);
void salir_scope_combinado(NodeProcessorContext* context, int linea);
void liberar_scope_node(ScopeNode* scope);

/**
 *   FUNCIONES PARA BÚSQUEDA EN SCOPES
 */
Simbolo* buscar_simbolo_en_scopes_combinado(NodeProcessorContext* context, const char* id);
int insertar_simbolo_en_scope_combinado(NodeProcessorContext* context, Simbolo simbolo);
void debug_mostrar_stack_scopes_combinado(NodeProcessorContext* context);

/**
 * Función principal: procesar cualquier nodo del AST
 */
int process_ast_node(NodeProcessorContext* context, ASTNode* node);

/**
 * Determinar el tipo de procesamiento para un nodo
 */
NodeProcessorType get_node_processor_type(const char* node_type);

/**
 * Funciones helper para output dual
 */
void procesador_debug_output(NodeProcessorContext* context, const char* message);
void procesador_error_output(NodeProcessorContext* context, const char* message);

#endif // NODE_PROCESSOR_H