#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "mainview.h"
#include "../../../Headers/ast.h"
#include "../../../Headers/node_processor.h"
#include "../../../Headers/scope_utils.h"
#include "../../../Headers/error_manager.h"

extern ErrorManager* global_error_manager;

int procesar_continue(NodeProcessorContext* context, ASTNode* node) {
    if (!context || !node) {
        printf("ERROR: Parámetros inválidos para continue\n");
        return 1;
    }

    printf("🔄 PROCESANDO CONTINUE en línea %d\n", node->line);

    // ===== VERIFICAR QUE ESTEMOS DENTRO DE UN BUCLE VÁLIDO =====
    ScopeNode* scope_actual = context->scope_actual;
    int en_bucle_valido = 0;
    ScopeNode* scope_objetivo = NULL;

    // Buscar hacia arriba en el stack de scopes hasta encontrar el primer bucle
    // NOTA: Continue NO es válido en switch (a diferencia de break)
    while (scope_actual) {
        if (scope_actual->tipo == SCOPE_WHILE ||
            scope_actual->tipo == SCOPE_FOR ||
            scope_actual->tipo == SCOPE_DO_WHILE) {
            en_bucle_valido = 1;
            scope_objetivo = scope_actual;

            const char* tipo_bucle =
                (scope_actual->tipo == SCOPE_WHILE) ? "WHILE" :
                (scope_actual->tipo == SCOPE_FOR) ? "FOR" : "DO_WHILE";

            printf("✅ CONTINUE válido - encontrado en bucle '%s' (%s)\n",
                   scope_actual->nombre, tipo_bucle);
            break;
        }
        // Si encontramos un switch, seguimos buscando hacia arriba
        // porque continue no es válido en switch
        scope_actual = scope_actual->parent;
    }

    if (!en_bucle_valido) {
        // ===== ERROR SEMÁNTICO: CONTINUE FUERA DE BUCLE =====
        char error_msg[512];
        snprintf(error_msg, sizeof(error_msg),
                "Sentencia 'continue' encontrada fuera de un bucle. "
                "Continue solo es válido dentro de while, for o do-while.");

        const char* scope_actual_name = "global";
        if (context->scope_actual && context->scope_actual->nombre) {
            scope_actual_name = context->scope_actual->nombre;
        }

        if (global_error_manager) {
            error_manager_add_semantico(global_error_manager,
                                      node->line, node->column,
                                      error_msg, "continue", scope_actual_name);
        }

        printf("❌ ERROR SEMÁNTICO: %s\n", error_msg);
        return 1;
    }

    // ===== CONTINUE VÁLIDO - COMPORTAMIENTO COMO JAVA =====
    const char* tipo_bucle =
        (scope_objetivo->tipo == SCOPE_WHILE) ? "WHILE" :
        (scope_objetivo->tipo == SCOPE_FOR) ? "FOR" : "DO_WHILE";

    printf("🔄 Continue ejecutado - saltando a siguiente iteración de '%s'\n",
           scope_objetivo->nombre);

    // ===== MARCAR ESTADO DE CONTINUE PARA CONTROL DE FLUJO =====
    switch (scope_objetivo->tipo) {
        case SCOPE_WHILE:
            printf("   → Saltando a evaluación de condición del WHILE\n");
            break;

        case SCOPE_FOR:
            printf("   → Saltando a incremento/evaluación del FOR\n");
            break;

        case SCOPE_DO_WHILE:
            printf("   → Saltando a evaluación de condición del DO-WHILE\n");
            break;

        default:
            break;
    }

    if (context->mainview) {
        char continue_msg[256];
        snprintf(continue_msg, sizeof(continue_msg),
                "[CONTROL] Continue ejecutado - saltando iteración en %s (línea %d)",
                scope_objetivo->nombre, node->line);
        mainview_append_console(context->mainview, continue_msg);
    }

    printf("🎯 Control transferido - continue procesado exitosamente\n");

    // ===== RETORNAR CÓDIGO ESPECIAL PARA CONTINUE =====
    // -2 = continue (salta a siguiente iteración)
    // -1 = break (sale del bucle)
    //  0 = éxito normal
    //  1 = error
    return -2;
}