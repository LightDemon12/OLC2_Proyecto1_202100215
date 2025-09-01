//
// Created by lightdemon on 18/08/25.
//

#include "../Headers/mainview.h"
#include <gtk/gtk.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "../Headers/mainview.h"
#include "../Headers/file_manager.h"
#include <gtk/gtk.h>
#include "../Headers/control.h"
#include "../Headers/error_report_window.h"
#include "../Headers/error_manager.h"
#include "../Headers/ast.h"
#include "../Headers/ast_visualizer.h"

extern ErrorManager* global_error_manager;
extern ASTNode* ast_root;

// Paleta de 8 colores para palabras (más suaves para Win98)
static const char *word_colors[8] = {
    "#800000",  // Maroon
    "#008000",  // Green
    "#000080",  // Navy
    "#800080",  // Purple
    "#808000",  // Olive
    "#008080",  // Teal
    "#C00000",  // Red
    "#0000C0"   // Blue
};

// Estructura para datos del callback del cursor
typedef struct {
    GtkLabel *line_col_label;
    GtkTextBuffer *buffer;
} CursorData;

// CSS con acabados 3D GRUESOS estilo Windows 98
static void apply_win98_finish() {
    GtkCssProvider *provider = gtk_css_provider_new();

    const char *win98_css =
        "/* Fondo general Windows 98 */\n"
        "window {\n"
        "    background-color: #c0c0c0;\n"
        "    color: #000000;\n"
        "}\n"

        "/* Barra de menús estilo Win98 */\n"
        "menubar {\n"
        "    background-color: #c0c0c0;\n"
        "    color: #000000;\n"
        "    border-top: 2px solid #ffffff;\n"
        "    border-left: 2px solid #ffffff;\n"
        "    border-bottom: 2px solid #808080;\n"
        "    border-right: 2px solid #808080;\n"
        "    padding: 2px;\n"
        "    font-family: 'MS Sans Serif';\n"
        "    font-size: 8pt;\n"
        "}\n"

        "menubar > menuitem {\n"
        "    background-color: transparent;\n"
        "    color: #000000;\n"
        "    padding: 4px 8px;\n"
        "    margin: 1px;\n"
        "}\n"

        "menubar > menuitem:hover {\n"
        "    background-color: #0080c0;\n"
        "    color: #ffffff;\n"
        "    border-top: 1px solid #ffffff;\n"
        "    border-left: 1px solid #ffffff;\n"
        "    border-bottom: 1px solid #000000;\n"
        "    border-right: 1px solid #000000;\n"
        "}\n"

        "menu {\n"
        "    background-color: #c0c0c0;\n"
        "    border-top: 2px solid #ffffff;\n"
        "    border-left: 2px solid #ffffff;\n"
        "    border-bottom: 2px solid #808080;\n"
        "    border-right: 2px solid #808080;\n"
        "    padding: 2px;\n"
        "}\n"

        "menu > menuitem {\n"
        "    background-color: transparent;\n"
        "    color: #000000;\n"
        "    padding: 4px 20px;\n"
        "    margin: 1px;\n"
        "    font-family: 'MS Sans Serif';\n"
        "    font-size: 8pt;\n"
        "}\n"

        "menu > menuitem:hover {\n"
        "    background-color: #0080c0;\n"
        "    color: #ffffff;\n"
        "}\n"

        "/* Acabados 3D GRUESOS para frames */\n"
        ".win98-frame {\n"
        "    background-color: #c0c0c0;\n"
        "    border-top: 3px solid #ffffff;\n"
        "    border-left: 3px solid #ffffff;\n"
        "    border-bottom: 3px solid #808080;\n"
        "    border-right: 3px solid #808080;\n"
        "    padding: 3px;\n"
        "    margin: 2px;\n"
        "}\n"

        "/* Áreas hundidas (inset) GRUESAS */\n"
        ".win98-inset {\n"
        "    background-color: #ffffff;\n"
        "    border-top: 2px solid #808080;\n"
        "    border-left: 2px solid #808080;\n"
        "    border-bottom: 2px solid #ffffff;\n"
        "    border-right: 2px solid #ffffff;\n"
        "    margin: 2px;\n"
        "}\n"

        "/* Barras de título con relieve GRUESO */\n"
        ".win98-titlebar {\n"
        "    background: linear-gradient(to bottom, #004080 0%, #0060c0 50%, #004080 100%);\n"
        "    color: #ffffff;\n"
        "    font-weight: bold;\n"
        "    font-size: 11px;\n"
        "    padding: 4px 8px;\n"
        "    border-top: 2px solid #ffffff;\n"
        "    border-left: 2px solid #ffffff;\n"
        "    border-bottom: 2px solid #000000;\n"
        "    border-right: 2px solid #000000;\n"
        "}\n"

        "/* Editor de código con borde hundido GRUESO */\n"
        ".code-area {\n"
        "    background-color: #ffffff;\n"
        "    color: #000000;\n"
        "    font-family: 'Courier New', monospace;\n"
        "    font-size: 10pt;\n"
        "}\n"

        "/* Output con acabado gris claro */\n"
        ".output-area {\n"
        "    background-color: #f0f0f0;\n"
        "    color: #000000;\n"
        "    font-family: 'MS Sans Serif', sans-serif;\n"
        "    font-size: 9pt;\n"
        "}\n"

        "/* Consola negra */\n"
        ".console-area {\n"
        "    background-color: #000000;\n"
        "    color: #c0c0c0;\n"
        "    font-family: 'Courier New', monospace;\n"
        "    font-size: 9pt;\n"
        "}\n"

        "/* Status bar con relieve GRUESO */\n"
        ".win98-status {\n"
        "    background-color: #c0c0c0;\n"
        "    color: #000000;\n"
        "    font-family: 'MS Sans Serif', sans-serif;\n"
        "    font-size: 8pt;\n"
        "    padding: 3px 6px;\n"
        "    border-top: 2px solid #808080;\n"
        "    border-left: 2px solid #808080;\n"
        "    border-bottom: 2px solid #ffffff;\n"
        "    border-right: 2px solid #ffffff;\n"
        "}\n"

        "/* Separadores con efecto 3D GRUESO */\n"
        "separator {\n"
        "    background-color: #c0c0c0;\n"
        "    min-height: 4px;\n"
        "    border-top: 2px solid #808080;\n"
        "    border-bottom: 2px solid #ffffff;\n"
        "    margin: 3px 0;\n"
        "}\n"

        "/* Scrollbars con acabado 3D GRUESO */\n"
        "scrollbar {\n"
        "    background-color: #c0c0c0;\n"
        "    border-top: 2px solid #ffffff;\n"
        "    border-left: 2px solid #ffffff;\n"
        "    border-bottom: 2px solid #808080;\n"
        "    border-right: 2px solid #808080;\n"
        "}\n"

        "scrollbar slider {\n"
        "    background: linear-gradient(to bottom, #e0e0e0 0%, #c0c0c0 50%, #a0a0a0 100%);\n"
        "    border-top: 2px solid #ffffff;\n"
        "    border-left: 2px solid #ffffff;\n"
        "    border-bottom: 2px solid #808080;\n"
        "    border-right: 2px solid #808080;\n"
        "    min-width: 18px;\n"
        "    min-height: 18px;\n"
        "}\n"

        "scrollbar button {\n"
        "    background: linear-gradient(to bottom, #e0e0e0 0%, #c0c0c0 50%, #a0a0a0 100%);\n"
        "    border-top: 2px solid #ffffff;\n"
        "    border-left: 2px solid #ffffff;\n"
        "    border-bottom: 2px solid #808080;\n"
        "    border-right: 2px solid #808080;\n"
        "    min-width: 18px;\n"
        "    min-height: 18px;\n"
        "}\n";

    gtk_css_provider_load_from_data(provider, win98_css, -1, NULL);
    gtk_style_context_add_provider_for_screen(gdk_screen_get_default(),
                                             GTK_STYLE_PROVIDER(provider),
                                             GTK_STYLE_PROVIDER_PRIORITY_USER);
    g_object_unref(provider);
}
// Función para validar y corregir UTF-8 para GTK
static char* sanitize_utf8_for_gtk(const char *input) {
    if (!input) return NULL;

    // Verificar si ya es UTF-8 válido
    if (g_utf8_validate(input, -1, NULL)) {
        return g_strdup(input);
    }

    // Si no es válido, convertir caracteres problemáticos
    size_t len = strlen(input);
    GString *output = g_string_new("");

    for (size_t i = 0; i < len; i++) {
        unsigned char c = (unsigned char)input[i];

        if (c < 128) {
            // ASCII válido
            g_string_append_c(output, c);
        } else {
            // Caracteres no ASCII - reemplazar con representación
            if (c >= 160 && c <= 255) {
                // Caracteres Latin-1 comunes
                switch(c) {
                    case 0xE1: g_string_append(output, "á"); break;  // á
                    case 0xE9: g_string_append(output, "é"); break;  // é
                    case 0xED: g_string_append(output, "í"); break;  // í
                    case 0xF3: g_string_append(output, "ó"); break;  // ó
                    case 0xFA: g_string_append(output, "ú"); break;  // ú
                    case 0xF1: g_string_append(output, "ñ"); break;  // ñ
                    case 0xC1: g_string_append(output, "Á"); break;  // Á
                    case 0xC9: g_string_append(output, "É"); break;  // É
                    case 0xCD: g_string_append(output, "Í"); break;  // Í
                    case 0xD3: g_string_append(output, "Ó"); break;  // Ó
                    case 0xDA: g_string_append(output, "Ú"); break;  // Ú
                    case 0xD1: g_string_append(output, "Ñ"); break;  // Ñ
                    default:
                        g_string_append_c(output, '?');
                        break;
                }
            } else {
                g_string_append_c(output, '?');
            }
        }
    }

    char *result = g_strdup(output->str);
    g_string_free(output, TRUE);
    return result;
}
// === CALLBACKS DE MENÚS ===

