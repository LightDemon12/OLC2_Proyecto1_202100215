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

#line 105 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"

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
  YYSYMBOL_ciclo_do = 109                  /* ciclo_do  */
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
#define YYLAST   781

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  84
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  80
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  170

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
       0,   192,   192,   200,   207,   211,   218,   222,   226,   230,
     234,   238,   242,   246,   254,   258,   262,   266,   270,   276,
     280,   286,   290,   294,   298,   304,   308,   314,   320,   326,
     331,   339,   343,   347,   354,   362,   366,   370,   374,   378,
     382,   386,   390,   394,   398,   402,   410,   414,   418,   422,
     426,   433,   437,   441,   445,   449,   453,   460,   464,   471,
     478,   485,   489,   493,   500,   507,   514,   521,   525,   532,
     539,   543,   547,   551,   558,   565,   569,   576,   580,   587,
     594
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
  "sentencia_switch", "lista_case", "case", "ciclo_while", "ciclo_do", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-62)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       2,    18,    35,   -62,    34,   -62,    64,     6,    37,    36,
     465,   -62,   -62,   -62,   -62,   -62,   239,   471,   471,    40,
      42,    44,    41,    45,   -62,   -62,   -62,   -62,   -62,   -62,
     150,   -62,   720,   -62,   -62,    74,   -62,   -62,   -62,   -62,
     -62,   -62,   -62,   -62,   -62,   -62,   -62,   -62,   -62,   -62,
     -62,   -62,   -62,   -62,   -62,   -62,   471,   -62,   -62,   595,
     471,   471,   471,   465,   471,   -62,   -62,   471,   471,   471,
     471,   471,   471,   471,   471,   471,   471,   471,   471,   471,
      -4,    -7,   -62,   -13,   -62,   606,   633,   644,   195,   671,
      31,    31,   -62,   -62,   -62,    -3,    -3,    82,    82,    82,
      82,   744,   144,   471,   -62,   -62,    75,   -62,    46,    48,
      50,    33,    60,   539,    76,   -62,   465,    52,   465,    65,
     -62,   -62,   471,   240,   -38,   -19,   -62,   285,   471,   720,
      57,    61,   -62,   -62,   -62,   682,   -45,    58,   -62,   465,
      73,   465,    77,   -35,   -62,    69,   -62,   330,   471,   465,
      78,    80,   143,    62,   -62,   709,   375,   -62,   -62,   -62,
     567,    83,    79,   -62,   -62,   465,   465,   465,   420,   -62
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     2,     0,     1,     0,     0,     0,     0,
       0,    47,    48,    46,    49,    50,    30,     0,     0,     0,
       0,     0,     0,     0,    52,    53,    51,    54,    55,    56,
       0,     4,     9,     7,     8,     0,    29,     6,    10,    61,
      62,    63,    11,    12,    13,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,     0,    30,    27,     0,
       0,     0,     0,     0,     0,     3,     5,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    57,     0,    28,     0,     0,     0,     0,     0,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,     0,    33,    32,     0,    34,     0,     0,
       0,     0,     0,    59,     0,    58,     0,     0,     0,     0,
      60,    31,     0,     0,     0,     0,    76,     0,     0,    59,
      64,     0,    74,    75,    79,     0,     0,     0,    68,     0,
       0,     0,     0,     0,    67,     0,    80,     0,     0,     0,
       0,     0,     0,    77,    65,     0,     0,    70,    71,    73,
       0,     0,     0,    66,    72,     0,     0,    78,     0,    69
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -62,   -62,   -62,   -61,   -30,    -8,   -62,   -62,   -62,   -62,
       5,   -62,    28,   -62,   -62,   -62,   -62,   -62,   -62,    -1,
     -62,   -62,   -62,    14,   -62,   -62
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     3,    30,    31,    32,    33,    34,    56,    35,
      36,    81,    82,    37,    38,    39,    40,    41,   137,   138,
     153,    42,   125,   126,    43,    44
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      66,   141,    88,    67,    68,    69,    70,    71,   142,    58,
      59,   149,     1,    67,    68,    69,    70,    71,   142,    72,
      73,    74,    75,    76,    77,    78,    79,   103,   132,     4,
     107,    74,    75,    76,    77,     5,   105,   124,   106,   104,
      24,    25,    26,    27,    28,    29,     6,     8,    83,    69,
      70,    71,    85,    86,    87,   123,    89,   127,    66,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    99,   100,
     101,   102,    11,    12,    13,    14,    15,     7,   145,     9,
     147,    60,    10,    61,    16,    62,    64,    63,   156,    80,
     114,   119,   116,    66,   117,   113,   118,    66,    67,    68,
      69,    70,    71,   120,   167,   168,   128,   122,   124,    17,
      18,   136,   143,   139,   129,    66,   146,    66,   148,   161,
     135,   157,    19,   158,    20,   166,    66,    21,    22,   131,
     150,   151,   152,    23,   115,   165,   144,    66,    66,   133,
     155,     0,     0,     0,   160,     0,     0,    24,    25,    26,
      27,    28,    29,    11,    12,    13,    14,    15,    57,     0,
      67,    68,    69,    70,    71,    16,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    72,    73,    74,    75,
      76,    77,    78,    17,    18,     0,   159,     0,     0,     0,
      17,    18,     0,     0,     0,     0,     0,    65,    11,    12,
      13,    14,    15,    19,     0,    20,     0,     0,    21,    22,
      16,     0,     0,     0,    23,     0,     0,     0,     0,     0,
       0,    24,    25,    26,    27,    28,    29,     0,    24,    25,
      26,    27,    28,    29,     0,    17,    18,     0,     0,     0,
       0,     0,   111,    11,    12,    13,    14,    15,    19,     0,
      20,     0,     0,    21,    22,    16,     0,     0,     0,    23,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,     0,     0,    24,    25,    26,    27,    28,    29,     0,
      17,    18,     0,     0,     0,     0,     0,   130,    11,    12,
      13,    14,    15,    19,     0,    20,     0,     0,    21,    22,
      16,     0,     0,     0,    23,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    24,    25,
      26,    27,    28,    29,     0,    17,    18,     0,     0,     0,
       0,     0,   134,    11,    12,    13,    14,    15,    19,     0,
      20,     0,     0,    21,    22,    16,     0,     0,     0,    23,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    24,    25,    26,    27,    28,    29,     0,
      17,    18,     0,     0,     0,     0,     0,   154,    11,    12,
      13,    14,    15,    19,     0,    20,     0,     0,    21,    22,
      16,     0,     0,     0,    23,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    24,    25,
      26,    27,    28,    29,     0,    17,    18,     0,     0,     0,
       0,     0,   163,    11,    12,    13,    14,    15,    19,     0,
      20,     0,     0,    21,    22,    16,     0,     0,     0,    23,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    24,    25,    26,    27,    28,    29,     0,
      17,    18,     0,     0,     0,     0,     0,   169,    11,    12,
      13,    14,    15,    19,     0,    20,     0,     0,    21,    22,
      16,     0,     0,     0,    23,     0,    57,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    24,    25,
      26,    27,    28,    29,     0,    17,    18,     0,     0,     0,
       0,    17,    18,     0,     0,     0,     0,     0,    19,     0,
      20,     0,     0,    21,    22,     0,     0,     0,     0,    23,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    24,    25,    26,    27,    28,    29,    24,
      25,    26,    27,    28,    29,    67,    68,    69,    70,    71,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    72,    73,    74,    75,    76,    77,    78,    79,     0,
       0,     0,   121,    67,    68,    69,    70,    71,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    72,
      73,    74,    75,    76,    77,    78,    79,     0,     0,     0,
     164,    67,    68,    69,    70,    71,     0,     0,     0,     0,
       0,     0,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,     0,     0,    84,    72,    73,
      74,    75,    76,    77,    78,    79,     0,     0,   108,    67,
      68,    69,    70,    71,     0,     0,     0,     0,     0,     0,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,     0,     0,   109,    72,    73,    74,    75,
      76,    77,    78,    79,     0,     0,   110,    67,    68,    69,
      70,    71,     0,     0,     0,     0,     0,     0,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,     0,     0,   112,    72,    73,    74,    75,    76,    77,
      78,    79,     0,     0,   140,    67,    68,    69,    70,    71,
       0,     0,     0,     0,     0,     0,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,     0,
       0,   162,    72,    73,    74,    75,    76,    77,    78,    79,
      67,    68,    69,    70,    71,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    72,    73,    74,    75,
      76,    77
};

