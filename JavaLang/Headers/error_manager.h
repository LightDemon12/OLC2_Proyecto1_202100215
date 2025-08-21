//
// Created by lightdemon on 21/08/25.
//

#ifndef ERROR_MANAGER_H
#define ERROR_MANAGER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Tipos de errores
typedef enum {
    ERROR_LEXICO = 0,
    ERROR_SINTACTICO,
    ERROR_SEMANTICO
} ErrorType;

// Estructura del nodo de error
typedef struct ErrorNode {
    ErrorType type;                    // Tipo de error
    int line;                         // Línea del error
    int column;                       // Columna del error
    char* message;                    // Mensaje descriptivo (Descripción)
    char* token_text;                 // Texto del token (si aplica)
    char* scope;                      // ✅ NUEVO: Ámbito del error
    struct ErrorNode* next;           // Puntero al siguiente nodo
} ErrorNode;

// Estructura del manejador de errores
typedef struct {
    ErrorNode* head;                  // Primer nodo de la lista
    ErrorNode* tail;                  // Último nodo (para inserción rápida)
    int lexico_count;                 // Contador de errores léxicos
    int sintactico_count;             // Contador de errores sintácticos
    int semantico_count;              // Contador de errores semánticos
    int total_count;                  // Total de errores
} ErrorManager;

// === FUNCIONES PÚBLICAS ===

// Crear y destruir manejador
ErrorManager* error_manager_create();
void error_manager_destroy(ErrorManager* manager);

// ✅ ACTUALIZAR FUNCIONES PARA INCLUIR ÁMBITO
void error_manager_add_lexico(ErrorManager* manager, int line, int column,
                             const char* message, const char* token_text);
void error_manager_add_sintactico(ErrorManager* manager, int line, int column,
                                 const char* message, const char* token_text);
void error_manager_add_semantico(ErrorManager* manager, int line, int column,
                                const char* message, const char* token_text,
                                const char* scope);

// Consultas
int error_manager_has_errors(const ErrorManager* manager);
int error_manager_get_total_count(const ErrorManager* manager);
int error_manager_get_lexico_count(const ErrorManager* manager);
int error_manager_get_sintactico_count(const ErrorManager* manager);
int error_manager_get_semantico_count(const ErrorManager* manager);

// Reportes
void error_manager_print_all(const ErrorManager* manager);
void error_manager_print_by_type(const ErrorManager* manager, ErrorType type);
char* error_manager_get_summary(const ErrorManager* manager);

// Limpiar errores
void error_manager_clear(ErrorManager* manager);

// Obtener nombre del tipo de error
const char* error_type_name(ErrorType type);

// ✅ NUEVA: Obtener ámbito formateado
const char* error_manager_get_scope_display(ErrorType type, const char* scope);

#endif // ERROR_MANAGER_H