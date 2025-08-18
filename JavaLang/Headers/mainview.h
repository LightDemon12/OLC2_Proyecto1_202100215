//
// Created by lightdemon on 18/08/25.
//

#ifndef MAINVIEW_H
#define MAINVIEW_H

#include <gtk/gtk.h>

// Estructura principal de la aplicación
typedef struct {
    GtkWidget *window;
    GtkWidget *code_textview;
    GtkWidget *output_textview;
    GtkWidget *console_textview;
    GtkTextBuffer *code_buffer;
    GtkTextBuffer *output_buffer;
    GtkTextBuffer *console_buffer;
} MainView;

// Funciones públicas
MainView* mainview_create(GtkApplication *app);
void mainview_destroy(MainView *mainview);
void mainview_show(const MainView *mainview);

// Funciones para manipular el contenido
void mainview_set_code(const MainView *mainview, const char *code);
void mainview_append_output(const MainView *mainview, const char *output);
void mainview_append_console(const MainView *mainview, const char *console_text);
void mainview_clear_output(const MainView *mainview);
void mainview_clear_console(const MainView *mainview);

#endif // MAINVIEW_H