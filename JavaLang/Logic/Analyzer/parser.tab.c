/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../Headers/error_manager.h"
#include "../../Headers/ast.h"
#include "../../Headers/builder_program.h"
#include "../../Headers/builder_bloque_main.h"
#include "../../Headers/builder_instrucciones.h"
#include "../../Headers/builder_sout.h"
#include "../../Headers/builder_declaraciones.h" 
#include "../../Headers/builder_tipos_datos.h" 
#include "../../Headers/builder_expresion.h"
#include "../../Headers/builder_asignacion.h" 
#include "../../Headers/builder_if.h" 
#include "../../Headers/builder_sentencias.h"  
#include "../../Headers/builder_switch.h"      
#include "../../Headers/builder_scope.h" 
#include "../../Headers/builder_ciclos.h" 
#include "../../Headers/builder_datos.h" 
#include "../../Headers/builder_vectores.h" 
#include "../../Headers/builder_matrices.h" 
#include "../../Headers/builder_arrays_acceso.h" 
#include "../../Headers/builder_arrays_multidimensional.h"
#include "../../Headers/builder_funciones.h"
#include "../../Headers/builder_expresion_arrays.h"
#include "../../Headers/builder_llamadas_funciones.h"
#include "../../Headers/builder_embebidas.h" 

/* DECLARAR COMO EXTERNAS - NO DEFINIR AQUÍ */
extern ASTNode* ast_root;
extern ErrorManager* global_error_manager;

/* DECLARACIONES MÍNIMAS */
extern int yylex();
extern int yylineno;
extern char* yytext;
extern FILE* yyin;

/* FUNCIÓN DE ERROR */
void yyerror(const char* s);

