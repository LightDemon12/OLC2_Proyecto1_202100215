#include "Procesador_Funciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "FuncionManager.h"
#include "scope_utils.h"

int procesar_declaracion_funcion(NodeProcessorContext* context, ASTNode* node) {
    if (!context || !node || node->child_count < 2) {
        printf("ERROR: Declaración de función malformada\n");
        return 0;
    }

    ASTNode* signatura_node = node->children[0];
    ASTNode* bloque_node = node->children[1];

    if (!signatura_node || signatura_node->child_count < 2) {
        printf("ERROR: Signatura de función malformada\n");
        return 0;
    }

    ASTNode* tipo_retorno_node = signatura_node->children[0];
    ASTNode* nombre_node = signatura_node->children[1];

    if (!tipo_retorno_node || !nombre_node || !nombre_node->value) {
        printf("ERROR: Función sin tipo de retorno o nombre\n");
        return 0;
    }

    const char* nombre_funcion = nombre_node->value;

    // Determinar el tipo de retorno
    TipoDato tipo_retorno = TIPO_VOID;
    if (tipo_retorno_node->child_count > 0) {
        ASTNode* tipo_node = tipo_retorno_node->children[0];
        if (tipo_node && tipo_node->value) {
            tipo_retorno = string_to_tipo_dato(tipo_node->value);
        }
    }

    // Crear el símbolo de la función
    Simbolo simbolo_funcion = crear_simbolo_default(nombre_funcion, SIMBOLO_FUNCION, tipo_retorno);
    strncpy(simbolo_funcion.ambito, "global", MAX_SCOPE_LENGTH - 1); // Registrar en el scope global
    simbolo_funcion.ambito[MAX_SCOPE_LENGTH - 1] = '\0';
    simbolo_funcion.linea = node->line;

    // Insertar la función en la tabla de símbolos (en el scope global)
    if (!insertar_simbolo_en_scope_combinado(context, simbolo_funcion)) {
        printf("ERROR: No se pudo insertar la función '%s' en la tabla de símbolos\n", nombre_funcion);
        return 0;
    }

    // Registrar el cuerpo de la función en el manejador de funciones
    if (!registrar_funcion(nombre_funcion, bloque_node)) {
        printf("ERROR: No se pudo registrar el cuerpo de la función '%s'\n", nombre_funcion);
        return 0;
    }

    printf("✅ Función '%s' declarada exitosamente\n", nombre_funcion);
    return 1;
}
// Procesa una llamada a una función
char* procesar_llamada_funcion(NodeProcessorContext* context, ASTNode* node) {
    if (!context || !node || node->child_count < 1) {
        printf("ERROR: Llamada a función malformada\n");
        return NULL;
    }

    ASTNode* nombre_node = node->children[0];
    if (!nombre_node || !nombre_node->value) {
        printf("ERROR: Llamada a función sin nombre\n");
        return NULL;
    }

    const char* nombre_funcion = nombre_node->value;

    // Buscar el símbolo de la función en la tabla de símbolos
    Simbolo* simbolo_funcion = buscar_simbolo(context->tabla_simbolos, nombre_funcion);
    if (!simbolo_funcion || simbolo_funcion->tipo_simbolo != SIMBOLO_FUNCION) {
        printf("ERROR: Función '%s' no encontrada\n", nombre_funcion);
        return NULL;
    }

    // Entrar al scope de la función
    entrar_ambito(context->tabla_simbolos, simbolo_funcion->ambito);

    // Obtener el cuerpo de la función
    ASTNode* cuerpo_funcion = obtener_cuerpo_funcion(nombre_funcion);
    if (!cuerpo_funcion) {
        printf("ERROR: No se encontró el cuerpo de la función '%s'\n", nombre_funcion);
        salir_ambito(context->tabla_simbolos);
        return NULL;
    }

    // Ejecutar el cuerpo de la función
    printf("📞 Ejecutando cuerpo de la función '%s'\n", nombre_funcion);
    for (int i = 0; i < cuerpo_funcion->child_count; i++) {
        ASTNode* instruccion = cuerpo_funcion->children[i];
        process_ast_node(context, instruccion);
    }

    // Salir del scope de la función
    salir_ambito(context->tabla_simbolos);

    // Simular un resultado
    char* resultado = (char*)malloc(64);
    snprintf(resultado, 64, "Resultado de '%s'", nombre_funcion);
    return resultado;
}