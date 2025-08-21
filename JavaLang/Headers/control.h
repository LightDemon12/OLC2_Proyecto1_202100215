//
// Created by lightdemon on 21/08/25.
//

#ifndef CONTROL_H
#define CONTROL_H

#include <gtk/gtk.h>

// Forward declaration usando la MISMA estructura que mainview.h
struct MainView;
typedef struct MainView MainView;

// Funciones que usan MainView
int control_rebuild_and_analyze_with_output(GtkTextBuffer* code_buffer, MainView* mainview);

// Funciones que NO necesitan MainView
int control_rebuild_and_analyze(GtkTextBuffer* code_buffer);
int control_analyze_only(GtkTextBuffer* code_buffer);

#endif // CONTROL_H