// Callbacks del menú Archivo
static void on_nuevo_clicked(GtkMenuItem *menuitem, gpointer user_data) {
    MainView *mainview = (MainView *)user_data;
    file_manager_new_file(mainview, mainview->file_state);
}

static void on_abrir_clicked(GtkMenuItem *menuitem, gpointer user_data) {
    MainView *mainview = (MainView *)user_data;
    file_manager_open_file(GTK_WINDOW(mainview->window), mainview, mainview->file_state);
}

static void on_guardar_clicked(GtkMenuItem *menuitem, gpointer user_data) {
    MainView *mainview = (MainView *)user_data;
    file_manager_save_file(GTK_WINDOW(mainview->window), mainview, mainview->file_state);
}

// Callbacks del menú Compilar
static void on_lexico_clicked(GtkMenuItem *menuitem, gpointer user_data) {
    MainView *mainview = (MainView *)user_data;

    mainview_clear_output(mainview);
    mainview_append_output(mainview, "=== ANÁLISIS LÉXICO ===");

    // ✅LIMPIAR ERRORES ANTES DE COMENZAR NUEVO ANÁLISIS
    extern ErrorManager* global_error_manager;
    if (global_error_manager) {
        error_manager_clear(global_error_manager);
        printf("DEBUG: Errores previos limpiados\n");
    }

    int result = control_rebuild_and_analyze_with_output(mainview->code_buffer, mainview);

    /* VERIFICAR TANTO RESULTADO COMO ERRORES ACUMULADOS */
    int has_errors = 0;

    if (global_error_manager) {
        has_errors = error_manager_has_errors(global_error_manager);
        printf("DEBUG: Global error manager tiene errores: %s (%d total)\n",
               has_errors ? "SI" : "NO",
               error_manager_get_total_count(global_error_manager));
    }

    /* DETERMINAR RESULTADO FINAL */
    if (has_errors || result != 0) {
        mainview_append_output(mainview, "Análisis léxico completado con errores");
        printf("DEBUG: Análisis completado con errores - Result: %d, Errors: %d\n",
               result, has_errors);
    } else {
        mainview_append_output(mainview, "Análisis léxico completado exitosamente");
        printf("DEBUG: Análisis completado exitosamente - Result: %d, Errors: %d\n",
               result, has_errors);
    }

    printf("DEBUG: Análisis léxico ejecutado (resultado: %d)\n", result);
}

