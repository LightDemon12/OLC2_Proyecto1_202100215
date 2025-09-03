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
#include "../../Headers/builder_casting.h" 

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

#line 115 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"

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
  YYSYMBOL_TOKEN_FINAL = 18,               /* TOKEN_FINAL  */
  YYSYMBOL_TOKEN_NULL = 19,                /* TOKEN_NULL  */
  YYSYMBOL_TOKEN_IDENTIFIER = 20,          /* TOKEN_IDENTIFIER  */
  YYSYMBOL_TOKEN_PLUS = 21,                /* TOKEN_PLUS  */
  YYSYMBOL_TOKEN_MINUS = 22,               /* TOKEN_MINUS  */
  YYSYMBOL_TOKEN_MULTIPLICATION = 23,      /* TOKEN_MULTIPLICATION  */
  YYSYMBOL_TOKEN_DIVISION = 24,            /* TOKEN_DIVISION  */
  YYSYMBOL_TOKEN_MODULE = 25,              /* TOKEN_MODULE  */
  YYSYMBOL_TOKEN_PLUS_ASSIGN = 26,         /* TOKEN_PLUS_ASSIGN  */
  YYSYMBOL_TOKEN_MINUS_ASSIGN = 27,        /* TOKEN_MINUS_ASSIGN  */
  YYSYMBOL_TOKEN_MULT_ASSIGN = 28,         /* TOKEN_MULT_ASSIGN  */
  YYSYMBOL_TOKEN_DIV_ASSIGN = 29,          /* TOKEN_DIV_ASSIGN  */
  YYSYMBOL_TOKEN_MOD_ASSIGN = 30,          /* TOKEN_MOD_ASSIGN  */
  YYSYMBOL_TOKEN_AND_ASSIGN = 31,          /* TOKEN_AND_ASSIGN  */
  YYSYMBOL_TOKEN_OR_ASSIGN = 32,           /* TOKEN_OR_ASSIGN  */
  YYSYMBOL_TOKEN_XOR_ASSIGN = 33,          /* TOKEN_XOR_ASSIGN  */
  YYSYMBOL_TOKEN_SHIFT_LEFT_ASSIGN = 34,   /* TOKEN_SHIFT_LEFT_ASSIGN  */
  YYSYMBOL_TOKEN_SHIFT_RIGHT_ASSIGN = 35,  /* TOKEN_SHIFT_RIGHT_ASSIGN  */
  YYSYMBOL_TOKEN_ASSIGN = 36,              /* TOKEN_ASSIGN  */
  YYSYMBOL_TOKEN_EQUAL = 37,               /* TOKEN_EQUAL  */
  YYSYMBOL_TOKEN_UNEQUAL = 38,             /* TOKEN_UNEQUAL  */
  YYSYMBOL_TOKEN_GREATER = 39,             /* TOKEN_GREATER  */
  YYSYMBOL_TOKEN_LESS = 40,                /* TOKEN_LESS  */
  YYSYMBOL_TOKEN_GREATER_EQUAL = 41,       /* TOKEN_GREATER_EQUAL  */
  YYSYMBOL_TOKEN_LESS_EQUAL = 42,          /* TOKEN_LESS_EQUAL  */
  YYSYMBOL_TOKEN_AND = 43,                 /* TOKEN_AND  */
  YYSYMBOL_TOKEN_OR = 44,                  /* TOKEN_OR  */
  YYSYMBOL_TOKEN_NOT = 45,                 /* TOKEN_NOT  */
  YYSYMBOL_TOKEN_PAREN_LEFT = 46,          /* TOKEN_PAREN_LEFT  */
  YYSYMBOL_TOKEN_PAREN_RIGHT = 47,         /* TOKEN_PAREN_RIGHT  */
  YYSYMBOL_TOKEN_SEMICOLON = 48,           /* TOKEN_SEMICOLON  */
  YYSYMBOL_TOKEN_DOT = 49,                 /* TOKEN_DOT  */
  YYSYMBOL_TOKEN_COMMA = 50,               /* TOKEN_COMMA  */
  YYSYMBOL_TOKEN_BRACE_LEFT = 51,          /* TOKEN_BRACE_LEFT  */
  YYSYMBOL_TOKEN_BRACE_RIGHT = 52,         /* TOKEN_BRACE_RIGHT  */
  YYSYMBOL_TOKEN_BRACKET_LEFT = 53,        /* TOKEN_BRACKET_LEFT  */
  YYSYMBOL_TOKEN_BRACKET_RIGHT = 54,       /* TOKEN_BRACKET_RIGHT  */
  YYSYMBOL_TOKEN_QUOTE_DOUBLE = 55,        /* TOKEN_QUOTE_DOUBLE  */
  YYSYMBOL_TOKEN_QUOTE_SINGLE = 56,        /* TOKEN_QUOTE_SINGLE  */
  YYSYMBOL_TOKEN_COLON = 57,               /* TOKEN_COLON  */
  YYSYMBOL_TOKEN_IF = 58,                  /* TOKEN_IF  */
  YYSYMBOL_TOKEN_ELSE = 59,                /* TOKEN_ELSE  */
  YYSYMBOL_TOKEN_SWITCH = 60,              /* TOKEN_SWITCH  */
  YYSYMBOL_TOKEN_CASE = 61,                /* TOKEN_CASE  */
  YYSYMBOL_TOKEN_DEFAULT = 62,             /* TOKEN_DEFAULT  */
  YYSYMBOL_TOKEN_WHILE = 63,               /* TOKEN_WHILE  */
  YYSYMBOL_TOKEN_DO = 64,                  /* TOKEN_DO  */
  YYSYMBOL_TOKEN_FOR = 65,                 /* TOKEN_FOR  */
  YYSYMBOL_TOKEN_BREAK = 66,               /* TOKEN_BREAK  */
  YYSYMBOL_TOKEN_CONTINUE = 67,            /* TOKEN_CONTINUE  */
  YYSYMBOL_TOKEN_RETURN = 68,              /* TOKEN_RETURN  */
  YYSYMBOL_TOKEN_SOUT = 69,                /* TOKEN_SOUT  */
  YYSYMBOL_TOKEN_PARSEINT = 70,            /* TOKEN_PARSEINT  */
  YYSYMBOL_TOKEN_PARSEFLOAT = 71,          /* TOKEN_PARSEFLOAT  */
  YYSYMBOL_TOKEN_PARSEDOUBLE = 72,         /* TOKEN_PARSEDOUBLE  */
  YYSYMBOL_TOKEN_VALUEOF = 73,             /* TOKEN_VALUEOF  */
  YYSYMBOL_TOKEN_STRINGJOIN = 74,          /* TOKEN_STRINGJOIN  */
  YYSYMBOL_TOKEN_INDEXOF = 75,             /* TOKEN_INDEXOF  */
  YYSYMBOL_TOKEN_LENGTH = 76,              /* TOKEN_LENGTH  */
  YYSYMBOL_TOKEN_ADD = 77,                 /* TOKEN_ADD  */
  YYSYMBOL_TOKEN_ESCAPE = 78,              /* TOKEN_ESCAPE  */
  YYSYMBOL_TOKEN_INCREMENT = 79,           /* TOKEN_INCREMENT  */
  YYSYMBOL_TOKEN_DECREMENT = 80,           /* TOKEN_DECREMENT  */
  YYSYMBOL_TOKEN_EOF = 81,                 /* TOKEN_EOF  */
  YYSYMBOL_TOKEN_ERROR = 82,               /* TOKEN_ERROR  */
  YYSYMBOL_TOKEN_TYPE_INT = 83,            /* TOKEN_TYPE_INT  */
  YYSYMBOL_TOKEN_TYPE_FLOAT = 84,          /* TOKEN_TYPE_FLOAT  */
  YYSYMBOL_TOKEN_TYPE_STRING = 85,         /* TOKEN_TYPE_STRING  */
  YYSYMBOL_TOKEN_TYPE_CHAR = 86,           /* TOKEN_TYPE_CHAR  */
  YYSYMBOL_TOKEN_TYPE_TRUE = 87,           /* TOKEN_TYPE_TRUE  */
  YYSYMBOL_TOKEN_TYPE_FALSE = 88,          /* TOKEN_TYPE_FALSE  */
  YYSYMBOL_TOKEN_TYPE_LONG = 89,           /* TOKEN_TYPE_LONG  */
  YYSYMBOL_TOKEN_TYPE_DOUBLE = 90,         /* TOKEN_TYPE_DOUBLE  */
  YYSYMBOL_YYACCEPT = 91,                  /* $accept  */
  YYSYMBOL_program = 92,                   /* program  */
  YYSYMBOL_bloque_main = 93,               /* bloque_main  */
  YYSYMBOL_instrucciones = 94,             /* instrucciones  */
  YYSYMBOL_instruccion = 95,               /* instruccion  */
  YYSYMBOL_expresion = 96,                 /* expresion  */
  YYSYMBOL_declaraciones = 97,             /* declaraciones  */
  YYSYMBOL_asignacion_compuesta = 98,      /* asignacion_compuesta  */
  YYSYMBOL_operador_asignacion = 99,       /* operador_asignacion  */
  YYSYMBOL_tipo = 100,                     /* tipo  */
  YYSYMBOL_dato = 101,                     /* dato  */
  YYSYMBOL_lista_declaraciones = 102,      /* lista_declaraciones  */
  YYSYMBOL_lista_declaracion = 103,        /* lista_declaracion  */
  YYSYMBOL_sout = 104,                     /* sout  */
  YYSYMBOL_sentencia_if = 105,             /* sentencia_if  */
  YYSYMBOL_if_simple = 106,                /* if_simple  */
  YYSYMBOL_if_con_else = 107,              /* if_con_else  */
  YYSYMBOL_if_con_else_if = 108,           /* if_con_else_if  */
  YYSYMBOL_lista_else_if = 109,            /* lista_else_if  */
  YYSYMBOL_lista_else_if_sin_llaves = 110, /* lista_else_if_sin_llaves  */
  YYSYMBOL_else_if = 111,                  /* else_if  */
  YYSYMBOL_else_if_sin_llaves = 112,       /* else_if_sin_llaves  */
  YYSYMBOL_sentencias = 113,               /* sentencias  */
  YYSYMBOL_sentencia_switch = 114,         /* sentencia_switch  */
  YYSYMBOL_lista_case = 115,               /* lista_case  */
  YYSYMBOL_case = 116,                     /* case  */
  YYSYMBOL_ciclo_while = 117,              /* ciclo_while  */
  YYSYMBOL_ciclo_do = 118,                 /* ciclo_do  */
  YYSYMBOL_ciclo_for = 119,                /* ciclo_for  */
  YYSYMBOL_inicializacion_for = 120,       /* inicializacion_for  */
  YYSYMBOL_actualizar_for = 121,           /* actualizar_for  */
  YYSYMBOL_arrays = 122,                   /* arrays  */
  YYSYMBOL_contenido_vector = 123,         /* contenido_vector  */
  YYSYMBOL_lista_expresiones = 124,        /* lista_expresiones  */
  YYSYMBOL_arrays_acceso = 125,            /* arrays_acceso  */
  YYSYMBOL_brackets_indices = 126,         /* brackets_indices  */
  YYSYMBOL_arrays_asignacion = 127,        /* arrays_asignacion  */
  YYSYMBOL_brackets = 128,                 /* brackets  */
  YYSYMBOL_brackets_new = 129,             /* brackets_new  */
  YYSYMBOL_TOKEN_brace_block = 130,        /* TOKEN_brace_block  */
  YYSYMBOL_brace_elements = 131,           /* brace_elements  */
  YYSYMBOL_brace_element = 132,            /* brace_element  */
  YYSYMBOL_funcion = 133,                  /* funcion  */
  YYSYMBOL_parametros = 134,               /* parametros  */
  YYSYMBOL_parametro = 135,                /* parametro  */
  YYSYMBOL_bloque_funcion = 136,           /* bloque_funcion  */
  YYSYMBOL_cuerpo_funcion = 137,           /* cuerpo_funcion  */
  YYSYMBOL_elemento_funcion = 138,         /* elemento_funcion  */
  YYSYMBOL_argumentos = 139,               /* argumentos  */
  YYSYMBOL_embebidas = 140,                /* embebidas  */
  YYSYMBOL_parseint_embebida = 141,        /* parseint_embebida  */
  YYSYMBOL_parsedouble_embebida = 142,     /* parsedouble_embebida  */
  YYSYMBOL_parsefloat_embebida = 143,      /* parsefloat_embebida  */
  YYSYMBOL_valueof_embebida = 144,         /* valueof_embebida  */
  YYSYMBOL_indexof_embebida = 145,         /* indexof_embebida  */
  YYSYMBOL_length_embebida = 146,          /* length_embebida  */
  YYSYMBOL_add_embebida = 147,             /* add_embebida  */
  YYSYMBOL_join_embebida = 148             /* join_embebida  */
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
#define YYLAST   3721

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  91
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  58
/* YYNRULES -- Number of rules.  */
#define YYNRULES  185
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  410

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   345


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
      85,    86,    87,    88,    89,    90
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   216,   216,   224,   231,   235,   242,   246,   250,   254,
     258,   262,   266,   270,   274,   278,   282,   286,   290,   294,
     298,   305,   309,   313,   319,   323,   327,   331,   335,   341,
     345,   351,   355,   359,   363,   369,   373,   379,   383,   387,
     391,   397,   402,   409,   415,   421,   426,   431,   437,   442,
     449,   453,   457,   462,   466,   473,   478,   483,   491,   495,
     499,   503,   507,   511,   515,   519,   523,   527,   531,   539,
     543,   547,   551,   555,   559,   563,   567,   571,   575,   582,
     586,   590,   594,   598,   602,   606,   610,   614,   621,   625,
     632,   639,   646,   650,   654,   662,   667,   675,   680,   685,
     690,   698,   703,   708,   715,   719,   727,   731,   739,   747,
     754,   758,   762,   766,   773,   780,   784,   791,   795,   802,
     809,   816,   820,   827,   831,   835,   840,   846,   851,   858,
     863,   868,   874,   882,   886,   893,   897,   904,   908,   915,
     919,   926,   930,   934,   943,   947,   955,   959,   967,   975,
     979,   986,   990,   997,  1005,  1009,  1014,  1021,  1025,  1032,
    1039,  1043,  1048,  1054,  1058,  1066,  1070,  1075,  1081,  1085,
    1089,  1093,  1097,  1101,  1105,  1109,  1117,  1122,  1129,  1136,
    1143,  1150,  1157,  1164,  1172,  1176
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
  "TOKEN_VOID", "TOKEN_MAIN", "TOKEN_FINAL", "TOKEN_NULL",
  "TOKEN_IDENTIFIER", "TOKEN_PLUS", "TOKEN_MINUS", "TOKEN_MULTIPLICATION",
  "TOKEN_DIVISION", "TOKEN_MODULE", "TOKEN_PLUS_ASSIGN",
  "TOKEN_MINUS_ASSIGN", "TOKEN_MULT_ASSIGN", "TOKEN_DIV_ASSIGN",
  "TOKEN_MOD_ASSIGN", "TOKEN_AND_ASSIGN", "TOKEN_OR_ASSIGN",
  "TOKEN_XOR_ASSIGN", "TOKEN_SHIFT_LEFT_ASSIGN",
  "TOKEN_SHIFT_RIGHT_ASSIGN", "TOKEN_ASSIGN", "TOKEN_EQUAL",
  "TOKEN_UNEQUAL", "TOKEN_GREATER", "TOKEN_LESS", "TOKEN_GREATER_EQUAL",
  "TOKEN_LESS_EQUAL", "TOKEN_AND", "TOKEN_OR", "TOKEN_NOT",
  "TOKEN_PAREN_LEFT", "TOKEN_PAREN_RIGHT", "TOKEN_SEMICOLON", "TOKEN_DOT",
  "TOKEN_COMMA", "TOKEN_BRACE_LEFT", "TOKEN_BRACE_RIGHT",
  "TOKEN_BRACKET_LEFT", "TOKEN_BRACKET_RIGHT", "TOKEN_QUOTE_DOUBLE",
  "TOKEN_QUOTE_SINGLE", "TOKEN_COLON", "TOKEN_IF", "TOKEN_ELSE",
  "TOKEN_SWITCH", "TOKEN_CASE", "TOKEN_DEFAULT", "TOKEN_WHILE", "TOKEN_DO",
  "TOKEN_FOR", "TOKEN_BREAK", "TOKEN_CONTINUE", "TOKEN_RETURN",
  "TOKEN_SOUT", "TOKEN_PARSEINT", "TOKEN_PARSEFLOAT", "TOKEN_PARSEDOUBLE",
  "TOKEN_VALUEOF", "TOKEN_STRINGJOIN", "TOKEN_INDEXOF", "TOKEN_LENGTH",
  "TOKEN_ADD", "TOKEN_ESCAPE", "TOKEN_INCREMENT", "TOKEN_DECREMENT",
  "TOKEN_EOF", "TOKEN_ERROR", "TOKEN_TYPE_INT", "TOKEN_TYPE_FLOAT",
  "TOKEN_TYPE_STRING", "TOKEN_TYPE_CHAR", "TOKEN_TYPE_TRUE",
  "TOKEN_TYPE_FALSE", "TOKEN_TYPE_LONG", "TOKEN_TYPE_DOUBLE", "$accept",
  "program", "bloque_main", "instrucciones", "instruccion", "expresion",
  "declaraciones", "asignacion_compuesta", "operador_asignacion", "tipo",
  "dato", "lista_declaraciones", "lista_declaracion", "sout",
  "sentencia_if", "if_simple", "if_con_else", "if_con_else_if",
  "lista_else_if", "lista_else_if_sin_llaves", "else_if",
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

