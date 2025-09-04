// Reemplazar los printf por las funciones correctas:

//
// Created by lightdemon on 3/09/25.
//
#include "../../../Headers/Procesador_Do_While.h"
#include "../../../Headers/node_processor.h"
#include "../../../Headers/mainview.h"
#include "../../../Headers/globals.h"
#include "../../../Headers/scope_utils.h"
#include "../../../Headers/node_utils.h"
#include "../../../Headers/Procesador_If.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ===== IMPORTAR LAS FUNCIONES HELPER DEL NODE_PROCESSOR =====
extern int procesar_instrucciones_con_control(NodeProcessorContext* context, ASTNode* instrucciones_node, const char* contexto);
extern int es_codigo_control_flujo(int codigo);
extern const char* obtener_nombre_control(int codigo);
extern void limpiar_variables_locales_scope_actual(NodeProcessorContext* context);

extern ErrorManager* global_error_manager;

// Función para evaluar condición do-while
ResultadoCondicion evaluar_condicion_do_while(NodeProcessorContext* context, ASTNode* condicion_node) {
    if (!condicion_node) {
        procesador_error_output(context, "Nodo de condición DO_WHILE NULL");
        return CONDICION_ERROR;
    }

    // ✅ CAMBIAR: Solo debug interno, no enviar a console
    if (context->modo_debug) {
        procesador_debug_output(context, "🔍 EVALUANDO CONDICIÓN DO_WHILE");
    }

    // La condición debe tener un hijo (la expresión)
    if (condicion_node->child_count < 1) {
        procesador_error_output(context, "Condición DO_WHILE sin expresión");
        return CONDICION_ERROR;
    }

    ASTNode* expresion_node = condicion_node->children[0];

    // Evaluar la expresión de condición
    char* valor_condicion = obtener_valor_desde_nodo(expresion_node, context);

    if (!valor_condicion) {
        procesador_error_output(context, "No se pudo evaluar la condición DO_WHILE");
        return CONDICION_ERROR;
    }

    // ✅ CAMBIAR: Solo debug interno
    if (context->modo_debug) {
        char debug_msg[128];
        snprintf(debug_msg, sizeof(debug_msg), "🔍 CONDICIÓN DO_WHILE EVALUADA: '%s'", valor_condicion);
        procesador_debug_output(context, debug_msg);
    }

    // Determinar resultado (para do-while, evaluamos como boolean)
    ResultadoCondicion resultado;
    if (strcmp(valor_condicion, "true") == 0) {
        resultado = CONDICION_TRUE;
    } else if (strcmp(valor_condicion, "false") == 0) {
        resultado = CONDICION_FALSE;
    } else {
        // Para valores numéricos, 0 = false, cualquier otro = true
        double valor = convertir_a_numero(valor_condicion, TIPO_DOUBLE);
        if (valor != 0.0) {
            resultado = CONDICION_TRUE;
        } else {
            resultado = CONDICION_FALSE;
        }
    }

    // ✅ CAMBIAR: Solo debug interno
    if (context->modo_debug) {
        char debug_msg[64];
        snprintf(debug_msg, sizeof(debug_msg), "🔍 CONDICIÓN DO_WHILE %s",
                resultado == CONDICION_TRUE ? "VERDADERA" : "FALSA");
        procesador_debug_output(context, debug_msg);
    }

    free(valor_condicion);
    return resultado;
}

