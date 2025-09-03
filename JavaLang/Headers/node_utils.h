//
// Created by lightdemon on 2/09/25.
//

#ifndef NODE_UTILS_H
#define NODE_UTILS_H

#include "ast.h"
#include "node_processor.h"
#include "Tabla_Simbolos.h"

// ===== FUNCIONES PRINCIPALES DE ANÁLISIS DE NODOS =====

/**
 * Obtiene el tipo de dato de un nodo AST
 * Maneja: DATO, literales, IDENTIFIER, EXPRESION_UNARIA, EXPRESION_BINARIA
 */
TipoDato obtener_tipo_desde_nodo(ASTNode* node, NodeProcessorContext* context);

/**
 * Obtiene el valor de un nodo AST como string
 * Maneja: DATO, literales, IDENTIFIER, EXPRESION_UNARIA, EXPRESION_BINARIA
 */
char* obtener_valor_desde_nodo(ASTNode* node, NodeProcessorContext* context);

// ===== FUNCIONES AUXILIARES DE CONVERSIÓN =====

/**
 * Convierte un string a número según el tipo de dato
 */
double convertir_a_numero(const char* valor, TipoDato tipo);

/**
 * Convierte un valor a string según el tipo
 */
char* convertir_numero_a_string(double valor, TipoDato tipo);

/**
 * Verifica si un tipo es numérico (int, float, double, char)
 */
int es_tipo_numerico(TipoDato tipo);

/**
 * Verifica si un nodo representa una expresión
 */
int es_nodo_expresion(const char* node_type);

// ===== FUNCIONES DE PROMOCIÓN DE TIPOS =====

/**
 * Determina el tipo resultante de promoción automática entre dos tipos
 * Sigue las reglas de Java: double > float > long > int > char
 */
TipoDato promocionar_tipos(TipoDato tipo1, TipoDato tipo2);

/**
 * Verifica si dos tipos son compatibles para operaciones aritméticas
 */
int tipos_compatibles_aritmetica(TipoDato tipo1, TipoDato tipo2);

// ===== FUNCIONES FORWARD DECLARATIONS =====
// Para evitar dependencias circulares con procesadores
struct NodeProcessorContext;
extern char* process_expresion_node(NodeProcessorContext* context, ASTNode* node);
/**
 * Verifica si es una promoción automática válida según Java
 * @param tipo_origen - Tipo original
 * @param tipo_destino - Tipo de destino
 * @return 1 si es promoción automática válida, 0 si no
 */
int es_promocion_automatica(TipoDato tipo_origen, TipoDato tipo_destino);
#endif // NODE_UTILS_H