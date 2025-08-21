//
// Created by lightdemon on 21/08/25.
//

#include "../Headers/error_report_window.h"
#include <stdio.h>
#include <stdlib.h>

// Enum para columnas de la tabla
enum {
    COL_ID = 0,
    COL_TYPE,
    COL_LINE,
    COL_COLUMN,
    COL_MESSAGE,
    COL_TOKEN,
    NUM_COLS
};

// CSS específico para la ventana de errores
static void apply_error_window_css() {
    GtkCssProvider *provider = gtk_css_provider_new();

    const char *error_window_css =
        "/* Tabla de errores estilo Win98 */\n"
        ".error-table {\n"
        "    background-color: #ffffff;\n"
        "    color: #000000;\n"
        "    font-family: 'MS Sans Serif', sans-serif;\n"
        "    font-size: 9pt;\n"
        "}\n"

        ".error-table:selected {\n"
        "    background-color: #0080c0;\n"
        "    color: #ffffff;\n"
        "}\n"

        "/* Botones estilo Win98 */\n"
        ".win98-button {\n"
        "    background: linear-gradient(to bottom, #e0e0e0 0%, #c0c0c0 50%, #a0a0a0 100%);\n"
        "    color: #000000;\n"
        "    font-family: 'MS Sans Serif', sans-serif;\n"
        "    font-size: 8pt;\n"
        "    font-weight: normal;\n"
        "    border-top: 2px solid #ffffff;\n"
        "    border-left: 2px solid #ffffff;\n"
        "    border-bottom: 2px solid #808080;\n"
        "    border-right: 2px solid #808080;\n"
        "    padding: 4px 16px;\n"
        "    margin: 2px;\n"
        "}\n"

        ".win98-button:hover {\n"
        "    background: linear-gradient(to bottom, #f0f0f0 0%, #d0d0d0 50%, #b0b0b0 100%);\n"
        "}\n"

        ".win98-button:active {\n"
        "    border-top: 2px solid #808080;\n"
        "    border-left: 2px solid #808080;\n"
        "    border-bottom: 2px solid #ffffff;\n"
        "    border-right: 2px solid #ffffff;\n"
        "    background: linear-gradient(to bottom, #a0a0a0 0%, #c0c0c0 50%, #e0e0e0 100%);\n"
        "}\n"

        "/* Headers de tabla */\n"
        ".error-table-header {\n"
        "    background: linear-gradient(to bottom, #e0e0e0 0%, #c0c0c0 50%, #a0a0a0 100%);\n"
        "    color: #000000;\n"
        "    font-weight: bold;\n"
        "    border-top: 2px solid #ffffff;\n"
        "    border-left: 2px solid #ffffff;\n"
        "    border-bottom: 2px solid #808080;\n"
        "    border-right: 2px solid #808080;\n"
        "    padding: 4px;\n"
        "}\n";

    gtk_css_provider_load_from_data(provider, error_window_css, -1, NULL);
    gtk_style_context_add_provider_for_screen(gdk_screen_get_default(),
                                             GTK_STYLE_PROVIDER(provider),
                                             GTK_STYLE_PROVIDER_PRIORITY_USER);
    g_object_unref(provider);
}

// Callback para cerrar ventana y regresar al mainview
static void on_close_button_clicked(GtkButton *button, gpointer user_data) {
    ErrorReportWindow *window = (ErrorReportWindow *)user_data;

    printf("DEBUG: Cerrando ventana de errores y regresando al MainView\n");

    // Enfocar la ventana principal
    if (window->main_view && window->main_view->window) {
        gtk_window_present(GTK_WINDOW(window->main_view->window));
    }

    // Cerrar ventana de errores
    gtk_widget_destroy(window->window);
}

// Crear modelo de datos para la tabla
static GtkListStore* create_error_table_model() {
    return gtk_list_store_new(NUM_COLS,
                             G_TYPE_INT,     // ID
                             G_TYPE_STRING,  // Tipo
                             G_TYPE_INT,     // Línea
                             G_TYPE_INT,     // Columna
                             G_TYPE_STRING,  // Mensaje
                             G_TYPE_STRING); // Token
}

