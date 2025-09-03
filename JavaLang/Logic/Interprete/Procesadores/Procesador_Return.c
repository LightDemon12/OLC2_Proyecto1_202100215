#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "mainview.h"
#include "../../../Headers/ast.h"
#include "../../../Headers/node_processor.h"
#include "../../../Headers/scope_utils.h"
#include "../../../Headers/error_manager.h"
#include "../../../Headers/Procesador_Expresion.h"
#include "../../../Headers/node_utils.h"

extern ErrorManager* global_error_manager;

int procesar_return_con_valor(NodeProcessorContext* context, ASTNode* node) {
    if (!context || !node) {
        printf("ERROR: Parámetros inválidos para return con valor\n");
        return 1;
    }

    printf("↩️ PROCESANDO RETURN_CON_VALOR en línea %d\n", node->line);

    // ===== VERIFICAR QUE ESTEMOS DENTRO DE UNA FUNCIÓN =====
    ScopeNode* scope_actual = context->scope_actual;
    int en_funcion = 0;
    ScopeNode* scope_funcion = NULL;

    // Buscar hacia arriba en el stack de scopes
    while (scope_actual) {
        if (scope_actual->tipo == SCOPE_FUNCION || scope_actual->tipo == SCOPE_MAIN) {
            en_funcion = 1;
            scope_funcion = scope_actual;
            printf("✅ RETURN válido - encontrado en función '%s'\n", scope_actual->nombre);
            break;
        }
        scope_actual = scope_actual->parent;
    }

    if (!en_funcion) {
        // ===== ERROR SEMÁNTICO: RETURN FUERA DE FUNCIÓN =====
        char error_msg[512];
        snprintf(error_msg, sizeof(error_msg),
                "Sentencia 'return' encontrada fuera de una función. "
                "Return solo es válido dentro de funciones o main.");

        const char* scope_actual_name = "global";
        if (context->scope_actual && context->scope_actual->nombre) {
            scope_actual_name = context->scope_actual->nombre;
        }

        if (global_error_manager) {
            error_manager_add_semantico(global_error_manager,
                                      node->line, node->column,
                                      error_msg, "return", scope_actual_name);
        }

        printf("❌ ERROR SEMÁNTICO: %s\n", error_msg);
        return 1;
    }

    // ===== RETURN CON VALOR - DEBE TENER EXACTAMENTE 1 HIJO =====
    if (node->child_count != 1) {
        char error_msg[256];
        snprintf(error_msg, sizeof(error_msg),
                "Return con valor debe tener exactamente una expresión. Encontrados: %d hijos",
                node->child_count);

        if (global_error_manager) {
            error_manager_add_semantico(global_error_manager,
                                      node->line, node->column,
                                      error_msg, "return",
                                      scope_funcion ? scope_funcion->nombre : "global");
        }

        printf("❌ ERROR SEMÁNTICO: %s\n", error_msg);
        return 1;
    }

    // ===== EVALUAR LA EXPRESIÓN DE RETORNO =====
    ASTNode* valor_retorno_node = node->children[0]; // VALOR_RETORNO

    printf("↩️ RETURN CON VALOR - evaluando expresión\n");

    // El VALOR_RETORNO contiene la expresión real
    if (valor_retorno_node->child_count > 0) {
        ASTNode* expresion_return = valor_retorno_node->children[0];

        // Evaluar la expresión de retorno
        char* valor_return = process_expresion_node(context, expresion_return);
        if (!valor_return) {
            char error_msg[256];
            snprintf(error_msg, sizeof(error_msg),
                    "Error evaluando expresión de retorno en función '%s'",
                    scope_funcion ? scope_funcion->nombre : "desconocida");

            if (global_error_manager) {
                error_manager_add_semantico(global_error_manager,
                                          node->line, node->column,
                                          error_msg, "return",
                                          scope_funcion ? scope_funcion->nombre : "global");
            }

            printf("❌ ERROR: %s\n", error_msg);
            return 1;
        }

        // Obtener tipo de la expresión
        TipoDato tipo_return = obtener_tipo_desde_nodo(expresion_return, context);

        printf("✅ RETURN evaluado: valor='%s', tipo=%s\n",
               valor_return, tipo_dato_to_string(tipo_return));

        // ===== MARCAR RETORNO PARA CONTROL DE FLUJO =====
        // En Java, return:
        // 1. Termina inmediatamente la ejecución de la función
        // 2. Devuelve el valor especificado al llamador
        // 3. Para funciones recursivas, cada return devuelve al nivel anterior
        // 4. No ejecuta más código después del return

        if (context->mainview) {
            char return_msg[256];
            snprintf(return_msg, sizeof(return_msg),
                    "[CONTROL] Return ejecutado en %s - valor: %s (línea %d)",
                    scope_funcion->nombre, valor_return, node->line);
            mainview_append_console(context->mainview, return_msg);
        }

        // TODO: Cuando implementemos el intérprete completo:
        // - Verificar compatibilidad con tipo de retorno de la función
        // - Marcar flag de return en el contexto
        // - Para funciones recursivas: devolver valor al stack de llamadas
        // - Limpiar scope local de la función
        // - Saltar al punto de llamada

        printf("🎯 Return procesado - función '%s' retorna '%s'\n",
               scope_funcion->nombre, valor_return);

        free(valor_return);
    } else {
        printf("❌ ERROR: VALOR_RETORNO sin expresión\n");
        return 1;
    }

    return 0;
}