#define YYPACT_NINF (-298)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-118)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       3,    11,    18,  -298,    28,  -298,    13,    30,    17,    43,
    2018,  -298,  -298,  -298,  -298,  -298,  -298,  -298,  -298,  -298,
    -298,   562,  -298,   287,  2183,  2183,   178,    53,    63,    80,
      47,    86,    79,   108,   147,   119,   122,   124,   125,   126,
     127,   130,  2183,  2183,  -298,  -298,  -298,  -298,  -298,  -298,
    -298,  -298,    50,  -298,  2325,  -298,  -298,   -16,  -298,  -298,
    -298,  -298,  -298,  -298,  -298,  -298,  -298,  -298,  -298,  -298,
    -298,  -298,  -298,  3603,  -298,  -298,  -298,  -298,  -298,  -298,
    -298,  -298,   157,   144,  -298,  -298,  -298,  -298,  -298,  -298,
    -298,  -298,  -298,  -298,  -298,  2183,  2183,  2183,  -298,  -298,
    2183,   785,    95,     0,  -298,   179,  2366,   149,  2183,  2183,
    2183,  2018,   471,  -298,  -298,  -298,  2407,  2183,  2183,  2183,
    2183,  2183,  2183,  2183,   179,   179,  -298,  -298,   153,  2183,
    2183,  2183,  2183,  2183,  2183,  2183,  2183,  2183,  2183,  2183,
    2183,  2183,  -298,  -298,   155,   106,   148,    -7,  -298,   167,
      15,  2183,  3644,    -2,  3644,  2448,  2456,    -6,  -298,  2183,
    2183,  2183,   151,  -298,  2183,  2497,  2538,  2579,   698,   700,
    3644,   185,   159,  -298,  2620,  2284,  2661,  2702,  2743,  2784,
    2825,  2183,     0,     0,   179,   179,   179,    10,    10,   139,
     139,   139,   139,   265,   567,  2183,  2214,   562,  -298,   154,
     -26,   189,  -298,   190,  2183,  -298,  2866,  -298,  2183,   873,
    -298,  2907,  2948,  2956,  2997,   179,   786,   162,   163,   152,
    2183,   -21,  2183,   168,  -298,  2183,  -298,  -298,  -298,  2183,
    2183,  3005,  3046,   100,  3087,   205,    56,  -298,  -298,    -5,
     174,   193,   202,  -298,  3128,  -298,  3644,  -298,  2183,  -298,
    -298,  -298,  -298,  2018,   180,   181,  2018,   194,  3644,  2183,
     221,  3169,  -298,  3210,  3251,    81,  3292,  -298,  -298,  2183,
      14,  -298,   191,   203,   562,   562,  2137,   212,  -298,    -4,
    2183,  -298,  3333,   874,   962,   211,  -298,     2,   -41,  -298,
    1050,  2183,  3644,   224,  2183,  -298,  -298,  -298,  2183,  -298,
    3374,  -298,   219,  2018,  -298,  -298,   222,  3644,   228,  -298,
      93,  -298,  -298,   562,  2183,  3644,  -298,   220,  2018,   235,
    -298,  2106,  -298,   225,  -298,  -298,  -298,  3382,   232,  3644,
     237,  3644,   243,  -298,  -298,  1138,  -298,  2183,    52,  2183,
    2137,  -298,   239,  3644,   105,  1226,   226,  -298,  1314,  2183,
    -298,  2018,   249,  2018,   247,  -298,  -298,  -298,  3423,  -298,
    2183,  3644,  -298,  2183,   253,  2018,   263,  -298,    46,  -298,
    -298,  3431,  2018,  -298,  1402,  2018,  -298,  3472,  3480,  -298,
    1490,  2183,  2018,   264,   786,   -33,  -298,  1578,  -298,   276,
    -298,  3521,  1666,  2183,   180,   255,  -298,  -298,  1754,  -298,
    3562,  2018,  2018,   275,  2018,  1842,  2018,   220,  1930,  -298
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     2,     0,     1,     0,     0,     0,     0,
       0,    70,    71,    69,    72,    73,    74,    75,    76,    77,
      78,     0,    87,    49,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    80,    82,    79,    84,    85,    86,
      81,    83,     0,     4,     0,     7,     8,     0,    48,     6,
      10,    92,    93,    94,    19,    11,    12,    13,    14,    15,
      16,    17,    18,    20,   168,   170,   169,   171,   172,   173,
     174,   175,     0,     0,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,   167,     0,     0,    41,    42,
       0,    44,    49,    40,    21,    37,     0,     0,     0,     0,
       0,     0,   126,   110,   111,   113,     0,     0,     0,     0,
       0,     0,     0,     0,    38,    39,     3,     5,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     9,   182,     0,     0,     0,     0,    88,     0,
       0,     0,   166,     0,    45,     0,     0,    68,   138,     0,
       0,     0,    44,    47,     0,     0,     0,     0,     0,    49,
     125,     0,     0,   112,     0,     0,     0,     0,     0,     0,
       0,     0,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,     0,     0,   156,    52,     0,
       0,     0,    51,     0,     0,    54,     0,    43,     0,   140,
      55,     0,     0,     0,     0,    46,     0,     0,     0,     0,
       0,     0,     0,     0,   176,     0,   179,   178,   180,     0,
       0,     0,     0,    49,    90,     0,     0,   154,   145,     0,
       0,     0,     0,    89,    90,    23,   165,   137,     0,   143,
     139,    57,   140,     0,    96,     0,     0,     0,   124,     0,
       0,     0,    91,     0,   134,     0,     0,    22,   183,     0,
      44,    50,   157,     0,     0,     0,     0,     0,   144,     0,
       0,    53,     0,     0,     0,   103,   107,     0,     0,   116,
       0,     0,   123,     0,   128,   177,   185,   184,     0,   181,
       0,   142,   158,   162,   153,   155,     0,   136,   152,   151,
       0,   150,   132,     0,     0,    90,    56,    95,     0,     0,
     100,     0,   106,     0,   114,   115,   119,     0,     0,   127,
       0,   133,   140,   163,    19,     0,   161,     0,     0,     0,
       0,   148,     0,   134,     0,     0,     0,   105,     0,     0,
     102,     0,     0,     0,     0,   141,   159,   160,     0,   131,
       0,   135,   149,     0,     0,     0,     0,    98,     0,   104,
      99,     0,     0,   120,     0,     0,   147,     0,     0,   130,
       0,     0,     0,     0,     0,    19,   122,     0,   146,     0,
      97,     0,     0,     0,    96,     0,   121,   129,     0,   101,
       0,     0,     0,     0,   118,     0,     0,    95,     0,   108
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -298,  -298,  -298,  -106,   292,   305,  -298,  -298,   -98,   -19,
      40,   246,   129,  -298,  -298,  -298,  -298,  -298,  -298,  -298,
     -12,    57,  -297,  -298,  -298,    49,  -298,  -298,  -298,  -298,
    -298,  -298,    31,  -298,  -298,   -22,  -298,    74,  -298,   110,
    -298,    12,  -298,  -298,    76,  -298,  -298,    16,  -298,   -10,
    -298,  -298,  -298,  -298,  -298,  -298,  -298,  -298
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     2,     3,    52,    53,    54,    55,    56,   100,    57,
      58,   147,   148,    59,    60,    61,    62,    63,   346,   285,
     347,   286,    64,    65,   288,   289,    66,    67,    68,   172,
     330,    69,   265,   308,    70,   162,    71,   200,   338,   309,
     310,   311,    72,   236,   237,   304,   335,   336,   153,   104,
      74,    75,    76,    77,    78,    79,    80,    81
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      73,   101,    82,   160,   145,   168,   334,   107,   275,   313,
     239,   324,   128,    22,   102,   259,    24,     1,     5,  -117,
     287,    22,   128,   131,   132,   133,     4,   240,  -117,   395,
       7,   129,   130,   131,   132,   133,   260,   146,   334,    25,
      26,   202,    73,   203,     6,   207,   276,   314,   208,   136,
     137,   138,   139,    11,    12,    13,    14,    15,    16,    17,
      18,    19,   301,   205,     9,   203,    20,   159,    21,    22,
      23,   220,    24,    42,    43,   385,     8,    44,    45,    46,
      47,    48,    49,    50,    51,    44,    45,    46,    47,    48,
      49,    50,    51,   171,    10,    25,    26,   382,   111,   108,
     359,    73,   126,   273,   383,   360,   274,    83,    27,   109,
      28,   248,    83,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,   110,   113,   297,    42,
      43,   298,   112,    44,    45,    46,    47,    48,    49,    50,
      51,    95,   196,   340,    96,   341,    95,   283,   161,    96,
     290,   128,   197,   269,   198,   298,   114,   364,    73,   199,
     129,   130,   131,   132,   133,   117,    22,   102,   118,    24,
     119,   120,   121,   122,    98,    99,   123,   149,   235,    98,
      99,    11,    12,    13,    14,    15,    16,    17,    18,    19,
     151,   128,    25,    26,    20,   115,   164,    22,   102,   181,
      24,   195,   201,   204,   159,   221,    73,   222,   238,   241,
     242,   270,   348,   255,   256,   257,   262,    36,    37,    38,
      39,    40,    41,    25,    26,   272,    42,    43,   278,   279,
      44,    45,    46,    47,    48,    49,    50,    51,   280,   284,
     291,   293,   287,    73,   199,   372,    73,   374,    36,    37,
      38,    39,    40,    41,   303,   235,   306,    42,    43,   380,
     312,    44,    45,    46,    47,    48,    49,    50,    51,   387,
     321,   328,   240,    73,    73,   337,   392,   128,   339,   345,
      73,   349,   351,   353,   354,   368,   129,   130,   131,   132,
     133,   355,   363,    73,   342,   404,   405,   373,   375,    83,
     408,   379,   134,   135,   136,   137,   138,   139,    73,   381,
     393,    73,   401,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,   397,    73,   406,   323,   150,   103,
     105,   106,   243,    95,   369,    73,    96,   325,    73,   116,
      97,    73,   322,    73,   127,   344,   302,   124,   125,   277,
     305,   357,   362,     0,     0,    73,     0,     0,     0,     0,
       0,     0,    73,     0,    73,    73,    98,    99,     0,     0,
      73,     0,    73,     0,    73,     0,     0,    73,     0,     0,
       0,     0,    73,     0,     0,     0,     0,     0,    73,     0,
       0,    73,    73,     0,    73,    73,    73,     0,    73,     0,
     152,   154,   155,     0,     0,   156,     0,     0,     0,     0,
       0,     0,     0,   165,   166,   167,     0,   170,     0,     0,
       0,     0,   174,   175,   176,   177,   178,   179,   180,     0,
       0,     0,     0,     0,   182,   183,   184,   185,   186,   187,
     188,   189,   190,   191,   192,   193,   194,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   206,     0,     0,     0,
     127,     0,   211,     0,   212,   213,   214,     0,     0,   215,
       0,     0,     0,     0,    11,    12,    13,    14,    15,    16,
      17,    18,    19,     0,     0,     0,   231,    20,     0,     0,
      22,   169,     0,    24,     0,     0,     0,     0,     0,     0,
     232,   234,     0,     0,     0,     0,     0,     0,   254,   244,
       0,     0,     0,   246,     0,     0,    25,    26,     0,     0,
       0,     0,     0,     0,     0,   258,     0,   261,     0,     0,
     263,     0,     0,     0,   264,   266,     0,     0,     0,     0,
       0,    36,    37,    38,    39,    40,    41,     0,     0,     0,
      42,    43,     0,   282,    44,    45,    46,    47,    48,    49,
      50,    51,     0,     0,   292,    11,    12,    13,    14,    15,
      16,    17,    18,    19,   300,   127,   320,     0,    20,   128,
       0,   307,   127,     0,     0,   315,     0,     0,   129,   130,
     131,   132,   133,     0,     0,   333,   327,     0,     0,   329,
       0,     0,     0,   331,   134,   135,   136,   137,   138,   139,
     140,     0,     0,   350,     0,     0,     0,     0,     0,   343,
       0,     0,     0,     0,     0,     0,     0,   333,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   367,     0,     0,
     127,     0,   358,     0,   361,   307,     0,     0,     0,     0,
       0,     0,     0,     0,   371,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   127,   377,   127,     0,   378,     0,
       0,     0,   127,     0,     0,     0,   394,     0,     0,   127,
       0,     0,     0,     0,   127,     0,   391,     0,     0,     0,
     254,     0,     0,     0,     0,     0,   127,   127,   400,     0,
     127,    11,    12,    13,    14,    15,    16,    17,    18,    19,
       0,     0,    83,     0,    20,     0,    21,    22,    23,     0,
      24,     0,     0,     0,     0,     0,    84,    85,    86,    87,
      88,    89,    90,    91,    92,    93,    94,     0,     0,     0,
       0,     0,     0,    25,    26,     0,    95,     0,     0,    96,
     219,     0,     0,   161,     0,     0,    27,     0,    28,     0,
       0,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,     0,     0,     0,    42,    43,    98,
      99,    44,    45,    46,    47,    48,    49,    50,    51,    11,
      12,    13,    14,    15,    16,    17,    18,    19,     0,     0,
       0,     0,    20,     0,    21,    22,    23,     0,    24,     0,
       0,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,   157,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    25,    26,   158,     0,     0,     0,   253,   159,     0,
       0,     0,     0,     0,    27,     0,    28,     0,     0,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,     0,     0,     0,    42,    43,     0,     0,    44,
      45,    46,    47,    48,    49,    50,    51,    11,    12,    13,
      14,    15,    16,    17,    18,    19,     0,     0,     0,     0,
      20,     0,    21,    22,    23,     0,    24,     0,     0,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    25,
      26,   247,     0,     0,     0,     0,   317,     0,     0,     0,
       0,     0,    27,     0,    28,     0,     0,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
       0,     0,     0,    42,    43,     0,     0,    44,    45,    46,
      47,    48,    49,    50,    51,    11,    12,    13,    14,    15,
      16,    17,    18,    19,     0,     0,     0,     0,    20,     0,
      21,    22,    23,     0,    24,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    25,    26,     0,
       0,     0,     0,   318,     0,     0,     0,     0,     0,     0,
     319,     0,    28,     0,     0,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,     0,     0,
       0,    42,    43,     0,     0,    44,    45,    46,    47,    48,
      49,    50,    51,    11,    12,    13,    14,    15,    16,    17,
      18,    19,     0,     0,     0,     0,    20,     0,    21,    22,
      23,     0,    24,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    25,    26,     0,     0,     0,
       0,     0,   326,     0,     0,     0,     0,     0,    27,     0,
      28,     0,     0,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,     0,     0,     0,    42,
      43,     0,     0,    44,    45,    46,    47,    48,    49,    50,
      51,    11,    12,    13,    14,    15,    16,    17,    18,    19,
       0,     0,     0,     0,    20,     0,    21,    22,    23,     0,
      24,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    25,    26,     0,     0,     0,     0,     0,
     356,     0,     0,     0,     0,     0,    27,     0,    28,     0,
       0,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,     0,     0,     0,    42,    43,     0,
       0,    44,    45,    46,    47,    48,    49,    50,    51,    11,
      12,    13,    14,    15,    16,    17,    18,    19,     0,     0,
       0,     0,    20,     0,    21,    22,    23,     0,    24,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    25,    26,     0,     0,     0,     0,   365,     0,     0,
       0,     0,     0,     0,   366,     0,    28,     0,     0,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,     0,     0,     0,    42,    43,     0,     0,    44,
      45,    46,    47,    48,    49,    50,    51,    11,    12,    13,
      14,    15,    16,    17,    18,    19,     0,     0,     0,     0,
      20,     0,    21,    22,    23,     0,    24,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    25,
      26,     0,     0,     0,     0,     0,   370,     0,     0,     0,
       0,     0,    27,     0,    28,     0,     0,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
       0,     0,     0,    42,    43,     0,     0,    44,    45,    46,
      47,    48,    49,    50,    51,    11,    12,    13,    14,    15,
      16,    17,    18,    19,     0,     0,     0,     0,    20,     0,
      21,    22,    23,     0,    24,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    25,    26,     0,
       0,     0,     0,     0,   386,     0,     0,     0,     0,     0,
      27,     0,    28,     0,     0,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,     0,     0,
       0,    42,    43,     0,     0,    44,    45,    46,    47,    48,
      49,    50,    51,    11,    12,    13,    14,    15,    16,    17,
      18,    19,     0,     0,     0,     0,    20,     0,    21,    22,
      23,     0,    24,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    25,    26,     0,     0,     0,
       0,     0,   390,     0,     0,     0,     0,     0,    27,     0,
      28,     0,     0,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,     0,     0,     0,    42,
      43,     0,     0,    44,    45,    46,    47,    48,    49,    50,
      51,    11,    12,    13,    14,    15,    16,    17,    18,    19,
       0,     0,     0,     0,    20,     0,    21,    22,    23,     0,
      24,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    25,    26,     0,     0,     0,     0,     0,
     396,     0,     0,     0,     0,     0,    27,     0,    28,     0,
       0,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,     0,     0,     0,    42,    43,     0,
       0,    44,    45,    46,    47,    48,    49,    50,    51,    11,
      12,    13,    14,    15,    16,    17,    18,    19,     0,     0,
       0,     0,    20,     0,    21,    22,    23,     0,    24,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    25,    26,     0,     0,     0,     0,     0,   399,     0,
       0,     0,     0,     0,    27,     0,    28,     0,     0,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,     0,     0,     0,    42,    43,     0,     0,    44,
      45,    46,    47,    48,    49,    50,    51,    11,    12,    13,
      14,    15,    16,    17,    18,    19,     0,     0,     0,     0,
      20,     0,    21,    22,    23,     0,    24,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    25,
      26,     0,     0,     0,     0,   402,     0,     0,     0,     0,
       0,     0,    27,     0,    28,     0,     0,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
       0,     0,     0,    42,    43,     0,     0,    44,    45,    46,
      47,    48,    49,    50,    51,    11,    12,    13,    14,    15,
      16,    17,    18,    19,     0,     0,     0,     0,    20,     0,
      21,    22,    23,     0,    24,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    25,    26,     0,
       0,     0,     0,     0,   407,     0,     0,     0,     0,     0,
      27,     0,    28,     0,     0,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,     0,     0,
       0,    42,    43,     0,     0,    44,    45,    46,    47,    48,
      49,    50,    51,    11,    12,    13,    14,    15,    16,    17,
      18,    19,     0,     0,     0,     0,    20,     0,    21,    22,
      23,     0,    24,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    25,    26,     0,     0,     0,
       0,     0,   409,     0,     0,     0,     0,     0,    27,     0,
      28,     0,     0,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,     0,     0,     0,    42,
      43,     0,     0,    44,    45,    46,    47,    48,    49,    50,
      51,    11,    12,    13,    14,    15,    16,    17,    18,    19,
       0,     0,     0,     0,    20,     0,    21,    22,    23,     0,
      24,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    25,    26,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    27,     0,    28,     0,
       0,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,     0,     0,     0,    42,    43,     0,
       0,    44,    45,    46,    47,    48,    49,    50,    51,    11,
      12,    13,    14,    15,    16,    17,    18,    19,     0,     0,
       0,     0,    20,     0,    21,    22,    23,     0,    24,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    25,    26,     0,     0,     0,    22,   102,     0,    24,
       0,     0,     0,     0,   319,     0,    28,     0,     0,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    25,    26,     0,    42,    43,     0,   276,    44,
      45,    46,    47,    48,    49,    50,    51,     0,     0,     0,
       0,     0,    22,   102,     0,    24,     0,    36,    37,    38,
      39,    40,    41,     0,     0,     0,    42,    43,     0,     0,
      44,    45,    46,    47,    48,    49,    50,    51,    25,    26,
       0,     0,     0,    22,   233,     0,    24,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    36,    37,    38,    39,    40,    41,    25,
      26,     0,    42,    43,     0,     0,    44,    45,    46,    47,
      48,    49,    50,    51,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    36,    37,    38,    39,    40,    41,
       0,     0,     0,    42,    43,     0,   128,    44,    45,    46,
      47,    48,    49,    50,    51,   129,   130,   131,   132,   133,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   134,   135,   136,   137,   138,   139,   140,   141,     0,
       0,   224,     0,     0,   225,     0,     0,   128,     0,     0,
       0,     0,     0,     0,     0,     0,   129,   130,   131,   132,
     133,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     143,   144,   134,   135,   136,   137,   138,   139,   140,   141,
       0,     0,     0,   142,     0,     0,     0,     0,   128,     0,
       0,     0,     0,     0,     0,     0,     0,   129,   130,   131,
     132,   133,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   143,   144,   134,   135,   136,   137,   138,   139,   140,
     141,     0,     0,   163,     0,     0,     0,     0,     0,   128,
       0,     0,     0,     0,     0,     0,     0,     0,   129,   130,
     131,   132,   133,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   143,   144,   134,   135,   136,   137,   138,   139,
     140,   141,     0,     0,     0,   173,     0,     0,     0,     0,
     128,     0,     0,     0,     0,     0,     0,     0,   128,   129,
     130,   131,   132,   133,     0,     0,     0,   129,   130,   131,
     132,   133,     0,   143,   144,   134,   135,   136,   137,   138,
     139,   140,   141,   134,   135,   136,   137,   138,   139,   140,
     141,     0,   209,     0,   210,     0,     0,     0,     0,   128,
       0,     0,     0,     0,     0,     0,     0,     0,   129,   130,
     131,   132,   133,     0,   143,   144,     0,     0,     0,     0,
       0,     0,   143,   144,   134,   135,   136,   137,   138,   139,
     140,   141,     0,     0,   216,     0,     0,     0,     0,     0,
     128,     0,     0,     0,     0,     0,     0,     0,     0,   129,
     130,   131,   132,   133,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   143,   144,   134,   135,   136,   137,   138,
     139,   140,   141,     0,     0,   217,     0,     0,     0,     0,
       0,   128,     0,     0,     0,     0,     0,     0,     0,     0,
     129,   130,   131,   132,   133,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   143,   144,   134,   135,   136,   137,
     138,   139,   140,   141,     0,     0,   218,     0,     0,     0,
       0,     0,   128,     0,     0,     0,     0,     0,     0,     0,
       0,   129,   130,   131,   132,   133,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   143,   144,   134,   135,   136,
     137,   138,   139,   140,   141,     0,     0,   223,     0,     0,
       0,     0,     0,   128,     0,     0,     0,     0,     0,     0,
       0,     0,   129,   130,   131,   132,   133,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   143,   144,   134,   135,
     136,   137,   138,   139,   140,   141,     0,     0,   226,     0,
       0,     0,     0,     0,   128,     0,     0,     0,     0,     0,
       0,     0,     0,   129,   130,   131,   132,   133,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   143,   144,   134,
     135,   136,   137,   138,   139,   140,   141,     0,     0,   227,
       0,     0,     0,     0,     0,   128,     0,     0,     0,     0,
       0,     0,     0,     0,   129,   130,   131,   132,   133,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   143,   144,
     134,   135,   136,   137,   138,   139,   140,   141,     0,     0,
     228,     0,     0,     0,     0,     0,   128,     0,     0,     0,
       0,     0,     0,     0,     0,   129,   130,   131,   132,   133,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   143,
     144,   134,   135,   136,   137,   138,   139,   140,   141,     0,
       0,     0,     0,     0,   229,     0,     0,   128,     0,     0,
       0,     0,     0,     0,     0,     0,   129,   130,   131,   132,
     133,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     143,   144,   134,   135,   136,   137,   138,   139,   140,   141,
       0,     0,     0,     0,     0,   230,     0,     0,   128,     0,
       0,     0,     0,     0,     0,     0,     0,   129,   130,   131,
     132,   133,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   143,   144,   134,   135,   136,   137,   138,   139,   140,
     141,     0,     0,   245,     0,     0,     0,     0,     0,   128,
       0,     0,     0,     0,     0,     0,     0,     0,   129,   130,
     131,   132,   133,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   143,   144,   134,   135,   136,   137,   138,   139,
     140,   141,     0,     0,     0,   249,     0,     0,     0,     0,
     128,     0,     0,     0,     0,     0,     0,     0,   128,   129,
     130,   131,   132,   133,     0,     0,     0,   129,   130,   131,
     132,   133,     0,   143,   144,   134,   135,   136,   137,   138,
     139,   140,   141,   134,   135,   136,   137,   138,   139,   140,
     141,     0,   250,     0,   251,     0,     0,     0,     0,   128,
       0,     0,     0,     0,     0,     0,     0,   128,   129,   130,
     131,   132,   133,     0,   143,   144,   129,   130,   131,   132,
     133,     0,   143,   144,   134,   135,   136,   137,   138,   139,
     140,   141,   134,   135,   136,   137,   138,   139,   140,   141,
       0,   252,   267,     0,     0,     0,     0,     0,   128,     0,
       0,     0,     0,     0,     0,     0,     0,   129,   130,   131,
     132,   133,     0,   143,   144,     0,     0,     0,     0,     0,
       0,   143,   144,   134,   135,   136,   137,   138,   139,   140,
     141,     0,     0,   268,     0,     0,     0,     0,     0,   128,
       0,     0,     0,     0,     0,     0,     0,     0,   129,   130,
     131,   132,   133,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   143,   144,   134,   135,   136,   137,   138,   139,
     140,   141,     0,     0,     0,   271,     0,     0,     0,     0,
     128,     0,     0,     0,     0,     0,     0,     0,     0,   129,
     130,   131,   132,   133,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   143,   144,   134,   135,   136,   137,   138,
     139,   140,   141,     0,     0,     0,   281,     0,     0,     0,
       0,   128,     0,     0,     0,     0,     0,     0,     0,     0,
     129,   130,   131,   132,   133,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   143,   144,   134,   135,   136,   137,
     138,   139,   140,   141,     0,     0,     0,   294,     0,     0,
       0,     0,   128,     0,     0,     0,     0,     0,     0,     0,
       0,   129,   130,   131,   132,   133,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   143,   144,   134,   135,   136,
     137,   138,   139,   140,   141,     0,     0,   295,     0,     0,
       0,     0,     0,   128,     0,     0,     0,     0,     0,     0,
       0,     0,   129,   130,   131,   132,   133,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   143,   144,   134,   135,
     136,   137,   138,   139,   140,   141,     0,     0,   296,     0,
       0,     0,     0,     0,   128,     0,     0,     0,     0,     0,
       0,     0,     0,   129,   130,   131,   132,   133,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   143,   144,   134,
     135,   136,   137,   138,   139,   140,   141,     0,     0,   299,
       0,     0,     0,     0,     0,   128,     0,     0,     0,     0,
       0,     0,     0,     0,   129,   130,   131,   132,   133,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   143,   144,
     134,   135,   136,   137,   138,   139,   140,   141,     0,     0,
       0,   316,     0,     0,     0,     0,   128,     0,     0,     0,
       0,     0,     0,     0,   128,   129,   130,   131,   132,   133,
       0,     0,     0,   129,   130,   131,   132,   133,     0,   143,
     144,   134,   135,   136,   137,   138,   139,   140,   141,   134,
     135,   136,   137,   138,   139,   140,   141,     0,   332,   352,
       0,     0,     0,     0,     0,   128,     0,     0,     0,     0,
       0,     0,     0,   128,   129,   130,   131,   132,   133,     0,
     143,   144,   129,   130,   131,   132,   133,     0,   143,   144,
     134,   135,   136,   137,   138,   139,   140,   141,   134,   135,
     136,   137,   138,   139,   140,   141,     0,   376,   384,     0,
       0,     0,     0,     0,   128,     0,     0,     0,     0,     0,
       0,     0,   128,   129,   130,   131,   132,   133,     0,   143,
     144,   129,   130,   131,   132,   133,     0,   143,   144,   134,
     135,   136,   137,   138,   139,   140,   141,   134,   135,   136,
     137,   138,   139,   140,   141,     0,   388,     0,     0,     0,
       0,     0,     0,   128,   389,     0,     0,     0,     0,     0,
       0,     0,   129,   130,   131,   132,   133,     0,   143,   144,
       0,     0,     0,     0,     0,     0,   143,   144,   134,   135,
     136,   137,   138,   139,   140,   141,     0,     0,   398,     0,
       0,     0,     0,     0,   128,     0,     0,     0,     0,     0,
       0,     0,     0,   129,   130,   131,   132,   133,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   143,   144,   134,
     135,   136,   137,   138,   139,   140,   141,     0,     0,   403,
       0,     0,     0,     0,     0,   -21,     0,     0,     0,     0,
       0,     0,     0,     0,   -21,     0,   -21,   -21,   -21,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   143,   144,
     -21,   -21,   -21,   -21,   -21,   -21,   -21,   -21,     0,     0,
       0,   -21,     0,     0,     0,     0,   128,     0,     0,     0,
       0,     0,     0,     0,     0,   129,   130,   131,   132,   133,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   -21,
     -21,   134,   135,   136,   137,   138,   139,   140,   141,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     143,   144
};

