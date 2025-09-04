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
#include "../../Headers/Procesador_While.h"
#include "../../Headers/Procesador_Do_While.h"
#include "../../Headers/Procesador_For.h"
#include "../../Headers/Procesador_Vectores.h"
#include "../../Headers/Procesador_Vectores.h"

#include <stdlib.h>
#include <string.h>

#include "Procesador_Sout.h"

//   IMPLEMENTACIÓN COMPLETA DEL SISTEMA COMBINADO DE SCOPES

int es_codigo_control_flujo(int codigo) {
    return (codigo == -1 || codigo == -2 || codigo == -3); // break, continue, return
}

// Obtener nombre del código de control
const char* obtener_nombre_control(int codigo) {
    switch (codigo) {
        case -1: return "BREAK";
        case -2: return "CONTINUE";
        case -3: return "RETURN";
        default: return "UNKNOWN";
    }
}

// Procesar lista de instrucciones con control de flujo
int procesar_instrucciones_con_control(NodeProcessorContext* context, ASTNode* instrucciones_node, const char* contexto) {
    if (!instrucciones_node || strcmp(instrucciones_node->type, "INSTRUCCIONES") != 0) {
        return 0;
    }

    printf("🔍 PROCESANDO INSTRUCCIONES en contexto '%s' - %d instrucciones\n",
           contexto, instrucciones_node->child_count);

    for (int i = 0; i < instrucciones_node->child_count; i++) {
        ASTNode* instruccion = instrucciones_node->children[i];
        if (!instruccion) continue;

        printf("   → Ejecutando instrucción %d/%d: '%s'\n",
               i+1, instrucciones_node->child_count, instruccion->type);

        int resultado = process_ast_node(context, instruccion);

        // ===== VERIFICAR CÓDIGOS DE CONTROL DE FLUJO =====
        if (es_codigo_control_flujo(resultado)) {
            printf("🔄 %s detectado en INSTRUCCIONES (%s) - propagando hacia arriba\n",
                   obtener_nombre_control(resultado), contexto);
            printf("   → Saltando instrucciones restantes (%d-%d de %d)\n",
                   i+2, instrucciones_node->child_count, instrucciones_node->child_count);
            return resultado;
        }

        // Si hay error normal, continuar procesando pero marcarlo
        if (resultado != 0) {
            printf("⚠️ WARNING: Instrucción '%s' retornó código %d\n",
                   instruccion->type, resultado);
        }
    }

    return 0; // Todas las instrucciones procesadas sin control de flujo
}

// Procesar bloque con scope (genérico para IF, FOR, WHILE, etc.)
int procesar_bloque_con_scope(NodeProcessorContext* context, ASTNode* bloque_node,
                              ScopeType tipo_scope, const char* nombre_scope,
                              const char* contexto) {
    if (!bloque_node) return 0;

    printf("🔍 ENTRANDO BLOQUE %s: %s\n", contexto, nombre_scope);
    entrar_scope_combinado(context, tipo_scope, nombre_scope, bloque_node->line);

    int resultado = 0;

    // Buscar INSTRUCCIONES dentro del bloque
    if (strcmp(bloque_node->type, "SCOPE") == 0) {
        // Es un SCOPE con INSTRUCCIONES dentro
        for (int i = 0; i < bloque_node->child_count; i++) {
            ASTNode* hijo = bloque_node->children[i];
            if (hijo && strcmp(hijo->type, "INSTRUCCIONES") == 0) {
                resultado = procesar_instrucciones_con_control(context, hijo, contexto);
                if (es_codigo_control_flujo(resultado)) {
                    break;
                }
            } else {
                int resultado_hijo = process_ast_node(context, hijo);
                if (es_codigo_control_flujo(resultado_hijo)) {
                    resultado = resultado_hijo;
                    break;
                }
            }
        }
    } else if (strcmp(bloque_node->type, "INSTRUCCIONES") == 0) {
        // Es directamente INSTRUCCIONES
        resultado = procesar_instrucciones_con_control(context, bloque_node, contexto);
    } else {
        // Procesar directamente
        resultado = process_ast_node(context, bloque_node);
    }

    printf("🔍 SALIENDO BLOQUE %s: %s\n", contexto, nombre_scope);
    salir_scope_combinado(context, bloque_node->line);

    // Propagar control de flujo
    if (es_codigo_control_flujo(resultado)) {
        printf("🔄 BLOQUE %s propagando %s: %d\n",
               contexto, obtener_nombre_control(resultado), resultado);
    }

    return resultado;
}

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

