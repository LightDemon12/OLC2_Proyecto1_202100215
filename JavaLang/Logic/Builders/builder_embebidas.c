//
// Created by lightdemon on 01/09/25.
//

#include "../../Headers/builder_embebidas.h"
#include "../../Headers/builder_datos.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

ASTNode* build_parseint_embebida(ASTNode* expresion_node, int line, int column) {
    ASTNode* parseint_node = create_node("PARSEINT_EMBEBIDA", line, column);

    // Crear wrapper para la expresión a convertir
    ASTNode* entrada_wrapper = create_node("ENTRADA_PARSEINT", line, column);
    add_child(entrada_wrapper, expresion_node);
    add_child(parseint_node, entrada_wrapper);

    printf("DEBUG EMBEBIDAS: PARSEINT_EMBEBIDA simple creado\n");

    return parseint_node;
}

ASTNode* build_parseint_embebida_radix(ASTNode* expresion_node, ASTNode* radix_node, int line, int column) {
    ASTNode* parseint_node = create_node("PARSEINT_EMBEBIDA_RADIX", line, column);

    // Crear wrapper para la expresión a convertir
    ASTNode* entrada_wrapper = create_node("ENTRADA_PARSEINT", line, column);
    add_child(entrada_wrapper, expresion_node);
    add_child(parseint_node, entrada_wrapper);

    // Crear wrapper para el radix/base
    ASTNode* radix_wrapper = create_node("RADIX_PARSEINT", line, column);
    add_child(radix_wrapper, radix_node);
    add_child(parseint_node, radix_wrapper);

    printf("DEBUG EMBEBIDAS: PARSEINT_EMBEBIDA_RADIX creado\n");

    return parseint_node;
}

ASTNode* build_parsefloat_embebida(ASTNode* expresion_node, int line, int column) {
    ASTNode* parsefloat_node = create_node("PARSEFLOAT_EMBEBIDA", line, column);

    // Crear wrapper para la expresión a convertir
    ASTNode* entrada_wrapper = create_node("ENTRADA_PARSEFLOAT", line, column);
    add_child(entrada_wrapper, expresion_node);
    add_child(parsefloat_node, entrada_wrapper);

    printf("DEBUG EMBEBIDAS: PARSEFLOAT_EMBEBIDA creado\n");

    return parsefloat_node;
}

ASTNode* build_parsedouble_embebida(ASTNode* expresion_node, int line, int column) {
    ASTNode* parsedouble_node = create_node("PARSEDOUBLE_EMBEBIDA", line, column);

    // Crear wrapper para la expresión a convertir
    ASTNode* entrada_wrapper = create_node("ENTRADA_PARSEDOUBLE", line, column);
    add_child(entrada_wrapper, expresion_node);
    add_child(parsedouble_node, entrada_wrapper);

    printf("DEBUG EMBEBIDAS: PARSEDOUBLE_EMBEBIDA creado\n");

    return parsedouble_node;
}

ASTNode* build_valueof_embebida(ASTNode* expresion_node, int line, int column) {
    ASTNode* valueof_node = create_node("VALUEOF_EMBEBIDA", line, column);

    // Crear wrapper para la expresión a convertir a String
    ASTNode* entrada_wrapper = create_node("ENTRADA_VALUEOF", line, column);
    add_child(entrada_wrapper, expresion_node);
    add_child(valueof_node, entrada_wrapper);

    printf("DEBUG EMBEBIDAS: VALUEOF_EMBEBIDA creado\n");

    return valueof_node;
}

ASTNode* build_indexof_embebida(ASTNode* array_expresion_node, ASTNode* elemento_expresion_node, int line, int column) {
    ASTNode* indexof_node = create_node("INDEXOF_EMBEBIDA", line, column);

    // Crear wrapper para el array donde buscar
    ASTNode* array_wrapper = create_node("ARRAY_INDEXOF", line, column);
    add_child(array_wrapper, array_expresion_node);
    add_child(indexof_node, array_wrapper);

    // Crear wrapper para el elemento a buscar
    ASTNode* elemento_wrapper = create_node("ELEMENTO_INDEXOF", line, column);
    add_child(elemento_wrapper, elemento_expresion_node);
    add_child(indexof_node, elemento_wrapper);

    printf("DEBUG EMBEBIDAS: INDEXOF_EMBEBIDA creado\n");

    return indexof_node;
}

ASTNode* build_length_embebida(ASTNode* expresion_node, int line, int column) {
    ASTNode* length_node = create_node("LENGTH_EMBEBIDA", line, column);

    // Crear wrapper para la expresión que tiene .length
    ASTNode* objeto_wrapper = create_node("OBJETO_LENGTH", line, column);
    add_child(objeto_wrapper, expresion_node);
    add_child(length_node, objeto_wrapper);

    printf("DEBUG EMBEBIDAS: LENGTH_EMBEBIDA creado\n");

    return length_node;
}

ASTNode* build_add_embebida(ASTNode* lista_expresion_node, ASTNode* elemento_expresion_node, int line, int column) {
    ASTNode* add_node = create_node("ADD_EMBEBIDA", line, column);

    // Crear wrapper para la lista/colección
    ASTNode* lista_wrapper = create_node("LISTA_ADD", line, column);
    add_child(lista_wrapper, lista_expresion_node);
    add_child(add_node, lista_wrapper);

    // Crear wrapper para el elemento a agregar
    ASTNode* elemento_wrapper = create_node("ELEMENTO_ADD", line, column);
    add_child(elemento_wrapper, elemento_expresion_node);
    add_child(add_node, elemento_wrapper);

    printf("DEBUG EMBEBIDAS: ADD_EMBEBIDA creado\n");

    return add_node;
}