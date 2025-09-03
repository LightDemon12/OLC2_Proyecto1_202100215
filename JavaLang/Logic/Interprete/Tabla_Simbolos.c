//
// Created by lightdemon on 02/09/25.
//

#include "../../Headers/Tabla_Simbolos.h"
#include <time.h>

// ========== IMPLEMENTACIÓN DE FUNCIONES PRINCIPALES ==========

TablaSimbolos* crear_tabla_simbolos() {
    TablaSimbolos* tabla = (TablaSimbolos*)malloc(sizeof(TablaSimbolos));
    if (!tabla) {
        printf("ERROR: No se pudo allocar memoria para la tabla de símbolos\n");
        return NULL;
    }

    // Inicializar tabla hash
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        tabla->tabla[i] = NULL;
    }

    // Inicializar contadores
    tabla->num_simbolos = 0;
    tabla->siguiente_direccion = 0;
    tabla->siguiente_temporal = 0;
    tabla->siguiente_etiqueta = 0;
    tabla->nivel_ambito_actual = 0;
    tabla->nivel_anidamiento = 0;       // AGREGAR inicialización
    tabla->contador_simbolos = 1;       // AGREGAR inicialización
    strcpy(tabla->ambito_actual, "global");

    printf("DEBUG TABLA_SIMBOLOS: Tabla de símbolos creada exitosamente\n");
    return tabla;
}

unsigned int hash_simbolo(const char* id) {
    if (!id) return 0;

    unsigned int hash = 5381;  // DJB2 hash algorithm
    int c;

    while ((c = *id++)) {
        hash = ((hash << 5) + hash) + c; // hash * 33 + c
    }

    return hash % HASH_TABLE_SIZE;
}

int insertar_simbolo(TablaSimbolos* tabla, Simbolo simbolo) {
    if (!tabla) {
        printf("ERROR TABLA_SIMBOLOS: Tabla nula\n");
        return 0;
    }

    // Validar símbolo
    if (!validar_simbolo(&simbolo)) {
        printf("ERROR TABLA_SIMBOLOS: Símbolo inválido: %s\n", simbolo.id);
        return 0;
    }

    // Verificar si ya existe en el ámbito actual
    if (existe_simbolo_en_ambito_actual(tabla, simbolo.id)) {
        printf("ERROR TABLA_SIMBOLOS: Símbolo '%s' ya existe en el ámbito '%s'\n",
               simbolo.id, tabla->ambito_actual);
        return 0;
    }

    // Crear nuevo nodo
    NodoSimbolo* nuevo = (NodoSimbolo*)malloc(sizeof(NodoSimbolo));
    if (!nuevo) {
        printf("ERROR TABLA_SIMBOLOS: No se pudo allocar memoria para el símbolo\n");
        return 0;
    }

    // Completar información del símbolo
    nuevo->simbolo = simbolo;
    strcpy(nuevo->simbolo.ambito, tabla->ambito_actual);
    nuevo->simbolo.nivel_ambito = tabla->nivel_ambito_actual;
    nuevo->simbolo.direccion = tabla->siguiente_direccion;
    nuevo->simbolo.timestamp_creacion = time(NULL);
    nuevo->simbolo.timestamp_ultimo_uso = time(NULL);

    // Calcular tamaño y actualizar dirección
    int tamaño = calcular_tamaño_tipo(simbolo.tipo_dato, simbolo.dimensiones, simbolo.tamaños_dimensiones);
    nuevo->simbolo.tamaño = tamaño;
    tabla->siguiente_direccion += tamaño;

    // Insertar en la tabla hash
    unsigned int indice = hash_simbolo(simbolo.id);
    nuevo->siguiente = tabla->tabla[indice];
    tabla->tabla[indice] = nuevo;

    tabla->num_simbolos++;

    printf("DEBUG TABLA_SIMBOLOS: Símbolo '%s' insertado en ámbito '%s' (dirección: %d, tamaño: %d)\n",
           simbolo.id, tabla->ambito_actual, nuevo->simbolo.direccion, tamaño);

    return 1;
}

