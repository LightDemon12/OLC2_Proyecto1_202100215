//
// Created by lightdemon on 4/09/25.
//

#include "FuncionManager.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// Lista dinámica para almacenar las funciones
static FuncionEntry* funciones = NULL;
static int num_funciones = 0;
static int capacidad_funciones = 0;

void inicializar_funcion_manager() {
    capacidad_funciones = 10;
    funciones = (FuncionEntry*)malloc(sizeof(FuncionEntry) * capacidad_funciones);
    num_funciones = 0;
}

int registrar_funcion(const char* nombre, ASTNode* cuerpo) {
    if (!nombre || !cuerpo) return 0;

    // Verificar si la función ya está registrada
    for (int i = 0; i < num_funciones; i++) {
        if (strcmp(funciones[i].nombre, nombre) == 0) {
            printf("ERROR: La función '%s' ya está registrada\n", nombre);
            return 0;
        }
    }

    // Expandir la lista si es necesario
    if (num_funciones >= capacidad_funciones) {
        capacidad_funciones *= 2;
        funciones = (FuncionEntry*)realloc(funciones, sizeof(FuncionEntry) * capacidad_funciones);
    }

    // Registrar la nueva función
    strncpy(funciones[num_funciones].nombre, nombre, MAX_ID_LENGTH - 1);
    funciones[num_funciones].nombre[MAX_ID_LENGTH - 1] = '\0';
    funciones[num_funciones].cuerpo = cuerpo;
    num_funciones++;

    printf("✅ Función '%s' registrada exitosamente\n", nombre);
    return 1;
}

ASTNode* obtener_cuerpo_funcion(const char* nombre) {
    if (!nombre) return NULL;

    for (int i = 0; i < num_funciones; i++) {
        if (strcmp(funciones[i].nombre, nombre) == 0) {
            return funciones[i].cuerpo;
        }
    }

    printf("ERROR: No se encontró el cuerpo de la función '%s'\n", nombre);
    return NULL;
}

void liberar_funcion_manager() {
    free(funciones);
    funciones = NULL;
    num_funciones = 0;
    capacidad_funciones = 0;
}