static const yytype_int16 yycheck[] =
{
      10,    23,    21,   101,    20,   111,   303,    26,    13,    13,
      36,    52,    12,    19,    20,    36,    22,    14,     0,    52,
      61,    19,    12,    23,    24,    25,    15,    53,    61,    62,
      17,    21,    22,    23,    24,    25,    57,    53,   335,    45,
      46,    48,    52,    50,    16,    47,    51,    51,    50,    39,
      40,    41,    42,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    48,    48,    47,    50,    16,    53,    18,    19,
      20,   169,    22,    79,    80,   372,    46,    83,    84,    85,
      86,    87,    88,    89,    90,    83,    84,    85,    86,    87,
      88,    89,    90,   112,    51,    45,    46,    51,    51,    46,
      48,   111,    52,    47,    58,    53,    50,    12,    58,    46,
      60,   209,    12,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    46,    48,    47,    79,
      80,    50,    46,    83,    84,    85,    86,    87,    88,    89,
      90,    46,    36,    50,    49,    52,    46,   253,    53,    49,
     256,    12,    46,    53,    48,    50,    48,    52,   168,    53,
      21,    22,    23,    24,    25,    46,    19,    20,    46,    22,
      46,    46,    46,    46,    79,    80,    46,    20,   197,    79,
      80,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      46,    12,    45,    46,    16,    48,    47,    19,    20,    46,
      22,    46,    54,    36,    53,    20,   216,    48,    54,    20,
      20,   233,   318,    51,    51,    63,    48,    70,    71,    72,
      73,    74,    75,    45,    46,    20,    79,    80,    54,    36,
      83,    84,    85,    86,    87,    88,    89,    90,    36,    59,
      46,    20,    61,   253,    53,   351,   256,   353,    70,    71,
      72,    73,    74,    75,    51,   274,   275,    79,    80,   365,
      48,    83,    84,    85,    86,    87,    88,    89,    90,   375,
      59,    47,    53,   283,   284,    53,   382,    12,    50,    59,
     290,    46,    57,    51,    47,    59,    21,    22,    23,    24,
      25,    48,    53,   303,   313,   401,   402,    48,    51,    12,
     406,    48,    37,    38,    39,    40,    41,    42,   318,    46,
      46,   321,    57,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    48,   335,    51,   287,    82,    24,
      25,    26,   203,    46,   346,   345,    49,   288,   348,    34,
      53,   351,   285,   353,    52,   314,   272,    42,    43,   239,
     274,   335,   340,    -1,    -1,   365,    -1,    -1,    -1,    -1,
      -1,    -1,   372,    -1,   374,   375,    79,    80,    -1,    -1,
     380,    -1,   382,    -1,   384,    -1,    -1,   387,    -1,    -1,
      -1,    -1,   392,    -1,    -1,    -1,    -1,    -1,   398,    -1,
      -1,   401,   402,    -1,   404,   405,   406,    -1,   408,    -1,
      95,    96,    97,    -1,    -1,   100,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   108,   109,   110,    -1,   112,    -1,    -1,
      -1,    -1,   117,   118,   119,   120,   121,   122,   123,    -1,
      -1,    -1,    -1,    -1,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   151,    -1,    -1,    -1,
     168,    -1,   157,    -1,   159,   160,   161,    -1,    -1,   164,
      -1,    -1,    -1,    -1,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    -1,    -1,    -1,   181,    16,    -1,    -1,
      19,    20,    -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,
     195,   196,    -1,    -1,    -1,    -1,    -1,    -1,   216,   204,
      -1,    -1,    -1,   208,    -1,    -1,    45,    46,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   220,    -1,   222,    -1,    -1,
     225,    -1,    -1,    -1,   229,   230,    -1,    -1,    -1,    -1,
      -1,    70,    71,    72,    73,    74,    75,    -1,    -1,    -1,
      79,    80,    -1,   248,    83,    84,    85,    86,    87,    88,
      89,    90,    -1,    -1,   259,     3,     4,     5,     6,     7,
       8,     9,    10,    11,   269,   283,   284,    -1,    16,    12,
      -1,   276,   290,    -1,    -1,   280,    -1,    -1,    21,    22,
      23,    24,    25,    -1,    -1,   303,   291,    -1,    -1,   294,
      -1,    -1,    -1,   298,    37,    38,    39,    40,    41,    42,
      43,    -1,    -1,   321,    -1,    -1,    -1,    -1,    -1,   314,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   335,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   345,    -1,    -1,
     348,    -1,   337,    -1,   339,   340,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   349,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   372,   360,   374,    -1,   363,    -1,
      -1,    -1,   380,    -1,    -1,    -1,   384,    -1,    -1,   387,
      -1,    -1,    -1,    -1,   392,    -1,   381,    -1,    -1,    -1,
     398,    -1,    -1,    -1,    -1,    -1,   404,   405,   393,    -1,
     408,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      -1,    -1,    12,    -1,    16,    -1,    18,    19,    20,    -1,
      22,    -1,    -1,    -1,    -1,    -1,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    -1,    -1,    -1,
      -1,    -1,    -1,    45,    46,    -1,    46,    -1,    -1,    49,
      52,    -1,    -1,    53,    -1,    -1,    58,    -1,    60,    -1,
      -1,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    -1,    -1,    -1,    79,    80,    79,
      80,    83,    84,    85,    86,    87,    88,    89,    90,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    -1,    -1,
      -1,    -1,    16,    -1,    18,    19,    20,    -1,    22,    -1,
      -1,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    45,    46,    48,    -1,    -1,    -1,    51,    53,    -1,
      -1,    -1,    -1,    -1,    58,    -1,    60,    -1,    -1,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    -1,    -1,    -1,    79,    80,    -1,    -1,    83,
      84,    85,    86,    87,    88,    89,    90,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,
      16,    -1,    18,    19,    20,    -1,    22,    -1,    -1,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,
      46,    48,    -1,    -1,    -1,    -1,    52,    -1,    -1,    -1,
      -1,    -1,    58,    -1,    60,    -1,    -1,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      -1,    -1,    -1,    79,    80,    -1,    -1,    83,    84,    85,
      86,    87,    88,    89,    90,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    -1,    -1,    -1,    -1,    16,    -1,
      18,    19,    20,    -1,    22,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    -1,
      -1,    -1,    -1,    51,    -1,    -1,    -1,    -1,    -1,    -1,
      58,    -1,    60,    -1,    -1,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    -1,    -1,
      -1,    79,    80,    -1,    -1,    83,    84,    85,    86,    87,
      88,    89,    90,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    -1,    -1,    -1,    -1,    16,    -1,    18,    19,
      20,    -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    45,    46,    -1,    -1,    -1,
      -1,    -1,    52,    -1,    -1,    -1,    -1,    -1,    58,    -1,
      60,    -1,    -1,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    -1,    -1,    -1,    79,
      80,    -1,    -1,    83,    84,    85,    86,    87,    88,    89,
      90,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      -1,    -1,    -1,    -1,    16,    -1,    18,    19,    20,    -1,
      22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    45,    46,    -1,    -1,    -1,    -1,    -1,
      52,    -1,    -1,    -1,    -1,    -1,    58,    -1,    60,    -1,
      -1,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    -1,    -1,    -1,    79,    80,    -1,
      -1,    83,    84,    85,    86,    87,    88,    89,    90,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    -1,    -1,
      -1,    -1,    16,    -1,    18,    19,    20,    -1,    22,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    45,    46,    -1,    -1,    -1,    -1,    51,    -1,    -1,
      -1,    -1,    -1,    -1,    58,    -1,    60,    -1,    -1,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    -1,    -1,    -1,    79,    80,    -1,    -1,    83,
      84,    85,    86,    87,    88,    89,    90,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,
      16,    -1,    18,    19,    20,    -1,    22,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,
      46,    -1,    -1,    -1,    -1,    -1,    52,    -1,    -1,    -1,
      -1,    -1,    58,    -1,    60,    -1,    -1,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      -1,    -1,    -1,    79,    80,    -1,    -1,    83,    84,    85,
      86,    87,    88,    89,    90,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    -1,    -1,    -1,    -1,    16,    -1,
      18,    19,    20,    -1,    22,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    -1,
      -1,    -1,    -1,    -1,    52,    -1,    -1,    -1,    -1,    -1,
      58,    -1,    60,    -1,    -1,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    -1,    -1,
      -1,    79,    80,    -1,    -1,    83,    84,    85,    86,    87,
      88,    89,    90,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    -1,    -1,    -1,    -1,    16,    -1,    18,    19,
      20,    -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    45,    46,    -1,    -1,    -1,
      -1,    -1,    52,    -1,    -1,    -1,    -1,    -1,    58,    -1,
      60,    -1,    -1,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    -1,    -1,    -1,    79,
      80,    -1,    -1,    83,    84,    85,    86,    87,    88,    89,
      90,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      -1,    -1,    -1,    -1,    16,    -1,    18,    19,    20,    -1,
      22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    45,    46,    -1,    -1,    -1,    -1,    -1,
      52,    -1,    -1,    -1,    -1,    -1,    58,    -1,    60,    -1,
      -1,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    -1,    -1,    -1,    79,    80,    -1,
      -1,    83,    84,    85,    86,    87,    88,    89,    90,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    -1,    -1,
      -1,    -1,    16,    -1,    18,    19,    20,    -1,    22,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    45,    46,    -1,    -1,    -1,    -1,    -1,    52,    -1,
      -1,    -1,    -1,    -1,    58,    -1,    60,    -1,    -1,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    -1,    -1,    -1,    79,    80,    -1,    -1,    83,
      84,    85,    86,    87,    88,    89,    90,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    -1,    -1,    -1,    -1,
      16,    -1,    18,    19,    20,    -1,    22,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,
      46,    -1,    -1,    -1,    -1,    51,    -1,    -1,    -1,    -1,
      -1,    -1,    58,    -1,    60,    -1,    -1,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      -1,    -1,    -1,    79,    80,    -1,    -1,    83,    84,    85,
      86,    87,    88,    89,    90,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    -1,    -1,    -1,    -1,    16,    -1,
      18,    19,    20,    -1,    22,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    45,    46,    -1,
      -1,    -1,    -1,    -1,    52,    -1,    -1,    -1,    -1,    -1,
      58,    -1,    60,    -1,    -1,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    -1,    -1,
      -1,    79,    80,    -1,    -1,    83,    84,    85,    86,    87,
      88,    89,    90,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    -1,    -1,    -1,    -1,    16,    -1,    18,    19,
      20,    -1,    22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    45,    46,    -1,    -1,    -1,
      -1,    -1,    52,    -1,    -1,    -1,    -1,    -1,    58,    -1,
      60,    -1,    -1,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    -1,    -1,    -1,    79,
      80,    -1,    -1,    83,    84,    85,    86,    87,    88,    89,
      90,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      -1,    -1,    -1,    -1,    16,    -1,    18,    19,    20,    -1,
      22,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    45,    46,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    58,    -1,    60,    -1,
      -1,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    -1,    -1,    -1,    79,    80,    -1,
      -1,    83,    84,    85,    86,    87,    88,    89,    90,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    -1,    -1,
      -1,    -1,    16,    -1,    18,    19,    20,    -1,    22,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    45,    46,    -1,    -1,    -1,    19,    20,    -1,    22,
      -1,    -1,    -1,    -1,    58,    -1,    60,    -1,    -1,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    45,    46,    -1,    79,    80,    -1,    51,    83,
      84,    85,    86,    87,    88,    89,    90,    -1,    -1,    -1,
      -1,    -1,    19,    20,    -1,    22,    -1,    70,    71,    72,
      73,    74,    75,    -1,    -1,    -1,    79,    80,    -1,    -1,
      83,    84,    85,    86,    87,    88,    89,    90,    45,    46,
      -1,    -1,    -1,    19,    20,    -1,    22,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    70,    71,    72,    73,    74,    75,    45,
      46,    -1,    79,    80,    -1,    -1,    83,    84,    85,    86,
      87,    88,    89,    90,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    70,    71,    72,    73,    74,    75,
      -1,    -1,    -1,    79,    80,    -1,    12,    83,    84,    85,
      86,    87,    88,    89,    90,    21,    22,    23,    24,    25,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    37,    38,    39,    40,    41,    42,    43,    44,    -1,
      -1,    47,    -1,    -1,    50,    -1,    -1,    12,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    21,    22,    23,    24,
      25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      76,    77,    37,    38,    39,    40,    41,    42,    43,    44,
      -1,    -1,    -1,    48,    -1,    -1,    -1,    -1,    12,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,    22,    23,
      24,    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    76,    77,    37,    38,    39,    40,    41,    42,    43,
      44,    -1,    -1,    47,    -1,    -1,    -1,    -1,    -1,    12,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,    22,
      23,    24,    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    76,    77,    37,    38,    39,    40,    41,    42,
      43,    44,    -1,    -1,    -1,    48,    -1,    -1,    -1,    -1,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    12,    21,
      22,    23,    24,    25,    -1,    -1,    -1,    21,    22,    23,
      24,    25,    -1,    76,    77,    37,    38,    39,    40,    41,
      42,    43,    44,    37,    38,    39,    40,    41,    42,    43,
      44,    -1,    54,    -1,    48,    -1,    -1,    -1,    -1,    12,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,    22,
      23,    24,    25,    -1,    76,    77,    -1,    -1,    -1,    -1,
      -1,    -1,    76,    77,    37,    38,    39,    40,    41,    42,
      43,    44,    -1,    -1,    47,    -1,    -1,    -1,    -1,    -1,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,
      22,    23,    24,    25,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    76,    77,    37,    38,    39,    40,    41,
      42,    43,    44,    -1,    -1,    47,    -1,    -1,    -1,    -1,
      -1,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      21,    22,    23,    24,    25,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    76,    77,    37,    38,    39,    40,
      41,    42,    43,    44,    -1,    -1,    47,    -1,    -1,    -1,
      -1,    -1,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    21,    22,    23,    24,    25,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    76,    77,    37,    38,    39,
      40,    41,    42,    43,    44,    -1,    -1,    47,    -1,    -1,
      -1,    -1,    -1,    12,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    21,    22,    23,    24,    25,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    76,    77,    37,    38,
      39,    40,    41,    42,    43,    44,    -1,    -1,    47,    -1,
      -1,    -1,    -1,    -1,    12,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    21,    22,    23,    24,    25,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    76,    77,    37,
      38,    39,    40,    41,    42,    43,    44,    -1,    -1,    47,
      -1,    -1,    -1,    -1,    -1,    12,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    21,    22,    23,    24,    25,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    76,    77,
      37,    38,    39,    40,    41,    42,    43,    44,    -1,    -1,
      47,    -1,    -1,    -1,    -1,    -1,    12,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    21,    22,    23,    24,    25,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    76,
      77,    37,    38,    39,    40,    41,    42,    43,    44,    -1,
      -1,    -1,    -1,    -1,    50,    -1,    -1,    12,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    21,    22,    23,    24,
      25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      76,    77,    37,    38,    39,    40,    41,    42,    43,    44,
      -1,    -1,    -1,    -1,    -1,    50,    -1,    -1,    12,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,    22,    23,
      24,    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    76,    77,    37,    38,    39,    40,    41,    42,    43,
      44,    -1,    -1,    47,    -1,    -1,    -1,    -1,    -1,    12,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,    22,
      23,    24,    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    76,    77,    37,    38,    39,    40,    41,    42,
      43,    44,    -1,    -1,    -1,    48,    -1,    -1,    -1,    -1,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    12,    21,
      22,    23,    24,    25,    -1,    -1,    -1,    21,    22,    23,
      24,    25,    -1,    76,    77,    37,    38,    39,    40,    41,
      42,    43,    44,    37,    38,    39,    40,    41,    42,    43,
      44,    -1,    54,    -1,    48,    -1,    -1,    -1,    -1,    12,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    12,    21,    22,
      23,    24,    25,    -1,    76,    77,    21,    22,    23,    24,
      25,    -1,    76,    77,    37,    38,    39,    40,    41,    42,
      43,    44,    37,    38,    39,    40,    41,    42,    43,    44,
      -1,    54,    47,    -1,    -1,    -1,    -1,    -1,    12,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,    22,    23,
      24,    25,    -1,    76,    77,    -1,    -1,    -1,    -1,    -1,
      -1,    76,    77,    37,    38,    39,    40,    41,    42,    43,
      44,    -1,    -1,    47,    -1,    -1,    -1,    -1,    -1,    12,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,    22,
      23,    24,    25,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    76,    77,    37,    38,    39,    40,    41,    42,
      43,    44,    -1,    -1,    -1,    48,    -1,    -1,    -1,    -1,
      12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,
      22,    23,    24,    25,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    76,    77,    37,    38,    39,    40,    41,
      42,    43,    44,    -1,    -1,    -1,    48,    -1,    -1,    -1,
      -1,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      21,    22,    23,    24,    25,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    76,    77,    37,    38,    39,    40,
      41,    42,    43,    44,    -1,    -1,    -1,    48,    -1,    -1,
      -1,    -1,    12,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    21,    22,    23,    24,    25,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    76,    77,    37,    38,    39,
      40,    41,    42,    43,    44,    -1,    -1,    47,    -1,    -1,
      -1,    -1,    -1,    12,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    21,    22,    23,    24,    25,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    76,    77,    37,    38,
      39,    40,    41,    42,    43,    44,    -1,    -1,    47,    -1,
      -1,    -1,    -1,    -1,    12,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    21,    22,    23,    24,    25,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    76,    77,    37,
      38,    39,    40,    41,    42,    43,    44,    -1,    -1,    47,
      -1,    -1,    -1,    -1,    -1,    12,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    21,    22,    23,    24,    25,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    76,    77,
      37,    38,    39,    40,    41,    42,    43,    44,    -1,    -1,
      -1,    48,    -1,    -1,    -1,    -1,    12,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    12,    21,    22,    23,    24,    25,
      -1,    -1,    -1,    21,    22,    23,    24,    25,    -1,    76,
      77,    37,    38,    39,    40,    41,    42,    43,    44,    37,
      38,    39,    40,    41,    42,    43,    44,    -1,    54,    47,
      -1,    -1,    -1,    -1,    -1,    12,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    12,    21,    22,    23,    24,    25,    -1,
      76,    77,    21,    22,    23,    24,    25,    -1,    76,    77,
      37,    38,    39,    40,    41,    42,    43,    44,    37,    38,
      39,    40,    41,    42,    43,    44,    -1,    54,    47,    -1,
      -1,    -1,    -1,    -1,    12,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    12,    21,    22,    23,    24,    25,    -1,    76,
      77,    21,    22,    23,    24,    25,    -1,    76,    77,    37,
      38,    39,    40,    41,    42,    43,    44,    37,    38,    39,
      40,    41,    42,    43,    44,    -1,    54,    -1,    -1,    -1,
      -1,    -1,    -1,    12,    54,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    21,    22,    23,    24,    25,    -1,    76,    77,
      -1,    -1,    -1,    -1,    -1,    -1,    76,    77,    37,    38,
      39,    40,    41,    42,    43,    44,    -1,    -1,    47,    -1,
      -1,    -1,    -1,    -1,    12,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    21,    22,    23,    24,    25,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    76,    77,    37,
      38,    39,    40,    41,    42,    43,    44,    -1,    -1,    47,
      -1,    -1,    -1,    -1,    -1,    12,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    21,    -1,    23,    24,    25,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    76,    77,
      37,    38,    39,    40,    41,    42,    43,    44,    -1,    -1,
      -1,    48,    -1,    -1,    -1,    -1,    12,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    21,    22,    23,    24,    25,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    76,
      77,    37,    38,    39,    40,    41,    42,    43,    44,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      76,    77
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    14,    92,    93,    15,     0,    16,    17,    46,    47,
      51,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      16,    18,    19,    20,    22,    45,    46,    58,    60,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    79,    80,    83,    84,    85,    86,    87,    88,
      89,    90,    94,    95,    96,    97,    98,   100,   101,   104,
     105,   106,   107,   108,   113,   114,   117,   118,   119,   122,
     125,   127,   133,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   100,    12,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    46,    49,    53,    79,    80,
      99,   126,    20,    96,   140,    96,    96,   100,    46,    46,
      46,    51,    46,    48,    48,    48,    96,    46,    46,    46,
      46,    46,    46,    46,    96,    96,    52,    95,    12,    21,
      22,    23,    24,    25,    37,    38,    39,    40,    41,    42,
      43,    44,    48,    76,    77,    20,    53,   102,   103,    20,
     102,    46,    96,   139,    96,    96,    96,    36,    48,    53,
      99,    53,   126,    47,    47,    96,    96,    96,    94,    20,
      96,   100,   120,    48,    96,    96,    96,    96,    96,    96,
      96,    46,    96,    96,    96,    96,    96,    96,    96,    96,
      96,    96,    96,    96,    96,    46,    36,    46,    48,    53,
     128,    54,    48,    50,    36,    48,    96,    47,    50,    54,
      48,    96,    96,    96,    96,    96,    47,    47,    47,    52,
      99,    20,    48,    47,    47,    50,    47,    47,    47,    50,
      50,    96,    96,    20,    96,   100,   134,   135,    54,    36,
      53,    20,    20,   103,    96,    47,    96,    48,    99,    48,
      54,    48,    54,    51,    95,    51,    51,    63,    96,    36,
      57,    96,    48,    96,    96,   123,    96,    47,    47,    53,
     126,    48,    20,    47,    50,    13,    51,   130,    54,    36,
      36,    48,    96,    94,    59,   110,   112,    61,   115,   116,
      94,    46,    96,    20,    48,    47,    47,    47,    50,    47,
      96,    48,   128,    51,   136,   135,   100,    96,   124,   130,
     131,   132,    48,    13,    51,    96,    48,    52,    51,    58,
      95,    59,   112,   101,    52,   116,    52,    96,    47,    96,
     121,    96,    54,    95,   113,   137,   138,    53,   129,    50,
      50,    52,   100,    96,   123,    59,   109,   111,    94,    46,
      95,    57,    47,    51,    47,    48,    52,   138,    96,    48,
      53,    96,   132,    53,    52,    51,    58,    95,    59,   111,
      52,    96,    94,    48,    94,    51,    54,    96,    96,    48,
      94,    46,    51,    58,    47,   113,    52,    94,    54,    54,
      52,    96,    94,    46,    95,    62,    52,    48,    47,    52,
      96,    57,    51,    47,    94,    94,    51,    52,    94,    52
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_uint8 yyr1[] =
{
       0,    91,    92,    93,    94,    94,    95,    95,    95,    95,
      95,    95,    95,    95,    95,    95,    95,    95,    95,    95,
      95,    96,    96,    96,    96,    96,    96,    96,    96,    96,
      96,    96,    96,    96,    96,    96,    96,    96,    96,    96,
      96,    96,    96,    96,    96,    96,    96,    96,    96,    96,
      97,    97,    97,    97,    97,    98,    98,    98,    99,    99,
      99,    99,    99,    99,    99,    99,    99,    99,    99,   100,
     100,   100,   100,   100,   100,   100,   100,   100,   100,   101,
     101,   101,   101,   101,   101,   101,   101,   101,   102,   102,
     103,   104,   105,   105,   105,   106,   106,   107,   107,   107,
     107,   108,   108,   108,   109,   109,   110,   110,   111,   112,
     113,   113,   113,   113,   114,   115,   115,   116,   116,   117,
     118,   119,   119,   120,   120,   120,   120,   121,   121,   122,
     122,   122,   122,   123,   123,   124,   124,   125,   125,   126,
     126,   127,   127,   127,   128,   128,   129,   129,   130,   131,
     131,   132,   132,   133,   134,   134,   134,   135,   135,   136,
     137,   137,   137,   138,   138,   139,   139,   139,   140,   140,
     140,   140,   140,   140,   140,   140,   141,   141,   142,   143,
     144,   145,   146,   147,   148,   148
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     9,     1,     2,     1,     1,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     5,     5,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     2,     2,
       2,     2,     2,     4,     2,     3,     4,     3,     1,     1,
       5,     3,     3,     6,     4,     4,     7,     5,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       3,     5,     1,     1,     1,     7,     5,    11,     9,     9,
       7,    12,     8,     6,     2,     1,     2,     1,     8,     6,
       2,     2,     3,     2,     7,     2,     1,     5,     8,     7,
       9,    11,    10,     4,     3,     1,     0,     1,     0,    11,
       9,     8,     6,     3,     1,     3,     1,     5,     3,     4,
       3,     8,     6,     5,     3,     2,     4,     3,     3,     3,
       1,     1,     1,     6,     1,     3,     0,     2,     3,     3,
       2,     1,     0,     1,     1,     3,     1,     0,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     6,     4,     4,
       4,     6,     2,     5,     6,     6
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
#line 217 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        ast_root = build_program_node((yyvsp[0].node), (yylsp[0]).first_line, (yylsp[0]).first_column);
        (yyval.node) = ast_root;
    }
#line 2600 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 3: /* bloque_main: TOKEN_PUBLIC TOKEN_STATIC TOKEN_VOID TOKEN_MAIN TOKEN_PAREN_LEFT TOKEN_PAREN_RIGHT TOKEN_BRACE_LEFT instrucciones TOKEN_BRACE_RIGHT  */
#line 225 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_bloque_main_node((yyvsp[-1].node), (yylsp[-8]).first_line, (yylsp[-8]).first_column);
    }
