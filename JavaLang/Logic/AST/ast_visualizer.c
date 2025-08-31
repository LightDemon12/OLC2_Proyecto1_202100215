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

// ========== CONSTANTES MEJORADAS ==========

#define MAX_PATH_SIZE 512
#define MAX_LABEL_SIZE 512
#define INITIAL_BUFFER_SIZE 8192    // Empezar con 8KB
#define BUFFER_GROWTH_FACTOR 2      // Duplicar cuando sea necesario
#define MAX_TOTAL_BUFFER 50*1024*1024  // 50MB máximo total

// ========== ESTRUCTURA PARA BUFFER DINÁMICO ==========

typedef struct {
    char* data;
    size_t size;
    size_t capacity;
    bool error;
} DynamicBuffer;

// ========== FUNCIONES PARA BUFFER DINÁMICO ==========

static DynamicBuffer* buffer_create(size_t initial_capacity) {
    DynamicBuffer* buffer = malloc(sizeof(DynamicBuffer));
    if (!buffer) return NULL;

    buffer->data = malloc(initial_capacity);
    if (!buffer->data) {
        free(buffer);
        return NULL;
    }

    buffer->size = 0;
    buffer->capacity = initial_capacity;
    buffer->error = false;
    buffer->data[0] = '\0';

    return buffer;
}

static bool buffer_ensure_capacity(DynamicBuffer* buffer, size_t needed_size) {
    if (buffer->error) return false;

    size_t required_capacity = buffer->size + needed_size + 1;

    if (required_capacity <= buffer->capacity) {
        return true; // Ya hay suficiente espacio
    }

    // Calcular nueva capacidad
    size_t new_capacity = buffer->capacity;
    while (new_capacity < required_capacity) {
        new_capacity *= BUFFER_GROWTH_FACTOR;

        // Verificar límite máximo
        if (new_capacity > MAX_TOTAL_BUFFER) {
            printf("ADVERTENCIA: AST demasiado grande, limitando a %d MB\n", MAX_TOTAL_BUFFER / (1024*1024));
            new_capacity = MAX_TOTAL_BUFFER;
            break;
        }
    }

    // Reallocar
    char* new_data = realloc(buffer->data, new_capacity);
    if (!new_data) {
        printf("ERROR: No se pudo expandir buffer a %zu bytes\n", new_capacity);
        buffer->error = true;
        return false;
    }

    buffer->data = new_data;
    buffer->capacity = new_capacity;

    printf("DEBUG: Buffer expandido a %zu bytes (%.2f MB)\n",
           new_capacity, (double)new_capacity / (1024*1024));

    return true;
}

static bool buffer_append(DynamicBuffer* buffer, const char* text) {
    if (buffer->error || !text) return false;

    size_t text_len = strlen(text);

    if (!buffer_ensure_capacity(buffer, text_len)) {
        return false;
    }

    strcpy(buffer->data + buffer->size, text);
    buffer->size += text_len;

    return true;
}

static void buffer_destroy(DynamicBuffer* buffer) {
    if (!buffer) return;

    if (buffer->data) {
        free(buffer->data);
    }
    free(buffer);
}

// ========== FUNCIONES DE UTILIDAD ==========

static char* escape_for_dot(const char* input) {
    if (!input) return strdup("");

    size_t len = strlen(input);
    char* escaped = malloc(len * 3 + 1); // Peor caso: todos los chars se triplican
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
            case '\r':
                escaped[j++] = '\\';
                escaped[j++] = 'r';
                break;
            case '{':
            case '}':
            case '<':
            case '>':
            case '|':
                escaped[j++] = '\\';
                escaped[j++] = input[i];
                break;
            default:
                escaped[j++] = input[i];
                break;
        }
    }

    escaped[j] = '\0';
    return escaped;
}

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

static double get_time_ms() {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return (ts.tv_sec * 1000.0) + (ts.tv_nsec / 1000000.0);
}

// ========== GENERACIÓN DOT SIMPLIFICADA ==========

static void generate_dot_for_node_optimized(ASTNode* node, DynamicBuffer* buffer,
                                           int* node_id, int parent_id, int depth) {
    if (!node || buffer->error) return;

    int current_node_id = (*node_id)++;

    // Limitar profundidad para evitar explosión de nodos
    if (depth > 100) {
        char warning[256];
        snprintf(warning, sizeof(warning),
                "  node_%d [label=\"... (profundidad máxima alcanzada)\"];\n",
                current_node_id);
        buffer_append(buffer, warning);
        return;
    }

    // Crear label del nodo de forma más compacta
    char* escaped_type = escape_for_dot(node->type ? node->type : "UNKNOWN");
    char label_buffer[MAX_LABEL_SIZE];

    // Label base
    snprintf(label_buffer, sizeof(label_buffer), "%s", escaped_type);

    // Agregar valor si existe (truncado para evitar labels enormes)
    if (node->value) {
        char* escaped_value = escape_for_dot(node->value);
        char truncated_value[100];

        if (strlen(escaped_value) > 80) {
            strncpy(truncated_value, escaped_value, 77);
            strcpy(truncated_value + 77, "...");
        } else {
            strcpy(truncated_value, escaped_value);
        }

        char value_part[150];
        snprintf(value_part, sizeof(value_part), "\\n%s", truncated_value);
        strncat(label_buffer, value_part, sizeof(label_buffer) - strlen(label_buffer) - 1);

        free(escaped_value);
    }

    // Crear nodo con estilo simple y consistente
    char node_line[1024];
    snprintf(node_line, sizeof(node_line),
             "  node_%d [label=\"%s\"];\n",
             current_node_id, label_buffer);

    if (!buffer_append(buffer, node_line)) {
        free(escaped_type);
        return;
    }

    // Conectar con padre
    if (parent_id >= 0) {
        char edge_line[128];
        snprintf(edge_line, sizeof(edge_line),
                "  node_%d -> node_%d;\n", parent_id, current_node_id);
        buffer_append(buffer, edge_line);
    }

    // Procesar hijos recursivamente
    for (int i = 0; i < node->child_count && !buffer->error; i++) {
        generate_dot_for_node_optimized(node->children[i], buffer,
                                       node_id, current_node_id, depth + 1);
    }

    free(escaped_type);
}

