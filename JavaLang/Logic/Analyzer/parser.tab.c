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

#line 106 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"

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
  YYSYMBOL_TOKEN_EQUALS = 8,               /* TOKEN_EQUALS  */
  YYSYMBOL_TOKEN_NEW = 9,                  /* TOKEN_NEW  */
  YYSYMBOL_TOKEN_PUBLIC = 10,              /* TOKEN_PUBLIC  */
  YYSYMBOL_TOKEN_STATIC = 11,              /* TOKEN_STATIC  */
  YYSYMBOL_TOKEN_VOID = 12,                /* TOKEN_VOID  */
  YYSYMBOL_TOKEN_MAIN = 13,                /* TOKEN_MAIN  */
  YYSYMBOL_TOKEN_NULL = 14,                /* TOKEN_NULL  */
  YYSYMBOL_TOKEN_IDENTIFIER = 15,          /* TOKEN_IDENTIFIER  */
  YYSYMBOL_TOKEN_PLUS = 16,                /* TOKEN_PLUS  */
  YYSYMBOL_TOKEN_MINUS = 17,               /* TOKEN_MINUS  */
  YYSYMBOL_TOKEN_MULTIPLICATION = 18,      /* TOKEN_MULTIPLICATION  */
  YYSYMBOL_TOKEN_DIVISION = 19,            /* TOKEN_DIVISION  */
  YYSYMBOL_TOKEN_MODULE = 20,              /* TOKEN_MODULE  */
  YYSYMBOL_TOKEN_PLUS_ASSIGN = 21,         /* TOKEN_PLUS_ASSIGN  */
  YYSYMBOL_TOKEN_MINUS_ASSIGN = 22,        /* TOKEN_MINUS_ASSIGN  */
  YYSYMBOL_TOKEN_MULT_ASSIGN = 23,         /* TOKEN_MULT_ASSIGN  */
  YYSYMBOL_TOKEN_DIV_ASSIGN = 24,          /* TOKEN_DIV_ASSIGN  */
  YYSYMBOL_TOKEN_MOD_ASSIGN = 25,          /* TOKEN_MOD_ASSIGN  */
  YYSYMBOL_TOKEN_AND_ASSIGN = 26,          /* TOKEN_AND_ASSIGN  */
  YYSYMBOL_TOKEN_OR_ASSIGN = 27,           /* TOKEN_OR_ASSIGN  */
  YYSYMBOL_TOKEN_XOR_ASSIGN = 28,          /* TOKEN_XOR_ASSIGN  */
  YYSYMBOL_TOKEN_SHIFT_LEFT_ASSIGN = 29,   /* TOKEN_SHIFT_LEFT_ASSIGN  */
  YYSYMBOL_TOKEN_SHIFT_RIGHT_ASSIGN = 30,  /* TOKEN_SHIFT_RIGHT_ASSIGN  */
  YYSYMBOL_TOKEN_ASSIGN = 31,              /* TOKEN_ASSIGN  */
  YYSYMBOL_TOKEN_EQUAL = 32,               /* TOKEN_EQUAL  */
  YYSYMBOL_TOKEN_UNEQUAL = 33,             /* TOKEN_UNEQUAL  */
  YYSYMBOL_TOKEN_GREATER = 34,             /* TOKEN_GREATER  */
  YYSYMBOL_TOKEN_LESS = 35,                /* TOKEN_LESS  */
  YYSYMBOL_TOKEN_GREATER_EQUAL = 36,       /* TOKEN_GREATER_EQUAL  */
  YYSYMBOL_TOKEN_LESS_EQUAL = 37,          /* TOKEN_LESS_EQUAL  */
  YYSYMBOL_TOKEN_AND = 38,                 /* TOKEN_AND  */
  YYSYMBOL_TOKEN_OR = 39,                  /* TOKEN_OR  */
  YYSYMBOL_TOKEN_NOT = 40,                 /* TOKEN_NOT  */
  YYSYMBOL_TOKEN_PAREN_LEFT = 41,          /* TOKEN_PAREN_LEFT  */
  YYSYMBOL_TOKEN_PAREN_RIGHT = 42,         /* TOKEN_PAREN_RIGHT  */
  YYSYMBOL_TOKEN_SEMICOLON = 43,           /* TOKEN_SEMICOLON  */
  YYSYMBOL_TOKEN_DOT = 44,                 /* TOKEN_DOT  */
  YYSYMBOL_TOKEN_COMMA = 45,               /* TOKEN_COMMA  */
  YYSYMBOL_TOKEN_BRACE_LEFT = 46,          /* TOKEN_BRACE_LEFT  */
  YYSYMBOL_TOKEN_BRACE_RIGHT = 47,         /* TOKEN_BRACE_RIGHT  */
  YYSYMBOL_TOKEN_BRACKET_LEFT = 48,        /* TOKEN_BRACKET_LEFT  */
  YYSYMBOL_TOKEN_BRACKET_RIGHT = 49,       /* TOKEN_BRACKET_RIGHT  */
  YYSYMBOL_TOKEN_QUOTE_DOUBLE = 50,        /* TOKEN_QUOTE_DOUBLE  */
  YYSYMBOL_TOKEN_QUOTE_SINGLE = 51,        /* TOKEN_QUOTE_SINGLE  */
  YYSYMBOL_TOKEN_COLON = 52,               /* TOKEN_COLON  */
  YYSYMBOL_TOKEN_IF = 53,                  /* TOKEN_IF  */
  YYSYMBOL_TOKEN_ELSE = 54,                /* TOKEN_ELSE  */
  YYSYMBOL_TOKEN_SWITCH = 55,              /* TOKEN_SWITCH  */
  YYSYMBOL_TOKEN_CASE = 56,                /* TOKEN_CASE  */
  YYSYMBOL_TOKEN_DEFAULT = 57,             /* TOKEN_DEFAULT  */
  YYSYMBOL_TOKEN_WHILE = 58,               /* TOKEN_WHILE  */
  YYSYMBOL_TOKEN_DO = 59,                  /* TOKEN_DO  */
  YYSYMBOL_TOKEN_FOR = 60,                 /* TOKEN_FOR  */
  YYSYMBOL_TOKEN_BREAK = 61,               /* TOKEN_BREAK  */
  YYSYMBOL_TOKEN_CONTINUE = 62,            /* TOKEN_CONTINUE  */
  YYSYMBOL_TOKEN_RETURN = 63,              /* TOKEN_RETURN  */
  YYSYMBOL_TOKEN_SOUT = 64,                /* TOKEN_SOUT  */
  YYSYMBOL_TOKEN_PARSEINT = 65,            /* TOKEN_PARSEINT  */
  YYSYMBOL_TOKEN_PARSEFLOAT = 66,          /* TOKEN_PARSEFLOAT  */
  YYSYMBOL_TOKEN_PARSEDOUBLE = 67,         /* TOKEN_PARSEDOUBLE  */
  YYSYMBOL_TOKEN_VALUEOF = 68,             /* TOKEN_VALUEOF  */
  YYSYMBOL_TOKEN_STRINGJOIN = 69,          /* TOKEN_STRINGJOIN  */
  YYSYMBOL_TOKEN_INDEXOF = 70,             /* TOKEN_INDEXOF  */
  YYSYMBOL_TOKEN_LENGTH = 71,              /* TOKEN_LENGTH  */
  YYSYMBOL_TOKEN_ADD = 72,                 /* TOKEN_ADD  */
  YYSYMBOL_TOKEN_ESCAPE = 73,              /* TOKEN_ESCAPE  */
  YYSYMBOL_TOKEN_INCREMENT = 74,           /* TOKEN_INCREMENT  */
  YYSYMBOL_TOKEN_DECREMENT = 75,           /* TOKEN_DECREMENT  */
  YYSYMBOL_TOKEN_EOF = 76,                 /* TOKEN_EOF  */
  YYSYMBOL_TOKEN_ERROR = 77,               /* TOKEN_ERROR  */
  YYSYMBOL_TOKEN_TYPE_INT = 78,            /* TOKEN_TYPE_INT  */
  YYSYMBOL_TOKEN_TYPE_FLOAT = 79,          /* TOKEN_TYPE_FLOAT  */
  YYSYMBOL_TOKEN_TYPE_STRING = 80,         /* TOKEN_TYPE_STRING  */
  YYSYMBOL_TOKEN_TYPE_CHAR = 81,           /* TOKEN_TYPE_CHAR  */
  YYSYMBOL_TOKEN_TYPE_TRUE = 82,           /* TOKEN_TYPE_TRUE  */
  YYSYMBOL_TOKEN_TYPE_FALSE = 83,          /* TOKEN_TYPE_FALSE  */
  YYSYMBOL_YYACCEPT = 84,                  /* $accept  */
  YYSYMBOL_program = 85,                   /* program  */
  YYSYMBOL_bloque_main = 86,               /* bloque_main  */
  YYSYMBOL_instrucciones = 87,             /* instrucciones  */
  YYSYMBOL_instruccion = 88,               /* instruccion  */
  YYSYMBOL_expresion = 89,                 /* expresion  */
  YYSYMBOL_declaraciones = 90,             /* declaraciones  */
  YYSYMBOL_asignacion_compuesta = 91,      /* asignacion_compuesta  */
  YYSYMBOL_operador_asignacion = 92,       /* operador_asignacion  */
  YYSYMBOL_tipo = 93,                      /* tipo  */
  YYSYMBOL_dato = 94,                      /* dato  */
  YYSYMBOL_lista_declaraciones = 95,       /* lista_declaraciones  */
  YYSYMBOL_lista_declaracion = 96,         /* lista_declaracion  */
  YYSYMBOL_sout = 97,                      /* sout  */
  YYSYMBOL_sentencia_if = 98,              /* sentencia_if  */
  YYSYMBOL_if_simple = 99,                 /* if_simple  */
  YYSYMBOL_if_con_else = 100,              /* if_con_else  */
  YYSYMBOL_if_con_else_if = 101,           /* if_con_else_if  */
  YYSYMBOL_lista_else_if = 102,            /* lista_else_if  */
  YYSYMBOL_else_if = 103,                  /* else_if  */
  YYSYMBOL_sentencias = 104,               /* sentencias  */
  YYSYMBOL_sentencia_switch = 105,         /* sentencia_switch  */
  YYSYMBOL_lista_case = 106,               /* lista_case  */
  YYSYMBOL_case = 107,                     /* case  */
  YYSYMBOL_ciclo_while = 108,              /* ciclo_while  */
  YYSYMBOL_ciclo_do = 109,                 /* ciclo_do  */
  YYSYMBOL_ciclo_for = 110,                /* ciclo_for  */
  YYSYMBOL_inicializacion_for = 111,       /* inicializacion_for  */
  YYSYMBOL_actualizar_for = 112            /* actualizar_for  */
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
typedef yytype_uint8 yy_state_t;

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
#define YYLAST   1090

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  84
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  93
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  200

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   338


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
      75,    76,    77,    78,    79,    80,    81,    82,    83
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   193,   193,   201,   208,   212,   219,   223,   227,   231,
     235,   239,   243,   247,   251,   259,   263,   267,   271,   275,
     281,   285,   291,   295,   299,   303,   309,   313,   319,   323,
     327,   333,   338,   345,   352,   358,   364,   371,   375,   379,
     386,   394,   398,   402,   406,   410,   414,   418,   422,   426,
     430,   434,   442,   446,   450,   454,   458,   465,   469,   473,
     477,   481,   485,   492,   496,   503,   510,   517,   521,   525,
     532,   539,   546,   553,   557,   564,   571,   575,   579,   583,
     590,   597,   601,   608,   612,   619,   626,   633,   640,   644,
     648,   653,   659,   664
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
  "if_con_else_if", "lista_else_if", "else_if", "sentencias",
  "sentencia_switch", "lista_case", "case", "ciclo_while", "ciclo_do",
  "ciclo_for", "inicializacion_for", "actualizar_for", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-52)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       0,     4,    26,   -52,    28,   -52,    25,     1,     7,     6,
     678,   -52,   -52,   -52,   -52,   -52,   741,   119,   119,     9,
      12,    14,    10,    16,    20,   119,   119,   -52,   -52,   -52,
     -52,   -52,   -52,   213,   -52,   757,   -52,   -52,    51,   -52,
     -52,   -52,   -52,   -52,   -52,   -52,   -52,   -52,   -52,   -52,
     -52,   -52,   -52,   -52,   -52,   -52,   -52,   -52,   -52,   -52,
     119,   -52,   -52,   119,   -42,   -52,   897,   119,   119,   119,
     678,    24,   119,   -52,   -52,   -52,   -52,   119,   119,   119,
     119,   119,   119,   119,   119,   119,   119,   119,   119,   119,
     -52,   -30,   -31,   -52,  1022,   785,   -52,   908,   935,   946,
     275,   741,  1022,    66,    39,   973,    17,    17,   -52,   -52,
     -52,   -13,   -13,    71,    71,    71,    71,  1053,  1046,   119,
     -52,   -52,    68,   -52,    46,    47,    48,    27,   119,    64,
     119,    53,   813,    69,   -52,   678,    41,   678,    60,  1022,
     119,   841,   -52,   -52,   119,   337,   -35,   -36,   -52,   399,
     119,  1022,   119,  1022,    54,    57,   -52,   -52,   -52,   984,
    1022,    73,   -28,    59,   -52,   678,    75,    65,   678,    79,
     -12,   -52,   151,   -52,   678,   461,   119,   678,    81,    82,
     107,    70,   523,   -52,  1011,   585,   -52,   -52,   -52,   869,
      76,   -52,    83,   -52,   -52,   678,   678,   678,   647,   -52
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     2,     0,     1,     0,     0,     0,     0,
       0,    53,    54,    52,    55,    56,    36,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    58,    59,    57,
      60,    61,    62,     0,     4,     0,     7,     8,     0,    35,
       6,    10,    67,    68,    69,    11,    12,    13,    14,    41,
      42,    43,    44,    45,    46,    47,    48,    49,    50,    51,
       0,    31,    32,     0,    36,    28,     0,     0,     0,     0,
       0,    91,     0,    29,    30,     3,     5,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       9,     0,     0,    63,    33,     0,    34,     0,     0,     0,
       0,    36,    90,     0,     0,     0,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,     0,
      39,    38,     0,    40,     0,     0,     0,     0,     0,     0,
       0,     0,    65,     0,    64,     0,     0,     0,     0,    89,
       0,     0,    66,    37,     0,     0,     0,     0,    82,     0,
       0,    88,    93,    65,    70,     0,    80,    81,    85,     0,
      92,     0,     0,     0,    74,     0,     0,     0,     0,     0,
       0,    73,     0,    86,     0,     0,     0,     0,     0,     0,
       0,    83,     0,    71,     0,     0,    76,    77,    79,     0,
       0,    87,     0,    72,    78,     0,     0,    84,     0,    75
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -52,   -52,   -52,   -51,   -33,    -9,   -52,   -52,    29,    61,
     -10,   -52,    11,   -52,   -52,   -52,   -52,   -52,   -52,   -26,
     -52,   -52,   -52,    -7,   -52,   -52,   -52,   -52,   -52
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     3,    33,    34,    35,    36,    37,    63,    38,
      39,    92,    93,    40,    41,    42,    43,    44,   163,   164,
     181,    45,   147,   148,    46,    47,    48,   104,   161
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      76,   119,    60,    77,    78,    79,    80,    81,    65,    66,
       1,   156,   121,   120,   122,     4,    73,    74,   168,   100,
     146,    84,    85,    86,    87,   169,     5,    11,    12,    13,
      14,    15,    61,    62,   177,    79,    80,    81,     7,   101,
       6,   169,     8,    27,    28,    29,    30,    31,    32,     9,
      67,    94,    10,    68,    95,    69,    70,    71,    97,    98,
      99,    72,   102,   105,    17,    18,    91,    76,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   129,   130,   133,   145,   138,   149,    77,    78,    79,
      80,    81,   135,   136,   137,   140,   142,   146,    25,    26,
     144,   150,    27,    28,    29,    30,    31,    32,   162,   165,
     132,   174,    76,   170,   172,   167,    76,   175,   173,   139,
     176,   141,    64,   182,   186,   187,   185,   190,   195,   196,
     128,   151,   103,   134,    64,   153,   155,   171,     0,    76,
     157,   159,    76,   160,   197,   198,     0,    17,    18,    76,
     188,     0,    76,     0,    11,    12,    13,    14,    15,    17,
      18,     0,     0,     0,    76,    76,    16,   184,     0,     0,
       0,   189,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    25,    26,     0,     0,    27,    28,    29,    30,    31,
      32,    17,    18,    25,    26,     0,     0,    27,    28,    29,
      30,    31,    32,     0,    19,     0,    20,     0,     0,    21,
      22,    23,   178,   179,   180,    24,    11,    12,    13,    14,
      15,     0,     0,     0,     0,    25,    26,     0,    16,    27,
      28,    29,    30,    31,    32,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    17,    18,     0,     0,     0,     0,     0,
      75,     0,     0,     0,     0,     0,    19,     0,    20,     0,
       0,    21,    22,    23,     0,     0,     0,    24,    11,    12,
      13,    14,    15,     0,     0,     0,     0,    25,    26,     0,
      16,    27,    28,    29,    30,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    17,    18,     0,     0,     0,
       0,     0,   127,     0,     0,     0,     0,     0,    19,     0,
      20,     0,     0,    21,    22,    23,     0,     0,     0,    24,
      11,    12,    13,    14,    15,     0,     0,     0,     0,    25,
      26,     0,    16,    27,    28,    29,    30,    31,    32,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    17,    18,     0,
       0,     0,     0,     0,   154,     0,     0,     0,     0,     0,
      19,     0,    20,     0,     0,    21,    22,    23,     0,     0,
       0,    24,    11,    12,    13,    14,    15,     0,     0,     0,
       0,    25,    26,     0,    16,    27,    28,    29,    30,    31,
      32,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    17,
      18,     0,     0,     0,     0,     0,   158,     0,     0,     0,
       0,     0,    19,     0,    20,     0,     0,    21,    22,    23,
       0,     0,     0,    24,    11,    12,    13,    14,    15,     0,
       0,     0,     0,    25,    26,     0,    16,    27,    28,    29,
      30,    31,    32,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    17,    18,     0,     0,     0,     0,     0,   183,     0,
       0,     0,     0,     0,    19,     0,    20,     0,     0,    21,
      22,    23,     0,     0,     0,    24,    11,    12,    13,    14,
      15,     0,     0,     0,     0,    25,    26,     0,    16,    27,
      28,    29,    30,    31,    32,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    17,    18,     0,     0,     0,     0,     0,
     191,     0,     0,     0,     0,     0,    19,     0,    20,     0,
       0,    21,    22,    23,     0,     0,     0,    24,    11,    12,
      13,    14,    15,     0,     0,     0,     0,    25,    26,     0,
      16,    27,    28,    29,    30,    31,    32,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    17,    18,     0,     0,     0,
       0,     0,   193,     0,     0,     0,     0,     0,    19,     0,
      20,     0,     0,    21,    22,    23,     0,     0,     0,    24,
      11,    12,    13,    14,    15,     0,     0,     0,     0,    25,
      26,     0,    16,    27,    28,    29,    30,    31,    32,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    11,    12,    13,    14,    15,     0,    17,    18,     0,
       0,     0,     0,    16,   199,     0,     0,     0,     0,     0,
      19,     0,    20,     0,     0,    21,    22,    23,     0,     0,
       0,    24,     0,     0,     0,     0,     0,     0,    17,    18,
       0,    25,    26,     0,     0,    27,    28,    29,    30,    31,
      32,    19,     0,    20,     0,     0,    21,    22,    23,     0,
       0,     0,    24,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    25,    26,     0,     0,    27,    28,    29,    30,
      31,    32,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    77,    78,    79,    80,    81,     0,     0,
       0,     0,     0,     0,     0,    60,     0,     0,     0,    82,
      83,    84,    85,    86,    87,    88,    89,     0,     0,     0,
      90,    77,    78,    79,    80,    81,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    61,    62,    82,    83,    84,
      85,    86,    87,    88,    89,     0,     0,     0,   123,    77,
      78,    79,    80,    81,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    82,    83,    84,    85,    86,
      87,    88,    89,     0,     0,     0,   143,    77,    78,    79,
      80,    81,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    82,    83,    84,    85,    86,    87,    88,
      89,     0,     0,     0,   152,    77,    78,    79,    80,    81,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    82,    83,    84,    85,    86,    87,    88,    89,     0,
       0,     0,   194,    77,    78,    79,    80,    81,     0,     0,
       0,     0,     0,     0,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,     0,     0,    96,
      82,    83,    84,    85,    86,    87,    88,    89,     0,     0,
     124,    77,    78,    79,    80,    81,     0,     0,     0,     0,
       0,     0,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,     0,     0,   125,    82,    83,
      84,    85,    86,    87,    88,    89,     0,     0,   126,    77,
      78,    79,    80,    81,     0,     0,     0,     0,     0,     0,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,     0,     0,   131,    82,    83,    84,    85,
      86,    87,    88,    89,     0,     0,   166,    77,    78,    79,
      80,    81,     0,     0,     0,     0,     0,     0,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,     0,     0,   192,    82,    83,    84,    85,    86,    87,
      88,    89,    77,    78,    79,    80,    81,     0,     0,    77,
      78,    79,    80,    81,     0,     0,     0,     0,    82,    83,
      84,    85,    86,    87,    88,    82,    83,    84,    85,    86,
      87
};

