#include "../../Headers/node_processor.h"
#include "../../Headers/Procesador_Declaraciones.h"
#include "../../Headers/Procesador_Expresion.h"
#include "../../Headers/mainview.h"
#include "../../Headers/Procesador_casting.h"
#include "../Headers/Procesador_Constantes.h"
#include "../../Headers/Procesador_If.h"
#include "../../Headers/Procesador_Asignaciones_Compuestas.h"
#include "../../Headers/Procesador_Break.h"
#include "../../Headers/scope_utils.h"
#include "../../Headers/Procesador_Continue.h"
#include "../../Headers/Procesador_Switch.h"
#include "../../Headers/Procesador_Return.h"
#include <stdlib.h>
#include <string.h>

#include "Procesador_Sout.h"

//   IMPLEMENTACIÓN COMPLETA DEL SISTEMA COMBINADO DE SCOPES

// Crear un nuevo nodo de scope
ScopeNode* crear_scope_node(ScopeType tipo, const char* nombre, int linea) {
    ScopeNode* scope = malloc(sizeof(ScopeNode));
    if (!scope) return NULL;

    scope->tipo = tipo;

    if (nombre) {
        strncpy(scope->nombre, nombre, sizeof(scope->nombre) - 1);
        scope->nombre[sizeof(scope->nombre) - 1] = '\0';
    } else {
        snprintf(scope->nombre, sizeof(scope->nombre), "scope_%d", rand() % 1000);
    }

    scope->nivel = 0;
    scope->linea_inicio = linea;
    scope->parent = NULL;

    return scope;
}

// Entrar a un nuevo scope (COMBINADO A+B)
void entrar_scope_combinado(NodeProcessorContext* context, ScopeType tipo, const char* nombre, int linea) {
    if (!context || !nombre) return;

    // ===== GENERAR NOMBRE JERÁRQUICO =====
    char nombre_jerarquico[128];

    if (context->scope_actual) {
        // Crear nombre que incluya el scope padre
        snprintf(nombre_jerarquico, sizeof(nombre_jerarquico),
                "%s.%s", context->scope_actual->nombre, nombre);
    } else {
        // Scope de primer nivel
        strncpy(nombre_jerarquico, nombre, sizeof(nombre_jerarquico) - 1);
        nombre_jerarquico[sizeof(nombre_jerarquico) - 1] = '\0';
    }

    ScopeNode* nuevo_scope = crear_scope_node(tipo, nombre_jerarquico, linea);
    if (!nuevo_scope) return;

    if (context->scope_actual) {
        nuevo_scope->parent = context->scope_actual;
        nuevo_scope->nivel = context->scope_actual->nivel + 1;
    }

    context->scope_actual = nuevo_scope;
    context->scope_counter++;

    // Usar el nombre jerárquico en la tabla de símbolos
    entrar_ambito(context->tabla_simbolos, nombre_jerarquico);

    if (context->modo_debug) {
        char debug_msg[256];
        snprintf(debug_msg, sizeof(debug_msg),
                "-> ENTRANDO SCOPE: %s (tipo: %d, nivel: %d) en linea %d",
                nombre_jerarquico, tipo, nuevo_scope->nivel, linea);
        procesador_debug_output(context, debug_msg);
    }
}

void reset_scope_counters(NodeProcessorContext* context) {
    if (!context) return;

    context->scope_counter = 0;
    context->scope_actual = NULL;

    // Reset tabla de símbolos
    if (context->tabla_simbolos) {
        context->tabla_simbolos->siguiente_temporal = 0;
        context->tabla_simbolos->siguiente_etiqueta = 0;
        context->tabla_simbolos->nivel_anidamiento = 0;
        strcpy(context->tabla_simbolos->ambito_actual, "global");
    }

    // ===== USAR EL RESET CENTRALIZADO =====
    reset_all_scope_counters(context);

    printf("DEBUG: Contadores de scope reseteados\n");
}

