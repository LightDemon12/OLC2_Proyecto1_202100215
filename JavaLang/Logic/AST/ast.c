//
// Created by lightdemon on 27/08/25.
//

#include "../../Headers/ast.h"
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
    /* SI NO SE PASA NODO Y ES LA PRIMERA LLAMADA, USAR EL GLOBAL */
    if (!node && indent == 0) {
        node = ast_root;  /* ← USAR LA VARIABLE GLOBAL */
        printf("DEBUG: Usando ast_root global: %p\n", (void*)ast_root);
    }

    if (!node) {
        printf("DEBUG: Nodo es NULL\n");
        return;
    }

    for (int i = 0; i < indent; i++) printf("  ");
    printf("{ type: %s", node->type);

    if (node->value) {
        printf(", value: %s", node->value);
    }

    printf(", line: %d, column: %d", node->line, node->column);

    if (node->attr_count > 0) {
        printf(", attributes: { ");
        for (int i = 0; i < node->attr_count; i++) {
            printf("%s: %s", node->attributes[i].key, node->attributes[i].value);
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
}