// Crear TreeView con columnas
static GtkWidget* create_error_tree_view(GtkListStore *store) {
    GtkWidget *tree_view = gtk_tree_view_new_with_model(GTK_TREE_MODEL(store));
    gtk_style_context_add_class(gtk_widget_get_style_context(tree_view), "error-table");

    // Columna ID
    GtkCellRenderer *renderer = gtk_cell_renderer_text_new();
    GtkTreeViewColumn *column = gtk_tree_view_column_new_with_attributes(
        "#", renderer, "text", COL_ID, NULL);
    gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
    gtk_tree_view_column_set_fixed_width(column, 50);
    gtk_style_context_add_class(gtk_widget_get_style_context(GTK_WIDGET(column)), "error-table-header");
    gtk_tree_view_append_column(GTK_TREE_VIEW(tree_view), column);

    // Columna Tipo
    renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes(
        "Tipo", renderer, "text", COL_TYPE, NULL);
    gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
    gtk_tree_view_column_set_fixed_width(column, 100);
    gtk_tree_view_append_column(GTK_TREE_VIEW(tree_view), column);

    // Columna Línea
    renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes(
        "Linea", renderer, "text", COL_LINE, NULL);
    gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
    gtk_tree_view_column_set_fixed_width(column, 80);
    gtk_tree_view_append_column(GTK_TREE_VIEW(tree_view), column);

    // Columna Columna
    renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes(
        "Columna", renderer, "text", COL_COLUMN, NULL);
    gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
    gtk_tree_view_column_set_fixed_width(column, 80);
    gtk_tree_view_append_column(GTK_TREE_VIEW(tree_view), column);

    // Columna Mensaje
    renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes(
        "Mensaje", renderer, "text", COL_MESSAGE, NULL);
    gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
    gtk_tree_view_column_set_fixed_width(column, 300);
    gtk_tree_view_append_column(GTK_TREE_VIEW(tree_view), column);

    // Columna Token
    renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes(
        "Token", renderer, "text", COL_TOKEN, NULL);
    gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_FIXED);
    gtk_tree_view_column_set_fixed_width(column, 100);
    gtk_tree_view_append_column(GTK_TREE_VIEW(tree_view), column);

    return tree_view;
}

// Crear barra de título Win98
static GtkWidget* create_error_titlebar(const char *title, GtkLabel **status_label) {
    GtkWidget *hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
    gtk_style_context_add_class(gtk_widget_get_style_context(hbox), "win98-titlebar");

    // Título (sin emoji para evitar UTF-8)
    GtkLabel *title_label = GTK_LABEL(gtk_label_new(title));
    gtk_widget_set_halign(GTK_WIDGET(title_label), GTK_ALIGN_START);
    gtk_box_pack_start(GTK_BOX(hbox), GTK_WIDGET(title_label), TRUE, TRUE, 8);

    // Status
    *status_label = GTK_LABEL(gtk_label_new("Cargando errores..."));
    gtk_style_context_add_class(gtk_widget_get_style_context(GTK_WIDGET(*status_label)), "win98-status");
    gtk_widget_set_halign(GTK_WIDGET(*status_label), GTK_ALIGN_END);
    gtk_box_pack_end(GTK_BOX(hbox), GTK_WIDGET(*status_label), FALSE, FALSE, 8);

    return hbox;
}

// Poblar tabla con datos del ErrorManager
void error_report_window_populate_table(ErrorReportWindow* window) {
    if (!window || !window->list_store || !window->error_manager) {
        return;
    }

    // Limpiar tabla
    gtk_list_store_clear(window->list_store);

    if (!error_manager_has_errors(window->error_manager)) {
        // Mostrar mensaje de "sin errores"
        GtkTreeIter iter;
        gtk_list_store_append(window->list_store, &iter);
        gtk_list_store_set(window->list_store, &iter,
                          COL_ID, 0,
                          COL_TYPE, "INFO",
                          COL_LINE, 0,
                          COL_COLUMN, 0,
                          COL_MESSAGE, "No hay errores registrados",
                          COL_TOKEN, "",
                          -1);

        gtk_label_set_text(GTK_LABEL(window->status_label), "Sin errores");
        return;
    }

    // Recorrer lista de errores
    ErrorNode* current = window->error_manager->head;
    int id = 1;

    while (current) {
        GtkTreeIter iter;
        gtk_list_store_append(window->list_store, &iter);
        gtk_list_store_set(window->list_store, &iter,
                          COL_ID, id++,
                          COL_TYPE, error_type_name(current->type),
                          COL_LINE, current->line,
                          COL_COLUMN, current->column,
                          COL_MESSAGE, current->message ? current->message : "",
                          COL_TOKEN, current->token_text ? current->token_text : "",
                          -1);

        current = current->next;
    }

    // Actualizar status
    char status_text[256];
    snprintf(status_text, sizeof(status_text),
             "Total: %d errores (%d lexicos, %d sintacticos, %d semanticos)",
             error_manager_get_total_count(window->error_manager),
             error_manager_get_lexico_count(window->error_manager),
             error_manager_get_sintactico_count(window->error_manager),
             error_manager_get_semantico_count(window->error_manager));

    gtk_label_set_text(GTK_LABEL(window->status_label), status_text);
}

