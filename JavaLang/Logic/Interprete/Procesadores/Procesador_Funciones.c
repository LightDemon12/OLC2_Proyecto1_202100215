#include "Procesador_Funciones.h"
#include "node_utils.h"
#include "Procesador_Return.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "error_manager.h"

// ===== DECLARACIONES EXTERN DEL NODE_PROCESSOR =====
extern int procesar_instrucciones_con_control(NodeProcessorContext* context, ASTNode* instrucciones_node, const char* contexto);
extern int es_codigo_control_flujo(int codigo);
extern void entrar_scope_combinado(NodeProcessorContext* context, ScopeType tipo, const char* nombre, int linea);
extern void salir_scope_combinado(NodeProcessorContext* context, int linea);
extern int insertar_simbolo_en_scope_combinado(NodeProcessorContext* context, Simbolo simbolo);
extern Simbolo* buscar_simbolo(TablaSimbolos* tabla, const char* id);

extern ErrorManager* global_error_manager;

Simbolo crear_simbolo_parametro(const char* nombre, TipoDato tipo, int posicion, const char* ambito_funcion) {
    Simbolo param = crear_simbolo_default(nombre, SIMBOLO_PARAMETRO, tipo);
    param.es_parametro = 1;
    param.posicion_parametro = posicion;
    strncpy(param.ambito, ambito_funcion, MAX_SCOPE_LENGTH - 1);
    param.ambito[MAX_SCOPE_LENGTH - 1] = '\0';
    return param;
}

int procesar_declaracion_funcion(NodeProcessorContext* context, ASTNode* node) {
    if (!context || !node || node->child_count < 2) {
        printf("ERROR: Declaración de función malformada\n");
        return 0;
    }

    printf("🔧 PROCESANDO DECLARACIÓN DE FUNCIÓN en línea %d\n", node->line);

    ASTNode* signatura_node = node->children[0];
    ASTNode* bloque_node = node->children[1];

    if (!signatura_node || signatura_node->child_count < 2) {
        printf("ERROR: Signatura de función malformada\n");
        return 0;
    }

    ASTNode* tipo_retorno_node = signatura_node->children[0];
    ASTNode* nombre_node = signatura_node->children[1];
    ASTNode* parametros_node = signatura_node->child_count > 2 ? signatura_node->children[2] : NULL;

    if (!tipo_retorno_node || !nombre_node || !nombre_node->value) {
        printf("ERROR: Función sin tipo de retorno o nombre\n");
        return 0;
    }

    TipoDato tipo_retorno = TIPO_VOID;
    if (tipo_retorno_node->child_count > 0) {
        ASTNode* tipo_node = tipo_retorno_node->children[0];
        if (tipo_node && tipo_node->value) {
            tipo_retorno = string_to_tipo_dato(tipo_node->value);
        }
    }

    // Generar nombre del scope de la función
    char* scope_name = generate_scope_name(context, SCOPE_TYPE_FUNCTION, node);
    if (!scope_name) {
        printf("ERROR: No se pudo generar el nombre del scope para la función\n");
        return 0;
    }

    printf("🏗️ CREANDO SCOPE PARA FUNCIÓN: %s\n", scope_name);
    entrar_scope_combinado(context, SCOPE_FUNCION, scope_name, node->line);

    Simbolo simbolo_funcion = crear_simbolo_default(nombre_node->value, SIMBOLO_FUNCION, tipo_retorno);
    strncpy(simbolo_funcion.ambito, "global", MAX_SCOPE_LENGTH - 1);
    simbolo_funcion.linea = node->line;

    insertar_simbolo_en_scope_combinado(context, simbolo_funcion);

    int num_parametros = 0;
    if (parametros_node && parametros_node->child_count > 0) {
        printf("🔍 PROCESANDO %d PARÁMETROS\n", parametros_node->child_count);

        for (int i = 0; i < parametros_node->child_count; i++) {
            ASTNode* param_node = parametros_node->children[i];
            if (param_node && param_node->child_count >= 2) {
                ASTNode* tipo_param_node = param_node->children[0];
                ASTNode* nombre_param_node = param_node->children[1];

                if (tipo_param_node && nombre_param_node && nombre_param_node->value) {
                    TipoDato tipo_param = TIPO_DESCONOCIDO;
                    if (tipo_param_node->child_count > 0) {
                        ASTNode* tipo_node = tipo_param_node->children[0];
                        if (tipo_node && tipo_node->value) {
                            tipo_param = string_to_tipo_dato(tipo_node->value);
                        }
                    }

                    Simbolo param = crear_simbolo_parametro(nombre_param_node->value, tipo_param,
                                                          num_parametros, scope_name);
                    param.linea = param_node->line;

                    if (insertar_simbolo_en_scope_combinado(context, param)) {
                        num_parametros++;
                        printf("   ✅ Parámetro %d: %s %s\n", num_parametros,
                               tipo_dato_to_string(tipo_param), nombre_param_node->value);
                    }
                }
            }
        }
    }

    printf("🔍 PROCESANDO CUERPO DE LA FUNCIÓN\n");
    if (bloque_node && bloque_node->child_count > 0) {
        ASTNode* scope_node = bloque_node->children[0];
        if (scope_node && scope_node->child_count > 0) {
            ASTNode* cuerpo_node = scope_node->children[0];

            // Buscar INSTRUCCIONES dentro del CUERPO_FUNCION
            for (int i = 0; i < cuerpo_node->child_count; i++) {
                ASTNode* hijo = cuerpo_node->children[i];
                if (hijo && strcmp(hijo->type, "INSTRUCCIONES") == 0) {
                    int resultado = procesar_instrucciones_con_control(context, hijo, "FUNCION");

                    if (tipo_retorno != TIPO_VOID && resultado != -3) {
                        printf("⚠️ ADVERTENCIA: Función '%s' debería retornar valor\n", nombre_node->value);
                    }
                    break;
                }
            }
        }
    }

    printf("🚪 SALIENDO DEL SCOPE DE FUNCIÓN: %s\n", scope_name);
    salir_scope_combinado(context, node->line);

    printf("✅ FUNCIÓN '%s' DECLARADA EXITOSAMENTE\n", nombre_node->value);
    free(scope_name);
    return 1;
}