int insertar_simbolo_en_scope_combinado(NodeProcessorContext* context, Simbolo simbolo) {
    if (!context) return 0;

    // CORRECCIÓN CRÍTICA: Determinar el scope correcto para la inserción
    const char* scope_destino = "global";  // Por defecto global

    // Si hay scope actual, usarlo, pero con correcciones
    if (context->scope_actual && context->scope_actual->nombre) {
        scope_destino = context->scope_actual->nombre;

        // CORRECCIÓN: Si estamos en el contexto "global" pero el scope dice otra cosa,
        // forzar que las declaraciones del main vayan al scope global real
        if (strcmp(scope_destino, "GLOBAL") == 0 ||
            (context->scope_actual->nivel == -1)) {
            scope_destino = "global";
            }
    }

    // ASEGURAR que el símbolo tenga el scope correcto en su estructura
    strncpy(simbolo.ambito, scope_destino, MAX_SCOPE_LENGTH - 1);
    simbolo.ambito[MAX_SCOPE_LENGTH - 1] = '\0';

    // VERIFICAR DUPLICADOS EN ÁMBITO CORRECTO
    if (existe_simbolo_en_ambito_actual(context->tabla_simbolos, simbolo.id)) {
        char error_msg[256];
        snprintf(error_msg, sizeof(error_msg),
                "Variable '%s' ya existe en scope '%s'",
                simbolo.id, scope_destino);
        procesador_error_output(context, error_msg);
        return 0;
    }

    // INSERTAR con el scope ya corregido
    int resultado = insertar_simbolo(context->tabla_simbolos, simbolo);

    if (resultado && context->modo_debug) {
        char debug_msg[256];
        snprintf(debug_msg, sizeof(debug_msg),
                "Variable '%s' declarada en scope '%s' (nivel %d)",
                simbolo.id, scope_destino,
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
    if (strcmp(node_type, "INICIALIZACION_FOR_DECLARACION") == 0) return NODE_TYPE_DECLARACION_CON_INICIALIZACION;
    // VECTORES Y ARRAYS
    if (strcmp(node_type, "VECTOR_NEW") == 0) return NODE_TYPE_VECTOR_NEW;
    if (strcmp(node_type, "VECTOR_INICIALIZADO") == 0) return NODE_TYPE_VECTOR_INICIALIZADO;
    if (strcmp(node_type, "ARRAY_MULTIDIMENSIONAL_NEW") == 0) return NODE_TYPE_ARRAY_MULTIDIMENSIONAL_NEW;
    if (strcmp(node_type, "ARRAY_MULTIDIMENSIONAL_INICIALIZADO") == 0) return NODE_TYPE_ARRAY_MULTIDIMENSIONAL_INICIALIZADO;
    if (strcmp(node_type, "ARRAY_ACCESO_MULTIDIMENSIONAL") == 0) return NODE_TYPE_ARRAY_ACCESO_MULTIDIMENSIONAL;
    if (strcmp(node_type, "ARRAY_ASIGNACION_1D") == 0) return NODE_TYPE_ARRAY_ASIGNACION_1D;
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
    if (strcmp(node_type, "FOR_EACH") == 0) return NODE_TYPE_FOR;
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
    if (strcmp(node_type, "ARRAY_ASIGNACION_1D") == 0) return NODE_TYPE_ARRAY_ASIGNACION_1D;
    if (strcmp(node_type, "ASIGNACION_COMPUESTA_ARRAY_1D") == 0) return NODE_TYPE_ASIGNACION_COMPUESTA_ARRAY_1D;
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
            printf("🔄 PROCESANDO WHILE: '%s'\n", node->type);
            // ===== USAR EL PROCESADOR DE WHILE ESPECIALIZADO =====
            char* resultado_while = process_while_node(context, node);
            if (resultado_while && context->modo_debug) {
                printf("   → Resultado WHILE: '%s' iteraciones\n", resultado_while);
                free(resultado_while);
            }
            return 0;
        case NODE_TYPE_DO_WHILE:
            printf("🔄 PROCESANDO DO_WHILE: '%s'\n", node->type);
            // ===== USAR EL PROCESADOR DE DO_WHILE ESPECIALIZADO =====
            char* resultado_do_while = process_do_while_node(context, node);
            if (resultado_do_while && context->modo_debug) {
                printf("   → Resultado DO_WHILE: '%s' iteraciones\n", resultado_do_while);
                free(resultado_do_while);
            }
            return 0;
        case NODE_TYPE_BREAK:
            printf("🛑 PROCESANDO BREAK: '%s'\n", node->type);
            return procesar_break(context, node);
        case NODE_TYPE_CONTINUE:
            printf("🔄 PROCESANDO CONTINUE: '%s'\n", node->type);
            // ===== RETORNAR EL CÓDIGO DE CONTINUE DIRECTAMENTE =====
            return procesar_continue(context, node);
        case NODE_TYPE_RETURN_CON_VALOR:
        case NODE_TYPE_RETURN_VACIO:
            printf("↩️ PROCESANDO RETURN: '%s'\n", node->type);
            return procesar_return(context, node);
        case NODE_TYPE_FOR:
            printf("🔁 PROCESANDO FOR: '%s'\n", node->type);
            char* resultado_for = process_for_node(context, node);
            if (resultado_for && context->modo_debug) {
                printf("   → Resultado FOR: '%s' iteraciones\n", resultado_for);
                free(resultado_for);
            }
            return 0;
        case NODE_TYPE_ASIGNACION_COMPUESTA_ARRAY_1D:
            printf("📝 PROCESANDO ASIGNACIÓN COMPUESTA ARRAY: '%s'\n", node->type);
            return procesar_asignacion_compuesta_array(context, node);
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
        case NODE_TYPE_VECTOR_NEW:
        case NODE_TYPE_VECTOR_INICIALIZADO:
            printf("🧮 PROCESANDO VECTOR/ARRAY: '%s'\n", node->type);
            return process_vector_node(context, node);
        case NODE_TYPE_ARRAY_ACCESO_MULTIDIMENSIONAL:
            printf("🔍 PROCESANDO ACCESO A VECTOR: '%s'\n", node->type);
            return procesar_acceso_vector(context, node);
        case NODE_TYPE_ARRAY_ASIGNACION_1D:
            printf("📝 PROCESANDO ARRAY_ASIGNACION_1D: '%s' en scope '%s'\n",
                   node->type,
                   context->scope_actual ? context->scope_actual->nombre : "GLOBAL");
            return process_declaracion_node(context, node);
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

            // ===== VERIFICAR SI ES INSTRUCCIONES =====
            if (strcmp(node->type, "INSTRUCCIONES") == 0) {
                return procesar_instrucciones_con_control(context, node, "ESTRUCTURAL");
            }

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

            // Procesar hijos para nodos estructurales (PROGRAM, SCOPE, etc.)
            for (int i = 0; i < node->child_count; i++) {
                printf("   → Procesando hijo %d/%d de '%s': '%s'\n",
                       i+1, node->child_count, node->type,
                       node->children[i] ? node->children[i]->type : "NULL");

                int resultado = process_ast_node(context, node->children[i]);

                // ===== PROPAGAR CONTROL DE FLUJO =====
                if (es_codigo_control_flujo(resultado)) {
                    printf("🔄 Nodo estructural '%s' propagando %s: %d\n",
                           node->type, obtener_nombre_control(resultado), resultado);
                    return resultado;
                }
            }
            return 0;

            // ===== VERIFICAR SI ES INSTRUCCIONES DENTRO DE ESTRUCTURAS DE CONTROL =====
            if (strcmp(node->type, "INSTRUCCIONES") == 0) {
                printf("🔍 PROCESANDO INSTRUCCIONES - verificando control de flujo\n");

                // Procesar cada instrucción y verificar códigos de control
                for (int i = 0; i < node->child_count; i++) {
                    printf("   → Procesando instrucción %d/%d de '%s': '%s'\n",
                           i+1, node->child_count, node->type,
                           node->children[i] ? node->children[i]->type : "NULL");

                    int resultado = process_ast_node(context, node->children[i]);

                    // ===== VERIFICAR CÓDIGOS DE CONTROL DE FLUJO =====
                    if (resultado == -1) { // break
                        printf("🛑 BREAK detectado en INSTRUCCIONES - propagando hacia arriba\n");
                        return -1;
                    }
                    if (resultado == -2) { // continue
                        printf("🔄 CONTINUE detectado en INSTRUCCIONES - propagando hacia arriba\n");
                        printf("   → Saltando instrucciones restantes (%d-%d de %d)\n",
                               i+1, node->child_count, node->child_count);
                        return -2;
                    }

                    // Si hay error normal, continuar procesando pero marcarlo
                    if (resultado != 0) {
                        printf("⚠️ WARNING: Instrucción '%s' retornó código %d\n",
                               node->children[i] ? node->children[i]->type : "NULL", resultado);
                    }
                }
                return 0; // Todas las instrucciones procesadas sin control de flujo
            }

            // Procesar hijos para nodos estructurales (PROGRAM, SCOPE, etc.)
            for (int i = 0; i < node->child_count; i++) {
                printf("   → Procesando hijo %d/%d de '%s': '%s'\n",
                       i+1, node->child_count, node->type,
                       node->children[i] ? node->children[i]->type : "NULL");

                int resultado = process_ast_node(context, node->children[i]);

                // ===== PARA NODOS ESTRUCTURALES, PROPAGAR CONTROL DE FLUJO =====
                if (resultado == -1 || resultado == -2) {
                    printf("🔄 Nodo estructural '%s' propagando código de control: %d\n",
                           node->type, resultado);
                    return resultado;
                }
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

void limpiar_variables_locales_scope_actual(NodeProcessorContext* context) {
    if (!context || !context->tabla_simbolos) return;

    printf("🧹 NODE_PROCESSOR: Limpiando variables locales del scope actual\n");
    limpiar_variables_locales_ambito_actual(context->tabla_simbolos);
}