#include "../../../Headers/Procesador_For.h"
#include "../../../Headers/node_processor.h"
#include "../../../Headers/mainview.h"
#include "../../../Headers/globals.h"
#include "../../../Headers/scope_utils.h"
#include "../../../Headers/node_utils.h"
#include "../../../Headers/Procesador_If.h"
#include "../../../Headers/Procesador_Declaraciones.h"
#include "../../../Headers/Procesador_Expresion.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ===== IMPORTAR FUNCIONES HELPER =====
extern int procesar_instrucciones_con_control(NodeProcessorContext* context, ASTNode* instrucciones_node, const char* contexto);
extern int es_codigo_control_flujo(int codigo);
extern const char* obtener_nombre_control(int codigo);
extern void limpiar_variables_locales_scope_actual(NodeProcessorContext* context);

extern ErrorManager* global_error_manager;

// ===== FUNCIONES AUXILIARES PARA FOR TRADICIONAL =====

// Función para procesar la inicialización del for
int procesar_inicializacion_for(NodeProcessorContext* context, ASTNode* inicializacion_node) {
    if (!inicializacion_node || inicializacion_node->child_count < 1) {
        return 0;
    }

    if (context->modo_debug) {
        procesador_debug_output(context, "🔧 PROCESANDO INICIALIZACIÓN FOR");
    }

    ASTNode* declaracion_node = inicializacion_node->children[0];

    if (strcmp(declaracion_node->type, "INICIALIZACION_FOR_DECLARACION") == 0) {
        // Procesar como declaración usando el procesador existente
        return process_declaracion_node(context, declaracion_node);
    }

    // Si no es declaración, procesar como expresión
    char* resultado = process_expresion_node(context, declaracion_node);
    if (resultado) {
        free(resultado);
        return 0;
    }

    return 1;
}

// Función para evaluar la condición del for
ResultadoCondicion evaluar_condicion_for(NodeProcessorContext* context, ASTNode* condicion_node) {
    if (!condicion_node || condicion_node->child_count < 1) {
        // Sin condición = siempre verdadero (for infinito)
        return CONDICION_TRUE;
    }

    if (context->modo_debug) {
        procesador_debug_output(context, "🔍 EVALUANDO CONDICIÓN FOR");
    }

    ASTNode* expresion_node = condicion_node->children[0];
    char* valor_condicion = obtener_valor_desde_nodo(expresion_node, context);

    if (!valor_condicion) {
        procesador_error_output(context, "No se pudo evaluar la condición FOR");
        return CONDICION_ERROR;
    }

    if (context->modo_debug) {
        char debug_msg[128];
        snprintf(debug_msg, sizeof(debug_msg), "🔍 CONDICIÓN FOR EVALUADA: '%s'", valor_condicion);
        procesador_debug_output(context, debug_msg);
    }

    ResultadoCondicion resultado;
    if (strcmp(valor_condicion, "true") == 0) {
        resultado = CONDICION_TRUE;
    } else if (strcmp(valor_condicion, "false") == 0) {
        resultado = CONDICION_FALSE;
    } else {
        double valor = convertir_a_numero(valor_condicion, TIPO_DOUBLE);
        resultado = (valor != 0.0) ? CONDICION_TRUE : CONDICION_FALSE;
    }

    if (context->modo_debug) {
        char debug_msg[64];
        snprintf(debug_msg, sizeof(debug_msg), "🔍 CONDICIÓN FOR %s",
                resultado == CONDICION_TRUE ? "VERDADERA" : "FALSA");
        procesador_debug_output(context, debug_msg);
    }

    free(valor_condicion);
    return resultado;
}

// Función para procesar la actualización del for
int procesar_actualizacion_for(NodeProcessorContext* context, ASTNode* actualizacion_node) {
    if (!actualizacion_node || actualizacion_node->child_count < 1) {
        return 0; // Sin actualización es válido
    }

    if (context->modo_debug) {
        procesador_debug_output(context, "🔄 PROCESANDO ACTUALIZACIÓN FOR");
    }

    ASTNode* nodo_actual = actualizacion_node;

    while (nodo_actual && strcmp(nodo_actual->type, "ACTUALIZACION_FOR") == 0 && nodo_actual->child_count > 0) {
        nodo_actual = nodo_actual->children[0];
    }

    if (nodo_actual) {
        char* resultado = process_expresion_node(context, nodo_actual);
        if (resultado) {
            if (context->modo_debug) {
                char debug_msg[128];
                snprintf(debug_msg, sizeof(debug_msg), "🔄 ACTUALIZACIÓN FOR ejecutada: %s", resultado);
                procesador_debug_output(context, debug_msg);
            }
            free(resultado);
        }
    }

    return 0;
}

