//
// Created by lightdemon on 21/08/25.
//

#include "../Headers/error_manager.h"

// === FUNCIONES AUXILIARES ===

const char* error_type_name(ErrorType type) {
    switch(type) {
        case ERROR_LEXICO: return "LEXICO";
        case ERROR_SINTACTICO: return "SINTACTICO";
        case ERROR_SEMANTICO: return "SEMANTICO";
        default: return "DESCONOCIDO";
    }
}

// Crear nuevo nodo de error
static ErrorNode* create_error_node(ErrorType type, int line, int column,
                                   const char* message, const char* token_text) {
    ErrorNode* node = malloc(sizeof(ErrorNode));
    if (!node) return NULL;

    node->type = type;
    node->line = line;
    node->column = column;
    node->message = message ? strdup(message) : NULL;
    node->token_text = token_text ? strdup(token_text) : NULL;
    node->next = NULL;

    return node;
}

// Liberar nodo de error
static void free_error_node(ErrorNode* node) {
    if (node) {
        free(node->message);
        free(node->token_text);
        free(node);
    }
}

// === FUNCIONES PÚBLICAS ===

ErrorManager* error_manager_create() {
    ErrorManager* manager = malloc(sizeof(ErrorManager));
    if (!manager) return NULL;

    manager->head = NULL;
    manager->tail = NULL;
    manager->lexico_count = 0;
    manager->sintactico_count = 0;
    manager->semantico_count = 0;
    manager->total_count = 0;

    return manager;
}

void error_manager_destroy(ErrorManager* manager) {
    if (!manager) return;

    error_manager_clear(manager);
    free(manager);
}

// Función genérica para agregar errores
static void add_error(ErrorManager* manager, ErrorType type, int line, int column,
                     const char* message, const char* token_text) {
    if (!manager) return;

    ErrorNode* node = create_error_node(type, line, column, message, token_text);
    if (!node) return;

    // Insertar al final de la lista
    if (manager->tail) {
        manager->tail->next = node;
        manager->tail = node;
    } else {
        // Primera inserción
        manager->head = manager->tail = node;
    }

    // Actualizar contadores
    switch(type) {
        case ERROR_LEXICO: manager->lexico_count++; break;
        case ERROR_SINTACTICO: manager->sintactico_count++; break;
        case ERROR_SEMANTICO: manager->semantico_count++; break;
    }
    manager->total_count++;
}

void error_manager_add_lexico(ErrorManager* manager, int line, int column,
                             const char* message, const char* token_text) {
    add_error(manager, ERROR_LEXICO, line, column, message, token_text);
}

void error_manager_add_sintactico(ErrorManager* manager, int line, int column,
                                 const char* message, const char* token_text) {
    add_error(manager, ERROR_SINTACTICO, line, column, message, token_text);
}

void error_manager_add_semantico(ErrorManager* manager, int line, int column,
                                const char* message, const char* token_text) {
    add_error(manager, ERROR_SEMANTICO, line, column, message, token_text);
}

// === CONSULTAS ===

int error_manager_has_errors(const ErrorManager* manager) {
    return manager ? manager->total_count > 0 : 0;
}

int error_manager_get_total_count(const ErrorManager* manager) {
    return manager ? manager->total_count : 0;
}

int error_manager_get_lexico_count(const ErrorManager* manager) {
    return manager ? manager->lexico_count : 0;
}

int error_manager_get_sintactico_count(const ErrorManager* manager) {
    return manager ? manager->sintactico_count : 0;
}

int error_manager_get_semantico_count(const ErrorManager* manager) {
    return manager ? manager->semantico_count : 0;
}

// === REPORTES ===

void error_manager_print_all(const ErrorManager* manager) {
    if (!manager || !manager->head) {
        printf("✅ No hay errores registrados\n");
        return;
    }

    printf("=== REPORTE DE ERRORES ===\n");
    ErrorNode* current = manager->head;
    int count = 1;

    while (current) {
        printf("%d. [%s] Línea %d, Columna %d: %s",
               count++, error_type_name(current->type),
               current->line, current->column, current->message);

        if (current->token_text) {
            printf(" | Token: '%s'", current->token_text);
        }
        printf("\n");

        current = current->next;
    }

    printf("=== TOTAL: %d errores ===\n", manager->total_count);
}

void error_manager_print_by_type(const ErrorManager* manager, ErrorType type) {
    if (!manager || !manager->head) return;

    printf("=== ERRORES %s ===\n", error_type_name(type));
    ErrorNode* current = manager->head;
    int count = 1;

    while (current) {
        if (current->type == type) {
            printf("%d. Línea %d, Columna %d: %s",
                   count++, current->line, current->column, current->message);

            if (current->token_text) {
                printf(" | Token: '%s'", current->token_text);
            }
            printf("\n");
        }
        current = current->next;
    }
}

char* error_manager_get_summary(const ErrorManager* manager) {
    if (!manager) return strdup("Error: Manager no valido");

    char* summary = malloc(256);
    if (!summary) return NULL;

    snprintf(summary, 256,
             "Errores: %d total | Lexicos: %d | Sintacticos: %d | Semanticos: %d",
             manager->total_count, manager->lexico_count,
             manager->sintactico_count, manager->semantico_count);

    return summary;
}

void error_manager_clear(ErrorManager* manager) {
    if (!manager) return;

    ErrorNode* current = manager->head;
    while (current) {
        ErrorNode* next = current->next;
        free_error_node(current);
        current = next;
    }

    manager->head = NULL;
    manager->tail = NULL;
    manager->lexico_count = 0;
    manager->sintactico_count = 0;
    manager->semantico_count = 0;
    manager->total_count = 0;
}