#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "mainview.h"
#include "../../../Headers/ast.h"
#include "../../../Headers/node_processor.h"
#include "../../../Headers/scope_utils.h"
#include "../../../Headers/error_manager.h"
#include "../../../Headers/Procesador_Expresion.h"
#include "../../../Headers/node_utils.h"

extern ErrorManager* global_error_manager;

// ===== IMPORTAR LAS FUNCIONES HELPER DEL NODE_PROCESSOR =====
extern int procesar_instrucciones_con_control(NodeProcessorContext* context, ASTNode* instrucciones_node, const char* contexto);
extern int procesar_bloque_con_scope(NodeProcessorContext* context, ASTNode* bloque_node,
                                     ScopeType tipo_scope, const char* nombre_scope,
                                     const char* contexto);
extern int es_codigo_control_flujo(int codigo);
extern const char* obtener_nombre_control(int codigo);
extern void limpiar_variables_locales_scope_actual(NodeProcessorContext* context);

// Estructura para manejar el estado del switch
typedef struct {
    char* valor_switch;          // Valor de la expresión del switch
    TipoDato tipo_switch;        // Tipo de la expresión
    int caso_ejecutando;         // Flag si estamos ejecutando un caso
    int break_encontrado;        // Flag si se encontró break
    int default_ejecutado;       // Flag si se ejecutó default
    int fall_through;           // Flag para fall-through (sin break)
    int return_encontrado;      // Flag si se encontró return
    int continue_encontrado;    // Flag si se encontró continue
} SwitchState;

// Función para crear estado del switch
SwitchState* crear_switch_state() {
    SwitchState* state = malloc(sizeof(SwitchState));
    if (!state) return NULL;

    state->valor_switch = NULL;
    state->tipo_switch = TIPO_DESCONOCIDO;
    state->caso_ejecutando = 0;
    state->break_encontrado = 0;
    state->default_ejecutado = 0;
    state->fall_through = 0;
    state->return_encontrado = 0;
    state->continue_encontrado = 0;

    return state;
}

// Función para liberar estado del switch
void liberar_switch_state(SwitchState* state) {
    if (state) {
        if (state->valor_switch) {
            free(state->valor_switch);
        }
        free(state);
    }
}

// Función para comparar valores de caso
int comparar_valores_caso(const char* valor_switch, TipoDato tipo_switch,
                         const char* valor_caso, TipoDato tipo_caso) {
    if (!valor_switch || !valor_caso) return 0;

    printf("   🔍 Comparando: switch='%s'(%s) vs case='%s'(%s)\n",
           valor_switch, tipo_dato_to_string(tipo_switch),
           valor_caso, tipo_dato_to_string(tipo_caso));

    // En Java, el switch requiere tipos compatibles
    if (tipo_switch != tipo_caso) {
        // Permitir algunas conversiones automáticas como en Java
        if ((tipo_switch == TIPO_INT && tipo_caso == TIPO_CHAR) ||
            (tipo_switch == TIPO_CHAR && tipo_caso == TIPO_INT)) {
            printf("   ✅ Conversión automática permitida\n");
        } else {
            printf("   ❌ Tipos incompatibles para comparación\n");
            return 0; // Tipos incompatibles
        }
    }

    // Comparación basada en el tipo
    switch (tipo_switch) {
        case TIPO_INT:
        case TIPO_CHAR: {
            int val_switch = (int)convertir_a_numero(valor_switch, tipo_switch);
            int val_caso = (int)convertir_a_numero(valor_caso, tipo_caso);
            printf("   → Comparando números: %d == %d\n", val_switch, val_caso);
            return val_switch == val_caso;
        }
        case TIPO_STRING: {
            int resultado = strcmp(valor_switch, valor_caso) == 0;
            printf("   → Comparando strings: %s\n", resultado ? "IGUALES" : "DIFERENTES");
            return resultado;
        }
        case TIPO_FLOAT:
        case TIPO_DOUBLE: {
            // Java no permite float/double en switch, pero manejamos por compatibilidad
            double val_switch = convertir_a_numero(valor_switch, tipo_switch);
            double val_caso = convertir_a_numero(valor_caso, tipo_caso);
            printf("   → Comparando decimales: %.2f == %.2f\n", val_switch, val_caso);
            return val_switch == val_caso;
        }
        default: {
            int resultado = strcmp(valor_switch, valor_caso) == 0;
            printf("   → Comparando como string: %s\n", resultado ? "IGUALES" : "DIFERENTES");
            return resultado;
        }
    }
}

