//
// Created by lightdemon on 01/09/25.
//

#include "../../Headers/builder_llamadas_funciones.h"
#include "../../Headers/builder_datos.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

ASTNode* build_llamada_funcion(const char* nombre_funcion, ASTNode* argumentos_node, int line, int column) {
    ASTNode* llamada_node = create_node("LLAMADA_FUNCION", line, column);

    // Crear nodo identificador para el nombre de la función
    ASTNode* nombre_node = build_identifier(nombre_funcion, line, column);
    add_child(llamada_node, nombre_node);

    // Agregar argumentos
    add_child(llamada_node, argumentos_node);

    // Calcular número de argumentos
    int num_argumentos = argumentos_node ? argumentos_node->child_count : 0;
    printf("DEBUG LLAMADAS_FUNCIONES: LLAMADA_FUNCION creada - nombre:%s, argumentos:%d\n",
           nombre_funcion ? nombre_funcion : "null", num_argumentos);

    return llamada_node;
}

ASTNode* build_argumentos_single(ASTNode* argumento_node, int line, int column) {
    ASTNode* argumentos_node = create_node("ARGUMENTOS", line, column);
    add_child(argumentos_node, argumento_node);

    printf("DEBUG LLAMADAS_FUNCIONES: ARGUMENTOS creado con 1 argumento\n");

    return argumentos_node;
}

ASTNode* build_argumentos_add(ASTNode* argumentos_node, ASTNode* argumento_node) {
    if (argumentos_node && argumento_node) {
        add_child(argumentos_node, argumento_node);

        printf("DEBUG LLAMADAS_FUNCIONES: Argumento agregado a ARGUMENTOS (total: %d argumentos)\n",
               argumentos_node->child_count);
    }

    return argumentos_node;
}

ASTNode* build_argumentos_vacio(int line, int column) {
    ASTNode* argumentos_node = create_node("ARGUMENTOS", line, column);

    printf("DEBUG LLAMADAS_FUNCIONES: ARGUMENTOS vacío creado\n");

    return argumentos_node;
}