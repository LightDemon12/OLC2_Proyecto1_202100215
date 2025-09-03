#include "../../Headers/Procesador_Constantes.h"
#include "../../Headers/Procesador_Declaraciones.h"  // Para reutilizar funciones de verificación
#include "../../Headers/node_processor.h"
#include "../../Headers/node_utils.h"
#include "../../Headers/mainview.h"
#include "../../Headers/globals.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "Procesador_casting.h"

int process_constante_node(NodeProcessorContext* context, ASTNode* node) {
    if (!context || !node) {
        procesador_error_output(context, "Contexto o nodo NULL en constante");
        return 1;
    }

    char debug_msg[256];
    snprintf(debug_msg, sizeof(debug_msg), "Procesando constante '%s' en linea %d (hijos: %d)",
            node->type, node->line, node->child_count);
    procesador_debug_output(context, debug_msg);

    if (node->child_count < 2) {
        snprintf(debug_msg, sizeof(debug_msg), "Nodo constante con pocos hijos (%d), saltando", node->child_count);
        procesador_debug_output(context, debug_msg);
        return 0;
    }

    // El primer hijo siempre es TIPO
    ASTNode* tipo_nodo = node->children[0];
    if (!tipo_nodo || !tipo_nodo->value) {
        procesador_error_output(context, "Nodo tipo invalido en constante");
        return 1;
    }

    const char* tipo_str = tipo_nodo->value;
    TipoDato tipo_dato = string_to_tipo_dato(tipo_str);
    if (tipo_dato == TIPO_DESCONOCIDO) {
        snprintf(debug_msg, sizeof(debug_msg), "Tipo de dato desconocido '%s' en constante", tipo_str);
        procesador_error_output(context, debug_msg);
        return 1;
    }

    snprintf(debug_msg, sizeof(debug_msg), "🔒 ANÁLISIS SEMÁNTICO: Tipo constante detectado '%s'", tipo_str);
    procesador_debug_output(context, debug_msg);

    // Delegar según el tipo específico de constante
    if (strcmp(node->type, "CONSTANTE_MULTIPLE") == 0) {
        return process_constante_multiple(context, tipo_dato, node->children[1], node);
    }
    else if (strcmp(node->type, "CONSTANTE_CON_INICIALIZACION") == 0) {
        return process_constante_con_inicializacion(context, tipo_dato,
                                                   node->children[1], node->children[2], node);
    }
    else {
        snprintf(debug_msg, sizeof(debug_msg), "Tipo de constante desconocido: '%s'", node->type);
        procesador_error_output(context, debug_msg);
        return 1;
    }
}

