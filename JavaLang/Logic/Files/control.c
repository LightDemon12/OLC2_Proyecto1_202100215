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

// ✅ INCLUDES CORRECTOS
#include "../../Headers/mainview.h"
#include "../../Headers/control.h"
#include "../../Headers/error_manager.h"

// ✅ DECLARACIÓN GLOBAL ÚNICA (quitar extern duplicado)
ErrorManager* global_error_manager = NULL;

// Función para obtener directorio de trabajo relativo
static const char* get_working_directory() {
    static char working_dir[256];
    static int initialized = 0;

    if (!initialized) {
        // Detectar si estamos en cmake-build-debug
        if (access("Logic/Analyzer", F_OK) == 0) {
            // Estamos en la raíz del proyecto
            strcpy(working_dir, ".");
        } else if (access("../Logic/Analyzer", F_OK) == 0) {
            // Estamos en cmake-build-debug
            strcpy(working_dir, "..");
        } else {
            // Fallback
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

        // Solo permitir caracteres ASCII imprimibles y espacios
        if (c >= 32 && c <= 126) {
            output[out_pos++] = c;
        } else if (c == '\n' || c == '\t') {
            output[out_pos++] = c;
        } else {
            // Reemplazar caracteres problemáticos con '?'
            output[out_pos++] = '?';
        }
    }

    output[out_pos] = '\0';
    return output;
}

static int execute_command(const char* command, const char* working_dir) {
    char full_command[1024];
    const char* base_dir = get_working_directory();

    if (working_dir) {
        snprintf(full_command, sizeof(full_command), "cd %s/%s && %s",
                base_dir, working_dir, command);
    } else {
        snprintf(full_command, sizeof(full_command), "cd %s && %s",
                base_dir, command);
    }

    printf("Ejecutando: %s\n", full_command);

    int result = system(full_command);
    return WEXITSTATUS(result);
}

static void clean_generated_files(MainView* mainview) {
    const char* analyzer_dir = "Logic/Analyzer";

    printf("Limpiando archivos generados...\n");
    if (mainview) {
        mainview_append_output(mainview, "Limpiando archivos generados...");
    }

    execute_command("rm -f lex.yy.c", analyzer_dir);
    execute_command("rm -f lexer", analyzer_dir);
    execute_command("rm -f parser.tab.c parser.tab.h", analyzer_dir);

    printf("Archivos limpiados\n");
    if (mainview) {
        mainview_append_output(mainview, "Archivos limpiados");
    }
}

static int build_lexer(MainView* mainview) {
    const char* analyzer_dir = "Logic/Analyzer";
    int result;

    printf("Generando lexer...\n");
    if (mainview) {
        mainview_append_output(mainview, "Generando lexer con Flex...");
    }

    result = execute_command("flex lexer.l", analyzer_dir);
    if (result != 0) {
        printf("Error generando lexer con flex\n");
        if (mainview) {
            mainview_append_output(mainview, "Error generando lexer con Flex");
        }
        return -1;
    }

    printf("Compilando lexer...\n");
    if (mainview) {
        mainview_append_output(mainview, "Compilando lexer...");
    }

    const char* compile_cmd = "gcc lex.yy.c ../../Utils/tokens.c ../../Utils/error_manager.c -lfl -o lexer";

    result = execute_command(compile_cmd, analyzer_dir);
    if (result != 0) {
        printf("Error compilando lexer\n");
        if (mainview) {
            mainview_append_output(mainview, "Error compilando lexer");
        }
        return -1;
    }

    printf("Lexer generado exitosamente\n");
    if (mainview) {
        mainview_append_output(mainview, "Lexer compilado exitosamente");
    }
    return 0;
}

static char* create_temp_file(const char* content) {
    // Generar nombre único basado en tiempo + PID + contador
    static int counter = 0;
    char* temp_filename = malloc(128);

    // Crear nombre único cada vez
    snprintf(temp_filename, 128, "/tmp/javalang_%ld_%d_%d.tmp",
             (long)time(NULL), getpid(), ++counter);

    int fd = open(temp_filename, O_CREAT | O_WRONLY | O_TRUNC, 0644);

    if (fd == -1) {
        printf("Error creando archivo temporal: %s\n", strerror(errno));
        free(temp_filename);
        return NULL;
    }

    // Escribir contenido
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

// ✅ PARSEAR OUTPUT DEL LEXER PARA POBLAR ERROR_MANAGER
static void parse_lexer_output_for_errors(const char* line) {
    if (!global_error_manager || !line) return;

    // Buscar patrones de errores en la salida
    if (strstr(line, "[LEXICO]")) {
        // Ejemplo: "1. [LEXICO] Linea 1, Columna 2: Caracter no reconocido: '@' (ASCII: 64) | Token: '@'"
        int line_num = 1, column_num = 1;
        char error_msg[256] = "Error lexico detectado";
        char token_text[64] = "";

        // Intentar parsear línea y columna
        sscanf(line, "%*d. [LEXICO] Linea %d, Columna %d:", &line_num, &column_num);
        
        // Buscar el mensaje de error
        char* msg_start = strstr(line, ": ");
        if (msg_start) {
            msg_start += 2; // Saltar ": "
            char* token_start = strstr(msg_start, " | Token: ");
            if (token_start) {
                size_t msg_len = token_start - msg_start;
                if (msg_len < sizeof(error_msg)) {
                    strncpy(error_msg, msg_start, msg_len);
                    error_msg[msg_len] = '\0';
                }
                
                // Extraer token
                token_start += 10; // Saltar " | Token: "
                if (strlen(token_start) < sizeof(token_text)) {
                    strcpy(token_text, token_start);
                    // Remover comillas si las hay
                    if (token_text[0] == '\'' && token_text[strlen(token_text)-1] == '\'') {
                        token_text[strlen(token_text)-1] = '\0';
                        memmove(token_text, token_text + 1, strlen(token_text));
                    }
                }
            }
        }

        error_manager_add_lexico(global_error_manager, line_num, column_num, 
                                error_msg, token_text);
    }
}

static int analyze_code_from_buffer_with_output(GtkTextBuffer* buffer, MainView* mainview) {
    GtkTextIter start, end;
    char* content;
    char* temp_file;
    char command[512];
    FILE* pipe;
    char line[256];
    int token_count = 0;
    int error_count = 0;
    const char* base_dir = get_working_directory();
    cleanup_old_temp_files();

    // ✅ INICIALIZAR GLOBAL ERROR MANAGER
    if (!global_error_manager) {
        global_error_manager = error_manager_create();
    } else {
        error_manager_clear(global_error_manager);
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
        mainview_append_output(mainview, "─────────────────────────");
    }

    temp_file = create_temp_file(content);
    if (!temp_file) {
        if (mainview) {
            mainview_append_output(mainview, "Error creando archivo temporal");
        }
        g_free(content);
        return -1;
    }

    snprintf(command, sizeof(command), "cd %s/Logic/Analyzer && ./lexer %s",
             base_dir, temp_file);
    pipe = popen(command, "r");

    if (!pipe) {
        if (mainview) {
            mainview_append_output(mainview, "Error ejecutando lexer");
        }
        unlink(temp_file);
        free(temp_file);
        g_free(content);
        return -1;
    }

    while (fgets(line, sizeof(line), pipe) != NULL) {
        line[strcspn(line, "\n")] = 0;

        if (strlen(line) > 0) {
            printf("%s\n", line);
            if (mainview) {
                char* clean_line = sanitize_utf8(line);
                mainview_append_output(mainview, clean_line);
                free(clean_line);
            }

            // ✅ PARSEAR ERRORES PARA GLOBAL_ERROR_MANAGER
            parse_lexer_output_for_errors(line);

            // Contar tokens y errores
            if (strstr(line, "Token:")) {
                token_count++;
                if (strstr(line, "TOKEN_ERROR")) {
                    error_count++;
                }
            }

            if (strstr(line, "[LEXICO]") || strstr(line, "Caracter no reconocido")) {
                error_count++;
            }
        }
    }

    int result = pclose(pipe);

    if (mainview) {
        char summary[256];
        mainview_append_output(mainview, "─────────────────────────");

        if (error_count > 0) {
            snprintf(summary, sizeof(summary), "Tokens: %d | Errores: %d",
                    token_count, error_count);
        } else {
            snprintf(summary, sizeof(summary), "Tokens: %d | Sin errores",
                    token_count);
        }
        mainview_append_output(mainview, summary);
    }

    unlink(temp_file);
    free(temp_file);
    g_free(content);

    return (error_count > 0) ? -1 : result;
}

int control_rebuild_and_analyze_with_output(GtkTextBuffer* code_buffer, MainView* mainview) {
    printf("Iniciando rebuild del lexer...\n");

    clean_generated_files(mainview);

    if (build_lexer(mainview) != 0) {
        return -1;
    }

    if (mainview) {
        mainview_append_output(mainview, "Analizando codigo...");
    }

    return analyze_code_from_buffer_with_output(code_buffer, mainview);
}

int control_rebuild_and_analyze(GtkTextBuffer* code_buffer) {
    return control_rebuild_and_analyze_with_output(code_buffer, NULL);
}

int control_analyze_only(GtkTextBuffer* code_buffer) {
    printf("Analizando codigo...\n");
    return analyze_code_from_buffer_with_output(code_buffer, NULL);
}