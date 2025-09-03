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

// Estructura para manejar el estado del switch
typedef struct {
    char* valor_switch;          // Valor de la expresión del switch
    TipoDato tipo_switch;        // Tipo de la expresión
    int caso_ejecutando;         // Flag si estamos ejecutando un caso
    int break_encontrado;        // Flag si se encontró break
    int default_ejecutado;       // Flag si se ejecutó default
    int fall_through;           // Flag para fall-through (sin break)
} SwitchState;

// Función para crear estado del switch
SwitchState* crear_switch_state() {
    SwitchState* state = malloc(sizeof(SwitchState));
    if (!state) return NULL;

    state->valor_switch = NULL;
    state->tipo_switch = TIPO_DESCONOCIDO; // ✅ CORREGIDO
    state->caso_ejecutando = 0;
    state->break_encontrado = 0;
    state->default_ejecutado = 0;
    state->fall_through = 0;

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

// Función para procesar un caso individual
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

        // ===== CREAR SCOPE ESPECÍFICO PARA CADA CASE =====
        char* case_scope_name = enter_generated_scope(context, SCOPE_TYPE_CASE, caso_node);
        if (!case_scope_name) {
            printf("❌ ERROR: No se pudo crear scope para case\n");
            return 1;
        }

        // Procesar INSTRUCCIONES_CASO y SENTENCIA_CASO
        for (int i = 1; i < caso_node->child_count; i++) {
            ASTNode* hijo = caso_node->children[i];

            if (strcmp(hijo->type, "INSTRUCCIONES_CASO") == 0) {
                // Procesar instrucciones del caso
                printf("   📝 Procesando instrucciones del caso\n");
                for (int j = 0; j < hijo->child_count; j++) {
                    process_ast_node(context, hijo->children[j]);
                }
            }
            else if (strcmp(hijo->type, "SENTENCIA_CASO") == 0) {
                // Procesar sentencia de control (break, continue, etc.)
                printf("   🎮 Procesando sentencia de control\n");
                for (int j = 0; j < hijo->child_count; j++) {
                    ASTNode* sentencia = hijo->children[j];

                    if (strcmp(sentencia->type, "BREAK") == 0) {
                        printf("   🛑 BREAK encontrado - terminando switch\n");
                        state->break_encontrado = 1;

                        // Salir del scope del case
                        salir_scope_combinado(context, caso_node->line);
                        free(case_scope_name);
                        return 0; // Salir del switch
                    } else {
                        process_ast_node(context, sentencia);
                    }
                }
            }
            else if (strcmp(hijo->type, "BLOQUE_DEFAULT") == 0) {
                // Procesar bloque default si estamos en fall-through
                if (state->caso_ejecutando) {
                    printf("   📋 EJECUTANDO DEFAULT por fall-through\n");

                    // Crear scope para default
                    char* default_scope_name = generate_scope_name(context, SCOPE_TYPE_CASE, hijo);
                    if (default_scope_name) {
                        entrar_scope_combinado(context, SCOPE_SWITCH, default_scope_name, hijo->line);

                        for (int j = 0; j < hijo->child_count; j++) {
                            process_ast_node(context, hijo->children[j]);
                        }

                        salir_scope_combinado(context, hijo->line);
                        free(default_scope_name);
                    }

                    state->default_ejecutado = 1;
                }
            }
        }

        // Salir del scope del case
        salir_scope_combinado(context, caso_node->line);
        free(case_scope_name);

        // Si no se encontró break, marcar fall-through
        if (!state->break_encontrado) {
            printf("   ⬇️ No hay break - activando fall-through\n");
            state->fall_through = 1;
        }
    }

    return 0;
}