int procesar_cuerpo_funcion(NodeProcessorContext* context, ASTNode* cuerpo_node, FuncionInfo* info) {
    if (!cuerpo_node || !info) return 1;

    printf("🔧 PROCESANDO CUERPO DE FUNCIÓN '%s'\n", info->nombre);

    for (int i = 0; i < cuerpo_node->child_count; i++) {
        ASTNode* instruccion = cuerpo_node->children[i];
        int resultado = process_ast_node(context, instruccion);

        if (es_codigo_control_flujo(resultado)) {
            return resultado;
        }
    }

    return 0;
}

int process_llamada_funcion_node(NodeProcessorContext* context, ASTNode* node) {
    if (!context || !node || node->child_count < 1) {
        procesador_error_output(context, "Llamada a función malformada");
        return 1;
    }

    printf("📞 PROCESANDO LLAMADA A FUNCIÓN en línea %d\n", node->line);

    // Obtener el nombre de la función
    ASTNode* nombre_node = node->children[0];
    if (!nombre_node || !nombre_node->value) {
        procesador_error_output(context, "Función sin nombre");
        return 1;
    }

    const char* nombre_funcion = nombre_node->value;

    // Buscar la función en la tabla de símbolos
    Simbolo* simbolo_funcion = buscar_simbolo(context->tabla_simbolos, nombre_funcion);
    if (!simbolo_funcion || simbolo_funcion->tipo_simbolo != SIMBOLO_FUNCION) {
        char error_msg[256];
        snprintf(error_msg, sizeof(error_msg), "Función '%s' no encontrada", nombre_funcion);
        procesador_error_output(context, error_msg);
        return 1;
    }

    FuncionInfo* info = simbolo_funcion->funcion_info;
    if (!info) {
        procesador_error_output(context, "Información de función no disponible");
        return 1;
    }

    // Crear un nuevo scope para la función
    char scope_name[64];
    snprintf(scope_name, sizeof(scope_name), "llamada_%s_%d", nombre_funcion, node->line);
    entrar_scope_combinado(context, SCOPE_FUNCION, scope_name, node->line);

    // Asignar argumentos a los parámetros de la función
    ASTNode* argumentos_node = node->child_count > 1 ? node->children[1] : NULL;
    int num_argumentos = argumentos_node ? argumentos_node->child_count : 0;

    if (num_argumentos != info->num_parametros) {
        char error_msg[256];
        snprintf(error_msg, sizeof(error_msg), "Número de argumentos incorrecto para la función '%s'", nombre_funcion);
        procesador_error_output(context, error_msg);
        salir_scope_combinado(context, node->line);
        return 1;
    }

    for (int i = 0; i < num_argumentos; i++) {
        ASTNode* argumento = argumentos_node->children[i];
        char* valor_argumento = obtener_valor_desde_nodo(argumento, context);

        Simbolo parametro = info->parametros[i];
        parametro.inicializado = 1;

        if (!insertar_simbolo_en_scope_combinado(context, parametro)) {
            char error_msg[256];
            snprintf(error_msg, sizeof(error_msg), "Error al asignar argumento al parámetro '%s'", parametro.id);
            procesador_error_output(context, error_msg);
            salir_scope_combinado(context, node->line);
            return 1;
        }

        if (valor_argumento) free(valor_argumento);
    }

    // Ejecutar el cuerpo de la función
    int resultado = procesar_cuerpo_funcion(context, info->cuerpo, info);

    // Salir del scope de la función
    salir_scope_combinado(context, node->line);

    return resultado;
}
