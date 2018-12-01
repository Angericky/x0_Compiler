/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     MAIN = 258,
     ID = 259,
     NUM = 260,
     TRUE = 261,
     FALSE = 262,
     FLOATNUM = 263,
     CHARACTER = 264,
     STRING_LITERAL = 265,
     CONSTANT = 266,
     PROCEDURE = 267,
     PTR_OP = 268,
     INC_OP = 269,
     DEC_OP = 270,
     LEFT_OP = 271,
     RIGHT_OP = 272,
     LE_OP = 273,
     GE_OP = 274,
     EQ_OP = 275,
     NE_OP = 276,
     AND_OP = 277,
     OR_OP = 278,
     MUL_ASSIGN = 279,
     DIV_ASSIGN = 280,
     MOD_ASSIGN = 281,
     ADD_ASSIGN = 282,
     SUB_ASSIGN = 283,
     LEFT_ASSIGN = 284,
     RIGHT_ASSIGN = 285,
     AND_ASSIGN = 286,
     XOR_ASSIGN = 287,
     OR_ASSIGN = 288,
     TYPE_NAME = 289,
     ODD_EVAL = 290,
     SQRT = 291,
     READ = 292,
     WRITE = 293,
     TYPEDEF = 294,
     EXTERN = 295,
     STATIC = 296,
     AUTO = 297,
     REGISTER = 298,
     CHAR = 299,
     INT = 300,
     LONG = 301,
     UNSIGNED = 302,
     FLOAT = 303,
     DOUBLE = 304,
     CONST = 305,
     VOLATILE = 306,
     VOID = 307,
     BOOLEAN = 308,
     STRUCT = 309,
     UNION = 310,
     ENUM = 311,
     ELLIPSIS = 312,
     CASE = 313,
     DEFAULT = 314,
     IF = 315,
     ELSE = 316,
     SWITCH = 317,
     WHILE = 318,
     DO = 319,
     FOR = 320,
     GOTO = 321,
     CONTINUE = 322,
     BREAK = 323,
     RETURN = 324,
     EXIT = 325,
     REPEAT = 326,
     UNTIL = 327,
     CALL = 328
   };
#endif
/* Tokens.  */
#define MAIN 258
#define ID 259
#define NUM 260
#define TRUE 261
#define FALSE 262
#define FLOATNUM 263
#define CHARACTER 264
#define STRING_LITERAL 265
#define CONSTANT 266
#define PROCEDURE 267
#define PTR_OP 268
#define INC_OP 269
#define DEC_OP 270
#define LEFT_OP 271
#define RIGHT_OP 272
#define LE_OP 273
#define GE_OP 274
#define EQ_OP 275
#define NE_OP 276
#define AND_OP 277
#define OR_OP 278
#define MUL_ASSIGN 279
#define DIV_ASSIGN 280
#define MOD_ASSIGN 281
#define ADD_ASSIGN 282
#define SUB_ASSIGN 283
#define LEFT_ASSIGN 284
#define RIGHT_ASSIGN 285
#define AND_ASSIGN 286
#define XOR_ASSIGN 287
#define OR_ASSIGN 288
#define TYPE_NAME 289
#define ODD_EVAL 290
#define SQRT 291
#define READ 292
#define WRITE 293
#define TYPEDEF 294
#define EXTERN 295
#define STATIC 296
#define AUTO 297
#define REGISTER 298
#define CHAR 299
#define INT 300
#define LONG 301
#define UNSIGNED 302
#define FLOAT 303
#define DOUBLE 304
#define CONST 305
#define VOLATILE 306
#define VOID 307
#define BOOLEAN 308
#define STRUCT 309
#define UNION 310
#define ENUM 311
#define ELLIPSIS 312
#define CASE 313
#define DEFAULT 314
#define IF 315
#define ELSE 316
#define SWITCH 317
#define WHILE 318
#define DO 319
#define FOR 320
#define GOTO 321
#define CONTINUE 322
#define BREAK 323
#define RETURN 324
#define EXIT 325
#define REPEAT 326
#define UNTIL 327
#define CALL 328




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 18 "x0.y"
{
	char *ident;
	int number;
	float floatnum;
	char character;
	char vartype;
	char *op;
	struct cx_ins *cx_table;
}
/* Line 1529 of yacc.c.  */
#line 205 "x0.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