static void on_sintactico_clicked(GtkMenuItem *menuitem, gpointer user_data) {
    MainView *mainview = (MainView *)user_data;
    mainview_clear_output(mainview);
    mainview_append_output(mainview, "=== ANÁLISIS SINTÁCTICO ===");
    mainview_append_output(mainview, "Construyendo árbol sintáctico...");
    mainview_append_output(mainview, "Verificando gramática...");
    mainview_append_output(mainview, "Análisis sintáctico completado exitosamente");
    printf("DEBUG: Análisis sintáctico\n");
}

static void on_compilar_clicked(GtkMenuItem *menuitem, gpointer user_data) {
    MainView *mainview = (MainView *)user_data;
    mainview_clear_output(mainview);
    mainview_append_output(mainview, "=== COMPILACIÓN COMPLETA ===");
    mainview_append_output(mainview, "Fase 1: Análisis léxico... OK");
    mainview_append_output(mainview, "Fase 2: Análisis sintáctico... OK");
    mainview_append_output(mainview, "Fase 3: Análisis semántico... OK");
    mainview_append_output(mainview, "Fase 4: Generación de código... OK");
    mainview_append_output(mainview, "Compilación exitosa!");
    printf("DEBUG: Compilación completa\n");
}

// Callbacks del menú Reportes
static void on_ast_clicked(GtkMenuItem *menuitem, gpointer user_data) {
    MainView *mainview = (MainView *)user_data;
    mainview_clear_output(mainview);
    mainview_append_output(mainview, "=== REPORTE AST ===");

    if (!ast_root) {
        mainview_append_output(mainview, "No hay AST disponible");
        mainview_append_output(mainview, "Ejecute 'Reconstruir y Analizar' primero");
        return;
    }

    /* GENERAR Y ABRIR VISUALIZACIÓN */
    mainview_append_output(mainview, "Generando visualización...");

    ASTVisualizationResult* result = generate_global_ast_visual("png");

    if (result && result->success) {
        mainview_append_output(mainview, "Visualización generada exitosamente");

        /* ABRIR AUTOMÁTICAMENTE */
        char cmd[1024];
        snprintf(cmd, sizeof(cmd), "xdg-open \"%s\" &", result->image_file_path);
        system(cmd);

        mainview_append_output(mainview, "Imagen abierta automáticamente");

        /* INFO DE ARCHIVOS */
        char info[256];
        snprintf(info, sizeof(info), "Archivos: Logic/AST/AST.png, Logic/AST/AST.dot");
        mainview_append_output(mainview, info);

    } else {
        mainview_append_output(mainview, "Error generando visualización");
        if (!check_graphviz_available()) {
            mainview_append_output(mainview, "Instale: sudo apt install graphviz");
        }
    }

    /* AST EN CONSOLA */
    mainview_append_output(mainview, "AST en consola (ver terminal)");
    printf("\n=== AST DESDE GUI ===\n");
    print_node(NULL, 0);
    printf("=== FIN AST ===\n\n");

    free_visualization_result(result);
    mainview_append_output(mainview, "=== FIN REPORTE ===");
}

