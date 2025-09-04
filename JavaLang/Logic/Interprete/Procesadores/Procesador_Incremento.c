#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../../Headers/ast.h"
#include "../../../Headers/node_processor.h"
#include "../../../Headers/Tabla_Simbolos.h"
#include "../../../Headers/error_manager.h"
#include "../../../Headers/node_utils.h"

extern ErrorManager* global_error_manager;

// Función para validar que la variable sea incrementable/decrementable
int validar_variable_incrementable(NodeProcessorContext* context, const char* variable_name, int linea) {
    if (!context || !variable_name || !context->tabla_simbolos) {
        return 0;
    }

    Simbolo* simbolo = buscar_simbolo(context->tabla_simbolos, variable_name);
    if (!simbolo) {
        char error_msg[256];
        snprintf(error_msg, sizeof(error_msg),
                "Variable '%s' no ha sido declarada", variable_name);

        if (global_error_manager) {
            error_manager_add_semantico(global_error_manager,
                                      linea, 1, error_msg, variable_name,
                                      context->scope_actual ? context->scope_actual->nombre : "global");
        }

        printf("❌ ERROR: %s\n", error_msg);
        return 0;
    }

    // Verificar que sea un tipo numérico
    if (simbolo->tipo_dato != TIPO_INT &&
        simbolo->tipo_dato != TIPO_FLOAT &&
        simbolo->tipo_dato != TIPO_DOUBLE &&
        simbolo->tipo_dato != TIPO_CHAR) {

        char error_msg[256];
        snprintf(error_msg, sizeof(error_msg),
                "No se puede aplicar operador de incremento/decremento a variable '%s' de tipo %s",
                variable_name, tipo_dato_to_string(simbolo->tipo_dato));

        if (global_error_manager) {
            error_manager_add_semantico(global_error_manager,
                                      linea, 1, error_msg, variable_name,
                                      context->scope_actual ? context->scope_actual->nombre : "global");
        }

        printf("❌ ERROR: %s\n", error_msg);
        return 0;
    }

    return 1;
}

// Función para incrementar/decrementar una variable
int modificar_variable(NodeProcessorContext* context, const char* variable_name,
                      int es_incremento, int linea) {
    if (!context || !variable_name || !context->tabla_simbolos) {
        return 0;
    }

    Simbolo* simbolo = buscar_simbolo(context->tabla_simbolos, variable_name);
    if (!simbolo) return 0;

    // Obtener valor actual
    double valor_actual = convertir_a_numero(simbolo->valor, simbolo->tipo_dato);

    // Aplicar incremento/decremento
    double nuevo_valor = es_incremento ? (valor_actual + 1) : (valor_actual - 1);

    // Convertir de vuelta al tipo original
    char nuevo_valor_str[64];
    switch (simbolo->tipo_dato) {
        case TIPO_INT:
        case TIPO_CHAR:
            snprintf(nuevo_valor_str, sizeof(nuevo_valor_str), "%d", (int)nuevo_valor);
            break;
        case TIPO_FLOAT:
            snprintf(nuevo_valor_str, sizeof(nuevo_valor_str), "%.2f", (float)nuevo_valor);
            break;
        case TIPO_DOUBLE:
            snprintf(nuevo_valor_str, sizeof(nuevo_valor_str), "%.6f", nuevo_valor);
            break;
        default:
            return 0;
    }

    // Usar función correcta: actualizar_valor_simbolo
    if (actualizar_valor_simbolo(context->tabla_simbolos, variable_name, nuevo_valor_str)) {
        printf("🔄 Variable '%s': %s → %s\n", variable_name, simbolo->valor, nuevo_valor_str);
        return 1;
    }

    return 0;
}

// Procesador de PRE-INCREMENTO (++variable)
char* process_pre_incremento_node(NodeProcessorContext* context, ASTNode* node) {
    if (!context || !node) {
        printf("ERROR: Parámetros inválidos para pre-incremento\n");
        return NULL;
    }

    printf("➕ PROCESANDO PRE-INCREMENTO (++var) en línea %d\n", node->line);

    // Verificar que hay una variable
    if (node->child_count == 0 || !node->children[0]) {
        printf("❌ ERROR: Pre-incremento sin variable\n");
        return NULL;
    }

    ASTNode* variable_node = node->children[0];
    if (strcmp(variable_node->type, "IDENTIFIER") != 0 || !variable_node->value) {
        printf("❌ ERROR: Pre-incremento debe aplicarse a una variable\n");
        return NULL;
    }

    const char* variable_name = variable_node->value;

    // Validar que la variable sea incrementable
    if (!validar_variable_incrementable(context, variable_name, node->line)) {
        return NULL;
    }

    // Incrementar la variable
    if (!modificar_variable(context, variable_name, 1, node->line)) {
        printf("❌ ERROR: No se pudo incrementar la variable '%s'\n", variable_name);
        return NULL;
    }

    // Obtener el NUEVO valor (después del incremento)
    Simbolo* simbolo = buscar_simbolo(context->tabla_simbolos, variable_name);
    if (!simbolo) return NULL;

    char* resultado = malloc(strlen(simbolo->valor) + 1);
    strcpy(resultado, simbolo->valor);

    printf("✅ PRE-INCREMENTO: ++%s = %s\n", variable_name, resultado);

    // Incrementar uso
    incrementar_uso_simbolo(context->tabla_simbolos, variable_name);

    return resultado;
}

