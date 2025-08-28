//
// Created by lightdemon on 21/08/25.
//

#ifndef AST_H
#define AST_H

#include <stdbool.h>

// ========== ESTRUCTURAS ==========

typedef struct Attribute {
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

// ========== FUNCIONES BÁSICAS ==========

/* Crear y liberar nodos */
ASTNode* create_node(const char *type, int line, int column);
void free_node(ASTNode *node);

/* Manejo de valores */
void set_value(ASTNode *node, const char *value);

/* Manejo de atributos */
void set_attribute(ASTNode *node, const char *key, const char *value);
char* get_attribute(ASTNode *node, const char *key, const char *default_value);
bool has_attribute(ASTNode *node, const char *key);

/* Manejo de hijos */
void add_child(ASTNode *parent, ASTNode *child);
void add_children(ASTNode *parent, ASTNode **children, int count);
ASTNode* get_child(ASTNode *parent, int index);

// ========== FUNCIONES DE DEBUG ==========

/* Imprimir AST (si node es NULL, usa ast_root global) */
void print_node(ASTNode *node, int indent);

/* Información y estadísticas */
void print_ast_info();
void print_ast_stats();
int count_nodes(ASTNode *node);

/* Validación y búsqueda */
bool validate_ast(ASTNode *node);
ASTNode* find_node_by_type(const char* type, ASTNode *start_node);

#endif // AST_H