// Salir del scope actual (COMBINADO A+B)
void salir_scope_combinado(NodeProcessorContext* context, int linea) {
    if (!context || !context->scope_actual) {
        procesador_error_output(context, "Intento de salir de scope inexistente");
        return;
    }

    ScopeNode* scope_saliente = context->scope_actual;

    if (context->modo_debug) {
        char debug_msg[256];
        snprintf(debug_msg, sizeof(debug_msg),
                "<- SALIENDO SCOPE: %s (tipo: %d, nivel: %d) en linea %d",
                scope_saliente->nombre, scope_saliente->tipo, scope_saliente->nivel, linea);
        procesador_debug_output(context, debug_msg);
    }

    //   USAR SISTEMA EXISTENTE DE TABLA_SIMBOLOS (PARTE A)
    salir_ambito(context->tabla_simbolos);

    //   ACTUALIZAR STACK DE SCOPES (PARTE B)
    context->scope_actual = scope_saliente->parent;
    liberar_scope_node(scope_saliente);
}

// Liberar nodo de scope
void liberar_scope_node(ScopeNode* scope) {
    if (scope) {
        free(scope);
    }
}

// Buscar símbolo en scopes combinado
Simbolo* buscar_simbolo_en_scopes_combinado(NodeProcessorContext* context, const char* id) {
    if (!context || !id) return NULL;
    //   USAR TU FUNCIÓN EXISTENTE (es suficiente para búsqueda jerárquica)
    return buscar_simbolo(context->tabla_simbolos, id);
}

// Insertar símbolo en scope actual
int insertar_simbolo_en_scope_combinado(NodeProcessorContext* context, Simbolo simbolo) {
    if (!context) return 0;

    //   VERIFICAR DUPLICADOS EN ÁMBITO ACTUAL
    if (existe_simbolo_en_ambito_actual(context->tabla_simbolos, simbolo.id)) {
        char error_msg[256];
        snprintf(error_msg, sizeof(error_msg),
                "Variable '%s' ya existe en scope '%s'",
                simbolo.id,
                context->scope_actual ? context->scope_actual->nombre : "GLOBAL");
        procesador_error_output(context, error_msg);
        return 0;
    }

    //   USAR TU FUNCIÓN EXISTENTE PARA INSERTAR
    int resultado = insertar_simbolo(context->tabla_simbolos, simbolo);

    if (resultado && context->modo_debug) {
        char debug_msg[256];
        snprintf(debug_msg, sizeof(debug_msg),
                "Variable '%s' declarada en scope '%s' (nivel %d)",
                simbolo.id,
                context->scope_actual ? context->scope_actual->nombre : "GLOBAL",
                context->scope_actual ? context->scope_actual->nivel : 0);
        procesador_debug_output(context, debug_msg);
    }

    return resultado;
}

// Debug del stack de scopes
void debug_mostrar_stack_scopes_combinado(NodeProcessorContext* context) {
    if (!context || !context->modo_debug) return;

    printf("=== STACK DE SCOPES COMBINADO ===\n");
    ScopeNode* scope = context->scope_actual;
    int contador = 0;

    while (scope) {
        printf("  [%d] %s (tipo: %d, nivel: %d, linea: %d)\n",
               contador, scope->nombre, scope->tipo, scope->nivel, scope->linea_inicio);
        scope = scope->parent;
        contador++;
    }
    printf("  [%d] GLOBAL\n", contador);
    printf("=== FIN STACK ===\n");
}