static const yytype_int16 yycheck[] =
{
      30,    46,    63,    16,    17,    18,    19,    20,    53,    17,
      18,    46,    10,    16,    17,    18,    19,    20,    53,    32,
      33,    34,    35,    36,    37,    38,    39,    31,    47,    11,
      43,    34,    35,    36,    37,     0,    43,    56,    45,    43,
      78,    79,    80,    81,    82,    83,    12,    41,    56,    18,
      19,    20,    60,    61,    62,   116,    64,   118,    88,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,     3,     4,     5,     6,     7,    13,   139,    42,
     141,    41,    46,    41,    15,    41,    41,    46,   149,    15,
      15,    58,    46,   123,    46,   103,    46,   127,    16,    17,
      18,    19,    20,    43,   165,   166,    41,    31,    56,    40,
      41,    54,    54,    52,   122,   145,    43,   147,    41,    57,
     128,    43,    53,    43,    55,    46,   156,    58,    59,   124,
      61,    62,    63,    64,   106,    52,   137,   167,   168,   125,
     148,    -1,    -1,    -1,   152,    -1,    -1,    78,    79,    80,
      81,    82,    83,     3,     4,     5,     6,     7,    15,    -1,
      16,    17,    18,    19,    20,    15,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    32,    33,    34,    35,
      36,    37,    38,    40,    41,    -1,    43,    -1,    -1,    -1,
      40,    41,    -1,    -1,    -1,    -1,    -1,    47,     3,     4,
       5,     6,     7,    53,    -1,    55,    -1,    -1,    58,    59,
      15,    -1,    -1,    -1,    64,    -1,    -1,    -1,    -1,    -1,
      -1,    78,    79,    80,    81,    82,    83,    -1,    78,    79,
      80,    81,    82,    83,    -1,    40,    41,    -1,    -1,    -1,
      -1,    -1,    47,     3,     4,     5,     6,     7,    53,    -1,
      55,    -1,    -1,    58,    59,    15,    -1,    -1,    -1,    64,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    -1,    -1,    78,    79,    80,    81,    82,    83,    -1,
      40,    41,    -1,    -1,    -1,    -1,    -1,    47,     3,     4,
       5,     6,     7,    53,    -1,    55,    -1,    -1,    58,    59,
      15,    -1,    -1,    -1,    64,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,    79,
      80,    81,    82,    83,    -1,    40,    41,    -1,    -1,    -1,
      -1,    -1,    47,     3,     4,     5,     6,     7,    53,    -1,
      55,    -1,    -1,    58,    59,    15,    -1,    -1,    -1,    64,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    78,    79,    80,    81,    82,    83,    -1,
      40,    41,    -1,    -1,    -1,    -1,    -1,    47,     3,     4,
       5,     6,     7,    53,    -1,    55,    -1,    -1,    58,    59,
      15,    -1,    -1,    -1,    64,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,    79,
      80,    81,    82,    83,    -1,    40,    41,    -1,    -1,    -1,
      -1,    -1,    47,     3,     4,     5,     6,     7,    53,    -1,
      55,    -1,    -1,    58,    59,    15,    -1,    -1,    -1,    64,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    78,    79,    80,    81,    82,    83,    -1,
      40,    41,    -1,    -1,    -1,    -1,    -1,    47,     3,     4,
       5,     6,     7,    53,    -1,    55,    -1,    -1,    58,    59,
      15,    -1,    -1,    -1,    64,    -1,    15,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    78,    79,
      80,    81,    82,    83,    -1,    40,    41,    -1,    -1,    -1,
      -1,    40,    41,    -1,    -1,    -1,    -1,    -1,    53,    -1,
      55,    -1,    -1,    58,    59,    -1,    -1,    -1,    -1,    64,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    78,    79,    80,    81,    82,    83,    78,
      79,    80,    81,    82,    83,    16,    17,    18,    19,    20,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    32,    33,    34,    35,    36,    37,    38,    39,    -1,
      -1,    -1,    43,    16,    17,    18,    19,    20,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,
      33,    34,    35,    36,    37,    38,    39,    -1,    -1,    -1,
      43,    16,    17,    18,    19,    20,    -1,    -1,    -1,    -1,
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
      38,    39,    -1,    -1,    42,    16,    17,    18,    19,    20,
      -1,    -1,    -1,    -1,    -1,    -1,    16,    17,    18,    19,
      20,    32,    33,    34,    35,    36,    37,    38,    39,    -1,
      -1,    42,    32,    33,    34,    35,    36,    37,    38,    39,
      16,    17,    18,    19,    20,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    32,    33,    34,    35,
      36,    37
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    10,    85,    86,    11,     0,    12,    13,    41,    42,
      46,     3,     4,     5,     6,     7,    15,    40,    41,    53,
      55,    58,    59,    64,    78,    79,    80,    81,    82,    83,
      87,    88,    89,    90,    91,    93,    94,    97,    98,    99,
     100,   101,   105,   108,   109,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    92,    15,    89,    89,
      41,    41,    41,    46,    41,    47,    88,    16,    17,    18,
      19,    20,    32,    33,    34,    35,    36,    37,    38,    39,
      15,    95,    96,    89,    42,    89,    89,    89,    87,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    31,    43,    43,    45,    43,    42,    42,
      42,    47,    42,    89,    15,    96,    46,    46,    46,    58,
      43,    43,    31,    87,    56,   106,   107,    87,    41,    89,
      47,    94,    47,   107,    47,    89,    54,   102,   103,    52,
      42,    46,    53,    54,   103,    87,    43,    87,    41,    46,
      61,    62,    63,   104,    47,    89,    87,    43,    43,    43,
      89,    57,    42,    47,    43,    52,    46,    87,    87,    47
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    84,    85,    86,    87,    87,    88,    88,    88,    88,
      88,    88,    88,    88,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    89,    89,    89,
      89,    90,    90,    90,    91,    92,    92,    92,    92,    92,
      92,    92,    92,    92,    92,    92,    93,    93,    93,    93,
      93,    94,    94,    94,    94,    94,    94,    95,    95,    96,
      97,    98,    98,    98,    99,   100,   101,   102,   102,   103,
     104,   104,   104,   104,   105,   106,   106,   107,   107,   108,
     109
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     9,     1,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     3,     1,
       1,     5,     3,     3,     4,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     3,
       5,     1,     1,     1,     7,    11,    12,     2,     1,     8,
       2,     2,     3,     2,     7,     2,     1,     5,     8,     7,
       9
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
#line 193 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        ast_root = build_program_node((yyvsp[0].node), (yylsp[0]).first_line, (yylsp[0]).first_column);
        (yyval.node) = ast_root;
    }