int procesar_caso(NodeProcessorContext* context, ASTNode* caso_node, SwitchState* state) {
    if (!context || !caso_node || !state) return 1;

    printf("🔍 PROCESANDO CASO en línea %d\n", caso_node->line);

    // Verificar si ya debemos ejecutar por fall-through
    if (state->fall_through || state->caso_ejecutando) {
        printf("   → Ejecutando por fall-through\n");
        state->caso_ejecutando = 1;
    }

    // Si no estamos ejecutando, verificar si este caso coincide
    if (!state->caso_ejecutando && caso_node->child_count > 0) {
        ASTNode* valor_caso_node = caso_node->children[0]; // VALOR_CASO

        if (valor_caso_node && valor_caso_node->child_count > 0) {
            ASTNode* expresion_caso = valor_caso_node->children[0];

            // Evaluar el valor del caso
            char* valor_caso = process_expresion_node(context, expresion_caso);
            if (valor_caso) {
                TipoDato tipo_caso = obtener_tipo_desde_nodo(expresion_caso, context);

                printf("   → Caso evaluado: '%s' (tipo: %s)\n",
                       valor_caso, tipo_dato_to_string(tipo_caso));

                // Verificar si coincide
                if (comparar_valores_caso(state->valor_switch, state->tipo_switch,
                                         valor_caso, tipo_caso)) {
                    printf("   ✅ CASO COINCIDE - iniciando ejecución\n");
                    state->caso_ejecutando = 1;
                } else {
                    printf("   ❌ Caso no coincide - saltando\n");
                }

                free(valor_caso);
            }
        }
    }

    // Si estamos ejecutando este caso, procesar sus instrucciones
    if (state->caso_ejecutando) {
        printf("   🚀 EJECUTANDO INSTRUCCIONES DEL CASO\n");

        // Procesar INSTRUCCIONES_CASO y SENTENCIA_CASO
        for (int i = 1; i < caso_node->child_count && !state->break_encontrado &&
             !state->return_encontrado && !state->continue_encontrado; i++) {
            ASTNode* hijo = caso_node->children[i];

            if (strcmp(hijo->type, "INSTRUCCIONES_CASO") == 0) {
                printf("   📝 Encontrado INSTRUCCIONES_CASO\n");

                // USAR TU SISTEMA DE SCOPE GENERATOR
                char* case_scope_name = generate_scope_name(context, SCOPE_TYPE_CASE, hijo);
                if (case_scope_name) {
                    // Entrar al scope del caso usando tu sistema
                    entrar_scope_combinado(context, SCOPE_SWITCH, case_scope_name, caso_node->line);

                    // Procesar el contenido del INSTRUCCIONES_CASO
                    if (hijo->child_count > 0) {
                        ASTNode* scope_node = hijo->children[0];

                        if (strcmp(scope_node->type, "SCOPE") == 0) {
                            printf("   🎯 Procesando SCOPE dentro de INSTRUCCIONES_CASO\n");

                            if (scope_node->child_count > 0) {
                                ASTNode* instrucciones_node = scope_node->children[0];

                                if (strcmp(instrucciones_node->type, "INSTRUCCIONES") == 0) {
                                    printf("   ✅ EJECUTANDO INSTRUCCIONES DEL CASO\n");

                                    // Usar tu función helper para procesar instrucciones
                                    int resultado = procesar_instrucciones_con_control(context, instrucciones_node, "SWITCH_CASE");

                                    // Verificar códigos de control de flujo
                                    if (resultado == -1) { // break
                                        printf("   🛑 BREAK detectado en caso\n");
                                        state->break_encontrado = 1;

                                        // 🧹 LIMPIEZA JAVA ANTES DE SALIR POR BREAK
                                        printf("🧹 Limpieza del scope CASE antes de BREAK (comportamiento Java)...\n");
                                        limpiar_variables_locales_scope_actual(context);

                                        salir_scope_combinado(context, caso_node->line);
                                        free(case_scope_name);
                                        return -1;
                                    }
                                    if (resultado == -2) { // continue
                                        printf("   🔄 CONTINUE detectado en caso\n");
                                        state->continue_encontrado = 1;

                                        // 🧹 LIMPIEZA JAVA ANTES DE SALIR POR CONTINUE
                                        printf("🧹 Limpieza del scope CASE antes de CONTINUE (comportamiento Java)...\n");
                                        limpiar_variables_locales_scope_actual(context);

                                        salir_scope_combinado(context, caso_node->line);
                                        free(case_scope_name);
                                        return -2;
                                    }
                                    if (resultado == -3) { // return
                                        printf("   ↩️ RETURN detectado en caso\n");
                                        state->return_encontrado = 1;

                                        // 🧹 LIMPIEZA JAVA ANTES DE SALIR POR RETURN
                                        printf("🧹 Limpieza del scope CASE antes de RETURN (comportamiento Java)...\n");
                                        limpiar_variables_locales_scope_actual(context);

                                        salir_scope_combinado(context, caso_node->line);
                                        free(case_scope_name);
                                        return -3;
                                    }
                                } else {
                                    // Procesar el nodo directamente
                                    printf("   🎯 Procesando nodo directo en SCOPE\n");
                                    int resultado = process_ast_node(context, instrucciones_node);

                                    if (es_codigo_control_flujo(resultado)) {
                                        if (resultado == -1) state->break_encontrado = 1;
                                        if (resultado == -2) state->continue_encontrado = 1;
                                        if (resultado == -3) state->return_encontrado = 1;

                                        // 🧹 LIMPIEZA JAVA ANTES DE SALIR POR CONTROL DE FLUJO
                                        printf("🧹 Limpieza del scope CASE antes de %s (comportamiento Java)...\n",
                                               obtener_nombre_control(resultado));
                                        limpiar_variables_locales_scope_actual(context);

                                        salir_scope_combinado(context, caso_node->line);
                                        free(case_scope_name);
                                        return resultado;
                                    }
                                }
                            }
                        } else {
                            // Procesar INSTRUCCIONES_CASO directamente
                            printf("   🎯 Procesando INSTRUCCIONES_CASO directamente\n");
                            int resultado = process_ast_node(context, hijo);

                            if (es_codigo_control_flujo(resultado)) {
                                if (resultado == -1) state->break_encontrado = 1;
                                if (resultado == -2) state->continue_encontrado = 1;
                                if (resultado == -3) state->return_encontrado = 1;

                                // 🧹 LIMPIEZA JAVA ANTES DE SALIR POR CONTROL DE FLUJO
                                printf("🧹 Limpieza del scope CASE antes de %s (comportamiento Java)...\n",
                                       obtener_nombre_control(resultado));
                                limpiar_variables_locales_scope_actual(context);

                                salir_scope_combinado(context, caso_node->line);
                                free(case_scope_name);
                                return resultado;
                            }
                        }
                    }

                    // 🧹 LIMPIEZA JAVA AL FINAL DEL CASO (FALL-THROUGH O TERMINACIÓN NORMAL)
                    if (!state->break_encontrado && !state->return_encontrado && !state->continue_encontrado) {
                        printf("🧹 Limpieza del scope CASE al final del caso (comportamiento Java)...\n");
                        limpiar_variables_locales_scope_actual(context);
                    }

                    // Salir del scope del caso
                    salir_scope_combinado(context, caso_node->line);
                    free(case_scope_name);
                }
            }
            else if (strcmp(hijo->type, "SENTENCIA_CASO") == 0) {
                printf("   🎮 Procesando sentencia de control\n");

                for (int j = 0; j < hijo->child_count; j++) {
                    ASTNode* sentencia = hijo->children[j];

                    if (strcmp(sentencia->type, "BREAK") == 0) {
                        printf("   🛑 BREAK explícito encontrado - terminando switch\n");
                        state->break_encontrado = 1;
                        return 0; // Break en switch termina el switch, no se propaga
                    } else {
                        int resultado = process_ast_node(context, sentencia);

                        if (resultado == -2) { // continue
                            printf("   🔄 CONTINUE detectado - propagando hacia arriba\n");
                            state->continue_encontrado = 1;
                            return -2;
                        }
                        if (resultado == -3) { // return
                            printf("   ↩️ RETURN detectado - propagando hacia arriba\n");
                            state->return_encontrado = 1;
                            return -3;
                        }
                    }
                }
            }
        }

        // Si no se encontró break, marcar fall-through
        if (!state->break_encontrado && !state->return_encontrado && !state->continue_encontrado) {
            printf("   ⬇️ No hay break - activando fall-through\n");
            state->fall_through = 1;
        }
    }

    return 0;
}