static const yytype_int16 yycheck[] =
{
      33,    31,    44,    16,    17,    18,    19,    20,    17,    18,
      10,    47,    43,    43,    45,    11,    25,    26,    46,    70,
      56,    34,    35,    36,    37,    53,     0,     3,     4,     5,
       6,     7,    74,    75,    46,    18,    19,    20,    13,    15,
      12,    53,    41,    78,    79,    80,    81,    82,    83,    42,
      41,    60,    46,    41,    63,    41,    46,    41,    67,    68,
      69,    41,    71,    72,    40,    41,    15,   100,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    15,    43,    15,   135,    58,   137,    16,    17,    18,
      19,    20,    46,    46,    46,    31,    43,    56,    74,    75,
      31,    41,    78,    79,    80,    81,    82,    83,    54,    52,
     119,    46,   145,    54,   165,    42,   149,   168,    43,   128,
      41,   130,    15,   174,    43,    43,   177,    57,    52,    46,
     101,   140,    71,   122,    15,   144,   146,   163,    -1,   172,
     147,   150,   175,   152,   195,   196,    -1,    40,    41,   182,
      43,    -1,   185,    -1,     3,     4,     5,     6,     7,    40,
      41,    -1,    -1,    -1,   197,   198,    15,   176,    -1,    -1,
      -1,   180,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    74,    75,    -1,    -1,    78,    79,    80,    81,    82,
      83,    40,    41,    74,    75,    -1,    -1,    78,    79,    80,
      81,    82,    83,    -1,    53,    -1,    55,    -1,    -1,    58,
      59,    60,    61,    62,    63,    64,     3,     4,     5,     6,
       7,    -1,    -1,    -1,    -1,    74,    75,    -1,    15,    78,
      79,    80,    81,    82,    83,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    40,    41,    -1,    -1,    -1,    -1,    -1,
      47,    -1,    -1,    -1,    -1,    -1,    53,    -1,    55,    -1,
      -1,    58,    59,    60,    -1,    -1,    -1,    64,     3,     4,
       5,     6,     7,    -1,    -1,    -1,    -1,    74,    75,    -1,
      15,    78,    79,    80,    81,    82,    83,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    40,    41,    -1,    -1,    -1,
      -1,    -1,    47,    -1,    -1,    -1,    -1,    -1,    53,    -1,
      55,    -1,    -1,    58,    59,    60,    -1,    -1,    -1,    64,
       3,     4,     5,     6,     7,    -1,    -1,    -1,    -1,    74,
      75,    -1,    15,    78,    79,    80,    81,    82,    83,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,    41,    -1,
      -1,    -1,    -1,    -1,    47,    -1,    -1,    -1,    -1,    -1,
      53,    -1,    55,    -1,    -1,    58,    59,    60,    -1,    -1,
      -1,    64,     3,     4,     5,     6,     7,    -1,    -1,    -1,
      -1,    74,    75,    -1,    15,    78,    79,    80,    81,    82,
      83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    40,
      41,    -1,    -1,    -1,    -1,    -1,    47,    -1,    -1,    -1,
      -1,    -1,    53,    -1,    55,    -1,    -1,    58,    59,    60,
      -1,    -1,    -1,    64,     3,     4,     5,     6,     7,    -1,
      -1,    -1,    -1,    74,    75,    -1,    15,    78,    79,    80,
      81,    82,    83,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    40,    41,    -1,    -1,    -1,    -1,    -1,    47,    -1,
      -1,    -1,    -1,    -1,    53,    -1,    55,    -1,    -1,    58,
      59,    60,    -1,    -1,    -1,    64,     3,     4,     5,     6,
       7,    -1,    -1,    -1,    -1,    74,    75,    -1,    15,    78,
      79,    80,    81,    82,    83,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    40,    41,    -1,    -1,    -1,    -1,    -1,
      47,    -1,    -1,    -1,    -1,    -1,    53,    -1,    55,    -1,
      -1,    58,    59,    60,    -1,    -1,    -1,    64,     3,     4,
       5,     6,     7,    -1,    -1,    -1,    -1,    74,    75,    -1,
      15,    78,    79,    80,    81,    82,    83,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    40,    41,    -1,    -1,    -1,
      -1,    -1,    47,    -1,    -1,    -1,    -1,    -1,    53,    -1,
      55,    -1,    -1,    58,    59,    60,    -1,    -1,    -1,    64,
       3,     4,     5,     6,     7,    -1,    -1,    -1,    -1,    74,
      75,    -1,    15,    78,    79,    80,    81,    82,    83,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,     6,     7,    -1,    40,    41,    -1,
      -1,    -1,    -1,    15,    47,    -1,    -1,    -1,    -1,    -1,
      53,    -1,    55,    -1,    -1,    58,    59,    60,    -1,    -1,
      -1,    64,    -1,    -1,    -1,    -1,    -1,    -1,    40,    41,
      -1,    74,    75,    -1,    -1,    78,    79,    80,    81,    82,
      83,    53,    -1,    55,    -1,    -1,    58,    59,    60,    -1,
      -1,    -1,    64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    74,    75,    -1,    -1,    78,    79,    80,    81,
      82,    83,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    16,    17,    18,    19,    20,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    44,    -1,    -1,    -1,    32,
      33,    34,    35,    36,    37,    38,    39,    -1,    -1,    -1,
      43,    16,    17,    18,    19,    20,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    74,    75,    32,    33,    34,
      35,    36,    37,    38,    39,    -1,    -1,    -1,    43,    16,
      17,    18,    19,    20,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    32,    33,    34,    35,    36,
      37,    38,    39,    -1,    -1,    -1,    43,    16,    17,    18,
      19,    20,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    32,    33,    34,    35,    36,    37,    38,
      39,    -1,    -1,    -1,    43,    16,    17,    18,    19,    20,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    32,    33,    34,    35,    36,    37,    38,    39,    -1,
      -1,    -1,    43,    16,    17,    18,    19,    20,    -1,    -1,
      -1,    -1,    -1,    -1,    16,    17,    18,    19,    20,    32,
      33,    34,    35,    36,    37,    38,    39,    -1,    -1,    42,
      32,    33,    34,    35,    36,    37,    38,    39,    -1,    -1,
      42,    16,    17,    18,    19,    20,    -1,    -1,    -1,    -1,
      -1,    -1,    16,    17,    18,    19,    20,    32,    33,    34,
      35,    36,    37,    38,    39,    -1,    -1,    42,    32,    33,
      34,    35,    36,    37,    38,    39,    -1,    -1,    42,    16,
      17,    18,    19,    20,    -1,    -1,    -1,    -1,    -1,    -1,
      16,    17,    18,    19,    20,    32,    33,    34,    35,    36,
      37,    38,    39,    -1,    -1,    42,    32,    33,    34,    35,
      36,    37,    38,    39,    -1,    -1,    42,    16,    17,    18,
      19,    20,    -1,    -1,    -1,    -1,    -1,    -1,    16,    17,
      18,    19,    20,    32,    33,    34,    35,    36,    37,    38,
      39,    -1,    -1,    42,    32,    33,    34,    35,    36,    37,
      38,    39,    16,    17,    18,    19,    20,    -1,    -1,    16,
      17,    18,    19,    20,    -1,    -1,    -1,    -1,    32,    33,
      34,    35,    36,    37,    38,    32,    33,    34,    35,    36,
      37
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    10,    85,    86,    11,     0,    12,    13,    41,    42,
      46,     3,     4,     5,     6,     7,    15,    40,    41,    53,
      55,    58,    59,    60,    64,    74,    75,    78,    79,    80,
      81,    82,    83,    87,    88,    89,    90,    91,    93,    94,
      97,    98,    99,   100,   101,   105,   108,   109,   110,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      44,    74,    75,    92,    15,    89,    89,    41,    41,    41,
      46,    41,    41,    89,    89,    47,    88,    16,    17,    18,
      19,    20,    32,    33,    34,    35,    36,    37,    38,    39,
      43,    15,    95,    96,    89,    89,    42,    89,    89,    89,
      87,    15,    89,    93,   111,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    31,
      43,    43,    45,    43,    42,    42,    42,    47,    92,    15,
      43,    42,    89,    15,    96,    46,    46,    46,    58,    89,
      31,    89,    43,    43,    31,    87,    56,   106,   107,    87,
      41,    89,    43,    89,    47,    94,    47,   107,    47,    89,
      89,   112,    54,   102,   103,    52,    42,    42,    46,    53,
      54,   103,    87,    43,    46,    87,    41,    46,    61,    62,
      63,   104,    87,    47,    89,    87,    43,    43,    43,    89,
      57,    47,    42,    47,    43,    52,    46,    87,    87,    47
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    84,    85,    86,    87,    87,    88,    88,    88,    88,
      88,    88,    88,    88,    88,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    90,    90,    90,
      91,    92,    92,    92,    92,    92,    92,    92,    92,    92,
      92,    92,    93,    93,    93,    93,    93,    94,    94,    94,
      94,    94,    94,    95,    95,    96,    97,    98,    98,    98,
      99,   100,   101,   102,   102,   103,   104,   104,   104,   104,
     105,   106,   106,   107,   107,   108,   109,   110,   111,   111,
     111,   111,   112,   112
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     9,     1,     2,     1,     1,     1,     2,
       1,     1,     1,     1,     1,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     2,
       2,     2,     2,     3,     3,     1,     1,     5,     3,     3,
       4,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     3,     5,     1,     1,     1,
       7,    11,    12,     2,     1,     8,     2,     2,     3,     2,
       7,     2,     1,     5,     8,     7,     9,    11,     4,     3,
       1,     0,     1,     0
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
#line 194 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        ast_root = build_program_node((yyvsp[0].node), (yylsp[0]).first_line, (yylsp[0]).first_column);
        (yyval.node) = ast_root;
    }
