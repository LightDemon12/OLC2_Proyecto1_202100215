#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "mainview.h"
#include "../../../Headers/ast.h"
#include "../../../Headers/node_processor.h"
#include "../../../Headers/scope_utils.h"
#include "../../../Headers/error_manager.h"

extern ErrorManager* global_error_manager;

int procesar_break(NodeProcessorContext* context, ASTNode* node) {
    if (!context || !node) {
        printf("ERROR: Parámetros inválidos para break\n");
        return 1;
    }

    printf("🛑 PROCESANDO BREAK en línea %d\n", node->line);

    // ===== VERIFICAR QUE ESTEMOS DENTRO DE UN CONTEXTO VÁLIDO =====
    ScopeNode* scope_actual = context->scope_actual;
    int en_contexto_valido = 0;
    ScopeNode* scope_objetivo = NULL;

    // Buscar hacia arriba en el stack de scopes hasta encontrar el primer bucle o switch
    while (scope_actual) {
        if (scope_actual->tipo == SCOPE_WHILE ||
            scope_actual->tipo == SCOPE_FOR ||
            scope_actual->tipo == SCOPE_DO_WHILE ||
            scope_actual->tipo == SCOPE_SWITCH) {
            en_contexto_valido = 1;
            scope_objetivo = scope_actual;

            const char* tipo_contexto =
                (scope_actual->tipo == SCOPE_WHILE) ? "WHILE" :
                (scope_actual->tipo == SCOPE_FOR) ? "FOR" :
                (scope_actual->tipo == SCOPE_DO_WHILE) ? "DO_WHILE" : "SWITCH";

            printf("✅ BREAK válido - encontrado en contexto '%s' (%s)\n",
                   scope_actual->nombre, tipo_contexto);
            break;
        }
        scope_actual = scope_actual->parent;
    }

    if (!en_contexto_valido) {
        // ===== ERROR SEMÁNTICO: BREAK FUERA DE CONTEXTO =====
        char error_msg[512];
        snprintf(error_msg, sizeof(error_msg),
                "Sentencia 'break' encontrada fuera de un bucle o switch. "
                "Break solo es válido dentro de while, for, do-while o switch.");

        const char* scope_actual_name = "global";
        if (context->scope_actual && context->scope_actual->nombre) {
            scope_actual_name = context->scope_actual->nombre;
        }

        if (global_error_manager) {
            error_manager_add_semantico(global_error_manager,
                                      node->line, node->column,
                                      error_msg, "break", scope_actual_name);
        }

        printf("❌ ERROR SEMÁNTICO: %s\n", error_msg);
        return 1;
    }

    // ===== BREAK VÁLIDO - COMPORTAMIENTO COMO JAVA =====
    printf("🛑 Break ejecutado - terminando '%s' y transfiriendo control\n",
           scope_objetivo->nombre);

    // ===== MARCAR ESTADO DE BREAK PARA CONTROL DE FLUJO =====
    // En Java, break:
    // 1. Termina inmediatamente el bucle/switch más cercano
    // 2. Transfiere control a la siguiente sentencia después del bucle/switch
    // 3. No ejecuta más iteraciones ni código dentro del bloque

    if (context->mainview) {
        char break_msg[256];
        snprintf(break_msg, sizeof(break_msg),
                "[CONTROL] Break ejecutado - saliendo de %s en línea %d",
                scope_objetivo->nombre, node->line);
        mainview_append_console(context->mainview, break_msg);
    }

    // TODO: Cuando implementemos el intérprete completo, aquí:
    // - Marcar flag de break en el contexto
    // - Saltar a la instrucción después del bucle/switch
    // - Limpiar cualquier estado de iteración pendiente

    printf("🎯 Control transferido - break procesado exitosamente\n");
    return 0;
}