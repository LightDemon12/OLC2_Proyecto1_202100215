//
// Created by lightdemon on 29/08/25.
//

#include "../../Headers/ast_visualizer.h"
#include "../../Headers/globals.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <time.h>
#include <errno.h>

// ========== CONSTANTES ==========

#define MAX_DOT_SIZE 1048576  // 1MB máximo para código DOT
#define MAX_PATH_SIZE 512
#define MAX_LABEL_SIZE 256

// ========== FUNCIONES PRIVADAS ==========

/* Escapar caracteres especiales para DOT */
static char* escape_for_dot(const char* input) {
    if (!input) return strdup("");

    size_t len = strlen(input);
    char* escaped = malloc(len * 2 + 1); // Peor caso: todos los chars se escapan
    size_t j = 0;

    for (size_t i = 0; i < len; i++) {
        switch (input[i]) {
            case '"':
                escaped[j++] = '\\';
                escaped[j++] = '"';
                break;
            case '\\':
                escaped[j++] = '\\';
                escaped[j++] = '\\';
                break;
            case '\n':
                escaped[j++] = '\\';
                escaped[j++] = 'n';
                break;
            case '\t':
                escaped[j++] = '\\';
                escaped[j++] = 't';
                break;
            default:
                escaped[j++] = input[i];
                break;
        }
    }

    escaped[j] = '\0';
    return escaped;
}

/* Verificar si directorio existe, si no, crearlo */
static bool ensure_directory_exists(const char* path) {
    struct stat st = {0};

    if (stat(path, &st) == -1) {
        if (mkdir(path, 0755) == -1) {
            printf("Error creando directorio %s: %s\n", path, strerror(errno));
            return false;
        }
        printf("Directorio creado: %s\n", path);
    }

    return true;
}

/* Obtener tiempo actual en milisegundos */
static double get_time_ms() {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return (ts.tv_sec * 1000.0) + (ts.tv_nsec / 1000000.0);
}

/* Generar DOT para un nodo específico (recursivo) */
static void generate_dot_for_node(ASTNode* node, char** dot_buffer, size_t* buffer_size,
                                  size_t* current_pos, int* node_id, int parent_id) {
    if (!node || !dot_buffer || !*dot_buffer) return;

    int current_node_id = (*node_id)++;
    char node_line[512];
    char label_parts[MAX_LABEL_SIZE];

    // Construir label del nodo
    snprintf(label_parts, sizeof(label_parts), "%s", node->type ? node->type : "UNKNOWN");

    // Agregar valor si existe
    if (node->value) {
        char* escaped_value = escape_for_dot(node->value);
        char value_part[128];
        snprintf(value_part, sizeof(value_part), "\\nValor: %s", escaped_value);
        strncat(label_parts, value_part, sizeof(label_parts) - strlen(label_parts) - 1);
        free(escaped_value);
    }

    // Agregar información de posición
    char position_part[64];
    snprintf(position_part, sizeof(position_part), "\\nLínea: %d, Col: %d", node->line, node->column);
    strncat(label_parts, position_part, sizeof(label_parts) - strlen(label_parts) - 1);

    // Generar línea del nodo
    snprintf(node_line, sizeof(node_line),
             "  node_%d [label=\"%s\"];\n", current_node_id, label_parts);

    // Verificar espacio en buffer
    size_t needed = strlen(node_line);
    if (*current_pos + needed >= *buffer_size - 1) {
        *buffer_size *= 2;
        *dot_buffer = realloc(*dot_buffer, *buffer_size);
        if (!*dot_buffer) {
            printf("Error: No se pudo expandir buffer DOT\n");
            return;
        }
    }

    // Agregar línea al buffer
    strcpy(*dot_buffer + *current_pos, node_line);
    *current_pos += needed;

    // Conectar con padre si existe
    if (parent_id >= 0) {
        char edge_line[128];
        snprintf(edge_line, sizeof(edge_line), "  node_%d -> node_%d;\n", parent_id, current_node_id);

        needed = strlen(edge_line);
        if (*current_pos + needed >= *buffer_size - 1) {
            *buffer_size *= 2;
            *dot_buffer = realloc(*dot_buffer, *buffer_size);
            if (!*dot_buffer) {
                printf("Error: No se pudo expandir buffer DOT para edge\n");
                return;
            }
        }

        strcpy(*dot_buffer + *current_pos, edge_line);
        *current_pos += needed;
    }

    // Procesar hijos recursivamente
    for (int i = 0; i < node->child_count; i++) {
        generate_dot_for_node(node->children[i], dot_buffer, buffer_size,
                             current_pos, node_id, current_node_id);
    }
}