#line 1922 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 3: /* bloque_main: TOKEN_PUBLIC TOKEN_STATIC TOKEN_VOID TOKEN_MAIN TOKEN_PAREN_LEFT TOKEN_PAREN_RIGHT TOKEN_BRACE_LEFT instrucciones TOKEN_BRACE_RIGHT  */
#line 202 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_bloque_main_node((yyvsp[-1].node), (yylsp[-8]).first_line, (yylsp[-8]).first_column);
    }
#line 1930 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 4: /* instrucciones: instruccion  */
#line 209 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_instrucciones_single((yyvsp[0].node), (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 1938 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 5: /* instrucciones: instrucciones instruccion  */
#line 213 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_instrucciones_add((yyvsp[-1].node), (yyvsp[0].node));
    }
#line 1946 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 6: /* instruccion: sout  */
#line 220 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1954 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 7: /* instruccion: declaraciones  */
#line 224 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1962 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 8: /* instruccion: asignacion_compuesta  */
#line 228 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1970 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 9: /* instruccion: expresion TOKEN_SEMICOLON  */
#line 232 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = (yyvsp[-1].node);
    }
#line 1978 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 10: /* instruccion: sentencia_if  */
#line 236 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1986 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 11: /* instruccion: sentencia_switch  */
#line 240 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1994 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 12: /* instruccion: ciclo_while  */
#line 244 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2002 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 13: /* instruccion: ciclo_do  */
#line 248 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2010 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 14: /* instruccion: ciclo_for  */
#line 252 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2018 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 15: /* expresion: expresion TOKEN_PLUS expresion  */
#line 260 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_expresion_binaria((yyvsp[-2].node), "+", (yyvsp[0].node), (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 2026 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 16: /* expresion: expresion TOKEN_MINUS expresion  */
#line 264 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_expresion_binaria((yyvsp[-2].node), "-", (yyvsp[0].node), (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 2034 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 17: /* expresion: expresion TOKEN_MULTIPLICATION expresion  */
#line 268 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_expresion_binaria((yyvsp[-2].node), "*", (yyvsp[0].node), (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 2042 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 18: /* expresion: expresion TOKEN_DIVISION expresion  */
#line 272 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_expresion_binaria((yyvsp[-2].node), "/", (yyvsp[0].node), (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 2050 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 19: /* expresion: expresion TOKEN_MODULE expresion  */
#line 276 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_expresion_binaria((yyvsp[-2].node), "%", (yyvsp[0].node), (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 2058 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 20: /* expresion: expresion TOKEN_EQUAL expresion  */
#line 282 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_expresion_binaria((yyvsp[-2].node), "==", (yyvsp[0].node), (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 2066 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 21: /* expresion: expresion TOKEN_UNEQUAL expresion  */
#line 286 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_expresion_binaria((yyvsp[-2].node), "!=", (yyvsp[0].node), (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 2074 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 22: /* expresion: expresion TOKEN_GREATER expresion  */
#line 292 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_expresion_binaria((yyvsp[-2].node), ">", (yyvsp[0].node), (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 2082 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 23: /* expresion: expresion TOKEN_LESS expresion  */
#line 296 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_expresion_binaria((yyvsp[-2].node), "<", (yyvsp[0].node), (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 2090 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 24: /* expresion: expresion TOKEN_GREATER_EQUAL expresion  */
#line 300 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_expresion_binaria((yyvsp[-2].node), ">=", (yyvsp[0].node), (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 2098 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 25: /* expresion: expresion TOKEN_LESS_EQUAL expresion  */
#line 304 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_expresion_binaria((yyvsp[-2].node), "<=", (yyvsp[0].node), (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 2106 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 26: /* expresion: expresion TOKEN_AND expresion  */
#line 310 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_expresion_binaria((yyvsp[-2].node), "&&", (yyvsp[0].node), (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 2114 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 27: /* expresion: expresion TOKEN_OR expresion  */
#line 314 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_expresion_binaria((yyvsp[-2].node), "||", (yyvsp[0].node), (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 2122 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 28: /* expresion: TOKEN_NOT expresion  */
#line 320 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_expresion_unaria("!", (yyvsp[0].node), (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 2130 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 29: /* expresion: TOKEN_INCREMENT expresion  */
#line 324 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_expresion_unaria("++", (yyvsp[0].node), (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 2138 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 30: /* expresion: TOKEN_DECREMENT expresion  */
#line 328 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_expresion_unaria("--", (yyvsp[0].node), (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 2146 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 31: /* expresion: TOKEN_IDENTIFIER TOKEN_INCREMENT  */
#line 334 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        ASTNode* id_node = build_identifier((yyvsp[-1].str), (yylsp[-1]).first_line, (yylsp[-1]).first_column);
        (yyval.node) = build_expresion_postfijo(id_node, "++", (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 2155 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 32: /* expresion: TOKEN_IDENTIFIER TOKEN_DECREMENT  */
#line 339 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        ASTNode* id_node = build_identifier((yyvsp[-1].str), (yylsp[-1]).first_line, (yylsp[-1]).first_column);
        (yyval.node) = build_expresion_postfijo(id_node, "--", (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 2164 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 33: /* expresion: TOKEN_IDENTIFIER TOKEN_DOT expresion  */
#line 346 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        ASTNode* id_node = build_identifier((yyvsp[-2].str), (yylsp[-2]).first_line, (yylsp[-2]).first_column);
        (yyval.node) = build_expresion_acceso(id_node, (yyvsp[0].node), (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 2173 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 34: /* expresion: TOKEN_PAREN_LEFT expresion TOKEN_PAREN_RIGHT  */
#line 353 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_expresion_parentesis((yyvsp[-1].node), (yylsp[-2]).first_line, (yylsp[-2]).first_column);
    }
#line 2181 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 35: /* expresion: dato  */
#line 359 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2189 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 36: /* expresion: TOKEN_IDENTIFIER  */
#line 365 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_identifier((yyvsp[0].str), (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 2197 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 37: /* declaraciones: tipo TOKEN_IDENTIFIER TOKEN_ASSIGN expresion TOKEN_SEMICOLON  */
#line 372 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_declaracion_single((yyvsp[-4].node), (yyvsp[-3].str), (yyvsp[-1].node), (yylsp[-4]).first_line, (yylsp[-4]).first_column);
    }
#line 2205 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 38: /* declaraciones: tipo lista_declaraciones TOKEN_SEMICOLON  */
#line 376 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_declaracion_multiple((yyvsp[-2].node), (yyvsp[-1].node), (yylsp[-2]).first_line, (yylsp[-2]).first_column);
    }
#line 2213 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 39: /* declaraciones: tipo TOKEN_IDENTIFIER TOKEN_SEMICOLON  */
#line 380 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_declaracion_sin_inicializacion((yyvsp[-2].node), (yyvsp[-1].str), (yylsp[-2]).first_line, (yylsp[-2]).first_column);
    }
#line 2221 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 40: /* asignacion_compuesta: TOKEN_IDENTIFIER operador_asignacion expresion TOKEN_SEMICOLON  */
#line 387 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_asignacion_compuesta((yyvsp[-3].str), (yyvsp[-2].node), (yyvsp[-1].node), (yylsp[-3]).first_line, (yylsp[-3]).first_column);
    }
#line 2229 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 41: /* operador_asignacion: TOKEN_PLUS_ASSIGN  */
#line 395 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_operador_asignacion("+=", (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 2237 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 42: /* operador_asignacion: TOKEN_MINUS_ASSIGN  */
#line 399 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_operador_asignacion("-=", (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 2245 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 43: /* operador_asignacion: TOKEN_MULT_ASSIGN  */
#line 403 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_operador_asignacion("*=", (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 2253 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 44: /* operador_asignacion: TOKEN_DIV_ASSIGN  */
#line 407 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_operador_asignacion("/=", (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 2261 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 45: /* operador_asignacion: TOKEN_MOD_ASSIGN  */
#line 411 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_operador_asignacion("%=", (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 2269 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 46: /* operador_asignacion: TOKEN_AND_ASSIGN  */
#line 415 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_operador_asignacion("&=", (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 2277 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 47: /* operador_asignacion: TOKEN_OR_ASSIGN  */
#line 419 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_operador_asignacion("|=", (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 2285 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 48: /* operador_asignacion: TOKEN_XOR_ASSIGN  */
#line 423 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_operador_asignacion("^=", (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 2293 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 49: /* operador_asignacion: TOKEN_SHIFT_LEFT_ASSIGN  */
#line 427 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_operador_asignacion("<<=", (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 2301 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 50: /* operador_asignacion: TOKEN_SHIFT_RIGHT_ASSIGN  */
#line 431 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_operador_asignacion(">>=", (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 2309 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 51: /* operador_asignacion: TOKEN_ASSIGN  */
#line 435 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_operador_asignacion("=", (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 2317 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 52: /* tipo: TOKEN_STRING  */
#line 443 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_tipo_node("string", (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 2325 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 53: /* tipo: TOKEN_INT  */
#line 447 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_tipo_node("int", (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 2333 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 54: /* tipo: TOKEN_FLOAT  */
#line 451 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_tipo_node("float", (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 2341 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 55: /* tipo: TOKEN_CHAR  */
#line 455 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_tipo_node("char", (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 2349 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 56: /* tipo: TOKEN_BOOLEAN  */
#line 459 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_tipo_node("boolean", (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 2357 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 57: /* dato: TOKEN_TYPE_STRING  */
#line 466 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_dato_string((yyvsp[0].str), (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 2365 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 58: /* dato: TOKEN_TYPE_INT  */
#line 470 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_dato_int((yyvsp[0].str), (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 2373 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 59: /* dato: TOKEN_TYPE_FLOAT  */
#line 474 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_dato_float((yyvsp[0].str), (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 2381 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 60: /* dato: TOKEN_TYPE_CHAR  */
#line 478 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_dato_char((yyvsp[0].str), (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 2389 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 61: /* dato: TOKEN_TYPE_TRUE  */
#line 482 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_dato_boolean((yyvsp[0].str), (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 2397 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 62: /* dato: TOKEN_TYPE_FALSE  */
#line 486 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_dato_boolean((yyvsp[0].str), (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 2405 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 63: /* lista_declaraciones: lista_declaracion  */
#line 493 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_lista_declaraciones_single((yyvsp[0].node), (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 2413 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 64: /* lista_declaraciones: lista_declaraciones TOKEN_COMMA lista_declaracion  */
#line 497 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_lista_declaraciones_add((yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2421 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 65: /* lista_declaracion: TOKEN_IDENTIFIER TOKEN_ASSIGN expresion  */
#line 504 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_lista_declaracion_node((yyvsp[-2].str), (yyvsp[0].node), (yylsp[-2]).first_line, (yylsp[-2]).first_column);
    }
