//
// Created by lightdemon on 18/08/25.
//

#include "../Headers/mainview.h"
#include <gtk/gtk.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Paleta de 8 colores para palabras
static const char *word_colors[8] = {
    "#FF6B6B",  // Rojo claro
    "#4ECDC4",  // Turquesa
    "#45B7D1",  // Azul
    "#96CEB4",  // Verde claro
    "#FFEAA7",  // Amarillo
    "#DDA0DD",  // Violeta
    "#FFB347",  // Naranja
    "#F8BBD9"   // Rosa
};

// Estructura para datos del callback del cursor
typedef struct {
    GtkLabel *line_col_label;
    GtkTextBuffer *buffer;
} CursorData;

// Función para aplicar CSS a un widget
static void apply_css_to_widget(GtkWidget *widget, const char *css_class, const char *css_data) {
    GtkCssProvider *provider = gtk_css_provider_new();
    GtkStyleContext *context = gtk_widget_get_style_context(widget);

    gtk_css_provider_load_from_data(provider, css_data, -1, NULL);
    gtk_style_context_add_provider(context, GTK_STYLE_PROVIDER(provider), GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
    gtk_style_context_add_class(context, css_class);

    g_object_unref(provider);
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

// Callback para actualizar línea y columna
static void on_cursor_moved(GtkTextBuffer *buffer, GtkTextIter *location, GtkTextMark *mark, gpointer user_data) {
    CursorData *data = (CursorData *)user_data;

    if (mark == gtk_text_buffer_get_insert(buffer)) {
        GtkTextIter iter;
        gtk_text_buffer_get_iter_at_mark(buffer, &iter, mark);

        int line = gtk_text_iter_get_line(&iter) + 1;
        int column = gtk_text_iter_get_line_offset(&iter) + 1;

        char status_text[64];
        g_snprintf(status_text, sizeof(status_text), "Línea: %d, Columna: %d", line, column);
        gtk_label_set_text(data->line_col_label, status_text);
    }
}

// Función para crear un área de texto con título y contador (solo para código)
static GtkWidget* create_text_area_with_title(const char *title, GtkTextBuffer **buffer,
                                             GtkWidget **textview, gboolean is_code_editor,
                                             gboolean editable, GtkLabel **line_col_label) {
    GtkWidget *vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 2);

    // Header box para título y contador
    GtkWidget *header_box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 10);

    // Título del área
    GtkLabel *title_label = GTK_LABEL(gtk_label_new(title));
    gtk_widget_set_halign(GTK_WIDGET(title_label), GTK_ALIGN_START);

    // Aplicar CSS al título para hacerlo más visible
    const char *title_css = ".area-title { font-weight: bold; color: #333; font-size: 12px; }";
    apply_css_to_widget(GTK_WIDGET(title_label), "area-title", title_css);

    gtk_box_pack_start(GTK_BOX(header_box), GTK_WIDGET(title_label), FALSE, FALSE, 0);

    // Contador de línea/columna (solo para editor de código)
    if (is_code_editor && line_col_label) {
        *line_col_label = GTK_LABEL(gtk_label_new("Línea: 1, Columna: 1"));
        gtk_widget_set_halign(GTK_WIDGET(*line_col_label), GTK_ALIGN_END);

        // CSS para el contador
        const char *counter_css = ".line-counter { font-size: 11px; color: #666; font-family: monospace; }";
        apply_css_to_widget(GTK_WIDGET(*line_col_label), "line-counter", counter_css);

        gtk_box_pack_end(GTK_BOX(header_box), GTK_WIDGET(*line_col_label), FALSE, FALSE, 0);
    }

    // Crear text view
    *buffer = gtk_text_buffer_new(NULL);
    *textview = gtk_text_view_new_with_buffer(*buffer);
    gtk_text_view_set_editable(GTK_TEXT_VIEW(*textview), editable);
    gtk_text_view_set_monospace(GTK_TEXT_VIEW(*textview), TRUE);
    gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(*textview), GTK_WRAP_WORD);

    // Crear scroll window
    GtkWidget *scroll = gtk_scrolled_window_new(NULL, NULL);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scroll),
                                   GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
    gtk_container_add(GTK_CONTAINER(scroll), *textview);

    // Si es editor de código, configurar colores y callback
    if (is_code_editor) {
        create_color_tags(*buffer);

        if (line_col_label) {
            // Crear datos para el callback
            CursorData *cursor_data = g_malloc(sizeof(CursorData));
            cursor_data->line_col_label = *line_col_label;
            cursor_data->buffer = *buffer;

            // Conectar señal para actualizar contador
            g_signal_connect(*buffer, "mark-set", G_CALLBACK(on_cursor_moved), cursor_data);
        }
    }

    // Agregar header y scroll al vbox
    gtk_box_pack_start(GTK_BOX(vbox), header_box, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(vbox), scroll, TRUE, TRUE, 0);

    return vbox;
}