// Crear ventana principal
ErrorReportWindow* error_report_window_create(ErrorManager* error_manager, MainView* main_view) {
    // Aplicar CSS específico
    apply_error_window_css();

    ErrorReportWindow* window = g_malloc(sizeof(ErrorReportWindow));
    window->error_manager = error_manager;
    window->main_view = main_view;

    // Crear ventana
    window->window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window->window), "JavaLang - Reporte de Errores");
    gtk_window_set_default_size(GTK_WINDOW(window->window), 800, 500);
    gtk_window_set_position(GTK_WINDOW(window->window), GTK_WIN_POS_CENTER);

    // Container principal
    GtkWidget *main_vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_style_context_add_class(gtk_widget_get_style_context(main_vbox), "win98-frame");

    // Título con status
    GtkLabel *status_label_ptr;
    GtkWidget *titlebar = create_error_titlebar("Reporte de Errores", &status_label_ptr);
    window->status_label = GTK_WIDGET(status_label_ptr);

    // Área de tabla con borde hundido
    GtkWidget *table_container = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    gtk_style_context_add_class(gtk_widget_get_style_context(table_container), "win98-inset");

    // Crear modelo y vista
    window->list_store = create_error_table_model();
    window->tree_view = create_error_tree_view(window->list_store);

    // Scroll para la tabla
    GtkWidget *scroll = gtk_scrolled_window_new(NULL, NULL);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(scroll),
                                   GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
    gtk_container_add(GTK_CONTAINER(scroll), window->tree_view);

    gtk_box_pack_start(GTK_BOX(table_container), scroll, TRUE, TRUE, 4);

    // Área de botones
    GtkWidget *button_box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0);
    gtk_style_context_add_class(gtk_widget_get_style_context(button_box), "win98-frame");

    // Botón Cerrar
    window->close_button = gtk_button_new_with_label("Cerrar");
    gtk_style_context_add_class(gtk_widget_get_style_context(window->close_button), "win98-button");
    gtk_widget_set_size_request(window->close_button, 100, 30);

    g_signal_connect(window->close_button, "clicked",
                     G_CALLBACK(on_close_button_clicked), window);

    gtk_box_pack_end(GTK_BOX(button_box), window->close_button, FALSE, FALSE, 8);

    // Ensamblar ventana
    gtk_box_pack_start(GTK_BOX(main_vbox), titlebar, FALSE, FALSE, 0);
    gtk_box_pack_start(GTK_BOX(main_vbox), table_container, TRUE, TRUE, 4);
    gtk_box_pack_start(GTK_BOX(main_vbox), button_box, FALSE, FALSE, 4);

    gtk_container_add(GTK_CONTAINER(window->window), main_vbox);

    // Callback para destruir al cerrar
    g_signal_connect(window->window, "destroy",
                     G_CALLBACK(gtk_widget_destroyed), &window->window);

    printf("DEBUG: Ventana de reporte de errores creada\n");
    return window;
}

void error_report_window_show(ErrorReportWindow* window) {
    if (window && window->window) {
        // Poblar datos antes de mostrar
        error_report_window_populate_table(window);
        gtk_widget_show_all(window->window);
        printf("DEBUG: Ventana de reporte de errores mostrada\n");
    }
}

void error_report_window_refresh(ErrorReportWindow* window) {
    if (window) {
        error_report_window_populate_table(window);
    }
}

void error_report_window_destroy(ErrorReportWindow* window) {
    if (window) {
        if (window->window) {
            gtk_widget_destroy(window->window);
        }
        g_free(window);
        printf("DEBUG: Ventana de reporte de errores destruida\n");
    }
}