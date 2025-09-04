//
// Created by lightdemon on 2/09/25.
//
#include "../../../Headers/Procesador_While.h"
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
extern int procesar_bloque_con_scope(NodeProcessorContext* context, ASTNode* bloque_node,
                                     ScopeType tipo_scope, const char* nombre_scope,
                                     const char* contexto);
extern int es_codigo_control_flujo(int codigo);
extern const char* obtener_nombre_control(int codigo);
extern void limpiar_variables_locales_scope_actual(NodeProcessorContext* context);

extern ErrorManager* global_error_manager;

// Función para evaluar condición while
ResultadoCondicion evaluar_condicion_while(NodeProcessorContext* context, ASTNode* condicion_node) {
    if (!condicion_node) {
        procesador_error_output(context, "Nodo de condición NULL");
        return CONDICION_ERROR;
    }

    char debug_msg[256];
    snprintf(debug_msg, sizeof(debug_msg), "🔍 EVALUANDO CONDICIÓN WHILE en línea %d", condicion_node->line);
    procesador_debug_output(context, debug_msg);

    // La condición debe tener un hijo (la expresión)
    if (condicion_node->child_count < 1) {
        procesador_error_output(context, "Condición WHILE sin expresión");
        return CONDICION_ERROR;
    }

    ASTNode* expresion_node = condicion_node->children[0];

    // Evaluar la expresión de condición
    TipoDato tipo_condicion = obtener_tipo_desde_nodo(expresion_node, context);
    char* valor_condicion = obtener_valor_desde_nodo(expresion_node, context);

    if (!valor_condicion) {
        procesador_error_output(context, "No se pudo evaluar la condición WHILE");
        return CONDICION_ERROR;
    }

    snprintf(debug_msg, sizeof(debug_msg), "🔍 CONDICIÓN EVALUADA: '%s'", valor_condicion);
    procesador_debug_output(context, debug_msg);

    // Determinar resultado (para while, evaluamos como boolean)
    ResultadoCondicion resultado;
    if (strcmp(valor_condicion, "true") == 0) {
        resultado = CONDICION_TRUE;
        snprintf(debug_msg, sizeof(debug_msg), "🔍 CONDICIÓN VERDADERA: true");
    } else if (strcmp(valor_condicion, "false") == 0) {
        resultado = CONDICION_FALSE;
        snprintf(debug_msg, sizeof(debug_msg), "🔍 CONDICIÓN FALSA: false");
    } else {
        // Para valores numéricos, 0 = false, cualquier otro = true
        double valor = convertir_a_numero(valor_condicion, tipo_condicion);
        if (valor != 0.0) {
            resultado = CONDICION_TRUE;
            snprintf(debug_msg, sizeof(debug_msg), "🔍 CONDICIÓN VERDADERA: %s", valor_condicion);
        } else {
            resultado = CONDICION_FALSE;
            snprintf(debug_msg, sizeof(debug_msg), "🔍 CONDICIÓN FALSA: %s", valor_condicion);
        }
    }

    procesador_debug_output(context, debug_msg);
    free(valor_condicion);
    return resultado;
}

// Función para ejecutar el bloque del while (USANDO FUNCIONES HELPER)
int ejecutar_bloque_while(NodeProcessorContext* context, ASTNode* bloque_node) {
    if (!context || !bloque_node) {
        printf("❌ ERROR WHILE: Bloque inválido\n");
        return 0;
    }

    printf("🔄 EJECUTANDO BLOQUE WHILE en línea %d\n", bloque_node->line);

    // El bloque puede tener estructura: BLOQUE_WHILE -> SCOPE -> INSTRUCCIONES
    ASTNode* nodo_a_procesar = bloque_node;

    // Si es BLOQUE_WHILE, buscar el SCOPE interno
    if (strcmp(bloque_node->type, "BLOQUE_WHILE") == 0) {
        if (bloque_node->child_count > 0 && bloque_node->children[0]) {
            nodo_a_procesar = bloque_node->children[0];
            printf("🔍 ENCONTRADO SCOPE dentro de BLOQUE_WHILE\n");
        }
    }

    // Usar la función helper para procesar
    if (strcmp(nodo_a_procesar->type, "SCOPE") == 0) {
        printf("🔍 ENCONTRADAS INSTRUCCIONES dentro del SCOPE\n");

        // Buscar INSTRUCCIONES dentro del SCOPE
        for (int i = 0; i < nodo_a_procesar->child_count; i++) {
            ASTNode* hijo = nodo_a_procesar->children[i];
            if (hijo && strcmp(hijo->type, "INSTRUCCIONES") == 0) {
                // ===== USAR FUNCIÓN HELPER PARA CONTROL DE FLUJO =====
                printf("🔍 PROCESANDO INSTRUCCIONES DEL WHILE con control de flujo\n");
                int resultado = procesar_instrucciones_con_control(context, hijo, "WHILE");

                // ===== VERIFICAR Y PROPAGAR CÓDIGOS DE CONTROL =====
                if (es_codigo_control_flujo(resultado)) {
                    printf("🔄 WHILE recibiendo %s: %d\n", obtener_nombre_control(resultado), resultado);
                }

                return resultado;
            }
        }
    } else if (strcmp(nodo_a_procesar->type, "INSTRUCCIONES") == 0) {
        // Es directamente INSTRUCCIONES
        printf("🔍 PROCESANDO INSTRUCCIONES DIRECTAS DEL WHILE\n");
        int resultado = procesar_instrucciones_con_control(context, nodo_a_procesar, "WHILE");

        if (es_codigo_control_flujo(resultado)) {
            printf("🔄 WHILE recibiendo %s: %d\n", obtener_nombre_control(resultado), resultado);
        }

        return resultado;
    }

    printf("❌ ERROR WHILE: Estructura de bloque no reconocida\n");
    return 0;
}

