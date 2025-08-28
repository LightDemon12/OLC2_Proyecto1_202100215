//
// Created by lightdemon on 27/08/25.
//

#ifndef AST_H
#define AST_H

#include <stdbool.h>

typedef struct {
    char *key;
    char *value;
} Attribute;

typedef struct ASTNode {
    char *type;
    char *value;
    int line;
    int column;
    struct ASTNode **children;
    int child_count;
    Attribute *attributes;
    int attr_count;
} ASTNode;

extern ASTNode* ast_root;

// Funciones principales
ASTNode* create_node(const char *type, int line, int column);
void free_node(ASTNode *node);

// Manejo de valores
void set_value(ASTNode *node, const char *value);

// Manejo de atributos
void set_attribute(ASTNode *node, const char *key, const char *value);
char* get_attribute(ASTNode *node, const char *key, const char *default_value);
bool has_attribute(ASTNode *node, const char *key);

// Manejo de hijos
void add_child(ASTNode *parent, ASTNode *child);
void add_children(ASTNode *parent, ASTNode **children, int count);
ASTNode* get_child(ASTNode *parent, int index);

// Debug
void print_node(ASTNode *node, int indent);

#endif // AST_H