Simbolo* buscar_simbolo(TablaSimbolos* tabla, const char* id) {
    if (!tabla || !id) return NULL;

    unsigned int indice = hash_simbolo(id);
    NodoSimbolo* actual = tabla->tabla[indice];

    while (actual) {
        if (strcmp(actual->simbolo.id, id) == 0) {
            actual->simbolo.num_usos++;
            actual->simbolo.timestamp_ultimo_uso = time(NULL);
            return &actual->simbolo;
        }
        actual = actual->siguiente;
    }

    return NULL;
}

Simbolo* buscar_simbolo_en_ambito(TablaSimbolos* tabla, const char* id, const char* ambito) {
    if (!tabla || !id || !ambito) return NULL;

    unsigned int indice = hash_simbolo(id);
    NodoSimbolo* actual = tabla->tabla[indice];

    while (actual) {
        if (strcmp(actual->simbolo.id, id) == 0 &&
            strcmp(actual->simbolo.ambito, ambito) == 0) {
            actual->simbolo.num_usos++;
            actual->simbolo.timestamp_ultimo_uso = time(NULL);
            return &actual->simbolo;
        }
        actual = actual->siguiente;
    }

    return NULL;
}

int actualizar_valor_simbolo(TablaSimbolos* tabla, const char* id, const char* nuevo_valor) {
    Simbolo* simbolo = buscar_simbolo(tabla, id);
    if (!simbolo) {
        printf("ERROR TABLA_SIMBOLOS: Símbolo '%s' no encontrado para actualizar\n", id);
        return 0;
    }

    strncpy(simbolo->valor, nuevo_valor, MAX_VALUE_LENGTH - 1);
    simbolo->valor[MAX_VALUE_LENGTH - 1] = '\0';
    simbolo->inicializado = 1;
    simbolo->timestamp_ultimo_uso = time(NULL);

    printf("DEBUG TABLA_SIMBOLOS: Valor de '%s' actualizado a '%s'\n", id, nuevo_valor);
    return 1;
}

void incrementar_uso_simbolo(TablaSimbolos* tabla, const char* id) {
    Simbolo* simbolo = buscar_simbolo(tabla, id);
    if (simbolo) {
        simbolo->num_usos++;
        simbolo->timestamp_ultimo_uso = time(NULL);
    }
}

void cambiar_ambito(TablaSimbolos* tabla, const char* nuevo_ambito) {
    if (!tabla || !nuevo_ambito) return;

    strncpy(tabla->ambito_actual, nuevo_ambito, MAX_SCOPE_LENGTH - 1);
    tabla->ambito_actual[MAX_SCOPE_LENGTH - 1] = '\0';

    printf("DEBUG TABLA_SIMBOLOS: Ámbito cambiado a '%s'\n", nuevo_ambito);
}

void entrar_ambito(TablaSimbolos* tabla, const char* nombre_ambito) {
    if (!tabla || !nombre_ambito) {
        printf("ERROR TABLA_SIMBOLOS: Parámetros inválidos para entrar_ambito\n");
        return;
    }

    // Incrementar nivel de anidamiento
    tabla->nivel_anidamiento++;

    // Actualizar nombre del ámbito actual
    snprintf(tabla->ambito_actual, MAX_SCOPE_LENGTH-1, "%s", nombre_ambito);
    tabla->ambito_actual[MAX_SCOPE_LENGTH-1] = '\0';

    printf("DEBUG TABLA_SIMBOLOS: Entrando a ámbito '%s' (nivel %d)\n",
           nombre_ambito, tabla->nivel_anidamiento);
}

