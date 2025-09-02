cmake_minimum_required(VERSION 3.16)
project(JavaLang C)

set(CMAKE_C_STANDARD 11)

# Buscar pkg-config
find_package(PkgConfig REQUIRED)

# Buscar GTK3
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)

# BUSCAR BISON Y FLEX
find_package(BISON REQUIRED)
find_package(FLEX REQUIRED)

# Configurar directorios de include
include_directories(${GTK3_INCLUDE_DIRS})
include_directories(${CMAKE_SOURCE_DIR})
include_directories(${CMAKE_SOURCE_DIR}/Headers)
include_directories(${CMAKE_SOURCE_DIR}/Logic/Analyzer)

# Configurar flags de compilación
add_compile_options(${GTK3_CFLAGS_OTHER})

# GENERAR ARCHIVOS CON BISON Y FLEX
set(PARSER_Y "${CMAKE_SOURCE_DIR}/Logic/Analyzer/parser.y")
set(LEXER_L "${CMAKE_SOURCE_DIR}/Logic/Analyzer/lexer.l")

# Generar parser con Bison
BISON_TARGET(JavaParser
        ${PARSER_Y}
        ${CMAKE_SOURCE_DIR}/Logic/Analyzer/parser.tab.c
        DEFINES_FILE ${CMAKE_SOURCE_DIR}/Logic/Analyzer/parser.tab.h
)

# Generar lexer con Flex
FLEX_TARGET(JavaLexer
        ${LEXER_L}
        ${CMAKE_SOURCE_DIR}/Logic/Analyzer/lex.yy.c
)

# Hacer que el lexer dependa del parser (necesita parser.tab.h)
ADD_FLEX_BISON_DEPENDENCY(JavaLexer JavaParser)

# DEFINIR TODAS LAS FUENTES
set(SOURCES
        main.c
        GUI/mainview.c
        Logic/Files/file_manager.c
        Logic/Files/control.c
        Utils/tokens.c
        Utils/error_manager.c
        GUI/error_report_window.c
        Logic/AST/ast.c
        # AGREGAR ARCHIVOS GENERADOS
        ${BISON_JavaParser_OUTPUTS}
        ${FLEX_JavaLexer_OUTPUTS}
        Utils/globals.c
        Headers/globals.h
        Headers/ast_visualizer.h
        Logic/AST/ast_visualizer.c
        Headers/builder_program.h
        Logic/Builders/program_builder..c
        Headers/builder_bloque_main.h
        Logic/Builders/builder_bloque_main.c
        Headers/builder_instrucciones.h
        Logic/Builders/builder_instrucciones.c
        Headers/builder_sout.h
        Logic/Builders/builder_sout.c
        Headers/builder_datos.h
        Logic/Builders/builder_datos.c
        Headers/builder_declaraciones.h
        Logic/Builders/builder_declaraciones.c
        Headers/builder_tipos_datos.h
        Logic/Builders/builder_tipos_datos.c
        Headers/builder_expresion.h
        Logic/Builders/builder_expresion.c
        Headers/builder_asignacion.h
        Logic/Builders/builder_asignacion.c
        Headers/builder_if.h
        Logic/Builders/builder_if.c
        Headers/builder_sentencias.h
        Logic/Builders/builder_sentencias.c
        Headers/builder_switch.h
        Logic/Builders/builder_switch.c
        Headers/builder_scope.h
        Logic/Builders/builder_scope.c
        Headers/builder_ciclos.h
        Logic/Builders/builder_ciclos.c
        Headers/builder_vectores.h
        Logic/Builders/builder_vectores.c
        Headers/builder_matrices.h
        Logic/Builders/builder_matrices.c
        Headers/builder_arrays_acceso.h
        Logic/Builders/builder_arrays_acceso.c
        Logic/Builders/builder_arrays_multidimensional.c
        Headers/builder_arrays_multidimensional.h
        Headers/builder_funciones.h
        Logic/Builders/builder_funciones.c
        Headers/builder_expresion_arrays.h
        Logic/Builders/builder_expresion_arrays.c
        Logic/Builders/builder_llamadas_funciones.c
        Headers/builder_llamadas_funciones.h
)

# Crear ejecutable
add_executable(JavaLang ${SOURCES})

# Configurar propiedades del target
target_include_directories(JavaLang PRIVATE
        ${GTK3_INCLUDE_DIRS}
        ${CMAKE_SOURCE_DIR}
        ${CMAKE_SOURCE_DIR}/Headers
        ${CMAKE_SOURCE_DIR}/Logic/Analyzer  # Para parser.tab.h
)

target_compile_options(JavaLang PRIVATE ${GTK3_CFLAGS_OTHER})
target_link_libraries(JavaLang ${GTK3_LIBRARIES} fl)  # ← AGREGAR fl para flex
target_link_directories(JavaLang PRIVATE ${GTK3_LIBRARY_DIRS})

# Debug info
message(STATUS "GTK3 Include Dirs: ${GTK3_INCLUDE_DIRS}")
message(STATUS "GTK3 Libraries: ${GTK3_LIBRARIES}")
message(STATUS "Bison encontrado: ${BISON_EXECUTABLE}")
message(STATUS "Flex encontrado: ${FLEX_EXECUTABLE}")
message(STATUS "Archivos del parser: ${BISON_JavaParser_OUTPUTS}")
message(STATUS "Archivos del lexer: ${FLEX_JavaLexer_OUTPUTS}")