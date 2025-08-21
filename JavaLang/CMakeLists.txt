cmake_minimum_required(VERSION 3.16)
project(JavaLang C)

set(CMAKE_C_STANDARD 11)

# Buscar pkg-config
find_package(PkgConfig REQUIRED)

# Buscar GTK3
pkg_check_modules(GTK3 REQUIRED gtk+-3.0)

# Configurar directorios de include
include_directories(${GTK3_INCLUDE_DIRS})
include_directories(${CMAKE_SOURCE_DIR})
include_directories(${CMAKE_SOURCE_DIR}/Headers)

# Configurar flags de compilación
add_compile_options(${GTK3_CFLAGS_OTHER})

# Crear ejecutable
add_executable(JavaLang
        main.c
        GUI/mainview.c
        Headers/file_manager.h
        Logic/Files/file_manager.c
        Headers/tokens.h
        Logic/Files/control.c
        Headers/control.h
        Utils/tokens.c
        Headers/error_manager.h
        Utils/error_manager.c
        Headers/error_report_window.h
        GUI/error_report_window.c
)

# Configurar propiedades del target
target_include_directories(JavaLang PRIVATE
        ${GTK3_INCLUDE_DIRS}
        ${CMAKE_SOURCE_DIR}
        ${CMAKE_SOURCE_DIR}/Headers
)

target_compile_options(JavaLang PRIVATE ${GTK3_CFLAGS_OTHER})
target_link_libraries(JavaLang ${GTK3_LIBRARIES})
target_link_directories(JavaLang PRIVATE ${GTK3_LIBRARY_DIRS})

# Debug info
message(STATUS "GTK3 Include Dirs: ${GTK3_INCLUDE_DIRS}")
message(STATUS "GTK3 Libraries: ${GTK3_LIBRARIES}")