#line 114 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_TOKEN_INT = 3,                  /* TOKEN_INT  */
  YYSYMBOL_TOKEN_FLOAT = 4,                /* TOKEN_FLOAT  */
  YYSYMBOL_TOKEN_STRING = 5,               /* TOKEN_STRING  */
  YYSYMBOL_TOKEN_CHAR = 6,                 /* TOKEN_CHAR  */
  YYSYMBOL_TOKEN_BOOLEAN = 7,              /* TOKEN_BOOLEAN  */
  YYSYMBOL_TOKEN_DOUBLE = 8,               /* TOKEN_DOUBLE  */
  YYSYMBOL_TOKEN_LONG = 9,                 /* TOKEN_LONG  */
  YYSYMBOL_TOKEN_SHORT = 10,               /* TOKEN_SHORT  */
  YYSYMBOL_TOKEN_BYTE = 11,                /* TOKEN_BYTE  */
  YYSYMBOL_TOKEN_EQUALS = 12,              /* TOKEN_EQUALS  */
  YYSYMBOL_TOKEN_NEW = 13,                 /* TOKEN_NEW  */
  YYSYMBOL_TOKEN_PUBLIC = 14,              /* TOKEN_PUBLIC  */
  YYSYMBOL_TOKEN_STATIC = 15,              /* TOKEN_STATIC  */
  YYSYMBOL_TOKEN_VOID = 16,                /* TOKEN_VOID  */
  YYSYMBOL_TOKEN_MAIN = 17,                /* TOKEN_MAIN  */
  YYSYMBOL_TOKEN_NULL = 18,                /* TOKEN_NULL  */
  YYSYMBOL_TOKEN_IDENTIFIER = 19,          /* TOKEN_IDENTIFIER  */
  YYSYMBOL_TOKEN_PLUS = 20,                /* TOKEN_PLUS  */
  YYSYMBOL_TOKEN_MINUS = 21,               /* TOKEN_MINUS  */
  YYSYMBOL_TOKEN_MULTIPLICATION = 22,      /* TOKEN_MULTIPLICATION  */
  YYSYMBOL_TOKEN_DIVISION = 23,            /* TOKEN_DIVISION  */
  YYSYMBOL_TOKEN_MODULE = 24,              /* TOKEN_MODULE  */
  YYSYMBOL_TOKEN_PLUS_ASSIGN = 25,         /* TOKEN_PLUS_ASSIGN  */
  YYSYMBOL_TOKEN_MINUS_ASSIGN = 26,        /* TOKEN_MINUS_ASSIGN  */
  YYSYMBOL_TOKEN_MULT_ASSIGN = 27,         /* TOKEN_MULT_ASSIGN  */
  YYSYMBOL_TOKEN_DIV_ASSIGN = 28,          /* TOKEN_DIV_ASSIGN  */
  YYSYMBOL_TOKEN_MOD_ASSIGN = 29,          /* TOKEN_MOD_ASSIGN  */
  YYSYMBOL_TOKEN_AND_ASSIGN = 30,          /* TOKEN_AND_ASSIGN  */
  YYSYMBOL_TOKEN_OR_ASSIGN = 31,           /* TOKEN_OR_ASSIGN  */
  YYSYMBOL_TOKEN_XOR_ASSIGN = 32,          /* TOKEN_XOR_ASSIGN  */
  YYSYMBOL_TOKEN_SHIFT_LEFT_ASSIGN = 33,   /* TOKEN_SHIFT_LEFT_ASSIGN  */
  YYSYMBOL_TOKEN_SHIFT_RIGHT_ASSIGN = 34,  /* TOKEN_SHIFT_RIGHT_ASSIGN  */
  YYSYMBOL_TOKEN_ASSIGN = 35,              /* TOKEN_ASSIGN  */
  YYSYMBOL_TOKEN_EQUAL = 36,               /* TOKEN_EQUAL  */
  YYSYMBOL_TOKEN_UNEQUAL = 37,             /* TOKEN_UNEQUAL  */
  YYSYMBOL_TOKEN_GREATER = 38,             /* TOKEN_GREATER  */
  YYSYMBOL_TOKEN_LESS = 39,                /* TOKEN_LESS  */
  YYSYMBOL_TOKEN_GREATER_EQUAL = 40,       /* TOKEN_GREATER_EQUAL  */
  YYSYMBOL_TOKEN_LESS_EQUAL = 41,          /* TOKEN_LESS_EQUAL  */
  YYSYMBOL_TOKEN_AND = 42,                 /* TOKEN_AND  */
  YYSYMBOL_TOKEN_OR = 43,                  /* TOKEN_OR  */
  YYSYMBOL_TOKEN_NOT = 44,                 /* TOKEN_NOT  */
  YYSYMBOL_TOKEN_PAREN_LEFT = 45,          /* TOKEN_PAREN_LEFT  */
  YYSYMBOL_TOKEN_PAREN_RIGHT = 46,         /* TOKEN_PAREN_RIGHT  */
  YYSYMBOL_TOKEN_SEMICOLON = 47,           /* TOKEN_SEMICOLON  */
  YYSYMBOL_TOKEN_DOT = 48,                 /* TOKEN_DOT  */
  YYSYMBOL_TOKEN_COMMA = 49,               /* TOKEN_COMMA  */
  YYSYMBOL_TOKEN_BRACE_LEFT = 50,          /* TOKEN_BRACE_LEFT  */
  YYSYMBOL_TOKEN_BRACE_RIGHT = 51,         /* TOKEN_BRACE_RIGHT  */
  YYSYMBOL_TOKEN_BRACKET_LEFT = 52,        /* TOKEN_BRACKET_LEFT  */
  YYSYMBOL_TOKEN_BRACKET_RIGHT = 53,       /* TOKEN_BRACKET_RIGHT  */
  YYSYMBOL_TOKEN_QUOTE_DOUBLE = 54,        /* TOKEN_QUOTE_DOUBLE  */
  YYSYMBOL_TOKEN_QUOTE_SINGLE = 55,        /* TOKEN_QUOTE_SINGLE  */
  YYSYMBOL_TOKEN_COLON = 56,               /* TOKEN_COLON  */
  YYSYMBOL_TOKEN_IF = 57,                  /* TOKEN_IF  */
  YYSYMBOL_TOKEN_ELSE = 58,                /* TOKEN_ELSE  */
  YYSYMBOL_TOKEN_SWITCH = 59,              /* TOKEN_SWITCH  */
  YYSYMBOL_TOKEN_CASE = 60,                /* TOKEN_CASE  */
  YYSYMBOL_TOKEN_DEFAULT = 61,             /* TOKEN_DEFAULT  */
  YYSYMBOL_TOKEN_WHILE = 62,               /* TOKEN_WHILE  */
  YYSYMBOL_TOKEN_DO = 63,                  /* TOKEN_DO  */
  YYSYMBOL_TOKEN_FOR = 64,                 /* TOKEN_FOR  */
  YYSYMBOL_TOKEN_BREAK = 65,               /* TOKEN_BREAK  */
  YYSYMBOL_TOKEN_CONTINUE = 66,            /* TOKEN_CONTINUE  */
  YYSYMBOL_TOKEN_RETURN = 67,              /* TOKEN_RETURN  */
  YYSYMBOL_TOKEN_SOUT = 68,                /* TOKEN_SOUT  */
  YYSYMBOL_TOKEN_PARSEINT = 69,            /* TOKEN_PARSEINT  */
  YYSYMBOL_TOKEN_PARSEFLOAT = 70,          /* TOKEN_PARSEFLOAT  */
  YYSYMBOL_TOKEN_PARSEDOUBLE = 71,         /* TOKEN_PARSEDOUBLE  */
  YYSYMBOL_TOKEN_VALUEOF = 72,             /* TOKEN_VALUEOF  */
  YYSYMBOL_TOKEN_STRINGJOIN = 73,          /* TOKEN_STRINGJOIN  */
  YYSYMBOL_TOKEN_INDEXOF = 74,             /* TOKEN_INDEXOF  */
  YYSYMBOL_TOKEN_LENGTH = 75,              /* TOKEN_LENGTH  */
  YYSYMBOL_TOKEN_ADD = 76,                 /* TOKEN_ADD  */
  YYSYMBOL_TOKEN_ESCAPE = 77,              /* TOKEN_ESCAPE  */
  YYSYMBOL_TOKEN_INCREMENT = 78,           /* TOKEN_INCREMENT  */
  YYSYMBOL_TOKEN_DECREMENT = 79,           /* TOKEN_DECREMENT  */
  YYSYMBOL_TOKEN_EOF = 80,                 /* TOKEN_EOF  */
  YYSYMBOL_TOKEN_ERROR = 81,               /* TOKEN_ERROR  */
  YYSYMBOL_TOKEN_TYPE_INT = 82,            /* TOKEN_TYPE_INT  */
  YYSYMBOL_TOKEN_TYPE_FLOAT = 83,          /* TOKEN_TYPE_FLOAT  */
  YYSYMBOL_TOKEN_TYPE_STRING = 84,         /* TOKEN_TYPE_STRING  */
  YYSYMBOL_TOKEN_TYPE_CHAR = 85,           /* TOKEN_TYPE_CHAR  */
  YYSYMBOL_TOKEN_TYPE_TRUE = 86,           /* TOKEN_TYPE_TRUE  */
  YYSYMBOL_TOKEN_TYPE_FALSE = 87,          /* TOKEN_TYPE_FALSE  */
  YYSYMBOL_YYACCEPT = 88,                  /* $accept  */
  YYSYMBOL_program = 89,                   /* program  */
  YYSYMBOL_bloque_main = 90,               /* bloque_main  */
  YYSYMBOL_instrucciones = 91,             /* instrucciones  */
  YYSYMBOL_instruccion = 92,               /* instruccion  */
  YYSYMBOL_expresion = 93,                 /* expresion  */
  YYSYMBOL_declaraciones = 94,             /* declaraciones  */
  YYSYMBOL_asignacion_compuesta = 95,      /* asignacion_compuesta  */
  YYSYMBOL_operador_asignacion = 96,       /* operador_asignacion  */
  YYSYMBOL_tipo = 97,                      /* tipo  */
  YYSYMBOL_dato = 98,                      /* dato  */
  YYSYMBOL_lista_declaraciones = 99,       /* lista_declaraciones  */
  YYSYMBOL_lista_declaracion = 100,        /* lista_declaracion  */
  YYSYMBOL_sout = 101,                     /* sout  */
  YYSYMBOL_sentencia_if = 102,             /* sentencia_if  */
  YYSYMBOL_if_simple = 103,                /* if_simple  */
  YYSYMBOL_if_con_else = 104,              /* if_con_else  */
  YYSYMBOL_if_con_else_if = 105,           /* if_con_else_if  */
  YYSYMBOL_lista_else_if = 106,            /* lista_else_if  */
  YYSYMBOL_lista_else_if_sin_llaves = 107, /* lista_else_if_sin_llaves  */
  YYSYMBOL_else_if = 108,                  /* else_if  */
  YYSYMBOL_else_if_sin_llaves = 109,       /* else_if_sin_llaves  */
  YYSYMBOL_sentencias = 110,               /* sentencias  */
  YYSYMBOL_sentencia_switch = 111,         /* sentencia_switch  */
  YYSYMBOL_lista_case = 112,               /* lista_case  */
  YYSYMBOL_case = 113,                     /* case  */
  YYSYMBOL_ciclo_while = 114,              /* ciclo_while  */
  YYSYMBOL_ciclo_do = 115,                 /* ciclo_do  */
  YYSYMBOL_ciclo_for = 116,                /* ciclo_for  */
  YYSYMBOL_inicializacion_for = 117,       /* inicializacion_for  */
  YYSYMBOL_actualizar_for = 118,           /* actualizar_for  */
  YYSYMBOL_arrays = 119,                   /* arrays  */
  YYSYMBOL_contenido_vector = 120,         /* contenido_vector  */
  YYSYMBOL_lista_expresiones = 121,        /* lista_expresiones  */
  YYSYMBOL_arrays_acceso = 122,            /* arrays_acceso  */
  YYSYMBOL_brackets_indices = 123,         /* brackets_indices  */
  YYSYMBOL_arrays_asignacion = 124,        /* arrays_asignacion  */
  YYSYMBOL_brackets = 125,                 /* brackets  */
  YYSYMBOL_brackets_new = 126,             /* brackets_new  */
  YYSYMBOL_TOKEN_brace_block = 127,        /* TOKEN_brace_block  */
  YYSYMBOL_brace_elements = 128,           /* brace_elements  */
  YYSYMBOL_brace_element = 129,            /* brace_element  */
  YYSYMBOL_funcion = 130,                  /* funcion  */
  YYSYMBOL_parametros = 131,               /* parametros  */
  YYSYMBOL_parametro = 132,                /* parametro  */
  YYSYMBOL_bloque_funcion = 133,           /* bloque_funcion  */
  YYSYMBOL_cuerpo_funcion = 134,           /* cuerpo_funcion  */
  YYSYMBOL_elemento_funcion = 135,         /* elemento_funcion  */
  YYSYMBOL_argumentos = 136,               /* argumentos  */
  YYSYMBOL_embebidas = 137,                /* embebidas  */
  YYSYMBOL_parseint_embebida = 138,        /* parseint_embebida  */
  YYSYMBOL_parsedouble_embebida = 139,     /* parsedouble_embebida  */
  YYSYMBOL_parsefloat_embebida = 140,      /* parsefloat_embebida  */
  YYSYMBOL_valueof_embebida = 141,         /* valueof_embebida  */
  YYSYMBOL_indexof_embebida = 142,         /* indexof_embebida  */
  YYSYMBOL_length_embebida = 143,          /* length_embebida  */
  YYSYMBOL_add_embebida = 144,             /* add_embebida  */
  YYSYMBOL_join_embebida = 145             /* join_embebida  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if 1

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   3446

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  88
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  58
/* YYNRULES -- Number of rules.  */
#define YYNRULES  180
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  397

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   342


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   212,   212,   220,   227,   231,   238,   242,   246,   250,
     254,   258,   262,   266,   270,   274,   278,   282,   286,   290,
     294,   301,   305,   309,   315,   319,   323,   327,   331,   337,
     341,   347,   351,   355,   359,   365,   369,   375,   379,   383,
     387,   393,   398,   405,   411,   417,   424,   430,   436,   443,
     447,   451,   458,   463,   468,   476,   480,   484,   488,   492,
     496,   500,   504,   508,   512,   516,   524,   528,   532,   536,
     540,   544,   548,   552,   556,   560,   567,   571,   575,   579,
     583,   587,   591,   598,   602,   609,   616,   623,   627,   631,
     639,   644,   652,   657,   662,   667,   675,   680,   685,   692,
     696,   704,   708,   716,   724,   731,   735,   739,   743,   750,
     757,   761,   768,   772,   779,   786,   793,   797,   804,   808,
     812,   817,   823,   828,   835,   840,   845,   851,   859,   863,
     870,   874,   881,   885,   892,   896,   903,   907,   911,   920,
     924,   932,   936,   944,   952,   956,   963,   967,   974,   982,
     986,   991,   998,  1002,  1009,  1016,  1020,  1025,  1031,  1035,
    1043,  1047,  1052,  1058,  1062,  1066,  1070,  1074,  1078,  1082,
    1086,  1094,  1099,  1106,  1113,  1120,  1127,  1134,  1141,  1149,
    1153
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "TOKEN_INT",
  "TOKEN_FLOAT", "TOKEN_STRING", "TOKEN_CHAR", "TOKEN_BOOLEAN",
  "TOKEN_DOUBLE", "TOKEN_LONG", "TOKEN_SHORT", "TOKEN_BYTE",
  "TOKEN_EQUALS", "TOKEN_NEW", "TOKEN_PUBLIC", "TOKEN_STATIC",
  "TOKEN_VOID", "TOKEN_MAIN", "TOKEN_NULL", "TOKEN_IDENTIFIER",
  "TOKEN_PLUS", "TOKEN_MINUS", "TOKEN_MULTIPLICATION", "TOKEN_DIVISION",
  "TOKEN_MODULE", "TOKEN_PLUS_ASSIGN", "TOKEN_MINUS_ASSIGN",
  "TOKEN_MULT_ASSIGN", "TOKEN_DIV_ASSIGN", "TOKEN_MOD_ASSIGN",
  "TOKEN_AND_ASSIGN", "TOKEN_OR_ASSIGN", "TOKEN_XOR_ASSIGN",
  "TOKEN_SHIFT_LEFT_ASSIGN", "TOKEN_SHIFT_RIGHT_ASSIGN", "TOKEN_ASSIGN",
  "TOKEN_EQUAL", "TOKEN_UNEQUAL", "TOKEN_GREATER", "TOKEN_LESS",
  "TOKEN_GREATER_EQUAL", "TOKEN_LESS_EQUAL", "TOKEN_AND", "TOKEN_OR",
  "TOKEN_NOT", "TOKEN_PAREN_LEFT", "TOKEN_PAREN_RIGHT", "TOKEN_SEMICOLON",
  "TOKEN_DOT", "TOKEN_COMMA", "TOKEN_BRACE_LEFT", "TOKEN_BRACE_RIGHT",
  "TOKEN_BRACKET_LEFT", "TOKEN_BRACKET_RIGHT", "TOKEN_QUOTE_DOUBLE",
  "TOKEN_QUOTE_SINGLE", "TOKEN_COLON", "TOKEN_IF", "TOKEN_ELSE",
  "TOKEN_SWITCH", "TOKEN_CASE", "TOKEN_DEFAULT", "TOKEN_WHILE", "TOKEN_DO",
  "TOKEN_FOR", "TOKEN_BREAK", "TOKEN_CONTINUE", "TOKEN_RETURN",
  "TOKEN_SOUT", "TOKEN_PARSEINT", "TOKEN_PARSEFLOAT", "TOKEN_PARSEDOUBLE",
  "TOKEN_VALUEOF", "TOKEN_STRINGJOIN", "TOKEN_INDEXOF", "TOKEN_LENGTH",
  "TOKEN_ADD", "TOKEN_ESCAPE", "TOKEN_INCREMENT", "TOKEN_DECREMENT",
  "TOKEN_EOF", "TOKEN_ERROR", "TOKEN_TYPE_INT", "TOKEN_TYPE_FLOAT",
  "TOKEN_TYPE_STRING", "TOKEN_TYPE_CHAR", "TOKEN_TYPE_TRUE",
  "TOKEN_TYPE_FALSE", "$accept", "program", "bloque_main", "instrucciones",
  "instruccion", "expresion", "declaraciones", "asignacion_compuesta",
  "operador_asignacion", "tipo", "dato", "lista_declaraciones",
  "lista_declaracion", "sout", "sentencia_if", "if_simple", "if_con_else",
  "if_con_else_if", "lista_else_if", "lista_else_if_sin_llaves", "else_if",
  "else_if_sin_llaves", "sentencias", "sentencia_switch", "lista_case",
  "case", "ciclo_while", "ciclo_do", "ciclo_for", "inicializacion_for",
  "actualizar_for", "arrays", "contenido_vector", "lista_expresiones",
  "arrays_acceso", "brackets_indices", "arrays_asignacion", "brackets",
  "brackets_new", "TOKEN_brace_block", "brace_elements", "brace_element",
  "funcion", "parametros", "parametro", "bloque_funcion", "cuerpo_funcion",
  "elemento_funcion", "argumentos", "embebidas", "parseint_embebida",
  "parsedouble_embebida", "parsefloat_embebida", "valueof_embebida",
  "indexof_embebida", "length_embebida", "add_embebida", "join_embebida", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-257)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-113)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      -4,     5,    31,  -257,    22,  -257,    39,    19,    23,    33,
    1618,  -257,  -257,  -257,  -257,  -257,  -257,  -257,  -257,  -257,
    -257,  -257,   211,  1734,  1734,  1734,    59,    60,    72,    34,
      79,    94,   105,   231,    90,   112,   115,   117,   119,   120,
     136,  1734,  1734,  -257,  -257,  -257,  -257,  -257,  -257,     8,
    -257,  1887,  -257,  -257,   -12,  -257,  -257,  -257,  -257,  -257,
    -257,  -257,  -257,  -257,  -257,  -257,  -257,  -257,  -257,  -257,
    3329,  -257,  -257,  -257,  -257,  -257,  -257,  -257,  -257,   139,
    -257,  -257,  -257,  -257,  -257,  -257,  -257,  -257,  -257,  -257,
    -257,  1734,  1734,  1734,  -257,  -257,  1734,   433,    10,   109,
    -257,   180,  1928,  1734,  1734,  1734,  1618,   600,  -257,  -257,
    -257,  1969,  1734,  1734,  1734,  1734,  1734,  1734,  1734,   180,
     180,  -257,  -257,   148,  1734,  1734,  1734,  1734,  1734,  1734,
    1734,  1734,  1734,  1734,  1734,  1734,  1734,  -257,  -257,   149,
       2,    98,     1,  -257,  1734,  3370,    11,  3370,  2010,  2052,
     434,  -257,  1734,  1734,  1734,   145,  -257,  2093,  2134,  2175,
     104,   847,  3370,   179,   152,  -257,  2216,  1846,  2257,  2298,
    2339,  2380,  2421,  1734,   109,   109,   180,   180,   180,   618,
     618,   204,   204,   204,   204,   106,   547,  1734,  1778,  1078,
    -257,   150,   -27,   182,  -257,   191,  2462,  -257,  1734,  1045,
    -257,  2503,  2544,  2586,  2627,   644,   161,   162,   167,  1734,
     -26,  1734,   183,  -257,  1734,  -257,  -257,  -257,  1734,  1734,
    2669,  2710,   287,  2751,   213,    70,  -257,  -257,    -8,   195,
     216,   218,  -257,  -257,  3370,  -257,  1734,  -257,  -257,  -257,
    -257,  1618,   196,   198,  1618,   210,  3370,  1734,   243,  2792,
    -257,  2833,  2874,    88,  2915,  -257,  -257,  1734,   -11,  -257,
     214,   215,  1078,  1078,   135,   221,  -257,    -7,  1734,  2956,
     729,   760,   212,  -257,    15,   -28,  -257,   845,  1734,  3370,
     223,  1734,  -257,  -257,  -257,  1734,  -257,  2997,  -257,   219,
    1618,  -257,  -257,   220,  3370,   224,  -257,    12,  -257,  -257,
    1078,  1734,  3370,  -257,   227,  1618,   229,  -257,  1703,  -257,
     225,  -257,  -257,  -257,  3039,   232,  3370,   233,  3370,   230,
    -257,  -257,   930,  -257,  1734,    -1,  1734,   135,  -257,   234,
    3370,    89,   961,   235,  -257,  1046,  1734,  -257,  1618,   240,
    1618,   241,  -257,  -257,  -257,  3080,  -257,  1734,  3370,  -257,
    1734,   245,  1618,   249,  -257,   -29,  -257,  -257,  3122,  1618,
    -257,  1131,  1618,  -257,  3163,  3205,  -257,  1216,  1734,  1618,
     251,   644,   -16,  -257,  1301,  -257,   250,  -257,  3247,  1386,
    1734,   196,   252,  -257,  -257,  1417,  -257,  3288,  1618,  1618,
     256,  1618,  1502,  1618,   227,  1587,  -257
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     0,     1,     0,     0,     0,     0,
       0,    67,    68,    66,    69,    70,    71,    72,    73,    74,
      75,    82,    48,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    77,    78,    76,    79,    80,    81,     0,
       4,     0,     7,     8,     0,    47,     6,    10,    87,    88,
      89,    19,    11,    12,    13,    14,    15,    16,    17,    18,
      20,   163,   165,   164,   166,   167,   168,   169,   170,     0,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,   162,     0,     0,    41,    42,     0,    44,    48,    40,
      21,    37,     0,     0,     0,     0,     0,   121,   105,   106,
     108,     0,     0,     0,     0,     0,     0,     0,     0,    38,
      39,     3,     5,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     9,   177,     0,
       0,     0,     0,    83,     0,   161,     0,    45,     0,     0,
      65,   133,     0,     0,     0,    44,    46,     0,     0,     0,
       0,    48,   120,     0,     0,   107,     0,     0,     0,     0,
       0,     0,     0,     0,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,     0,     0,   151,
      51,     0,     0,     0,    50,     0,     0,    43,     0,   135,
      52,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   171,     0,   174,   173,   175,     0,     0,
       0,     0,    48,    85,     0,     0,   149,   140,     0,     0,
       0,     0,    84,    23,   160,   132,     0,   138,   134,    54,
     135,     0,    91,     0,     0,     0,   119,     0,     0,     0,
      86,     0,   129,     0,     0,    22,   178,     0,    44,    49,
     152,     0,     0,     0,     0,     0,   139,     0,     0,     0,
       0,     0,    98,   102,     0,     0,   111,     0,     0,   118,
       0,   123,   172,   180,   179,     0,   176,     0,   137,   153,
     157,   148,   150,     0,   131,   147,   146,     0,   145,   127,
       0,     0,    85,    53,    90,     0,     0,    95,     0,   101,
       0,   109,   110,   114,     0,     0,   122,     0,   128,   135,
     158,    19,     0,   156,     0,     0,     0,     0,   143,     0,
     129,     0,     0,     0,   100,     0,     0,    97,     0,     0,
       0,     0,   136,   154,   155,     0,   126,     0,   130,   144,
       0,     0,     0,     0,    93,     0,    99,    94,     0,     0,
     115,     0,     0,   142,     0,     0,   125,     0,     0,     0,
       0,     0,    19,   117,     0,   141,     0,    92,     0,     0,
       0,    91,     0,   116,   124,     0,    96,     0,     0,     0,
       0,   113,     0,     0,    90,     0,   103
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -257,  -257,  -257,  -105,   166,   296,  -257,  -257,   -93,  -104,
      37,  -257,   128,  -257,  -257,  -257,  -257,  -257,  -257,  -257,
      -9,    35,  -256,  -257,  -257,    52,  -257,  -257,  -257,  -257,
    -257,  -257,    30,  -257,  -257,   -20,  -257,    73,  -257,   108,
    -257,     7,  -257,  -257,    78,  -257,  -257,    21,  -257,   -10,
    -257,  -257,  -257,  -257,  -257,  -257,  -257,  -257
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     2,     3,    49,    50,    51,    52,    53,    96,    54,
      55,   142,   143,    56,    57,    58,    59,    60,   333,   272,
     334,   273,    61,    62,   275,   276,    63,    64,    65,   164,
     317,    66,   253,   295,    67,   155,    68,   192,   325,   296,
     297,   298,    69,   225,   226,   291,   322,   323,   146,   100,
      71,    72,    73,    74,    75,    76,    77,    78
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      70,   160,    97,   163,   153,   263,   300,   140,   228,   247,
       1,    11,    12,    13,    14,    15,    16,    17,    18,    19,
       4,   369,    79,   311,    20,   229,    21,    22,   370,    23,
     248,     5,   274,    21,   321,  -112,   288,   188,     6,    70,
     141,   152,   264,   301,  -112,   382,   346,   189,   194,   190,
     195,   347,    24,    25,   191,    91,     7,   197,    92,   121,
     198,   327,   154,   328,     8,    26,   321,    27,   209,     9,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    10,   106,   224,    41,    42,    94,    95,
      43,    44,    45,    46,    47,    48,    70,    43,    44,    45,
      46,    47,    48,   372,   103,   104,   236,    11,    12,    13,
      14,    15,    16,    17,    18,    19,   261,   105,   123,   262,
      20,   123,    21,    22,   107,    23,   124,   125,   126,   127,
     128,   126,   127,   128,   284,   112,   270,   285,   285,   277,
     351,   108,   129,   130,   131,   132,   133,   134,    24,    25,
      70,   193,   109,    21,    98,   208,    23,   113,   224,   293,
     114,    26,   115,    27,   116,   117,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    24,
      25,   118,    41,    42,   144,   264,    43,    44,    45,    46,
      47,    48,   123,   173,   187,    70,   329,   152,   210,   211,
     335,   230,   258,   227,    35,    36,    37,    38,    39,    40,
     231,   243,   244,    41,    42,   122,   123,    43,    44,    45,
      46,    47,    48,    79,   124,   125,   126,   127,   128,   245,
     250,    70,   260,   359,    70,   361,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,   367,   266,    21,
      98,   267,    23,   268,   271,   278,    91,   374,   274,    92,
      70,    70,   280,    93,   379,   290,   191,    70,   299,   315,
     308,   229,   324,   326,   336,    24,    25,   342,   110,   341,
      70,   338,   340,   391,   392,   332,   350,   360,   395,    94,
      95,   362,   366,   355,   368,    70,   380,   384,    70,    79,
      35,    36,    37,    38,    39,    40,   393,   309,   388,    41,
      42,   310,    70,    43,    44,    45,    46,    47,    48,    99,
     101,   102,    70,   232,   356,    70,   122,   312,    70,   111,
      70,   331,    91,   289,   349,    92,   265,   119,   120,   257,
     292,     0,    70,   344,     0,     0,     0,     0,     0,    70,
       0,    70,    70,     0,     0,     0,     0,    70,     0,    70,
       0,    70,     0,     0,    70,    94,    95,     0,     0,    70,
       0,   242,     0,     0,     0,    70,     0,     0,    70,    70,
       0,    70,    70,    70,     0,    70,     0,   145,   147,   148,
       0,     0,   149,     0,     0,     0,     0,     0,     0,   157,
     158,   159,     0,   162,     0,     0,     0,     0,   166,   167,
     168,   169,   170,   171,   172,     0,     0,     0,     0,     0,
     174,   175,   176,   177,   178,   179,   180,   181,   182,   183,
     184,   185,   186,     0,     0,     0,   122,   307,     0,     0,
     196,     0,     0,   122,     0,     0,   201,     0,   202,   203,
     204,     0,    21,    98,     0,    23,   320,     0,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,   150,   220,
       0,     0,     0,     0,   337,     0,     0,     0,    24,    25,
     151,     0,     0,   221,   223,   152,     0,     0,   320,     0,
       0,     0,     0,     0,   234,     0,     0,     0,   354,     0,
       0,   122,     0,     0,     0,   246,     0,   249,     0,     0,
     251,     0,    41,    42,   252,   254,    43,    44,    45,    46,
      47,    48,     0,     0,     0,   122,     0,   122,     0,     0,
       0,     0,   269,   122,     0,     0,     0,   381,     0,     0,
     122,     0,     0,   279,     0,   122,     0,     0,     0,     0,
       0,   242,     0,   287,     0,     0,     0,   122,   122,   123,
     294,   122,     0,     0,   302,     0,     0,   124,   125,   126,
     127,   128,     0,     0,   314,     0,     0,   316,     0,     0,
       0,   318,     0,   129,   130,   131,   132,   133,   134,   135,
       0,     0,     0,     0,     0,     0,     0,   330,     0,     0,
       0,     0,     0,    11,    12,    13,    14,    15,    16,    17,
      18,    19,     0,     0,     0,     0,    20,     0,    21,   161,
     345,    23,   348,   294,     0,     0,     0,     0,     0,     0,
     123,     0,   358,     0,     0,     0,     0,     0,   124,   125,
     126,   127,   128,   364,    24,    25,   365,    11,    12,    13,
      14,    15,    16,    17,    18,    19,   131,   132,   133,   134,
      20,     0,    21,    22,   378,    23,     0,     0,     0,    35,
      36,    37,    38,    39,    40,     0,   387,     0,    41,    42,
       0,     0,    43,    44,    45,    46,    47,    48,    24,    25,
       0,     0,     0,     0,   241,     0,     0,     0,     0,     0,
       0,    26,     0,    27,     0,     0,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,     0,
       0,     0,    41,    42,     0,     0,    43,    44,    45,    46,
      47,    48,    11,    12,    13,    14,    15,    16,    17,    18,
      19,     0,     0,     0,     0,    20,     0,    21,    22,     0,
      23,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    11,    12,    13,    14,    15,    16,    17,
      18,    19,     0,    24,    25,     0,    20,     0,    21,    22,
     304,    23,     0,     0,     0,     0,    26,     0,    27,     0,
       0,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    24,    25,     0,    41,    42,     0,
     305,    43,    44,    45,    46,    47,    48,   306,     0,    27,
       0,     0,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,     0,     0,     0,    41,    42,
       0,     0,    43,    44,    45,    46,    47,    48,    11,    12,
      13,    14,    15,    16,    17,    18,    19,     0,     0,    79,
       0,    20,     0,    21,    22,     0,    23,     0,     0,     0,
       0,     0,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,     0,     0,     0,     0,     0,     0,    24,
      25,     0,    91,     0,     0,    92,   313,     0,     0,   154,
       0,     0,    26,     0,    27,     0,     0,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
       0,     0,     0,    41,    42,    94,    95,    43,    44,    45,
      46,    47,    48,    11,    12,    13,    14,    15,    16,    17,
      18,    19,     0,     0,     0,     0,    20,     0,    21,    22,
       0,    23,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    11,    12,    13,    14,    15,    16,
      17,    18,    19,     0,    24,    25,     0,    20,     0,    21,
      22,   343,    23,     0,     0,     0,     0,    26,     0,    27,
       0,     0,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    24,    25,     0,    41,    42,
       0,   352,    43,    44,    45,    46,    47,    48,   353,     0,
      27,     0,     0,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,     0,     0,     0,    41,
      42,     0,     0,    43,    44,    45,    46,    47,    48,    11,
      12,    13,    14,    15,    16,    17,    18,    19,     0,     0,
       0,     0,    20,     0,    21,    22,     0,    23,     0,     0,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      24,    25,   235,     0,    20,     0,     0,   357,     0,     0,
       0,     0,     0,    26,     0,    27,     0,     0,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,     0,     0,     0,    41,    42,     0,     0,    43,    44,
      45,    46,    47,    48,    11,    12,    13,    14,    15,    16,
      17,    18,    19,     0,     0,     0,     0,    20,     0,    21,
      22,     0,    23,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    24,    25,     0,     0,     0,
       0,     0,   373,     0,     0,     0,     0,     0,    26,     0,
      27,     0,     0,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,     0,     0,     0,    41,
      42,     0,     0,    43,    44,    45,    46,    47,    48,    11,
      12,    13,    14,    15,    16,    17,    18,    19,     0,     0,
       0,     0,    20,     0,    21,    22,     0,    23,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      24,    25,     0,     0,     0,     0,     0,   377,     0,     0,
       0,     0,     0,    26,     0,    27,     0,     0,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,     0,     0,     0,    41,    42,     0,     0,    43,    44,
      45,    46,    47,    48,    11,    12,    13,    14,    15,    16,
      17,    18,    19,     0,     0,     0,     0,    20,     0,    21,
      22,     0,    23,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    24,    25,     0,     0,     0,
       0,     0,   383,     0,     0,     0,     0,     0,    26,     0,
      27,     0,     0,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,     0,     0,     0,    41,
      42,     0,     0,    43,    44,    45,    46,    47,    48,    11,
      12,    13,    14,    15,    16,    17,    18,    19,     0,     0,
       0,     0,    20,     0,    21,    22,     0,    23,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      11,    12,    13,    14,    15,    16,    17,    18,    19,     0,
      24,    25,     0,    20,     0,    21,    22,   386,    23,     0,
       0,     0,     0,    26,     0,    27,     0,     0,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    24,    25,     0,    41,    42,     0,   389,    43,    44,
      45,    46,    47,    48,    26,     0,    27,     0,     0,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,     0,     0,     0,    41,    42,     0,     0,    43,
      44,    45,    46,    47,    48,    11,    12,    13,    14,    15,
      16,    17,    18,    19,     0,     0,     0,     0,    20,     0,
      21,    22,     0,    23,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    24,    25,     0,     0,
       0,     0,     0,   394,     0,     0,     0,     0,     0,    26,
       0,    27,     0,     0,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,     0,     0,     0,
      41,    42,     0,     0,    43,    44,    45,    46,    47,    48,
      11,    12,    13,    14,    15,    16,    17,    18,    19,     0,
       0,     0,     0,    20,     0,    21,    22,     0,    23,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    11,    12,    13,    14,    15,    16,    17,    18,    19,
       0,    24,    25,     0,    20,     0,    21,    22,   396,    23,
       0,     0,     0,     0,    26,     0,    27,     0,     0,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    24,    25,     0,    41,    42,     0,     0,    43,
      44,    45,    46,    47,    48,    26,     0,    27,     0,     0,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,     0,     0,     0,    41,    42,     0,     0,
      43,    44,    45,    46,    47,    48,    11,    12,    13,    14,
      15,    16,    17,    18,    19,     0,     0,     0,     0,    20,
       0,    21,    22,     0,    23,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    24,    25,     0,
       0,     0,    21,    98,     0,    23,     0,     0,     0,     0,
     306,     0,    27,     0,     0,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    24,    25,
       0,    41,    42,     0,     0,    43,    44,    45,    46,    47,
      48,     0,     0,     0,     0,     0,    21,   222,     0,    23,
       0,     0,     0,    35,    36,    37,    38,    39,    40,     0,
       0,     0,    41,    42,     0,     0,    43,    44,    45,    46,
      47,    48,    24,    25,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    35,    36,    37,
      38,    39,    40,     0,     0,     0,    41,    42,   123,     0,
      43,    44,    45,    46,    47,    48,   124,   125,   126,   127,
     128,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   129,   130,   131,   132,   133,   134,   135,   136,
       0,     0,   213,     0,     0,   214,     0,     0,     0,   123,
       0,     0,     0,     0,     0,     0,     0,   124,   125,   126,
     127,   128,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   138,   139,   129,   130,   131,   132,   133,   134,   135,
     136,     0,     0,     0,   137,     0,     0,     0,     0,     0,
     123,     0,     0,     0,     0,     0,     0,     0,   124,   125,
     126,   127,   128,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   138,   139,   129,   130,   131,   132,   133,   134,
     135,   136,     0,     0,   156,     0,     0,     0,     0,     0,
       0,   123,     0,     0,     0,     0,     0,     0,     0,   124,
     125,   126,   127,   128,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   138,   139,   129,   130,   131,   132,   133,
     134,   135,   136,     0,     0,     0,   165,     0,     0,     0,
       0,     0,   123,     0,     0,     0,     0,     0,     0,     0,
     124,   125,   126,   127,   128,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   138,   139,   129,   130,   131,   132,
     133,   134,   135,   136,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   199,   123,     0,     0,     0,     0,     0,
       0,     0,   124,   125,   126,   127,   128,     0,     0,     0,
       0,     0,     0,     0,     0,   138,   139,     0,   129,   130,
     131,   132,   133,   134,   135,   136,     0,     0,     0,   200,
       0,     0,     0,     0,     0,   123,     0,     0,     0,     0,
       0,     0,     0,   124,   125,   126,   127,   128,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   138,   139,   129,
     130,   131,   132,   133,   134,   135,   136,     0,     0,   205,
       0,     0,     0,     0,     0,     0,   123,     0,     0,     0,
       0,     0,     0,     0,   124,   125,   126,   127,   128,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   138,   139,
     129,   130,   131,   132,   133,   134,   135,   136,     0,     0,
     206,     0,     0,     0,     0,     0,     0,   123,     0,     0,
       0,     0,     0,     0,     0,   124,   125,   126,   127,   128,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   138,
     139,   129,   130,   131,   132,   133,   134,   135,   136,     0,
       0,   207,     0,     0,     0,     0,     0,     0,   123,     0,
       0,     0,     0,     0,     0,     0,   124,   125,   126,   127,
     128,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     138,   139,   129,   130,   131,   132,   133,   134,   135,   136,
       0,     0,   212,     0,     0,     0,     0,     0,     0,   123,
       0,     0,     0,     0,     0,     0,     0,   124,   125,   126,
     127,   128,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   138,   139,   129,   130,   131,   132,   133,   134,   135,
     136,     0,     0,   215,     0,     0,     0,     0,     0,     0,
     123,     0,     0,     0,     0,     0,     0,     0,   124,   125,
     126,   127,   128,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   138,   139,   129,   130,   131,   132,   133,   134,
     135,   136,     0,     0,   216,     0,     0,     0,     0,     0,
       0,   123,     0,     0,     0,     0,     0,     0,     0,   124,
     125,   126,   127,   128,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   138,   139,   129,   130,   131,   132,   133,
     134,   135,   136,     0,     0,   217,     0,     0,     0,     0,
       0,     0,   123,     0,     0,     0,     0,     0,     0,     0,
     124,   125,   126,   127,   128,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   138,   139,   129,   130,   131,   132,
     133,   134,   135,   136,     0,     0,     0,     0,     0,   218,
       0,     0,     0,   123,     0,     0,     0,     0,     0,     0,
       0,   124,   125,   126,   127,   128,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   138,   139,   129,   130,   131,
     132,   133,   134,   135,   136,     0,     0,     0,     0,     0,
     219,     0,     0,     0,   123,     0,     0,     0,     0,     0,
       0,     0,   124,   125,   126,   127,   128,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   138,   139,   129,   130,
     131,   132,   133,   134,   135,   136,     0,     0,   233,     0,
       0,     0,     0,     0,     0,   123,     0,     0,     0,     0,
       0,     0,     0,   124,   125,   126,   127,   128,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   138,   139,   129,
     130,   131,   132,   133,   134,   135,   136,     0,     0,     0,
     237,     0,     0,     0,     0,     0,   123,     0,     0,     0,
       0,     0,     0,     0,   124,   125,   126,   127,   128,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   138,   139,
     129,   130,   131,   132,   133,   134,   135,   136,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   238,   123,     0,
       0,     0,     0,     0,     0,     0,   124,   125,   126,   127,
     128,     0,     0,     0,     0,     0,     0,     0,     0,   138,
     139,     0,   129,   130,   131,   132,   133,   134,   135,   136,
       0,     0,     0,   239,     0,     0,     0,     0,     0,   123,
       0,     0,     0,     0,     0,     0,     0,   124,   125,   126,
     127,   128,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   138,   139,   129,   130,   131,   132,   133,   134,   135,
     136,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     240,   123,     0,     0,     0,     0,     0,     0,     0,   124,
     125,   126,   127,   128,     0,     0,     0,     0,     0,     0,
       0,     0,   138,   139,     0,   129,   130,   131,   132,   133,
     134,   135,   136,     0,     0,   255,     0,     0,     0,     0,
       0,     0,   123,     0,     0,     0,     0,     0,     0,     0,
     124,   125,   126,   127,   128,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   138,   139,   129,   130,   131,   132,
     133,   134,   135,   136,     0,     0,   256,     0,     0,     0,
       0,     0,     0,   123,     0,     0,     0,     0,     0,     0,
       0,   124,   125,   126,   127,   128,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   138,   139,   129,   130,   131,
     132,   133,   134,   135,   136,     0,     0,     0,   259,     0,
       0,     0,     0,     0,   123,     0,     0,     0,     0,     0,
       0,     0,   124,   125,   126,   127,   128,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   138,   139,   129,   130,
     131,   132,   133,   134,   135,   136,     0,     0,     0,   281,
       0,     0,     0,     0,     0,   123,     0,     0,     0,     0,
       0,     0,     0,   124,   125,   126,   127,   128,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   138,   139,   129,
     130,   131,   132,   133,   134,   135,   136,     0,     0,   282,
       0,     0,     0,     0,     0,     0,   123,     0,     0,     0,
       0,     0,     0,     0,   124,   125,   126,   127,   128,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   138,   139,
     129,   130,   131,   132,   133,   134,   135,   136,     0,     0,
     283,     0,     0,     0,     0,     0,     0,   123,     0,     0,
       0,     0,     0,     0,     0,   124,   125,   126,   127,   128,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   138,
     139,   129,   130,   131,   132,   133,   134,   135,   136,     0,
       0,   286,     0,     0,     0,     0,     0,     0,   123,     0,
       0,     0,     0,     0,     0,     0,   124,   125,   126,   127,
     128,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     138,   139,   129,   130,   131,   132,   133,   134,   135,   136,
       0,     0,     0,   303,     0,     0,     0,     0,     0,   123,
       0,     0,     0,     0,     0,     0,     0,   124,   125,   126,
     127,   128,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   138,   139,   129,   130,   131,   132,   133,   134,   135,
     136,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     319,   123,     0,     0,     0,     0,     0,     0,     0,   124,
     125,   126,   127,   128,     0,     0,     0,     0,     0,     0,
       0,     0,   138,   139,     0,   129,   130,   131,   132,   133,
     134,   135,   136,     0,     0,   339,     0,     0,     0,     0,
       0,     0,   123,     0,     0,     0,     0,     0,     0,     0,
     124,   125,   126,   127,   128,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   138,   139,   129,   130,   131,   132,
     133,   134,   135,   136,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   363,   123,     0,     0,     0,     0,     0,
       0,     0,   124,   125,   126,   127,   128,     0,     0,     0,
       0,     0,     0,     0,     0,   138,   139,     0,   129,   130,
     131,   132,   133,   134,   135,   136,     0,     0,   371,     0,
       0,     0,     0,     0,     0,   123,     0,     0,     0,     0,
       0,     0,     0,   124,   125,   126,   127,   128,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   138,   139,   129,
     130,   131,   132,   133,   134,   135,   136,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   375,   123,     0,     0,
       0,     0,     0,     0,     0,   124,   125,   126,   127,   128,
       0,     0,     0,     0,     0,     0,     0,     0,   138,   139,
       0,   129,   130,   131,   132,   133,   134,   135,   136,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   376,   123,
       0,     0,     0,     0,     0,     0,     0,   124,   125,   126,
     127,   128,     0,     0,     0,     0,     0,     0,     0,     0,
     138,   139,     0,   129,   130,   131,   132,   133,   134,   135,
     136,     0,     0,   385,     0,     0,     0,     0,     0,     0,
     123,     0,     0,     0,     0,     0,     0,     0,   124,   125,
     126,   127,   128,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   138,   139,   129,   130,   131,   132,   133,   134,
     135,   136,     0,     0,   390,     0,     0,     0,     0,     0,
       0,   -21,     0,     0,     0,     0,     0,     0,     0,   -21,
       0,   -21,   -21,   -21,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   138,   139,   -21,   -21,   -21,   -21,   -21,
     -21,   -21,   -21,     0,     0,     0,   -21,     0,     0,     0,
       0,     0,   123,     0,     0,     0,     0,     0,     0,     0,
     124,   125,   126,   127,   128,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   -21,   -21,   129,   130,   131,   132,
     133,   134,   135,   136,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   138,   139
};