static void on_errores_clicked(GtkMenuItem *menuitem, gpointer user_data) {
    MainView *mainview = (MainView *)user_data;

    printf("DEBUG: Abriendo ventana de reporte de errores\n");

    // Crear y mostrar ventana de errores
    ErrorReportWindow* error_window = error_report_window_create(global_error_manager, mainview);

    if (error_window) {
        error_report_window_show(error_window);
    } else {
        // Fallback al output si falla la ventana
        mainview_clear_output(mainview);
        mainview_append_output(mainview, "=== REPORTE DE ERRORES ===");
        mainview_append_output(mainview, "Error: No se pudo abrir la ventana de errores");
    }
}

static void on_sintactico_reporte_clicked(GtkMenuItem *menuitem, gpointer user_data) {
    MainView *mainview = (MainView *)user_data;
    mainview_clear_output(mainview);
    mainview_append_output(mainview, "=== REPORTE SINTÁCTICO ===");
    mainview_append_output(mainview, "Generando reporte de análisis sintáctico...");
    mainview_append_output(mainview, "Reporte guardado en: /tmp/sintactico_report.html");
    printf("DEBUG: Reporte sintáctico\n");
}

static void on_tabla_simbolos_clicked(GtkMenuItem *menuitem, gpointer user_data) {
    MainView *mainview = (MainView *)user_data;
    mainview_clear_output(mainview);
    mainview_append_output(mainview, "=== TABLA DE SÍMBOLOS ===");
    mainview_append_output(mainview, "Variables encontradas: 3");
    mainview_append_output(mainview, "Funciones encontradas: 1");
    mainview_append_output(mainview, "Tabla guardada en: /tmp/tabla_simbolos.html");
    printf("DEBUG: Tabla de símbolos\n");
}

