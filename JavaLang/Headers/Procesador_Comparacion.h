//
// Created by lightdemon on 2/09/25.
//

#ifndef PROCESADOR_COMPARACION_H
#define PROCESADOR_COMPARACION_H

#include "ast.h"
#include "Tabla_Simbolos.h"
#include "node_processor.h"

/**
 * Tipos de operadores de comparación soportados
 */
typedef enum {
    COMP_IGUAL,          // ==
    COMP_DIFERENTE,      // !=
    COMP_MAYOR,          // >
    COMP_MENOR,          // <
    COMP_MAYOR_IGUAL,    // >=
    COMP_MENOR_IGUAL,    // <=
    COMP_DESCONOCIDO
} TipoComparacion;

/**
 * Procesa un nodo de expresión binaria de comparación
 * @param context - Contexto del procesador con tabla de símbolos
 * @param node - Nodo AST de tipo EXPRESION_BINARIA con operador de comparación
 * @return String con resultado boolean ("true" o "false") o NULL si error
 */
char* process_comparacion_node(NodeProcessorContext* context, ASTNode* node);

/**
 * Determina el tipo de comparación desde el operador
 * @param operador - String del operador (==, !=, >, <, >=, <=)
 * @return Tipo de comparación correspondiente
 */
TipoComparacion get_tipo_comparacion(const char* operador);

/**
 * Verifica si dos tipos de datos son compatibles para comparación
 * @param tipo1 - Primer tipo
 * @param tipo2 - Segundo tipo
 * @param operador - Operador de comparación
 * @return 1 si son compatibles, 0 si no
 */
int tipos_compatibles_comparacion(TipoDato tipo1, TipoDato tipo2, const char* operador);

/**
 * Realiza la comparación numérica entre dos valores
 * @param valor1 - Primer valor numérico
 * @param valor2 - Segundo valor numérico
 * @param tipo_comp - Tipo de comparación a realizar
 * @return 1 si la comparación es verdadera, 0 si es falsa
 */
int realizar_comparacion_numerica(double valor1, double valor2, TipoComparacion tipo_comp);

/**
 * Realiza la comparación de caracteres
 * @param char1 - Primer carácter
 * @param char2 - Segundo carácter
 * @param tipo_comp - Tipo de comparación a realizar
 * @return 1 si la comparación es verdadera, 0 si es falsa
 */
int realizar_comparacion_char(char char1, char char2, TipoComparacion tipo_comp);

/**
 * Realiza la comparación de booleanos
 * @param bool1 - Primer valor booleano
 * @param bool2 - Segundo valor booleano
 * @param tipo_comp - Tipo de comparación a realizar
 * @return 1 si la comparación es verdadera, 0 si es falsa
 */
int realizar_comparacion_boolean(int bool1, int bool2, TipoComparacion tipo_comp);

/**
 * Realiza la comparación de strings (para .equals() futuro)
 * @param str1 - Primera cadena
 * @param str2 - Segunda cadena
 * @param tipo_comp - Tipo de comparación a realizar
 * @return 1 si la comparación es verdadera, 0 si es falsa
 */
int realizar_comparacion_string(const char* str1, const char* str2, TipoComparacion tipo_comp);

#endif // PROCESADOR_COMPARACION_H