static const yytype_int16 yycheck[] =
{
      10,   106,    22,   107,    97,    13,    13,    19,    35,    35,
      14,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      15,    50,    12,    51,    16,    52,    18,    19,    57,    21,
      56,     0,    60,    18,   290,    51,    47,    35,    16,    49,
      52,    52,    50,    50,    60,    61,    47,    45,    47,    47,
      49,    52,    44,    45,    52,    45,    17,    46,    48,    51,
      49,    49,    52,    51,    45,    57,   322,    59,   161,    46,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    50,    50,   189,    78,    79,    78,    79,
      82,    83,    84,    85,    86,    87,   106,    82,    83,    84,
      85,    86,    87,   359,    45,    45,   199,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    46,    45,    12,    49,
      16,    12,    18,    19,    45,    21,    20,    21,    22,    23,
      24,    22,    23,    24,    46,    45,   241,    49,    49,   244,
      51,    47,    36,    37,    38,    39,    40,    41,    44,    45,
     160,    53,    47,    18,    19,    51,    21,    45,   262,   263,
      45,    57,    45,    59,    45,    45,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    44,
      45,    45,    78,    79,    45,    50,    82,    83,    84,    85,
      86,    87,    12,    45,    45,   205,   300,    52,    19,    47,
     305,    19,   222,    53,    69,    70,    71,    72,    73,    74,
      19,    50,    50,    78,    79,    49,    12,    82,    83,    84,
      85,    86,    87,    12,    20,    21,    22,    23,    24,    62,
      47,   241,    19,   338,   244,   340,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,   352,    53,    18,
      19,    35,    21,    35,    58,    45,    45,   362,    60,    48,
     270,   271,    19,    52,   369,    50,    52,   277,    47,    46,
      58,    52,    52,    49,    45,    44,    45,    47,    47,    46,
     290,    56,    50,   388,   389,    58,    52,    47,   393,    78,
      79,    50,    47,    58,    45,   305,    45,    47,   308,    12,
      69,    70,    71,    72,    73,    74,    50,   272,    56,    78,
      79,   274,   322,    82,    83,    84,    85,    86,    87,    23,
      24,    25,   332,   195,   333,   335,   160,   275,   338,    33,
     340,   301,    45,   260,   327,    48,   228,    41,    42,    52,
     262,    -1,   352,   322,    -1,    -1,    -1,    -1,    -1,   359,
      -1,   361,   362,    -1,    -1,    -1,    -1,   367,    -1,   369,
      -1,   371,    -1,    -1,   374,    78,    79,    -1,    -1,   379,
      -1,   205,    -1,    -1,    -1,   385,    -1,    -1,   388,   389,
      -1,   391,   392,   393,    -1,   395,    -1,    91,    92,    93,
      -1,    -1,    96,    -1,    -1,    -1,    -1,    -1,    -1,   103,
     104,   105,    -1,   107,    -1,    -1,    -1,    -1,   112,   113,
     114,   115,   116,   117,   118,    -1,    -1,    -1,    -1,    -1,
     124,   125,   126,   127,   128,   129,   130,   131,   132,   133,
     134,   135,   136,    -1,    -1,    -1,   270,   271,    -1,    -1,
     144,    -1,    -1,   277,    -1,    -1,   150,    -1,   152,   153,
     154,    -1,    18,    19,    -1,    21,   290,    -1,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,   173,
      -1,    -1,    -1,    -1,   308,    -1,    -1,    -1,    44,    45,
      47,    -1,    -1,   187,   188,    52,    -1,    -1,   322,    -1,
      -1,    -1,    -1,    -1,   198,    -1,    -1,    -1,   332,    -1,
      -1,   335,    -1,    -1,    -1,   209,    -1,   211,    -1,    -1,
     214,    -1,    78,    79,   218,   219,    82,    83,    84,    85,
      86,    87,    -1,    -1,    -1,   359,    -1,   361,    -1,    -1,
      -1,    -1,   236,   367,    -1,    -1,    -1,   371,    -1,    -1,
     374,    -1,    -1,   247,    -1,   379,    -1,    -1,    -1,    -1,
      -1,   385,    -1,   257,    -1,    -1,    -1,   391,   392,    12,
     264,   395,    -1,    -1,   268,    -1,    -1,    20,    21,    22,
      23,    24,    -1,    -1,   278,    -1,    -1,   281,    -1,    -1,
      -1,   285,    -1,    36,    37,    38,    39,    40,    41,    42,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   301,    -1,    -1,
      -1,    -1,    -1,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    -1,    -1,    -1,    -1,    16,    -1,    18,    19,
     324,    21,   326,   327,    -1,    -1,    -1,    -1,    -1,    -1,
      12,    -1,   336,    -1,    -1,    -1,    -1,    -1,    20,    21,
      22,    23,    24,   347,    44,    45,   350,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    38,    39,    40,    41,
      16,    -1,    18,    19,   368,    21,    -1,    -1,    -1,    69,
      70,    71,    72,    73,    74,    -1,   380,    -1,    78,    79,
      -1,    -1,    82,    83,    84,    85,    86,    87,    44,    45,
      -1,    -1,    -1,    -1,    50,    -1,    -1,    -1,    -1,    -1,
      -1,    57,    -1,    59,    -1,    -1,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    -1,
      -1,    -1,    78,    79,    -1,    -1,    82,    83,    84,    85,
      86,    87,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    -1,    -1,    -1,    -1,    16,    -1,    18,    19,    -1,
      21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    -1,    44,    45,    -1,    16,    -1,    18,    19,
      51,    21,    -1,    -1,    -1,    -1,    57,    -1,    59,    -1,
      -1,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    44,    45,    -1,    78,    79,    -1,
      50,    82,    83,    84,    85,    86,    87,    57,    -1,    59,
      -1,    -1,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    -1,    -1,    -1,    78,    79,
      -1,    -1,    82,    83,    84,    85,    86,    87,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    -1,    -1,    12,
      -1,    16,    -1,    18,    19,    -1,    21,    -1,    -1,    -1,
      -1,    -1,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    -1,    -1,    -1,    -1,    -1,    -1,    44,
      45,    -1,    45,    -1,    -1,    48,    51,    -1,    -1,    52,
      -1,    -1,    57,    -1,    59,    -1,    -1,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      -1,    -1,    -1,    78,    79,    78,    79,    82,    83,    84,
      85,    86,    87,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    -1,    -1,    -1,    -1,    16,    -1,    18,    19,
      -1,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    -1,    44,    45,    -1,    16,    -1,    18,
      19,    51,    21,    -1,    -1,    -1,    -1,    57,    -1,    59,
      -1,    -1,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    44,    45,    -1,    78,    79,
      -1,    50,    82,    83,    84,    85,    86,    87,    57,    -1,
      59,    -1,    -1,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    -1,    -1,    -1,    78,
      79,    -1,    -1,    82,    83,    84,    85,    86,    87,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    -1,    -1,
      -1,    -1,    16,    -1,    18,    19,    -1,    21,    -1,    -1,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      44,    45,    47,    -1,    16,    -1,    -1,    51,    -1,    -1,
      -1,    -1,    -1,    57,    -1,    59,    -1,    -1,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    -1,    -1,    -1,    78,    79,    -1,    -1,    82,    83,
      84,    85,    86,    87,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    -1,    -1,    -1,    -1,    16,    -1,    18,
      19,    -1,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    44,    45,    -1,    -1,    -1,
      -1,    -1,    51,    -1,    -1,    -1,    -1,    -1,    57,    -1,
      59,    -1,    -1,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    -1,    -1,    -1,    78,
      79,    -1,    -1,    82,    83,    84,    85,    86,    87,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    -1,    -1,
      -1,    -1,    16,    -1,    18,    19,    -1,    21,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      44,    45,    -1,    -1,    -1,    -1,    -1,    51,    -1,    -1,
      -1,    -1,    -1,    57,    -1,    59,    -1,    -1,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    -1,    -1,    -1,    78,    79,    -1,    -1,    82,    83,
      84,    85,    86,    87,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    -1,    -1,    -1,    -1,    16,    -1,    18,
      19,    -1,    21,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    44,    45,    -1,    -1,    -1,
      -1,    -1,    51,    -1,    -1,    -1,    -1,    -1,    57,    -1,
      59,    -1,    -1,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    -1,    -1,    -1,    78,
      79,    -1,    -1,    82,    83,    84,    85,    86,    87,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    -1,    -1,
      -1,    -1,    16,    -1,    18,    19,    -1,    21,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    -1,
      44,    45,    -1,    16,    -1,    18,    19,    51,    21,    -1,
      -1,    -1,    -1,    57,    -1,    59,    -1,    -1,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    44,    45,    -1,    78,    79,    -1,    50,    82,    83,
      84,    85,    86,    87,    57,    -1,    59,    -1,    -1,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    -1,    -1,    -1,    78,    79,    -1,    -1,    82,
      83,    84,    85,    86,    87,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    -1,    -1,    -1,    -1,    16,    -1,
      18,    19,    -1,    21,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    44,    45,    -1,    -1,
      -1,    -1,    -1,    51,    -1,    -1,    -1,    -1,    -1,    57,
      -1,    59,    -1,    -1,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    -1,    -1,    -1,
      78,    79,    -1,    -1,    82,    83,    84,    85,    86,    87,
       3,     4,     5,     6,     7,     8,     9,    10,    11,    -1,
      -1,    -1,    -1,    16,    -1,    18,    19,    -1,    21,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      -1,    44,    45,    -1,    16,    -1,    18,    19,    51,    21,
      -1,    -1,    -1,    -1,    57,    -1,    59,    -1,    -1,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    44,    45,    -1,    78,    79,    -1,    -1,    82,
      83,    84,    85,    86,    87,    57,    -1,    59,    -1,    -1,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    -1,    -1,    -1,    78,    79,    -1,    -1,
      82,    83,    84,    85,    86,    87,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,    16,
      -1,    18,    19,    -1,    21,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    45,    -1,
      -1,    -1,    18,    19,    -1,    21,    -1,    -1,    -1,    -1,
      57,    -1,    59,    -1,    -1,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    44,    45,
      -1,    78,    79,    -1,    -1,    82,    83,    84,    85,    86,
      87,    -1,    -1,    -1,    -1,    -1,    18,    19,    -1,    21,
      -1,    -1,    -1,    69,    70,    71,    72,    73,    74,    -1,
      -1,    -1,    78,    79,    -1,    -1,    82,    83,    84,    85,
      86,    87,    44,    45,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    70,    71,
      72,    73,    74,    -1,    -1,    -1,    78,    79,    12,    -1,
      82,    83,    84,    85,    86,    87,    20,    21,    22,    23,
      24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    36,    37,    38,    39,    40,    41,    42,    43,
      -1,    -1,    46,    -1,    -1,    49,    -1,    -1,    -1,    12,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,    22,
      23,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    75,    76,    36,    37,    38,    39,    40,    41,    42,
      43,    -1,    -1,    -1,    47,    -1,    -1,    -1,    -1,    -1,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,
      22,    23,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    75,    76,    36,    37,    38,    39,    40,    41,
      42,    43,    -1,    -1,    46,    -1,    -1,    -1,    -1,    -1,
      -1,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,
      21,    22,    23,    24,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    75,    76,    36,    37,    38,    39,    40,
      41,    42,    43,    -1,    -1,    -1,    47,    -1,    -1,    -1,
      -1,    -1,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      20,    21,    22,    23,    24,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    75,    76,    36,    37,    38,    39,
      40,    41,    42,    43,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    53,    12,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    20,    21,    22,    23,    24,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    75,    76,    -1,    36,    37,
      38,    39,    40,    41,    42,    43,    -1,    -1,    -1,    47,
      -1,    -1,    -1,    -1,    -1,    12,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    20,    21,    22,    23,    24,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    76,    36,
      37,    38,    39,    40,    41,    42,    43,    -1,    -1,    46,
      -1,    -1,    -1,    -1,    -1,    -1,    12,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    20,    21,    22,    23,    24,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    76,
      36,    37,    38,    39,    40,    41,    42,    43,    -1,    -1,
      46,    -1,    -1,    -1,    -1,    -1,    -1,    12,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    20,    21,    22,    23,    24,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,
      76,    36,    37,    38,    39,    40,    41,    42,    43,    -1,
      -1,    46,    -1,    -1,    -1,    -1,    -1,    -1,    12,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    20,    21,    22,    23,
      24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      75,    76,    36,    37,    38,    39,    40,    41,    42,    43,
      -1,    -1,    46,    -1,    -1,    -1,    -1,    -1,    -1,    12,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,    22,
      23,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    75,    76,    36,    37,    38,    39,    40,    41,    42,
      43,    -1,    -1,    46,    -1,    -1,    -1,    -1,    -1,    -1,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,
      22,    23,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    75,    76,    36,    37,    38,    39,    40,    41,
      42,    43,    -1,    -1,    46,    -1,    -1,    -1,    -1,    -1,
      -1,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,
      21,    22,    23,    24,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    75,    76,    36,    37,    38,    39,    40,
      41,    42,    43,    -1,    -1,    46,    -1,    -1,    -1,    -1,
      -1,    -1,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      20,    21,    22,    23,    24,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    75,    76,    36,    37,    38,    39,
      40,    41,    42,    43,    -1,    -1,    -1,    -1,    -1,    49,
      -1,    -1,    -1,    12,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    20,    21,    22,    23,    24,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    75,    76,    36,    37,    38,
      39,    40,    41,    42,    43,    -1,    -1,    -1,    -1,    -1,
      49,    -1,    -1,    -1,    12,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    20,    21,    22,    23,    24,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    75,    76,    36,    37,
      38,    39,    40,    41,    42,    43,    -1,    -1,    46,    -1,
      -1,    -1,    -1,    -1,    -1,    12,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    20,    21,    22,    23,    24,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    76,    36,
      37,    38,    39,    40,    41,    42,    43,    -1,    -1,    -1,
      47,    -1,    -1,    -1,    -1,    -1,    12,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    20,    21,    22,    23,    24,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    76,
      36,    37,    38,    39,    40,    41,    42,    43,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,    12,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    20,    21,    22,    23,
      24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,
      76,    -1,    36,    37,    38,    39,    40,    41,    42,    43,
      -1,    -1,    -1,    47,    -1,    -1,    -1,    -1,    -1,    12,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,    22,
      23,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    75,    76,    36,    37,    38,    39,    40,    41,    42,
      43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      53,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,
      21,    22,    23,    24,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    75,    76,    -1,    36,    37,    38,    39,    40,
      41,    42,    43,    -1,    -1,    46,    -1,    -1,    -1,    -1,
      -1,    -1,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      20,    21,    22,    23,    24,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    75,    76,    36,    37,    38,    39,
      40,    41,    42,    43,    -1,    -1,    46,    -1,    -1,    -1,
      -1,    -1,    -1,    12,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    20,    21,    22,    23,    24,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    75,    76,    36,    37,    38,
      39,    40,    41,    42,    43,    -1,    -1,    -1,    47,    -1,
      -1,    -1,    -1,    -1,    12,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    20,    21,    22,    23,    24,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    75,    76,    36,    37,
      38,    39,    40,    41,    42,    43,    -1,    -1,    -1,    47,
      -1,    -1,    -1,    -1,    -1,    12,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    20,    21,    22,    23,    24,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    76,    36,
      37,    38,    39,    40,    41,    42,    43,    -1,    -1,    46,
      -1,    -1,    -1,    -1,    -1,    -1,    12,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    20,    21,    22,    23,    24,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    76,
      36,    37,    38,    39,    40,    41,    42,    43,    -1,    -1,
      46,    -1,    -1,    -1,    -1,    -1,    -1,    12,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    20,    21,    22,    23,    24,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,
      76,    36,    37,    38,    39,    40,    41,    42,    43,    -1,
      -1,    46,    -1,    -1,    -1,    -1,    -1,    -1,    12,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    20,    21,    22,    23,
      24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      75,    76,    36,    37,    38,    39,    40,    41,    42,    43,
      -1,    -1,    -1,    47,    -1,    -1,    -1,    -1,    -1,    12,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,    22,
      23,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    75,    76,    36,    37,    38,    39,    40,    41,    42,
      43,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      53,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,
      21,    22,    23,    24,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    75,    76,    -1,    36,    37,    38,    39,    40,
      41,    42,    43,    -1,    -1,    46,    -1,    -1,    -1,    -1,
      -1,    -1,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      20,    21,    22,    23,    24,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    75,    76,    36,    37,    38,    39,
      40,    41,    42,    43,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    53,    12,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    20,    21,    22,    23,    24,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    75,    76,    -1,    36,    37,
      38,    39,    40,    41,    42,    43,    -1,    -1,    46,    -1,
      -1,    -1,    -1,    -1,    -1,    12,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    20,    21,    22,    23,    24,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    76,    36,
      37,    38,    39,    40,    41,    42,    43,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    53,    12,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    20,    21,    22,    23,    24,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    75,    76,
      -1,    36,    37,    38,    39,    40,    41,    42,    43,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    53,    12,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,    22,
      23,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      75,    76,    -1,    36,    37,    38,    39,    40,    41,    42,
      43,    -1,    -1,    46,    -1,    -1,    -1,    -1,    -1,    -1,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,
      22,    23,    24,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    75,    76,    36,    37,    38,    39,    40,    41,
      42,    43,    -1,    -1,    46,    -1,    -1,    -1,    -1,    -1,
      -1,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,
      -1,    22,    23,    24,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    75,    76,    36,    37,    38,    39,    40,
      41,    42,    43,    -1,    -1,    -1,    47,    -1,    -1,    -1,
      -1,    -1,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      20,    21,    22,    23,    24,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    75,    76,    36,    37,    38,    39,
      40,    41,    42,    43,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    75,    76
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    14,    89,    90,    15,     0,    16,    17,    45,    46,
      50,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      16,    18,    19,    21,    44,    45,    57,    59,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    78,    79,    82,    83,    84,    85,    86,    87,    91,
      92,    93,    94,    95,    97,    98,   101,   102,   103,   104,
     105,   110,   111,   114,   115,   116,   119,   122,   124,   130,
     137,   138,   139,   140,   141,   142,   143,   144,   145,    12,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    45,    48,    52,    78,    79,    96,   123,    19,    93,
     137,    93,    93,    45,    45,    45,    50,    45,    47,    47,
      47,    93,    45,    45,    45,    45,    45,    45,    45,    93,
      93,    51,    92,    12,    20,    21,    22,    23,    24,    36,
      37,    38,    39,    40,    41,    42,    43,    47,    75,    76,
      19,    52,    99,   100,    45,    93,   136,    93,    93,    93,
      35,    47,    52,    96,    52,   123,    46,    93,    93,    93,
      91,    19,    93,    97,   117,    47,    93,    93,    93,    93,
      93,    93,    93,    45,    93,    93,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    93,    93,    45,    35,    45,
      47,    52,   125,    53,    47,    49,    93,    46,    49,    53,
      47,    93,    93,    93,    93,    46,    46,    46,    51,    96,
      19,    47,    46,    46,    49,    46,    46,    46,    49,    49,
      93,    93,    19,    93,    97,   131,   132,    53,    35,    52,
      19,    19,   100,    46,    93,    47,    96,    47,    53,    47,
      53,    50,    92,    50,    50,    62,    93,    35,    56,    93,
      47,    93,    93,   120,    93,    46,    46,    52,   123,    47,
      19,    46,    49,    13,    50,   127,    53,    35,    35,    93,
      91,    58,   107,   109,    60,   112,   113,    91,    45,    93,
      19,    47,    46,    46,    46,    49,    46,    93,    47,   125,
      50,   133,   132,    97,    93,   121,   127,   128,   129,    47,
      13,    50,    93,    47,    51,    50,    57,    92,    58,   109,
      98,    51,   113,    51,    93,    46,    93,   118,    93,    53,
      92,   110,   134,   135,    52,   126,    49,    49,    51,    97,
      93,   120,    58,   106,   108,    91,    45,    92,    56,    46,
      50,    46,    47,    51,   135,    93,    47,    52,    93,   129,
      52,    51,    50,    57,    92,    58,   108,    51,    93,    91,
      47,    91,    50,    53,    93,    93,    47,    91,    45,    50,
      57,    46,   110,    51,    91,    53,    53,    51,    93,    91,
      45,    92,    61,    51,    47,    46,    51,    93,    56,    50,
      46,    91,    91,    50,    51,    91,    51
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    88,    89,    90,    91,    91,    92,    92,    92,    92,
      92,    92,    92,    92,    92,    92,    92,    92,    92,    92,
      92,    93,    93,    93,    93,    93,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    93,
      93,    93,    93,    93,    93,    93,    93,    93,    93,    94,
      94,    94,    95,    95,    95,    96,    96,    96,    96,    96,
      96,    96,    96,    96,    96,    96,    97,    97,    97,    97,
      97,    97,    97,    97,    97,    97,    98,    98,    98,    98,
      98,    98,    98,    99,    99,   100,   101,   102,   102,   102,
     103,   103,   104,   104,   104,   104,   105,   105,   105,   106,
     106,   107,   107,   108,   109,   110,   110,   110,   110,   111,
     112,   112,   113,   113,   114,   115,   116,   116,   117,   117,
     117,   117,   118,   118,   119,   119,   119,   119,   120,   120,
     121,   121,   122,   122,   123,   123,   124,   124,   124,   125,
     125,   126,   126,   127,   128,   128,   129,   129,   130,   131,
     131,   131,   132,   132,   133,   134,   134,   134,   135,   135,
     136,   136,   136,   137,   137,   137,   137,   137,   137,   137,
     137,   138,   138,   139,   140,   141,   142,   143,   144,   145,
     145
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     9,     1,     2,     1,     1,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     5,     5,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     2,     2,
       2,     2,     2,     4,     2,     3,     3,     1,     1,     5,
       3,     3,     4,     7,     5,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     3,     5,     1,     1,     1,
       7,     5,    11,     9,     9,     7,    12,     8,     6,     2,
       1,     2,     1,     8,     6,     2,     2,     3,     2,     7,
       2,     1,     5,     8,     7,     9,    11,    10,     4,     3,
       1,     0,     1,     0,    11,     9,     8,     6,     3,     1,
       3,     1,     5,     3,     4,     3,     8,     6,     5,     3,
       2,     4,     3,     3,     3,     1,     1,     1,     6,     1,
       3,     0,     2,     3,     3,     2,     1,     0,     1,     1,
       3,     1,     0,     1,     1,     1,     1,     1,     1,     1,
       1,     4,     6,     4,     4,     4,     6,     2,     5,     6,
       6
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YYLOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YYLOCATION_PRINT

#  if defined YY_LOCATION_PRINT

   /* Temporary convenience wrapper in case some people defined the
      undocumented and private YY_LOCATION_PRINT macros.  */
#   define YYLOCATION_PRINT(File, Loc)  YY_LOCATION_PRINT(File, *(Loc))

#  elif defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
}

