#include <stdio.h>
#include <gtk/gtk.h>
#include "Headers/mainview.h"



// Función para aplicar tema Windows clásico
static void apply_windows_classic_theme() {
    GtkSettings *settings = gtk_settings_get_default();

    // Intentar usar temas que simulan Windows clásico
    const char *classic_themes[] = {
        "Raleigh",      // Tema clásico GTK (más parecido a Win98)
        "Redmond",      // Si está disponible
        "Windows-95",   // Si está disponible
        "Adwaita"       // Fallback
    };

    // Probar cada tema hasta encontrar uno disponible
    for (int i = 0; i < 4; i++) {
        g_object_set(settings, "gtk-theme-name", classic_themes[i], NULL);
        printf("DEBUG: Aplicando tema: %s\n", classic_themes[i]);
        break; // Usar el primero disponible
    }

    // Configuraciones adicionales para look Windows clásico
    g_object_set(settings,
                "gtk-application-prefer-dark-theme", FALSE,
                "gtk-font-name", "Sans 8",
                "gtk-icon-theme-name", "hicolor",
                "gtk-button-images", TRUE,
                "gtk-menu-images", TRUE,
                "gtk-toolbar-style", GTK_TOOLBAR_BOTH,
                NULL);

    printf("DEBUG: Tema Windows clásico aplicado\n");
}


// Estructura para pasar datos al callback
typedef struct {
    MainView *mainview;
} CallbackData;

static gboolean set_initial_content(gpointer user_data) {
    CallbackData *data = (CallbackData *)user_data;
    MainView *mainview = data->mainview;

    printf("DEBUG: Ejecutando callback para establecer contenido\n");

    gtk_text_buffer_set_text(mainview->code_buffer,"// JavaLang IDE v1.0\n""\n""public static void main() {\n""    System.out.println(\"Hello World\");\n""}", -1);
    mainview_append_output(mainview, "Intérprete JavaLang iniciado correctamente");

    g_free(data);
    return FALSE;
}

static void activate(GtkApplication *app, gpointer user_data) {
    // IMPORTANTE: Aplicar tema Windows clásico ANTES de crear la interfaz
    apply_windows_classic_theme();

    MainView *mainview = mainview_create(app);
    mainview_show(mainview);


    CallbackData *callback_data = g_malloc(sizeof(CallbackData));
    callback_data->mainview = mainview;
    g_idle_add(set_initial_content, callback_data);
}

int main(int argc, char **argv) {
    // Variables de entorno para forzar tema clásico
    g_setenv("GTK_THEME", "Raleigh", TRUE);
    g_setenv("GTK_APPLICATION_PREFER_DARK_THEME", "0", TRUE);
    g_setenv("GTK_CSD", "0", TRUE); // Deshabilitar decoraciones del lado cliente

    printf("DEBUG: Iniciando JavaLang IDE con tema Windows clásico\n");

    GtkApplication *app = gtk_application_new("com.usac.javalang.interpreter", G_APPLICATION_DEFAULT_FLAGS);
    g_signal_connect(app, "activate", G_CALLBACK(activate), NULL);

    int status = g_application_run(G_APPLICATION(app), argc, argv);
    g_object_unref(app);
    return status;
}