//   FUNCIÓN get_node_processor_type CORREGIDA
NodeProcessorType get_node_processor_type(const char* node_type) {
    if (!node_type) return NODE_TYPE_UNKNOWN;

    // DECLARACIONES
    if (strcmp(node_type, "DECLARACION_CON_INICIALIZACION") == 0) return NODE_TYPE_DECLARACION_CON_INICIALIZACION;
    if (strcmp(node_type, "DECLARACION_MULTIPLE") == 0) return NODE_TYPE_DECLARACION_MULTIPLE;
    if (strcmp(node_type, "DECLARACION_SIN_INICIALIZACION") == 0) return NODE_TYPE_DECLARACION_SIN_INICIALIZACION;
    if (strcmp(node_type, "CONSTANTE_CON_INICIALIZACION") == 0) return NODE_TYPE_CONSTANTE_CON_INICIALIZACION;
    if (strcmp(node_type, "ASIGNACION_COMPUESTA") == 0) return NODE_TYPE_ASIGNACION_COMPUESTA;
    if (strcmp(node_type, "CONSTANTE_MULTIPLE") == 0) return NODE_TYPE_CONSTANTE_MULTIPLE;
    if (strcmp(node_type, "CAST") == 0) return NODE_TYPE_CAST;
    // ===== INSTRUCCIONES DE SALIDA =====
    if (strcmp(node_type, "SOUT") == 0) return NODE_TYPE_SOUT;
    //   SCOPES SEGÚN TU PARSER (nombres exactos del parser.y)
    if (strcmp(node_type, "BLOQUE_MAIN") == 0) return NODE_TYPE_BLOQUE_MAIN;
    if (strcmp(node_type, "IF_SIMPLE") == 0) return NODE_TYPE_IF_SIMPLE;
    if (strcmp(node_type, "IF_CON_ELSE") == 0) return NODE_TYPE_IF_CON_ELSE;
    if (strcmp(node_type, "IF_CON_ELSE_IF") == 0) return NODE_TYPE_IF_CON_ELSE_IF;
    if (strcmp(node_type, "IF_CON_ELSE_MIXTO_1") == 0) return NODE_TYPE_IF_CON_ELSE_MIXTO_1;
    if (strcmp(node_type, "IF_CON_ELSE_MIXTO_2") == 0) return NODE_TYPE_IF_CON_ELSE_MIXTO_2;
    if (strcmp(node_type, "WHILE") == 0) return NODE_TYPE_WHILE;
    if (strcmp(node_type, "DO_WHILE") == 0) return NODE_TYPE_DO_WHILE;
    if (strcmp(node_type, "FOR") == 0) return NODE_TYPE_FOR;
    if (strcmp(node_type, "SWITCH") == 0) return NODE_TYPE_SWITCH;
    if (strcmp(node_type, "FUNCION") == 0) return NODE_TYPE_FUNCION;
    if (strcmp(node_type, "BREAK") == 0) return NODE_TYPE_BREAK;
    if (strcmp(node_type, "CONTINUE") == 0) return NODE_TYPE_CONTINUE;
    if (strcmp(node_type, "RETURN_CON_VALOR") == 0) return NODE_TYPE_RETURN_CON_VALOR;
    if (strcmp(node_type, "RETURN_VACIO") == 0) return NODE_TYPE_RETURN_VACIO;
    // EXPRESIONES
    if (strcmp(node_type, "EXPRESION_BINARIA") == 0) return NODE_TYPE_EXPRESION_BINARIA;
    if (strcmp(node_type, "EXPRESION_UNARIA") == 0) return NODE_TYPE_EXPRESION_UNARIA;
    if (strcmp(node_type, "EXPRESION_POSTFIJO") == 0) return NODE_TYPE_EXPRESION_POSTFIJO;
    if (strcmp(node_type, "EXPRESION_PARENTESIS") == 0) return NODE_TYPE_EXPRESION_PARENTESIS;
    if (strcmp(node_type, "DATO") == 0) return NODE_TYPE_DATO;
    if (strcmp(node_type, "IDENTIFIER") == 0) return NODE_TYPE_IDENTIFIER;

    return NODE_TYPE_UNKNOWN;
}

