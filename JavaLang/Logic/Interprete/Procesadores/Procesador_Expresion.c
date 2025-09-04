#include "../../../Headers/Procesador_Expresion.h"
#include "../../../Headers/Procesador_Suma.h"
#include "../../../Headers/Procesador_Division.h"
#include "../../../Headers/Procesador_Resta.h"
#include "../../../Headers/Procesador_Multiplicacion.h"
#include "../../../Headers/node_utils.h"
#include "../../../Headers/Procesador_Logico.h"
#include "../../../Headers/Procesador_Comparacion.h"
#include "../../../Headers/Procesador_Modulo.h"
#include "../../../Headers/globals.h"
#include "../../Headers/mainview.h"
#include "../../../Headers/Procesador_Incremento.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ===== FUNCIÓN PARA DETERMINAR EL TIPO DE EXPRESIÓN =====
ExpressionProcessorType get_expression_processor_type(const char* node_type, const char* operator_value) {
    if (!node_type) return EXPR_TYPE_UNKNOWN;

    // ===== EXPRESIONES BINARIAS =====
    if (strcmp(node_type, "EXPRESION_BINARIA") == 0) {
        if (!operator_value) return EXPR_TYPE_UNKNOWN;
        
        // Operadores aritméticos
        if (strcmp(operator_value, "+") == 0) return EXPR_TYPE_SUMA;
        if (strcmp(operator_value, "-") == 0) return EXPR_TYPE_RESTA;
        if (strcmp(operator_value, "*") == 0) return EXPR_TYPE_MULTIPLICACION;
        if (strcmp(operator_value, "/") == 0) return EXPR_TYPE_DIVISION;
        if (strcmp(operator_value, "%") == 0) return EXPR_TYPE_MODULO;
        
        // Operadores de comparación
        if (strcmp(operator_value, "==") == 0) return EXPR_TYPE_IGUAL;
        if (strcmp(operator_value, "!=") == 0) return EXPR_TYPE_DIFERENTE;
        if (strcmp(operator_value, ">") == 0) return EXPR_TYPE_MAYOR;
        if (strcmp(operator_value, "<") == 0) return EXPR_TYPE_MENOR;
        if (strcmp(operator_value, ">=") == 0) return EXPR_TYPE_MAYOR_IGUAL;
        if (strcmp(operator_value, "<=") == 0) return EXPR_TYPE_MENOR_IGUAL;
        
        // Operadores lógicos
        if (strcmp(operator_value, "&&") == 0) return EXPR_TYPE_AND_LOGICO;
        if (strcmp(operator_value, "||") == 0) return EXPR_TYPE_OR_LOGICO;
        
        return EXPR_TYPE_UNKNOWN;
    }

    // ===== EXPRESIONES UNARIAS =====
    if (strcmp(node_type, "EXPRESION_UNARIA") == 0) {
        if (!operator_value) return EXPR_TYPE_UNKNOWN;
        
        if (strcmp(operator_value, "-") == 0) return EXPR_TYPE_NEGACION_ARITMETICA;
        if (strcmp(operator_value, "+") == 0) return EXPR_TYPE_POSITIVO_EXPLICITO;
        if (strcmp(operator_value, "!") == 0) return EXPR_TYPE_NEGACION_LOGICA;
        if (strcmp(operator_value, "++") == 0) return EXPR_TYPE_PRE_INCREMENTO;
        if (strcmp(operator_value, "--") == 0) return EXPR_TYPE_PRE_DECREMENTO;
        
        return EXPR_TYPE_UNKNOWN;
    }

    // ===== EXPRESIONES POSTFIJO =====
    if (strcmp(node_type, "EXPRESION_POSTFIJO") == 0) {
        if (!operator_value) return EXPR_TYPE_UNKNOWN;
        
        if (strcmp(operator_value, "++") == 0) return EXPR_TYPE_POST_INCREMENTO;
        if (strcmp(operator_value, "--") == 0) return EXPR_TYPE_POST_DECREMENTO;
        
        return EXPR_TYPE_UNKNOWN;
    }

    // ===== TIPOS DE NODOS SIMPLES =====
    if (strcmp(node_type, "DATO") == 0) return EXPR_TYPE_DATO;
    if (strcmp(node_type, "IDENTIFIER") == 0) return EXPR_TYPE_IDENTIFIER;
    if (strcmp(node_type, "EXPRESION_PARENTESIS") == 0) return EXPR_TYPE_PARENTESIS;
    if (strcmp(node_type, "NULL_LITERAL") == 0) return EXPR_TYPE_NULL_LITERAL;
    if (strcmp(node_type, "INT_LITERAL") == 0) return EXPR_TYPE_INT_LITERAL;
    if (strcmp(node_type, "FLOAT_LITERAL") == 0) return EXPR_TYPE_FLOAT_LITERAL;
    if (strcmp(node_type, "STRING_LITERAL") == 0) return EXPR_TYPE_STRING_LITERAL;
    if (strcmp(node_type, "CHAR_LITERAL") == 0) return EXPR_TYPE_CHAR_LITERAL;
    if (strcmp(node_type, "BOOLEAN_LITERAL") == 0) return EXPR_TYPE_BOOLEAN_LITERAL;

    // ===== TIPOS AVANZADOS (FUTURO) =====
    if (strcmp(node_type, "LLAMADA_FUNCION") == 0) return EXPR_TYPE_LLAMADA_FUNCION;
    if (strcmp(node_type, "ARRAY_ACCESO_MULTIDIMENSIONAL") == 0) return EXPR_TYPE_ACCESO_ARRAY;
    if (strcmp(node_type, "EXPRESION_ACCESO") == 0) return EXPR_TYPE_ACCESO_PROPIEDAD;
    
    // Embebidas
    if (strcmp(node_type, "PARSEINT_EMBEBIDA") == 0 ||
        strcmp(node_type, "PARSEFLOAT_EMBEBIDA") == 0 ||
        strcmp(node_type, "PARSEDOUBLE_EMBEBIDA") == 0 ||
        strcmp(node_type, "VALUEOF_EMBEBIDA") == 0 ||
        strcmp(node_type, "INDEXOF_EMBEBIDA") == 0 ||
        strcmp(node_type, "LENGTH_EMBEBIDA") == 0 ||
        strcmp(node_type, "ADD_EMBEBIDA") == 0 ||
        strcmp(node_type, "JOIN_EMBEBIDA") == 0) {
        return EXPR_TYPE_EMBEBIDA;
    }

    return EXPR_TYPE_UNKNOWN;
}

