#include "../../Headers/node_processor.h"
#include "../../Headers/Procesador_Declaraciones.h"
#include "../../Headers/Procesador_Expresion.h"
#include "../../Headers/mainview.h"
#include <stdlib.h>
#include <string.h>

// Hash simple para optimizar el switch
// Hash simple para optimizar el switch
static unsigned int simple_hash(const char* str) {
    if (!str) return 0;
    unsigned int hash = 5381;
    int c;
    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c;
    }
    return hash;
}


NodeProcessorType get_node_processor_type(const char* node_type) {
    if (!node_type) return NODE_TYPE_UNKNOWN;

    // DECLARACIONES (las que ya tienes)
    if (strcmp(node_type, "DECLARACION_CON_INICIALIZACION") == 0) return NODE_TYPE_DECLARACION_CON_INICIALIZACION;
    if (strcmp(node_type, "DECLARACION_MULTIPLE") == 0) return NODE_TYPE_DECLARACION_MULTIPLE;
    if (strcmp(node_type, "DECLARACION_SIN_INICIALIZACION") == 0) return NODE_TYPE_DECLARACION_SIN_INICIALIZACION;

    //   EXPRESIONES (solo agregar estas por ahora)
    if (strcmp(node_type, "EXPRESION_BINARIA") == 0) return NODE_TYPE_EXPRESION_BINARIA;
    if (strcmp(node_type, "EXPRESION_UNARIA") == 0) return NODE_TYPE_EXPRESION_UNARIA;
    if (strcmp(node_type, "EXPRESION_POSTFIJO") == 0) return NODE_TYPE_EXPRESION_POSTFIJO;
    if (strcmp(node_type, "EXPRESION_PARENTESIS") == 0) return NODE_TYPE_EXPRESION_PARENTESIS;
    if (strcmp(node_type, "DATO") == 0) return NODE_TYPE_DATO;
    if (strcmp(node_type, "IDENTIFIER") == 0) return NODE_TYPE_IDENTIFIER;

    return NODE_TYPE_UNKNOWN;
}

int process_ast_node(NodeProcessorContext* context, ASTNode* node) {
    if (!context || !node) {
        return 1;
    }

    context->linea_actual = node->line;

    if (context->modo_debug) {
        printf("DEBUG NODE_PROCESSOR: Procesando nodo '%s' en línea %d\n",
               node->type, node->line);
    }

    // Determinar tipo de procesamiento
    NodeProcessorType processor_type = get_node_processor_type(node->type);

    // Switch optimizado para manejar cada tipo de nodo
    switch (processor_type) {
        // DECLARACIONES - Generan símbolos
        case NODE_TYPE_DECLARACION_CON_INICIALIZACION:
        case NODE_TYPE_DECLARACION_MULTIPLE:
        case NODE_TYPE_DECLARACION_SIN_INICIALIZACION:
            if (context->modo_debug) {
                printf("DEBUG NODE_PROCESSOR: → Procesando declaración '%s'\n", node->type);
            }
            return process_declaracion_node(context, node);

        //   EXPRESIONES - Delegar al procesador de expresiones
        case NODE_TYPE_EXPRESION_BINARIA:
        case NODE_TYPE_EXPRESION_UNARIA:
        case NODE_TYPE_EXPRESION_POSTFIJO:
        case NODE_TYPE_EXPRESION_PARENTESIS:
        case NODE_TYPE_DATO:
        case NODE_TYPE_IDENTIFIER:
            if (context->modo_debug) {
                printf("DEBUG NODE_PROCESSOR: → Procesando expresión '%s'\n", node->type);
            }
            // Por ahora solo procesamos expresiones con resultado (no las que están sueltas)
            char* resultado = process_expresion_node(context, node);
            if (resultado) {
                if (context->modo_debug) {
                    printf("DEBUG NODE_PROCESSOR: → Resultado expresión: '%s'\n", resultado);
                }
                free(resultado);
            }
            return 0;

        // NODOS ESTRUCTURALES - No requieren procesamiento especial
        case NODE_TYPE_UNKNOWN:
        default:
            if (context->modo_debug) {
                printf("DEBUG NODE_PROCESSOR: → Nodo '%s' no requiere procesamiento especial\n",
                       node->type);
            }
            return 0;
    }
}

// Función helper para debug dual (consola + GUI)
void procesador_debug_output(NodeProcessorContext* context, const char* message) {
    if (context->modo_debug) {
        // Siempre mostrar en consola
        printf("DEBUG PROCESADOR: %s\n", message);

        // Si hay mainview, también mostrar en GUI
        if (context->mainview) {
            char gui_message[512];
            snprintf(gui_message, sizeof(gui_message), " %s", message);
            mainview_append_output(context->mainview, gui_message);
        }
    }
}

void procesador_error_output(NodeProcessorContext* context, const char* message) {
    // Siempre mostrar errores
    printf("ERROR PROCESADOR: %s\n", message);

    if (context->mainview) {
        char gui_message[512];
        snprintf(gui_message, sizeof(gui_message), "❌ ERROR: %s", message);
        mainview_append_output(context->mainview, gui_message);
    }
}