MainView* mainview_create(GtkApplication *app) {
    // Inicializar generador de números aleatorios
    srand(time(NULL));

    MainView *mainview = g_malloc(sizeof(MainView));

    // Crear ventana principal
    mainview->window = gtk_application_window_new(app);
    gtk_window_set_title(GTK_WINDOW(mainview->window), "JavaLang Interpreter");
    gtk_window_set_default_size(GTK_WINDOW(mainview->window), 1200, 800);

    // Container principal vertical
    GtkWidget *main_vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 5);
    gtk_container_set_border_width(GTK_CONTAINER(main_vbox), 10);

    // Container horizontal para código y output
    GtkWidget *top_hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 5);

    // === CREAR ÁREAS CON TÍTULOS ===
    GtkLabel *line_col_label = NULL;

    // Área de código con contador
    GtkWidget *code_area = create_text_area_with_title("📝 Editor de Código (.usl)",
                                                       &mainview->code_buffer,
                                                       &mainview->code_textview,
                                                       TRUE, TRUE, &line_col_label);

    // Área de output
    GtkWidget *output_area = create_text_area_with_title("📤 Salida de Comandos",
                                                         &mainview->output_buffer,
                                                         &mainview->output_textview,
                                                         FALSE, FALSE, NULL);

    // Área de consola
    GtkWidget *console_area = create_text_area_with_title("💻 Consola",
                                                          &mainview->console_buffer,
                                                          &mainview->console_textview,
                                                          FALSE, FALSE, NULL);

    // === APLICAR ESTILOS CSS ===
    const char *code_css = ".code-editor { background-color: #ffffff; color: #000000; font-family: monospace; }";
    const char *output_css = ".output-area { background-color: #f5f5f5; color: #000000; }";
    const char *console_css = ".console-area { background-color: #000000; color: #00ff00; }";

    apply_css_to_widget(mainview->code_textview, "code-editor", code_css);
    apply_css_to_widget(mainview->output_textview, "output-area", output_css);
    apply_css_to_widget(mainview->console_textview, "console-area", console_css);

    // === AGREGAR CONTENIDO INICIAL PARA PROBAR ===
    gtk_text_buffer_set_text(mainview->code_buffer, "// Editor de código funcionando\nint main() {\n    printf(\"Hola Mundo\");\n    return 0;\n}", -1);
    gtk_text_buffer_set_text(mainview->output_buffer, "Output funcionando\n", -1);
    gtk_text_buffer_set_text(mainview->console_buffer, ">>> Consola funcionando\n", -1);

    // Aplicar colores aleatorios al código inicial
    apply_random_colors_to_words(mainview->code_buffer);

    // === LAYOUT ===
    gtk_box_pack_start(GTK_BOX(top_hbox), code_area, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(top_hbox), output_area, TRUE, TRUE, 0);

    GtkWidget *separator = gtk_separator_new(GTK_ORIENTATION_HORIZONTAL);

    gtk_box_pack_start(GTK_BOX(main_vbox), top_hbox, TRUE, TRUE, 0);
    gtk_box_pack_start(GTK_BOX(main_vbox), separator, FALSE, FALSE, 5);
    gtk_box_pack_start(GTK_BOX(main_vbox), console_area, TRUE, TRUE, 0);

    gtk_container_add(GTK_CONTAINER(mainview->window), main_vbox);

    printf("DEBUG: MainView creado con títulos y contador de líneas\n");

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
        printf("DEBUG: Ventana mostrada\n");
    }
}

void mainview_set_code(const MainView *mainview, const char *code) {
    if (mainview && mainview->code_buffer && code) {
        printf("DEBUG: Estableciendo código con colores aleatorios\n");
        gtk_text_buffer_set_text(mainview->code_buffer, code, -1);

        // Aplicar colores aleatorios después de establecer el texto
        apply_random_colors_to_words(mainview->code_buffer);
    }
}

void mainview_append_output(const MainView *mainview, const char *output) {
    if (mainview && mainview->output_buffer && output) {
        printf("DEBUG: Agregando output: [%s]\n", output);
        GtkTextIter iter;
        gtk_text_buffer_get_end_iter(mainview->output_buffer, &iter);
        gtk_text_buffer_insert(mainview->output_buffer, &iter, output, -1);
        gtk_text_buffer_insert(mainview->output_buffer, &iter, "\n", -1);
    }
}

void mainview_append_console(const MainView *mainview, const char *console_text) {
    if (mainview && mainview->console_buffer && console_text) {
        printf("DEBUG: Agregando consola: [%s]\n", console_text);
        GtkTextIter iter;
        gtk_text_buffer_get_end_iter(mainview->console_buffer, &iter);
        gtk_text_buffer_insert(mainview->console_buffer, &iter, console_text, -1);
        gtk_text_buffer_insert(mainview->console_buffer, &iter, "\n", -1);
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