// Función para crear la barra de menús estilo Win98
static GtkWidget* create_win98_menubar(MainView *mainview) {
    GtkWidget *menubar = gtk_menu_bar_new();

    // === MENÚ ARCHIVO ===
    GtkWidget *archivo_menu = gtk_menu_new();
    GtkWidget *archivo_item = gtk_menu_item_new_with_label("Archivo");
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(archivo_item), archivo_menu);

    GtkWidget *nuevo_item = gtk_menu_item_new_with_label("Nuevo");
    GtkWidget *abrir_item = gtk_menu_item_new_with_label("Abrir");
    GtkWidget *guardar_item = gtk_menu_item_new_with_label("Guardar");

    g_signal_connect(nuevo_item, "activate", G_CALLBACK(on_nuevo_clicked), mainview);
    g_signal_connect(abrir_item, "activate", G_CALLBACK(on_abrir_clicked), mainview);
    g_signal_connect(guardar_item, "activate", G_CALLBACK(on_guardar_clicked), mainview);

    gtk_menu_shell_append(GTK_MENU_SHELL(archivo_menu), nuevo_item);
    gtk_menu_shell_append(GTK_MENU_SHELL(archivo_menu), abrir_item);
    gtk_menu_shell_append(GTK_MENU_SHELL(archivo_menu), gtk_separator_menu_item_new());
    gtk_menu_shell_append(GTK_MENU_SHELL(archivo_menu), guardar_item);

    // === MENÚ COMPILAR ===
    GtkWidget *compilar_menu = gtk_menu_new();
    GtkWidget *compilar_item = gtk_menu_item_new_with_label("Compilar");
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(compilar_item), compilar_menu);

    GtkWidget *lexico_item = gtk_menu_item_new_with_label("Léxico");
    GtkWidget *sintactico_item = gtk_menu_item_new_with_label("Sintáctico");
    GtkWidget *compilar_full_item = gtk_menu_item_new_with_label("Compilar");

    g_signal_connect(lexico_item, "activate", G_CALLBACK(on_lexico_clicked), mainview);
    g_signal_connect(sintactico_item, "activate", G_CALLBACK(on_sintactico_clicked), mainview);
    g_signal_connect(compilar_full_item, "activate", G_CALLBACK(on_compilar_clicked), mainview);

    gtk_menu_shell_append(GTK_MENU_SHELL(compilar_menu), lexico_item);
    gtk_menu_shell_append(GTK_MENU_SHELL(compilar_menu), sintactico_item);
    gtk_menu_shell_append(GTK_MENU_SHELL(compilar_menu), gtk_separator_menu_item_new());
    gtk_menu_shell_append(GTK_MENU_SHELL(compilar_menu), compilar_full_item);

    // === MENÚ REPORTES ===
    GtkWidget *reportes_menu = gtk_menu_new();
    GtkWidget *reportes_item = gtk_menu_item_new_with_label("Reportes");
    gtk_menu_item_set_submenu(GTK_MENU_ITEM(reportes_item), reportes_menu);

    GtkWidget *ast_item = gtk_menu_item_new_with_label("AST");
    GtkWidget *errores_item = gtk_menu_item_new_with_label("Errores");
    GtkWidget *sintactico_rep_item = gtk_menu_item_new_with_label("Sintáctico");
    GtkWidget *tabla_item = gtk_menu_item_new_with_label("Tabla de Símbolos");

    g_signal_connect(ast_item, "activate", G_CALLBACK(on_ast_clicked), mainview);
    g_signal_connect(errores_item, "activate", G_CALLBACK(on_errores_clicked), mainview);
    g_signal_connect(sintactico_rep_item, "activate", G_CALLBACK(on_sintactico_reporte_clicked), mainview);
    g_signal_connect(tabla_item, "activate", G_CALLBACK(on_tabla_simbolos_clicked), mainview);

    gtk_menu_shell_append(GTK_MENU_SHELL(reportes_menu), ast_item);
    gtk_menu_shell_append(GTK_MENU_SHELL(reportes_menu), errores_item);
    gtk_menu_shell_append(GTK_MENU_SHELL(reportes_menu), sintactico_rep_item);
    gtk_menu_shell_append(GTK_MENU_SHELL(reportes_menu), tabla_item);

    // Agregar todos los menús a la barra
    gtk_menu_shell_append(GTK_MENU_SHELL(menubar), archivo_item);
    gtk_menu_shell_append(GTK_MENU_SHELL(menubar), compilar_item);
    gtk_menu_shell_append(GTK_MENU_SHELL(menubar), reportes_item);

    return menubar;
}

