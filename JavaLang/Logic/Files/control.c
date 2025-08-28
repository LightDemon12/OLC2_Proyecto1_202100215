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
#include "../../Headers/error_manager.h"
#include "../../Headers/ast.h"


// DECLARACION GLOBAL UNICA
ErrorManager* global_error_manager = NULL;
extern ASTNode* ast_root;

extern int parser_main(int argc, char** argv);

// Funcion para obtener directorio de trabajo relativo
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

// Funcion para validar y limpiar UTF-8
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
    execute_command("rm -f lexer parser", analyzer_dir);
    execute_command("rm -f parser.tab.c parser.tab.h", analyzer_dir);

    printf("Archivos limpiados\n");
    if (mainview) {
        mainview_append_output(mainview, "Archivos limpiados");
    }
}

// FUNCION PARA CONSTRUIR ANALIZADOR INTEGRADO (lexer + parser)
static int build_integrated_analyzer(MainView* mainview) {
    const char* analyzer_dir = "Logic/Analyzer";
    int result;

    printf("Generando analizador lexico-sintactico integrado...\n");
    if (mainview) {
        mainview_append_output(mainview, "Generando analizador con Bison...");
    }

    // 1. Generar parser con Bison
    result = execute_command("bison -d parser.y", analyzer_dir);
    if (result != 0) {
        printf("Error generando analizador sintactico con bison\n");
        if (mainview) {
            mainview_append_output(mainview, "Error generando analizador sintactico con Bison");
        }
        return -1;
    }

    printf("Generando analizador lexico...\n");
    if (mainview) {
        mainview_append_output(mainview, "Generando analizador lexico con Flex...");
    }

    // 2. Generar lexer con Flex
    result = execute_command("flex lexer.l", analyzer_dir);
    if (result != 0) {
        printf("Error generando analizador lexico con flex\n");
        if (mainview) {
            mainview_append_output(mainview, "Error generando analizador lexico con Flex");
        }
        return -1;
    }

    printf("Compilando analizador lexico-sintactico integrado...\n");
    if (mainview) {
        mainview_append_output(mainview, "Compilando analizador lexico-sintactico...");
    }

    // 3. Compilar analizador integrado (lexer + parser) con flag STANDALONE_PARSER
    const char* compile_cmd = "gcc -DSTANDALONE_PARSER parser.tab.c lex.yy.c ../../Logic/AST/ast.c ../../Utils/error_manager.c -lfl -o parser";

    result = execute_command(compile_cmd, analyzer_dir);
    if (result != 0) {
        printf("Error compilando analizador integrado\n");
        if (mainview) {
            mainview_append_output(mainview, "Error compilando analizador integrado");
        }
        return -1;
    }

    printf("Analizador lexico-sintactico generado exitosamente\n");
    if (mainview) {
        mainview_append_output(mainview, "Analizador lexico-sintactico compilado exitosamente");
    }
    return 0;
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

// FUNCION MODIFICADA PARA USAR ANALIZADOR INTEGRADO
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

    /* LLAMAR AL PARSER DIRECTAMENTE EN EL MISMO PROCESO */
    printf("DEBUG: Llamando parser_main directamente...\n");
    char* argv_fake[] = {"parser", temp_file, NULL};
    result = parser_main(2, argv_fake);

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

// FUNCION PRINCIPAL MODIFICADA
int control_rebuild_and_analyze_with_output(GtkTextBuffer* code_buffer, MainView* mainview) {
    printf("Iniciando rebuild del analizador lexico-sintactico...\n");

    clean_generated_files(mainview);

    // CONSTRUIR ANALIZADOR INTEGRADO (lexer + parser)
    if (build_integrated_analyzer(mainview) != 0) {
        return -1;
    }

    if (mainview) {
        mainview_append_output(mainview, "Ejecutando analisis lexico-sintactico...");
    }

    return analyze_code_from_buffer_with_output(code_buffer, mainview);
}

// MANTENER FUNCIONES EXISTENTES
int control_rebuild_and_analyze(GtkTextBuffer* code_buffer) {
    return control_rebuild_and_analyze_with_output(code_buffer, NULL);
}

int control_analyze_only(GtkTextBuffer* code_buffer) {
    printf("Analizando codigo con analizador existente...\n");
    return analyze_code_from_buffer_with_output(code_buffer, NULL);
}

// FUNCION PUBLICA PARA PROBAR ANALIZADOR
int control_test_parser(MainView* mainview) {
    printf("Probando analizador lexico-sintactico...\n");

    if (build_integrated_analyzer(mainview) != 0) {
        return -1;
    }

    if (mainview) {
        mainview_append_output(mainview, "Analizador lexico-sintactico listo");
        mainview_append_output(mainview, "Use 'Reconstruir y Analizar' para analizar codigo");
    }

    return 0;
}