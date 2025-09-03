//
// Created by lightdemon on 2/09/25.
//

#ifndef PROCESADOR_EXPRESION_H
#define PROCESADOR_EXPRESION_H

#include "node_processor.h"
#include "ast.h"

// ===== ENUM PARA TIPOS DE EXPRESIONES =====
typedef enum {
    EXPR_TYPE_UNKNOWN = 0,

    // EXPRESIONES BINARIAS
    EXPR_TYPE_SUMA,
    EXPR_TYPE_RESTA,
    EXPR_TYPE_MULTIPLICACION,
    EXPR_TYPE_DIVISION,
    EXPR_TYPE_MODULO,
    EXPR_TYPE_IGUAL,
    EXPR_TYPE_DIFERENTE,
    EXPR_TYPE_MAYOR,
    EXPR_TYPE_MENOR,
    EXPR_TYPE_MAYOR_IGUAL,
    EXPR_TYPE_MENOR_IGUAL,
    EXPR_TYPE_AND_LOGICO,
    EXPR_TYPE_OR_LOGICO,

    // EXPRESIONES UNARIAS
    EXPR_TYPE_NEGACION_ARITMETICA,
    EXPR_TYPE_POSITIVO_EXPLICITO,
    EXPR_TYPE_NEGACION_LOGICA,
    EXPR_TYPE_PRE_INCREMENTO,
    EXPR_TYPE_PRE_DECREMENTO,

    // EXPRESIONES POSTFIJO
    EXPR_TYPE_POST_INCREMENTO,
    EXPR_TYPE_POST_DECREMENTO,

    // TIPOS DE NODOS
    EXPR_TYPE_DATO,
    EXPR_TYPE_IDENTIFIER,
    EXPR_TYPE_PARENTESIS,
    EXPR_TYPE_NULL_LITERAL,
    EXPR_TYPE_INT_LITERAL,
    EXPR_TYPE_FLOAT_LITERAL,
    EXPR_TYPE_STRING_LITERAL,
    EXPR_TYPE_CHAR_LITERAL,
    EXPR_TYPE_BOOLEAN_LITERAL,

    // AVANZADOS (para futuro)
    EXPR_TYPE_LLAMADA_FUNCION,
    EXPR_TYPE_ACCESO_ARRAY,
    EXPR_TYPE_ACCESO_PROPIEDAD,
    EXPR_TYPE_EMBEBIDA
} ExpressionProcessorType;

// ===== FUNCIONES PRINCIPALES =====
char* process_expresion_node(NodeProcessorContext* context, ASTNode* node);
ExpressionProcessorType get_expression_processor_type(const char* node_type, const char* operator_value);
int is_expresion_node(const char* node_type);

// ===== FORWARD DECLARATIONS =====
extern char* process_suma_node(NodeProcessorContext* context, ASTNode* node);
extern char* process_resta_node(NodeProcessorContext* context, ASTNode* node);
extern char* process_multiplicacion_node(NodeProcessorContext* context, ASTNode* node);
extern char* obtener_valor_desde_nodo(ASTNode* node, NodeProcessorContext* context);

#endif // PROCESADOR_EXPRESION_H