#line 2429 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 66: /* sout: TOKEN_SOUT TOKEN_PAREN_LEFT expresion TOKEN_PAREN_RIGHT TOKEN_SEMICOLON  */
#line 511 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_sout_node((yyvsp[-2].node), (yylsp[-4]).first_line, (yylsp[-4]).first_column);
    }
#line 2437 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 67: /* sentencia_if: if_simple  */
#line 518 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2445 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 68: /* sentencia_if: if_con_else  */
#line 522 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2453 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 69: /* sentencia_if: if_con_else_if  */
#line 526 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2461 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 70: /* if_simple: TOKEN_IF TOKEN_PAREN_LEFT expresion TOKEN_PAREN_RIGHT TOKEN_BRACE_LEFT instrucciones TOKEN_BRACE_RIGHT  */
#line 533 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_if_simple((yyvsp[-4].node), (yyvsp[-1].node), (yylsp[-6]).first_line, (yylsp[-6]).first_column);
    }
#line 2469 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 71: /* if_con_else: TOKEN_IF TOKEN_PAREN_LEFT expresion TOKEN_PAREN_RIGHT TOKEN_BRACE_LEFT instrucciones TOKEN_BRACE_RIGHT TOKEN_ELSE TOKEN_BRACE_LEFT instrucciones TOKEN_BRACE_RIGHT  */
#line 540 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_if_con_else((yyvsp[-8].node), (yyvsp[-5].node), (yyvsp[-1].node), (yylsp[-10]).first_line, (yylsp[-10]).first_column);
    }
