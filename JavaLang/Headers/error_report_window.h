//
// Created by lightdemon on 21/08/25.
//

#ifndef ERROR_REPORT_WINDOW_H
#define ERROR_REPORT_WINDOW_H

#include <gtk/gtk.h>
#include "error_manager.h"
#include "mainview.h"

// Estructura para la ventana de reporte de errores
typedef struct {
    GtkWidget* window;
    GtkWidget* tree_view;
    GtkWidget* status_label;
    GtkWidget* close_button;
    GtkListStore* list_store;
    ErrorManager* error_manager;
    MainView* main_view;  // Referencia al mainview para regresar
} ErrorReportWindow;

// === FUNCIONES PÚBLICAS ===

// Crear y mostrar ventana de reporte
ErrorReportWindow* error_report_window_create(ErrorManager* error_manager, MainView* main_view);
void error_report_window_show(ErrorReportWindow* window);
void error_report_window_destroy(ErrorReportWindow* window);

// Actualizar datos
void error_report_window_refresh(ErrorReportWindow* window);
void error_report_window_populate_table(ErrorReportWindow* window);

#endif // ERROR_REPORT_WINDOW_H