#line 1843 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 3: /* bloque_main: TOKEN_PUBLIC TOKEN_STATIC TOKEN_VOID TOKEN_MAIN TOKEN_PAREN_LEFT TOKEN_PAREN_RIGHT TOKEN_BRACE_LEFT instrucciones TOKEN_BRACE_RIGHT  */
#line 201 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_bloque_main_node((yyvsp[-1].node), (yylsp[-8]).first_line, (yylsp[-8]).first_column);
    }
#line 1851 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 4: /* instrucciones: instruccion  */
#line 208 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_instrucciones_single((yyvsp[0].node), (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 1859 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 5: /* instrucciones: instrucciones instruccion  */
#line 212 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_instrucciones_add((yyvsp[-1].node), (yyvsp[0].node));
    }
#line 1867 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 6: /* instruccion: sout  */
#line 219 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1875 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 7: /* instruccion: declaraciones  */
#line 223 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1883 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 8: /* instruccion: asignacion_compuesta  */
#line 227 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1891 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 9: /* instruccion: expresion  */
#line 231 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1899 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 10: /* instruccion: sentencia_if  */
#line 235 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1907 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 11: /* instruccion: sentencia_switch  */
#line 239 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1915 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 12: /* instruccion: ciclo_while  */
#line 243 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1923 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 13: /* instruccion: ciclo_do  */
#line 247 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 1931 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 14: /* expresion: expresion TOKEN_PLUS expresion  */
#line 255 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_expresion_binaria((yyvsp[-2].node), "+", (yyvsp[0].node), (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 1939 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 15: /* expresion: expresion TOKEN_MINUS expresion  */
#line 259 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_expresion_binaria((yyvsp[-2].node), "-", (yyvsp[0].node), (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 1947 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 16: /* expresion: expresion TOKEN_MULTIPLICATION expresion  */
#line 263 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_expresion_binaria((yyvsp[-2].node), "*", (yyvsp[0].node), (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 1955 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 17: /* expresion: expresion TOKEN_DIVISION expresion  */
#line 267 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_expresion_binaria((yyvsp[-2].node), "/", (yyvsp[0].node), (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 1963 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 18: /* expresion: expresion TOKEN_MODULE expresion  */
#line 271 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_expresion_binaria((yyvsp[-2].node), "%", (yyvsp[0].node), (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 1971 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 19: /* expresion: expresion TOKEN_EQUAL expresion  */
#line 277 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_expresion_binaria((yyvsp[-2].node), "==", (yyvsp[0].node), (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 1979 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 20: /* expresion: expresion TOKEN_UNEQUAL expresion  */
#line 281 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_expresion_binaria((yyvsp[-2].node), "!=", (yyvsp[0].node), (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 1987 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 21: /* expresion: expresion TOKEN_GREATER expresion  */
#line 287 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_expresion_binaria((yyvsp[-2].node), ">", (yyvsp[0].node), (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 1995 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 22: /* expresion: expresion TOKEN_LESS expresion  */
#line 291 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_expresion_binaria((yyvsp[-2].node), "<", (yyvsp[0].node), (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 2003 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 23: /* expresion: expresion TOKEN_GREATER_EQUAL expresion  */
#line 295 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_expresion_binaria((yyvsp[-2].node), ">=", (yyvsp[0].node), (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 2011 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 24: /* expresion: expresion TOKEN_LESS_EQUAL expresion  */
#line 299 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_expresion_binaria((yyvsp[-2].node), "<=", (yyvsp[0].node), (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 2019 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 25: /* expresion: expresion TOKEN_AND expresion  */
#line 305 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_expresion_binaria((yyvsp[-2].node), "&&", (yyvsp[0].node), (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 2027 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 26: /* expresion: expresion TOKEN_OR expresion  */
#line 309 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_expresion_binaria((yyvsp[-2].node), "||", (yyvsp[0].node), (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 2035 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 27: /* expresion: TOKEN_NOT expresion  */
#line 315 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_expresion_unaria("!", (yyvsp[0].node), (yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 2043 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 28: /* expresion: TOKEN_PAREN_LEFT expresion TOKEN_PAREN_RIGHT  */
#line 321 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_expresion_parentesis((yyvsp[-1].node), (yylsp[-2]).first_line, (yylsp[-2]).first_column);
    }
