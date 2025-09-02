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

int recorrer_ast_recursivo(NodeProcessorContext* context, ASTNode* node) {
    if (!context || !node) {
        return 0;
    }

    context->linea_actual = node->line;

    if (context->modo_debug) {
        printf("DEBUG INTERPRETE: Recorriendo nodo '%s' en línea %d\n",
               node->type ? node->type : "NULL", node->line);
    }

    // **MANEJAR SCOPES ESPECÍFICOS**
    int entro_scope_especial = 0;
    char scope_name[128] = {0};

    // Si es un SCOPE con valor específico, manejar ámbito
    if (node->type && strcmp(node->type, "SCOPE") == 0 && node->value) {
        if (strcmp(node->value, "FUNCION") == 0 ||
            strcmp(node->value, "IF") == 0 ||
            strcmp(node->value, "ELSE") == 0 ||
            strcmp(node->value, "BLOQUE_FOR") == 0 ||
            strcmp(node->value, "BLOQUE_WHILE") == 0 ||
            strcmp(node->value, "BLOQUE_SWITCH") == 0) {

            // Crear ámbito temporal para bloques
            snprintf(scope_name, sizeof(scope_name), "%s_%d",
                     node->value, context->tabla_simbolos->siguiente_direccion++);

            if (context->modo_debug) {
                printf("DEBUG INTERPRETE: Entrando a ámbito temporal '%s'\n", scope_name);
            }

            entrar_ambito(context->tabla_simbolos, scope_name);
            entro_scope_especial = 1;
        }
    }

    // Procesar el nodo actual
    int result = process_ast_node(context, node);

    if (result != 0) {
        printf("ERROR INTERPRETE: Error procesando nodo '%s' en línea %d\n",
               node->type ? node->type : "NULL", node->line);

        // Salir del ámbito si entramos
        if (entro_scope_especial) {
            salir_ambito(context->tabla_simbolos);
        }
        return result;
    }

    // **CASOS ESPECIALES: Funciones ya manejan sus propios ámbitos**
    if (node->type && strcmp(node->type, "FUNCION") == 0) {
        // Las funciones ya manejan sus ámbitos en process_funcion_node
        // Solo procesar los hijos que NO sean SIGNATURA_FUNCION, BLOQUE_FUNCION
        for (int i = 0; i < node->child_count; i++) {
            ASTNode* child = node->children[i];
            if (child && child->type) {
                // Saltar hijos que ya se procesaron en process_funcion_node
                if (strcmp(child->type, "SIGNATURA_FUNCION") == 0 ||
                    strcmp(child->type, "BLOQUE_FUNCION") == 0) {
                    continue;
                }

                result = recorrer_ast_recursivo(context, child);
                if (result != 0) {
                    if (entro_scope_especial) {
                        salir_ambito(context->tabla_simbolos);
                    }
                    return result;
                }
            }
        }
    } else {
        // Procesar hijos recursivamente para otros nodos
        for (int i = 0; i < node->child_count; i++) {
            ASTNode* child = node->children[i];
            if (child) {
                result = recorrer_ast_recursivo(context, child);
                if (result != 0) {
                    if (entro_scope_especial) {
                        salir_ambito(context->tabla_simbolos);
                    }
                    return result;
                }
            }
        }
    }

    // Salir del ámbito temporal si entramos
    if (entro_scope_especial) {
        if (context->modo_debug) {
            printf("DEBUG INTERPRETE: Saliendo de ámbito temporal '%s'\n", scope_name);
        }
        salir_ambito(context->tabla_simbolos);
    }

    return 0;
}

// Función nueva para usar desde la GUI
int interpretar_ast_con_gui(ASTNode* ast_root, MainView* mainview) {
    if (!ast_root) {
        if (mainview) {
            mainview_append_output(mainview, "❌ No hay AST para procesar");
        }
        return 1;
    }

    // Crear contexto con mainview
    NodeProcessorContext context = {
        .tabla_simbolos = crear_tabla_simbolos(),
        .linea_actual = 1,
        .modo_debug = 1,  // Activar debug para GUI
        .mainview = mainview  //   PASAR MAINVIEW
    };

    if (mainview) {
        mainview_append_output(mainview, "  Iniciando procesamiento del AST...");
    }

    // Procesar AST con output visible
    int resultado = recorrer_ast_recursivo(&context, ast_root);

    if (mainview) {
        if (resultado == 0) {
            mainview_append_output(mainview, "  AST procesado exitosamente");
        } else {
            mainview_append_output(mainview, "❌ Error procesando AST");
        }
    }

    return resultado;
}

// Función original sin GUI (para uso desde consola)
int interpretar_ast_simple(ASTNode* ast_root) {
    return interpretar_ast_con_gui(ast_root, NULL);
}