// ========== FUNCIONES PÚBLICAS MEJORADAS ==========

char* generate_dot(ASTNode* ast) {
    printf("=== GENERANDO CÓDIGO DOT PARA AST GRANDE ===\n");

    if (!ast) {
        ast = ast_root;
        printf("Usando ast_root global: %p\n", (void*)ast_root);
    }

    if (!ast) {
        printf("ERROR: No hay AST disponible para generar DOT\n");
        return NULL;
    }

    // Crear buffer dinámico
    DynamicBuffer* buffer = buffer_create(INITIAL_BUFFER_SIZE);
    if (!buffer) {
        printf("ERROR: No se pudo crear buffer dinámico\n");
        return NULL;
    }

    // Header del archivo DOT simplificado
    const char* header =
        "digraph AST {\n"
        "  rankdir=TB;\n"
        "  node [fontname=\"Arial, sans-serif\", style=filled, shape=box, fillcolor=\"#E8F5E9\"];\n"
        "  edge [fontname=\"Arial, sans-serif\", color=\"#555555\", arrowsize=0.7];\n"
        "  graph [fontname=\"Arial, sans-serif\", labelloc=t, fontsize=16];\n"
        "  label=\"AST - Árbol de Sintaxis Abstracta\";\n"
        "  splines=ortho;\n"
        "  concentrate=true;\n"
        "\n";

    if (!buffer_append(buffer, header)) {
        buffer_destroy(buffer);
        return NULL;
    }

    // Generar nodos recursivamente
    int node_id = 0;
    generate_dot_for_node_optimized(ast, buffer, &node_id, -1, 0);

    if (buffer->error) {
        printf("ERROR: Error durante generación DOT\n");
        buffer_destroy(buffer);
        return NULL;
    }

    // Footer
    const char* footer = "\n}\n";
    if (!buffer_append(buffer, footer)) {
        buffer_destroy(buffer);
        return NULL;
    }

    // Extraer resultado
    char* result = strdup(buffer->data);
    size_t final_size = buffer->size;

    buffer_destroy(buffer);

    printf("Código DOT generado: %.2f MB, %d nodos\n",
           (double)final_size / (1024*1024), node_id);

    return result;
}

ASTVisualizationResult* generate_ast_visual(ASTNode* ast, const char* format) {
    double start_time = get_time_ms();

    printf("=== GENERANDO VISUALIZACIÓN AST ESCALABLE ===\n");
    printf("Formato: %s\n", format ? format : "svg");

    // Crear resultado
    ASTVisualizationResult* result = malloc(sizeof(ASTVisualizationResult));
    memset(result, 0, sizeof(ASTVisualizationResult));
    result->success = false;

    // Usar SVG por defecto para ASTs grandes (mejor escalabilidad)
    if (!format) format = "svg";

    // Verificar Graphviz
    if (system("dot -V 2>/dev/null") != 0) {
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

    // Generar código DOT
    printf("Generando código DOT optimizado...\n");
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
    printf("Archivo DOT guardado: %s (%.2f MB)\n", dot_file,
           (double)strlen(dot_content) / (1024*1024));

    // Generar imagen con Graphviz (configuración para ASTs grandes)
    char command[MAX_PATH_SIZE * 2 + 200];

    if (strcmp(format, "svg") == 0) {
        // SVG: Mejor para ASTs grandes, escalable
        snprintf(command, sizeof(command),
                "dot -Tsvg -Gconcentrate=true -Gsplines=ortho -Goverlap=false \"%s\" -o \"%s\"",
                dot_file, image_file);
    } else if (strcmp(format, "png") == 0) {
        // PNG: Con configuración optimizada para tamaño
        snprintf(command, sizeof(command),
                "dot -Tpng -Gdpi=150 -Gsize=\"20,20!\" -Gconcentrate=true \"%s\" -o \"%s\"",
                dot_file, image_file);
    } else {
        // Otros formatos
        snprintf(command, sizeof(command),
                "dot -T%s -Gconcentrate=true \"%s\" -o \"%s\"",
                format, dot_file, image_file);
    }

    printf("Ejecutando Graphviz: %s\n", command);
    int cmd_result = system(command);

    if (cmd_result != 0) {
        printf("ADVERTENCIA: Graphviz reportó código %d (puede ser normal para ASTs grandes)\n", cmd_result);
        // No fallar inmediatamente, verificar si se creó el archivo
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
    printf("Tamaño DOT: %.2f MB\n", (double)strlen(dot_content) / (1024*1024));

    return result;
}

// ========== FUNCIONES EXISTENTES (sin cambios) ==========

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

    return all_cleaned;
}

bool check_graphviz_available() {
    int result = system("dot -V 2>/dev/null");
    return (result == 0);
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
        printf("Tamaño DOT: %.2f MB\n",
               result->dot_content ? (double)strlen(result->dot_content) / (1024*1024) : 0);
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