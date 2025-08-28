//
// Created by lightdemon on 21/08/25.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <gtk/gtk.h>
#include <fcntl.h>
#include <time.h>
#include <errno.h>

// INCLUDES CORRECTOS
#include "../../Headers/mainview.h"
#include "../../Headers/control.h"
#include "../../Headers/globals.h"  // ← YA DECLARA LAS VARIABLES COMO EXTERN

// DECLARAR FUNCIÓN DEL PARSER GENERADO POR BISON
extern int parse_java_code(const char* filename);

// Función para obtener directorio de trabajo relativo
static const char* get_working_directory() {
    static char working_dir[256];
    static int initialized = 0;

    if (!initialized) {
        if (access("Logic/Analyzer", F_OK) == 0) {
            strcpy(working_dir, ".");
        } else if (access("../Logic/Analyzer", F_OK) == 0) {
            strcpy(working_dir, "..");
        } else {
            strcpy(working_dir, ".");
        }

        initialized = 1;
        printf("Directorio de trabajo: %s\n", working_dir);
    }

    return working_dir;
}

// Función para validar y limpiar UTF-8
static char* sanitize_utf8(const char* input) {
    if (!input) return NULL;

    size_t len = strlen(input);
    char* output = malloc(len + 1);
    size_t out_pos = 0;

    for (size_t i = 0; i < len; i++) {
        unsigned char c = (unsigned char)input[i];

        if (c >= 32 && c <= 126) {
            output[out_pos++] = c;
        } else if (c == '\n' || c == '\t') {
            output[out_pos++] = c;
        } else {
            output[out_pos++] = '?';
        }
    }

    output[out_pos] = '\0';
    return output;
}

static char* create_temp_file(const char* content) {
    static int counter = 0;
    char* temp_filename = malloc(128);

    snprintf(temp_filename, 128, "/tmp/javalang_%ld_%d_%d.tmp",
             (long)time(NULL), getpid(), ++counter);

    int fd = open(temp_filename, O_CREAT | O_WRONLY | O_TRUNC, 0644);

    if (fd == -1) {
        printf("Error creando archivo temporal: %s\n", strerror(errno));
        free(temp_filename);
        return NULL;
    }

    ssize_t written = write(fd, content, strlen(content));
    if (written == -1) {
        printf("Error escribiendo archivo temporal: %s\n", strerror(errno));
        close(fd);
        unlink(temp_filename);
        free(temp_filename);
        return NULL;
    }

    close(fd);

    printf("Archivo temporal creado: %s\n", temp_filename);
    return temp_filename;
}

static void cleanup_old_temp_files() {
    char command[256];
    snprintf(command, sizeof(command),
             "find /tmp -name 'javalang_*' -mmin +60 -delete 2>/dev/null || true");
    system(command);
}