#line 2051 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 29: /* expresion: dato  */
#line 327 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2059 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 30: /* expresion: TOKEN_IDENTIFIER  */
#line 332 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_identifier_node((yyvsp[0].str), (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 2067 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 31: /* declaraciones: tipo TOKEN_IDENTIFIER TOKEN_ASSIGN expresion TOKEN_SEMICOLON  */
#line 340 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_declaracion_single((yyvsp[-4].node), (yyvsp[-3].str), (yyvsp[-1].node), (yylsp[-4]).first_line, (yylsp[-4]).first_column);
    }
#line 2075 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 32: /* declaraciones: tipo lista_declaraciones TOKEN_SEMICOLON  */
#line 344 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_declaracion_multiple((yyvsp[-2].node), (yyvsp[-1].node), (yylsp[-2]).first_line, (yylsp[-2]).first_column);
    }
#line 2083 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 33: /* declaraciones: tipo TOKEN_IDENTIFIER TOKEN_SEMICOLON  */
#line 348 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_declaracion_sin_inicializacion((yyvsp[-2].node), (yyvsp[-1].str), (yylsp[-2]).first_line, (yylsp[-2]).first_column);
    }
#line 2091 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 34: /* asignacion_compuesta: TOKEN_IDENTIFIER operador_asignacion expresion TOKEN_SEMICOLON  */
#line 355 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_asignacion_compuesta((yyvsp[-3].str), (yyvsp[-2].node), (yyvsp[-1].node), (yylsp[-3]).first_line, (yylsp[-3]).first_column);
    }