#line 2608 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 4: /* instrucciones: instruccion  */
#line 232 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_instrucciones_single((yyvsp[0].node), (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 2616 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 5: /* instrucciones: instrucciones instruccion  */
#line 236 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_instrucciones_add((yyvsp[-1].node), (yyvsp[0].node));
    }
#line 2624 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 6: /* instruccion: sout  */
#line 243 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2632 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 7: /* instruccion: declaraciones  */
#line 247 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2640 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 8: /* instruccion: asignacion_compuesta  */
#line 251 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2648 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 9: /* instruccion: expresion TOKEN_SEMICOLON  */
#line 255 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = (yyvsp[-1].node);
    }
#line 2656 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 10: /* instruccion: sentencia_if  */
#line 259 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2664 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 11: /* instruccion: sentencia_switch  */
#line 263 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2672 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 12: /* instruccion: ciclo_while  */
#line 267 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2680 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 13: /* instruccion: ciclo_do  */
#line 271 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2688 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 14: /* instruccion: ciclo_for  */
#line 275 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2696 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 15: /* instruccion: arrays  */
#line 279 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2704 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 16: /* instruccion: arrays_acceso  */
#line 283 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2712 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 17: /* instruccion: arrays_asignacion  */
#line 287 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2720 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 18: /* instruccion: funcion  */
#line 291 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2728 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 19: /* instruccion: sentencias  */
#line 295 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2736 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 20: /* instruccion: embebidas  */
#line 299 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2744 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 21: /* expresion: embebidas  */
#line 306 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2752 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 22: /* expresion: expresion TOKEN_EQUALS TOKEN_PAREN_LEFT expresion TOKEN_PAREN_RIGHT  */
#line 310 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_equals_embebida((yyvsp[-4].node), (yyvsp[-1].node), (yylsp[-3]).first_line, (yylsp[-3]).first_column);
    }