// Procesador de PRE-DECREMENTO (--variable)
char* process_pre_decremento_node(NodeProcessorContext* context, ASTNode* node) {
    if (!context || !node) {
        printf("ERROR: Parámetros inválidos para pre-decremento\n");
        return NULL;
    }

    printf("➖ PROCESANDO PRE-DECREMENTO (--var) en línea %d\n", node->line);

    // Verificar que hay una variable
    if (node->child_count == 0 || !node->children[0]) {
        printf("❌ ERROR: Pre-decremento sin variable\n");
        return NULL;
    }

    ASTNode* variable_node = node->children[0];
    if (strcmp(variable_node->type, "IDENTIFIER") != 0 || !variable_node->value) {
        printf("❌ ERROR: Pre-decremento debe aplicarse a una variable\n");
        return NULL;
    }

    const char* variable_name = variable_node->value;

    // Validar que la variable sea decrementable
    if (!validar_variable_incrementable(context, variable_name, node->line)) {
        return NULL;
    }

    // Decrementar la variable
    if (!modificar_variable(context, variable_name, 0, node->line)) {
        printf("❌ ERROR: No se pudo decrementar la variable '%s'\n", variable_name);
        return NULL;
    }

    // Obtener el NUEVO valor (después del decremento)
    Simbolo* simbolo = buscar_simbolo(context->tabla_simbolos, variable_name);
    if (!simbolo) return NULL;

    char* resultado = malloc(strlen(simbolo->valor) + 1);
    strcpy(resultado, simbolo->valor);

    printf("✅ PRE-DECREMENTO: --%s = %s\n", variable_name, resultado);

    // Incrementar uso
    incrementar_uso_simbolo(context->tabla_simbolos, variable_name);

    return resultado;
}

// Procesador de POST-INCREMENTO (variable++)
char* process_post_incremento_node(NodeProcessorContext* context, ASTNode* node) {
    if (!context || !node) {
        printf("ERROR: Parámetros inválidos para post-incremento\n");
        return NULL;
    }

    printf("➕ PROCESANDO POST-INCREMENTO (var++) en línea %d\n", node->line);

    // Verificar que hay una variable
    if (node->child_count == 0 || !node->children[0]) {
        printf("❌ ERROR: Post-incremento sin variable\n");
        return NULL;
    }

    ASTNode* variable_node = node->children[0];
    if (strcmp(variable_node->type, "IDENTIFIER") != 0 || !variable_node->value) {
        printf("❌ ERROR: Post-incremento debe aplicarse a una variable\n");
        return NULL;
    }

    const char* variable_name = variable_node->value;

    // Validar que la variable sea incrementable
    if (!validar_variable_incrementable(context, variable_name, node->line)) {
        return NULL;
    }

    // Obtener el valor ACTUAL (antes del incremento)
    Simbolo* simbolo = buscar_simbolo(context->tabla_simbolos, variable_name);
    if (!simbolo) return NULL;

    char* valor_anterior = malloc(strlen(simbolo->valor) + 1);
    strcpy(valor_anterior, simbolo->valor);

    // Incrementar la variable
    if (!modificar_variable(context, variable_name, 1, node->line)) {
        printf("❌ ERROR: No se pudo incrementar la variable '%s'\n", variable_name);
        free(valor_anterior);
        return NULL;
    }

    // Obtener el nuevo valor para mostrar
    Simbolo* simbolo_actualizado = buscar_simbolo(context->tabla_simbolos, variable_name);

    printf("✅ POST-INCREMENTO: %s++ = %s (ahora %s vale %s)\n",
           variable_name, valor_anterior, variable_name,
           simbolo_actualizado ? simbolo_actualizado->valor : "?");

    // Incrementar uso
    incrementar_uso_simbolo(context->tabla_simbolos, variable_name);

    // Retornar el valor ANTERIOR
    return valor_anterior;
}

// Procesador de POST-DECREMENTO (variable--)
char* process_post_decremento_node(NodeProcessorContext* context, ASTNode* node) {
    if (!context || !node) {
        printf("ERROR: Parámetros inválidos para post-decremento\n");
        return NULL;
    }

    printf("➖ PROCESANDO POST-DECREMENTO (var--) en línea %d\n", node->line);

    // Verificar que hay una variable
    if (node->child_count == 0 || !node->children[0]) {
        printf("❌ ERROR: Post-decremento sin variable\n");
        return NULL;
    }

    ASTNode* variable_node = node->children[0];
    if (strcmp(variable_node->type, "IDENTIFIER") != 0 || !variable_node->value) {
        printf("❌ ERROR: Post-decremento debe aplicarse a una variable\n");
        return NULL;
    }

    const char* variable_name = variable_node->value;

    // Validar que la variable sea decrementable
    if (!validar_variable_incrementable(context, variable_name, node->line)) {
        return NULL;
    }

    // Obtener el valor ACTUAL (antes del decremento)
    Simbolo* simbolo = buscar_simbolo(context->tabla_simbolos, variable_name);
    if (!simbolo) return NULL;

    char* valor_anterior = malloc(strlen(simbolo->valor) + 1);
    strcpy(valor_anterior, simbolo->valor);

    // Decrementar la variable
    if (!modificar_variable(context, variable_name, 0, node->line)) {
        printf("❌ ERROR: No se pudo decrementar la variable '%s'\n", variable_name);
        free(valor_anterior);
        return NULL;
    }

    // Obtener el nuevo valor para mostrar
    Simbolo* simbolo_actualizado = buscar_simbolo(context->tabla_simbolos, variable_name);

    printf("✅ POST-DECREMENTO: %s-- = %s (ahora %s vale %s)\n",
           variable_name, valor_anterior, variable_name,
           simbolo_actualizado ? simbolo_actualizado->valor : "?");

    // Incrementar uso
    incrementar_uso_simbolo(context->tabla_simbolos, variable_name);

    // Retornar el valor ANTERIOR
    return valor_anterior;
}