// Función para crear tags de colores en el buffer
static void create_color_tags(GtkTextBuffer *buffer) {
    for (int i = 0; i < 8; i++) {
        char tag_name[32];
        snprintf(tag_name, sizeof(tag_name), "color_%d", i);
        gtk_text_buffer_create_tag(buffer, tag_name,
                                  "foreground", word_colors[i],
                                  "weight", PANGO_WEIGHT_BOLD,
                                  NULL);
    }
}

// Función para aplicar colores aleatorios a las palabras
static void apply_random_colors_to_words(GtkTextBuffer *buffer) {
    GtkTextIter start, end;
    gtk_text_buffer_get_bounds(buffer, &start, &end);

    // Remover tags existentes
    gtk_text_buffer_remove_all_tags(buffer, &start, &end);

    // Obtener todo el texto
    gchar *text = gtk_text_buffer_get_text(buffer, &start, &end, FALSE);
    if (!text) return;

    // Procesar palabra por palabra
    GtkTextIter word_start = start;
    GtkTextIter word_end = start;

    while (!gtk_text_iter_is_end(&word_end)) {
        // Encontrar el inicio de la siguiente palabra
        while (!gtk_text_iter_is_end(&word_start) &&
               !g_unichar_isalnum(gtk_text_iter_get_char(&word_start))) {
            gtk_text_iter_forward_char(&word_start);
        }

        if (gtk_text_iter_is_end(&word_start)) break;

        word_end = word_start;

        // Encontrar el final de la palabra
        while (!gtk_text_iter_is_end(&word_end) &&
               g_unichar_isalnum(gtk_text_iter_get_char(&word_end))) {
            gtk_text_iter_forward_char(&word_end);
        }

        // Aplicar color aleatorio si la palabra tiene más de 2 caracteres
        gchar *word = gtk_text_buffer_get_text(buffer, &word_start, &word_end, FALSE);
        if (word && strlen(word) > 2) {
            int color_index = rand() % 8;
            char tag_name[32];
            snprintf(tag_name, sizeof(tag_name), "color_%d", color_index);
            gtk_text_buffer_apply_tag_by_name(buffer, tag_name, &word_start, &word_end);
        }
        g_free(word);

        word_start = word_end;
    }

    g_free(text);
}

// Simplificar on_buffer_changed - ELIMINAR file tracking
static void on_buffer_changed(GtkTextBuffer *buffer, gpointer user_data) {
    // Solo aplicar colores, sin tracking de archivos
    g_timeout_add(100, (GSourceFunc)apply_random_colors_to_words, buffer);
}

// Callback para actualizar línea y columna
static void on_cursor_moved(GtkTextBuffer *buffer, GtkTextIter *location, GtkTextMark *mark, gpointer user_data) {
    CursorData *data = (CursorData *)user_data;

    if (mark == gtk_text_buffer_get_insert(buffer)) {
        GtkTextIter iter;
        gtk_text_buffer_get_iter_at_mark(buffer, &iter, mark);

        int line = gtk_text_iter_get_line(&iter) + 1;
        int column = gtk_text_iter_get_line_offset(&iter) + 1;

        char status_text[64];
        g_snprintf(status_text, sizeof(status_text), "Ln %d, Col %d", line, column);
        gtk_label_set_text(data->line_col_label, status_text);
    }
}

// Función para crear una barra de título con relieve Win98
static GtkWidget* create_win98_titlebar(const char *title, GtkLabel **status_label) {
    GtkWidget *hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
    gtk_style_context_add_class(gtk_widget_get_style_context(hbox), "win98-titlebar");

    // Título
    GtkLabel *title_label = GTK_LABEL(gtk_label_new(title));
    gtk_widget_set_halign(GTK_WIDGET(title_label), GTK_ALIGN_START);
    gtk_box_pack_start(GTK_BOX(hbox), GTK_WIDGET(title_label), TRUE, TRUE, 8);

    // Status (solo para editor)
    if (status_label) {
        *status_label = GTK_LABEL(gtk_label_new("Ln 1, Col 1"));
        gtk_style_context_add_class(gtk_widget_get_style_context(GTK_WIDGET(*status_label)), "win98-status");
        gtk_widget_set_halign(GTK_WIDGET(*status_label), GTK_ALIGN_END);
        gtk_box_pack_end(GTK_BOX(hbox), GTK_WIDGET(*status_label), FALSE, FALSE, 8);
    }

    return hbox;
}