#line 2760 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 23: /* expresion: TOKEN_IDENTIFIER TOKEN_EQUALS TOKEN_PAREN_LEFT expresion TOKEN_PAREN_RIGHT  */
#line 314 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        ASTNode* id_node = build_identifier((yyvsp[-4].str), (yylsp[-4]).first_line, (yylsp[-4]).first_column);
        (yyval.node) = build_equals_embebida(id_node, (yyvsp[-1].node), (yylsp[-3]).first_line, (yylsp[-3]).first_column);
    }
#line 2769 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 24: /* expresion: expresion TOKEN_PLUS expresion  */
#line 320 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_expresion_binaria((yyvsp[-2].node), "+", (yyvsp[0].node), (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 2777 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 25: /* expresion: expresion TOKEN_MINUS expresion  */
#line 324 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_expresion_binaria((yyvsp[-2].node), "-", (yyvsp[0].node), (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 2785 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 26: /* expresion: expresion TOKEN_MULTIPLICATION expresion  */
#line 328 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_expresion_binaria((yyvsp[-2].node), "*", (yyvsp[0].node), (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 2793 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 27: /* expresion: expresion TOKEN_DIVISION expresion  */
#line 332 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_expresion_binaria((yyvsp[-2].node), "/", (yyvsp[0].node), (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 2801 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 28: /* expresion: expresion TOKEN_MODULE expresion  */
#line 336 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_expresion_binaria((yyvsp[-2].node), "%", (yyvsp[0].node), (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 2809 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 29: /* expresion: expresion TOKEN_EQUAL expresion  */
#line 342 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_expresion_binaria((yyvsp[-2].node), "==", (yyvsp[0].node), (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 2817 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 30: /* expresion: expresion TOKEN_UNEQUAL expresion  */
#line 346 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_expresion_binaria((yyvsp[-2].node), "!=", (yyvsp[0].node), (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 2825 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 31: /* expresion: expresion TOKEN_GREATER expresion  */
#line 352 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_expresion_binaria((yyvsp[-2].node), ">", (yyvsp[0].node), (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 2833 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 32: /* expresion: expresion TOKEN_LESS expresion  */
#line 356 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_expresion_binaria((yyvsp[-2].node), "<", (yyvsp[0].node), (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 2841 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 33: /* expresion: expresion TOKEN_GREATER_EQUAL expresion  */
#line 360 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_expresion_binaria((yyvsp[-2].node), ">=", (yyvsp[0].node), (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 2849 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 34: /* expresion: expresion TOKEN_LESS_EQUAL expresion  */
#line 364 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_expresion_binaria((yyvsp[-2].node), "<=", (yyvsp[0].node), (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 2857 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 35: /* expresion: expresion TOKEN_AND expresion  */
#line 370 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_expresion_binaria((yyvsp[-2].node), "&&", (yyvsp[0].node), (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 2865 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 36: /* expresion: expresion TOKEN_OR expresion  */
#line 374 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_expresion_binaria((yyvsp[-2].node), "||", (yyvsp[0].node), (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 2873 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 37: /* expresion: TOKEN_NOT expresion  */
#line 380 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_expresion_unaria("!", (yyvsp[0].node), (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 2881 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 38: /* expresion: TOKEN_INCREMENT expresion  */
#line 384 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_expresion_unaria("++", (yyvsp[0].node), (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 2889 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 39: /* expresion: TOKEN_DECREMENT expresion  */
#line 388 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_expresion_unaria("--", (yyvsp[0].node), (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 2897 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 40: /* expresion: TOKEN_MINUS expresion  */
#line 392 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_expresion_unaria("-", (yyvsp[0].node), (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 2905 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 41: /* expresion: TOKEN_IDENTIFIER TOKEN_INCREMENT  */
#line 398 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        ASTNode* id_node = build_identifier((yyvsp[-1].str), (yylsp[-1]).first_line, (yylsp[-1]).first_column);
        (yyval.node) = build_expresion_postfijo(id_node, "++", (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 2914 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 42: /* expresion: TOKEN_IDENTIFIER TOKEN_DECREMENT  */
#line 403 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        ASTNode* id_node = build_identifier((yyvsp[-1].str), (yylsp[-1]).first_line, (yylsp[-1]).first_column);
        (yyval.node) = build_expresion_postfijo(id_node, "--", (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 2923 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 43: /* expresion: TOKEN_IDENTIFIER TOKEN_PAREN_LEFT argumentos TOKEN_PAREN_RIGHT  */
#line 410 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_llamada_funcion((yyvsp[-3].str), (yyvsp[-1].node), (yylsp[-3]).first_line, (yylsp[-3]).first_column);
    }
#line 2931 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 44: /* expresion: TOKEN_IDENTIFIER brackets_indices  */
#line 416 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_array_acceso_multidimensional((yyvsp[-1].str), (yyvsp[0].node), (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 2939 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 45: /* expresion: TOKEN_IDENTIFIER TOKEN_DOT expresion  */
#line 422 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        ASTNode* id_node = build_identifier((yyvsp[-2].str), (yylsp[-2]).first_line, (yylsp[-2]).first_column);
        (yyval.node) = build_expresion_acceso(id_node, (yyvsp[0].node), (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 2948 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 46: /* expresion: TOKEN_PAREN_LEFT tipo TOKEN_PAREN_RIGHT expresion  */
#line 427 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_cast_node((yyvsp[-2].node), (yyvsp[0].node), (yylsp[-3]).first_line, (yylsp[-3]).first_column);
    }
#line 2956 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 47: /* expresion: TOKEN_PAREN_LEFT expresion TOKEN_PAREN_RIGHT  */
#line 432 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_expresion_parentesis((yyvsp[-1].node), (yylsp[-2]).first_line, (yylsp[-2]).first_column);
    }
#line 2964 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 48: /* expresion: dato  */
#line 438 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2972 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 49: /* expresion: TOKEN_IDENTIFIER  */
#line 443 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_identifier((yyvsp[0].str), (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 2980 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 50: /* declaraciones: tipo TOKEN_IDENTIFIER TOKEN_ASSIGN expresion TOKEN_SEMICOLON  */
#line 450 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_declaracion_single((yyvsp[-4].node), (yyvsp[-3].str), (yyvsp[-1].node), (yylsp[-4]).first_line, (yylsp[-4]).first_column);
    }
#line 2988 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 51: /* declaraciones: tipo lista_declaraciones TOKEN_SEMICOLON  */
#line 454 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_declaracion_multiple((yyvsp[-2].node), (yyvsp[-1].node), (yylsp[-2]).first_line, (yylsp[-2]).first_column);
    }
#line 2996 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 52: /* declaraciones: tipo TOKEN_IDENTIFIER TOKEN_SEMICOLON  */
#line 458 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_declaracion_sin_inicializacion((yyvsp[-2].node), (yyvsp[-1].str), (yylsp[-2]).first_line, (yylsp[-2]).first_column);
    }