#   define YYLOCATION_PRINT  yy_location_print_

    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT(File, Loc)  YYLOCATION_PRINT(File, &(Loc))

#  else

#   define YYLOCATION_PRINT(File, Loc) ((void) 0)
    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT  YYLOCATION_PRINT

#  endif
# endif /* !defined YYLOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  YY_USE (yylocationp);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YYLOCATION_PRINT (yyo, yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]));
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
  YYLTYPE *yylloc;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;
      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  yylsp[0] = yylloc;
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      yyerror_range[1] = yylloc;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* program: bloque_main  */
#line 213 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        ast_root = build_program_node((yyvsp[0].node), (yylsp[0]).first_line, (yylsp[0]).first_column);
        (yyval.node) = ast_root;
    }
#line 2535 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 3: /* bloque_main: TOKEN_PUBLIC TOKEN_STATIC TOKEN_VOID TOKEN_MAIN TOKEN_PAREN_LEFT TOKEN_PAREN_RIGHT TOKEN_BRACE_LEFT instrucciones TOKEN_BRACE_RIGHT  */
#line 221 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_bloque_main_node((yyvsp[-1].node), (yylsp[-8]).first_line, (yylsp[-8]).first_column);
    }
#line 2543 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 4: /* instrucciones: instruccion  */
#line 228 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_instrucciones_single((yyvsp[0].node), (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 2551 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 5: /* instrucciones: instrucciones instruccion  */
#line 232 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_instrucciones_add((yyvsp[-1].node), (yyvsp[0].node));
    }
