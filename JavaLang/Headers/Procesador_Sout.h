//
// Created by lightdemon on 3/09/25.
//

#ifndef PROCESADOR_SOUT_H
#define PROCESADOR_SOUT_H

#include "node_processor.h"
#include "Tabla_Simbolos.h"
#include "ast.h"

// ===== TIPOS DE RESULTADO SOUT =====
typedef struct {
    char* contenido_impreso;
    int exitoso;
    int linea;
    TipoDato tipo_final;
} ResultadoSout;

// ===== FUNCIONES PRINCIPALES =====
char* process_sout_node(NodeProcessorContext* context, ASTNode* node);
ResultadoSout evaluar_sout_completo(NodeProcessorContext* context, ASTNode* node);

// ===== FUNCIONES AUXILIARES =====
char* evaluar_expresion_para_sout(NodeProcessorContext* context, ASTNode* expresion);
char* convertir_a_string_para_sout(const char* valor, TipoDato tipo);
char* procesar_concatenacion_sout(NodeProcessorContext* context, ASTNode* expr_binaria);
char* procesar_array_acceso_sout(NodeProcessorContext* context, ASTNode* array_node);

// ===== FUNCIONES DE DEBUG =====
void debug_sout_inicio(NodeProcessorContext* context, ASTNode* node);
void debug_sout_resultado(NodeProcessorContext* context, const char* resultado);
void debug_sout_error(NodeProcessorContext* context, const char* mensaje);

// ===== FUNCIONES DE VALIDACIÓN =====
int validar_nodo_sout(ASTNode* node);
int es_expresion_valida_para_sout(ASTNode* expresion);

// ===== LIBERACIÓN DE MEMORIA =====
void liberar_resultado_sout(ResultadoSout* resultado);

#endif // PROCESADOR_SOUT_H