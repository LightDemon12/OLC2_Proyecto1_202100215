//
// Created by lightdemon on 01/09/25.
//

#include "../../Headers/builder_expresion_arrays.h"
#include "../../Headers/builder_datos.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

ASTNode* build_asignacion_compuesta_array_1d(const char* nombre_array, ASTNode* indice_node, ASTNode* operador_node, ASTNode* expresion_node, int line, int column) {
    ASTNode* asignacion_node = create_node("ASIGNACION_COMPUESTA_ARRAY_1D", line, column);

    // Crear acceso al array
    ASTNode* acceso_wrapper = create_node("ACCESO_ARRAY_1D", line, column);
    ASTNode* array_node = build_identifier(nombre_array, line, column);
    add_child(acceso_wrapper, array_node);

    ASTNode* indice_wrapper = create_node("INDICE_ARRAY", line, column);
    add_child(indice_wrapper, indice_node);
    add_child(acceso_wrapper, indice_wrapper);
    add_child(asignacion_node, acceso_wrapper);

    // Operador
    add_child(asignacion_node, operador_node);

    // Expresión
    ASTNode* valor_wrapper = create_node("VALOR_ASIGNACION", line, column);
    add_child(valor_wrapper, expresion_node);
    add_child(asignacion_node, valor_wrapper);

    printf("DEBUG EXPRESION_ARRAYS: ASIGNACION_COMPUESTA_ARRAY_1D creado - array:%s, operador:%s\n",
           nombre_array ? nombre_array : "null",
           operador_node && operador_node->value ? operador_node->value : "unknown");

    return asignacion_node;
}

ASTNode* build_asignacion_compuesta_array_multidimensional(const char* nombre_array, ASTNode* brackets_indices_node, ASTNode* operador_node, ASTNode* expresion_node, int line, int column) {
    ASTNode* asignacion_node = create_node("ASIGNACION_COMPUESTA_ARRAY_MULTIDIMENSIONAL", line, column);

    // Crear acceso multidimensional
    ASTNode* acceso_wrapper = create_node("ACCESO_ARRAY_MULTIDIMENSIONAL", line, column);
    ASTNode* array_node = build_identifier(nombre_array, line, column);
    add_child(acceso_wrapper, array_node);
    add_child(acceso_wrapper, brackets_indices_node);
    add_child(asignacion_node, acceso_wrapper);

    // Operador
    add_child(asignacion_node, operador_node);

    // Expresión
    ASTNode* valor_wrapper = create_node("VALOR_ASIGNACION", line, column);
    add_child(valor_wrapper, expresion_node);
    add_child(asignacion_node, valor_wrapper);

    // Calcular dimensiones
    int dimensiones = brackets_indices_node ? brackets_indices_node->child_count : 0;
    printf("DEBUG EXPRESION_ARRAYS: ASIGNACION_COMPUESTA_ARRAY_MULTIDIMENSIONAL creado - array:%s, operador:%s, dimensiones:%d\n",
           nombre_array ? nombre_array : "null",
           operador_node && operador_node->value ? operador_node->value : "unknown", dimensiones);

    return asignacion_node;
}