#line 2099 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 35: /* operador_asignacion: TOKEN_PLUS_ASSIGN  */
#line 363 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_operador_asignacion("+=", (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 2107 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 36: /* operador_asignacion: TOKEN_MINUS_ASSIGN  */
#line 367 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_operador_asignacion("-=", (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 2115 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 37: /* operador_asignacion: TOKEN_MULT_ASSIGN  */
#line 371 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_operador_asignacion("*=", (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 2123 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 38: /* operador_asignacion: TOKEN_DIV_ASSIGN  */
#line 375 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_operador_asignacion("/=", (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 2131 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 39: /* operador_asignacion: TOKEN_MOD_ASSIGN  */
#line 379 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_operador_asignacion("%=", (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 2139 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 40: /* operador_asignacion: TOKEN_AND_ASSIGN  */
#line 383 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_operador_asignacion("&=", (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 2147 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 41: /* operador_asignacion: TOKEN_OR_ASSIGN  */
#line 387 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_operador_asignacion("|=", (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 2155 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 42: /* operador_asignacion: TOKEN_XOR_ASSIGN  */
#line 391 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_operador_asignacion("^=", (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 2163 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 43: /* operador_asignacion: TOKEN_SHIFT_LEFT_ASSIGN  */
#line 395 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_operador_asignacion("<<=", (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 2171 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 44: /* operador_asignacion: TOKEN_SHIFT_RIGHT_ASSIGN  */
#line 399 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_operador_asignacion(">>=", (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 2179 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 45: /* operador_asignacion: TOKEN_ASSIGN  */
#line 403 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_operador_asignacion("=", (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 2187 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 46: /* tipo: TOKEN_STRING  */
#line 411 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_tipo_node("string", (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 2195 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 47: /* tipo: TOKEN_INT  */
#line 415 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_tipo_node("int", (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 2203 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 48: /* tipo: TOKEN_FLOAT  */
#line 419 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_tipo_node("float", (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 2211 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 49: /* tipo: TOKEN_CHAR  */
#line 423 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_tipo_node("char", (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 2219 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 50: /* tipo: TOKEN_BOOLEAN  */
#line 427 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_tipo_node("boolean", (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 2227 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 51: /* dato: TOKEN_TYPE_STRING  */
#line 434 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_dato_string((yyvsp[0].str), (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 2235 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 52: /* dato: TOKEN_TYPE_INT  */
#line 438 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_dato_int((yyvsp[0].str), (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 2243 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 53: /* dato: TOKEN_TYPE_FLOAT  */
#line 442 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_dato_float((yyvsp[0].str), (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 2251 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 54: /* dato: TOKEN_TYPE_CHAR  */
#line 446 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_dato_char((yyvsp[0].str), (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 2259 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 55: /* dato: TOKEN_TYPE_TRUE  */
#line 450 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_dato_boolean((yyvsp[0].str), (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 2267 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 56: /* dato: TOKEN_TYPE_FALSE  */
#line 454 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_dato_boolean((yyvsp[0].str), (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 2275 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 57: /* lista_declaraciones: lista_declaracion  */
#line 461 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_lista_declaraciones_single((yyvsp[0].node), (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 2283 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 58: /* lista_declaraciones: lista_declaraciones TOKEN_COMMA lista_declaracion  */
#line 465 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_lista_declaraciones_add((yyvsp[-2].node), (yyvsp[0].node));
    }
