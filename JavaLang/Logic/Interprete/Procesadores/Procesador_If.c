//
// Created by lightdemon on 2/09/25.
//
#include "../../../Headers/Procesador_If.h"
#include "../../../Headers/node_processor.h"
#include "../../Headers/mainview.h"
#include "../../../Headers/globals.h"
#include "../../Headers/scope_utils.h"  // ← YA ESTÁ INCLUIDO
#include "../../../Headers/node_utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Función para determinar el tipo de IF
TipoIF get_tipo_if(const char* node_type) {
    if (!node_type) return IF_TYPE_DESCONOCIDO;

    if (strcmp(node_type, "IF_SIMPLE") == 0) return IF_TYPE_SIMPLE;
    if (strcmp(node_type, "IF_SIMPLE_SIN_LLAVES") == 0) return IF_TYPE_SIMPLE_SIN_LLAVES;
    if (strcmp(node_type, "IF_CON_ELSE") == 0) return IF_TYPE_CON_ELSE;
    if (strcmp(node_type, "IF_CON_ELSE_MIXTO_1") == 0) return IF_TYPE_CON_ELSE_MIXTO_1;
    if (strcmp(node_type, "IF_CON_ELSE_IF") == 0) return IF_TYPE_CON_ELSE_IF;

    return IF_TYPE_DESCONOCIDO;
}

// Función para validar condición boolean
int validar_condicion_boolean(NodeProcessorContext* context, const char* valor_condicion, TipoDato tipo_condicion) {
    if (tipo_condicion != TIPO_BOOLEAN) {
        char error_msg[256];
        snprintf(error_msg, sizeof(error_msg),
                "Condición IF debe ser boolean, se encontró: %s",
                tipo_dato_to_string(tipo_condicion));

        const char* scope_actual = "global";
        if (context->scope_actual && context->scope_actual->nombre) {
            scope_actual = context->scope_actual->nombre;
        }

        if (global_error_manager) {
            error_manager_add_semantico(global_error_manager,
                                      context->linea_actual, 1,
                                      error_msg, "if",
                                      scope_actual);
        }

        procesador_error_output(context, error_msg);
        return 0;
    }

    if (!valor_condicion || (strcmp(valor_condicion, "true") != 0 && strcmp(valor_condicion, "false") != 0)) {
        procesador_error_output(context, "Valor de condición IF inválido");
        return 0;
    }

    return 1;
}

// Función para evaluar condición IF
ResultadoCondicion evaluar_condicion_if(NodeProcessorContext* context, ASTNode* condicion_node) {
    if (!condicion_node) {
        procesador_error_output(context, "Nodo de condición NULL");
        return CONDICION_ERROR;
    }

    char debug_msg[256];
    snprintf(debug_msg, sizeof(debug_msg), "🔍 EVALUANDO CONDICIÓN IF en línea %d", condicion_node->line);
    procesador_debug_output(context, debug_msg);

    // La condición debe tener un hijo (la expresión)
    if (condicion_node->child_count < 1) {
        procesador_error_output(context, "Condición IF sin expresión");
        return CONDICION_ERROR;
    }

    ASTNode* expresion_node = condicion_node->children[0];

    // Evaluar la expresión de condición
    TipoDato tipo_condicion = obtener_tipo_desde_nodo(expresion_node, context);
    char* valor_condicion = obtener_valor_desde_nodo(expresion_node, context);

    if (!valor_condicion) {
        procesador_error_output(context, "No se pudo evaluar la condición IF");
        return CONDICION_ERROR;
    }

    snprintf(debug_msg, sizeof(debug_msg), "🔍 CONDICIÓN EVALUADA: '%s' (%s)",
             valor_condicion, tipo_dato_to_string(tipo_condicion));
    procesador_debug_output(context, debug_msg);

    // Validar que sea boolean
    if (!validar_condicion_boolean(context, valor_condicion, tipo_condicion)) {
        free(valor_condicion);
        return CONDICION_ERROR;
    }

    // Determinar resultado
    ResultadoCondicion resultado;
    if (strcmp(valor_condicion, "true") == 0) {
        resultado = CONDICION_TRUE;
        snprintf(debug_msg, sizeof(debug_msg), "✅ CONDICIÓN IF: TRUE - bloque se ejecutará");
    } else {
        resultado = CONDICION_FALSE;
        snprintf(debug_msg, sizeof(debug_msg), "❌ CONDICIÓN IF: FALSE - bloque se omitirá");
    }

    procesador_debug_output(context, debug_msg);
    free(valor_condicion);
    return resultado;
}