// Función para ejecutar el bloque del for
int ejecutar_bloque_for(NodeProcessorContext* context, ASTNode* bloque_node) {
    if (!context || !bloque_node) {
        return 0;
    }

    if (context->modo_debug) {
        char debug_msg[128];
        snprintf(debug_msg, sizeof(debug_msg), "🔄 EJECUTANDO BLOQUE FOR en línea %d", bloque_node->line);
        procesador_debug_output(context, debug_msg);
    }

    ASTNode* nodo_a_procesar = bloque_node;

    if (strcmp(bloque_node->type, "BLOQUE_FOR") == 0) {
        if (bloque_node->child_count > 0 && bloque_node->children[0]) {
            nodo_a_procesar = bloque_node->children[0];
        }
    }

    if (strcmp(nodo_a_procesar->type, "SCOPE") == 0) {
        for (int i = 0; i < nodo_a_procesar->child_count; i++) {
            ASTNode* hijo = nodo_a_procesar->children[i];
            if (hijo && strcmp(hijo->type, "INSTRUCCIONES") == 0) {
                if (context->modo_debug) {
                    procesador_debug_output(context, "🔍 PROCESANDO INSTRUCCIONES DEL FOR con control de flujo");
                }
                int resultado = procesar_instrucciones_con_control(context, hijo, "FOR");

                if (es_codigo_control_flujo(resultado) && context->modo_debug) {
                    char debug_msg[128];
                    snprintf(debug_msg, sizeof(debug_msg), "🔄 FOR recibiendo %s: %d",
                            obtener_nombre_control(resultado), resultado);
                    procesador_debug_output(context, debug_msg);
                }

                return resultado;
            }
        }
    } else if (strcmp(nodo_a_procesar->type, "INSTRUCCIONES") == 0) {
        return procesar_instrucciones_con_control(context, nodo_a_procesar, "FOR");
    }

    return 0;
}

// ===== PROCESADOR FOR TRADICIONAL =====
char* process_for_node(NodeProcessorContext* context, ASTNode* node) {
    if (!context || !node) {
        procesador_error_output(context, "ERROR: Parámetros inválidos para for");
        return NULL;
    }

    if (node->child_count < 4) {
        procesador_error_output(context, "ERROR: For malformado - faltan componentes");
        return NULL;
    }

    ASTNode* inicializacion_node = node->children[0];
    ASTNode* condicion_node = node->children[1];
    ASTNode* actualizacion_node = node->children[2];
    ASTNode* bloque_node = node->children[3];

    char* for_scope_name = generate_scope_name(context, SCOPE_TYPE_FOR, node);
    if (!for_scope_name) {
        procesador_error_output(context, "ERROR: No se pudo crear scope para for");
        return NULL;
    }

    entrar_scope_combinado(context, SCOPE_FOR, for_scope_name, node->line);

    int resultado_init = procesar_inicializacion_for(context, inicializacion_node);
    if (resultado_init != 0) {
        procesador_error_output(context, "ERROR en inicialización del for");
        salir_scope_combinado(context, node->line);
        free(for_scope_name);
        return NULL;
    }

    int iteraciones = 0;
    int max_iteraciones = 10000;

    while (iteraciones < max_iteraciones) {
        // 🔑 Restaurar el ámbito del for antes de la condición
        entrar_ambito(context->tabla_simbolos, for_scope_name);

        ResultadoCondicion resultado_condicion = evaluar_condicion_for(context, condicion_node);
        if (resultado_condicion == CONDICION_ERROR) {
            procesador_error_output(context, "ERROR evaluando condición del for");
            break;
        }
        if (resultado_condicion == CONDICION_FALSE) {
            break;
        }

        iteraciones++;

        // 🔑 Restaurar el ámbito del for antes de ejecutar el bloque
        entrar_ambito(context->tabla_simbolos, for_scope_name);

        int resultado_bloque = ejecutar_bloque_for(context, bloque_node);

        if (resultado_bloque == -1) { // break
            break;
        }
        if (resultado_bloque == -2) { // continue
            // 🔑 Restaurar el ámbito del for antes de la actualización
            entrar_ambito(context->tabla_simbolos, for_scope_name);
            procesar_actualizacion_for(context, actualizacion_node);
            continue;
        }
        if (resultado_bloque == -3) { // return
            salir_scope_combinado(context, node->line);
            free(for_scope_name);
            return NULL;
        }

        // 🔑 Restaurar el ámbito del for antes de la actualización
        entrar_ambito(context->tabla_simbolos, for_scope_name);
        procesar_actualizacion_for(context, actualizacion_node);
    }

    limpiar_variables_locales_scope_actual(context);
    salir_scope_combinado(context, node->line);
    free(for_scope_name);

    char* resultado = malloc(16);
    snprintf(resultado, 16, "%d", iteraciones);
    return resultado;
}