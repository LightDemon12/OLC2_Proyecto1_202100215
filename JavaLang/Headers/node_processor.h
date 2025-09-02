//
// Created by lightdemon on 2/09/25.
//

#ifndef NODE_PROCESSOR_H
#define NODE_PROCESSOR_H

#include "ast.h"
#include "Tabla_Simbolos.h"

struct MainView;
typedef struct MainView MainView;
/**
 * Contexto para el procesamiento de nodos
 */
typedef struct {
    TablaSimbolos* tabla_simbolos;
    int linea_actual;
    int modo_debug;
    MainView* mainview;
} NodeProcessorContext;

/**
 * Enumerar tipos de nodos que procesamos
 */
typedef enum {
    // DECLARACIONES
    NODE_TYPE_DECLARACION_CON_INICIALIZACION,      // tipo id = expresion;
    NODE_TYPE_DECLARACION_MULTIPLE,                // tipo id1 = val1, id2 = val2;
    NODE_TYPE_DECLARACION_SIN_INICIALIZACION,      // tipo id;

    // ASIGNACIONES
    NODE_TYPE_ASIGNACION_COMPUESTA,                // id += expresion;
    NODE_TYPE_ASIGNACION_COMPUESTA_ARRAY_1D,       // id[index] += valor;
    NODE_TYPE_ASIGNACION_COMPUESTA_ARRAY_MULTI,    // id[i][j] += valor;

    // ARRAYS Y VECTORES
    NODE_TYPE_VECTOR_NEW,                          // tipo[] id = new tipo[size];
    NODE_TYPE_VECTOR_INICIALIZADO,                 // tipo[] id = {val1, val2};
    NODE_TYPE_ARRAY_MULTIDIMENSIONAL_NEW,          // tipo[][] id = new tipo[x][y];
    NODE_TYPE_ARRAY_MULTIDIMENSIONAL_INICIALIZADO, // tipo[][] id = {{}, {}};
    NODE_TYPE_ARRAY_ACCESO_1D,                     // id[index]
    NODE_TYPE_ARRAY_ACCESO_MULTIDIMENSIONAL,       // id[i][j][k]
    NODE_TYPE_ARRAY_ASIGNACION_1D,                 // tipo id = array[index];
    NODE_TYPE_ARRAY_ASIGNACION_MULTIDIMENSIONAL,   // tipo id = array[i][j];
    NODE_TYPE_ARRAY_ASIGNACION_ELEMENTO,           // array[i][j] = valor;

    // FUNCIONES
    NODE_TYPE_FUNCION,                             // tipo funcion(params) { }
    NODE_TYPE_PARAMETRO_SIMPLE,                    // tipo id
    NODE_TYPE_PARAMETRO_ARRAY,                     // tipo[] id
    NODE_TYPE_LLAMADA_FUNCION,                     // funcion(args)
    NODE_TYPE_ARGUMENTOS,                          // lista de argumentos

    // ESTRUCTURAS DE CONTROL
    NODE_TYPE_IF_SIMPLE,                          // if (cond) { }
    NODE_TYPE_IF_CON_ELSE,                        // if (cond) { } else { }
    NODE_TYPE_IF_CON_ELSE_IF,                     // if (cond) { } else if { } else { }
    NODE_TYPE_IF_SIMPLE_SIN_LLAVES,               // if (cond) instruccion;
    NODE_TYPE_IF_CON_ELSE_SIN_LLAVES,             // if (cond) inst; else inst;
    NODE_TYPE_SWITCH,                             // switch (expr) { case: }
    NODE_TYPE_CASE,                               // case valor: instrucciones break;
    NODE_TYPE_CASE_CON_DEFAULT,                   // case + default

    // CICLOS
    NODE_TYPE_WHILE,                              // while (cond) { }
    NODE_TYPE_DO_WHILE,                           // do { } while (cond);
    NODE_TYPE_FOR,                                // for (init; cond; update) { }
    NODE_TYPE_FOR_EACH,                           // for (tipo var : array) { }
    NODE_TYPE_INICIALIZACION_FOR_DECLARACION,     // tipo id = valor (en for)
    NODE_TYPE_INICIALIZACION_FOR_ASIGNACION,      // id = valor (en for)
    NODE_TYPE_INICIALIZACION_FOR_EXPRESION,       // expresion (en for)

    // SENTENCIAS DE CONTROL
    NODE_TYPE_BREAK,                              // break;
    NODE_TYPE_CONTINUE,                           // continue;
    NODE_TYPE_RETURN_CON_VALOR,                   // return expresion;
    NODE_TYPE_RETURN_VACIO,                       // return;

    // FUNCIONES EMBEBIDAS
    NODE_TYPE_PARSEINT,                           // Integer.parseInt()
    NODE_TYPE_PARSEFLOAT,                         // Float.parseFloat()
    NODE_TYPE_PARSEDOUBLE,                        // Double.parseDouble()
    NODE_TYPE_VALUEOF,                            // String.valueOf()
    NODE_TYPE_INDEXOF,                            // Arrays.indexOf()
    NODE_TYPE_LENGTH,                             // expr.length
    NODE_TYPE_ADD,                                // expr.add()
    NODE_TYPE_JOIN,                               // String.join()
    NODE_TYPE_SOUT,                               // System.out.println()
    NODE_TYPE_EQUALS,                             // expr.equals()

    // EXPRESIONES
    NODE_TYPE_EXPRESION_BINARIA,                  // a + b, a == b, etc.
    NODE_TYPE_EXPRESION_UNARIA,                   // !a, ++a, --a
    NODE_TYPE_EXPRESION_POSTFIJO,                 // a++, a--
    NODE_TYPE_EXPRESION_PARENTESIS,               // (expresion)
    NODE_TYPE_EXPRESION_ACCESO,                   // obj.propiedad


    // OTROS NODOS ESTRUCTURALES (no generan símbolos)
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

    NODE_TYPE_UNKNOWN
} NodeProcessorType;

/**
 * Función principal: procesar cualquier nodo del AST
 */
int process_ast_node(NodeProcessorContext* context, ASTNode* node);

/**
 * Determinar el tipo de procesamiento para un nodo usando switch
 */
NodeProcessorType get_node_processor_type(const char* node_type);

/**
 * Funciones helper para output dual
 */
void procesador_debug_output(NodeProcessorContext* context, const char* message);
void procesador_error_output(NodeProcessorContext* context, const char* message);

#endif // NODE_PROCESSOR_Hv