// Función para procesar un bloque IF
int process_bloque_if(NodeProcessorContext* context, ASTNode* bloque_node,
                      const char* nombre_scope, int crear_scope) {
    if (!bloque_node) return 0;

    char debug_msg[256];
    if (crear_scope) {
        snprintf(debug_msg, sizeof(debug_msg), "🔍 ENTRANDO SCOPE IF: %s", nombre_scope);
        procesador_debug_output(context, debug_msg);
        entrar_scope_combinado(context, SCOPE_IF, nombre_scope, bloque_node->line);
    } else {
        snprintf(debug_msg, sizeof(debug_msg), "🔍 EJECUTANDO INSTRUCCIÓN IF (sin scope)");
        procesador_debug_output(context, debug_msg);
    }

    int resultado = 0;

    // Procesar contenido del bloque
    if (strcmp(bloque_node->type, "SCOPE") == 0) {
        // Es un SCOPE con INSTRUCCIONES dentro
        for (int i = 0; i < bloque_node->child_count; i++) {
            if (process_ast_node(context, bloque_node->children[i]) != 0) {
                resultado = 1;
                break;
            }
        }
    } else if (strcmp(bloque_node->type, "INSTRUCCION_IF") == 0) {
        // Es una sola instrucción
        for (int i = 0; i < bloque_node->child_count; i++) {
            if (process_ast_node(context, bloque_node->children[i]) != 0) {
                resultado = 1;
                break;
            }
        }
    } else {
        // Procesar directamente
        resultado = process_ast_node(context, bloque_node);
    }

    if (crear_scope) {
        snprintf(debug_msg, sizeof(debug_msg), "🔍 SALIENDO SCOPE IF: %s", nombre_scope);
        procesador_debug_output(context, debug_msg);
        salir_scope_combinado(context, bloque_node->line);
    }

    return resultado;
}

// Procesador principal para todos los tipos de IF
int process_if_node(NodeProcessorContext* context, ASTNode* node) {
    if (!context || !node) {
        procesador_error_output(context, "Contexto o nodo NULL en IF");
        return 1;
    }

    char debug_msg[256];
    snprintf(debug_msg, sizeof(debug_msg), "🔀 ANÁLISIS SEMÁNTICO: IF '%s' en línea %d",
             node->type, node->line);
    procesador_debug_output(context, debug_msg);

    TipoIF tipo_if = get_tipo_if(node->type);

    switch (tipo_if) {
        case IF_TYPE_SIMPLE:
            return process_if_simple(context, node);
        case IF_TYPE_SIMPLE_SIN_LLAVES:
            return process_if_simple_sin_llaves(context, node);
        case IF_TYPE_CON_ELSE:
            return process_if_con_else(context, node);
        case IF_TYPE_CON_ELSE_MIXTO_1:
            return process_if_con_else_mixto(context, node);
        case IF_TYPE_CON_ELSE_IF:
            // Procesar igual que IF_CON_ELSE pero sin else final
            return process_if_con_else(context, node);
        default:
            procesador_error_output(context, "Tipo de IF desconocido");
            return 1;
    }
}

// IF_SIMPLE: if (condicion) { ... }
int process_if_simple(NodeProcessorContext* context, ASTNode* node) {
    if (node->child_count < 2) {
        procesador_error_output(context, "IF_SIMPLE con estructura incorrecta");
        return 1;
    }

    ASTNode* condicion_node = node->children[0];
    ASTNode* bloque_node = node->children[1];

    char debug_msg[256];
    snprintf(debug_msg, sizeof(debug_msg), "🔀 ANÁLISIS SEMÁNTICO: IF_SIMPLE en línea %d", node->line);
    procesador_debug_output(context, debug_msg);

    // ===== EVALUAR CONDICIÓN ANTES DE CREAR SCOPE =====
    ResultadoCondicion resultado_condicion = evaluar_condicion_if(context, condicion_node);
    if (resultado_condicion == CONDICION_ERROR) {
        return 1;
    }

    // ===== USAR SCOPE_UTILS PARA GENERAR NOMBRE =====
    char* scope_name = generate_scope_name(context, SCOPE_TYPE_IF, node);
    if (!scope_name) {
        procesador_error_output(context, "Error generando nombre de scope IF");
        return 1;
    }

    // Ejecutar bloque solo si condición es true
    if (resultado_condicion == CONDICION_TRUE) {
        snprintf(debug_msg, sizeof(debug_msg), "✅ CONDICIÓN TRUE - ejecutando bloque IF: %s", scope_name);
        procesador_debug_output(context, debug_msg);
        int resultado = process_bloque_if(context, bloque_node, scope_name, 1);
        free(scope_name);
        return resultado;
    } else {
        snprintf(debug_msg, sizeof(debug_msg), "❌ CONDICIÓN FALSE - omitiendo bloque IF: %s", scope_name);
        procesador_debug_output(context, debug_msg);
        free(scope_name);
        return 0;
    }
}

// IF_SIMPLE_SIN_LLAVES: if (condicion) instruccion;
int process_if_simple_sin_llaves(NodeProcessorContext* context, ASTNode* node) {
    if (node->child_count < 2) {
        procesador_error_output(context, "IF_SIMPLE_SIN_LLAVES con estructura incorrecta");
        return 1;
    }

    ASTNode* condicion_node = node->children[0];
    ASTNode* instruccion_node = node->children[1];

    // Evaluar condición
    ResultadoCondicion resultado_condicion = evaluar_condicion_if(context, condicion_node);
    if (resultado_condicion == CONDICION_ERROR) {
        return 1;
    }

    // Ejecutar instrucción solo si condición es true (SIN CREAR SCOPE)
    if (resultado_condicion == CONDICION_TRUE) {
        return process_bloque_if(context, instruccion_node, "if_sin_llaves", 0);
    } else {
        procesador_debug_output(context, "🔀 IF SIN LLAVES: Condición falsa, omitiendo instrucción");
        return 0;
    }
}