#line 2477 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 72: /* if_con_else_if: TOKEN_IF TOKEN_PAREN_LEFT expresion TOKEN_PAREN_RIGHT TOKEN_BRACE_LEFT instrucciones TOKEN_BRACE_RIGHT lista_else_if TOKEN_ELSE TOKEN_BRACE_LEFT instrucciones TOKEN_BRACE_RIGHT  */
#line 547 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_if_con_else_if((yyvsp[-9].node), (yyvsp[-6].node), (yyvsp[-4].node), (yyvsp[-1].node), (yylsp[-11]).first_line, (yylsp[-11]).first_column);
    }
#line 2485 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 73: /* lista_else_if: lista_else_if else_if  */
#line 554 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_lista_else_if_add((yyvsp[-1].node), (yyvsp[0].node));
    }
#line 2493 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 74: /* lista_else_if: else_if  */
#line 558 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_lista_else_if_single((yyvsp[0].node), (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 2501 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 75: /* else_if: TOKEN_ELSE TOKEN_IF TOKEN_PAREN_LEFT expresion TOKEN_PAREN_RIGHT TOKEN_BRACE_LEFT instrucciones TOKEN_BRACE_RIGHT  */
#line 565 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_else_if((yyvsp[-4].node), (yyvsp[-1].node), (yylsp[-7]).first_line, (yylsp[-7]).first_column);
    }