// ===== PROCESADOR PRINCIPAL OPTIMIZADO =====
char* process_expresion_node(NodeProcessorContext* context, ASTNode* node) {
    if (!context || !node) {
        printf("ERROR PROCESADOR_EXPRESION: Contexto o nodo NULL\n");
        return NULL;
    }

    if (context->modo_debug) {
        printf("DEBUG PROCESADOR_EXPRESION: Procesando '%s' en línea %d\n",
               node->type, node->line);
    }

    // Determinar tipo de expresión
    ExpressionProcessorType expr_type = get_expression_processor_type(node->type, node->value);

    // ===== SWITCH OPTIMIZADO =====
    switch (expr_type) {
        // ===== OPERADORES ARITMÉTICOS IMPLEMENTADOS =====
        case EXPR_TYPE_SUMA:
            if (context->modo_debug) {
                printf("DEBUG PROCESADOR_EXPRESION: → Delegando suma a Procesador_Suma\n");
            }
            return process_suma_node(context, node);

        case EXPR_TYPE_RESTA:
            if (context->modo_debug) {
                printf("DEBUG PROCESADOR_EXPRESION: → Delegando resta a Procesador_Resta\n");
            }
            return process_resta_node(context, node);

        case EXPR_TYPE_MULTIPLICACION:
            if (context->modo_debug) {
                printf("DEBUG PROCESADOR_EXPRESION: → Delegando multiplicación a Procesador_Multiplicacion\n");
            }
            return process_multiplicacion_node(context, node);

        // ===== OPERADORES ARITMÉTICOS NO IMPLEMENTADOS =====
        case EXPR_TYPE_DIVISION:
            // ===== IMPLEMENTAR DIVISIÓN =====
            if (context->modo_debug) {
                printf("DEBUG PROCESADOR_EXPRESION: → Delegando división a Procesador_Division\n");
            }
            return process_division_node(context, node);

        case EXPR_TYPE_MODULO:
            if (context->modo_debug) {
                printf("DEBUG PROCESADOR_EXPRESION: → Delegando módulo a Procesador_Modulo\n");
            }
            return process_modulo_node(context, node);

        // ===== OPERADORES DE COMPARACIÓN NO IMPLEMENTADOS =====
        case EXPR_TYPE_IGUAL:
            if (context->modo_debug) {
                printf("DEBUG PROCESADOR_EXPRESION: → Delegando igualdad a Procesador_Comparacion\n");
            }
            return process_comparacion_node(context, node);

        case EXPR_TYPE_DIFERENTE:
            if (context->modo_debug) {
                printf("DEBUG PROCESADOR_EXPRESION: → Delegando desigualdad a Procesador_Comparacion\n");
            }
            return process_comparacion_node(context, node);

        case EXPR_TYPE_MAYOR:
        case EXPR_TYPE_MENOR:
        case EXPR_TYPE_MAYOR_IGUAL:
        case EXPR_TYPE_MENOR_IGUAL:
            if (context->modo_debug) {
                printf("DEBUG PROCESADOR_EXPRESION: → Delegando comparación relacional a Procesador_Comparacion\n");
            }
            return process_comparacion_node(context, node);

        // ===== OPERADORES LÓGICOS NO IMPLEMENTADOS =====
        case EXPR_TYPE_AND_LOGICO:
            if (context->modo_debug) {
                printf("DEBUG PROCESADOR_EXPRESION: → Delegando AND lógico a Procesador_Logico\n");
            }
            return process_logico_binario_node(context, node);
        case EXPR_TYPE_OR_LOGICO:
            if (context->modo_debug) {
                printf("DEBUG PROCESADOR_EXPRESION: → Delegando OR lógico a Procesador_Logico\n");
            }
            return process_logico_binario_node(context, node);

        // ===== OPERADORES UNARIOS IMPLEMENTADOS =====
        case EXPR_TYPE_NEGACION_ARITMETICA:
            if (context->modo_debug) {
                printf("DEBUG PROCESADOR_EXPRESION: → Procesando negación unaria '-'\n");
            }
            return obtener_valor_desde_nodo(node, context);

        case EXPR_TYPE_POSITIVO_EXPLICITO:
            if (context->modo_debug) {
                printf("DEBUG PROCESADOR_EXPRESION: → Procesando positivo unario '+'\n");
            }
            return obtener_valor_desde_nodo(node, context);
        case EXPR_TYPE_PRE_INCREMENTO:
            if (context->modo_debug) {
                printf("DEBUG PROCESADOR_EXPRESION: → Delegando pre-incremento a Procesador_Incremento\n");
            }
            return process_pre_incremento_node(context, node);

        case EXPR_TYPE_PRE_DECREMENTO:
            if (context->modo_debug) {
                printf("DEBUG PROCESADOR_EXPRESION: → Delegando pre-decremento a Procesador_Incremento\n");
            }
            return process_pre_decremento_node(context, node);

        case EXPR_TYPE_POST_INCREMENTO:
            if (context->modo_debug) {
                printf("DEBUG PROCESADOR_EXPRESION: → Delegando post-incremento a Procesador_Incremento\n");
            }
            return process_post_incremento_node(context, node);

        case EXPR_TYPE_POST_DECREMENTO:
            if (context->modo_debug) {
                printf("DEBUG PROCESADOR_EXPRESION: → Delegando post-decremento a Procesador_Incremento\n");
            }
            return process_post_decremento_node(context, node);
        // ===== OPERADORES UNARIOS NO IMPLEMENTADOS =====
        case EXPR_TYPE_NEGACION_LOGICA:
            if (context->modo_debug) {
                printf("DEBUG PROCESADOR_EXPRESION: → Delegando negación lógica (!) a Procesador_Logico\n");
            }
            return process_logico_unario_node(context, node);

        // ===== TIPOS DE DATOS IMPLEMENTADOS =====
        case EXPR_TYPE_DATO:
            // Los DATO son valores literales, extraer su valor directo
            if (node->child_count > 0 && node->children[0]) {
                ASTNode* literal = node->children[0];
                if (literal->value) {
                    char* resultado = malloc(strlen(literal->value) + 1);
                    strcpy(resultado, literal->value);

                    if (context->modo_debug) {
                        printf("DEBUG PROCESADOR_EXPRESION: → Literal extraído: '%s'\n", resultado);
                    }
                    return resultado;
                }
            }
            return NULL;

        case EXPR_TYPE_IDENTIFIER:
            // ===== BUSCAR EN TABLA DE SÍMBOLOS =====
            if (node->value && context->tabla_simbolos) {
                Simbolo* simbolo = buscar_simbolo(context->tabla_simbolos, node->value);

                if (simbolo) {
                    // Incrementar uso del símbolo
                    incrementar_uso_simbolo(context->tabla_simbolos, node->value);

                    // Retornar VALOR de la variable, no su nombre
                    char* resultado = malloc(strlen(simbolo->valor) + 1);
                    strcpy(resultado, simbolo->valor);

                    if (context->modo_debug) {
                        printf("DEBUG PROCESADOR_EXPRESION: → Variable '%s' = '%s' (tipo: %s)\n",
                               node->value, simbolo->valor, tipo_dato_to_string(simbolo->tipo_dato));
                    }
                    return resultado;
                } else {
                    // ===== ERROR SEMÁNTICO: VARIABLE NO DECLARADA =====
                    char error_msg[256];
                    snprintf(error_msg, sizeof(error_msg), "Variable '%s' no ha sido declarada", node->value);

                    // Obtener scope actual
                    const char* scope_actual = "global";
                    if (context->scope_actual && context->scope_actual->nombre) {
                        scope_actual = context->scope_actual->nombre;
                    } else if (context->tabla_simbolos && context->tabla_simbolos->ambito_actual) {
                        scope_actual = context->tabla_simbolos->ambito_actual;
                    }

                    // Registrar error semántico
                    if (global_error_manager) {
                        error_manager_add_semantico(global_error_manager,
                                                  node->line, node->column,
                                                  error_msg, node->value,
                                                  scope_actual);
                    }

                    printf("ERROR PROCESADOR_EXPRESION: %s\n", error_msg);
                    return NULL;
                }
            } else {
                printf("ERROR PROCESADOR_EXPRESION: Identificador sin valor o tabla de símbolos nula\n");
                return NULL;
            }

        case EXPR_TYPE_PARENTESIS:
            // Para expresiones con paréntesis, evaluar la expresión interna
            if (node->child_count > 0 && node->children[0]) {
                if (context->modo_debug) {
                    printf("DEBUG PROCESADOR_EXPRESION: → Procesando expresión entre paréntesis\n");
                }
                return process_expresion_node(context, node->children[0]);
            }
            printf("ERROR PROCESADOR_EXPRESION: Expresión entre paréntesis sin contenido\n");
            return NULL;

        case EXPR_TYPE_NULL_LITERAL:
            if (context->modo_debug) {
                printf("DEBUG PROCESADOR_EXPRESION: → Literal null detectado\n");
            }
            return strdup("null");

        case EXPR_TYPE_INT_LITERAL:
        case EXPR_TYPE_FLOAT_LITERAL:
        case EXPR_TYPE_STRING_LITERAL:
        case EXPR_TYPE_CHAR_LITERAL:
        case EXPR_TYPE_BOOLEAN_LITERAL:
            // ===== LITERALES DIRECTOS =====
            if (node->value) {
                char* resultado = malloc(strlen(node->value) + 1);
                strcpy(resultado, node->value);

                if (context->modo_debug) {
                    printf("DEBUG PROCESADOR_EXPRESION: → Literal directo: '%s'\n", resultado);
                }
                return resultado;
            }
            printf("ERROR PROCESADOR_EXPRESION: Literal sin valor\n");
            return NULL;

        // ===== TIPOS AVANZADOS NO IMPLEMENTADOS =====
        case EXPR_TYPE_LLAMADA_FUNCION:
            printf("ERROR PROCESADOR_EXPRESION: Llamadas a funciones no implementadas\n");
            return NULL;

        case EXPR_TYPE_ACCESO_ARRAY:
            printf("ERROR PROCESADOR_EXPRESION: Acceso a arrays no implementado\n");
            return NULL;

        case EXPR_TYPE_ACCESO_PROPIEDAD:
            printf("ERROR PROCESADOR_EXPRESION: Acceso a propiedades no implementado\n");
            return NULL;

        case EXPR_TYPE_EMBEBIDA:
            printf("ERROR PROCESADOR_EXPRESION: Funciones embebidas no implementadas\n");
            return NULL;

        // ===== TIPO DESCONOCIDO =====
        case EXPR_TYPE_UNKNOWN:
        default:
            printf("ERROR PROCESADOR_EXPRESION: Tipo de expresión no implementado: '%s'\n", node->type);
            return NULL;
    }
}

// ===== FUNCIÓN AUXILIAR =====
int is_expresion_node(const char* node_type) {
    if (!node_type) return 0;

    ExpressionProcessorType type = get_expression_processor_type(node_type, NULL);
    return (type != EXPR_TYPE_UNKNOWN);
}