int procesar_return_vacio(NodeProcessorContext* context, ASTNode* node) {
    if (!context || !node) {
        printf("ERROR: Parámetros inválidos para return vacío\n");
        return 1;
    }

    printf("↩️ PROCESANDO RETURN_VACIO en línea %d\n", node->line);

    // ===== VERIFICAR QUE ESTEMOS DENTRO DE UNA FUNCIÓN =====
    ScopeNode* scope_actual = context->scope_actual;
    int en_funcion = 0;
    ScopeNode* scope_funcion = NULL;

    // Buscar hacia arriba en el stack de scopes
    while (scope_actual) {
        if (scope_actual->tipo == SCOPE_FUNCION || scope_actual->tipo == SCOPE_MAIN) {
            en_funcion = 1;
            scope_funcion = scope_actual;
            printf("✅ RETURN VOID válido - encontrado en función '%s'\n", scope_actual->nombre);
            break;
        }
        scope_actual = scope_actual->parent;
    }

    if (!en_funcion) {
        // ===== ERROR SEMÁNTICO: RETURN FUERA DE FUNCIÓN =====
        char error_msg[512];
        snprintf(error_msg, sizeof(error_msg),
                "Sentencia 'return' encontrada fuera de una función. "
                "Return solo es válido dentro de funciones o main.");

        const char* scope_actual_name = "global";
        if (context->scope_actual && context->scope_actual->nombre) {
            scope_actual_name = context->scope_actual->nombre;
        }

        if (global_error_manager) {
            error_manager_add_semantico(global_error_manager,
                                      node->line, node->column,
                                      error_msg, "return", scope_actual_name);
        }

        printf("❌ ERROR SEMÁNTICO: %s\n", error_msg);
        return 1;
    }

    // ===== RETURN VOID - NO DEBE TENER HIJOS =====
    if (node->child_count > 0) {
        char error_msg[256];
        snprintf(error_msg, sizeof(error_msg),
                "Return void no debe tener valor de retorno. Encontrados: %d hijos",
                node->child_count);

        if (global_error_manager) {
            error_manager_add_semantico(global_error_manager,
                                      node->line, node->column,
                                      error_msg, "return",
                                      scope_funcion ? scope_funcion->nombre : "global");
        }

        printf("❌ ERROR SEMÁNTICO: %s\n", error_msg);
        return 1;
    }

    // ===== MARCAR RETORNO VOID PARA CONTROL DE FLUJO =====
    printf("↩️ RETURN VOID - terminando función sin valor de retorno\n");

    // En Java, return; en función void:
    // 1. Termina inmediatamente la ejecución de la función
    // 2. No devuelve ningún valor
    // 3. Control regresa al punto de llamada
    // 4. Para main, termina el programa

    if (context->mainview) {
        char return_msg[256];
        snprintf(return_msg, sizeof(return_msg),
                "[CONTROL] Return void ejecutado en %s (línea %d)",
                scope_funcion->nombre, node->line);
        mainview_append_console(context->mainview, return_msg);
    }

    // TODO: Cuando implementemos el intérprete completo:
    // - Verificar que la función sea realmente void
    // - Marcar flag de return en el contexto
    // - Limpiar scope local de la función
    // - Saltar al punto de llamada

    printf("🎯 Return void procesado - función '%s' terminada\n",
           scope_funcion->nombre);

    return 0;
}

// Función unificada para manejar ambos tipos de return
int procesar_return(NodeProcessorContext* context, ASTNode* node) {
    if (!context || !node) {
        printf("ERROR: Parámetros inválidos para return\n");
        return 1;
    }

    // Delegar según el tipo específico de return
    if (strcmp(node->type, "RETURN_CON_VALOR") == 0) {
        return procesar_return_con_valor(context, node);
    }
    else if (strcmp(node->type, "RETURN_VACIO") == 0) {
        return procesar_return_vacio(context, node);
    }
    else {
        printf("❌ ERROR: Tipo de return desconocido: '%s'\n", node->type);
        return 1;
    }
}