// IF_CON_ELSE: if (condicion) { ... } else { ... }
int process_if_con_else(NodeProcessorContext* context, ASTNode* node) {
    if (node->child_count < 3) {
        procesador_error_output(context, "IF_CON_ELSE con estructura incorrecta");
        return 1;
    }

    ASTNode* condicion_node = node->children[0];
    ASTNode* bloque_if = node->children[1];
    ASTNode* bloque_else = node->children[2];

    char debug_msg[256];
    snprintf(debug_msg, sizeof(debug_msg), "🔀 ANÁLISIS SEMÁNTICO: IF_CON_ELSE en línea %d", node->line);
    procesador_debug_output(context, debug_msg);

    // ===== EVALUAR CONDICIÓN =====
    ResultadoCondicion resultado_condicion = evaluar_condicion_if(context, condicion_node);
    if (resultado_condicion == CONDICION_ERROR) {
        return 1;
    }

    // ===== SI CONDICIÓN ES TRUE, EJECUTAR IF =====
    if (resultado_condicion == CONDICION_TRUE) {
        char* scope_name = generate_scope_name(context, SCOPE_TYPE_IF, node);
        if (!scope_name) {
            procesador_error_output(context, "Error generando nombre de scope IF");
            return 1;
        }

        snprintf(debug_msg, sizeof(debug_msg), "✅ CONDICIÓN TRUE - ejecutando IF: %s", scope_name);
        procesador_debug_output(context, debug_msg);

        int resultado = process_bloque_if(context, bloque_if, scope_name, 1);
        free(scope_name);
        return resultado;
    } else {
        // ===== CONDICIÓN FALSE, EJECUTAR ELSE =====
        snprintf(debug_msg, sizeof(debug_msg), "❌ CONDICIÓN IF FALSE - ejecutando ELSE");
        procesador_debug_output(context, debug_msg);

        // ===== EJECUTAR BLOQUE ELSE =====
        char* scope_name = generate_scope_name(context, SCOPE_TYPE_ELSE, node);
        if (!scope_name) {
            procesador_error_output(context, "Error generando nombre de scope ELSE");
            return 1;
        }

        snprintf(debug_msg, sizeof(debug_msg), "✅ Ejecutando bloque ELSE: %s", scope_name);
        procesador_debug_output(context, debug_msg);

        int resultado = process_bloque_if(context, bloque_else, scope_name, 1);
        free(scope_name);
        return resultado;
    }
}

// IF_CON_ELSE_MIXTO_1: if + else if + else (estructura compleja)
int process_if_con_else_mixto(NodeProcessorContext* context, ASTNode* node) {
    if (node->child_count < 3) {
        procesador_error_output(context, "IF_CON_ELSE_MIXTO con estructura incorrecta");
        return 1;
    }

    ASTNode* condicion_node = node->children[0];
    ASTNode* bloque_if = node->children[1];
    ASTNode* instruccion_else = node->children[2];

    char debug_msg[256];
    snprintf(debug_msg, sizeof(debug_msg), "🔀 ANÁLISIS SEMÁNTICO: IF_CON_ELSE_MIXTO en línea %d", node->line);
    procesador_debug_output(context, debug_msg);

    // ===== EVALUAR CONDICIÓN PRINCIPAL =====
    ResultadoCondicion resultado_condicion = evaluar_condicion_if(context, condicion_node);
    if (resultado_condicion == CONDICION_ERROR) {
        return 1;
    }

    // ===== SI CONDICIÓN ES TRUE, EJECUTAR IF Y TERMINAR =====
    if (resultado_condicion == CONDICION_TRUE) {
        char* scope_name = generate_scope_name(context, SCOPE_TYPE_IF, node);
        if (!scope_name) {
            procesador_error_output(context, "Error generando nombre de scope IF_MIXTO");
            return 1;
        }

        snprintf(debug_msg, sizeof(debug_msg), "✅ CONDICIÓN TRUE - ejecutando IF_MIXTO: %s", scope_name);
        procesador_debug_output(context, debug_msg);

        // EJECUTAR SOLO EL BLOQUE IF Y TERMINAR
        int resultado = process_bloque_if(context, bloque_if, scope_name, 1);
        free(scope_name);
        return resultado;
    } else {
        // ===== CONDICIÓN FALSE, PROCESAR ELSE (SIN PROCESAR AUTOMÁTICAMENTE) =====
        snprintf(debug_msg, sizeof(debug_msg), "❌ CONDICIÓN FALSE - procesando rama ELSE_MIXTO");
        procesador_debug_output(context, debug_msg);

        // ===== PROCESAR LA INSTRUCCIÓN ELSE RECURSIVAMENTE =====
        // Esto debería ser otro IF que se evaluará independientemente
        return process_ast_node(context, instruccion_else);
    }
}