#line 2559 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 6: /* instruccion: sout  */
#line 239 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2567 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 7: /* instruccion: declaraciones  */
#line 243 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2575 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 8: /* instruccion: asignacion_compuesta  */
#line 247 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2583 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 9: /* instruccion: expresion TOKEN_SEMICOLON  */
#line 251 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = (yyvsp[-1].node);
    }
#line 2591 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 10: /* instruccion: sentencia_if  */
#line 255 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2599 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 11: /* instruccion: sentencia_switch  */
#line 259 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2607 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 12: /* instruccion: ciclo_while  */
#line 263 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2615 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 13: /* instruccion: ciclo_do  */
#line 267 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2623 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 14: /* instruccion: ciclo_for  */
#line 271 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2631 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 15: /* instruccion: arrays  */
#line 275 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2639 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 16: /* instruccion: arrays_acceso  */
#line 279 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2647 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 17: /* instruccion: arrays_asignacion  */
#line 283 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2655 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 18: /* instruccion: funcion  */
#line 287 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2663 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 19: /* instruccion: sentencias  */
#line 291 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2671 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 20: /* instruccion: embebidas  */
#line 295 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2679 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 21: /* expresion: embebidas  */
#line 302 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2687 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 22: /* expresion: expresion TOKEN_EQUALS TOKEN_PAREN_LEFT expresion TOKEN_PAREN_RIGHT  */
#line 306 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_equals_embebida((yyvsp[-4].node), (yyvsp[-1].node), (yylsp[-3]).first_line, (yylsp[-3]).first_column);
    }