void salir_ambito(TablaSimbolos* tabla) {
    if (!tabla) {
        printf("ERROR TABLA_SIMBOLOS: Tabla inválida para salir_ambito\n");
        return;
    }

    printf("DEBUG TABLA_SIMBOLOS: Saliendo de ámbito '%s' (nivel %d)\n",
           tabla->ambito_actual, tabla->nivel_anidamiento);

    // Decrementar nivel si no estamos en el nivel base
    if (tabla->nivel_anidamiento > 1) {
        tabla->nivel_anidamiento--;

        // Volver al ámbito padre (simplificado)
        snprintf(tabla->ambito_actual, MAX_SCOPE_LENGTH-1, "main_%d", tabla->nivel_anidamiento);
        tabla->ambito_actual[MAX_SCOPE_LENGTH-1] = '\0';
    } else {
        // Volver al ámbito global
        strcpy(tabla->ambito_actual, "global");
    }
}

char* generar_temporal(TablaSimbolos* tabla) {
    if (!tabla) return NULL;

    static char temporal[MAX_TEMP_LENGTH];
    snprintf(temporal, MAX_TEMP_LENGTH, "t%d", tabla->siguiente_temporal);

    // CREAR E INSERTAR EL SÍMBOLO TEMPORAL EN LA TABLA
    Simbolo simbolo_temporal = crear_simbolo_default(temporal, SIMBOLO_TEMPORAL, TIPO_INT);
    simbolo_temporal.linea = 0;  // Los temporales no tienen línea específica
    simbolo_temporal.columna = 0;
    simbolo_temporal.inicializado = 1;
    strcpy(simbolo_temporal.valor, "temp");

    // Insertar en la tabla
    insertar_simbolo(tabla, simbolo_temporal);

    // Incrementar contador DESPUÉS de usar el valor
    tabla->siguiente_temporal++;

    printf("DEBUG TABLA_SIMBOLOS: Temporal generado e insertado: %s\n", temporal);
    return temporal;
}

char* generar_etiqueta(TablaSimbolos* tabla) {
    if (!tabla) return NULL;

    static char etiqueta[MAX_LABEL_LENGTH];
    snprintf(etiqueta, MAX_LABEL_LENGTH, "L%d", tabla->siguiente_etiqueta);

    // CREAR E INSERTAR EL SÍMBOLO ETIQUETA EN LA TABLA
    Simbolo simbolo_etiqueta = crear_simbolo_default(etiqueta, SIMBOLO_ETIQUETA, TIPO_VOID);
    simbolo_etiqueta.linea = 0;  // Las etiquetas no tienen línea específica
    simbolo_etiqueta.columna = 0;
    simbolo_etiqueta.inicializado = 1;
    strcpy(simbolo_etiqueta.valor, "label");

    // Insertar en la tabla
    insertar_simbolo(tabla, simbolo_etiqueta);

    // Incrementar contador DESPUÉS de usar el valor
    tabla->siguiente_etiqueta++;

    printf("DEBUG TABLA_SIMBOLOS: Etiqueta generada e insertada: %s\n", etiqueta);
    return etiqueta;
}

int existe_simbolo(TablaSimbolos* tabla, const char* id) {
    return buscar_simbolo(tabla, id) != NULL;
}

int existe_simbolo_en_ambito_actual(TablaSimbolos* tabla, const char* id) {
    return buscar_simbolo_en_ambito(tabla, id, tabla->ambito_actual) != NULL;
}

