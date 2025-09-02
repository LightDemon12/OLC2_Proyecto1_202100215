//
// Created by lightdemon on 1/09/25.
//

#include "../../Headers/builder_matrices.h"
#include "../../Headers/builder_datos.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

ASTNode* build_matriz_new(ASTNode* tipo_matriz_node, const char* nombre_matriz, ASTNode* tipo_new_node, ASTNode* filas_node, ASTNode* columnas_node, int line, int column) {
    ASTNode* matriz_node = create_node("MATRIZ_NEW", line, column);

    // Crear wrapper para el tipo de la matriz
    ASTNode* tipo_wrapper = create_node("TIPO_MATRIZ", line, column);
    add_child(tipo_wrapper, tipo_matriz_node);
    add_child(matriz_node, tipo_wrapper);

    // Crear nodo identificador para el nombre de la matriz
    ASTNode* nombre_node = build_identifier(nombre_matriz, line, column);
    add_child(matriz_node, nombre_node);

    // Crear wrapper para la declaración NEW con dimensiones
    ASTNode* new_wrapper = create_node("NEW_DECLARATION_MATRIZ", line, column);
    add_child(new_wrapper, tipo_new_node);

    // Crear nodo para las dimensiones de la matriz
    ASTNode* dimensiones_wrapper = create_node("DIMENSIONES_MATRIZ", line, column);

    // Crear nodo específico para filas
    ASTNode* filas_wrapper = create_node("DIMENSION_FILAS", line, column);
    add_child(filas_wrapper, filas_node);
    add_child(dimensiones_wrapper, filas_wrapper);

    // Crear nodo específico para columnas
    ASTNode* columnas_wrapper = create_node("DIMENSION_COLUMNAS", line, column);
    add_child(columnas_wrapper, columnas_node);
    add_child(dimensiones_wrapper, columnas_wrapper);

    add_child(new_wrapper, dimensiones_wrapper);
    add_child(matriz_node, new_wrapper);

    printf("DEBUG MATRICES: MATRIZ_NEW creado - nombre:%s con DIMENSIONES_MATRIZ\n",
           nombre_matriz ? nombre_matriz : "null");

    return matriz_node;
}

ASTNode* build_matriz_inicializada(ASTNode* tipo_matriz_node, const char* nombre_matriz, ASTNode* contenido_node, int line, int column) {
    ASTNode* matriz_node = create_node("MATRIZ_INICIALIZADA", line, column);

    // Crear wrapper para el tipo de la matriz
    ASTNode* tipo_wrapper = create_node("TIPO_MATRIZ", line, column);
    add_child(tipo_wrapper, tipo_matriz_node);
    add_child(matriz_node, tipo_wrapper);

    // Crear nodo identificador para el nombre de la matriz
    ASTNode* nombre_node = build_identifier(nombre_matriz, line, column);
    add_child(matriz_node, nombre_node);

    // Agregar el contenido de la matriz
    add_child(matriz_node, contenido_node);

    printf("DEBUG MATRICES: MATRIZ_INICIALIZADA creado - nombre:%s\n",
           nombre_matriz ? nombre_matriz : "null");

    return matriz_node;
}

ASTNode* build_contenido_matriz_single(ASTNode* fila_node, int line, int column) {
    ASTNode* contenido_node = create_node("CONTENIDO_MATRIZ", line, column);
    add_child(contenido_node, fila_node);

    printf("DEBUG MATRICES: CONTENIDO_MATRIZ creado con 1 fila\n");

    return contenido_node;
}

ASTNode* build_contenido_matriz_add(ASTNode* contenido_node, ASTNode* fila_node) {
    if (contenido_node && fila_node) {
        add_child(contenido_node, fila_node);

        printf("DEBUG MATRICES: Fila agregada a CONTENIDO_MATRIZ (total: %d filas)\n",
               contenido_node->child_count);
    }

    return contenido_node;
}

ASTNode* build_fila_matriz(ASTNode* lista_expresiones_node, int line, int column) {
    ASTNode* fila_node = create_node("FILA_MATRIZ", line, column);
    add_child(fila_node, lista_expresiones_node);

    printf("DEBUG MATRICES: FILA_MATRIZ creada\n");

    return fila_node;
}

ASTNode* build_lista_expresiones_single(ASTNode* expresion_node, int line, int column) {
    ASTNode* lista_node = create_node("LISTA_EXPRESIONES", line, column);
    add_child(lista_node, expresion_node);

    printf("DEBUG MATRICES: LISTA_EXPRESIONES creada con 1 elemento\n");

    return lista_node;
}

ASTNode* build_lista_expresiones_add(ASTNode* lista_node, ASTNode* expresion_node) {
    if (lista_node && expresion_node) {
        add_child(lista_node, expresion_node);

        printf("DEBUG MATRICES: Elemento agregado a LISTA_EXPRESIONES (total: %d elementos)\n",
               lista_node->child_count);
    }

    return lista_node;
}