#line 2695 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 23: /* expresion: TOKEN_IDENTIFIER TOKEN_EQUALS TOKEN_PAREN_LEFT expresion TOKEN_PAREN_RIGHT  */
#line 310 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        ASTNode* id_node = build_identifier((yyvsp[-4].str), (yylsp[-4]).first_line, (yylsp[-4]).first_column);
        (yyval.node) = build_equals_embebida(id_node, (yyvsp[-1].node), (yylsp[-3]).first_line, (yylsp[-3]).first_column);
    }
#line 2704 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 24: /* expresion: expresion TOKEN_PLUS expresion  */
#line 316 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_expresion_binaria((yyvsp[-2].node), "+", (yyvsp[0].node), (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 2712 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 25: /* expresion: expresion TOKEN_MINUS expresion  */
#line 320 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_expresion_binaria((yyvsp[-2].node), "-", (yyvsp[0].node), (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 2720 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 26: /* expresion: expresion TOKEN_MULTIPLICATION expresion  */
#line 324 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_expresion_binaria((yyvsp[-2].node), "*", (yyvsp[0].node), (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 2728 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 27: /* expresion: expresion TOKEN_DIVISION expresion  */
#line 328 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_expresion_binaria((yyvsp[-2].node), "/", (yyvsp[0].node), (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 2736 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 28: /* expresion: expresion TOKEN_MODULE expresion  */
#line 332 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_expresion_binaria((yyvsp[-2].node), "%", (yyvsp[0].node), (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 2744 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 29: /* expresion: expresion TOKEN_EQUAL expresion  */
#line 338 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_expresion_binaria((yyvsp[-2].node), "==", (yyvsp[0].node), (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 2752 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 30: /* expresion: expresion TOKEN_UNEQUAL expresion  */
#line 342 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_expresion_binaria((yyvsp[-2].node), "!=", (yyvsp[0].node), (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 2760 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 31: /* expresion: expresion TOKEN_GREATER expresion  */
#line 348 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_expresion_binaria((yyvsp[-2].node), ">", (yyvsp[0].node), (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 2768 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 32: /* expresion: expresion TOKEN_LESS expresion  */
#line 352 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_expresion_binaria((yyvsp[-2].node), "<", (yyvsp[0].node), (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 2776 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 33: /* expresion: expresion TOKEN_GREATER_EQUAL expresion  */
#line 356 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_expresion_binaria((yyvsp[-2].node), ">=", (yyvsp[0].node), (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 2784 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 34: /* expresion: expresion TOKEN_LESS_EQUAL expresion  */
#line 360 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_expresion_binaria((yyvsp[-2].node), "<=", (yyvsp[0].node), (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 2792 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 35: /* expresion: expresion TOKEN_AND expresion  */
#line 366 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_expresion_binaria((yyvsp[-2].node), "&&", (yyvsp[0].node), (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 2800 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 36: /* expresion: expresion TOKEN_OR expresion  */
#line 370 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_expresion_binaria((yyvsp[-2].node), "||", (yyvsp[0].node), (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 2808 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 37: /* expresion: TOKEN_NOT expresion  */
#line 376 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_expresion_unaria("!", (yyvsp[0].node), (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 2816 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 38: /* expresion: TOKEN_INCREMENT expresion  */
#line 380 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_expresion_unaria("++", (yyvsp[0].node), (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 2824 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 39: /* expresion: TOKEN_DECREMENT expresion  */
#line 384 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_expresion_unaria("--", (yyvsp[0].node), (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 2832 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 40: /* expresion: TOKEN_MINUS expresion  */
#line 388 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_expresion_unaria("-", (yyvsp[0].node), (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 2840 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 41: /* expresion: TOKEN_IDENTIFIER TOKEN_INCREMENT  */
#line 394 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        ASTNode* id_node = build_identifier((yyvsp[-1].str), (yylsp[-1]).first_line, (yylsp[-1]).first_column);
        (yyval.node) = build_expresion_postfijo(id_node, "++", (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 2849 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 42: /* expresion: TOKEN_IDENTIFIER TOKEN_DECREMENT  */
#line 399 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        ASTNode* id_node = build_identifier((yyvsp[-1].str), (yylsp[-1]).first_line, (yylsp[-1]).first_column);
        (yyval.node) = build_expresion_postfijo(id_node, "--", (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 2858 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 43: /* expresion: TOKEN_IDENTIFIER TOKEN_PAREN_LEFT argumentos TOKEN_PAREN_RIGHT  */
#line 406 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_llamada_funcion((yyvsp[-3].str), (yyvsp[-1].node), (yylsp[-3]).first_line, (yylsp[-3]).first_column);
    }
#line 2866 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 44: /* expresion: TOKEN_IDENTIFIER brackets_indices  */
#line 412 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_array_acceso_multidimensional((yyvsp[-1].str), (yyvsp[0].node), (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 2874 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 45: /* expresion: TOKEN_IDENTIFIER TOKEN_DOT expresion  */
#line 418 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        ASTNode* id_node = build_identifier((yyvsp[-2].str), (yylsp[-2]).first_line, (yylsp[-2]).first_column);
        (yyval.node) = build_expresion_acceso(id_node, (yyvsp[0].node), (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 2883 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 46: /* expresion: TOKEN_PAREN_LEFT expresion TOKEN_PAREN_RIGHT  */
#line 425 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_expresion_parentesis((yyvsp[-1].node), (yylsp[-2]).first_line, (yylsp[-2]).first_column);
    }
#line 2891 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 47: /* expresion: dato  */
#line 431 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2899 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 48: /* expresion: TOKEN_IDENTIFIER  */
#line 437 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_identifier((yyvsp[0].str), (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 2907 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 49: /* declaraciones: tipo TOKEN_IDENTIFIER TOKEN_ASSIGN expresion TOKEN_SEMICOLON  */
#line 444 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_declaracion_single((yyvsp[-4].node), (yyvsp[-3].str), (yyvsp[-1].node), (yylsp[-4]).first_line, (yylsp[-4]).first_column);
    }
#line 2915 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 50: /* declaraciones: tipo lista_declaraciones TOKEN_SEMICOLON  */
#line 448 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_declaracion_multiple((yyvsp[-2].node), (yyvsp[-1].node), (yylsp[-2]).first_line, (yylsp[-2]).first_column);
    }
#line 2923 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 51: /* declaraciones: tipo TOKEN_IDENTIFIER TOKEN_SEMICOLON  */
#line 452 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_declaracion_sin_inicializacion((yyvsp[-2].node), (yyvsp[-1].str), (yylsp[-2]).first_line, (yylsp[-2]).first_column);
    }
#line 2931 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 52: /* asignacion_compuesta: TOKEN_IDENTIFIER operador_asignacion expresion TOKEN_SEMICOLON  */
#line 459 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_asignacion_compuesta((yyvsp[-3].str), (yyvsp[-2].node), (yyvsp[-1].node), (yylsp[-3]).first_line, (yylsp[-3]).first_column);
    }
#line 2939 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 53: /* asignacion_compuesta: TOKEN_IDENTIFIER TOKEN_BRACKET_LEFT expresion TOKEN_BRACKET_RIGHT operador_asignacion expresion TOKEN_SEMICOLON  */
#line 464 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_asignacion_compuesta_array_1d((yyvsp[-6].str), (yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[-1].node), (yylsp[-6]).first_line, (yylsp[-6]).first_column);
    }
#line 2947 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 54: /* asignacion_compuesta: TOKEN_IDENTIFIER brackets_indices operador_asignacion expresion TOKEN_SEMICOLON  */
#line 469 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_asignacion_compuesta_array_multidimensional((yyvsp[-4].str), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yylsp[-4]).first_line, (yylsp[-4]).first_column);
    }
#line 2955 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 55: /* operador_asignacion: TOKEN_PLUS_ASSIGN  */
#line 477 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_operador_asignacion("+=", (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 2963 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 56: /* operador_asignacion: TOKEN_MINUS_ASSIGN  */
#line 481 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_operador_asignacion("-=", (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 2971 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 57: /* operador_asignacion: TOKEN_MULT_ASSIGN  */
#line 485 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_operador_asignacion("*=", (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 2979 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 58: /* operador_asignacion: TOKEN_DIV_ASSIGN  */
#line 489 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_operador_asignacion("/=", (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 2987 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 59: /* operador_asignacion: TOKEN_MOD_ASSIGN  */
#line 493 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_operador_asignacion("%=", (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 2995 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 60: /* operador_asignacion: TOKEN_AND_ASSIGN  */
#line 497 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_operador_asignacion("&=", (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 3003 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 61: /* operador_asignacion: TOKEN_OR_ASSIGN  */
#line 501 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_operador_asignacion("|=", (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 3011 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 62: /* operador_asignacion: TOKEN_XOR_ASSIGN  */
#line 505 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_operador_asignacion("^=", (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 3019 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 63: /* operador_asignacion: TOKEN_SHIFT_LEFT_ASSIGN  */
#line 509 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_operador_asignacion("<<=", (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 3027 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 64: /* operador_asignacion: TOKEN_SHIFT_RIGHT_ASSIGN  */
#line 513 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_operador_asignacion(">>=", (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 3035 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 65: /* operador_asignacion: TOKEN_ASSIGN  */
#line 517 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_operador_asignacion("=", (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 3043 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 66: /* tipo: TOKEN_STRING  */
#line 525 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_tipo_node("string", (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 3051 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 67: /* tipo: TOKEN_INT  */
#line 529 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_tipo_node("int", (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 3059 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 68: /* tipo: TOKEN_FLOAT  */
#line 533 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_tipo_node("float", (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 3067 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 69: /* tipo: TOKEN_CHAR  */
#line 537 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_tipo_node("char", (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 3075 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 70: /* tipo: TOKEN_BOOLEAN  */
#line 541 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_tipo_node("boolean", (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 3083 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 71: /* tipo: TOKEN_DOUBLE  */
#line 545 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_tipo_node("double", (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 3091 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 72: /* tipo: TOKEN_LONG  */
#line 549 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_tipo_node("long", (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 3099 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 73: /* tipo: TOKEN_SHORT  */
#line 553 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_tipo_node("short", (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 3107 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 74: /* tipo: TOKEN_BYTE  */
#line 557 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_tipo_node("byte", (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 3115 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 75: /* tipo: TOKEN_VOID  */
#line 561 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_tipo_node("void", (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 3123 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 76: /* dato: TOKEN_TYPE_STRING  */
#line 568 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_dato_string((yyvsp[0].str), (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 3131 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 77: /* dato: TOKEN_TYPE_INT  */
#line 572 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_dato_int((yyvsp[0].str), (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 3139 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 78: /* dato: TOKEN_TYPE_FLOAT  */
#line 576 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_dato_float((yyvsp[0].str), (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 3147 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 79: /* dato: TOKEN_TYPE_CHAR  */
#line 580 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_dato_char((yyvsp[0].str), (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 3155 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 80: /* dato: TOKEN_TYPE_TRUE  */
#line 584 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_dato_boolean((yyvsp[0].str), (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 3163 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 81: /* dato: TOKEN_TYPE_FALSE  */
#line 588 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_dato_boolean((yyvsp[0].str), (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 3171 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 82: /* dato: TOKEN_NULL  */
#line 592 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_dato_null((yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 3179 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 83: /* lista_declaraciones: lista_declaracion  */
#line 599 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_lista_declaraciones_single((yyvsp[0].node), (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 3187 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 84: /* lista_declaraciones: lista_declaraciones TOKEN_COMMA lista_declaracion  */
#line 603 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_lista_declaraciones_add((yyvsp[-2].node), (yyvsp[0].node));
    }