int process_constante_con_inicializacion(NodeProcessorContext* context, TipoDato tipo,
                                        ASTNode* id_nodo, ASTNode* valor_nodo, ASTNode* parent) {
    if (!id_nodo || !id_nodo->value) {
        procesador_error_output(context, "Identificador invalido en constante");
        return 1;
    }

    const char* id_str = id_nodo->value;

    char debug_msg[256];
    snprintf(debug_msg, sizeof(debug_msg),
            "🔒 ANÁLISIS SEMÁNTICO: Declarando constante '%s' tipo '%s' en scope '%s'",
            id_str, tipo_dato_to_string(tipo),
            context->scope_actual ? context->scope_actual->nombre : "GLOBAL");
    procesador_debug_output(context, debug_msg);

    // ===== VERIFICAR REDECLARACIÓN =====
    if (context->tabla_simbolos) {
        Simbolo* simbolo_existente = buscar_simbolo(context->tabla_simbolos, id_str);
        if (simbolo_existente) {
            char error_msg[512];
            snprintf(error_msg, sizeof(error_msg),
                    "Constante '%s' ya está declarada en el scope '%s' (línea %d)",
                    id_str, simbolo_existente->ambito, simbolo_existente->linea);

            const char* scope_actual = "global";
            if (context->scope_actual && context->scope_actual->nombre) {
                scope_actual = context->scope_actual->nombre;
            }

            if (global_error_manager) {
                error_manager_add_semantico(global_error_manager,
                                          parent->line, parent->column,
                                          error_msg, id_str, scope_actual);
            }

            procesador_error_output(context, error_msg);
            return 1;
        }
    }

    // ===== ANÁLISIS SEMÁNTICO DE TIPOS =====
    TipoDato tipo_valor = obtener_tipo_desde_nodo(valor_nodo, context);
    char* valor_extraido = obtener_valor_desde_nodo(valor_nodo, context);

    const char* valor_display = valor_extraido ? valor_extraido : "expresion_compleja";

    snprintf(debug_msg, sizeof(debug_msg),
            "🔍 TIPOS DETECTADOS: constante '%s'(%s) = valor '%s'(%s)",
            id_str, tipo_dato_to_string(tipo),
            valor_display, tipo_dato_to_string(tipo_valor));
    procesador_debug_output(context, debug_msg);

    // ===== VERIFICAR COMPATIBILIDAD (IGUAL QUE VARIABLES) =====
    int es_compatible = 0;
    char* valor_final = valor_extraido;

    if (tipo == tipo_valor) {
        es_compatible = 1;
        snprintf(debug_msg, sizeof(debug_msg), "✅ TIPOS IDÉNTICOS - Asignación directa");
        procesador_debug_output(context, debug_msg);
    }
    else if (tipo_valor == TIPO_INT && (tipo == TIPO_BYTE || tipo == TIPO_SHORT)) {
        // Narrowing implícito para constantes (sin verificación de rango)
        es_compatible = 1;
        snprintf(debug_msg, sizeof(debug_msg),
                "🔽 NARROWING IMPLÍCITO: int → %s (literal permitido)",
                tipo_dato_to_string(tipo));
        procesador_debug_output(context, debug_msg);
    }
    else if (es_promocion_automatica(tipo_valor, tipo)) {
        // Promoción automática para constantes
        es_compatible = 1;

        snprintf(debug_msg, sizeof(debug_msg),
                "🔄 PROMOCIÓN AUTOMÁTICA: %s → %s",
                tipo_dato_to_string(tipo_valor), tipo_dato_to_string(tipo));
        procesador_debug_output(context, debug_msg);

        if (valor_extraido) {
            char* valor_promovido = convertir_valor_cast(valor_extraido, tipo_valor, tipo);
            if (valor_promovido) {
                free(valor_extraido);
                valor_final = valor_promovido;

                snprintf(debug_msg, sizeof(debug_msg),
                        "📈 VALOR PROMOVIDO: '%s' → '%s'",
                        valor_display, valor_final);
                procesador_debug_output(context, debug_msg);
            }
        }
    }
    else if (tipos_compatibles_asignacion(tipo, tipo_valor)) {
        es_compatible = 1;
        snprintf(debug_msg, sizeof(debug_msg), "✅ TIPOS COMPATIBLES - Asignación válida");
        procesador_debug_output(context, debug_msg);
    }

    if (!es_compatible) {
        char error_msg[512];
        snprintf(error_msg, sizeof(error_msg),
                "Asignación incompatible: no se puede asignar %s a constante %s de tipo %s",
                tipo_dato_to_string(tipo_valor), id_str, tipo_dato_to_string(tipo));

        const char* scope_actual = "global";
        if (context->scope_actual && context->scope_actual->nombre) {
            scope_actual = context->scope_actual->nombre;
        }

        if (global_error_manager) {
            error_manager_add_semantico(global_error_manager,
                                      parent->line, parent->column,
                                      error_msg, "=", scope_actual);
        }

        procesador_error_output(context, error_msg);
        if (valor_final) free(valor_final);
        return 1;
    }

    // ===== CREAR Y GUARDAR CONSTANTE =====
    Simbolo simbolo = crear_simbolo_default(id_str, SIMBOLO_CONSTANTE, tipo);
    simbolo.linea = parent->line;
    simbolo.columna = parent->column;
    simbolo.visibilidad = VIS_PUBLIC;
    simbolo.inicializado = 1;
    simbolo.timestamp_creacion = time(NULL);

    // Guardar el valor
    if (valor_final) {
        strncpy(simbolo.valor, valor_final, MAX_VALUE_LENGTH - 1);
        simbolo.valor[MAX_VALUE_LENGTH - 1] = '\0';
        free(valor_final);
    } else {
        strncpy(simbolo.valor, "expresion_compleja", MAX_VALUE_LENGTH - 1);
    }

    // Insertar símbolo
    if (!insertar_simbolo_en_scope_combinado(context, simbolo)) {
        procesador_error_output(context, "Error interno: No se pudo insertar constante");
        return 1;
    }

    snprintf(debug_msg, sizeof(debug_msg),
            "✅ Constante '%s' = '%s' declarada exitosamente",
            simbolo.id, simbolo.valor);
    procesador_debug_output(context, debug_msg);

    return 0;
}

int process_constante_multiple(NodeProcessorContext* context, TipoDato tipo,
                              ASTNode* lista_nodo, ASTNode* parent) {
    if (!lista_nodo || lista_nodo->child_count == 0) {
        procesador_error_output(context, "Lista de constantes invalida");
        return 1;
    }

    char debug_msg[256];
    snprintf(debug_msg, sizeof(debug_msg),
            "🔒 ANÁLISIS SEMÁNTICO: Constante múltiple - tipo:'%s', elementos:%d",
            tipo_dato_to_string(tipo), lista_nodo->child_count);
    procesador_debug_output(context, debug_msg);

    // Procesar cada elemento de la lista
    for (int i = 0; i < lista_nodo->child_count; i++) {
        ASTNode* elemento = lista_nodo->children[i];
        if (!elemento) continue;

        if (elemento->child_count >= 2) {
            if (process_constante_con_inicializacion(context, tipo,
                                                    elemento->children[0],
                                                    elemento->children[1], parent) != 0) {
                return 1;
            }
        } else {
            snprintf(debug_msg, sizeof(debug_msg),
                    "Elemento de constante inválido en lista (hijos: %d)", elemento->child_count);
            procesador_error_output(context, debug_msg);
            return 1;
        }
    }

    procesador_debug_output(context, "✅ Constante múltiple procesada exitosamente");
    return 0;
}