#line 2291 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 59: /* lista_declaracion: TOKEN_IDENTIFIER TOKEN_ASSIGN expresion  */
#line 472 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_lista_declaracion_node((yyvsp[-2].str), (yyvsp[0].node), (yylsp[-2]).first_line, (yylsp[-2]).first_column);
    }
#line 2299 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 60: /* sout: TOKEN_SOUT TOKEN_PAREN_LEFT expresion TOKEN_PAREN_RIGHT TOKEN_SEMICOLON  */
#line 479 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_sout_node((yyvsp[-2].node), (yylsp[-4]).first_line, (yylsp[-4]).first_column);
    }
#line 2307 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 61: /* sentencia_if: if_simple  */
#line 486 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2315 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 62: /* sentencia_if: if_con_else  */
#line 490 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2323 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 63: /* sentencia_if: if_con_else_if  */
#line 494 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = (yyvsp[0].node);
    }
#line 2331 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 64: /* if_simple: TOKEN_IF TOKEN_PAREN_LEFT expresion TOKEN_PAREN_RIGHT TOKEN_BRACE_LEFT instrucciones TOKEN_BRACE_RIGHT  */
#line 501 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_if_simple((yyvsp[-4].node), (yyvsp[-1].node), (yylsp[-6]).first_line, (yylsp[-6]).first_column);
    }
