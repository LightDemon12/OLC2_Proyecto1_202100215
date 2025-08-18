//
// Created by lightdemon on 18/08/25.
// Implementación SIMPLE del sistema de gestión de archivos
//

#include "../../Headers/file_manager.h"
#include "../../Headers/mainview.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// === FUNCIONES DE INICIALIZACIÓN ===

FileState* file_manager_init(void) {
    FileState *file_state = g_malloc(sizeof(FileState));
    file_state->current_file_path = NULL;
    file_state->is_modified = FALSE;
    file_state->has_file = FALSE;

    printf("DEBUG: Sistema de archivos inicializado\n");
    return file_state;
}

void file_manager_destroy(FileState *file_state) {
    if (file_state) {
        if (file_state->current_file_path) {
            g_free(file_state->current_file_path);
        }
        g_free(file_state);
        printf("DEBUG: Sistema de archivos destruido\n");
    }
}

// === FUNCIONES AUXILIARES SIMPLES ===

static GtkFileFilter* create_usl_filter(void) {
    GtkFileFilter *filter = gtk_file_filter_new();
    gtk_file_filter_set_name(filter, "Archivos JavaLang (*.usl)");
    gtk_file_filter_add_pattern(filter, "*.usl");
    return filter;
}

// === FUNCIONES PRINCIPALES SIMPLIFICADAS ===

gboolean file_manager_open_file(GtkWindow *parent_window, struct MainView *mainview, FileState *file_state) {
    MainView *mv = (MainView*)mainview;

    GtkWidget *dialog = gtk_file_chooser_dialog_new("Abrir Archivo",
                                                   parent_window,
                                                   GTK_FILE_CHOOSER_ACTION_OPEN,
                                                   "_Cancelar", GTK_RESPONSE_CANCEL,
                                                   "_Abrir", GTK_RESPONSE_ACCEPT,
                                                   NULL);

    gtk_file_chooser_add_filter(GTK_FILE_CHOOSER(dialog), create_usl_filter());

    gint result = gtk_dialog_run(GTK_DIALOG(dialog));

    if (result == GTK_RESPONSE_ACCEPT) {
        char *filename = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(dialog));

        // Leer archivo simple
        GError *error = NULL;
        gchar *content = NULL;

        if (g_file_get_contents(filename, &content, NULL, &error)) {
            // Solo cargar contenido, sin tracking
            gtk_text_buffer_set_text(mv->code_buffer, content, -1);
            mainview_append_output(mv, "Archivo abierto");

            g_free(content);
            g_free(filename);
            gtk_widget_destroy(dialog);

            printf("DEBUG: Archivo abierto\n");
            return TRUE;
        } else {
            mainview_append_output(mv, "Error al leer archivo");
            g_free(filename);
        }
    }

    gtk_widget_destroy(dialog);
    return FALSE;
}

gboolean file_manager_save_file(GtkWindow *parent_window, struct MainView *mainview, FileState *file_state) {
    MainView *mv = (MainView*)mainview;

    GtkWidget *dialog = gtk_file_chooser_dialog_new("Guardar Archivo",
                                                   parent_window,
                                                   GTK_FILE_CHOOSER_ACTION_SAVE,
                                                   "_Cancelar", GTK_RESPONSE_CANCEL,
                                                   "_Guardar", GTK_RESPONSE_ACCEPT,
                                                   NULL);

    gtk_file_chooser_add_filter(GTK_FILE_CHOOSER(dialog), create_usl_filter());
    gtk_file_chooser_set_current_name(GTK_FILE_CHOOSER(dialog), "archivo.usl");

    gint result = gtk_dialog_run(GTK_DIALOG(dialog));

    if (result == GTK_RESPONSE_ACCEPT) {
        char *filename = gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(dialog));

        // Obtener contenido del editor
        GtkTextIter start, end;
        gtk_text_buffer_get_bounds(mv->code_buffer, &start, &end);
        gchar *content = gtk_text_buffer_get_text(mv->code_buffer, &start, &end, FALSE);

        // Guardar archivo simple
        GError *error = NULL;
        if (g_file_set_contents(filename, content, -1, &error)) {
            mainview_append_output(mv, "Archivo guardado");

            g_free(content);
            g_free(filename);
            gtk_widget_destroy(dialog);

            printf("DEBUG: Archivo guardado\n");
            return TRUE;
        } else {
            mainview_append_output(mv, "Error al guardar archivo");
            g_free(content);
            g_free(filename);
        }
    }

    gtk_widget_destroy(dialog);
    return FALSE;
}

// No implementamos save_as por separado, save siempre pregunta dónde guardar
gboolean file_manager_save_as_file(GtkWindow *parent_window, struct MainView *mainview, FileState *file_state) {
    return file_manager_save_file(parent_window, mainview, file_state);
}

void file_manager_new_file(struct MainView *mainview, FileState *file_state) {
    MainView *mv = (MainView*)mainview;

    // Solo limpiar con código por defecto
    const char *template_code =
        "// Nuevo archivo JavaLang\n"
        "int main() {\n"
        "    // Tu código aquí\n"
        "    return 0;\n"
        "}";

    gtk_text_buffer_set_text(mv->code_buffer, template_code, -1);
    mainview_append_output(mv, "Nuevo archivo");

    printf("DEBUG: Nuevo archivo\n");
}

// === FUNCIONES DUMMY ===

const char* file_manager_get_filename(FileState *file_state) {
    return "archivo.usl";
}

void file_manager_mark_modified(FileState *file_state) {
    // No hacer nada
}

gboolean file_manager_is_modified(FileState *file_state) {
    return FALSE;
}