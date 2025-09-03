//
// Created by lightdemon on 3/09/25.
//

#include "../../Headers/scope_utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ===== CONTADORES CENTRALIZADOS =====
typedef struct {
    int if_counter;
    int else_counter;
    int else_if_counter;
    int while_counter;
    int for_counter;
    int do_while_counter;
    int switch_counter;
    int case_counter;
    int function_counter;
    int block_counter;
    int try_counter;
    int catch_counter;
    int finally_counter;
} ScopeCounters;

// Variable global para contadores
static ScopeCounters global_counters = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

// ===== IMPLEMENTACIÓN DE FUNCIONES =====

const char* scope_type_to_string(ScopeGeneratorType type) {
    switch (type) {
        case SCOPE_TYPE_IF: return "if";
        case SCOPE_TYPE_ELSE: return "else";
        case SCOPE_TYPE_ELSE_IF: return "else_if";
        case SCOPE_TYPE_WHILE: return "while";
        case SCOPE_TYPE_FOR: return "for";
        case SCOPE_TYPE_DO_WHILE: return "do_while";
        case SCOPE_TYPE_SWITCH: return "switch";
        case SCOPE_TYPE_CASE: return "case";
        case SCOPE_TYPE_FUNCTION: return "function";
        case SCOPE_TYPE_BLOCK: return "block";
        case SCOPE_TYPE_TRY: return "try";
        case SCOPE_TYPE_CATCH: return "catch";
        case SCOPE_TYPE_FINALLY: return "finally";
        default: return "unknown";
    }
}

char* generate_scope_name(NodeProcessorContext* context, ScopeGeneratorType type, ASTNode* node) {
    if (!context) return NULL;

    char* scope_name = malloc(128);
    if (!scope_name) return NULL;

    int* counter = NULL;
    const char* type_str = scope_type_to_string(type);

    // Seleccionar contador apropiado
    switch (type) {
        case SCOPE_TYPE_IF: counter = &global_counters.if_counter; break;
        case SCOPE_TYPE_ELSE: counter = &global_counters.else_counter; break;
        case SCOPE_TYPE_ELSE_IF: counter = &global_counters.else_if_counter; break;
        case SCOPE_TYPE_WHILE: counter = &global_counters.while_counter; break;
        case SCOPE_TYPE_FOR: counter = &global_counters.for_counter; break;
        case SCOPE_TYPE_DO_WHILE: counter = &global_counters.do_while_counter; break;
        case SCOPE_TYPE_SWITCH: counter = &global_counters.switch_counter; break;
        case SCOPE_TYPE_CASE: counter = &global_counters.case_counter; break;
        case SCOPE_TYPE_FUNCTION: counter = &global_counters.function_counter; break;
        case SCOPE_TYPE_BLOCK: counter = &global_counters.block_counter; break;
        case SCOPE_TYPE_TRY: counter = &global_counters.try_counter; break;
        case SCOPE_TYPE_CATCH: counter = &global_counters.catch_counter; break;
        case SCOPE_TYPE_FINALLY: counter = &global_counters.finally_counter; break;
        default:
            free(scope_name);
            return NULL;
    }

    // Generar nombre con contador y referencia opcional al nodo
    if (node) {
        snprintf(scope_name, 128, "%s_%d_%p", type_str, (*counter)++, (void*)node);
    } else {
        snprintf(scope_name, 128, "%s_%d", type_str, (*counter)++);
    }

    printf("🏷️  SCOPE GENERATOR: Generado '%s' (tipo: %s)\n", scope_name, type_str);
    return scope_name;
}

char* generate_hierarchical_scope_name(NodeProcessorContext* context, const char* base_name) {
    if (!context || !base_name) return NULL;

    char* hierarchical_name = malloc(256);
    if (!hierarchical_name) return NULL;

    if (context->scope_actual) {
        // Crear nombre jerárquico
        snprintf(hierarchical_name, 256, "%s.%s", context->scope_actual->nombre, base_name);
    } else {
        // Scope de primer nivel
        strncpy(hierarchical_name, base_name, 255);
        hierarchical_name[255] = '\0';
    }

    return hierarchical_name;
}

char* enter_generated_scope(NodeProcessorContext* context, ScopeGeneratorType type, ASTNode* node) {
    if (!context) return NULL;

    // Generar nombre base
    char* base_name = generate_scope_name(context, type, node);
    if (!base_name) return NULL;

    // Generar nombre jerárquico
    char* hierarchical_name = generate_hierarchical_scope_name(context, base_name);
    if (!hierarchical_name) {
        free(base_name);
        return NULL;
    }

    // Entrar al scope usando el sistema existente
    ScopeType scope_type_enum;
    switch (type) {
        case SCOPE_TYPE_IF:
        case SCOPE_TYPE_ELSE:
        case SCOPE_TYPE_ELSE_IF:
            scope_type_enum = SCOPE_IF;
            break;
        case SCOPE_TYPE_WHILE:
        case SCOPE_TYPE_DO_WHILE:
            scope_type_enum = SCOPE_WHILE;
            break;
        case SCOPE_TYPE_FOR:
            scope_type_enum = SCOPE_FOR;
            break;
        case SCOPE_TYPE_SWITCH:
        case SCOPE_TYPE_CASE:
            scope_type_enum = SCOPE_SWITCH;
            break;
        case SCOPE_TYPE_FUNCTION:
            scope_type_enum = SCOPE_FUNCION;
            break;
        default:
            scope_type_enum = SCOPE_BLOQUE;
            break;
    }

    entrar_scope_combinado(context, scope_type_enum, hierarchical_name,
                          node ? node->line : context->linea_actual);

    printf("🚪 SCOPE GENERATOR: Entrado a scope '%s'\n", hierarchical_name);

    free(base_name);
    return hierarchical_name; // El llamador debe liberar esto
}

void reset_all_scope_counters(NodeProcessorContext* context) {
    // Resetear todos los contadores a 1
    global_counters.if_counter = 1;
    global_counters.else_counter = 1;
    global_counters.else_if_counter = 1;
    global_counters.while_counter = 1;
    global_counters.for_counter = 1;
    global_counters.do_while_counter = 1;
    global_counters.switch_counter = 1;
    global_counters.case_counter = 1;
    global_counters.function_counter = 1;
    global_counters.block_counter = 1;
    global_counters.try_counter = 1;
    global_counters.catch_counter = 1;
    global_counters.finally_counter = 1;

    printf("🔄 SCOPE GENERATOR: Todos los contadores reseteados a 1\n");
}