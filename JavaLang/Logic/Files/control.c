#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <gtk/gtk.h>

// INCLUIR mainview.h directamente
#include "../../Headers/mainview.h"
#include "../../Headers/control.h"

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
        printf("🔧 Directorio de trabajo: %s\n", working_dir);
    }

    return working_dir;
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

    printf("🔧 Ejecutando: %s\n", full_command);

    int result = system(full_command);
    return WEXITSTATUS(result);
}

static void clean_generated_files(MainView* mainview) {
    const char* analyzer_dir = "Logic/Analyzer";

    printf("🧹 Limpiando archivos generados...\n");
    if (mainview) {
        mainview_append_output(mainview, "🧹 Limpiando archivos generados...");
    }

    execute_command("rm -f lex.yy.c", analyzer_dir);
    execute_command("rm -f lexer", analyzer_dir);
    execute_command("rm -f parser.tab.c parser.tab.h", analyzer_dir);

    printf("✅ Archivos limpiados\n");
    if (mainview) {
        mainview_append_output(mainview, "✅ Archivos limpiados");
    }
}

static int build_lexer(MainView* mainview) {
    const char* analyzer_dir = "Logic/Analyzer";
    int result;

    printf("🔧 Generando lexer...\n");
    if (mainview) {
        mainview_append_output(mainview, "🔧 Generando lexer con Flex...");
    }

    result = execute_command("flex lexer.l", analyzer_dir);
    if (result != 0) {
        printf("❌ Error generando lexer con flex\n");
        if (mainview) {
            mainview_append_output(mainview, "❌ Error generando lexer con Flex");
        }
        return -1;
    }

    printf("📦 Compilando lexer...\n");
    if (mainview) {
        mainview_append_output(mainview, "📦 Compilando lexer...");
    }

    // USAR RUTAS RELATIVAS: ../../Utils/tokens.c
    const char* compile_cmd = "gcc lex.yy.c ../../Utils/tokens.c -lfl -o lexer";

    result = execute_command(compile_cmd, analyzer_dir);
    if (result != 0) {
        printf("❌ Error compilando lexer\n");
        if (mainview) {
            mainview_append_output(mainview, "❌ Error compilando lexer");
        }
        return -1;
    }

    printf("✅ Lexer generado exitosamente\n");
    if (mainview) {
        mainview_append_output(mainview, "✅ Lexer compilado exitosamente");
    }
    return 0;
}

static char* create_temp_file(const char* content) {
    static char temp_filename[] = "/tmp/javalang_temp_XXXXXX";
    int fd = mkstemp(temp_filename);

    if (fd == -1) {
        printf("❌ Error creando archivo temporal\n");
        return NULL;
    }

    write(fd, content, strlen(content));
    close(fd);

    return temp_filename;
}

static int analyze_code_from_buffer_with_output(GtkTextBuffer* buffer, MainView* mainview) {
    GtkTextIter start, end;
    char* content;
    char* temp_file;
    char command[512];
    FILE* pipe;
    char line[256];
    int token_count = 0;
    const char* base_dir = get_working_directory();

    if (!buffer) {
        printf("❌ Buffer de código no válido\n");
        if (mainview) {
            mainview_append_output(mainview, "❌ Buffer de código no válido");
        }
        return -1;
    }

    gtk_text_buffer_get_bounds(buffer, &start, &end);
    content = gtk_text_buffer_get_text(buffer, &start, &end, FALSE);

    if (!content || strlen(content) == 0) {
        printf("⚠️ No hay código para analizar\n");
        if (mainview) {
            mainview_append_output(mainview, "⚠️ No hay código para analizar");
        }
        g_free(content);
        return -1;
    }

    if (mainview) {
        char buffer_msg[512];
        snprintf(buffer_msg, sizeof(buffer_msg), "📝 Código a analizar (%zu caracteres)", strlen(content));
        mainview_append_output(mainview, buffer_msg);
        mainview_append_output(mainview, "─────────────────────────");
    }

    temp_file = create_temp_file(content);
    if (!temp_file) {
        if (mainview) {
            mainview_append_output(mainview, "❌ Error creando archivo temporal");
        }
        g_free(content);
        return -1;
    }

    // USAR RUTAS RELATIVAS
    snprintf(command, sizeof(command), "cd %s/Logic/Analyzer && ./lexer %s",
             base_dir, temp_file);
    pipe = popen(command, "r");

    if (!pipe) {
        if (mainview) {
            mainview_append_output(mainview, "❌ Error ejecutando lexer");
        }
        unlink(temp_file);
        g_free(content);
        return -1;
    }

    while (fgets(line, sizeof(line), pipe) != NULL) {
        line[strcspn(line, "\n")] = 0;

        if (strlen(line) > 0) {
            printf("%s\n", line);
            if (mainview) {
                mainview_append_output(mainview, line);
            }

            if (strstr(line, "Token:")) {
                token_count++;
            }
        }
    }

    int result = pclose(pipe);

    if (mainview) {
        char summary[256];
        mainview_append_output(mainview, "─────────────────────────");
        snprintf(summary, sizeof(summary), "📊 Total de tokens encontrados: %d", token_count);
        mainview_append_output(mainview, summary);
    }

    unlink(temp_file);
    g_free(content);

    return result;
}

int control_rebuild_and_analyze_with_output(GtkTextBuffer* code_buffer, MainView* mainview) {
    printf("🚀 Iniciando rebuild del lexer...\n");

    clean_generated_files(mainview);

    if (build_lexer(mainview) != 0) {
        return -1;
    }

    if (mainview) {
        mainview_append_output(mainview, "🔍 Analizando código...");
    }

    return analyze_code_from_buffer_with_output(code_buffer, mainview);
}

int control_rebuild_and_analyze(GtkTextBuffer* code_buffer) {
    return control_rebuild_and_analyze_with_output(code_buffer, NULL);
}

int control_analyze_only(GtkTextBuffer* code_buffer) {
    printf("🔍 Analizando código...\n");
    return analyze_code_from_buffer_with_output(code_buffer, NULL);
}