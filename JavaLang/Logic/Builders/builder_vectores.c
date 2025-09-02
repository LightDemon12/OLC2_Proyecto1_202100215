//
// Created by lightdemon on 1/09/25.
//
//
// Created by lightdemon on 01/09/25.
//

#include "../../Headers/builder_vectores.h"
#include "../../Headers/builder_datos.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

ASTNode* build_vector_new(ASTNode* tipo_array_node, const char* nombre_array, ASTNode* tipo_new_node, ASTNode* tamano_node, int line, int column) {
    ASTNode* vector_node = create_node("VECTOR_NEW", line, column);

    // Crear wrapper para el tipo del array
    ASTNode* tipo_wrapper = create_node("TIPO_ARRAY", line, column);
    add_child(tipo_wrapper, tipo_array_node);
    add_child(vector_node, tipo_wrapper);

    // Crear nodo identificador para el nombre del array
    ASTNode* nombre_node = build_identifier(nombre_array, line, column);
    add_child(vector_node, nombre_node);

    // Crear wrapper para la declaración NEW con nodo DIMENSION_VECTOR
    ASTNode* new_wrapper = create_node("NEW_DECLARATION", line, column);
    add_child(new_wrapper, tipo_new_node);

    // Crear nodo específico para la dimensión del vector
    ASTNode* dimension_wrapper = create_node("DIMENSION_VECTOR", line, column);
    add_child(dimension_wrapper, tamano_node);
    add_child(new_wrapper, dimension_wrapper);

    add_child(vector_node, new_wrapper);

    printf("DEBUG VECTORES: VECTOR_NEW creado - nombre:%s con DIMENSION_VECTOR\n",
           nombre_array ? nombre_array : "null");

    return vector_node;
}

ASTNode* build_vector_inicializado(ASTNode* tipo_array_node, const char* nombre_array, ASTNode* contenido_node, int line, int column) {
    ASTNode* vector_node = create_node("VECTOR_INICIALIZADO", line, column);

    // Crear wrapper para el tipo del array
    ASTNode* tipo_wrapper = create_node("TIPO_ARRAY", line, column);
    add_child(tipo_wrapper, tipo_array_node);
    add_child(vector_node, tipo_wrapper);

    // Crear nodo identificador para el nombre del array
    ASTNode* nombre_node = build_identifier(nombre_array, line, column);
    add_child(vector_node, nombre_node);

    // Agregar el contenido del vector
    add_child(vector_node, contenido_node);

    printf("DEBUG VECTORES: VECTOR_INICIALIZADO creado - nombre:%s\n",
           nombre_array ? nombre_array : "null");

    return vector_node;
}

ASTNode* build_contenido_vector_single(ASTNode* expresion_node, int line, int column) {
    ASTNode* contenido_node = create_node("CONTENIDO_VECTOR", line, column);
    add_child(contenido_node, expresion_node);

    printf("DEBUG VECTORES: CONTENIDO_VECTOR creado con 1 elemento\n");

    return contenido_node;
}

ASTNode* build_contenido_vector_add(ASTNode* contenido_node, ASTNode* expresion_node) {
    if (contenido_node && expresion_node) {
        add_child(contenido_node, expresion_node);

        printf("DEBUG VECTORES: Elemento agregado a CONTENIDO_VECTOR (total: %d elementos)\n",
               contenido_node->child_count);
    }

    return contenido_node;
}