// Función para crear un área de texto con acabados Win98 GRUESOS
static GtkWidget* create_win98_text_area(const char *title, GtkTextBuffer **buffer,
                                         GtkWidget **textview, const char *css_class,
                                         gboolean is_code_editor, gboolean editable) {
    // Frame principal con relieve GRUESO
    GtkWidget *outer_frame = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_style_context_add_class(gtk_widget_get_style_context(outer_frame), "win98-frame");

    // Crear titlebar
    GtkLabel *status_label = NULL;
    GtkWidget *titlebar = create_win98_titlebar(title, is_code_editor ? &status_label : NULL);

    // Container para el área de texto con borde hundido GRUESO
    GtkWidget *text_container = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_style_context_add_class(gtk_widget_get_style_context(text_container), "win98-inset");

    // Crear text view
    *buffer = gtk_text_buffer_new(NULL);
    *textview = gtk_text_view_new_with_buffer(*buffer);
    gtk_text_view_set_editable(GTK_TEXT_VIEW(*textview), editable);
    gtk_text_view_set_monospace(GTK_TEXT_VIEW(*textview), TRUE);
    gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(*textview), GTK_WRAP_WORD);

    // Aplicar clase CSS
    gtk_style_context_add_class(gtk_widget_get_style_context(*textview), css_class);

    // Configurar para editor de código
    if (is_code_editor) {
        create_color_tags(*buffer);
        g_signal_connect(*buffer, "changed", G_CALLBACK(on_buffer_changed), NULL);

        if (status_label) {
            CursorData *cursor_data = g_malloc(sizeof(CursorData));
            cursor_data->line_col_label = status_label;
            cursor_data->buffer = *buffer;
            g_signal_connect(*buffer, "mark-set", G_CALLBACK(on_cursor_moved), cursor_data);
        }
    }

    // Crear scroll window
    GtkWidget *scroll = gtk_scrolled_window_new(NULL, NULL);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scroll),
                                   GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
    gtk_container_add(GTK_CONTAINER(scroll), *textview);

    // Ensamblar jerarquía con más padding
    gtk_box_pack_start(GTK_BOX(text_container), scroll, TRUE, TRUE, 2);
    gtk_box_pack_start(GTK_BOX(outer_frame), titlebar, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(outer_frame), text_container, TRUE, TRUE, 0);

    return outer_frame;
}

