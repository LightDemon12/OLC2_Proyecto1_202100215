//
// Created by lightdemon on 02/09/25.
//

#include "../../Headers/Interprete.h"
#include "../../Headers/node_processor.h"
#include "../../Headers/mainview.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

ContextoInterprete* crear_contexto_interprete(ASTNode* ast_root) {
    if (!ast_root) {
        printf("ERROR INTERPRETE: AST raíz es NULL\n");
        return NULL;
    }

    ContextoInterprete* contexto = (ContextoInterprete*)malloc(sizeof(ContextoInterprete));
    if (!contexto) {
        printf("ERROR INTERPRETE: No se pudo allocar memoria para el contexto\n");
        return NULL;
    }

    // Crear tabla de símbolos
    contexto->tabla_simbolos = crear_tabla_simbolos();
    if (!contexto->tabla_simbolos) {
        free(contexto);
        return NULL;
    }

    // Inicializar contexto
    contexto->ast_root = ast_root;
    contexto->linea_actual = 1;
    contexto->modo_debug = 1; // Debug activo por defecto

    printf("DEBUG INTERPRETE: Contexto creado exitosamente\n");
    printf("DEBUG INTERPRETE: AST tipo: %s, línea: %d\n",
           ast_root->type, ast_root->line);

    return contexto;
}

void liberar_contexto_interprete(ContextoInterprete* contexto) {
    if (!contexto) return;

    if (contexto->tabla_simbolos) {
        liberar_tabla_simbolos(contexto->tabla_simbolos);
    }

    free(contexto);
    printf("DEBUG INTERPRETE: Contexto liberado\n");
}

int procesar_ast(ContextoInterprete* contexto) {
    if (!contexto || !contexto->ast_root) {
        printf("ERROR INTERPRETE: Contexto o AST inválido\n");
        return 1;
    }

    printf("\n=== INICIANDO PROCESAMIENTO DEL AST ===\n");
    printf("DEBUG INTERPRETE: Recorriendo AST desde tipo: %s\n",
           contexto->ast_root->type);

    // Entrar al ámbito main
    entrar_ambito(contexto->tabla_simbolos, "main");

    // Recorrer el AST completo
    int resultado = recorrer_nodo(contexto, contexto->ast_root);

    printf("=== PROCESAMIENTO DEL AST FINALIZADO ===\n");

    // Mostrar tabla de símbolos final
    if (contexto->modo_debug) {
        imprimir_tabla_simbolos(contexto->tabla_simbolos);
    }

    return resultado;
}

int recorrer_nodo(ContextoInterprete* contexto, ASTNode* nodo) {
    if (!contexto || !nodo) {
        return 1;
    }

    contexto->linea_actual = nodo->line;

    if (contexto->modo_debug) {
        printf("DEBUG INTERPRETE: Recorriendo nodo '%s' en línea %d\n",
               nodo->type, nodo->line);
    }

    // Crear contexto para el procesador de nodos
    NodeProcessorContext processor_context = {
        .tabla_simbolos = contexto->tabla_simbolos,
        .linea_actual = contexto->linea_actual,
        .modo_debug = contexto->modo_debug
    };

    // Procesar el nodo usando el procesador especializado
    int resultado_procesamiento = process_ast_node(&processor_context, nodo);
    if (resultado_procesamiento != 0) {
        return resultado_procesamiento;
    }

    // **CASOS ESPECIALES: No recorrer hijos de nodos que ya manejan su recorrido internamente**
    if (nodo->type && strcmp(nodo->type, "FUNCION") == 0) {
        // Las funciones ya procesan sus hijos en process_funcion_node()
        // No recorrer hijos aquí para evitar doble procesamiento
        if (contexto->modo_debug) {
            printf("DEBUG INTERPRETE: Función '%s' ya procesó sus hijos, saltando recorrido\n",
                   nodo->type);
        }
        return 0;
    }

    // **MANEJO DE SCOPES TEMPORALES**
    int entro_scope_especial = 0;
    char scope_name[128] = {0};

    // Si es un SCOPE con valor específico, manejar ámbito
    if (nodo->type && strcmp(nodo->type, "SCOPE") == 0 && nodo->value) {
        if (strcmp(nodo->value, "IF") == 0 ||
            strcmp(nodo->value, "ELSE") == 0 ||
            strcmp(nodo->value, "BLOQUE_FOR") == 0 ||
            strcmp(nodo->value, "BLOQUE_WHILE") == 0 ||
            strcmp(nodo->value, "BLOQUE_SWITCH") == 0) {

            // Crear ámbito temporal para bloques (excluyendo FUNCION que ya se maneja)
            snprintf(scope_name, sizeof(scope_name), "%s_%d",
                     nodo->value, contexto->tabla_simbolos->siguiente_direccion++);

            if (contexto->modo_debug) {
                printf("DEBUG INTERPRETE: Entrando a ámbito temporal '%s'\n", scope_name);
            }

            entrar_ambito(contexto->tabla_simbolos, scope_name);
            entro_scope_especial = 1;
        }
    }

    // Recorrer hijos recursivamente para otros nodos
    for (int i = 0; i < nodo->child_count; i++) {
        int resultado_hijo = recorrer_nodo(contexto, nodo->children[i]);
        if (resultado_hijo != 0) {
            // Salir del ámbito si entramos
            if (entro_scope_especial) {
                salir_ambito(contexto->tabla_simbolos);
            }
            return resultado_hijo;
        }
    }

    // Salir del ámbito temporal si entramos
    if (entro_scope_especial) {
        if (contexto->modo_debug) {
            printf("DEBUG INTERPRETE: Saliendo de ámbito temporal '%s'\n", scope_name);
        }
        salir_ambito(contexto->tabla_simbolos);
    }

    return 0;
}