static void parse_analyzer_output_for_errors(const char* line) {
    if (!global_error_manager || !line) return;

    /* PARSEAR ERRORES EN FORMATO: [ERROR_TIPO] linea|columna|mensaje|token */
    if (strstr(line, "[ERROR_LEXICO]") ||
        strstr(line, "[ERROR_SINTACTICO]") ||
        strstr(line, "[ERROR_SEMANTICO]")) {

        char error_type_str[32] = "";
        int line_num = 0, column_num = 0;
        char message[256] = "";
        char token_text[64] = "";

        /* EXTRAER TIPO DE ERROR */
        if (strstr(line, "[ERROR_LEXICO]")) {
            strcpy(error_type_str, "LEXICO");
        } else if (strstr(line, "[ERROR_SINTACTICO]")) {
            strcpy(error_type_str, "SINTACTICO");
        } else if (strstr(line, "[ERROR_SEMANTICO]")) {
            strcpy(error_type_str, "SEMANTICO");
        }

        /* ENCONTRAR INICIO DE DATOS */
        char* data_start = strchr(line, ']');
        if (data_start) {
            data_start++; /* Saltar el ] */
            while (*data_start == ' ') data_start++; /* Saltar espacios */

            /* PARSEAR: linea|columna|mensaje|token */
            int parsed = sscanf(data_start, "%d|%d|%255[^|]|%63s",
                               &line_num, &column_num, message, token_text);

            if (parsed >= 3) {
                printf("DEBUG CONTROL: Parseado %s - Linea: %d, Col: %d, Msg: '%s', Token: '%s'\n",
                       error_type_str, line_num, column_num, message, token_text);

                /* AGREGAR AL GLOBAL_ERROR_MANAGER */
                if (strcmp(error_type_str, "LEXICO") == 0) {
                    error_manager_add_lexico(global_error_manager, line_num, column_num,
                                           message, token_text);
                } else if (strcmp(error_type_str, "SINTACTICO") == 0) {
                    error_manager_add_sintactico(global_error_manager, line_num, column_num,
                                                message, token_text);
                } else if (strcmp(error_type_str, "SEMANTICO") == 0) {
                    error_manager_add_semantico(global_error_manager, line_num, column_num,
                                              message, token_text, "Sin ambito");
                }
            }
        }
    }
}

// FUNCIÓN PRINCIPAL DE ANÁLISIS - USANDO PARSER INTEGRADO EN MISMO PROCESO
static int analyze_code_from_buffer_with_output(GtkTextBuffer* buffer, MainView* mainview) {
    GtkTextIter start, end;
    char* content;
    char* temp_file;
    int result;
    cleanup_old_temp_files();

    // LIMPIAR ERROR MANAGER AL INICIO
    if (!global_error_manager) {
        global_error_manager = error_manager_create();
    } else {
        error_manager_clear(global_error_manager);
    }

    /* LIMPIAR AST GLOBAL AL INICIO */
    if (ast_root) {
        free_node(ast_root);
        ast_root = NULL;
    }

    if (!buffer) {
        printf("Buffer de codigo no valido\n");
        if (mainview) {
            mainview_append_output(mainview, "Buffer de codigo no valido");
        }
        return -1;
    }

    gtk_text_buffer_get_bounds(buffer, &start, &end);
    content = gtk_text_buffer_get_text(buffer, &start, &end, FALSE);

    if (!content || strlen(content) == 0) {
        printf("No hay codigo para analizar\n");
        if (mainview) {
            mainview_append_output(mainview, "No hay codigo para analizar");
        }
        g_free(content);
        return -1;
    }

    if (mainview) {
        char buffer_msg[512];
        snprintf(buffer_msg, sizeof(buffer_msg), "Codigo a analizar (%zu caracteres)", strlen(content));
        mainview_append_output(mainview, buffer_msg);
        mainview_append_output(mainview, "==========================================");
        mainview_append_output(mainview, "Iniciando analisis lexico y sintactico...");
    }

    temp_file = create_temp_file(content);
    if (!temp_file) {
        if (mainview) {
            mainview_append_output(mainview, "Error creando archivo temporal");
        }
        g_free(content);
        return -1;
    }

    /* LLAMAR AL PARSER DIRECTAMENTE EN EL MISMO PROCESO ← INTEGRADO CON BISON/FLEX */
    printf("DEBUG: Llamando parse_java_code directamente...\n");
    if (mainview) {
        mainview_append_output(mainview, "Ejecutando analizador lexico-sintactico integrado...");
    }

    result = parse_java_code(temp_file);

    /* VERIFICAR SI EL AST SE CONSTRUYÓ CORRECTAMENTE */
    printf("DEBUG: AST después del análisis: %s\n",
           ast_root ? "Disponible" : "NULL");

    /* MOSTRAR RESULTADO */
    if (mainview) {
        int actual_errors = 0;
        if (global_error_manager) {
            actual_errors = error_manager_get_total_count(global_error_manager);
            printf("DEBUG CONTROL: Global error manager tiene %d errores parseados\n", actual_errors);
        }

        mainview_append_output(mainview, "==========================================");
        if (actual_errors > 0) {
            char error_msg[256];
            snprintf(error_msg, sizeof(error_msg), "ERRORES ENCONTRADOS: %d", actual_errors);
            mainview_append_output(mainview, error_msg);
        } else if (result == 0) {
            mainview_append_output(mainview, "EXITO: Analisis lexico-sintactico completado");
        } else {
            mainview_append_output(mainview, "ERROR: Fallo en analisis lexico-sintactico");
        }
    }

    unlink(temp_file);
    free(temp_file);
    g_free(content);

    return result;
}