// ========== FUNCIONES PÚBLICAS ==========

char* generate_dot(ASTNode* ast) {
    printf("=== GENERANDO CÓDIGO DOT PARA AST ===\n");

    if (!ast) {
        ast = ast_root;
        printf("Usando ast_root global: %p\n", (void*)ast_root);
    }

    if (!ast) {
        printf("ERROR: No hay AST disponible para generar DOT\n");
        return NULL;
    }

    // Inicializar buffer
    size_t buffer_size = 4096;
    char* dot_buffer = malloc(buffer_size);
    if (!dot_buffer) {
        printf("Error: No se pudo asignar memoria para buffer DOT\n");
        return NULL;
    }

    size_t current_pos = 0;
    int node_id = 0;

    // Header del archivo DOT
    const char* header =
        "digraph AST {\n"
        "  rankdir=TB;\n"
        "  node [fontname=\"Arial\", style=filled, shape=box, fillcolor=\"#E8F5E9\"];\n"
        "  edge [fontname=\"Arial\", color=\"#555555\"];\n"
        "  label=\"Árbol de Sintaxis Abstracta (AST)\";\n"
        "\n";

    strcpy(dot_buffer, header);
    current_pos = strlen(header);

    // Generar nodos recursivamente
    generate_dot_for_node(ast, &dot_buffer, &buffer_size, &current_pos, &node_id, -1);

    // Footer
    const char* footer = "\n}\n";
    size_t footer_len = strlen(footer);

    if (current_pos + footer_len >= buffer_size - 1) {
        buffer_size = current_pos + footer_len + 1;
        dot_buffer = realloc(dot_buffer, buffer_size);
    }

    strcpy(dot_buffer + current_pos, footer);

    printf("Código DOT generado (%zu caracteres, %d nodos)\n", strlen(dot_buffer), node_id);
    return dot_buffer;
}

bool clean_previous_files(const char* base_path, const char* format) {
    char file_path[MAX_PATH_SIZE];
    bool all_cleaned = true;

    // Limpiar archivo DOT
    snprintf(file_path, sizeof(file_path), "%s/AST.dot", base_path);
    if (access(file_path, F_OK) == 0) {
        if (unlink(file_path) == 0) {
            printf("Archivo eliminado: AST.dot\n");
        } else {
            printf("Advertencia: No se pudo eliminar AST.dot\n");
            all_cleaned = false;
        }
    }

    // Limpiar imagen anterior
    snprintf(file_path, sizeof(file_path), "%s/AST.%s", base_path, format);
    if (access(file_path, F_OK) == 0) {
        if (unlink(file_path) == 0) {
            printf("Archivo eliminado: AST.%s\n", format);
        } else {
            printf("Advertencia: No se pudo eliminar AST.%s\n", format);
            all_cleaned = false;
        }
    }

    // Limpiar otros formatos posibles
    const char* formats[] = {"png", "svg", "jpg", "pdf"};
    for (int i = 0; i < 4; i++) {
        if (strcmp(formats[i], format) != 0) {
            snprintf(file_path, sizeof(file_path), "%s/AST.%s", base_path, formats[i]);
            if (access(file_path, F_OK) == 0) {
                if (unlink(file_path) == 0) {
                    printf("Archivo eliminado: AST.%s\n", formats[i]);
                }
            }
        }
    }

    return all_cleaned;
}

bool check_graphviz_available() {
    int result = system("dot -V 2>/dev/null");
    return (result == 0);
}

