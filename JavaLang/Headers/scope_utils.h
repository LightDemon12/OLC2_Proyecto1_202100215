//
// Created by lightdemon on 3/09/25.
//

#ifndef SCOPE_UTILS_H
#define SCOPE_UTILS_H

#include "node_processor.h"
#include "ast.h"

// ===== ENUMERACIÓN DE TIPOS DE SCOPE =====
typedef enum {
    SCOPE_TYPE_IF,
    SCOPE_TYPE_ELSE,
    SCOPE_TYPE_ELSE_IF,
    SCOPE_TYPE_WHILE,
    SCOPE_TYPE_FOR,
    SCOPE_TYPE_DO_WHILE,
    SCOPE_TYPE_SWITCH,
    SCOPE_TYPE_CASE,
    SCOPE_TYPE_FUNCTION,
    SCOPE_TYPE_BLOCK,
    SCOPE_TYPE_TRY,
    SCOPE_TYPE_CATCH,
    SCOPE_TYPE_FINALLY
} ScopeGeneratorType;

// ===== FUNCIONES PRINCIPALES =====

/**
 * Genera un nombre único para un scope basado en el tipo y contexto
 * @param context - Contexto del procesador
 * @param type - Tipo de scope a generar
 * @param node - Nodo AST para referencia (puede ser NULL)
 * @return Nombre del scope generado (debe liberarse con free)
 */
char* generate_scope_name(NodeProcessorContext* context, ScopeGeneratorType type, ASTNode* node);

/**
 * Genera un nombre jerárquico completo para el scope
 * @param context - Contexto del procesador
 * @param base_name - Nombre base del scope
 * @return Nombre jerárquico completo (debe liberarse con free)
 */
char* generate_hierarchical_scope_name(NodeProcessorContext* context, const char* base_name);

/**
 * Resetea todos los contadores de scope
 * @param context - Contexto del procesador
 */
void reset_all_scope_counters(NodeProcessorContext* context);

/**
 * Entra a un scope usando el generador centralizado
 * @param context - Contexto del procesador
 * @param type - Tipo de scope
 * @param node - Nodo AST asociado
 * @return Nombre del scope creado (debe liberarse con free)
 */
char* enter_generated_scope(NodeProcessorContext* context, ScopeGeneratorType type, ASTNode* node);

/**
 * Convierte tipo de scope a string para debug
 * @param type - Tipo de scope
 * @return String representativo
 */
const char* scope_type_to_string(ScopeGeneratorType type);

#endif // SCOPE_UTILS_H