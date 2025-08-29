//
// Created by lightdemon on 29/08/25.
//

#ifndef AST_VISUALIZER_H
#define AST_VISUALIZER_H

#include "ast.h"
#include <stdbool.h>

// ========== ESTRUCTURAS ==========

typedef struct {
    char* dot_file_path;
    char* image_file_path;
    char* dot_content;
    double generation_time_ms;
    bool success;
} ASTVisualizationResult;

// ========== FUNCIONES PRINCIPALES ==========

/* Generar visualización completa del AST */
ASTVisualizationResult* generate_ast_visual(ASTNode* ast, const char* format);

/* Generar solo código DOT */
char* generate_dot(ASTNode* ast);

/* Limpiar archivos anteriores */
bool clean_previous_files(const char* base_path, const char* format);

/* Liberar resultado de visualización */
void free_visualization_result(ASTVisualizationResult* result);

/* Verificar disponibilidad de Graphviz */
bool check_graphviz_available();

// ========== FUNCIONES DE UTILIDAD ==========

/* Generar visualización usando ast_root global */
ASTVisualizationResult* generate_global_ast_visual(const char* format);

/* Imprimir información del resultado */
void print_visualization_info(ASTVisualizationResult* result);

#endif // AST_VISUALIZER_H