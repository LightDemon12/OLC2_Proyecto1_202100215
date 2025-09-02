//
// Created by lightdemon on 01/09/25.
//

#include "../../Headers/builder_funciones.h"
#include "../../Headers/builder_datos.h"
#include "../../Headers/builder_scope.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

ASTNode* build_funcion(ASTNode* tipo_retorno_node, const char* nombre_funcion, ASTNode* parametros_node, ASTNode* bloque_funcion_node, int line, int column) {
    ASTNode* funcion_node = create_node("FUNCION", line, column);

    // Crear wrapper para la signatura de la función
    ASTNode* signatura_wrapper = create_node("SIGNATURA_FUNCION", line, column);

    // Tipo de retorno
    ASTNode* retorno_wrapper = create_node("TIPO_RETORNO", line, column);
    add_child(retorno_wrapper, tipo_retorno_node);
    add_child(signatura_wrapper, retorno_wrapper);

    // Nombre de la función
    ASTNode* nombre_node = build_identifier(nombre_funcion, line, column);
    add_child(signatura_wrapper, nombre_node);

    // Parámetros
    add_child(signatura_wrapper, parametros_node);

    add_child(funcion_node, signatura_wrapper);

    // Bloque de código
    add_child(funcion_node, bloque_funcion_node);

    // Calcular número de parámetros
    int num_parametros = parametros_node ? parametros_node->child_count : 0;
    printf("DEBUG FUNCIONES: FUNCION creada - nombre:%s, tipo_retorno:%s, parametros:%d\n",
           nombre_funcion ? nombre_funcion : "null",
           tipo_retorno_node && tipo_retorno_node->value ? tipo_retorno_node->value : "unknown",
           num_parametros);

    return funcion_node;
}

ASTNode* build_parametros_single(ASTNode* parametro_node, int line, int column) {
    ASTNode* parametros_node = create_node("PARAMETROS", line, column);
    add_child(parametros_node, parametro_node);

    printf("DEBUG FUNCIONES: PARAMETROS creado con 1 parámetro\n");

    return parametros_node;
}

ASTNode* build_parametros_add(ASTNode* parametros_node, ASTNode* parametro_node) {
    if (parametros_node && parametro_node) {
        add_child(parametros_node, parametro_node);

        printf("DEBUG FUNCIONES: Parámetro agregado a PARAMETROS (total: %d parámetros)\n",
               parametros_node->child_count);
    }

    return parametros_node;
}

ASTNode* build_parametros_vacio(int line, int column) {
    ASTNode* parametros_node = create_node("PARAMETROS", line, column);

    printf("DEBUG FUNCIONES: PARAMETROS vacío creado\n");

    return parametros_node;
}

ASTNode* build_parametro_simple(ASTNode* tipo_node, const char* nombre_parametro, int line, int column) {
    ASTNode* parametro_node = create_node("PARAMETRO", line, column);

    // Crear wrapper para el tipo del parámetro
    ASTNode* tipo_wrapper = create_node("TIPO_PARAMETRO", line, column);
    add_child(tipo_wrapper, tipo_node);
    add_child(parametro_node, tipo_wrapper);

    // Nombre del parámetro
    ASTNode* nombre_node = build_identifier(nombre_parametro, line, column);
    add_child(parametro_node, nombre_node);

    printf("DEBUG FUNCIONES: PARAMETRO simple creado - tipo:%s, nombre:%s\n",
           tipo_node && tipo_node->value ? tipo_node->value : "unknown",
           nombre_parametro ? nombre_parametro : "null");

    return parametro_node;
}

ASTNode* build_parametro_array(ASTNode* tipo_node, const char* nombre_parametro, ASTNode* brackets_node, int line, int column) {
    ASTNode* parametro_node = create_node("PARAMETRO", line, column);

    // Crear wrapper para el tipo array del parámetro
    ASTNode* tipo_wrapper = create_node("TIPO_PARAMETRO_ARRAY", line, column);
    add_child(tipo_wrapper, tipo_node);
    add_child(tipo_wrapper, brackets_node);
    add_child(parametro_node, tipo_wrapper);

    // Nombre del parámetro
    ASTNode* nombre_node = build_identifier(nombre_parametro, line, column);
    add_child(parametro_node, nombre_node);

    // Calcular dimensiones
    int dimensiones = brackets_node ? brackets_node->child_count : 0;
    printf("DEBUG FUNCIONES: PARAMETRO array creado - tipo:%s, nombre:%s, dimensiones:%d\n",
           tipo_node && tipo_node->value ? tipo_node->value : "unknown",
           nombre_parametro ? nombre_parametro : "null", dimensiones);

    return parametro_node;
}

ASTNode* build_bloque_funcion(ASTNode* cuerpo_funcion_node, int line, int column) {
    ASTNode* bloque_node = create_node("BLOQUE_FUNCION", line, column);

    // Usar build_scope con el cuerpo de la función
    ASTNode* scope_node = build_scope(cuerpo_funcion_node, "FUNCION", line, column);
    add_child(bloque_node, scope_node);

    printf("DEBUG FUNCIONES: BLOQUE_FUNCION creado con scope FUNCION\n");

    return bloque_node;
}

// ========== BUILDERS PARA CUERPO DE FUNCIÓN ==========

ASTNode* build_cuerpo_funcion_single(ASTNode* elemento_node, int line, int column) {
    ASTNode* cuerpo_node = create_node("CUERPO_FUNCION", line, column);
    add_child(cuerpo_node, elemento_node);

    printf("DEBUG FUNCIONES: CUERPO_FUNCION creado con 1 elemento\n");

    return cuerpo_node;
}

ASTNode* build_cuerpo_funcion_add(ASTNode* cuerpo_node, ASTNode* elemento_node) {
    if (cuerpo_node && elemento_node) {
        add_child(cuerpo_node, elemento_node);

        printf("DEBUG FUNCIONES: Elemento agregado a CUERPO_FUNCION (total: %d elementos)\n",
               cuerpo_node->child_count);
    }

    return cuerpo_node;
}

ASTNode* build_cuerpo_funcion_vacio(int line, int column) {
    ASTNode* cuerpo_node = create_node("CUERPO_FUNCION", line, column);

    printf("DEBUG FUNCIONES: CUERPO_FUNCION vacío creado\n");

    return cuerpo_node;
}