#line 2339 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 65: /* if_con_else: TOKEN_IF TOKEN_PAREN_LEFT expresion TOKEN_PAREN_RIGHT TOKEN_BRACE_LEFT instrucciones TOKEN_BRACE_RIGHT TOKEN_ELSE TOKEN_BRACE_LEFT instrucciones TOKEN_BRACE_RIGHT  */
#line 508 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_if_con_else((yyvsp[-8].node), (yyvsp[-5].node), (yyvsp[-1].node), (yylsp[-10]).first_line, (yylsp[-10]).first_column);
    }
#line 2347 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 66: /* if_con_else_if: TOKEN_IF TOKEN_PAREN_LEFT expresion TOKEN_PAREN_RIGHT TOKEN_BRACE_LEFT instrucciones TOKEN_BRACE_RIGHT lista_else_if TOKEN_ELSE TOKEN_BRACE_LEFT instrucciones TOKEN_BRACE_RIGHT  */
#line 515 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_if_con_else_if((yyvsp[-9].node), (yyvsp[-6].node), (yyvsp[-4].node), (yyvsp[-1].node), (yylsp[-11]).first_line, (yylsp[-11]).first_column);
    }
#line 2355 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 67: /* lista_else_if: lista_else_if else_if  */
#line 522 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_lista_else_if_add((yyvsp[-1].node), (yyvsp[0].node));
    }
