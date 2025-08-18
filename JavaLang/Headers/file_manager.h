//
// Created by lightdemon on 18/08/25.
// Sistema de gestión de archivos para JavaLang IDE
//

#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include <gtk/gtk.h>

// === DEFINICIÓN DE ESTRUCTURAS ===

// Estructura para mantener estado del archivo actual
typedef struct FileState {
    char *current_file_path;    // Ruta del archivo actual
    gboolean is_modified;       // Si el archivo ha sido modificado
    gboolean has_file;          // Si hay un archivo abierto
} FileState;

// Forward declaration para evitar dependencia circular
struct MainView;

// === FUNCIONES PRINCIPALES ===

/**
 * Inicializar el sistema de archivos
 * @return Puntero a FileState inicializado
 */
FileState* file_manager_init(void);

/**
 * Destruir el sistema de archivos y liberar memoria
 * @param file_state Estado del archivo a liberar
 */
void file_manager_destroy(FileState *file_state);

/**
 * Abrir archivo con filtro .usl
 * @param parent_window Ventana padre para el diálogo
 * @param mainview Vista principal del IDE
 * @param file_state Estado del archivo
 * @return TRUE si se abrió correctamente, FALSE en caso contrario
 */
gboolean file_manager_open_file(GtkWindow *parent_window, struct MainView *mainview, FileState *file_state);

/**
 * Guardar archivo actual
 * @param parent_window Ventana padre para el diálogo
 * @param mainview Vista principal del IDE
 * @param file_state Estado del archivo
 * @return TRUE si se guardó correctamente, FALSE en caso contrario
 */
gboolean file_manager_save_file(GtkWindow *parent_window, struct MainView *mainview, FileState *file_state);

/**
 * Guardar como nuevo archivo
 * @param parent_window Ventana padre para el diálogo
 * @param mainview Vista principal del IDE
 * @param file_state Estado del archivo
 * @return TRUE si se guardó correctamente, FALSE en caso contrario
 */
gboolean file_manager_save_as_file(GtkWindow *parent_window, struct MainView *mainview, FileState *file_state);

/**
 * Crear nuevo archivo (limpiar editor)
 * @param mainview Vista principal del IDE
 * @param file_state Estado del archivo
 */
void file_manager_new_file(struct MainView *mainview, FileState *file_state);

/**
 * Obtener nombre del archivo actual
 * @param file_state Estado del archivo
 * @return Nombre del archivo o "Untitled.usl" si no hay archivo
 */
const char* file_manager_get_filename(FileState *file_state);

/**
 * Marcar archivo como modificado
 * @param file_state Estado del archivo
 */
void file_manager_mark_modified(FileState *file_state);

/**
 * Verificar si el archivo ha sido modificado
 * @param file_state Estado del archivo
 * @return TRUE si ha sido modificado, FALSE en caso contrario
 */
gboolean file_manager_is_modified(FileState *file_state);

#endif // FILE_MANAGER_H