#line 2509 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 76: /* sentencias: TOKEN_BREAK TOKEN_SEMICOLON  */
#line 572 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_break((yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 2517 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 77: /* sentencias: TOKEN_CONTINUE TOKEN_SEMICOLON  */
#line 576 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_continue((yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 2525 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 78: /* sentencias: TOKEN_RETURN expresion TOKEN_SEMICOLON  */
#line 580 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_return_con_valor((yyvsp[-1].node), (yylsp[-2]).first_line, (yylsp[-2]).first_column);
    }
#line 2533 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 79: /* sentencias: TOKEN_RETURN TOKEN_SEMICOLON  */
#line 584 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_return_vacio((yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 2541 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 80: /* sentencia_switch: TOKEN_SWITCH TOKEN_PAREN_LEFT expresion TOKEN_PAREN_RIGHT TOKEN_BRACE_LEFT lista_case TOKEN_BRACE_RIGHT  */
#line 591 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_switch((yyvsp[-4].node), (yyvsp[-1].node), (yylsp[-6]).first_line, (yylsp[-6]).first_column);
    }
#line 2549 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 81: /* lista_case: lista_case case  */
#line 598 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_lista_casos_add((yyvsp[-1].node), (yyvsp[0].node));
    }
#line 2557 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 82: /* lista_case: case  */
#line 602 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_lista_casos_single((yyvsp[0].node), (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 2565 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 83: /* case: TOKEN_CASE dato TOKEN_COLON instrucciones sentencias  */
#line 609 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_caso((yyvsp[-3].node), (yyvsp[-1].node), (yyvsp[0].node), (yylsp[-4]).first_line, (yylsp[-4]).first_column);
    }