#line 2363 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 68: /* lista_else_if: else_if  */
#line 526 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_lista_else_if_single((yyvsp[0].node), (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 2371 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 69: /* else_if: TOKEN_ELSE TOKEN_IF TOKEN_PAREN_LEFT expresion TOKEN_PAREN_RIGHT TOKEN_BRACE_LEFT instrucciones TOKEN_BRACE_RIGHT  */
#line 533 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_else_if((yyvsp[-4].node), (yyvsp[-1].node), (yylsp[-7]).first_line, (yylsp[-7]).first_column);
    }
#line 2379 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 70: /* sentencias: TOKEN_BREAK TOKEN_SEMICOLON  */
#line 540 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_break((yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 2387 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 71: /* sentencias: TOKEN_CONTINUE TOKEN_SEMICOLON  */
#line 544 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_continue((yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 2395 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 72: /* sentencias: TOKEN_RETURN expresion TOKEN_SEMICOLON  */
#line 548 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_return_con_valor((yyvsp[-1].node), (yylsp[-2]).first_line, (yylsp[-2]).first_column);
    }
#line 2403 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 73: /* sentencias: TOKEN_RETURN TOKEN_SEMICOLON  */
#line 552 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_return_vacio((yylsp[-1]).first_line, (yylsp[-1]).first_column);
    }
#line 2411 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 74: /* sentencia_switch: TOKEN_SWITCH TOKEN_PAREN_LEFT expresion TOKEN_PAREN_RIGHT TOKEN_BRACE_LEFT lista_case TOKEN_BRACE_RIGHT  */
#line 559 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_switch((yyvsp[-4].node), (yyvsp[-1].node), (yylsp[-6]).first_line, (yylsp[-6]).first_column);
    }
#line 2419 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 75: /* lista_case: lista_case case  */
#line 566 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_lista_casos_add((yyvsp[-1].node), (yyvsp[0].node));
    }
#line 2427 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 76: /* lista_case: case  */
#line 570 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_lista_casos_single((yyvsp[0].node), (yylsp[0]).first_line, (yylsp[0]).first_column);
    }
#line 2435 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 77: /* case: TOKEN_CASE dato TOKEN_COLON instrucciones sentencias  */
#line 577 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_caso((yyvsp[-3].node), (yyvsp[-1].node), (yyvsp[0].node), (yylsp[-4]).first_line, (yylsp[-4]).first_column);
    }
#line 2443 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 78: /* case: TOKEN_CASE dato TOKEN_COLON instrucciones sentencias TOKEN_DEFAULT TOKEN_COLON instrucciones  */
#line 581 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_caso_con_default((yyvsp[-6].node), (yyvsp[-4].node), (yyvsp[-3].node), (yyvsp[0].node), (yylsp[-7]).first_line, (yylsp[-7]).first_column);
    }
#line 2451 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 79: /* ciclo_while: TOKEN_WHILE TOKEN_PAREN_LEFT expresion TOKEN_PAREN_RIGHT TOKEN_BRACE_LEFT instrucciones TOKEN_BRACE_RIGHT  */
#line 588 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_while((yyvsp[-4].node), (yyvsp[-1].node), (yylsp[-6]).first_line, (yylsp[-6]).first_column);
    }
#line 2459 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;

  case 80: /* ciclo_do: TOKEN_DO TOKEN_BRACE_LEFT instrucciones TOKEN_BRACE_RIGHT TOKEN_WHILE TOKEN_PAREN_LEFT expresion TOKEN_PAREN_RIGHT TOKEN_SEMICOLON  */
#line 595 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"
    {
        (yyval.node) = build_do_while((yyvsp[-6].node), (yyvsp[-2].node), (yylsp[-8]).first_line, (yylsp[-8]).first_column);
    }
#line 2467 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"
    break;


#line 2471 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.c"

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

#line 599 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"


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