#line 3004 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 53: /* declaraciones: TOKEN_FINAL tipo TOKEN_IDENTIFIER TOKEN_ASSIGN expresion TOKEN_SEMICOLON  */
#line 463 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_constante_single((yyvsp[-4].node), (yyvsp[-3].str), (yyvsp[-1].node), (yylsp[-5]).first_line, (yylsp[-5]).first_column);
    }
#line 3012 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 54: /* declaraciones: TOKEN_FINAL tipo lista_declaraciones TOKEN_SEMICOLON  */
#line 467 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_constante_multiple((yyvsp[-2].node), (yyvsp[-1].node), (yylsp[-3]).first_line, (yylsp[-3]).first_column);
    }
#line 3020 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 55: /* asignacion_compuesta: TOKEN_IDENTIFIER operador_asignacion expresion TOKEN_SEMICOLON  */
#line 474 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_asignacion_compuesta((yyvsp[-3].str), (yyvsp[-2].node), (yyvsp[-1].node), (yylsp[-3]).first_line, (yylsp[-3]).first_column);
    }
#line 3028 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 56: /* asignacion_compuesta: TOKEN_IDENTIFIER TOKEN_BRACKET_LEFT expresion TOKEN_BRACKET_RIGHT operador_asignacion expresion TOKEN_SEMICOLON  */
#line 479 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_asignacion_compuesta_array_1d((yyvsp[-6].str), (yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[-1].node), (yylsp[-6]).first_line, (yylsp[-6]).first_column);
    }
#line 3036 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 57: /* asignacion_compuesta: TOKEN_IDENTIFIER brackets_indices operador_asignacion expresion TOKEN_SEMICOLON  */
#line 484 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_asignacion_compuesta_array_multidimensional((yyvsp[-4].str), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[-1].node), (yylsp[-4]).first_line, (yylsp[-4]).first_column);
    }
