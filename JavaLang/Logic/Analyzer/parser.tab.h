/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_HOME_LIGHTDEMON_ESCRITORIO_OLC2_PROYECTO1_202100215_JAVALANG_LOGIC_ANALYZER_PARSER_TAB_H_INCLUDED
# define YY_YY_HOME_LIGHTDEMON_ESCRITORIO_OLC2_PROYECTO1_202100215_JAVALANG_LOGIC_ANALYZER_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 43 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"

    typedef struct ASTNode ASTNode;

#line 53 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.h"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    TOKEN_INT = 258,               /* TOKEN_INT  */
    TOKEN_FLOAT = 259,             /* TOKEN_FLOAT  */
    TOKEN_STRING = 260,            /* TOKEN_STRING  */
    TOKEN_CHAR = 261,              /* TOKEN_CHAR  */
    TOKEN_BOOLEAN = 262,           /* TOKEN_BOOLEAN  */
    TOKEN_DOUBLE = 263,            /* TOKEN_DOUBLE  */
    TOKEN_LONG = 264,              /* TOKEN_LONG  */
    TOKEN_SHORT = 265,             /* TOKEN_SHORT  */
    TOKEN_BYTE = 266,              /* TOKEN_BYTE  */
    TOKEN_EQUALS = 267,            /* TOKEN_EQUALS  */
    TOKEN_NEW = 268,               /* TOKEN_NEW  */
    TOKEN_PUBLIC = 269,            /* TOKEN_PUBLIC  */
    TOKEN_STATIC = 270,            /* TOKEN_STATIC  */
    TOKEN_VOID = 271,              /* TOKEN_VOID  */
    TOKEN_MAIN = 272,              /* TOKEN_MAIN  */
    TOKEN_NULL = 273,              /* TOKEN_NULL  */
    TOKEN_IDENTIFIER = 274,        /* TOKEN_IDENTIFIER  */
    TOKEN_PLUS = 275,              /* TOKEN_PLUS  */
    TOKEN_MINUS = 276,             /* TOKEN_MINUS  */
    TOKEN_MULTIPLICATION = 277,    /* TOKEN_MULTIPLICATION  */
    TOKEN_DIVISION = 278,          /* TOKEN_DIVISION  */
    TOKEN_MODULE = 279,            /* TOKEN_MODULE  */
    TOKEN_PLUS_ASSIGN = 280,       /* TOKEN_PLUS_ASSIGN  */
    TOKEN_MINUS_ASSIGN = 281,      /* TOKEN_MINUS_ASSIGN  */
    TOKEN_MULT_ASSIGN = 282,       /* TOKEN_MULT_ASSIGN  */
    TOKEN_DIV_ASSIGN = 283,        /* TOKEN_DIV_ASSIGN  */
    TOKEN_MOD_ASSIGN = 284,        /* TOKEN_MOD_ASSIGN  */
    TOKEN_AND_ASSIGN = 285,        /* TOKEN_AND_ASSIGN  */
    TOKEN_OR_ASSIGN = 286,         /* TOKEN_OR_ASSIGN  */
    TOKEN_XOR_ASSIGN = 287,        /* TOKEN_XOR_ASSIGN  */
    TOKEN_SHIFT_LEFT_ASSIGN = 288, /* TOKEN_SHIFT_LEFT_ASSIGN  */
    TOKEN_SHIFT_RIGHT_ASSIGN = 289, /* TOKEN_SHIFT_RIGHT_ASSIGN  */
    TOKEN_ASSIGN = 290,            /* TOKEN_ASSIGN  */
    TOKEN_EQUAL = 291,             /* TOKEN_EQUAL  */
    TOKEN_UNEQUAL = 292,           /* TOKEN_UNEQUAL  */
    TOKEN_GREATER = 293,           /* TOKEN_GREATER  */
    TOKEN_LESS = 294,              /* TOKEN_LESS  */
    TOKEN_GREATER_EQUAL = 295,     /* TOKEN_GREATER_EQUAL  */
    TOKEN_LESS_EQUAL = 296,        /* TOKEN_LESS_EQUAL  */
    TOKEN_AND = 297,               /* TOKEN_AND  */
    TOKEN_OR = 298,                /* TOKEN_OR  */
    TOKEN_NOT = 299,               /* TOKEN_NOT  */
    TOKEN_PAREN_LEFT = 300,        /* TOKEN_PAREN_LEFT  */
    TOKEN_PAREN_RIGHT = 301,       /* TOKEN_PAREN_RIGHT  */
    TOKEN_SEMICOLON = 302,         /* TOKEN_SEMICOLON  */
    TOKEN_DOT = 303,               /* TOKEN_DOT  */
    TOKEN_COMMA = 304,             /* TOKEN_COMMA  */
    TOKEN_BRACE_LEFT = 305,        /* TOKEN_BRACE_LEFT  */
    TOKEN_BRACE_RIGHT = 306,       /* TOKEN_BRACE_RIGHT  */
    TOKEN_BRACKET_LEFT = 307,      /* TOKEN_BRACKET_LEFT  */
    TOKEN_BRACKET_RIGHT = 308,     /* TOKEN_BRACKET_RIGHT  */
    TOKEN_QUOTE_DOUBLE = 309,      /* TOKEN_QUOTE_DOUBLE  */
    TOKEN_QUOTE_SINGLE = 310,      /* TOKEN_QUOTE_SINGLE  */
    TOKEN_COLON = 311,             /* TOKEN_COLON  */
    TOKEN_IF = 312,                /* TOKEN_IF  */
    TOKEN_ELSE = 313,              /* TOKEN_ELSE  */
    TOKEN_SWITCH = 314,            /* TOKEN_SWITCH  */
    TOKEN_CASE = 315,              /* TOKEN_CASE  */
    TOKEN_DEFAULT = 316,           /* TOKEN_DEFAULT  */
    TOKEN_WHILE = 317,             /* TOKEN_WHILE  */
    TOKEN_DO = 318,                /* TOKEN_DO  */
    TOKEN_FOR = 319,               /* TOKEN_FOR  */
    TOKEN_BREAK = 320,             /* TOKEN_BREAK  */
    TOKEN_CONTINUE = 321,          /* TOKEN_CONTINUE  */
    TOKEN_RETURN = 322,            /* TOKEN_RETURN  */
    TOKEN_SOUT = 323,              /* TOKEN_SOUT  */
    TOKEN_PARSEINT = 324,          /* TOKEN_PARSEINT  */
    TOKEN_PARSEFLOAT = 325,        /* TOKEN_PARSEFLOAT  */
    TOKEN_PARSEDOUBLE = 326,       /* TOKEN_PARSEDOUBLE  */
    TOKEN_VALUEOF = 327,           /* TOKEN_VALUEOF  */
    TOKEN_STRINGJOIN = 328,        /* TOKEN_STRINGJOIN  */
    TOKEN_INDEXOF = 329,           /* TOKEN_INDEXOF  */
    TOKEN_LENGTH = 330,            /* TOKEN_LENGTH  */
    TOKEN_ADD = 331,               /* TOKEN_ADD  */
    TOKEN_ESCAPE = 332,            /* TOKEN_ESCAPE  */
    TOKEN_INCREMENT = 333,         /* TOKEN_INCREMENT  */
    TOKEN_DECREMENT = 334,         /* TOKEN_DECREMENT  */
    TOKEN_EOF = 335,               /* TOKEN_EOF  */
    TOKEN_ERROR = 336,             /* TOKEN_ERROR  */
    TOKEN_TYPE_INT = 337,          /* TOKEN_TYPE_INT  */
    TOKEN_TYPE_FLOAT = 338,        /* TOKEN_TYPE_FLOAT  */
    TOKEN_TYPE_STRING = 339,       /* TOKEN_TYPE_STRING  */
    TOKEN_TYPE_CHAR = 340,         /* TOKEN_TYPE_CHAR  */
    TOKEN_TYPE_TRUE = 341,         /* TOKEN_TYPE_TRUE  */
    TOKEN_TYPE_FALSE = 342         /* TOKEN_TYPE_FALSE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 47 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.y"

    ASTNode* node;
    char* str; 

#line 162 "/home/lightdemon/Escritorio/OLC2_Proyecto1_202100215/JavaLang/Logic/Analyzer/parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;

int yyparse (void);


#endif /* !YY_YY_HOME_LIGHTDEMON_ESCRITORIO_OLC2_PROYECTO1_202100215_JAVALANG_LOGIC_ANALYZER_PARSER_TAB_H_INCLUDED  */
