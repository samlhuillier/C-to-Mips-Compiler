/* A Bison parser, made by GNU Bison 3.5.3.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_SRC_C_PARSER_TAB_HPP_INCLUDED
# define YY_YY_SRC_C_PARSER_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 1 "src/c_parser.y"

  #include "ast.hpp"

  #include <cassert>

  extern TreeNode* g_root; // A way of getting the AST out

  //! This is to fix problems when generating C++
  // We are declaring the functions provided by Flex, so
  // that Bison generated code can call them.
  extern FILE *yyin;
  int yylex(void);
  void yyerror(const char *);

#line 63 "src/c_parser.tab.hpp"

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    T_INT = 258,
    T_PP = 259,
    T_PE = 260,
    T_MM = 261,
    T_ME = 262,
    T_DE = 263,
    T_TE = 264,
    T_MODE = 265,
    T_AE = 266,
    T_OE = 267,
    T_RSE = 268,
    T_LSE = 269,
    T_XE = 270,
    T_ASSIGN = 271,
    T_BAND = 272,
    T_BOR = 273,
    T_NOT = 274,
    T_XOR = 275,
    T_LESS = 276,
    T_GREAT = 277,
    T_LAND = 278,
    T_LOR = 279,
    T_ARS = 280,
    T_ALS = 281,
    T_TWOLESS = 282,
    T_TWOGREAT = 283,
    T_LESSEQUAL = 284,
    T_GREATEQUAL = 285,
    T_TIMES = 286,
    T_DIVIDE = 287,
    T_PLUS = 288,
    T_MINUS = 289,
    T_MOD = 290,
    T_LBRACKET = 291,
    T_RBRACKET = 292,
    T_OPEN = 293,
    T_CLOSE = 294,
    T_COMMA = 295,
    T_LSQ = 296,
    T_RSQ = 297,
    T_COLON = 298,
    T_DOT = 299,
    T_NUMBER = 300,
    T_VARIABLE = 301,
    T_IF = 302,
    T_ELSE = 303,
    T_EOL = 304,
    T_RETURN = 305,
    T_WHILE = 306,
    T_FOR = 307,
    T_BREAK = 308,
    T_CONT = 309,
    T_SWITCH = 310,
    T_CASE = 311,
    T_DEFAULT = 312,
    T_VOID = 313,
    T_UNSIGNED = 314
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 18 "src/c_parser.y"

  TreeNode* node;
  std::string *string;

#line 139 "src/c_parser.tab.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_C_PARSER_TAB_HPP_INCLUDED  */