#line 2573 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 84: /* case: TOKEN_CASE dato TOKEN_COLON instrucciones sentencias TOKEN_DEFAULT TOKEN_COLON instrucciones  */
#line 613 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_caso_con_default((yyvsp[-6].node), (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[0].node), (yylsp[-7]).first_line, (yylsp[-7]).first_column);
    }
#line 2581 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 85: /* ciclo_while: TOKEN_WHILE TOKEN_PAREN_LEFT expresion TOKEN_PAREN_RIGHT TOKEN_BRACE_LEFT instrucciones TOKEN_BRACE_RIGHT  */
#line 620 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_while((yyvsp[-4].node), (yyvsp[-1].node), (yylsp[-6]).first_line, (yylsp[-6]).first_column);
    }
#line 2589 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 86: /* ciclo_do: TOKEN_DO TOKEN_BRACE_LEFT instrucciones TOKEN_BRACE_RIGHT TOKEN_WHILE TOKEN_PAREN_LEFT expresion TOKEN_PAREN_RIGHT TOKEN_SEMICOLON  */
#line 627 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_do_while((yyvsp[-6].node), (yyvsp[-2].node), (yylsp[-8]).first_line, (yylsp[-8]).first_column);
    }
#line 2597 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 87: /* ciclo_for: TOKEN_FOR TOKEN_PAREN_LEFT inicializacion_for TOKEN_SEMICOLON expresion TOKEN_SEMICOLON actualizar_for TOKEN_PAREN_RIGHT TOKEN_BRACE_LEFT instrucciones TOKEN_BRACE_RIGHT  */
#line 634 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_for((yyvsp[-8].node), (yyvsp[-6].node), (yyvsp[-4].node), (yyvsp[-1].node), (yylsp[-10]).first_line, (yylsp[-10]).first_column);  
    }
