//
// Created by lightdemon on 31/08/25.
//

#include "../../Headers/builder_ciclos.h"
#include "../../Headers/builder_scope.h"
#include "../../Headers/builder_datos.h"

#include <stdio.h>
#include <stdlib.h>

// ========== BUILDERS PARA CICLOS ==========

ASTNode* build_while(ASTNode* condicion_node, ASTNode* instrucciones_node, int line, int column) {
    ASTNode* while_node = create_node("WHILE", line, column);

    // Crear nodo explícito para la condición
    ASTNode* condicion_wrapper = create_node("CONDICION_WHILE", line, column);
    add_child(condicion_wrapper, condicion_node);
    add_child(while_node, condicion_wrapper);

    // Crear nodo explícito para el bloque del while CON SCOPE
    ASTNode* bloque_while = create_node("BLOQUE_WHILE", line, column);
    ASTNode* scope_while = build_scope_bloque(instrucciones_node, "WHILE", line, column);
    add_child(bloque_while, scope_while);
    add_child(while_node, bloque_while);

    printf("DEBUG CICLOS: WHILE creado con CONDICION_WHILE y BLOQUE_WHILE con SCOPE\n");

    return while_node;
}

ASTNode* build_do_while(ASTNode* instrucciones_node, ASTNode* condicion_node, int line, int column) {
    ASTNode* do_while_node = create_node("DO_WHILE", line, column);

    // Crear nodo explícito para el bloque del do CON SCOPE
    ASTNode* bloque_do = create_node("BLOQUE_DO", line, column);
    ASTNode* scope_do = build_scope_bloque(instrucciones_node, "DO", line, column);
    add_child(bloque_do, scope_do);
    add_child(do_while_node, bloque_do);

    // Crear nodo explícito para la condición del while
    ASTNode* condicion_wrapper = create_node("CONDICION_DO_WHILE", line, column);
    add_child(condicion_wrapper, condicion_node);
    add_child(do_while_node, condicion_wrapper);

    printf("DEBUG CICLOS: DO_WHILE creado con BLOQUE_DO con SCOPE y CONDICION_DO_WHILE\n");

    return do_while_node;
}

ASTNode* build_for(ASTNode* inicializacion_node, ASTNode* condicion_node, ASTNode* actualizacion_node, ASTNode* instrucciones_node, int line, int column) {
    ASTNode* for_node = create_node("FOR", line, column);

    // Crear nodo explícito para la inicialización (puede ser NULL)
    ASTNode* inicializacion_wrapper = create_node("INICIALIZACION_FOR", line, column);
    if (inicializacion_node) {
        add_child(inicializacion_wrapper, inicializacion_node);
    }
    add_child(for_node, inicializacion_wrapper);

    // Crear nodo explícito para la condición (puede ser NULL)
    ASTNode* condicion_wrapper = create_node("CONDICION_FOR", line, column);
    if (condicion_node) {
        add_child(condicion_wrapper, condicion_node);
    }
    add_child(for_node, condicion_wrapper);

    // Crear nodo explícito para la actualización (puede ser NULL)
    ASTNode* actualizacion_wrapper = create_node("ACTUALIZACION_FOR", line, column);
    if (actualizacion_node) {
        add_child(actualizacion_wrapper, actualizacion_node);
    }
    add_child(for_node, actualizacion_wrapper);

    // Crear nodo explícito para el bloque del for CON SCOPE
    ASTNode* bloque_for = create_node("BLOQUE_FOR", line, column);
    ASTNode* scope_for = build_scope_bloque(instrucciones_node, "FOR", line, column);
    add_child(bloque_for, scope_for);
    add_child(for_node, bloque_for);

    printf("DEBUG CICLOS: FOR creado con INICIALIZACION_FOR, CONDICION_FOR, ACTUALIZACION_FOR y BLOQUE_FOR con SCOPE\n");

    return for_node;
}

