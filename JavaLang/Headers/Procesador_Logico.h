//
// Created by lightdemon on 2/09/25.
//

#ifndef PROCESADOR_LOGICO_H
#define PROCESADOR_LOGICO_H

#include "ast.h"
#include "Tabla_Simbolos.h"
#include "node_processor.h"

/**
 * Tipos de operadores lógicos soportados
 */
typedef enum {
    LOGICO_AND,       // &&
    LOGICO_OR,        // ||
    LOGICO_NOT,       // !
    LOGICO_DESCONOCIDO
} TipoOperadorLogico;

/**
 * Procesa un nodo de expresión binaria lógica (&&, ||)
 * @param context - Contexto del procesador con tabla de símbolos
 * @param node - Nodo AST de tipo EXPRESION_BINARIA con operador lógico
 * @return String con resultado boolean ("true" o "false") o NULL si error
 */
char* process_logico_binario_node(NodeProcessorContext* context, ASTNode* node);

/**
 * Procesa un nodo de expresión unaria lógica (!)
 * @param context - Contexto del procesador con tabla de símbolos
 * @param node - Nodo AST de tipo EXPRESION_UNARIA con operador !
 * @return String con resultado boolean ("true" o "false") o NULL si error
 */
char* process_logico_unario_node(NodeProcessorContext* context, ASTNode* node);

/**
 * Determina el tipo de operador lógico desde el string
 * @param operador - String del operador (&&, ||, !)
 * @return Tipo de operador lógico correspondiente
 */
TipoOperadorLogico get_tipo_operador_logico(const char* operador);

/**
 * Verifica si un valor string representa un boolean válido
 * @param valor - String a verificar
 * @return 1 si es "true" o "false", 0 si no
 */
int es_valor_boolean_valido(const char* valor);

/**
 * Convierte un string boolean a valor entero
 * @param valor - String "true" o "false"
 * @return 1 para true, 0 para false, -1 para error
 */
int string_to_boolean(const char* valor);

/**
 * Convierte un valor entero boolean a string
 * @param valor - 0 (false) o 1 (true)
 * @return String "true" o "false"
 */
const char* boolean_to_string(int valor);

/**
 * Realiza operación AND lógica con evaluación perezosa
 * @param izq - Valor boolean izquierdo (0 o 1)
 * @param der - Valor boolean derecho (0 o 1)
 * @return Resultado de izq && der
 */
int realizar_and_logico(int izq, int der);

/**
 * Realiza operación OR lógica con evaluación perezosa
 * @param izq - Valor boolean izquierdo (0 o 1)
 * @param der - Valor boolean derecho (0 o 1)
 * @return Resultado de izq || der
 */
int realizar_or_logico(int izq, int der);

/**
 * Realiza operación NOT lógica
 * @param valor - Valor boolean (0 o 1)
 * @return Resultado de !valor
 */
int realizar_not_logico(int valor);

/**
 * Verifica si un tipo de dato es compatible con operaciones lógicas
 * @param tipo - Tipo de dato a verificar
 * @return 1 si es compatible (TIPO_BOOLEAN), 0 si no
 */
int tipo_compatible_logico(TipoDato tipo);

#endif // PROCESADOR_LOGICO_H