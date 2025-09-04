//
// Created by lightdemon on 4/09/25.
//
#ifndef FUNCION_INFO_H
#define FUNCION_INFO_H

#include "Tabla_Simbolos.h"

typedef struct {
    char nombre[MAX_ID_LENGTH];       // Nombre de la función
    TipoDato tipo_retorno;            // Tipo de dato de retorno
    int num_parametros;               // Número de parámetros
    Simbolo parametros[10];           // Lista de parámetros (máximo 10)
    struct ASTNode* cuerpo;           // Nodo del cuerpo de la función
    char ambito[MAX_SCOPE_LENGTH];    // Ámbito de la función
} FuncionInfo;

#endif // FUNCION_INFO_H