void imprimir_tabla_simbolos(TablaSimbolos* tabla) {
    if (!tabla) {
        printf("ERROR: Tabla de símbolos nula\n");
        return;
    }

    printf("\n=== TABLA DE SÍMBOLOS ===\n");
    printf("Total de símbolos: %d\n", tabla->num_simbolos);
    printf("Ámbito actual: %s (nivel %d)\n", tabla->ambito_actual, tabla->nivel_ambito_actual);
    printf("Siguiente dirección: %d\n", tabla->siguiente_direccion);
    printf("Siguiente temporal: t%d\n", tabla->siguiente_temporal);
    printf("Siguiente etiqueta: L%d\n", tabla->siguiente_etiqueta);

    printf("\n%-15s %-12s %-10s %-15s %-8s %-8s %-15s %-10s\n",
           "ID", "TIPO_SIMB", "TIPO_DATO", "ÁMBITO", "LÍNEA", "DIR", "VALOR", "USOS");
    printf("%-15s %-12s %-10s %-15s %-8s %-8s %-15s %-10s\n",
           "===============", "============", "==========", "===============",
           "========", "========", "===============", "==========");

    // Primero imprimir variables y símbolos regulares
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        NodoSimbolo* actual = tabla->tabla[i];
        while (actual) {
            Simbolo* s = &actual->simbolo;
            if (s->tipo_simbolo != SIMBOLO_TEMPORAL && s->tipo_simbolo != SIMBOLO_ETIQUETA) {
                printf("%-15s %-12s %-10s %-15s %-8d %-8d %-15s %-10d\n",
                       s->id,
                       tipo_simbolo_to_string(s->tipo_simbolo),
                       tipo_dato_to_string(s->tipo_dato),
                       s->ambito,
                       s->linea,
                       s->direccion,
                       s->inicializado ? s->valor : "N/A",
                       s->num_usos);
            }
            actual = actual->siguiente;
        }
    }

    // Luego imprimir temporales y etiquetas si existen
    bool hay_temporales_etiquetas = false;
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        NodoSimbolo* actual = tabla->tabla[i];
        while (actual) {
            Simbolo* s = &actual->simbolo;
            if (s->tipo_simbolo == SIMBOLO_TEMPORAL || s->tipo_simbolo == SIMBOLO_ETIQUETA) {
                if (!hay_temporales_etiquetas) {
                    printf("\n--- TEMPORALES Y ETIQUETAS ---\n");
                    hay_temporales_etiquetas = true;
                }
                printf("%-15s %-12s %-10s %-15s %-8d %-8d %-15s %-10d\n",
                       s->id,
                       tipo_simbolo_to_string(s->tipo_simbolo),
                       tipo_dato_to_string(s->tipo_dato),
                       s->ambito,
                       s->linea,
                       s->direccion,
                       s->inicializado ? s->valor : "N/A",
                       s->num_usos);
            }
            actual = actual->siguiente;
        }
    }

    printf("=== FIN TABLA DE SÍMBOLOS ===\n\n");
}

void liberar_tabla_simbolos(TablaSimbolos* tabla) {
    if (!tabla) return;

    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        NodoSimbolo* actual = tabla->tabla[i];
        while (actual) {
            NodoSimbolo* temp = actual;
            actual = actual->siguiente;
            free(temp);
        }
    }

    free(tabla);
    printf("DEBUG TABLA_SIMBOLOS: Tabla de símbolos liberada\n");
}

// ========== FUNCIONES AUXILIARES ==========

const char* tipo_simbolo_to_string(TipoSimbolo tipo) {
    switch (tipo) {
        case SIMBOLO_VARIABLE: return "VARIABLE";
        case SIMBOLO_FUNCION: return "FUNCION";
        case SIMBOLO_PARAMETRO: return "PARAMETRO";
        case SIMBOLO_ARRAY: return "ARRAY";
        case SIMBOLO_TEMPORAL: return "TEMPORAL";
        case SIMBOLO_ETIQUETA: return "ETIQUETA";
        case SIMBOLO_CONSTANTE: return "CONSTANTE";
        default: return "DESCONOCIDO";
    }
}

const char* tipo_dato_to_string(TipoDato tipo) {
    switch(tipo) {
        case TIPO_INT: return "int";
        case TIPO_FLOAT: return "float";
        case TIPO_DOUBLE: return "double";
        case TIPO_CHAR: return "char";
        case TIPO_STRING: return "string";
        case TIPO_BOOLEAN: return "boolean";
        case TIPO_LONG: return "long";
        case TIPO_SHORT: return "short";
        case TIPO_BYTE: return "byte";
        case TIPO_VOID: return "void";
        case TIPO_NULL: return "null";        // ← AGREGAR ESTE
        case TIPO_DESCONOCIDO: return "desconocido";
        default: return "tipo_invalido";
    }
}

