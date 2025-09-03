//
// Created by lightdemon on 2/09/25.
//

#ifndef PROCESADOR_CONSTANTES_H
#define PROCESADOR_CONSTANTES_H

#include "node_processor.h"
#include "ast.h"
#include "Tabla_Simbolos.h"

/**
 * Procesa nodos de constantes (final)
 * @param context - Contexto del procesador
 * @param node - Nodo de constante a procesar
 * @return 0 si es exitoso, 1 si hay error
 */
int process_constante_node(NodeProcessorContext* context, ASTNode* node);

/**
 * Procesa una constante con inicialización
 * @param context - Contexto del procesador
 * @param tipo - Tipo de dato de la constante
 * @param id_nodo - Nodo identificador
 * @param valor_nodo - Nodo con el valor
 * @param parent - Nodo padre
 * @return 0 si es exitoso, 1 si hay error
 */
int process_constante_con_inicializacion(NodeProcessorContext* context, TipoDato tipo,
                                        ASTNode* id_nodo, ASTNode* valor_nodo, ASTNode* parent);

/**
 * Procesa múltiples constantes en una declaración
 * @param context - Contexto del procesador
 * @param tipo - Tipo de dato de las constantes
 * @param lista_nodo - Nodo con la lista de constantes
 * @param parent - Nodo padre
 * @return 0 si es exitoso, 1 si hay error
 */
int process_constante_multiple(NodeProcessorContext* context, TipoDato tipo,
                              ASTNode* lista_nodo, ASTNode* parent);

#endif // PROCESADOR_CONSTANTES_H