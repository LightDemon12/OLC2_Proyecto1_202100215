//
// Created by lightdemon on 27/08/25.
//

#include "../../Headers/ast.h"
#include "../../Headers/globals.h"  // ← INCLUIR PARA ast_root GLOBAL
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ----- Crear nodo -----
ASTNode* create_node(const char *type, int line, int column) {
    ASTNode *node = (ASTNode*)malloc(sizeof(ASTNode));
    node->type = strdup(type);
    node->value = NULL;
    node->line = line;
    node->column = column;
    node->children = NULL;
    node->child_count = 0;
    node->attributes = NULL;
    node->attr_count = 0;
    return node;
}

// ----- Liberar memoria -----
void free_node(ASTNode *node) {
    if (!node) return;

    free(node->type);
    if (node->value) free(node->value);

    for (int i = 0; i < node->child_count; i++) {
        free_node(node->children[i]);
    }
    free(node->children);

    for (int i = 0; i < node->attr_count; i++) {
        free(node->attributes[i].key);
        free(node->attributes[i].value);
    }
    free(node->attributes);

    free(node);
}

// ----- Value -----
void set_value(ASTNode *node, const char *value) {
    if (node->value) free(node->value);
    node->value = strdup(value);
}

// ----- Atributos -----
void set_attribute(ASTNode *node, const char *key, const char *value) {
    node->attributes = realloc(node->attributes,
                              (node->attr_count + 1) * sizeof(Attribute));
    node->attributes[node->attr_count].key = strdup(key);
    node->attributes[node->attr_count].value = strdup(value);
    node->attr_count++;
}

char* get_attribute(ASTNode *node, const char *key, const char *default_value) {
    for (int i = 0; i < node->attr_count; i++) {
        if (strcmp(node->attributes[i].key, key) == 0) {
            return node->attributes[i].value;
        }
    }
    return (char*)default_value;
}

bool has_attribute(ASTNode *node, const char *key) {
    for (int i = 0; i < node->attr_count; i++) {
        if (strcmp(node->attributes[i].key, key) == 0) {
            return true;
        }
    }
    return false;
}

// ----- Hijos -----
void add_child(ASTNode *parent, ASTNode *child) {
    parent->children = realloc(parent->children,
                              (parent->child_count + 1) * sizeof(ASTNode*));
    parent->children[parent->child_count] = child;
    parent->child_count++;
}

void add_children(ASTNode *parent, ASTNode **children, int count) {
    for (int i = 0; i < count; i++) {
        add_child(parent, children[i]);
    }
}

ASTNode* get_child(ASTNode *parent, int index) {
    if (index >= 0 && index < parent->child_count) {
        return parent->children[index];
    }
    return NULL;
}

// ----- Debug -----
void print_node(ASTNode *node, int indent) {
    /* SI NO SE PASA NODO (NULL), USAR LA VARIABLE GLOBAL */
    if (!node) {
        node = ast_root;
        if (indent == 0) {
            printf("=== IMPRIMIENDO AST DESDE RAÍZ GLOBAL ===\n");
            printf("DEBUG: ast_root = %p\n", (void*)ast_root);
        }

        if (!node) {
            printf("ERROR: ast_root es NULL - no hay AST para imprimir\n");
            return;
        }
    }

    for (int i = 0; i < indent; i++) printf("  ");
    printf("{ type: %s", node->type);

    if (node->value) {
        printf(", value: \"%s\"", node->value);
    }

    printf(", line: %d, column: %d", node->line, node->column);

    if (node->attr_count > 0) {
        printf(", attributes: { ");
        for (int i = 0; i < node->attr_count; i++) {
            printf("%s: \"%s\"", node->attributes[i].key, node->attributes[i].value);
            if (i < node->attr_count - 1) printf(", ");
        }
        printf(" }");
    }

    if (node->child_count > 0) {
        printf(", children: [\n");
        for (int i = 0; i < node->child_count; i++) {
            print_node(node->children[i], indent + 1);
        }
        for (int i = 0; i < indent; i++) printf("  ");
        printf("]");
    }

    printf(" }\n");

    /* AGREGAR INFORMACIÓN FINAL SOLO EN LA RAÍZ */
    if (indent == 0) {
        printf("=== FIN AST ===\n");
    }
}

// ----- Funciones adicionales para debug -----

/* FUNCIÓN PARA OBTENER INFORMACIÓN BÁSICA DEL AST */
void print_ast_info() {
    printf("=== INFORMACIÓN DEL AST ===\n");
    printf("ast_root: %p\n", (void*)ast_root);

    if (ast_root) {
        printf("Tipo de raíz: %s\n", ast_root->type);
        printf("Línea: %d, Columna: %d\n", ast_root->line, ast_root->column);
        printf("Número de hijos: %d\n", ast_root->child_count);

        if (ast_root->value) {
            printf("Valor: \"%s\"\n", ast_root->value);
        }

        printf("Atributos: %d\n", ast_root->attr_count);
    } else {
        printf("AST no disponible\n");
    }
    printf("========================\n");
}

/* FUNCIÓN PARA CONTAR NODOS TOTALES */
int count_nodes(ASTNode *node) {
    if (!node) {
        node = ast_root;
    }

    if (!node) return 0;

    int count = 1; // El nodo actual

    for (int i = 0; i < node->child_count; i++) {
        count += count_nodes(node->children[i]);
    }

    return count;
}

/* FUNCIÓN PARA OBTENER ESTADÍSTICAS DEL AST */
void print_ast_stats() {
    printf("=== ESTADÍSTICAS DEL AST ===\n");

    if (!ast_root) {
        printf("AST no disponible\n");
        printf("==========================\n");
        return;
    }

    int total_nodes = count_nodes(NULL);
    printf("Total de nodos: %d\n", total_nodes);
    printf("Tipo de raíz: %s\n", ast_root->type);
    printf("Profundidad máxima: "); // TODO: implementar si es necesario
    printf("Calculando...\n");
    printf("===========================\n");
}

/* FUNCIÓN PARA VALIDAR INTEGRIDAD DEL AST */
bool validate_ast(ASTNode *node) {
    if (!node) {
        node = ast_root;
    }

    if (!node) return false;

    // Validaciones básicas
    if (!node->type) return false;
    if (node->child_count < 0) return false;
    if (node->attr_count < 0) return false;

    // Validar hijos recursivamente
    for (int i = 0; i < node->child_count; i++) {
        if (!validate_ast(node->children[i])) {
            return false;
        }
    }

    return true;
}

/* FUNCIÓN PARA BUSCAR NODOS POR TIPO */
ASTNode* find_node_by_type(const char* type, ASTNode *start_node) {
    if (!start_node) {
        start_node = ast_root;
    }

    if (!start_node) return NULL;

    if (strcmp(start_node->type, type) == 0) {
        return start_node;
    }

    for (int i = 0; i < start_node->child_count; i++) {
        ASTNode* result = find_node_by_type(type, start_node->children[i]);
        if (result) return result;
    }

    return NULL;
}