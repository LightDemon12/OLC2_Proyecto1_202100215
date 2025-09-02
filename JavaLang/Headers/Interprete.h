//
// Created by lightdemon on 2/09/25.
//

#ifndef INTERPRETE_H
#define INTERPRETE_H

#include "ast.h"
#include "Tabla_Simbolos.h"
#include "node_processor.h"

struct MainView;
typedef struct MainView MainView;

/**
 * Contexto del intérprete - Solo para recorrido de AST y tabla de símbolos
 */
typedef struct {
    TablaSimbolos* tabla_simbolos;       // Tabla de símbolos
    ASTNode* ast_root;                   // AST a recorrer
    int linea_actual;                    // Línea actual
    int modo_debug;                      // 1 = debug activo, 0 = silencioso
} ContextoInterprete;

/**
 * Crear un nuevo contexto del intérprete
 */
ContextoInterprete* crear_contexto_interprete(ASTNode* ast_root);

/**
 * Liberar el contexto del intérprete
 */
void liberar_contexto_interprete(ContextoInterprete* contexto);

/**
 * Función principal: recorrer AST y generar tabla de símbolos
 */
int procesar_ast(ContextoInterprete* contexto);

/**
 * Recorrer un nodo del AST recursivamente
 */
int recorrer_nodo(ContextoInterprete* contexto, ASTNode* nodo);

/**
 * Procesar declaraciones y agregar a tabla de símbolos
 */
int procesar_declaracion(ContextoInterprete* contexto, ASTNode* nodo);
/**
 * Función pública para procesar un AST y generar tabla de símbolos
 */
int interpretar_ast_simple(ASTNode* ast_root);

/**
 * Recorre el AST de forma recursiva manejando ámbitos correctamente
 * @param context Contexto del intérprete
 * @param node Nodo AST a recorrer
 * @return 0 si exitoso, código de error caso contrario
 */
int recorrer_ast_recursivo(NodeProcessorContext* context, ASTNode* node);


/**
 * Interpreta el AST con salida visible en GUI
 */
int interpretar_ast_con_gui(ASTNode* ast_root, MainView* mainview);

/**
 * Interpreta el AST solo en consola (función original)
 */
int interpretar_ast_simple(ASTNode* ast_root);

#endif // INTERPRETE_H