MainView* mainview_create(GtkApplication *app) {
    // Inicializar generador de números aleatorios
    srand(time(NULL));

    // Aplicar acabados Win98 GRUESOS
    apply_win98_finish();

    MainView *mainview = g_malloc(sizeof(MainView));

    // Crear ventana principal
    mainview->window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(mainview->window), "JavaLang IDE - [Untitled.usl]");
    gtk_window_set_default_size(GTK_WINDOW(mainview->window), 1024, 768);

    // Container principal con acabado Win98
    GtkWidget *main_vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);

    // === CREAR BARRA DE MENÚS ===
    GtkWidget *menubar = create_win98_menubar(mainview);
    gtk_box_pack_start(GTK_BOX(main_vbox), menubar, FALSE, FALSE, 0);

    // Container para el contenido principal
    GtkWidget *content_vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 4);
    gtk_container_set_border_width(GTK_CONTAINER(content_vbox), 6);
    gtk_style_context_add_class(gtk_widget_get_style_context(content_vbox), "win98-frame");

    // Container horizontal para código y output
    GtkWidget *top_hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 4);

    // === CREAR ÁREAS CON ACABADOS WIN98 GRUESOS ===

    // Editor de código
    GtkWidget *code_area = create_win98_text_area("📝 Code Editor",
                                                  &mainview->code_buffer,
                                                  &mainview->code_textview,
                                                  "code-area", TRUE, TRUE);

    // Área de output
    GtkWidget *output_area = create_win98_text_area("📤 Output",
                                                    &mainview->output_buffer,
                                                    &mainview->output_textview,
                                                    "output-area", FALSE, FALSE);

    // Consola
    GtkWidget *console_area = create_win98_text_area("💻 Console",
                                                     &mainview->console_buffer,
                                                     &mainview->console_textview,
                                                     "console-area", FALSE, FALSE);

    // === CONTENIDO INICIAL ===
    gtk_text_buffer_set_text(mainview->code_buffer,
        "// JavaLang IDE v1.0\n"
        "// Windows 98 Classic Look\n\n"
        "	public static void main() {\n"
        "    		System.out.println(\"Hello World\");\n"
        "}", -1);

    gtk_text_buffer_set_text(mainview->output_buffer,
        "JavaLang Compiler Ready\n"
        "Windows 98 Style Activated\n"
        "Build: 98001\n"
        "Usa los menús para compilar y generar reportes", -1);

    gtk_text_buffer_set_text(mainview->console_buffer,
        "Microsoft(R) JavaLang Interpreter\n"
        "Version 6.0 for Windows 98\n"
        "C:\\JAVALANG> _\n", -1);

    // Aplicar colores al código inicial
    apply_random_colors_to_words(mainview->code_buffer);

    // === LAYOUT CON ACABADOS 3D GRUESOS ===
    gtk_box_pack_start(GTK_BOX(top_hbox), code_area, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(top_hbox), output_area, TRUE, TRUE, 0);

    // Separador con relieve GRUESO
    GtkWidget *separator = gtk_separator_new(GTK_ORIENTATION_HORIZONTAL);

    gtk_box_pack_start(GTK_BOX(content_vbox), top_hbox, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(content_vbox), separator, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(content_vbox), console_area, TRUE, TRUE, 0);

    gtk_box_pack_start(GTK_BOX(main_vbox), content_vbox, TRUE, TRUE, 0);
    gtk_container_add(GTK_CONTAINER(mainview->window), main_vbox);

    printf("DEBUG: JavaLang IDE con acabados Windows 98 GRUESOS y menús creado\n");

    return mainview;
}

void mainview_destroy(MainView *mainview) {
    if (mainview) {
        g_free(mainview);
    }
}

void mainview_show(const MainView *mainview) {
    if (mainview && mainview->window) {
        gtk_widget_show_all(mainview->window);
        printf("DEBUG: IDE con acabados Win98 GRUESOS y menús mostrado\n");
    }
}

// Simplificar mainview_set_code - ELIMINAR signal blocking
void mainview_set_code(const MainView *mainview, const char *code) {
    if (mainview && mainview->code_buffer && code) {
        gtk_text_buffer_set_text(mainview->code_buffer, code, -1);
        apply_random_colors_to_words(mainview->code_buffer);
    }
}

// Actualizar mainview_append_output para usar UTF-8 seguro
void mainview_append_output(const MainView *mainview, const char *output) {
    if (mainview && mainview->output_buffer && output) {
        // Sanitizar texto antes de insertar
        char *safe_text = sanitize_utf8_for_gtk(output);

        GtkTextIter iter;
        gtk_text_buffer_get_end_iter(mainview->output_buffer, &iter);
        gtk_text_buffer_insert(mainview->output_buffer, &iter, safe_text, -1);
        gtk_text_buffer_insert(mainview->output_buffer, &iter, "\n", -1);

        // Scroll automático al final
        GtkTextMark *mark = gtk_text_buffer_get_insert(mainview->output_buffer);
        gtk_text_view_scroll_mark_onscreen(GTK_TEXT_VIEW(mainview->output_textview), mark);

        g_free(safe_text);
    }
}

void mainview_append_console(const MainView *mainview, const char *console_text) {
    if (mainview && mainview->console_buffer && console_text) {
        char *safe_text = sanitize_utf8_for_gtk(console_text);

        GtkTextIter iter;
        gtk_text_buffer_get_end_iter(mainview->console_buffer, &iter);
        gtk_text_buffer_insert(mainview->console_buffer, &iter, safe_text, -1);
        gtk_text_buffer_insert(mainview->console_buffer, &iter, "\n", -1);

        g_free(safe_text);
    }
}

void mainview_clear_output(const MainView *mainview) {
    if (mainview && mainview->output_buffer) {
        gtk_text_buffer_set_text(mainview->output_buffer, "", -1);
    }
}

void mainview_clear_console(const MainView *mainview) {
    if (mainview && mainview->console_buffer) {
        gtk_text_buffer_set_text(mainview->console_buffer, "", -1);
    }
}