//   FUNCIÓN process_ast_node CORREGIDA - SIN DUPLICACIÓN
int process_ast_node(NodeProcessorContext* context, ASTNode* node) {
    if (!context || !node) {
        return 1;
    }

    context->linea_actual = node->line;

    if (context->modo_debug) {
        printf("🔍 DEBUG NODE_PROCESSOR: Procesando nodo '%s' en linea %d\n",
               node->type, node->line);
        printf("   → Scope actual: %s (nivel %d)\n",
               context->scope_actual ? context->scope_actual->nombre : "NULL",
               context->scope_actual ? context->scope_actual->nivel : -1);
        printf("   → Ámbito tabla: %s\n", context->tabla_simbolos->ambito_actual);
    }

    // Determinar tipo de procesamiento
    NodeProcessorType processor_type = get_node_processor_type(node->type);

    //   SWITCH CORREGIDO - CADA TIPO MANEJA SUS HIJOS COMPLETAMENTE
    switch (processor_type) {
        case NODE_TYPE_BLOQUE_MAIN:
            printf("🏠 DETECTADO BLOQUE_MAIN - entrando scope 'main'\n");
            entrar_scope_combinado(context, SCOPE_MAIN, "main", node->line);

            // Procesar hijos del BLOQUE_MAIN
            for (int i = 0; i < node->child_count; i++) {
                printf("   → Procesando hijo %d/%d del BLOQUE_MAIN: '%s'\n",
                       i+1, node->child_count,
                       node->children[i] ? node->children[i]->type : "NULL");
                process_ast_node(context, node->children[i]);
            }

            salir_scope_combinado(context, node->line);
            printf("🏠 SALIENDO BLOQUE_MAIN\n");
            return 0;

        case NODE_TYPE_IF_SIMPLE:
        case NODE_TYPE_IF_CON_ELSE:
        case NODE_TYPE_IF_CON_ELSE_IF:
        case NODE_TYPE_IF_CON_ELSE_MIXTO_1:
        case NODE_TYPE_IF_CON_ELSE_MIXTO_2:
            printf("🔀 PROCESANDO IF: '%s'\n", node->type);
            // ===== USAR EL PROCESADOR DE IF ESPECIALIZADO =====
            return process_if_node(context, node);

        case NODE_TYPE_WHILE:
            {
                char scope_name[64];
                snprintf(scope_name, sizeof(scope_name), "while_%d", node->line);
                printf("🔄 DETECTADO WHILE - entrando scope '%s'\n", scope_name);
                entrar_scope_combinado(context, SCOPE_WHILE, scope_name, node->line);

                for (int i = 0; i < node->child_count; i++) {
                    process_ast_node(context, node->children[i]);
                }

                salir_scope_combinado(context, node->line);
                printf("🔄 SALIENDO WHILE '%s'\n", scope_name);
                return 0;
            }
        case NODE_TYPE_BREAK:
            printf("🛑 PROCESANDO BREAK: '%s'\n", node->type);
            return procesar_break(context, node);
        case NODE_TYPE_CONTINUE:
            printf("🔄 PROCESANDO CONTINUE: '%s'\n", node->type);
            return procesar_continue(context, node);
        case NODE_TYPE_RETURN_CON_VALOR:
        case NODE_TYPE_RETURN_VACIO:
            printf("↩️ PROCESANDO RETURN: '%s'\n", node->type);
            return procesar_return(context, node);
        case NODE_TYPE_FOR:
            {
                char scope_name[64];
                snprintf(scope_name, sizeof(scope_name), "for_%d", node->line);
                printf("🔁 DETECTADO FOR - entrando scope '%s'\n", scope_name);
                entrar_scope_combinado(context, SCOPE_FOR, scope_name, node->line);

                for (int i = 0; i < node->child_count; i++) {
                    process_ast_node(context, node->children[i]);
                }

                salir_scope_combinado(context, node->line);
                printf("🔁 SALIENDO FOR '%s'\n", scope_name);
                return 0;
            }

        case NODE_TYPE_SWITCH:
            printf("🔀 PROCESANDO SWITCH: '%s'\n", node->type);
            return procesar_switch(context, node);

        case NODE_TYPE_FUNCION:
            {
                char scope_name[64];
                snprintf(scope_name, sizeof(scope_name), "funcion_%d", node->line);
                printf("🔧 DETECTADO FUNCION - entrando scope '%s'\n", scope_name);
                entrar_scope_combinado(context, SCOPE_FUNCION, scope_name, node->line);

                for (int i = 0; i < node->child_count; i++) {
                    process_ast_node(context, node->children[i]);
                }

                salir_scope_combinado(context, node->line);
                printf("🔧 SALIENDO FUNCION '%s'\n", scope_name);
                return 0;
            }

        // DECLARACIONES - Generan símbolos (NO tienen hijos que procesar)
        case NODE_TYPE_DECLARACION_CON_INICIALIZACION:
        case NODE_TYPE_DECLARACION_MULTIPLE:
        case NODE_TYPE_DECLARACION_SIN_INICIALIZACION:
            printf("📝 PROCESANDO DECLARACIÓN: '%s' en scope '%s'\n",
                   node->type,
                   context->scope_actual ? context->scope_actual->nombre : "GLOBAL");
            return process_declaracion_node(context, node);
        case NODE_TYPE_CONSTANTE_CON_INICIALIZACION:
        case NODE_TYPE_CONSTANTE_MULTIPLE:
            printf("🔒 PROCESANDO CONSTANTE: '%s' en scope '%s'\n",
                   node->type,
                   context->scope_actual ? context->scope_actual->nombre : "GLOBAL");
            return process_constante_node(context, node);
        // EXPRESIONES - Delegar al procesador (NO tienen hijos que procesar aquí)
        case NODE_TYPE_ASIGNACION_COMPUESTA:
            printf("📝 PROCESANDO ASIGNACIÓN COMPUESTA: '%s'\n", node->type);
            return procesar_asignacion_compuesta(context, node);

        case NODE_TYPE_EXPRESION_BINARIA:
        case NODE_TYPE_EXPRESION_UNARIA:
        case NODE_TYPE_EXPRESION_POSTFIJO:
        case NODE_TYPE_EXPRESION_PARENTESIS:
        case NODE_TYPE_DATO:
        case NODE_TYPE_IDENTIFIER:
            printf("🧮 PROCESANDO EXPRESIÓN: '%s'\n", node->type);
            char* resultado = process_expresion_node(context, node);
            if (resultado) {
                if (context->modo_debug) {
                    printf("   → Resultado expresión: '%s'\n", resultado);
                }
                free(resultado);
            }
            return 0;
        case NODE_TYPE_CAST:
            printf("🎭 PROCESANDO CASTING: '%s'\n", node->type);
            char* resultado_cast = process_cast_node(context, node);
            if (resultado_cast && context->modo_debug) {
                printf("   → Resultado casting: '%s'\n", resultado_cast);
                free(resultado_cast);
            }
            return 0;

        case NODE_TYPE_SOUT:
            printf("🖨️  PROCESANDO SOUT: '%s'\n", node->type);
            char* resultado_sout = process_sout_node(context, node);
            if (resultado_sout && context->modo_debug) {
                printf("   → Resultado SOUT: '%s'\n", resultado_sout);
                free(resultado_sout);
            }
            return 0;
        // NODOS ESTRUCTURALES - Procesar hijos sin crear scope
        case NODE_TYPE_UNKNOWN:
        default:
            printf("❓ NODO ESTRUCTURAL: '%s' - procesando %d hijos\n",
                   node->type, node->child_count);

            //   IMPORTANTE: Verificar que no sea un BLOQUE_MAIN mal detectado
            if (strcmp(node->type, "BLOQUE_MAIN") == 0) {
                printf("⚠️  ADVERTENCIA: BLOQUE_MAIN detectado como UNKNOWN - corrigiendo\n");
                // Procesar como BLOQUE_MAIN
                entrar_scope_combinado(context, SCOPE_MAIN, "main", node->line);
                for (int i = 0; i < node->child_count; i++) {
                    process_ast_node(context, node->children[i]);
                }
                salir_scope_combinado(context, node->line);
                return 0;
            }

            // Procesar hijos para nodos estructurales (PROGRAM, INSTRUCCIONES, etc.)
            for (int i = 0; i < node->child_count; i++) {
                printf("   → Procesando hijo %d/%d de '%s': '%s'\n",
                       i+1, node->child_count, node->type,
                       node->children[i] ? node->children[i]->type : "NULL");
                process_ast_node(context, node->children[i]);
            }
            return 0;
    }
}

// Funciones helper para debug dual (consola + GUI)
void procesador_debug_output(NodeProcessorContext* context, const char* message) {
    if (context && context->modo_debug) {
        printf("DEBUG PROCESADOR: %s\n", message);

        if (context->mainview) {
            char gui_message[512];
            snprintf(gui_message, sizeof(gui_message), "[DEBUG] %s", message);
            mainview_append_output(context->mainview, gui_message);
        }
    }
}

void procesador_error_output(NodeProcessorContext* context, const char* message) {
    printf("ERROR PROCESADOR: %s\n", message);

    if (context && context->mainview) {
        char gui_message[512];
        snprintf(gui_message, sizeof(gui_message), "[ERROR] %s", message);
        mainview_append_output(context->mainview, gui_message);
    }
}