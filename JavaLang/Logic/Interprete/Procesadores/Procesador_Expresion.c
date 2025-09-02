//
// Created by lightdemon on 2/09/25.
//
#include "../../../Headers/Procesador_Expresion.h"
#include "../../../Headers/Procesador_Suma.h"
#include "../../Headers/mainview.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* process_expresion_node(NodeProcessorContext* context, ASTNode* node) {
    if (!context || !node) {
        printf("ERROR PROCESADOR_EXPRESION: Contexto o nodo NULL\n");
        return NULL;
    }

    if (context->modo_debug) {
        printf("DEBUG PROCESADOR_EXPRESION: Procesando '%s' en línea %d\n",
               node->type, node->line);
    }

    // Delegar según el tipo de expresión
    if (strcmp(node->type, "EXPRESION_BINARIA") == 0) {

        // Verificar qué operador es
        if (node->value && strcmp(node->value, "+") == 0) {
            if (context->modo_debug) {
                printf("DEBUG PROCESADOR_EXPRESION: → Delegando suma a Procesador_Suma\n");
            }
            return process_suma_node(context, node);
        }
        else {
            printf("ERROR PROCESADOR_EXPRESION: Operador binario '%s' no implementado\n",
                   node->value ? node->value : "NULL");
            return NULL;
        }
    }
    else if (strcmp(node->type, "DATO") == 0) {
        // Los DATO son valores literales, extraer su valor directo
        if (node->child_count > 0 && node->children[0]) {
            ASTNode* literal = node->children[0];
            if (literal->value) {
                char* resultado = malloc(strlen(literal->value) + 1);
                strcpy(resultado, literal->value);

                if (context->modo_debug) {
                    printf("DEBUG PROCESADOR_EXPRESION: → Literal extraído: '%s'\n", resultado);
                }
                return resultado;
            }
        }
        return NULL;
    }
    else if (strcmp(node->type, "IDENTIFIER") == 0) {
        // Para identificadores, por ahora retornamos el nombre
        // TODO: Buscar en tabla de símbolos y retornar su valor
        if (node->value) {
            char* resultado = malloc(strlen(node->value) + 1);
            strcpy(resultado, node->value);

            if (context->modo_debug) {
                printf("DEBUG PROCESADOR_EXPRESION: → Identificador: '%s'\n", resultado);
            }
            return resultado;
        }
        return NULL;
    }
    else {
        printf("ERROR PROCESADOR_EXPRESION: Tipo de expresión no implementado: '%s'\n", node->type);
        return NULL;
    }
}

int is_expresion_node(const char* node_type) {
    if (!node_type) return 0;

    return (strcmp(node_type, "EXPRESION_BINARIA") == 0 ||
            strcmp(node_type, "EXPRESION_UNARIA") == 0 ||
            strcmp(node_type, "EXPRESION_POSTFIJO") == 0 ||
            strcmp(node_type, "EXPRESION_PARENTESIS") == 0 ||
            strcmp(node_type, "DATO") == 0 ||
            strcmp(node_type, "IDENTIFIER") == 0);
}