// FUNCIÓN PRINCIPAL SIMPLIFICADA - NO NECESITA REBUILD (BISON/FLEX YA INTEGRADOS)
int control_rebuild_and_analyze_with_output(GtkTextBuffer* code_buffer, MainView* mainview) {
    printf("Iniciando analisis lexico-sintactico integrado...\n");

    if (mainview) {
        mainview_append_output(mainview, "=== ANALIZADOR JAVA INTEGRADO ===");
        mainview_append_output(mainview, "Parser y Lexer compilados con el proyecto");
        mainview_append_output(mainview, "==========================================");
    }

    return analyze_code_from_buffer_with_output(code_buffer, mainview);
}

// MANTENER FUNCIONES EXISTENTES PARA COMPATIBILIDAD
int control_rebuild_and_analyze(GtkTextBuffer* code_buffer) {
    return control_rebuild_and_analyze_with_output(code_buffer, NULL);
}

int control_analyze_only(GtkTextBuffer* code_buffer) {
    printf("Analizando codigo con analizador integrado...\n");
    return analyze_code_from_buffer_with_output(code_buffer, NULL);
}

// FUNCIÓN DE PRUEBA SIMPLIFICADA
int control_test_parser(MainView* mainview) {
    printf("Probando analizador lexico-sintactico integrado...\n");

    if (mainview) {
        mainview_append_output(mainview, "=== PRUEBA DEL ANALIZADOR INTEGRADO ===");
        mainview_append_output(mainview, "Analizador lexico-sintactico listo");
        mainview_append_output(mainview, "Parser: Compilado con Bison");
        mainview_append_output(mainview, "Lexer: Compilado con Flex");
        mainview_append_output(mainview, "AST: Sistema de nodos integrado");
        mainview_append_output(mainview, "Error Manager: Sistema de errores integrado");
        mainview_append_output(mainview, "==========================================");
        mainview_append_output(mainview, "Use 'Reconstruir y Analizar' para analizar codigo");
    }

    /* VERIFICAR QUE EL SISTEMA ESTÉ LISTO */
    if (!global_error_manager) {
        global_error_manager = error_manager_create();
    }

    printf("Sistema integrado listo para análisis\n");
    return 0;
}

/* FUNCIÓN ADICIONAL PARA OBTENER ESTADO DEL AST */
int control_get_ast_status() {
    if (ast_root) {
        printf("AST Status: Disponible (%s)\n", ast_root->type ? ast_root->type : "Sin tipo");
        return 1;
    } else {
        printf("AST Status: No disponible\n");
        return 0;
    }
}

/* FUNCIÓN ADICIONAL PARA OBTENER ESTADO DE ERRORES */
int control_get_error_count() {
    if (global_error_manager) {
        return error_manager_get_total_count(global_error_manager);
    }
    return 0;
}

/* FUNCIÓN ADICIONAL PARA LIMPIAR ESTADO */
void control_reset_state() {
    printf("Reiniciando estado del analizador...\n");

    if (ast_root) {
        free_node(ast_root);
        ast_root = NULL;
    }

    if (global_error_manager) {
        error_manager_clear(global_error_manager);
    }

    printf("Estado reiniciado\n");
}