// Función CORREGIDA - SIN DOBLE PROCESAMIENTO
int recorrer_ast_recursivo(NodeProcessorContext* context, ASTNode* node) {
    if (!context || !node) {
        return 0;
    }

    context->linea_actual = node->line;

    if (context->modo_debug) {
        printf("🌳 RECORRER_AST_RECURSIVO: nodo '%s' en linea %d\n",
               node->type ? node->type : "NULL", node->line);
    }

    //   SOLO PROCESAR EL NODO ACTUAL - NO RECORRER HIJOS AQUÍ
    // Los hijos se procesan dentro de process_ast_node según el tipo
    int result = process_ast_node(context, node);

    if (result != 0) {
        printf("❌ ERROR procesando nodo '%s' en linea %d\n",
               node->type ? node->type : "NULL", node->line);
        return result;
    }

    if (context->modo_debug) {
        printf("  RECORRER_AST_RECURSIVO: nodo '%s' procesado exitosamente\n",
               node->type ? node->type : "NULL");
    }

    return 0;
}

// Función nueva para usar desde la GUI
int interpretar_ast_con_gui(ASTNode* ast_root, MainView* mainview) {
    if (!ast_root) {
        if (mainview) {
            mainview_append_output(mainview, "ERROR: No hay AST para procesar");
        }
        return 1;
    }

    //   CREAR CONTEXTO CON SCOPES COMBINADOS
    NodeProcessorContext context = {
        .tabla_simbolos = crear_tabla_simbolos(),
        .linea_actual = 1,
        .modo_debug = 1,
        .mainview = mainview,
        .scope_actual = NULL,    //   INICIALIZAR STACK DE SCOPES
        .scope_counter = 0       //   CONTADOR PARA NOMBRES ÚNICOS
    };

    if (mainview) {
        mainview_append_output(mainview, "Iniciando procesamiento del AST...");
    }

    // Procesar AST con output visible y scopes combinados
    int resultado = recorrer_ast_recursivo(&context, ast_root);

    if (mainview) {
        if (resultado == 0) {
            mainview_append_output(mainview, "AST procesado exitosamente");
        } else {
            mainview_append_output(mainview, "Error procesando AST");
        }
    }

    //   LIMPIAR SCOPES RESTANTES
    while (context.scope_actual) {
        salir_scope_combinado(&context, context.linea_actual);
    }

    // Mostrar tabla de símbolos final
    if (context.modo_debug) {
        printf("\n=== TABLA DE SIMBOLOS FINAL ===\n");
        imprimir_tabla_simbolos(context.tabla_simbolos);
        printf("=== FIN TABLA ===\n\n");
    }

    // Limpiar memoria
    liberar_tabla_simbolos(context.tabla_simbolos);

    return resultado;
}

// Función original sin GUI (para uso desde consola)
int interpretar_ast_simple(ASTNode* ast_root) {
    return interpretar_ast_con_gui(ast_root, NULL);
}

