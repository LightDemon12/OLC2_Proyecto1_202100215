//
// Created by lightdemon on 31/08/25.
//

#include "../../Headers/builder_scope.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ========== BUILDERS PARA MANEJO DE SCOPES ==========

ASTNode* build_scope(ASTNode* instrucciones_node, const char* scope_type, int line, int column) {
    ASTNode* scope_node = create_node("SCOPE", line, column);
    set_value(scope_node, scope_type);

    // Agregar las instrucciones como hijo
    add_child(scope_node, instrucciones_node);

    printf("DEBUG SCOPE: SCOPE creado - tipo:%s\n", scope_type ? scope_type : "null");

    return scope_node;
}

ASTNode* build_scope_main(ASTNode* instrucciones_node, int line, int column) {
    return build_scope(instrucciones_node, "MAIN", line, column);
}

ASTNode* build_scope_bloque(ASTNode* instrucciones_node, const char* control_type, int line, int column) {
    char scope_name[64];
    snprintf(scope_name, sizeof(scope_name), "BLOQUE_%s", control_type);

    return build_scope(instrucciones_node, scope_name, line, column);
}