// Función para procesar caso con default
int procesar_caso_con_default(NodeProcessorContext* context, ASTNode* caso_node, SwitchState* state) {
    if (!context || !caso_node || !state) return 1;

    printf("🔍 PROCESANDO CASO_CON_DEFAULT en línea %d\n", caso_node->line);

    // Primero procesar como caso normal
    int resultado = procesar_caso(context, caso_node, state);

    // Si no se ejecutó ningún caso y no se ejecutó default, ejecutar default
    if (!state->caso_ejecutando && !state->default_ejecutado && !state->break_encontrado) {
        for (int i = 0; i < caso_node->child_count; i++) {
            ASTNode* hijo = caso_node->children[i];

            if (strcmp(hijo->type, "BLOQUE_DEFAULT") == 0) {
                printf("   📋 EJECUTANDO BLOQUE DEFAULT\n");

                // Crear scope específico para default
                char* default_scope_name = generate_scope_name(context, SCOPE_TYPE_CASE, hijo);
                if (default_scope_name) {
                    entrar_scope_combinado(context, SCOPE_SWITCH, default_scope_name, hijo->line);

                    for (int j = 0; j < hijo->child_count; j++) {
                        process_ast_node(context, hijo->children[j]);
                    }

                    salir_scope_combinado(context, hijo->line);
                    free(default_scope_name);
                }

                state->default_ejecutado = 1;
                break;
            }
        }
    }

    return resultado;
}

// Función principal para procesar switch
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

            if (global_error_manager) {
                error_manager_add_semantico(global_error_manager,
                                          node->line, node->column,
                                          error_msg, "switch",
                                          context->scope_actual ? context->scope_actual->nombre : "global");
            }

            printf("❌ ERROR: %s\n", error_msg);
            liberar_switch_state(state);
            return 1;
        }

        state->tipo_switch = obtener_tipo_desde_nodo(expresion, context);

        printf("🎯 Switch evaluado: valor='%s', tipo=%s\n",
               state->valor_switch, tipo_dato_to_string(state->tipo_switch));
    }

    // ===== USAR SCOPE UTILS PARA CREAR SCOPE DEL SWITCH =====
    char* switch_scope_name = enter_generated_scope(context, SCOPE_TYPE_SWITCH, node);
    if (!switch_scope_name) {
        printf("ERROR: No se pudo crear scope para switch\n");
        liberar_switch_state(state);
        return 1;
    }

    // Procesar bloque del switch
    if (bloque_switch_node) {
        for (int i = 0; i < bloque_switch_node->child_count; i++) {
            ASTNode* scope_switch = bloque_switch_node->children[i];

            if (strcmp(scope_switch->type, "SCOPE") == 0) {
                for (int j = 0; j < scope_switch->child_count; j++) {
                    ASTNode* lista_casos = scope_switch->children[j];

                    if (strcmp(lista_casos->type, "LISTA_CASOS") == 0) {
                        // Procesar cada caso
                        for (int k = 0; k < lista_casos->child_count && !state->break_encontrado; k++) {
                            ASTNode* caso = lista_casos->children[k];

                            if (strcmp(caso->type, "CASO") == 0) {
                                procesar_caso(context, caso, state);
                            }
                            else if (strcmp(caso->type, "CASO_CON_DEFAULT") == 0) {
                                procesar_caso_con_default(context, caso, state);
                            }
                        }

                        // Si no se ejecutó ningún caso, buscar y ejecutar default
                        if (!state->caso_ejecutando && !state->default_ejecutado) {
                            printf("🔍 Ningún caso coincidió - buscando default\n");
                            for (int k = 0; k < lista_casos->child_count; k++) {
                                ASTNode* caso = lista_casos->children[k];
                                if (strcmp(caso->type, "CASO_CON_DEFAULT") == 0) {
                                    // Forzar ejecución del default
                                    for (int l = 0; l < caso->child_count; l++) {
                                        ASTNode* hijo = caso->children[l];
                                        if (strcmp(hijo->type, "BLOQUE_DEFAULT") == 0) {
                                            printf("   📋 EJECUTANDO DEFAULT\n");

                                            char* default_scope_name = generate_scope_name(context, SCOPE_TYPE_CASE, hijo);
                                            if (default_scope_name) {
                                                entrar_scope_combinado(context, SCOPE_SWITCH, default_scope_name, hijo->line);

                                                for (int m = 0; m < hijo->child_count; m++) {
                                                    process_ast_node(context, hijo->children[m]);
                                                }

                                                salir_scope_combinado(context, hijo->line);
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
                    }
                }
            }
        }
    }

    // Salir del scope del switch usando scope utils
    salir_scope_combinado(context, node->line);
    free(switch_scope_name);

    printf("🎯 Switch completado - casos ejecutados: %s, default: %s\n",
           state->caso_ejecutando ? "SÍ" : "NO",
           state->default_ejecutado ? "SÍ" : "NO");


    // Liberar estado
    liberar_switch_state(state);

    return 0;
}