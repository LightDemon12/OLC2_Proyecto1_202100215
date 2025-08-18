#include <stdio.h>
#include <gtk/gtk.h>
#include "Headers/mainview.h"

// Estructura para pasar datos al callback
typedef struct {
    MainView *mainview;
} CallbackData;

// Callback que se ejecuta después de que la ventana esté completamente mostrada
static gboolean set_initial_content(gpointer user_data) {
    CallbackData *data = (CallbackData *)user_data;
    MainView *mainview = data->mainview;

    printf("DEBUG: Ejecutando callback para establecer contenido\n");

    // Ahora sí establecer el contenido
    mainview_set_code(mainview, "// Escribe tu código JavaLang aquí\nint main() {\n    print(\"Hola Mundo\");\n    return 0;\n}");
    mainview_append_output(mainview, "Intérprete JavaLang iniciado correctamente");

    // Liberar memoria
    g_free(data);

    // Retornar FALSE para que el callback se ejecute solo una vez
    return FALSE;
}

static void activate(GtkApplication *app, gpointer user_data) {
    MainView *mainview = mainview_create(app);

    // Mostrar la ventana
    mainview_show(mainview);

    // La consola ya se establece correctamente, solo necesitamos arreglar código y output
    mainview_append_console(mainview, ">>> Consola lista para comandos");

    // Crear estructura para pasar datos al callback
    CallbackData *callback_data = g_malloc(sizeof(CallbackData));
    callback_data->mainview = mainview;

    // Programar el callback para que se ejecute cuando el main loop esté listo
    g_idle_add(set_initial_content, callback_data);
}

int main(int argc, char **argv) {
    GtkApplication *app = gtk_application_new("com.usac.javalang.interpreter", G_APPLICATION_DEFAULT_FLAGS);

    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);
    int status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);

    return status;
}