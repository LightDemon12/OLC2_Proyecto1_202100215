//
// Created by lightdemon on 18/08/25.
//

#ifndef MAINVIEW_H
#define MAINVIEW_H

#include <gtk/gtk.h>
#include "file_manager.h"  // Ahora podemos incluir porque FileState ya está definido

typedef struct MainView {
    GtkWidget *window;
    GtkWidget *code_textview;
    GtkWidget *output_textview;
    GtkWidget *console_textview;
    GtkTextBuffer *code_buffer;
    GtkTextBuffer *output_buffer;
    GtkTextBuffer *console_buffer;

    // === Estado de archivos ===
    FileState *file_state;

} MainView;

// === FUNCIONES PRINCIPALES ===

MainView* mainview_create(GtkApplication *app);
void mainview_destroy(MainView *mainview);
void mainview_show(const MainView *mainview);
void mainview_set_code(const MainView *mainview, const char *code);
void mainview_append_output(const MainView *mainview, const char *output);
void mainview_append_console(const MainView *mainview, const char *console_text);
void mainview_clear_output(const MainView *mainview);
void mainview_clear_console(const MainView *mainview);

#endif // MAINVIEW_H