// Función para ejecutar el bloque del do-while
int ejecutar_bloque_do_while(NodeProcessorContext* context, ASTNode* bloque_node) {
    if (!context || !bloque_node) {
        procesador_error_output(context, "❌ ERROR DO_WHILE: Bloque inválido");
        return 0;
    }

    // ✅ CAMBIAR: Solo debug interno
    if (context->modo_debug) {
        char debug_msg[128];
        snprintf(debug_msg, sizeof(debug_msg), "🔄 EJECUTANDO BLOQUE DO_WHILE en línea %d", bloque_node->line);
        procesador_debug_output(context, debug_msg);
    }

    // El bloque puede tener estructura: BLOQUE_DO -> SCOPE -> INSTRUCCIONES
    ASTNode* nodo_a_procesar = bloque_node;

    // Si es BLOQUE_DO, buscar el SCOPE interno
    if (strcmp(bloque_node->type, "BLOQUE_DO") == 0) {
        if (bloque_node->child_count > 0 && bloque_node->children[0]) {
            nodo_a_procesar = bloque_node->children[0];
            if (context->modo_debug) {
                procesador_debug_output(context, "🔍 ENCONTRADO SCOPE dentro de BLOQUE_DO");
            }
        }
    }

    // Usar la función helper para procesar
    if (strcmp(nodo_a_procesar->type, "SCOPE") == 0) {
        if (context->modo_debug) {
            procesador_debug_output(context, "🔍 ENCONTRADAS INSTRUCCIONES dentro del SCOPE");
        }

        // Buscar INSTRUCCIONES dentro del SCOPE
        for (int i = 0; i < nodo_a_procesar->child_count; i++) {
            ASTNode* hijo = nodo_a_procesar->children[i];
            if (hijo && strcmp(hijo->type, "INSTRUCCIONES") == 0) {
                if (context->modo_debug) {
                    procesador_debug_output(context, "🔍 PROCESANDO INSTRUCCIONES DEL DO_WHILE con control de flujo");
                }
                int resultado = procesar_instrucciones_con_control(context, hijo, "DO_WHILE");

                if (es_codigo_control_flujo(resultado) && context->modo_debug) {
                    char debug_msg[128];
                    snprintf(debug_msg, sizeof(debug_msg), "🔄 DO_WHILE recibiendo %s: %d",
                            obtener_nombre_control(resultado), resultado);
                    procesador_debug_output(context, debug_msg);
                }

                return resultado;
            }
        }
    } else if (strcmp(nodo_a_procesar->type, "INSTRUCCIONES") == 0) {
        // Es directamente INSTRUCCIONES
        if (context->modo_debug) {
            procesador_debug_output(context, "🔍 PROCESANDO INSTRUCCIONES DIRECTAS DEL DO_WHILE");
        }
        int resultado = procesar_instrucciones_con_control(context, nodo_a_procesar, "DO_WHILE");

        if (es_codigo_control_flujo(resultado) && context->modo_debug) {
            char debug_msg[128];
            snprintf(debug_msg, sizeof(debug_msg), "🔄 DO_WHILE recibiendo %s: %d",
                    obtener_nombre_control(resultado), resultado);
            procesador_debug_output(context, debug_msg);
        }

        return resultado;
    }

    procesador_error_output(context, "❌ ERROR DO_WHILE: Estructura de bloque no reconocida");
    return 0;
}