// Procesador principal para el nodo WHILE (CORREGIDO PARA USAR HELPERS)
char* process_while_node(NodeProcessorContext* context, ASTNode* node) {
    if (!context || !node) {
        printf("ERROR: Parámetros inválidos para while\n");
        return NULL;
    }

    printf("🔄 PROCESANDO WHILE en línea %d\n", node->line);

    if (node->child_count < 2) {
        printf("ERROR: While malformado - faltan componentes\n");
        return NULL;
    }

    ASTNode* condicion_node = node->children[0]; // CONDICION_WHILE
    ASTNode* bloque_node = node->children[1];    // BLOQUE_WHILE

    // ===== USAR SCOPE UTILS PARA CREAR SCOPE DEL WHILE =====
    char* while_scope_name = generate_scope_name(context, SCOPE_TYPE_WHILE, node);
    if (!while_scope_name) {
        printf("ERROR: No se pudo crear scope para while\n");
        return NULL;
    }

    printf("🔄 INICIANDO WHILE - creando scope '%s'\n", while_scope_name);
    entrar_scope_combinado(context, SCOPE_WHILE, while_scope_name, node->line);

    int iteraciones = 0;
    int max_iteraciones = 10000; // Protección contra bucles infinitos

    // ===== BUCLE PRINCIPAL DEL WHILE CON CONTROL DE FLUJO =====
    ResultadoCondicion resultado_condicion = evaluar_condicion_while(context, condicion_node);

    while (iteraciones < max_iteraciones && resultado_condicion == CONDICION_TRUE) {
        printf("\n🔄 === ITERACIÓN %d DEL WHILE ===\n", iteraciones + 1);

        // 🧹 LIMPIAR VARIABLES LOCALES DE LA ITERACIÓN ANTERIOR (COMPORTAMIENTO JAVA)
        if (iteraciones > 0) {
            printf("🧹 Limpiando variables de iteración anterior (comportamiento Java)...\n");
            limpiar_variables_locales_scope_actual(context);
        }

        // Ejecutar bloque del while usando función helper
        int resultado_bloque = ejecutar_bloque_while(context, bloque_node);

        // ===== VERIFICAR CÓDIGOS DE CONTROL DE FLUJO =====
        if (resultado_bloque == -1) { // break
            printf("🛑 BREAK detectado - terminando while\n");
            break;
        }

        if (resultado_bloque == -2) { // continue
            printf("🔄 CONTINUE detectado - saltando a siguiente iteración\n");
            printf("   → Continue procesado correctamente\n");

            // 🧹 LIMPIAR VARIABLES ANTES DE CONTINUE (COMPORTAMIENTO JAVA)
            printf("🧹 Limpiando variables antes de continue (comportamiento Java)...\n");
            limpiar_variables_locales_scope_actual(context);

            iteraciones++;

            // ===== RE-EVALUAR LA CONDICIÓN PARA LA SIGUIENTE ITERACIÓN =====
            resultado_condicion = evaluar_condicion_while(context, condicion_node);
            continue; // Saltar al siguiente ciclo del while
        }

        if (resultado_bloque == -3) { // return
            printf("↩️ RETURN detectado - saliendo de función\n");
            salir_scope_combinado(context, node->line);
            free(while_scope_name);
            return NULL; // Propagar return
        }

        if (resultado_bloque != 0 && !es_codigo_control_flujo(resultado_bloque)) {
            printf("❌ ERROR en ejecución del bloque while\n");
            break;
        }

        iteraciones++;

        // ===== RE-EVALUAR LA CONDICIÓN SOLO SI NO HUBO CONTINUE =====
        resultado_condicion = evaluar_condicion_while(context, condicion_node);

        printf("🔄 === FIN ITERACIÓN %d ===\n", iteraciones);
    }

    // Verificar si se terminó por condición falsa
    if (resultado_condicion == CONDICION_FALSE) {
        printf("🔄 CONDICIÓN FALSA - terminando while\n");
    }

    // 🧹 LIMPIEZA FINAL: Eliminar todas las variables del scope del while
    printf("🧹 Limpieza final del scope WHILE (comportamiento Java)...\n");
    limpiar_variables_locales_scope_actual(context);

    // Salir del scope del while
    salir_scope_combinado(context, node->line);
    free(while_scope_name);

    printf("✅ WHILE COMPLETADO - %d iteraciones ejecutadas\n", iteraciones);

    // Retornar resultado
    char* resultado = malloc(16);
    snprintf(resultado, 16, "%d", iteraciones);
    return resultado;
}