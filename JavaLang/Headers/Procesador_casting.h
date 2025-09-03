//
// Created by lightdemon on 2/09/25.
//

#ifndef PROCESADOR_CASTING_H
#define PROCESADOR_CASTING_H

#include "node_processor.h"
#include "ast.h"
#include "Tabla_Simbolos.h"

// ========== PROCESADOR DE CASTING ==========

/**
 * Procesa un nodo CAST para conversión explícita de tipos
 * @param context - Contexto del procesador
 * @param node - Nodo CAST con estructura: [0]=tipo_destino, [1]=expresion
 * @return Valor convertido como string, NULL si hay error
 */
char* process_cast_node(NodeProcessorContext* context, ASTNode* node);

/**
 * Verifica si un cast es válido según las reglas de Java
 * @param tipo_origen - Tipo original de la expresión
 * @param tipo_destino - Tipo al que se quiere convertir
 * @return 1 si es válido, 0 si no
 */
int validar_cast(TipoDato tipo_origen, TipoDato tipo_destino);

/**
 * Convierte un valor de un tipo a otro
 * @param valor - Valor original como string
 * @param tipo_origen - Tipo original
 * @param tipo_destino - Tipo de destino
 * @return Valor convertido como string, NULL si hay error
 */
char* convertir_valor_cast(const char* valor, TipoDato tipo_origen, TipoDato tipo_destino);

/**
 * Convierte un número a entero (para cast a int, long, char, etc.)
 * @param valor - Valor como string
 * @return Valor entero
 */
long convertir_a_entero(const char* valor);

/**
 * Convierte un número a decimal (para cast a float, double)
 * @param valor - Valor como string
 * @return Valor decimal
 */
double convertir_a_decimal(const char* valor);
/**
 * Extrae el valor ASCII de un carácter en cualquier formato
 * @param char_str - String con el carácter ('A', 'B', etc.)
 * @return Valor ASCII entero
 */
int extraer_valor_ascii_char(const char* char_str);
#endif // PROCESADOR_CASTING_H