// Procesador principal para el nodo DO_WHILE
char* process_do_while_node(NodeProcessorContext* context, ASTNode* node) {
    if (!context || !node) {
        procesador_error_output(context, "ERROR: Parámetros inválidos para do-while");
        return NULL;
    }

    // ✅ CAMBIAR: Solo debug interno
    if (context->modo_debug) {
        char debug_msg[128];
        snprintf(debug_msg, sizeof(debug_msg), "🔄 PROCESANDO DO_WHILE en línea %d", node->line);
        procesador_debug_output(context, debug_msg);
    }

    if (node->child_count < 2) {
        procesador_error_output(context, "ERROR: Do-While malformado - faltan componentes");
        return NULL;
    }

    ASTNode* bloque_node = node->children[0];    // BLOQUE_DO (primero en do-while)
    ASTNode* condicion_node = node->children[1]; // CONDICION_DO_WHILE (segundo en do-while)

    // Crear scope del do-while
    char* do_while_scope_name = generate_scope_name(context, SCOPE_TYPE_DO_WHILE, node);
    if (!do_while_scope_name) {
        procesador_error_output(context, "ERROR: No se pudo crear scope para do-while");
        return NULL;
    }

    // ✅ CAMBIAR: Solo debug interno
    if (context->modo_debug) {
        char debug_msg[256];
        snprintf(debug_msg, sizeof(debug_msg), "🔄 INICIANDO DO_WHILE - creando scope '%s'", do_while_scope_name);
        procesador_debug_output(context, debug_msg);
    }

    entrar_scope_combinado(context, SCOPE_WHILE, do_while_scope_name, node->line);

    int iteraciones = 0;
    int max_iteraciones = 10000; // Protección contra bucles infinitos

    // ===== LÓGICA ESPECÍFICA DO_WHILE: EJECUTAR AL MENOS UNA VEZ =====
    if (context->modo_debug) {
        procesador_debug_output(context, "🔄 === DO_WHILE: EJECUCIÓN GARANTIZADA (ITERACIÓN 1) ===");
    }

    do {
        iteraciones++;

        // ✅ CAMBIAR: Solo debug interno
        if (context->modo_debug) {
            char debug_msg[128];
            snprintf(debug_msg, sizeof(debug_msg), "🔄 === ITERACIÓN %d DEL DO_WHILE ===", iteraciones);
            procesador_debug_output(context, debug_msg);
        }

        // 🧹 LIMPIAR VARIABLES LOCALES DE LA ITERACIÓN ANTERIOR
        if (iteraciones > 1) {
            if (context->modo_debug) {
                procesador_debug_output(context, "🧹 Limpiando variables de iteración anterior...");
            }
            limpiar_variables_locales_scope_actual(context);
        }

        // Ejecutar bloque del do-while usando función helper
        int resultado_bloque = ejecutar_bloque_do_while(context, bloque_node);

        // ===== VERIFICAR CÓDIGOS DE CONTROL DE FLUJO =====
        if (resultado_bloque == -1) { // break
            if (context->modo_debug) {
                procesador_debug_output(context, "🛑 BREAK detectado - terminando do-while");
            }
            break;
        }

        if (resultado_bloque == -2) { // continue
            if (context->modo_debug) {
                procesador_debug_output(context, "🔄 CONTINUE detectado - saltando a evaluación de condición");
                procesador_debug_output(context, "🧹 Limpiando variables antes de continue...");
            }

            // 🧹 LIMPIAR VARIABLES ANTES DE CONTINUE
            limpiar_variables_locales_scope_actual(context);

            // ===== EVALUAR LA CONDICIÓN PARA VER SI CONTINÚA =====
            ResultadoCondicion resultado_condicion = evaluar_condicion_do_while(context, condicion_node);
            if (resultado_condicion != CONDICION_TRUE || iteraciones >= max_iteraciones) {
                if (context->modo_debug) {
                    procesador_debug_output(context, "🔄 CONDICIÓN FALSA O LÍMITE ALCANZADO - terminando do-while después de continue");
                }
                break;
            }
            continue; // Saltar al siguiente ciclo del do-while
        }

        if (resultado_bloque == -3) { // return
            if (context->modo_debug) {
                procesador_debug_output(context, "↩️ RETURN detectado - saliendo de función");
            }
            salir_scope_combinado(context, node->line);
            free(do_while_scope_name);
            return NULL; // Propagar return
        }

        // ✅ CAMBIAR: Solo debug interno
        if (context->modo_debug) {
            char debug_msg[128];
            snprintf(debug_msg, sizeof(debug_msg), "🔄 === FIN ITERACIÓN %d ===", iteraciones);
            procesador_debug_output(context, debug_msg);
        }

        // ===== EVALUAR LA CONDICIÓN PARA VER SI CONTINÚA =====
        if (iteraciones >= max_iteraciones) {
            if (context->modo_debug) {
                char debug_msg[128];
                snprintf(debug_msg, sizeof(debug_msg), "⚠️ LÍMITE DE ITERACIONES ALCANZADO (%d) - terminando do-while", max_iteraciones);
                procesador_debug_output(context, debug_msg);
            }
            break;
        }

        ResultadoCondicion resultado_condicion = evaluar_condicion_do_while(context, condicion_node);
        if (resultado_condicion != CONDICION_TRUE) {
            if (context->modo_debug) {
                procesador_debug_output(context, "🔄 CONDICIÓN FALSA - terminando do-while");
            }
            break;
        }

        if (context->modo_debug) {
            procesador_debug_output(context, "🔄 CONDICIÓN VERDADERA - continuando do-while");
        }

    } while (iteraciones < max_iteraciones);

    // 🧹 LIMPIEZA FINAL
    if (context->modo_debug) {
        procesador_debug_output(context, "🧹 Limpieza final del scope DO_WHILE...");
    }
    limpiar_variables_locales_scope_actual(context);

    // Salir del scope del do-while
    salir_scope_combinado(context, node->line);
    free(do_while_scope_name);

    // ✅ CAMBIAR: Solo debug interno
    if (context->modo_debug) {
        char debug_msg[128];
        snprintf(debug_msg, sizeof(debug_msg), "✅ DO_WHILE COMPLETADO - %d iteraciones ejecutadas", iteraciones);
        procesador_debug_output(context, debug_msg);
    }

    // Retornar resultado
    char* resultado = malloc(16);
    snprintf(resultado, 16, "%d", iteraciones);
    return resultado;
}