//
// Created by lightdemon on 01/09/25.
//

#include "../../Headers/builder_arrays_multidimensional.h"
#include "../../Headers/builder_datos.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

ASTNode* build_array_multidimensional_new(ASTNode* tipo_node, ASTNode* brackets_node, const char* nombre_array, ASTNode* tipo_new_node, ASTNode* brackets_new_node, int line, int column) {
    ASTNode* array_node = create_node("ARRAY_MULTIDIMENSIONAL_NEW", line, column);

    // Crear wrapper para el tipo multidimensional
    ASTNode* tipo_wrapper = create_node("TIPO_MULTIDIMENSIONAL", line, column);
    add_child(tipo_wrapper, tipo_node);
    add_child(tipo_wrapper, brackets_node);
    add_child(array_node, tipo_wrapper);

    // Crear nodo identificador para el nombre del array
    ASTNode* nombre_node = build_identifier(nombre_array, line, column);
    add_child(array_node, nombre_node);

    // Crear wrapper para la declaración NEW multidimensional
    ASTNode* new_wrapper = create_node("NEW_DECLARATION_MULTIDIMENSIONAL", line, column);
    add_child(new_wrapper, tipo_new_node);
    add_child(new_wrapper, brackets_new_node);
    add_child(array_node, new_wrapper);

    // Calcular dimensiones
    int dimensiones = brackets_node ? brackets_node->child_count : 0;
    printf("DEBUG ARRAYS_MULTIDIMENSIONAL: ARRAY_MULTIDIMENSIONAL_NEW creado - nombre:%s, dimensiones:%d\n",
           nombre_array ? nombre_array : "null", dimensiones);

    return array_node;
}

ASTNode* build_array_multidimensional_inicializado(ASTNode* tipo_node, ASTNode* brackets_node, const char* nombre_array, ASTNode* brace_block_node, int line, int column) {
    ASTNode* array_node = create_node("ARRAY_MULTIDIMENSIONAL_INICIALIZADO", line, column);

    // Crear wrapper para el tipo multidimensional
    ASTNode* tipo_wrapper = create_node("TIPO_MULTIDIMENSIONAL", line, column);
    add_child(tipo_wrapper, tipo_node);
    add_child(tipo_wrapper, brackets_node);
    add_child(array_node, tipo_wrapper);

    // Crear nodo identificador para el nombre del array
    ASTNode* nombre_node = build_identifier(nombre_array, line, column);
    add_child(array_node, nombre_node);

    // Agregar el contenido del array
    add_child(array_node, brace_block_node);

    // Calcular dimensiones
    int dimensiones = brackets_node ? brackets_node->child_count : 0;
    printf("DEBUG ARRAYS_MULTIDIMENSIONAL: ARRAY_MULTIDIMENSIONAL_INICIALIZADO creado - nombre:%s, dimensiones:%d\n",
           nombre_array ? nombre_array : "null", dimensiones);

    return array_node;
}

ASTNode* build_brackets_single(int line, int column) {
    ASTNode* brackets_node = create_node("BRACKETS", line, column);

    // Crear nodo para representar un par de corchetes
    ASTNode* bracket_pair = create_node("BRACKET_PAIR", line, column);
    add_child(brackets_node, bracket_pair);

    printf("DEBUG ARRAYS_MULTIDIMENSIONAL: BRACKETS creado con 1 dimensión\n");

    return brackets_node;
}

ASTNode* build_brackets_add(ASTNode* brackets_node, int line, int column) {
    if (brackets_node) {
        // Crear nodo para representar un par de corchetes adicional
        ASTNode* bracket_pair = create_node("BRACKET_PAIR", line, column);
        add_child(brackets_node, bracket_pair);

        printf("DEBUG ARRAYS_MULTIDIMENSIONAL: Dimensión agregada a BRACKETS (total: %d dimensiones)\n",
               brackets_node->child_count);
    }

    return brackets_node;
}

ASTNode* build_brackets_new_single(ASTNode* expresion_node, int line, int column) {
    ASTNode* brackets_new_node = create_node("BRACKETS_NEW", line, column);

    // Crear wrapper para la primera dimensión
    ASTNode* dimension_wrapper = create_node("DIMENSION", line, column);
    add_child(dimension_wrapper, expresion_node);
    add_child(brackets_new_node, dimension_wrapper);

    printf("DEBUG ARRAYS_MULTIDIMENSIONAL: BRACKETS_NEW creado con 1 dimensión\n");

    return brackets_new_node;
}

ASTNode* build_brackets_new_add(ASTNode* brackets_new_node, ASTNode* expresion_node) {
    if (brackets_new_node && expresion_node) {
        // Crear wrapper para la nueva dimensión
        ASTNode* dimension_wrapper = create_node("DIMENSION", brackets_new_node->line, brackets_new_node->column);
        add_child(dimension_wrapper, expresion_node);
        add_child(brackets_new_node, dimension_wrapper);

        printf("DEBUG ARRAYS_MULTIDIMENSIONAL: Dimensión agregada a BRACKETS_NEW (total: %d dimensiones)\n",
               brackets_new_node->child_count);
    }

    return brackets_new_node;
}

ASTNode* build_brace_block(ASTNode* brace_elements_node, int line, int column) {
    ASTNode* brace_block_node = create_node("BRACE_BLOCK", line, column);
    add_child(brace_block_node, brace_elements_node);

    printf("DEBUG ARRAYS_MULTIDIMENSIONAL: BRACE_BLOCK creado\n");

    return brace_block_node;
}

ASTNode* build_brace_elements_single(ASTNode* brace_element_node, int line, int column) {
    ASTNode* brace_elements_node = create_node("BRACE_ELEMENTS", line, column);
    add_child(brace_elements_node, brace_element_node);

    printf("DEBUG ARRAYS_MULTIDIMENSIONAL: BRACE_ELEMENTS creado con 1 elemento\n");

    return brace_elements_node;
}

ASTNode* build_brace_elements_add(ASTNode* brace_elements_node, ASTNode* brace_element_node) {
    if (brace_elements_node && brace_element_node) {
        add_child(brace_elements_node, brace_element_node);

        printf("DEBUG ARRAYS_MULTIDIMENSIONAL: Elemento agregado a BRACE_ELEMENTS (total: %d elementos)\n",
               brace_elements_node->child_count);
    }

    return brace_elements_node;
}