// Función para procesar caso con default (USANDO FUNCIONES HELPER)
int procesar_caso_con_default(NodeProcessorContext* context, ASTNode* caso_node, SwitchState* state) {
    if (!context || !caso_node || !state) return 1;

    printf("🔍 PROCESANDO CASO_CON_DEFAULT en línea %d\n", caso_node->line);

    // Primero procesar como caso normal
    int resultado = procesar_caso(context, caso_node, state);

    // ===== PROPAGAR CÓDIGOS DE CONTROL DE FLUJO =====
    if (es_codigo_control_flujo(resultado)) {
        printf("🔄 CASO_CON_DEFAULT propagando %s: %d\n",
               obtener_nombre_control(resultado), resultado);
        return resultado;
    }

    // Si no se ejecutó ningún caso y no se ejecutó default, ejecutar default
    if (!state->caso_ejecutando && !state->default_ejecutado && !state->break_encontrado &&
        !state->return_encontrado && !state->continue_encontrado) {

        for (int i = 0; i < caso_node->child_count; i++) {
            ASTNode* hijo = caso_node->children[i];

            if (strcmp(hijo->type, "BLOQUE_DEFAULT") == 0) {
                printf("   📋 EJECUTANDO BLOQUE DEFAULT\n");

                // ===== USAR FUNCIÓN HELPER PARA DEFAULT =====
                char* default_scope_name = generate_scope_name(context, SCOPE_TYPE_CASE, hijo);
                if (default_scope_name) {
                    int resultado_default = procesar_bloque_con_scope(context, hijo, SCOPE_SWITCH,
                                                                     default_scope_name, "SWITCH_DEFAULT");

                    // ===== VERIFICAR Y PROPAGAR CONTROL DE FLUJO =====
                    if (es_codigo_control_flujo(resultado_default)) {
                        printf("🔄 BLOQUE_DEFAULT propagando %s: %d\n",
                               obtener_nombre_control(resultado_default), resultado_default);
                        free(default_scope_name);
                        return resultado_default;
                    }

                    free(default_scope_name);
                }

                state->default_ejecutado = 1;
                break;
            }
        }
    }

    return resultado;
}

