//
// Created by lightdemon on 21/08/25.
//

#ifndef CONTROL_H
#define CONTROL_H

#include <gtk/gtk.h>
#include "error_manager.h"  // ← Sin ../../Headers/

// Forward declaration usando la MISMA estructura que mainview.h
struct MainView;
typedef struct MainView MainView;

// ✅ SOLO DECLARAR EXTERN (no definir)
extern ErrorManager* global_error_manager;
extern int parse_java_code(const char* filename);

// Funciones que usan MainView
int control_rebuild_and_analyze_with_output(GtkTextBuffer* code_buffer, MainView* mainview);

// Funciones que NO necesitan MainView
int control_rebuild_and_analyze(GtkTextBuffer* code_buffer);
int control_analyze_only(GtkTextBuffer* code_buffer);
int control_test_parser(MainView* mainview);
#endif // CONTROL_H