TipoDato string_to_tipo_dato(const char* tipo_str) {
    if (!tipo_str) return TIPO_DESCONOCIDO;

    if (strcmp(tipo_str, "int") == 0) return TIPO_INT;
    if (strcmp(tipo_str, "float") == 0) return TIPO_FLOAT;
    if (strcmp(tipo_str, "double") == 0) return TIPO_DOUBLE;
    if (strcmp(tipo_str, "long") == 0) return TIPO_LONG;
    if (strcmp(tipo_str, "string") == 0) return TIPO_STRING;
    if (strcmp(tipo_str, "char") == 0) return TIPO_CHAR;
    if (strcmp(tipo_str, "boolean") == 0) return TIPO_BOOLEAN;
    if (strcmp(tipo_str, "void") == 0) return TIPO_VOID;
    if (strcmp(tipo_str, "short") == 0) return TIPO_SHORT;
    if (strcmp(tipo_str, "byte") == 0) return TIPO_BYTE;
    return TIPO_DESCONOCIDO;
}

const char* visibilidad_to_string(Visibilidad vis) {
    switch (vis) {
        case VIS_PUBLIC: return "public";
        case VIS_PRIVATE: return "private";
        case VIS_PROTECTED: return "protected";
        case VIS_DEFAULT: return "default";
        default: return "default";
    }
}

int calcular_tamaño_tipo(TipoDato tipo, int dimensiones, int* tamaños_dimensiones) {
    int tamaño_base = 0;

    switch (tipo) {
        case TIPO_INT:
        case TIPO_ARRAY_INT:
            tamaño_base = 4;
            break;
        case TIPO_FLOAT:
        case TIPO_ARRAY_FLOAT:
            tamaño_base = 4;
            break;
        case TIPO_DOUBLE:
        case TIPO_ARRAY_DOUBLE:
            tamaño_base = 8;
            break;
        case TIPO_CHAR:
        case TIPO_ARRAY_CHAR:
            tamaño_base = 1;
            break;
        case TIPO_BOOLEAN:
        case TIPO_ARRAY_BOOLEAN:
            tamaño_base = 1;
            break;
        case TIPO_STRING:
        case TIPO_ARRAY_STRING:
            tamaño_base = 8; // Puntero
            break;
        default:
            tamaño_base = 4;
    }

    // Si es array, multiplicar por las dimensiones
    if (dimensiones > 0 && tamaños_dimensiones) {
        int tamaño_total = tamaño_base;
        for (int i = 0; i < dimensiones; i++) {
            tamaño_total *= tamaños_dimensiones[i];
        }
        return tamaño_total;
    }

    return tamaño_base;
}

Simbolo crear_simbolo_default(const char* id, TipoSimbolo tipo_simbolo, TipoDato tipo_dato) {
    Simbolo simbolo = {0};  // Inicializar toda la estructura a 0

    strncpy(simbolo.id, id, MAX_ID_LENGTH - 1);
    simbolo.tipo_simbolo = tipo_simbolo;
    simbolo.tipo_dato = tipo_dato;
    simbolo.inicializado = 0;
    simbolo.num_usos = 0;
    simbolo.es_parametro = 0;
    simbolo.posicion_parametro = -1;
    simbolo.visibilidad = VIS_DEFAULT;
    simbolo.es_array = 0;
    simbolo.dimensiones = 0;
    simbolo.es_constante = 0;
    simbolo.es_global = 0;

    return simbolo;
}

int validar_simbolo(Simbolo* simbolo) {
    if (!simbolo) return 0;
    if (strlen(simbolo->id) == 0) return 0;
    if (strlen(simbolo->id) >= MAX_ID_LENGTH) return 0;

    return 1;
}