// Función principal para procesar switch (ACTUALIZADA COMPLETA)
int procesar_switch(NodeProcessorContext* context, ASTNode* node) {
    if (!context || !node) {
        printf("ERROR: Parámetros inválidos para switch\n");
        return 1;
    }

    printf("🔀 PROCESANDO SWITCH en línea %d\n", node->line);

    // Crear estado del switch
    SwitchState* state = crear_switch_state();
    if (!state) {
        printf("ERROR: No se pudo crear estado del switch\n");
        return 1;
    }

    // Evaluar la expresión del switch
    if (node->child_count < 2) {
        printf("ERROR: Switch malformado - faltan componentes\n");
        liberar_switch_state(state);
        return 1;
    }

    ASTNode* expresion_switch_node = node->children[0]; // EXPRESION_SWITCH
    ASTNode* bloque_switch_node = node->children[1];    // BLOQUE_SWITCH

    // Evaluar expresión del switch
    if (expresion_switch_node && expresion_switch_node->child_count > 0) {
        ASTNode* expresion = expresion_switch_node->children[0];

        state->valor_switch = process_expresion_node(context, expresion);
        if (!state->valor_switch) {
            char error_msg[256];
            snprintf(error_msg, sizeof(error_msg),
                    "Error evaluando expresión del switch en línea %d", node->line);

            printf("❌ ERROR: %s\n", error_msg);
            liberar_switch_state(state);
            return 1;
        }

        state->tipo_switch = obtener_tipo_desde_nodo(expresion, context);

        printf("🎯 Switch evaluado: valor='%s', tipo=%s\n",
               state->valor_switch, tipo_dato_to_string(state->tipo_switch));
    }

    // ===== USAR TU SISTEMA DE SCOPE UTILS =====
    char* switch_scope_name = generate_scope_name(context, SCOPE_TYPE_SWITCH, node);
    if (!switch_scope_name) {
        printf("ERROR: No se pudo crear scope para switch\n");
        liberar_switch_state(state);
        return 1;
    }

    // Entrar al scope del switch usando tu sistema combinado
    entrar_scope_combinado(context, SCOPE_SWITCH, switch_scope_name, node->line);

    int resultado_switch = 0;

    // Procesar bloque del switch
    if (bloque_switch_node) {
        printf("🔍 Procesando BLOQUE_SWITCH con %d hijos\n", bloque_switch_node->child_count);

        for (int i = 0; i < bloque_switch_node->child_count &&
             !state->break_encontrado && !state->return_encontrado && !state->continue_encontrado; i++) {

            ASTNode* scope_switch = bloque_switch_node->children[i];
            printf("   → Procesando hijo %d: '%s'\n", i, scope_switch->type);

            if (strcmp(scope_switch->type, "SCOPE") == 0) {
                printf("   🔍 Entrando en SCOPE del switch\n");

                for (int j = 0; j < scope_switch->child_count &&
                     !state->break_encontrado && !state->return_encontrado && !state->continue_encontrado; j++) {

                    ASTNode* lista_casos = scope_switch->children[j];
                    printf("      → Procesando elemento %d: '%s'\n", j, lista_casos->type);

                    if (strcmp(lista_casos->type, "LISTA_CASOS") == 0) {
                        printf("   📋 PROCESANDO LISTA_CASOS con %d casos\n", lista_casos->child_count);

                        // ===== PRIMERA PASADA: BUSCAR CASO COINCIDENTE =====
                        for (int k = 0; k < lista_casos->child_count &&
                             !state->break_encontrado && !state->return_encontrado && !state->continue_encontrado; k++) {

                            ASTNode* caso = lista_casos->children[k];
                            printf("      🎯 Procesando caso %d: '%s'\n", k, caso->type);

                            int resultado_caso = 0;
                            if (strcmp(caso->type, "CASO") == 0) {
                                resultado_caso = procesar_caso(context, caso, state);
                            }
                            else if (strcmp(caso->type, "CASO_CON_DEFAULT") == 0) {
                                resultado_caso = procesar_caso_con_default(context, caso, state);
                            }

                            // ===== VERIFICAR CÓDIGOS DE CONTROL DE FLUJO =====
                            if (es_codigo_control_flujo(resultado_caso)) {
                                printf("🔄 SWITCH recibiendo %s de caso: %d\n",
                                       obtener_nombre_control(resultado_caso), resultado_caso);

                                if (resultado_caso == -1) { // break
                                    printf("   🛑 BREAK en switch - terminando ejecución\n");
                                    state->break_encontrado = 1;
                                    resultado_switch = 0; // break en switch no se propaga
                                } else if (resultado_caso == -2) { // continue
                                    printf("   🔄 CONTINUE en switch - propagando hacia bucle externo\n");
                                    state->continue_encontrado = 1;
                                    resultado_switch = -2; // continue se propaga a bucles externos
                                } else if (resultado_caso == -3) { // return
                                    printf("   ↩️ RETURN en switch - propagando hacia función\n");
                                    state->return_encontrado = 1;
                                    resultado_switch = -3; // return se propaga
                                }
                                break;
                            }
                        }

                        // ===== SEGUNDA PASADA: EJECUTAR DEFAULT SI NO SE EJECUTÓ NINGÚN CASO =====
                        if (!state->caso_ejecutando && !state->default_ejecutado &&
                            !state->break_encontrado && !state->return_encontrado && !state->continue_encontrado) {

                            printf("🔍 Ningún caso coincidió - buscando DEFAULT\n");

                            for (int k = 0; k < lista_casos->child_count; k++) {
                                ASTNode* caso = lista_casos->children[k];

                                if (strcmp(caso->type, "CASO_CON_DEFAULT") == 0) {
                                    printf("   📋 Encontrado CASO_CON_DEFAULT\n");

                                    // Buscar el BLOQUE_DEFAULT dentro del caso
                                    for (int l = 0; l < caso->child_count; l++) {
                                        ASTNode* hijo = caso->children[l];

                                        if (strcmp(hijo->type, "BLOQUE_DEFAULT") == 0) {
                                            printf("   ✅ EJECUTANDO BLOQUE_DEFAULT\n");

                                            // Usar tu sistema para crear scope del default
                                            char* default_scope_name = generate_scope_name(context, SCOPE_TYPE_CASE, hijo);
                                            if (default_scope_name) {
                                                // Usar tu función helper para procesar el bloque con scope
                                                int resultado_default = procesar_bloque_con_scope(context, hijo,
                                                                                                 SCOPE_SWITCH,
                                                                                                 default_scope_name,
                                                                                                 "SWITCH_DEFAULT");

                                                // ===== VERIFICAR CONTROL DE FLUJO EN DEFAULT =====
                                                if (es_codigo_control_flujo(resultado_default)) {
                                                    printf("🔄 DEFAULT propagando %s: %d\n",
                                                           obtener_nombre_control(resultado_default), resultado_default);

                                                    if (resultado_default == -1) { // break
                                                        state->break_encontrado = 1;
                                                        resultado_switch = 0; // break en switch no se propaga
                                                    } else if (resultado_default == -2) { // continue
                                                        state->continue_encontrado = 1;
                                                        resultado_switch = -2; // continue se propaga
                                                    } else if (resultado_default == -3) { // return
                                                        state->return_encontrado = 1;
                                                        resultado_switch = -3; // return se propaga
                                                    }
                                                }

                                                free(default_scope_name);
                                            }

                                            state->default_ejecutado = 1;
                                            break;
                                        }
                                    }
                                    break;
                                }
                            }
                        }
                    } else {
                        // Procesar otros elementos que no sean LISTA_CASOS
                        printf("      🎯 Procesando elemento no-lista: '%s'\n", lista_casos->type);
                        int resultado_elemento = process_ast_node(context, lista_casos);

                        if (es_codigo_control_flujo(resultado_elemento)) {
                            printf("🔄 Elemento '%s' propagando %s: %d\n",
                                   lista_casos->type, obtener_nombre_control(resultado_elemento), resultado_elemento);
                            resultado_switch = resultado_elemento;
                            break;
                        }
                    }
                }
            } else {
                // Procesar elementos que no sean SCOPE
                printf("   🎯 Procesando elemento no-scope: '%s'\n", scope_switch->type);
                int resultado_elemento = process_ast_node(context, scope_switch);

                if (es_codigo_control_flujo(resultado_elemento)) {
                    printf("🔄 Elemento '%s' propagando %s: %d\n",
                           scope_switch->type, obtener_nombre_control(resultado_elemento), resultado_elemento);
                    resultado_switch = resultado_elemento;
                    break;
                }
            }
        }
    }

    // Salir del scope del switch usando tu sistema
    salir_scope_combinado(context, node->line);
    free(switch_scope_name);

    printf("🎯 Switch completado:\n");
    printf("   → Casos ejecutados: %s\n", state->caso_ejecutando ? "SÍ" : "NO");
    printf("   → Default ejecutado: %s\n", state->default_ejecutado ? "SÍ" : "NO");
    printf("   → Break encontrado: %s\n", state->break_encontrado ? "SÍ" : "NO");
    printf("   → Continue encontrado: %s\n", state->continue_encontrado ? "SÍ" : "NO");
    printf("   → Return encontrado: %s\n", state->return_encontrado ? "SÍ" : "NO");

    // ===== PROPAGAR CÓDIGOS DE CONTROL DE FLUJO =====
    if (es_codigo_control_flujo(resultado_switch)) {
        printf("🔄 SWITCH propagando %s hacia arriba: %d\n",
               obtener_nombre_control(resultado_switch), resultado_switch);
    }

    // Liberar estado
    liberar_switch_state(state);

    return resultado_switch;
}