#line 3195 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 85: /* lista_declaracion: TOKEN_IDENTIFIER TOKEN_ASSIGN expresion  */
#line 610 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_lista_declaracion_node((yyvsp[-2].str), (yyvsp[0].node), (yylsp[-2]).first_line, (yylsp[-2]).first_column);
    }
#line 3203 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 86: /* sout: TOKEN_SOUT TOKEN_PAREN_LEFT expresion TOKEN_PAREN_RIGHT TOKEN_SEMICOLON  */
#line 617 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_sout_node((yyvsp[-2].node), (yylsp[-4]).first_line, (yylsp[-4]).first_column);
    }
#line 3211 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 87: /* sentencia_if: if_simple  */
#line 624 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 3219 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 88: /* sentencia_if: if_con_else  */
#line 628 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 3227 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 89: /* sentencia_if: if_con_else_if  */
#line 632 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 3235 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 90: /* if_simple: TOKEN_IF TOKEN_PAREN_LEFT expresion TOKEN_PAREN_RIGHT TOKEN_BRACE_LEFT instrucciones TOKEN_BRACE_RIGHT  */
#line 640 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_if_simple((yyvsp[-4].node), (yyvsp[-1].node), (yylsp[-6]).first_line, (yylsp[-6]).first_column);
    }
#line 3243 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 91: /* if_simple: TOKEN_IF TOKEN_PAREN_LEFT expresion TOKEN_PAREN_RIGHT instruccion  */
#line 645 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_if_simple_sin_llaves((yyvsp[-2].node), (yyvsp[0].node), (yylsp[-4]).first_line, (yylsp[-4]).first_column);
    }
#line 3251 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 92: /* if_con_else: TOKEN_IF TOKEN_PAREN_LEFT expresion TOKEN_PAREN_RIGHT TOKEN_BRACE_LEFT instrucciones TOKEN_BRACE_RIGHT TOKEN_ELSE TOKEN_BRACE_LEFT instrucciones TOKEN_BRACE_RIGHT  */
#line 653 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_if_con_else((yyvsp[-8].node), (yyvsp[-5].node), (yyvsp[-1].node), (yylsp[-10]).first_line, (yylsp[-10]).first_column);
    }
#line 3259 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 93: /* if_con_else: TOKEN_IF TOKEN_PAREN_LEFT expresion TOKEN_PAREN_RIGHT TOKEN_BRACE_LEFT instrucciones TOKEN_BRACE_RIGHT TOKEN_ELSE instruccion  */
#line 658 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_if_con_else_mixto_1((yyvsp[-6].node), (yyvsp[-3].node), (yyvsp[0].node), (yylsp[-8]).first_line, (yylsp[-8]).first_column);
    }
#line 3267 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 94: /* if_con_else: TOKEN_IF TOKEN_PAREN_LEFT expresion TOKEN_PAREN_RIGHT instruccion TOKEN_ELSE TOKEN_BRACE_LEFT instrucciones TOKEN_BRACE_RIGHT  */
#line 663 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_if_con_else_mixto_2((yyvsp[-6].node), (yyvsp[-4].node), (yyvsp[-1].node), (yylsp[-8]).first_line, (yylsp[-8]).first_column);
    }
#line 3275 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 95: /* if_con_else: TOKEN_IF TOKEN_PAREN_LEFT expresion TOKEN_PAREN_RIGHT instruccion TOKEN_ELSE instruccion  */
#line 668 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_if_con_else_sin_llaves((yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node), (yylsp[-6]).first_line, (yylsp[-6]).first_column);
    }
#line 3283 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 96: /* if_con_else_if: TOKEN_IF TOKEN_PAREN_LEFT expresion TOKEN_PAREN_RIGHT TOKEN_BRACE_LEFT instrucciones TOKEN_BRACE_RIGHT lista_else_if TOKEN_ELSE TOKEN_BRACE_LEFT instrucciones TOKEN_BRACE_RIGHT  */
#line 676 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_if_con_else_if((yyvsp[-9].node), (yyvsp[-6].node), (yyvsp[-4].node), (yyvsp[-1].node), (yylsp[-11]).first_line, (yylsp[-11]).first_column);
    }
#line 3291 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 97: /* if_con_else_if: TOKEN_IF TOKEN_PAREN_LEFT expresion TOKEN_PAREN_RIGHT instruccion lista_else_if_sin_llaves TOKEN_ELSE instruccion  */
#line 681 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_if_con_else_if_sin_llaves((yyvsp[-5].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[0].node), (yylsp[-7]).first_line, (yylsp[-7]).first_column);
    }
#line 3299 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 98: /* if_con_else_if: TOKEN_IF TOKEN_PAREN_LEFT expresion TOKEN_PAREN_RIGHT instruccion lista_else_if_sin_llaves  */
#line 686 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_if_con_else_if_sin_else_final((yyvsp[-3].node), (yyvsp[-1].node), (yyvsp[0].node), (yylsp[-5]).first_line, (yylsp[-5]).first_column);
    }
#line 3307 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 99: /* lista_else_if: lista_else_if else_if  */
#line 693 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_lista_else_if_add((yyvsp[-1].node), (yyvsp[0].node));
    }
#line 3315 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 100: /* lista_else_if: else_if  */
#line 697 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_lista_else_if_single((yyvsp[0].node), (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 3323 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 101: /* lista_else_if_sin_llaves: lista_else_if_sin_llaves else_if_sin_llaves  */
#line 705 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_lista_else_if_sin_llaves_add((yyvsp[-1].node), (yyvsp[0].node));
    }
#line 3331 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 102: /* lista_else_if_sin_llaves: else_if_sin_llaves  */
#line 709 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_lista_else_if_sin_llaves_single((yyvsp[0].node), (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 3339 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 103: /* else_if: TOKEN_ELSE TOKEN_IF TOKEN_PAREN_LEFT expresion TOKEN_PAREN_RIGHT TOKEN_BRACE_LEFT instrucciones TOKEN_BRACE_RIGHT  */
#line 717 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_else_if((yyvsp[-4].node), (yyvsp[-1].node), (yylsp[-7]).first_line, (yylsp[-7]).first_column);
    }
#line 3347 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 104: /* else_if_sin_llaves: TOKEN_ELSE TOKEN_IF TOKEN_PAREN_LEFT expresion TOKEN_PAREN_RIGHT instruccion  */
#line 725 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_else_if_sin_llaves((yyvsp[-2].node), (yyvsp[0].node), (yylsp[-5]).first_line, (yylsp[-5]).first_column);
    }
#line 3355 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 105: /* sentencias: TOKEN_BREAK TOKEN_SEMICOLON  */
#line 732 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_break((yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 3363 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 106: /* sentencias: TOKEN_CONTINUE TOKEN_SEMICOLON  */
#line 736 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_continue((yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 3371 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 107: /* sentencias: TOKEN_RETURN expresion TOKEN_SEMICOLON  */
#line 740 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_return_con_valor((yyvsp[-1].node), (yylsp[-2]).first_line, (yylsp[-2]).first_column);
    }
#line 3379 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 108: /* sentencias: TOKEN_RETURN TOKEN_SEMICOLON  */
#line 744 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_return_vacio((yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 3387 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 109: /* sentencia_switch: TOKEN_SWITCH TOKEN_PAREN_LEFT expresion TOKEN_PAREN_RIGHT TOKEN_BRACE_LEFT lista_case TOKEN_BRACE_RIGHT  */
#line 751 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_switch((yyvsp[-4].node), (yyvsp[-1].node), (yylsp[-6]).first_line, (yylsp[-6]).first_column);
    }
#line 3395 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 110: /* lista_case: lista_case case  */
#line 758 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_lista_casos_add((yyvsp[-1].node), (yyvsp[0].node));
    }
#line 3403 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 111: /* lista_case: case  */
#line 762 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_lista_casos_single((yyvsp[0].node), (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 3411 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 112: /* case: TOKEN_CASE dato TOKEN_COLON instrucciones sentencias  */
#line 769 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_caso((yyvsp[-3].node), (yyvsp[-1].node), (yyvsp[0].node), (yylsp[-4]).first_line, (yylsp[-4]).first_column);
    }
#line 3419 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 113: /* case: TOKEN_CASE dato TOKEN_COLON instrucciones sentencias TOKEN_DEFAULT TOKEN_COLON instrucciones  */
#line 773 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_caso_con_default((yyvsp[-6].node), (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[0].node), (yylsp[-7]).first_line, (yylsp[-7]).first_column);
    }
#line 3427 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 114: /* ciclo_while: TOKEN_WHILE TOKEN_PAREN_LEFT expresion TOKEN_PAREN_RIGHT TOKEN_BRACE_LEFT instrucciones TOKEN_BRACE_RIGHT  */
#line 780 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_while((yyvsp[-4].node), (yyvsp[-1].node), (yylsp[-6]).first_line, (yylsp[-6]).first_column);
    }
#line 3435 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 115: /* ciclo_do: TOKEN_DO TOKEN_BRACE_LEFT instrucciones TOKEN_BRACE_RIGHT TOKEN_WHILE TOKEN_PAREN_LEFT expresion TOKEN_PAREN_RIGHT TOKEN_SEMICOLON  */
#line 787 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_do_while((yyvsp[-6].node), (yyvsp[-2].node), (yylsp[-8]).first_line, (yylsp[-8]).first_column);
    }
#line 3443 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 116: /* ciclo_for: TOKEN_FOR TOKEN_PAREN_LEFT inicializacion_for TOKEN_SEMICOLON expresion TOKEN_SEMICOLON actualizar_for TOKEN_PAREN_RIGHT TOKEN_BRACE_LEFT instrucciones TOKEN_BRACE_RIGHT  */
#line 794 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_for((yyvsp[-8].node), (yyvsp[-6].node), (yyvsp[-4].node), (yyvsp[-1].node), (yylsp[-10]).first_line, (yylsp[-10]).first_column);  
    }
#line 3451 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 117: /* ciclo_for: TOKEN_FOR TOKEN_PAREN_LEFT tipo TOKEN_IDENTIFIER TOKEN_COLON TOKEN_IDENTIFIER TOKEN_PAREN_RIGHT TOKEN_BRACE_LEFT instrucciones TOKEN_BRACE_RIGHT  */
#line 798 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_for_each((yyvsp[-7].node), (yyvsp[-6].str), (yyvsp[-4].str), (yyvsp[-1].node), (yylsp[-9]).first_line, (yylsp[-9]).first_column);
    }
#line 3459 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 118: /* inicializacion_for: tipo TOKEN_IDENTIFIER TOKEN_ASSIGN expresion  */
#line 805 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_inicializacion_for_declaracion((yyvsp[-3].node), (yyvsp[-2].str), (yyvsp[0].node), (yylsp[-3]).first_line, (yylsp[-3]).first_column);
    }
#line 3467 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 119: /* inicializacion_for: TOKEN_IDENTIFIER operador_asignacion expresion  */
#line 809 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_inicializacion_for_asignacion((yyvsp[-2].str), (yyvsp[-1].node), (yyvsp[0].node), (yylsp[-2]).first_line, (yylsp[-2]).first_column);
    }
#line 3475 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 120: /* inicializacion_for: expresion  */
#line 813 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_inicializacion_for_expresion((yyvsp[0].node), (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 3483 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 121: /* inicializacion_for: %empty  */
#line 817 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_inicializacion_for_vacia(0, 0);
    }
#line 3491 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 122: /* actualizar_for: expresion  */
#line 824 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_actualizacion_for((yyvsp[0].node), (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 3499 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 123: /* actualizar_for: %empty  */
#line 828 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_actualizacion_for_vacia(0, 0);  // ← USAR 0, 0 en lugar de @1
    }
#line 3507 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 124: /* arrays: tipo TOKEN_BRACKET_LEFT TOKEN_BRACKET_RIGHT TOKEN_IDENTIFIER TOKEN_ASSIGN TOKEN_NEW tipo TOKEN_BRACKET_LEFT expresion TOKEN_BRACKET_RIGHT TOKEN_SEMICOLON  */
#line 836 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_vector_new((yyvsp[-10].node), (yyvsp[-7].str), (yyvsp[-4].node), (yyvsp[-2].node), (yylsp[-10]).first_line, (yylsp[-10]).first_column);
    }
#line 3515 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 125: /* arrays: tipo TOKEN_BRACKET_LEFT TOKEN_BRACKET_RIGHT TOKEN_IDENTIFIER TOKEN_ASSIGN TOKEN_BRACE_LEFT contenido_vector TOKEN_BRACE_RIGHT TOKEN_SEMICOLON  */
#line 841 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_vector_inicializado((yyvsp[-8].node), (yyvsp[-5].str), (yyvsp[-2].node), (yylsp[-8]).first_line, (yylsp[-8]).first_column);
    }
#line 3523 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 126: /* arrays: tipo TOKEN_IDENTIFIER brackets TOKEN_ASSIGN TOKEN_NEW tipo brackets_new TOKEN_SEMICOLON  */
#line 846 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_array_multidimensional_new((yyvsp[-7].node), (yyvsp[-5].node), (yyvsp[-6].str), (yyvsp[-2].node), (yyvsp[-1].node), (yylsp[-7]).first_line, (yylsp[-7]).first_column);
        //                                          ^^^ $3 = brackets, $2 = TOKEN_IDENTIFIER
    }
#line 3532 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 127: /* arrays: tipo TOKEN_IDENTIFIER brackets TOKEN_ASSIGN TOKEN_brace_block TOKEN_SEMICOLON  */
#line 852 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_array_multidimensional_inicializado((yyvsp[-5].node), (yyvsp[-3].node), (yyvsp[-4].str), (yyvsp[-1].node), (yylsp[-5]).first_line, (yylsp[-5]).first_column);
        //                                                   ^^^ $3 = brackets, $2 = TOKEN_IDENTIFIER
    }
