//
// Created by lightdemon on 2/09/25.
//

#ifndef TABLA_SIMBOLOS_H
#define TABLA_SIMBOLOS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#define HASH_TABLE_SIZE 101
#define MAX_ID_LENGTH 64
#define MAX_SCOPE_LENGTH 64
#define MAX_VALUE_LENGTH 64
#define MAX_TEMP_LENGTH 32
#define MAX_LABEL_LENGTH 32

typedef enum {
    SIMBOLO_VARIABLE,
    SIMBOLO_CONSTANTE,
    SIMBOLO_FUNCION,
    SIMBOLO_PARAMETRO,
    SIMBOLO_ARRAY,
    SIMBOLO_TEMPORAL,
    SIMBOLO_ETIQUETA
} TipoSimbolo;

typedef enum {
    TIPO_INT, TIPO_FLOAT, TIPO_DOUBLE, TIPO_CHAR, TIPO_STRING, TIPO_BOOLEAN, TIPO_VOID,
    TIPO_ARRAY_INT, TIPO_ARRAY_FLOAT, TIPO_ARRAY_DOUBLE, TIPO_ARRAY_CHAR, TIPO_ARRAY_STRING, TIPO_ARRAY_BOOLEAN,
    TIPO_DESCONOCIDO, TIPO_NULL,    TIPO_LONG, TIPO_SHORT, TIPO_BYTE,
} TipoDato;

typedef enum {
    VIS_PUBLIC, VIS_PRIVATE, VIS_PROTECTED, VIS_DEFAULT
} Visibilidad;

typedef struct {
    char id[MAX_ID_LENGTH];            // Identificador
    TipoSimbolo tipo_simbolo;          // Tipo de símbolo (variable, función, etc.)
    TipoDato tipo_dato;                // Tipo de dato
    char ambito[MAX_SCOPE_LENGTH];     // Ámbito
    int nivel_ambito;                  // Profundidad de ámbito (scope stack)
    int linea;                         // Línea de declaración
    int columna;                       // Columna de declaración
    int direccion;                     // Dirección/desplazamiento en memoria/código 3D
    int tamaño;                        // Tamaño del dato
    int inicializado;                  // 1 si inicializado, 0 no
    char valor[MAX_VALUE_LENGTH];      // Valor actual (si aplica)
    int num_usos;                      // Número de usos
    Visibilidad visibilidad;           // Visibilidad (public, private, etc)
    int es_parametro;                  // 1 si es parámetro, 0 si no
    int posicion_parametro;            // Posición si es parámetro
    int es_array;                      // 1 si es array/matriz
    int dimensiones;                   // Número de dimensiones (para arrays/matrices)
    int tamaños_dimensiones[4];        // Tamaños por dimensión (ej. [3][4][5])
    int es_constante;                  // 1 si es constante, 0 si no
    int es_global;                     // 1 si es variable global
    char temporal[MAX_TEMP_LENGTH];    // Nombre de temporal (para 3D)
    char etiqueta[MAX_LABEL_LENGTH];   // Nombre de etiqueta (para saltos/ensamblador)
    time_t timestamp_creacion;         // Momento de creación
    time_t timestamp_ultimo_uso;       // Última vez usado
} Simbolo;

typedef struct NodoSimbolo {
    Simbolo simbolo;
    struct NodoSimbolo* siguiente;
} NodoSimbolo;

typedef struct {
    NodoSimbolo* tabla[HASH_TABLE_SIZE];
    int num_simbolos;
    int siguiente_direccion;
    int siguiente_temporal;
    int siguiente_etiqueta;
    int nivel_ambito_actual;
    char ambito_actual[MAX_SCOPE_LENGTH];
    int nivel_anidamiento;
    int contador_simbolos;
} TablaSimbolos;

// Funciones principales
TablaSimbolos* crear_tabla_simbolos();
int insertar_simbolo(TablaSimbolos* tabla, Simbolo simbolo);
Simbolo* buscar_simbolo(TablaSimbolos* tabla, const char* id);
Simbolo* buscar_simbolo_en_ambito(TablaSimbolos* tabla, const char* id, const char* ambito);
int actualizar_valor_simbolo(TablaSimbolos* tabla, const char* id, const char* nuevo_valor);
void incrementar_uso_simbolo(TablaSimbolos* tabla, const char* id);

// Manejo de ámbitos
void cambiar_ambito(TablaSimbolos* tabla, const char* nuevo_ambito);
void entrar_ambito(TablaSimbolos* tabla, const char* nombre_ambito);
void salir_ambito(TablaSimbolos* tabla);

// Generadores
char* generar_temporal(TablaSimbolos* tabla);
char* generar_etiqueta(TablaSimbolos* tabla);

// Utilidades
int existe_simbolo(TablaSimbolos* tabla, const char* id);
int existe_simbolo_en_ambito_actual(TablaSimbolos* tabla, const char* id);
void imprimir_tabla_simbolos(TablaSimbolos* tabla);
void liberar_tabla_simbolos(TablaSimbolos* tabla);

// Funciones auxiliares
const char* tipo_simbolo_to_string(TipoSimbolo tipo);
const char* tipo_dato_to_string(TipoDato tipo);
TipoDato string_to_tipo_dato(const char* tipo_str);
const char* visibilidad_to_string(Visibilidad vis);
int calcular_tamaño_tipo(TipoDato tipo, int dimensiones, int* tamaños_dimensiones);
Simbolo crear_simbolo_default(const char* id, TipoSimbolo tipo_simbolo, TipoDato tipo_dato);
int validar_simbolo(Simbolo* simbolo);

int es_simbolo_accesible_desde_ambito_actual(TablaSimbolos* tabla, Simbolo* simbolo);
Simbolo* buscar_simbolo_en_ambito(TablaSimbolos* tabla, const char* id, const char* ambito);
int verificar_si_existe_en_otro_scope(TablaSimbolos* tabla, const char* id);
#endif // TABLA_SIMBOLOS_H