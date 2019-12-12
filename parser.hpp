/* A Bison parser, made by GNU Bison 3.4.1.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2019 Free Software Foundation,
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

#ifndef YY_YY_PARSER_HPP_INCLUDED
# define YY_YY_PARSER_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TPROGR = 258,
    TTACT = 259,
    TCONST = 260,
    TENUM = 261,
    TINPUT = 262,
    TOUTPUT = 263,
    TPROC = 264,
    TLOCAL = 265,
    TFOR = 266,
    TALL = 267,
    TFROM = 268,
    TSTATE = 269,
    TSWITCH = 270,
    TCASE = 271,
    TBREAK = 272,
    TIF = 273,
    TELSE = 274,
    TSTART = 275,
    TSTOP = 276,
    TERROR = 277,
    TRESTART = 278,
    TLOOP = 279,
    TSET = 280,
    TNEXT = 281,
    TRESET = 282,
    TTIMEOUT = 283,
    TIN = 284,
    TIS = 285,
    TACTIVE = 286,
    TINACTIVE = 287,
    TBOOL = 288,
    TVOID = 289,
    TFLOAT = 290,
    TDOUBLE = 291,
    TSIGNED = 292,
    TUNSIGNED = 293,
    TSHORT = 294,
    TLONG = 295,
    TINT = 296,
    TIDENTIFIER = 297,
    TFCONST = 298,
    TICONST = 299,
    TLPAREN = 300,
    TRPAREN = 301,
    TLBRACKET = 302,
    TRBRACKET = 303,
    TSEMIC = 304,
    TLBRACE = 305,
    TRBRACE = 306,
    TCOLON = 307,
    TASSGN = 308,
    TCOMMA = 309,
    TPERIOD = 310,
    TAND = 311,
    TNOT = 312,
    TTILDE = 313,
    TMINUS = 314,
    TPLUS = 315,
    TMUL = 316,
    TDIV = 317,
    TPERC = 318,
    TLT = 319,
    TGT = 320,
    TXOR = 321,
    TOR = 322,
    TQMARK = 323,
    TEQ = 324,
    TNEQ = 325,
    TLE = 326,
    TGE = 327,
    TINC = 328,
    TDEC = 329,
    TRSHIFT = 330,
    TLSHIFT = 331,
    TLOR = 332,
    TLAND = 333,
    TR_ASSGN = 334,
    TL_ASSGN = 335,
    TPLUS_ASSGN = 336,
    TMINUS_ASSGN = 337,
    TSTAR_ASSGN = 338,
    TDIV_ASSGN = 339,
    TPERC_ASSGN = 340,
    TAND_ASSGN = 341,
    TXOR_ASSGN = 342,
    TOR_ASSGN = 343,
    XIF = 344,
    UMINUS = 345
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 20 "parser.y"

    std::string* string;
	int token;
	ASTNode* ast_node;
	ASTNodeList* node_list;

#line 155 "parser.hpp"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_HPP_INCLUDED  */
