//
// Created by lightdemon on 4/09/25.
//

#ifndef FUNCION_MANAGER_H
#define FUNCION_MANAGER_H

#include "node_utils.h"
#include "globals.h"

// Estructura para almacenar información de las funciones
typedef struct {
    char nombre[MAX_ID_LENGTH]; // Nombre de la función
    ASTNode* cuerpo;            // Nodo del cuerpo de la función
} FuncionEntry;

// Inicializa el manejador de funciones
void inicializar_funcion_manager();

// Registra una función con su cuerpo
int registrar_funcion(const char* nombre, ASTNode* cuerpo);

// Obtiene el cuerpo de una función por su nombre
ASTNode* obtener_cuerpo_funcion(const char* nombre);

// Libera los recursos del manejador de funciones
void liberar_funcion_manager();

#endif // FUNCION_MANAGER_H