#line 3541 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 128: /* contenido_vector: contenido_vector TOKEN_COMMA expresion  */
#line 860 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_contenido_vector_add((yyvsp[-2].node), (yyvsp[0].node));
    }
#line 3549 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 129: /* contenido_vector: expresion  */
#line 864 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_contenido_vector_single((yyvsp[0].node), (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 3557 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 130: /* lista_expresiones: lista_expresiones TOKEN_COMMA expresion  */
#line 871 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_lista_expresiones_add((yyvsp[-2].node), (yyvsp[0].node));
    }
#line 3565 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 131: /* lista_expresiones: expresion  */
#line 875 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_lista_expresiones_single((yyvsp[0].node), (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 3573 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 132: /* arrays_acceso: TOKEN_IDENTIFIER TOKEN_BRACKET_LEFT expresion TOKEN_BRACKET_RIGHT TOKEN_SEMICOLON  */
#line 882 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_array_acceso_1d((yyvsp[-4].str), (yyvsp[-2].node), (yylsp[-4]).first_line, (yylsp[-4]).first_column);
    }
#line 3581 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 133: /* arrays_acceso: TOKEN_IDENTIFIER brackets_indices TOKEN_SEMICOLON  */
#line 886 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_array_acceso_multidimensional((yyvsp[-2].str), (yyvsp[-1].node), (yylsp[-2]).first_line, (yylsp[-2]).first_column);
    }
#line 3589 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 134: /* brackets_indices: brackets_indices TOKEN_BRACKET_LEFT expresion TOKEN_BRACKET_RIGHT  */
#line 893 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_brackets_indices_add((yyvsp[-3].node), (yyvsp[-1].node));
    }
#line 3597 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 135: /* brackets_indices: TOKEN_BRACKET_LEFT expresion TOKEN_BRACKET_RIGHT  */
#line 897 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_brackets_indices_single((yyvsp[-1].node), (yylsp[-2]).first_line, (yylsp[-2]).first_column);
    }
#line 3605 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 136: /* arrays_asignacion: tipo TOKEN_IDENTIFIER TOKEN_ASSIGN TOKEN_IDENTIFIER TOKEN_BRACKET_LEFT expresion TOKEN_BRACKET_RIGHT TOKEN_SEMICOLON  */
#line 904 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_array_asignacion_1d((yyvsp[-7].node), (yyvsp[-6].str), (yyvsp[-4].str), (yyvsp[-2].node), (yylsp[-7]).first_line, (yylsp[-7]).first_column);
    }
#line 3613 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 137: /* arrays_asignacion: tipo TOKEN_IDENTIFIER TOKEN_ASSIGN TOKEN_IDENTIFIER brackets_indices TOKEN_SEMICOLON  */
#line 908 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_array_asignacion_multidimensional((yyvsp[-5].node), (yyvsp[-4].str), (yyvsp[-2].str), (yyvsp[-1].node), (yylsp[-5]).first_line, (yylsp[-5]).first_column);
    }
#line 3621 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 138: /* arrays_asignacion: TOKEN_IDENTIFIER brackets_indices TOKEN_ASSIGN expresion TOKEN_SEMICOLON  */
#line 912 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_array_asignacion_elemento((yyvsp[-4].str), (yyvsp[-3].node), (yyvsp[-1].node), (yylsp[-4]).first_line, (yylsp[-4]).first_column);
    }
#line 3629 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 139: /* brackets: brackets TOKEN_BRACKET_LEFT TOKEN_BRACKET_RIGHT  */
#line 921 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_brackets_add((yyvsp[-2].node), (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 3637 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 140: /* brackets: TOKEN_BRACKET_LEFT TOKEN_BRACKET_RIGHT  */
#line 925 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_brackets_single((yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 3645 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 141: /* brackets_new: brackets_new TOKEN_BRACKET_LEFT expresion TOKEN_BRACKET_RIGHT  */
#line 933 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_brackets_new_add((yyvsp[-3].node), (yyvsp[-1].node));
    }
#line 3653 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 142: /* brackets_new: TOKEN_BRACKET_LEFT expresion TOKEN_BRACKET_RIGHT  */
#line 937 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_brackets_new_single((yyvsp[-1].node), (yylsp[-2]).first_line, (yylsp[-2]).first_column);
    }
#line 3661 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 143: /* TOKEN_brace_block: TOKEN_BRACE_LEFT brace_elements TOKEN_BRACE_RIGHT  */
#line 945 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_brace_block((yyvsp[-1].node), (yylsp[-2]).first_line, (yylsp[-2]).first_column);
    }
#line 3669 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 144: /* brace_elements: brace_elements TOKEN_COMMA brace_element  */
#line 953 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_brace_elements_add((yyvsp[-2].node), (yyvsp[0].node));
    }
#line 3677 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 145: /* brace_elements: brace_element  */
#line 957 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_brace_elements_single((yyvsp[0].node), (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 3685 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 146: /* brace_element: TOKEN_brace_block  */
#line 964 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 3693 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 147: /* brace_element: lista_expresiones  */
#line 968 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 3701 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 148: /* funcion: tipo TOKEN_IDENTIFIER TOKEN_PAREN_LEFT parametros TOKEN_PAREN_RIGHT bloque_funcion  */
#line 975 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_funcion((yyvsp[-5].node), (yyvsp[-4].str), (yyvsp[-2].node), (yyvsp[0].node), (yylsp[-5]).first_line, (yylsp[-5]).first_column);
    }
#line 3709 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 149: /* parametros: parametro  */
#line 983 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_parametros_single((yyvsp[0].node), (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 3717 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 150: /* parametros: parametros TOKEN_COMMA parametro  */
#line 987 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_parametros_add((yyvsp[-2].node), (yyvsp[0].node));
    }
#line 3725 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 151: /* parametros: %empty  */
#line 991 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_parametros_vacio(0, 0);  // ← Usar 0, 0 como en otras reglas vacías
    }
#line 3733 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 152: /* parametro: tipo TOKEN_IDENTIFIER  */
#line 999 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_parametro_simple((yyvsp[-1].node), (yyvsp[0].str), (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 3741 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 153: /* parametro: tipo TOKEN_IDENTIFIER brackets  */
#line 1003 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_parametro_array((yyvsp[-2].node), (yyvsp[-1].str), (yyvsp[0].node), (yylsp[-2]).first_line, (yylsp[-2]).first_column);
    }
#line 3749 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 154: /* bloque_funcion: TOKEN_BRACE_LEFT cuerpo_funcion TOKEN_BRACE_RIGHT  */
#line 1010 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_bloque_funcion((yyvsp[-1].node), (yylsp[-2]).first_line, (yylsp[-2]).first_column);
    }
#line 3757 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 155: /* cuerpo_funcion: cuerpo_funcion elemento_funcion  */
#line 1017 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_cuerpo_funcion_add((yyvsp[-1].node), (yyvsp[0].node));
    }
#line 3765 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 156: /* cuerpo_funcion: elemento_funcion  */
#line 1021 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_cuerpo_funcion_single((yyvsp[0].node), (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 3773 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 157: /* cuerpo_funcion: %empty  */
#line 1025 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_cuerpo_funcion_vacio(0, 0);
    }
#line 3781 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 158: /* elemento_funcion: instruccion  */
#line 1032 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 3789 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 159: /* elemento_funcion: sentencias  */
#line 1036 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 3797 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 160: /* argumentos: argumentos TOKEN_COMMA expresion  */
#line 1044 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_argumentos_add((yyvsp[-2].node), (yyvsp[0].node));
    }
#line 3805 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 161: /* argumentos: expresion  */
#line 1048 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_argumentos_single((yyvsp[0].node), (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 3813 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 162: /* argumentos: %empty  */
#line 1052 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_argumentos_vacio(0, 0);
    }
#line 3821 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 163: /* embebidas: parseint_embebida  */
#line 1059 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 3829 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 164: /* embebidas: parsefloat_embebida  */
#line 1063 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 3837 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 165: /* embebidas: parsedouble_embebida  */
#line 1067 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 3845 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 166: /* embebidas: valueof_embebida  */
#line 1071 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 3853 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 167: /* embebidas: indexof_embebida  */
#line 1075 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 3861 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 168: /* embebidas: length_embebida  */
#line 1079 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 3869 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 169: /* embebidas: add_embebida  */
#line 1083 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 3877 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 170: /* embebidas: join_embebida  */
#line 1087 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 3885 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 171: /* parseint_embebida: TOKEN_PARSEINT TOKEN_PAREN_LEFT expresion TOKEN_PAREN_RIGHT  */
#line 1095 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_parseint_embebida((yyvsp[-1].node), (yylsp[-3]).first_line, (yylsp[-3]).first_column);
    }
#line 3893 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 172: /* parseint_embebida: TOKEN_PARSEINT TOKEN_PAREN_LEFT expresion TOKEN_COMMA expresion TOKEN_PAREN_RIGHT  */
#line 1100 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_parseint_embebida_radix((yyvsp[-3].node), (yyvsp[-1].node), (yylsp[-5]).first_line, (yylsp[-5]).first_column);
    }
#line 3901 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 173: /* parsedouble_embebida: TOKEN_PARSEDOUBLE TOKEN_PAREN_LEFT expresion TOKEN_PAREN_RIGHT  */
#line 1107 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_parsedouble_embebida((yyvsp[-1].node), (yylsp[-3]).first_line, (yylsp[-3]).first_column);
    }
#line 3909 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 174: /* parsefloat_embebida: TOKEN_PARSEFLOAT TOKEN_PAREN_LEFT expresion TOKEN_PAREN_RIGHT  */
#line 1114 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_parsefloat_embebida((yyvsp[-1].node), (yylsp[-3]).first_line, (yylsp[-3]).first_column);
    }
#line 3917 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 175: /* valueof_embebida: TOKEN_VALUEOF TOKEN_PAREN_LEFT expresion TOKEN_PAREN_RIGHT  */
#line 1121 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_valueof_embebida((yyvsp[-1].node), (yylsp[-3]).first_line, (yylsp[-3]).first_column);
    }
#line 3925 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 176: /* indexof_embebida: TOKEN_INDEXOF TOKEN_PAREN_LEFT expresion TOKEN_COMMA expresion TOKEN_PAREN_RIGHT  */
#line 1128 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_indexof_embebida((yyvsp[-3].node), (yyvsp[-1].node), (yylsp[-5]).first_line, (yylsp[-5]).first_column);
    }
#line 3933 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 177: /* length_embebida: expresion TOKEN_LENGTH  */
#line 1135 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_length_embebida((yyvsp[-1].node), (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 3941 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 178: /* add_embebida: expresion TOKEN_ADD TOKEN_PAREN_LEFT expresion TOKEN_PAREN_RIGHT  */
#line 1142 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_add_embebida((yyvsp[-4].node), (yyvsp[-1].node), (yylsp[-3]).first_line, (yylsp[-3]).first_column);
    }
#line 3949 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 179: /* join_embebida: TOKEN_STRINGJOIN TOKEN_PAREN_LEFT expresion TOKEN_COMMA contenido_vector TOKEN_PAREN_RIGHT  */
#line 1150 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_join_embebida((yyvsp[-3].node), (yyvsp[-1].node), (yylsp[-5]).first_line, (yylsp[-5]).first_column);
    }
#line 3957 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 180: /* join_embebida: TOKEN_STRINGJOIN TOKEN_PAREN_LEFT expresion TOKEN_COMMA expresion TOKEN_PAREN_RIGHT  */
#line 1154 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_join_embebida((yyvsp[-3].node), (yyvsp[-1].node), (yylsp[-5]).first_line, (yylsp[-5]).first_column);
    }
#line 3965 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;


#line 3969 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken, &yylloc};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
    }

  yyerror_range[1] = yylloc;
  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, &yylloc);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 1160 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"


void yyerror(const char* s) {
    printf("ERROR SINTACTICO en linea %d: %s (token actual: '%s')\n",
           yylineno, s, yytext ? yytext : "NULL");
    
    if (!global_error_manager) {
        global_error_manager = error_manager_create();
    }
    
    char simple_message[256];
    char token_display[64];
    
    if (yytext && strlen(yytext) > 0) {
        snprintf(token_display, sizeof(token_display), "'%s'", yytext);
    } else {
        strcpy(token_display, "desconocido");
    }
    
    snprintf(simple_message, sizeof(simple_message),
            "Error de sintaxis en el token %s", token_display);
    
    error_manager_add_sintactico(global_error_manager, yylineno, 0, simple_message, yytext);
}

/* FUNCIÓN DEL PARSER PARA SER LLAMADA DESDE CONTROL.C */
int parse_java_code(const char* filename) {
    printf("=== ANALIZADOR LEXICO-SINTACTICO JAVA ===\n");

    if (filename) {
        yyin = fopen(filename, "r");
        if (!yyin) {
            printf("Error: No se pudo abrir %s\n", filename);
            return 1;
        }
        printf("DEBUG: Archivo %s abierto correctamente\n", filename);
    } else {
        printf("DEBUG: Leyendo desde stdin\n");
    }

    printf("DEBUG: Iniciando analisis sintactico...\n");
    int result = yyparse();
    printf("DEBUG: yyparse() termino con codigo: %d\n", result);

    /* IMPRIMIR EL AST SI SE GENERÓ CORRECTAMENTE */
    if (result == 0 && ast_root != NULL) {
        printf("\n=== ÁRBOL SINTÁCTICO ABSTRACTO ===\n");
        print_node(ast_root, 0);
        printf("=== FIN AST ===\n\n");
    }

    /* IMPRIMIR ERRORES */
    if (global_error_manager && error_manager_has_errors(global_error_manager)) {
        printf("=== ERRORES DETECTADOS ===\n");
        ErrorNode* current = global_error_manager->head;
        
        while (current) {
            printf("[ERROR_%s] %d|%d|%s|%s\n",
                   error_type_name(current->type),
                   current->line,
                   current->column,
                   current->message ? current->message : "",
                   current->token_text ? current->token_text : "");
            current = current->next;
        }
        printf("=== FIN ERRORES ===\n");
    }

    if (result == 0) {
        printf("EXITO: Analisis completado\n");
    } else {
        printf("FALLO: Error en analisis\n");
    }

    if (yyin && yyin != stdin) {
        fclose(yyin);
    }

    return result;
}