ASTVisualizationResult* generate_ast_visual(ASTNode* ast, const char* format) {
    double start_time = get_time_ms();

    printf("=== GENERANDO VISUALIZACIÓN DEL AST ===\n");
    printf("Formato: %s\n", format ? format : "png");

    // Crear resultado
    ASTVisualizationResult* result = malloc(sizeof(ASTVisualizationResult));
    memset(result, 0, sizeof(ASTVisualizationResult));
    result->success = false;

    // Usar formato por defecto si no se especifica
    if (!format) format = "png";

    // Verificar Graphviz
    if (!check_graphviz_available()) {
        printf("ERROR: Graphviz no está disponible. Instale con: sudo apt install graphviz\n");
        return result;
    }

    // Usar AST global si no se proporciona uno
    if (!ast) {
        ast = ast_root;
        printf("Usando ast_root global\n");
    }

    if (!ast) {
        printf("ERROR: No hay AST disponible\n");
        return result;
    }

    // Crear directorio
    const char* base_path = "../Logic/AST";
    if (!ensure_directory_exists(base_path)) {
        printf("ERROR: No se pudo crear directorio %s\n", base_path);
        return result;
    }

    // Limpiar archivos anteriores
    printf("Limpiando archivos anteriores...\n");
    clean_previous_files(base_path, format);

    // Generar código DOT
    printf("Generando código DOT...\n");
    char* dot_content = generate_dot(ast);
    if (!dot_content) {
        printf("ERROR: No se pudo generar código DOT\n");
        return result;
    }

    // Rutas de archivos
    char dot_file[MAX_PATH_SIZE];
    char image_file[MAX_PATH_SIZE];
    snprintf(dot_file, sizeof(dot_file), "%s/AST.dot", base_path);
    snprintf(image_file, sizeof(image_file), "%s/AST.%s", base_path, format);

    // Guardar archivo DOT
    FILE* fp = fopen(dot_file, "w");
    if (!fp) {
        printf("ERROR: No se pudo crear archivo DOT: %s\n", strerror(errno));
        free(dot_content);
        return result;
    }

    fprintf(fp, "%s", dot_content);
    fclose(fp);
    printf("Archivo DOT guardado: %s\n", dot_file);

    // Generar imagen con Graphviz
    char command[MAX_PATH_SIZE * 2];
    snprintf(command, sizeof(command), "dot -T%s -Gdpi=300 \"%s\" -o \"%s\"",
             format, dot_file, image_file);

    printf("Ejecutando Graphviz: %s\n", command);
    int cmd_result = system(command);

    if (cmd_result != 0) {
        printf("ERROR: Graphviz falló con código %d\n", cmd_result);
        free(dot_content);
        return result;
    }

    // Verificar que la imagen se creó
    if (access(image_file, F_OK) != 0) {
        printf("ERROR: La imagen no se generó: %s\n", image_file);
        free(dot_content);
        return result;
    }

    // Llenar resultado
    result->dot_file_path = strdup(dot_file);
    result->image_file_path = strdup(image_file);
    result->dot_content = dot_content;
    result->generation_time_ms = get_time_ms() - start_time;
    result->success = true;

    printf("=== VISUALIZACIÓN COMPLETADA ===\n");
    printf("Tiempo: %.2f ms\n", result->generation_time_ms);
    printf("DOT: %s\n", result->dot_file_path);
    printf("Imagen: %s\n", result->image_file_path);

    return result;
}

ASTVisualizationResult* generate_global_ast_visual(const char* format) {
    return generate_ast_visual(NULL, format);
}

void print_visualization_info(ASTVisualizationResult* result) {
    if (!result) {
        printf("Resultado de visualización: NULL\n");
        return;
    }

    printf("=== INFORMACIÓN DE VISUALIZACIÓN ===\n");
    printf("Éxito: %s\n", result->success ? "SÍ" : "NO");

    if (result->success) {
        printf("Tiempo generación: %.2f ms\n", result->generation_time_ms);
        printf("Archivo DOT: %s\n", result->dot_file_path ? result->dot_file_path : "N/A");
        printf("Archivo imagen: %s\n", result->image_file_path ? result->image_file_path : "N/A");
        printf("Tamaño DOT: %zu caracteres\n",
               result->dot_content ? strlen(result->dot_content) : 0);
    } else {
        printf("Error: No se pudo generar la visualización\n");
    }
    printf("==================================\n");
}

void free_visualization_result(ASTVisualizationResult* result) {
    if (!result) return;

    if (result->dot_file_path) free(result->dot_file_path);
    if (result->image_file_path) free(result->image_file_path);
    if (result->dot_content) free(result->dot_content);

    free(result);
}