#line 2605 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 88: /* inicializacion_for: tipo TOKEN_IDENTIFIER TOKEN_ASSIGN expresion  */
#line 641 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_inicializacion_for_declaracion((yyvsp[-3].node), (yyvsp[-2].str), (yyvsp[0].node), (yylsp[-3]).first_line, (yylsp[-3]).first_column);
    }
#line 2613 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 89: /* inicializacion_for: TOKEN_IDENTIFIER operador_asignacion expresion  */
#line 645 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_inicializacion_for_asignacion((yyvsp[-2].str), (yyvsp[-1].node), (yyvsp[0].node), (yylsp[-2]).first_line, (yylsp[-2]).first_column);
    }
#line 2621 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 90: /* inicializacion_for: expresion  */
#line 649 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_inicializacion_for_expresion((yyvsp[0].node), (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 2629 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 91: /* inicializacion_for: %empty  */
#line 653 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_inicializacion_for_vacia(0, 0);
    }
#line 2637 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 92: /* actualizar_for: expresion  */
#line 660 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_actualizacion_for((yyvsp[0].node), (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 2645 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 93: /* actualizar_for: %empty  */
#line 664 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_actualizacion_for_vacia(0, 0);  // ← USAR 0, 0 en lugar de @1
    }
#line 2653 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;


#line 2657 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"

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

#line 670 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"


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