ASTNode* build_inicializacion_for_declaracion(ASTNode* tipo_node, const char* identifier, ASTNode* expresion_node, int line, int column) {
    ASTNode* init_node = create_node("INICIALIZACION_FOR_DECLARACION", line, column);

    // Agregar tipo
    add_child(init_node, tipo_node);

    // Agregar identificador
    ASTNode* id_node = create_node("IDENTIFIER", line, column);
    set_value(id_node, identifier);
    add_child(init_node, id_node);

    // Agregar expresión de inicialización
    add_child(init_node, expresion_node);

    printf("DEBUG CICLOS: INICIALIZACION_FOR_DECLARACION creada para variable '%s'\n", identifier ? identifier : "null");

    return init_node;
}

ASTNode* build_inicializacion_for_expresion(ASTNode* expresion_node, int line, int column) {
    ASTNode* init_node = create_node("INICIALIZACION_FOR_EXPRESION", line, column);
    add_child(init_node, expresion_node);

    printf("DEBUG CICLOS: INICIALIZACION_FOR_EXPRESION creada\n");

    return init_node;
}

ASTNode* build_inicializacion_for_vacia(int line, int column) {
    ASTNode* init_node = create_node("INICIALIZACION_FOR_VACIA", line, column);

    printf("DEBUG CICLOS: INICIALIZACION_FOR_VACIA creada\n");

    return init_node;
}

ASTNode* build_actualizacion_for(ASTNode* expresion_node, int line, int column) {
    ASTNode* update_node = create_node("ACTUALIZACION_FOR", line, column);
    add_child(update_node, expresion_node);

    printf("DEBUG CICLOS: ACTUALIZACION_FOR creada\n");

    return update_node;
}

ASTNode* build_actualizacion_for_vacia(int line, int column) {
    ASTNode* update_node = create_node("ACTUALIZACION_FOR_VACIA", line, column);

    printf("DEBUG CICLOS: ACTUALIZACION_FOR_VACIA creada\n");

    return update_node;
}

ASTNode* build_inicializacion_for_asignacion(const char* identifier, ASTNode* operador_node, ASTNode* expresion_node, int line, int column) {
    ASTNode* inicializacion_node = create_node("INICIALIZACION_FOR_ASIGNACION", line, column);

    // Crear nodo identificador
    ASTNode* id_node = build_identifier(identifier, line, column);

    // Agregar hijos: identificador, operador y expresión
    add_child(inicializacion_node, id_node);
    add_child(inicializacion_node, operador_node);
    add_child(inicializacion_node, expresion_node);

    // Obtener el operador para el debug
    const char* op_str = operador_node && operador_node->value ? operador_node->value : "=";
    printf("DEBUG CICLOS: INICIALIZACION_FOR_ASIGNACION creada para variable '%s' con operador '%s'\n",
           identifier ? identifier : "null", op_str);

    return inicializacion_node;
}

ASTNode* build_for_each(ASTNode* tipo_node, const char* variable, const char* coleccion, ASTNode* instrucciones_node, int line, int column) {
    ASTNode* for_each_node = create_node("FOR_EACH", line, column);

    // Crear nodo de declaración de la variable iteradora
    ASTNode* declaracion_wrapper = create_node("DECLARACION_FOR_EACH", line, column);
    add_child(declaracion_wrapper, tipo_node);

    ASTNode* variable_node = build_identifier(variable, line, column);
    add_child(declaracion_wrapper, variable_node);
    add_child(for_each_node, declaracion_wrapper);

    // Crear nodo de la colección a iterar
    ASTNode* coleccion_wrapper = create_node("COLECCION_FOR_EACH", line, column);
    ASTNode* coleccion_node = build_identifier(coleccion, line, column);
    add_child(coleccion_wrapper, coleccion_node);
    add_child(for_each_node, coleccion_wrapper);

    // Crear nodo explícito para el bloque del for-each CON SCOPE
    ASTNode* bloque_for_each = create_node("BLOQUE_FOR_EACH", line, column);
    ASTNode* scope_for_each = build_scope_bloque(instrucciones_node, "FOR_EACH", line, column);
    add_child(bloque_for_each, scope_for_each);
    add_child(for_each_node, bloque_for_each);

    printf("DEBUG CICLOS: FOR_EACH creado - variable:%s, coleccion:%s con BLOQUE_FOR_EACH y SCOPE\n",
           variable ? variable : "null", coleccion ? coleccion : "null");

    return for_each_node;
}