#line 3044 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 58: /* operador_asignacion: TOKEN_PLUS_ASSIGN  */
#line 492 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_operador_asignacion("+=", (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 3052 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 59: /* operador_asignacion: TOKEN_MINUS_ASSIGN  */
#line 496 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_operador_asignacion("-=", (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 3060 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 60: /* operador_asignacion: TOKEN_MULT_ASSIGN  */
#line 500 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_operador_asignacion("*=", (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 3068 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 61: /* operador_asignacion: TOKEN_DIV_ASSIGN  */
#line 504 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_operador_asignacion("/=", (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 3076 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 62: /* operador_asignacion: TOKEN_MOD_ASSIGN  */
#line 508 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_operador_asignacion("%=", (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 3084 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 63: /* operador_asignacion: TOKEN_AND_ASSIGN  */
#line 512 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_operador_asignacion("&=", (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 3092 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 64: /* operador_asignacion: TOKEN_OR_ASSIGN  */
#line 516 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_operador_asignacion("|=", (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 3100 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 65: /* operador_asignacion: TOKEN_XOR_ASSIGN  */
#line 520 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_operador_asignacion("^=", (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 3108 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 66: /* operador_asignacion: TOKEN_SHIFT_LEFT_ASSIGN  */
#line 524 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_operador_asignacion("<<=", (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 3116 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 67: /* operador_asignacion: TOKEN_SHIFT_RIGHT_ASSIGN  */
#line 528 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_operador_asignacion(">>=", (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 3124 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 68: /* operador_asignacion: TOKEN_ASSIGN  */
#line 532 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_operador_asignacion("=", (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 3132 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 69: /* tipo: TOKEN_STRING  */
#line 540 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_tipo_node("string", (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 3140 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 70: /* tipo: TOKEN_INT  */
#line 544 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_tipo_node("int", (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 3148 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 71: /* tipo: TOKEN_FLOAT  */
#line 548 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_tipo_node("float", (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 3156 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 72: /* tipo: TOKEN_CHAR  */
#line 552 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_tipo_node("char", (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 3164 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 73: /* tipo: TOKEN_BOOLEAN  */
#line 556 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_tipo_node("boolean", (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 3172 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 74: /* tipo: TOKEN_DOUBLE  */
#line 560 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_tipo_node("double", (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 3180 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 75: /* tipo: TOKEN_LONG  */
#line 564 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_tipo_node("long", (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 3188 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 76: /* tipo: TOKEN_SHORT  */
#line 568 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_tipo_node("short", (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 3196 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 77: /* tipo: TOKEN_BYTE  */
#line 572 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_tipo_node("byte", (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 3204 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 78: /* tipo: TOKEN_VOID  */
#line 576 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_tipo_node("void", (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 3212 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 79: /* dato: TOKEN_TYPE_STRING  */
#line 583 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_dato_string((yyvsp[0].str), (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 3220 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 80: /* dato: TOKEN_TYPE_INT  */
#line 587 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_dato_int((yyvsp[0].str), (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 3228 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 81: /* dato: TOKEN_TYPE_LONG  */
#line 591 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_dato_long((yyvsp[0].str), (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 3236 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 82: /* dato: TOKEN_TYPE_FLOAT  */
#line 595 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_dato_float((yyvsp[0].str), (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 3244 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 83: /* dato: TOKEN_TYPE_DOUBLE  */
#line 599 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_dato_double((yyvsp[0].str), (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 3252 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 84: /* dato: TOKEN_TYPE_CHAR  */
#line 603 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_dato_char((yyvsp[0].str), (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 3260 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 85: /* dato: TOKEN_TYPE_TRUE  */
#line 607 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_dato_boolean((yyvsp[0].str), (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 3268 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 86: /* dato: TOKEN_TYPE_FALSE  */
#line 611 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_dato_boolean((yyvsp[0].str), (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 3276 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 87: /* dato: TOKEN_NULL  */
#line 615 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_dato_null((yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 3284 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 88: /* lista_declaraciones: lista_declaracion  */
#line 622 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_lista_declaraciones_single((yyvsp[0].node), (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 3292 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 89: /* lista_declaraciones: lista_declaraciones TOKEN_COMMA lista_declaracion  */
#line 626 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_lista_declaraciones_add((yyvsp[-2].node), (yyvsp[0].node));
    }
#line 3300 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 90: /* lista_declaracion: TOKEN_IDENTIFIER TOKEN_ASSIGN expresion  */
#line 633 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_lista_declaracion_node((yyvsp[-2].str), (yyvsp[0].node), (yylsp[-2]).first_line, (yylsp[-2]).first_column);
    }
#line 3308 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 91: /* sout: TOKEN_SOUT TOKEN_PAREN_LEFT expresion TOKEN_PAREN_RIGHT TOKEN_SEMICOLON  */
#line 640 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_sout_node((yyvsp[-2].node), (yylsp[-4]).first_line, (yylsp[-4]).first_column);
    }
#line 3316 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 92: /* sentencia_if: if_simple  */
#line 647 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 3324 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 93: /* sentencia_if: if_con_else  */
#line 651 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 3332 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 94: /* sentencia_if: if_con_else_if  */
#line 655 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 3340 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 95: /* if_simple: TOKEN_IF TOKEN_PAREN_LEFT expresion TOKEN_PAREN_RIGHT TOKEN_BRACE_LEFT instrucciones TOKEN_BRACE_RIGHT  */
#line 663 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_if_simple((yyvsp[-4].node), (yyvsp[-1].node), (yylsp[-6]).first_line, (yylsp[-6]).first_column);
    }
#line 3348 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 96: /* if_simple: TOKEN_IF TOKEN_PAREN_LEFT expresion TOKEN_PAREN_RIGHT instruccion  */
#line 668 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_if_simple_sin_llaves((yyvsp[-2].node), (yyvsp[0].node), (yylsp[-4]).first_line, (yylsp[-4]).first_column);
    }
#line 3356 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 97: /* if_con_else: TOKEN_IF TOKEN_PAREN_LEFT expresion TOKEN_PAREN_RIGHT TOKEN_BRACE_LEFT instrucciones TOKEN_BRACE_RIGHT TOKEN_ELSE TOKEN_BRACE_LEFT instrucciones TOKEN_BRACE_RIGHT  */
#line 676 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_if_con_else((yyvsp[-8].node), (yyvsp[-5].node), (yyvsp[-1].node), (yylsp[-10]).first_line, (yylsp[-10]).first_column);
    }
#line 3364 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 98: /* if_con_else: TOKEN_IF TOKEN_PAREN_LEFT expresion TOKEN_PAREN_RIGHT TOKEN_BRACE_LEFT instrucciones TOKEN_BRACE_RIGHT TOKEN_ELSE instruccion  */
#line 681 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_if_con_else_mixto_1((yyvsp[-6].node), (yyvsp[-3].node), (yyvsp[0].node), (yylsp[-8]).first_line, (yylsp[-8]).first_column);
    }
#line 3372 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 99: /* if_con_else: TOKEN_IF TOKEN_PAREN_LEFT expresion TOKEN_PAREN_RIGHT instruccion TOKEN_ELSE TOKEN_BRACE_LEFT instrucciones TOKEN_BRACE_RIGHT  */
#line 686 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_if_con_else_mixto_2((yyvsp[-6].node), (yyvsp[-4].node), (yyvsp[-1].node), (yylsp[-8]).first_line, (yylsp[-8]).first_column);
    }
#line 3380 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 100: /* if_con_else: TOKEN_IF TOKEN_PAREN_LEFT expresion TOKEN_PAREN_RIGHT instruccion TOKEN_ELSE instruccion  */
#line 691 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_if_con_else_sin_llaves((yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node), (yylsp[-6]).first_line, (yylsp[-6]).first_column);
    }
#line 3388 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 101: /* if_con_else_if: TOKEN_IF TOKEN_PAREN_LEFT expresion TOKEN_PAREN_RIGHT TOKEN_BRACE_LEFT instrucciones TOKEN_BRACE_RIGHT lista_else_if TOKEN_ELSE TOKEN_BRACE_LEFT instrucciones TOKEN_BRACE_RIGHT  */
#line 699 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_if_con_else_if((yyvsp[-9].node), (yyvsp[-6].node), (yyvsp[-4].node), (yyvsp[-1].node), (yylsp[-11]).first_line, (yylsp[-11]).first_column);
    }
#line 3396 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 102: /* if_con_else_if: TOKEN_IF TOKEN_PAREN_LEFT expresion TOKEN_PAREN_RIGHT instruccion lista_else_if_sin_llaves TOKEN_ELSE instruccion  */
#line 704 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_if_con_else_if_sin_llaves((yyvsp[-5].node), (yyvsp[-3].node), (yyvsp[-2].node), (yyvsp[0].node), (yylsp[-7]).first_line, (yylsp[-7]).first_column);
    }
#line 3404 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 103: /* if_con_else_if: TOKEN_IF TOKEN_PAREN_LEFT expresion TOKEN_PAREN_RIGHT instruccion lista_else_if_sin_llaves  */
#line 709 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_if_con_else_if_sin_else_final((yyvsp[-3].node), (yyvsp[-1].node), (yyvsp[0].node), (yylsp[-5]).first_line, (yylsp[-5]).first_column);
    }
#line 3412 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 104: /* lista_else_if: lista_else_if else_if  */
#line 716 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_lista_else_if_add((yyvsp[-1].node), (yyvsp[0].node));
    }
#line 3420 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 105: /* lista_else_if: else_if  */
#line 720 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_lista_else_if_single((yyvsp[0].node), (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 3428 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 106: /* lista_else_if_sin_llaves: lista_else_if_sin_llaves else_if_sin_llaves  */
#line 728 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_lista_else_if_sin_llaves_add((yyvsp[-1].node), (yyvsp[0].node));
    }
#line 3436 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 107: /* lista_else_if_sin_llaves: else_if_sin_llaves  */
#line 732 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_lista_else_if_sin_llaves_single((yyvsp[0].node), (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 3444 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 108: /* else_if: TOKEN_ELSE TOKEN_IF TOKEN_PAREN_LEFT expresion TOKEN_PAREN_RIGHT TOKEN_BRACE_LEFT instrucciones TOKEN_BRACE_RIGHT  */
#line 740 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_else_if((yyvsp[-4].node), (yyvsp[-1].node), (yylsp[-7]).first_line, (yylsp[-7]).first_column);
    }
#line 3452 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 109: /* else_if_sin_llaves: TOKEN_ELSE TOKEN_IF TOKEN_PAREN_LEFT expresion TOKEN_PAREN_RIGHT instruccion  */
#line 748 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_else_if_sin_llaves((yyvsp[-2].node), (yyvsp[0].node), (yylsp[-5]).first_line, (yylsp[-5]).first_column);
    }
#line 3460 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 110: /* sentencias: TOKEN_BREAK TOKEN_SEMICOLON  */
#line 755 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_break((yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 3468 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 111: /* sentencias: TOKEN_CONTINUE TOKEN_SEMICOLON  */
#line 759 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_continue((yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 3476 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 112: /* sentencias: TOKEN_RETURN expresion TOKEN_SEMICOLON  */
#line 763 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_return_con_valor((yyvsp[-1].node), (yylsp[-2]).first_line, (yylsp[-2]).first_column);
    }
#line 3484 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 113: /* sentencias: TOKEN_RETURN TOKEN_SEMICOLON  */
#line 767 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_return_vacio((yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 3492 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 114: /* sentencia_switch: TOKEN_SWITCH TOKEN_PAREN_LEFT expresion TOKEN_PAREN_RIGHT TOKEN_BRACE_LEFT lista_case TOKEN_BRACE_RIGHT  */
#line 774 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_switch((yyvsp[-4].node), (yyvsp[-1].node), (yylsp[-6]).first_line, (yylsp[-6]).first_column);
    }
#line 3500 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 115: /* lista_case: lista_case case  */
#line 781 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_lista_casos_add((yyvsp[-1].node), (yyvsp[0].node));
    }
#line 3508 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 116: /* lista_case: case  */
#line 785 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_lista_casos_single((yyvsp[0].node), (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 3516 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 117: /* case: TOKEN_CASE dato TOKEN_COLON instrucciones sentencias  */
#line 792 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_caso((yyvsp[-3].node), (yyvsp[-1].node), (yyvsp[0].node), (yylsp[-4]).first_line, (yylsp[-4]).first_column);
    }
#line 3524 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 118: /* case: TOKEN_CASE dato TOKEN_COLON instrucciones sentencias TOKEN_DEFAULT TOKEN_COLON instrucciones  */
#line 796 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_caso_con_default((yyvsp[-6].node), (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[0].node), (yylsp[-7]).first_line, (yylsp[-7]).first_column);
    }
#line 3532 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 119: /* ciclo_while: TOKEN_WHILE TOKEN_PAREN_LEFT expresion TOKEN_PAREN_RIGHT TOKEN_BRACE_LEFT instrucciones TOKEN_BRACE_RIGHT  */
#line 803 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_while((yyvsp[-4].node), (yyvsp[-1].node), (yylsp[-6]).first_line, (yylsp[-6]).first_column);
    }
#line 3540 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 120: /* ciclo_do: TOKEN_DO TOKEN_BRACE_LEFT instrucciones TOKEN_BRACE_RIGHT TOKEN_WHILE TOKEN_PAREN_LEFT expresion TOKEN_PAREN_RIGHT TOKEN_SEMICOLON  */
#line 810 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_do_while((yyvsp[-6].node), (yyvsp[-2].node), (yylsp[-8]).first_line, (yylsp[-8]).first_column);
    }
#line 3548 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 121: /* ciclo_for: TOKEN_FOR TOKEN_PAREN_LEFT inicializacion_for TOKEN_SEMICOLON expresion TOKEN_SEMICOLON actualizar_for TOKEN_PAREN_RIGHT TOKEN_BRACE_LEFT instrucciones TOKEN_BRACE_RIGHT  */
#line 817 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_for((yyvsp[-8].node), (yyvsp[-6].node), (yyvsp[-4].node), (yyvsp[-1].node), (yylsp[-10]).first_line, (yylsp[-10]).first_column);  
    }
#line 3556 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 122: /* ciclo_for: TOKEN_FOR TOKEN_PAREN_LEFT tipo TOKEN_IDENTIFIER TOKEN_COLON TOKEN_IDENTIFIER TOKEN_PAREN_RIGHT TOKEN_BRACE_LEFT instrucciones TOKEN_BRACE_RIGHT  */
#line 821 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_for_each((yyvsp[-7].node), (yyvsp[-6].str), (yyvsp[-4].str), (yyvsp[-1].node), (yylsp[-9]).first_line, (yylsp[-9]).first_column);
    }
#line 3564 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 123: /* inicializacion_for: tipo TOKEN_IDENTIFIER TOKEN_ASSIGN expresion  */
#line 828 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_inicializacion_for_declaracion((yyvsp[-3].node), (yyvsp[-2].str), (yyvsp[0].node), (yylsp[-3]).first_line, (yylsp[-3]).first_column);
    }
#line 3572 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 124: /* inicializacion_for: TOKEN_IDENTIFIER operador_asignacion expresion  */
#line 832 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_inicializacion_for_asignacion((yyvsp[-2].str), (yyvsp[-1].node), (yyvsp[0].node), (yylsp[-2]).first_line, (yylsp[-2]).first_column);
    }
#line 3580 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 125: /* inicializacion_for: expresion  */
#line 836 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_inicializacion_for_expresion((yyvsp[0].node), (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 3588 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 126: /* inicializacion_for: %empty  */
#line 840 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_inicializacion_for_vacia(0, 0);
    }
