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
                                   const char* message, const char* token_text,
                                   const char* scope) {
    ErrorNode* node = malloc(sizeof(ErrorNode));
    if (!node) return NULL;

    node->type = type;
    node->line = line;
    node->column = column;
    node->message = message ? strdup(message) : NULL;
    node->token_text = token_text ? strdup(token_text) : NULL;

    //   MANEJAR ÁMBITO SEGÚN TIPO DE ERROR
    if (type == ERROR_SEMANTICO && scope) {
        node->scope = strdup(scope);
    } else {
        // Para errores léxicos y sintácticos
        node->scope = strdup("Sin ambito");
    }

    node->next = NULL;
    return node;
}

//   ACTUALIZAR FUNCIÓN DE LIBERACIÓN:
static void free_error_node(ErrorNode* node) {
    if (node) {
        free(node->message);
        free(node->token_text);
        free(node->scope);  // ← AGREGAR
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



void error_manager_add_lexico(ErrorManager* manager, int line, int column,
                             const char* message, const char* token_text) {
    /*   VALIDACIONES SEGURAS */
    if (!manager) {
        fprintf(stderr, "ERROR: error_manager es NULL\n");
        return;
    }

    if (!message) {
        fprintf(stderr, "ERROR: message es NULL\n");
        return;
    }

    /*   CREAR NODO CON VERIFICACIONES */
    ErrorNode* node = malloc(sizeof(ErrorNode));
    if (!node) {
        fprintf(stderr, "ERROR: No se pudo allocar memoria para ErrorNode\n");
        return;
    }

    node->type = ERROR_LEXICO;
    node->line = line;
    node->column = column;
    node->message = strdup(message);
    node->token_text = token_text ? strdup(token_text) : NULL;
    node->scope = strdup("Sin ambito");
    node->next = NULL;

    /*   VERIFICAR DUPLICACIÓN DE STRINGS */
    if (!node->message || !node->scope) {
        fprintf(stderr, "ERROR: No se pudo duplicar strings\n");
        free(node->message);
        free(node->token_text);
        free(node->scope);
        free(node);
        return;
    }

    /*   INSERTAR EN LISTA */
    if (!manager->head) {
        manager->head = manager->tail = node;
    } else {
        manager->tail->next = node;
        manager->tail = node;
    }

    manager->lexico_count++;
    manager->total_count++;
}

void error_manager_add_sintactico(ErrorManager* manager, int line, int column,
                                 const char* message, const char* token_text) {
    if (!manager) return;

    ErrorNode* node = create_error_node(ERROR_SINTACTICO, line, column,
                                       message, token_text, NULL);
    if (!node) return;

    if (!manager->head) {
        manager->head = manager->tail = node;
    } else {
        manager->tail->next = node;
        manager->tail = node;
    }

    manager->sintactico_count++;
    manager->total_count++;
}

void error_manager_add_semantico(ErrorManager* manager, int line, int column,
                                const char* message, const char* token_text,
                                const char* scope) {
    if (!manager) return;

    ErrorNode* node = create_error_node(ERROR_SEMANTICO, line, column,
                                       message, token_text, scope);
    if (!node) return;

    if (!manager->head) {
        manager->head = manager->tail = node;
    } else {
        manager->tail->next = node;
        manager->tail = node;
    }

    manager->semantico_count++;
    manager->total_count++;
}

const char* error_manager_get_scope_display(ErrorType type, const char* scope) {
    switch(type) {
        case ERROR_LEXICO:
            return "Error tipo lexico sin ambito";
        case ERROR_SINTACTICO:
            return "Error tipo sintactico sin ambito";
        case ERROR_SEMANTICO:
            return scope ? scope : "Ambito desconocido";
        default:
            return "Sin ambito";
    }
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
        printf("  No hay errores registrados\n");
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