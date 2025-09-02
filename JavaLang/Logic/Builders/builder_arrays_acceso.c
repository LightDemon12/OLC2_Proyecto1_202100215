//
// Created by lightdemon on 01/09/25.
//

#include "../../Headers/builder_arrays_acceso.h"
#include "../../Headers/builder_datos.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

ASTNode* build_array_acceso_1d(const char* nombre_array, ASTNode* indice_node, int line, int column) {
    ASTNode* acceso_node = create_node("ARRAY_ACCESO_1D", line, column);

    // Crear nodo identificador para el array
    ASTNode* array_node = build_identifier(nombre_array, line, column);
    add_child(acceso_node, array_node);

    // Crear wrapper para el índice
    ASTNode* indice_wrapper = create_node("INDICE_ARRAY", line, column);
    add_child(indice_wrapper, indice_node);
    add_child(acceso_node, indice_wrapper);

    printf("DEBUG ARRAYS_ACCESO: ARRAY_ACCESO_1D creado - array:%s\n",
           nombre_array ? nombre_array : "null");

    return acceso_node;
}

ASTNode* build_array_acceso_multidimensional(const char* nombre_array, ASTNode* brackets_indices_node, int line, int column) {
    ASTNode* acceso_node = create_node("ARRAY_ACCESO_MULTIDIMENSIONAL", line, column);

    // Crear nodo identificador para el array
    ASTNode* array_node = build_identifier(nombre_array, line, column);
    add_child(acceso_node, array_node);

    // Agregar los índices multidimensionales
    add_child(acceso_node, brackets_indices_node);

    // Calcular dimensiones basado en el número de índices
    int dimensiones = brackets_indices_node ? brackets_indices_node->child_count : 0;
    printf("DEBUG ARRAYS_ACCESO: ARRAY_ACCESO_MULTIDIMENSIONAL creado - array:%s, dimensiones:%d\n",
           nombre_array ? nombre_array : "null", dimensiones);

    return acceso_node;
}

ASTNode* build_array_asignacion_1d(ASTNode* tipo_node, const char* nombre_variable, const char* nombre_array, ASTNode* indice_node, int line, int column) {
    ASTNode* asignacion_node = create_node("ARRAY_ASIGNACION_1D", line, column);

    // Crear wrapper para la declaración de la variable
    ASTNode* declaracion_wrapper = create_node("DECLARACION_VARIABLE", line, column);
    add_child(declaracion_wrapper, tipo_node);

    ASTNode* variable_node = build_identifier(nombre_variable, line, column);
    add_child(declaracion_wrapper, variable_node);
    add_child(asignacion_node, declaracion_wrapper);

    // Crear wrapper para el acceso al array
    ASTNode* acceso_wrapper = create_node("ACCESO_ARRAY_1D", line, column);
    ASTNode* array_node = build_identifier(nombre_array, line, column);
    add_child(acceso_wrapper, array_node);

    ASTNode* indice_wrapper = create_node("INDICE_ARRAY", line, column);
    add_child(indice_wrapper, indice_node);
    add_child(acceso_wrapper, indice_wrapper);
    add_child(asignacion_node, acceso_wrapper);

    printf("DEBUG ARRAYS_ACCESO: ARRAY_ASIGNACION_1D creado - variable:%s, array:%s\n",
           nombre_variable ? nombre_variable : "null",
           nombre_array ? nombre_array : "null");

    return asignacion_node;
}

ASTNode* build_array_asignacion_multidimensional(ASTNode* tipo_node, const char* nombre_variable, const char* nombre_array, ASTNode* brackets_indices_node, int line, int column) {
    ASTNode* asignacion_node = create_node("ARRAY_ASIGNACION_MULTIDIMENSIONAL", line, column);

    // Crear wrapper para la declaración de la variable
    ASTNode* declaracion_wrapper = create_node("DECLARACION_VARIABLE", line, column);
    add_child(declaracion_wrapper, tipo_node);

    ASTNode* variable_node = build_identifier(nombre_variable, line, column);
    add_child(declaracion_wrapper, variable_node);
    add_child(asignacion_node, declaracion_wrapper);

    // Crear wrapper para el acceso multidimensional
    ASTNode* acceso_wrapper = create_node("ACCESO_ARRAY_MULTIDIMENSIONAL", line, column);
    ASTNode* array_node = build_identifier(nombre_array, line, column);
    add_child(acceso_wrapper, array_node);
    add_child(acceso_wrapper, brackets_indices_node);
    add_child(asignacion_node, acceso_wrapper);

    // Calcular dimensiones
    int dimensiones = brackets_indices_node ? brackets_indices_node->child_count : 0;
    printf("DEBUG ARRAYS_ACCESO: ARRAY_ASIGNACION_MULTIDIMENSIONAL creado - variable:%s, array:%s, dimensiones:%d\n",
           nombre_variable ? nombre_variable : "null",
           nombre_array ? nombre_array : "null", dimensiones);

    return asignacion_node;
}

ASTNode* build_array_asignacion_elemento(const char* nombre_array, ASTNode* brackets_indices_node, ASTNode* expresion_node, int line, int column) {
    ASTNode* asignacion_node = create_node("ARRAY_ASIGNACION_ELEMENTO", line, column);

    // Crear nodo identificador para el array
    ASTNode* array_node = build_identifier(nombre_array, line, column);
    add_child(asignacion_node, array_node);

    // Agregar los índices
    add_child(asignacion_node, brackets_indices_node);

    // Agregar la expresión a asignar
    ASTNode* valor_wrapper = create_node("VALOR_ASIGNACION", line, column);
    add_child(valor_wrapper, expresion_node);
    add_child(asignacion_node, valor_wrapper);

    // Calcular dimensiones
    int dimensiones = brackets_indices_node ? brackets_indices_node->child_count : 0;
    printf("DEBUG ARRAYS_ACCESO: ARRAY_ASIGNACION_ELEMENTO creado - array:%s, dimensiones:%d\n",
           nombre_array ? nombre_array : "null", dimensiones);

    return asignacion_node;
}

ASTNode* build_brackets_indices_single(ASTNode* expresion_node, int line, int column) {
    ASTNode* brackets_indices_node = create_node("BRACKETS_INDICES", line, column);

    // Crear wrapper para el índice
    ASTNode* indice_wrapper = create_node("INDICE", line, column);
    add_child(indice_wrapper, expresion_node);
    add_child(brackets_indices_node, indice_wrapper);

    printf("DEBUG ARRAYS_ACCESO: BRACKETS_INDICES creado con 1 índice\n");

    return brackets_indices_node;
}

ASTNode* build_brackets_indices_add(ASTNode* brackets_indices_node, ASTNode* expresion_node) {
    if (brackets_indices_node && expresion_node) {
        // Crear wrapper para el nuevo índice
        ASTNode* indice_wrapper = create_node("INDICE", brackets_indices_node->line, brackets_indices_node->column);
        add_child(indice_wrapper, expresion_node);
        add_child(brackets_indices_node, indice_wrapper);

        printf("DEBUG ARRAYS_ACCESO: Índice agregado a BRACKETS_INDICES (total: %d índices)\n",
               brackets_indices_node->child_count);
    }

    return brackets_indices_node;
}