#line 3596 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 127: /* actualizar_for: expresion  */
#line 847 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_actualizacion_for((yyvsp[0].node), (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 3604 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 128: /* actualizar_for: %empty  */
#line 851 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_actualizacion_for_vacia(0, 0);  // ← USAR 0, 0 en lugar de @1
    }
#line 3612 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 129: /* arrays: tipo TOKEN_BRACKET_LEFT TOKEN_BRACKET_RIGHT TOKEN_IDENTIFIER TOKEN_ASSIGN TOKEN_NEW tipo TOKEN_BRACKET_LEFT expresion TOKEN_BRACKET_RIGHT TOKEN_SEMICOLON  */
#line 859 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_vector_new((yyvsp[-10].node), (yyvsp[-7].str), (yyvsp[-4].node), (yyvsp[-2].node), (yylsp[-10]).first_line, (yylsp[-10]).first_column);
    }
#line 3620 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 130: /* arrays: tipo TOKEN_BRACKET_LEFT TOKEN_BRACKET_RIGHT TOKEN_IDENTIFIER TOKEN_ASSIGN TOKEN_BRACE_LEFT contenido_vector TOKEN_BRACE_RIGHT TOKEN_SEMICOLON  */
#line 864 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_vector_inicializado((yyvsp[-8].node), (yyvsp[-5].str), (yyvsp[-2].node), (yylsp[-8]).first_line, (yylsp[-8]).first_column);
    }
#line 3628 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 131: /* arrays: tipo TOKEN_IDENTIFIER brackets TOKEN_ASSIGN TOKEN_NEW tipo brackets_new TOKEN_SEMICOLON  */
#line 869 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_array_multidimensional_new((yyvsp[-7].node), (yyvsp[-5].node), (yyvsp[-6].str), (yyvsp[-2].node), (yyvsp[-1].node), (yylsp[-7]).first_line, (yylsp[-7]).first_column);
        //                                          ^^^ $3 = brackets, $2 = TOKEN_IDENTIFIER
    }
#line 3637 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 132: /* arrays: tipo TOKEN_IDENTIFIER brackets TOKEN_ASSIGN TOKEN_brace_block TOKEN_SEMICOLON  */
#line 875 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_array_multidimensional_inicializado((yyvsp[-5].node), (yyvsp[-3].node), (yyvsp[-4].str), (yyvsp[-1].node), (yylsp[-5]).first_line, (yylsp[-5]).first_column);
        //                                                   ^^^ $3 = brackets, $2 = TOKEN_IDENTIFIER
    }
#line 3646 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 133: /* contenido_vector: contenido_vector TOKEN_COMMA expresion  */
#line 883 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_contenido_vector_add((yyvsp[-2].node), (yyvsp[0].node));
    }
#line 3654 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 134: /* contenido_vector: expresion  */
#line 887 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_contenido_vector_single((yyvsp[0].node), (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 3662 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 135: /* lista_expresiones: lista_expresiones TOKEN_COMMA expresion  */
#line 894 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_lista_expresiones_add((yyvsp[-2].node), (yyvsp[0].node));
    }
#line 3670 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 136: /* lista_expresiones: expresion  */
#line 898 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_lista_expresiones_single((yyvsp[0].node), (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 3678 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 137: /* arrays_acceso: TOKEN_IDENTIFIER TOKEN_BRACKET_LEFT expresion TOKEN_BRACKET_RIGHT TOKEN_SEMICOLON  */
#line 905 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_array_acceso_1d((yyvsp[-4].str), (yyvsp[-2].node), (yylsp[-4]).first_line, (yylsp[-4]).first_column);
    }
#line 3686 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 138: /* arrays_acceso: TOKEN_IDENTIFIER brackets_indices TOKEN_SEMICOLON  */
#line 909 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_array_acceso_multidimensional((yyvsp[-2].str), (yyvsp[-1].node), (yylsp[-2]).first_line, (yylsp[-2]).first_column);
    }
#line 3694 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 139: /* brackets_indices: brackets_indices TOKEN_BRACKET_LEFT expresion TOKEN_BRACKET_RIGHT  */
#line 916 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_brackets_indices_add((yyvsp[-3].node), (yyvsp[-1].node));
    }
#line 3702 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 140: /* brackets_indices: TOKEN_BRACKET_LEFT expresion TOKEN_BRACKET_RIGHT  */
#line 920 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_brackets_indices_single((yyvsp[-1].node), (yylsp[-2]).first_line, (yylsp[-2]).first_column);
    }
#line 3710 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 141: /* arrays_asignacion: tipo TOKEN_IDENTIFIER TOKEN_ASSIGN TOKEN_IDENTIFIER TOKEN_BRACKET_LEFT expresion TOKEN_BRACKET_RIGHT TOKEN_SEMICOLON  */
#line 927 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_array_asignacion_1d((yyvsp[-7].node), (yyvsp[-6].str), (yyvsp[-4].str), (yyvsp[-2].node), (yylsp[-7]).first_line, (yylsp[-7]).first_column);
    }
#line 3718 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 142: /* arrays_asignacion: tipo TOKEN_IDENTIFIER TOKEN_ASSIGN TOKEN_IDENTIFIER brackets_indices TOKEN_SEMICOLON  */
#line 931 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_array_asignacion_multidimensional((yyvsp[-5].node), (yyvsp[-4].str), (yyvsp[-2].str), (yyvsp[-1].node), (yylsp[-5]).first_line, (yylsp[-5]).first_column);
    }
#line 3726 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 143: /* arrays_asignacion: TOKEN_IDENTIFIER brackets_indices TOKEN_ASSIGN expresion TOKEN_SEMICOLON  */
#line 935 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_array_asignacion_elemento((yyvsp[-4].str), (yyvsp[-3].node), (yyvsp[-1].node), (yylsp[-4]).first_line, (yylsp[-4]).first_column);
    }
#line 3734 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 144: /* brackets: brackets TOKEN_BRACKET_LEFT TOKEN_BRACKET_RIGHT  */
#line 944 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_brackets_add((yyvsp[-2].node), (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 3742 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 145: /* brackets: TOKEN_BRACKET_LEFT TOKEN_BRACKET_RIGHT  */
#line 948 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_brackets_single((yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 3750 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 146: /* brackets_new: brackets_new TOKEN_BRACKET_LEFT expresion TOKEN_BRACKET_RIGHT  */
#line 956 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_brackets_new_add((yyvsp[-3].node), (yyvsp[-1].node));
    }
#line 3758 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 147: /* brackets_new: TOKEN_BRACKET_LEFT expresion TOKEN_BRACKET_RIGHT  */
#line 960 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_brackets_new_single((yyvsp[-1].node), (yylsp[-2]).first_line, (yylsp[-2]).first_column);
    }
#line 3766 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 148: /* TOKEN_brace_block: TOKEN_BRACE_LEFT brace_elements TOKEN_BRACE_RIGHT  */
#line 968 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_brace_block((yyvsp[-1].node), (yylsp[-2]).first_line, (yylsp[-2]).first_column);
    }
#line 3774 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 149: /* brace_elements: brace_elements TOKEN_COMMA brace_element  */
#line 976 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_brace_elements_add((yyvsp[-2].node), (yyvsp[0].node));
    }
#line 3782 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 150: /* brace_elements: brace_element  */
#line 980 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_brace_elements_single((yyvsp[0].node), (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 3790 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 151: /* brace_element: TOKEN_brace_block  */
#line 987 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 3798 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 152: /* brace_element: lista_expresiones  */
#line 991 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 3806 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 153: /* funcion: tipo TOKEN_IDENTIFIER TOKEN_PAREN_LEFT parametros TOKEN_PAREN_RIGHT bloque_funcion  */
#line 998 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_funcion((yyvsp[-5].node), (yyvsp[-4].str), (yyvsp[-2].node), (yyvsp[0].node), (yylsp[-5]).first_line, (yylsp[-5]).first_column);
    }
#line 3814 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 154: /* parametros: parametro  */
#line 1006 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_parametros_single((yyvsp[0].node), (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 3822 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 155: /* parametros: parametros TOKEN_COMMA parametro  */
#line 1010 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_parametros_add((yyvsp[-2].node), (yyvsp[0].node));
    }
#line 3830 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 156: /* parametros: %empty  */
#line 1014 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_parametros_vacio(0, 0);  // ← Usar 0, 0 como en otras reglas vacías
    }
#line 3838 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 157: /* parametro: tipo TOKEN_IDENTIFIER  */
#line 1022 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_parametro_simple((yyvsp[-1].node), (yyvsp[0].str), (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 3846 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 158: /* parametro: tipo TOKEN_IDENTIFIER brackets  */
#line 1026 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_parametro_array((yyvsp[-2].node), (yyvsp[-1].str), (yyvsp[0].node), (yylsp[-2]).first_line, (yylsp[-2]).first_column);
    }
#line 3854 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 159: /* bloque_funcion: TOKEN_BRACE_LEFT cuerpo_funcion TOKEN_BRACE_RIGHT  */
#line 1033 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_bloque_funcion((yyvsp[-1].node), (yylsp[-2]).first_line, (yylsp[-2]).first_column);
    }
#line 3862 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 160: /* cuerpo_funcion: cuerpo_funcion elemento_funcion  */
#line 1040 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_cuerpo_funcion_add((yyvsp[-1].node), (yyvsp[0].node));
    }
#line 3870 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 161: /* cuerpo_funcion: elemento_funcion  */
#line 1044 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_cuerpo_funcion_single((yyvsp[0].node), (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 3878 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 162: /* cuerpo_funcion: %empty  */
#line 1048 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_cuerpo_funcion_vacio(0, 0);
    }
#line 3886 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 163: /* elemento_funcion: instruccion  */
#line 1055 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 3894 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 164: /* elemento_funcion: sentencias  */
#line 1059 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 3902 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 165: /* argumentos: argumentos TOKEN_COMMA expresion  */
#line 1067 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_argumentos_add((yyvsp[-2].node), (yyvsp[0].node));
    }
#line 3910 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 166: /* argumentos: expresion  */
#line 1071 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_argumentos_single((yyvsp[0].node), (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 3918 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 167: /* argumentos: %empty  */
#line 1075 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_argumentos_vacio(0, 0);
    }
#line 3926 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 168: /* embebidas: parseint_embebida  */
#line 1082 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 3934 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 169: /* embebidas: parsefloat_embebida  */
#line 1086 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 3942 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 170: /* embebidas: parsedouble_embebida  */
#line 1090 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 3950 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 171: /* embebidas: valueof_embebida  */
#line 1094 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 3958 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 172: /* embebidas: indexof_embebida  */
#line 1098 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 3966 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 173: /* embebidas: length_embebida  */
#line 1102 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 3974 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 174: /* embebidas: add_embebida  */
#line 1106 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 3982 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 175: /* embebidas: join_embebida  */
#line 1110 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 3990 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 176: /* parseint_embebida: TOKEN_PARSEINT TOKEN_PAREN_LEFT expresion TOKEN_PAREN_RIGHT  */
#line 1118 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_parseint_embebida((yyvsp[-1].node), (yylsp[-3]).first_line, (yylsp[-3]).first_column);
    }
#line 3998 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 177: /* parseint_embebida: TOKEN_PARSEINT TOKEN_PAREN_LEFT expresion TOKEN_COMMA expresion TOKEN_PAREN_RIGHT  */
#line 1123 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_parseint_embebida_radix((yyvsp[-3].node), (yyvsp[-1].node), (yylsp[-5]).first_line, (yylsp[-5]).first_column);
    }
#line 4006 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 178: /* parsedouble_embebida: TOKEN_PARSEDOUBLE TOKEN_PAREN_LEFT expresion TOKEN_PAREN_RIGHT  */
#line 1130 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_parsedouble_embebida((yyvsp[-1].node), (yylsp[-3]).first_line, (yylsp[-3]).first_column);
    }
#line 4014 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 179: /* parsefloat_embebida: TOKEN_PARSEFLOAT TOKEN_PAREN_LEFT expresion TOKEN_PAREN_RIGHT  */
#line 1137 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_parsefloat_embebida((yyvsp[-1].node), (yylsp[-3]).first_line, (yylsp[-3]).first_column);
    }
#line 4022 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 180: /* valueof_embebida: TOKEN_VALUEOF TOKEN_PAREN_LEFT expresion TOKEN_PAREN_RIGHT  */
#line 1144 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_valueof_embebida((yyvsp[-1].node), (yylsp[-3]).first_line, (yylsp[-3]).first_column);
    }
#line 4030 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 181: /* indexof_embebida: TOKEN_INDEXOF TOKEN_PAREN_LEFT expresion TOKEN_COMMA expresion TOKEN_PAREN_RIGHT  */
#line 1151 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_indexof_embebida((yyvsp[-3].node), (yyvsp[-1].node), (yylsp[-5]).first_line, (yylsp[-5]).first_column);
    }
#line 4038 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 182: /* length_embebida: expresion TOKEN_LENGTH  */
#line 1158 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_length_embebida((yyvsp[-1].node), (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 4046 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 183: /* add_embebida: expresion TOKEN_ADD TOKEN_PAREN_LEFT expresion TOKEN_PAREN_RIGHT  */
#line 1165 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_add_embebida((yyvsp[-4].node), (yyvsp[-1].node), (yylsp[-3]).first_line, (yylsp[-3]).first_column);
    }
#line 4054 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 184: /* join_embebida: TOKEN_STRINGJOIN TOKEN_PAREN_LEFT expresion TOKEN_COMMA contenido_vector TOKEN_PAREN_RIGHT  */
#line 1173 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_join_embebida((yyvsp[-3].node), (yyvsp[-1].node), (yylsp[-5]).first_line, (yylsp[-5]).first_column);
    }
#line 4062 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 185: /* join_embebida: TOKEN_STRINGJOIN TOKEN_PAREN_LEFT expresion TOKEN_COMMA expresion TOKEN_PAREN_RIGHT  */
#line 1177 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_join_embebida((yyvsp[-3].node), (yyvsp[-1].node), (yylsp[-5]).first_line, (yylsp[-5]).first_column);
    }
#line 4070 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;


#line 4074 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"

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

#line 1183 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"


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
