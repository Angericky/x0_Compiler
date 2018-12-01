/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



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




/* Copy the first part of user declarations.  */
#line 1 "x0.y"

	#include "code.h"
	#include <sys/malloc.h>
	int isconst = 0;
	int isarray = 0;
	int arridx = 0;
	int islit = 0;
	int iscall = 0;
	int call_cx = 0;
	char tp;
	struct cx_ins
	{
		int adr;
		struct cx_ins* next;
	};


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

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
/* Line 193 of yacc.c.  */
#line 269 "x0.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 282 "x0.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

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
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   594

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  93
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  95
/* YYNRULES -- Number of rules.  */
#define YYNRULES  174
/* YYNRULES -- Number of states.  */
#define YYNSTATES  288

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   328

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    86,     2,     2,     2,    92,     2,     2,
      76,    77,    90,    88,    79,    89,     2,    91,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    83,    78,
      85,    80,    84,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    81,     2,    82,    87,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    74,     2,    75,     2,     2,     2,     2,
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
      65,    66,    67,    68,    69,    70,    71,    72,    73
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     8,     9,    10,    11,    12,    24,
      25,    26,    32,    33,    37,    38,    41,    43,    44,    47,
      48,    49,    50,    51,    59,    60,    61,    67,    69,    70,
      73,    77,    78,    79,    85,    87,    91,    92,    97,    98,
     105,   106,   110,   111,   115,   117,   119,   121,   123,   125,
     126,   130,   131,   137,   138,   139,   145,   149,   152,   153,
     156,   158,   159,   161,   163,   165,   167,   169,   171,   173,
     175,   177,   179,   181,   182,   190,   191,   195,   196,   201,
     203,   204,   206,   208,   210,   211,   212,   220,   221,   222,
     232,   237,   239,   240,   242,   244,   246,   247,   248,   258,
     259,   260,   261,   273,   277,   279,   281,   284,   286,   288,
     290,   292,   295,   296,   300,   301,   308,   312,   314,   317,
     320,   321,   322,   329,   331,   332,   334,   338,   339,   340,
     346,   350,   352,   356,   360,   363,   365,   366,   371,   373,
     375,   378,   381,   385,   389,   393,   397,   401,   405,   408,
     412,   416,   420,   424,   428,   430,   434,   438,   442,   444,
     449,   454,   459,   461,   465,   467,   468,   470,   474,   476,
     478,   480,   482,   484,   486
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
      94,     0,    -1,    -1,    95,     3,    96,    -1,    -1,    -1,
      -1,    -1,    97,   101,    98,    74,   105,    99,   106,   100,
     133,   104,    75,    -1,    -1,    -1,    76,   102,   111,   103,
      77,    -1,    -1,    69,   186,    78,    -1,    -1,   105,   115,
      -1,   115,    -1,    -1,   107,   106,    -1,    -1,    -1,    -1,
      -1,    12,     4,   108,   109,    96,   110,    78,    -1,    -1,
      -1,   114,   112,    79,   113,   111,    -1,   114,    -1,    -1,
     125,   122,    -1,   125,   118,    78,    -1,    -1,    -1,    50,
     116,   119,   117,    78,    -1,   122,    -1,   118,    79,   122,
      -1,    -1,     4,   120,    80,   178,    -1,    -1,   119,    79,
       4,   121,    80,   178,    -1,    -1,     4,   123,   132,    -1,
      -1,     4,   124,   130,    -1,    45,    -1,    44,    -1,    48,
      -1,    53,    -1,     4,    -1,    -1,     4,   127,   128,    -1,
      -1,    81,   178,   129,    82,   128,    -1,    -1,    -1,    81,
     178,    82,   131,   130,    -1,    81,   178,    82,    -1,    80,
     178,    -1,    -1,   133,   134,    -1,   134,    -1,    -1,   135,
      -1,   141,    -1,   144,    -1,   149,    -1,   152,    -1,   162,
      -1,   174,    -1,   171,    -1,   176,    -1,   177,    -1,   187,
      -1,    -1,    60,    76,   178,    77,   136,   139,   137,    -1,
      -1,    61,   138,   139,    -1,    -1,    74,   139,   140,    75,
      -1,   140,    -1,    -1,   159,    -1,   160,    -1,   134,    -1,
      -1,    -1,    63,   142,    76,   178,    77,   143,   147,    -1,
      -1,    -1,    64,   145,   147,    63,    76,   178,    77,   146,
      78,    -1,    74,   147,   148,    75,    -1,   148,    -1,    -1,
     134,    -1,   159,    -1,   160,    -1,    -1,    -1,    71,   150,
     147,    72,    76,   178,    77,   151,    78,    -1,    -1,    -1,
      -1,    65,    76,   177,   153,   180,    78,   154,   178,   155,
      77,   156,    -1,    74,   157,    75,    -1,   134,    -1,   159,
      -1,   157,   158,    -1,   158,    -1,   134,    -1,   159,    -1,
     160,    -1,    68,    78,    -1,    -1,    67,   161,    78,    -1,
      -1,    62,    76,   126,   163,    77,   164,    -1,    74,   164,
      75,    -1,   165,    -1,   165,   170,    -1,   165,   166,    -1,
      -1,    -1,    58,   169,    83,   167,   133,   168,    -1,   159,
      -1,    -1,     5,    -1,    59,    83,   134,    -1,    -1,    -1,
      38,   172,   178,   173,    78,    -1,    37,   175,    78,    -1,
     126,    -1,   175,    79,   126,    -1,    74,   133,    75,    -1,
     178,    78,    -1,    78,    -1,    -1,   126,   179,    80,   178,
      -1,   180,    -1,   181,    -1,   181,    14,    -1,   181,    15,
      -1,   181,    84,   181,    -1,   181,    85,   181,    -1,   181,
      18,   181,    -1,   181,    19,   181,    -1,   181,    20,   181,
      -1,   181,    21,   181,    -1,    86,   181,    -1,   181,    22,
     181,    -1,   181,    23,   181,    -1,   181,    87,   181,    -1,
     181,    88,   182,    -1,   181,    89,   182,    -1,   182,    -1,
     182,    90,   183,    -1,   182,    91,   183,    -1,   182,    92,
     183,    -1,   183,    -1,    35,    76,   186,    77,    -1,    36,
      76,   186,    77,    -1,     4,    76,   184,    77,    -1,   186,
      -1,   184,    79,   185,    -1,   185,    -1,    -1,   126,    -1,
      76,   178,    77,    -1,   126,    -1,     5,    -1,     9,    -1,
       8,    -1,     6,    -1,     7,    -1,    70,    78,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    55,    55,    55,    61,    76,    82,    93,    61,   126,
     126,   126,   128,   132,   134,   138,   139,   140,   144,   145,
     151,   158,   160,   149,   169,   169,   169,   171,   172,   177,
     188,   193,   195,   192,   200,   201,   206,   205,   214,   212,
     224,   223,   255,   254,   284,   285,   286,   287,   291,   305,
     305,   323,   322,   366,   371,   370,   403,   438,   443,   449,
     450,   451,   455,   456,   457,   458,   459,   460,   461,   462,
     464,   465,   466,   472,   471,   485,   484,   494,   498,   501,
     502,   506,   507,   508,   513,   515,   512,   538,   543,   537,
     560,   561,   562,   566,   567,   568,   573,   577,   572,   586,
     590,   596,   585,   619,   620,   621,   625,   626,   630,   631,
     632,   636,   646,   645,   655,   654,   664,   666,   680,   681,
     701,   706,   705,   718,   719,   723,   728,   733,   733,   733,
     759,   764,   788,   815,   819,   820,   825,   824,   843,   847,
     848,   857,   866,   868,   870,   872,   874,   876,   878,   880,
     882,   884,   890,   892,   894,   898,   900,   902,   904,   908,
     911,   915,   934,   939,   940,   941,   945,   955,   956,   991,
    1003,  1009,  1021,  1027,  1036
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "MAIN", "ID", "NUM", "TRUE", "FALSE",
  "FLOATNUM", "CHARACTER", "STRING_LITERAL", "CONSTANT", "PROCEDURE",
  "PTR_OP", "INC_OP", "DEC_OP", "LEFT_OP", "RIGHT_OP", "LE_OP", "GE_OP",
  "EQ_OP", "NE_OP", "AND_OP", "OR_OP", "MUL_ASSIGN", "DIV_ASSIGN",
  "MOD_ASSIGN", "ADD_ASSIGN", "SUB_ASSIGN", "LEFT_ASSIGN", "RIGHT_ASSIGN",
  "AND_ASSIGN", "XOR_ASSIGN", "OR_ASSIGN", "TYPE_NAME", "ODD_EVAL", "SQRT",
  "READ", "WRITE", "TYPEDEF", "EXTERN", "STATIC", "AUTO", "REGISTER",
  "CHAR", "INT", "LONG", "UNSIGNED", "FLOAT", "DOUBLE", "CONST",
  "VOLATILE", "VOID", "BOOLEAN", "STRUCT", "UNION", "ENUM", "ELLIPSIS",
  "CASE", "DEFAULT", "IF", "ELSE", "SWITCH", "WHILE", "DO", "FOR", "GOTO",
  "CONTINUE", "BREAK", "RETURN", "EXIT", "REPEAT", "UNTIL", "CALL", "'{'",
  "'}'", "'('", "')'", "';'", "','", "'='", "'['", "']'", "':'", "'>'",
  "'<'", "'!'", "'^'", "'+'", "'-'", "'*'", "'/'", "'%'", "$accept",
  "program", "@1", "block", "@2", "@3", "@4", "@5", "function_parentheses",
  "@6", "@7", "return_stat", "declaration_list", "proc_dec_list",
  "proc_dec_stat", "@8", "@9", "@10", "parameter_list", "@11", "@12",
  "parameter_stat", "declaration_stat", "@13", "@14",
  "declaration_id_list", "constdec_id_list", "@15", "@16",
  "declaration_id", "@17", "@18", "type", "var", "@19", "arraylist", "@20",
  "decarraylist", "@21", "definition_stat", "statement_list", "statement",
  "if_stat", "@22", "ELSE_stat", "@23", "if_statement_list",
  "if_statement", "while_stat", "@24", "@25", "do_while_stat", "@26",
  "@27", "do_statement_list", "do_statement", "repeat_until_stat", "@28",
  "@29", "for_stat", "@30", "@31", "@32", "for_operation",
  "for_opstatlist", "for_opstat", "break_stat", "continue_stat", "@33",
  "switch_case_stat", "@34", "case_list", "case_stat_list", "case_stat",
  "@35", "case_break_stat", "case_num", "default_stat", "write_stat",
  "@36", "@37", "read_stat", "readVar", "compound_stat", "expression_stat",
  "expression", "@38", "simple_expr", "additive_expr", "term", "function",
  "call_value_list", "call_value_stat", "factor", "exit_stat", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   123,   125,    40,    41,    59,    44,
      61,    91,    93,    58,    62,    60,    33,    94,    43,    45,
      42,    47,    37
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    93,    95,    94,    97,    98,    99,   100,    96,   102,
     103,   101,   101,   104,   104,   105,   105,   105,   106,   106,
     108,   109,   110,   107,   112,   113,   111,   111,   111,   114,
     115,   116,   117,   115,   118,   118,   120,   119,   121,   119,
     123,   122,   124,   122,   125,   125,   125,   125,   126,   127,
     126,   129,   128,   128,   131,   130,   130,   132,   132,   133,
     133,   133,   134,   134,   134,   134,   134,   134,   134,   134,
     134,   134,   134,   136,   135,   138,   137,   137,   139,   139,
     139,   140,   140,   140,   142,   143,   141,   145,   146,   144,
     147,   147,   147,   148,   148,   148,   150,   151,   149,   153,
     154,   155,   152,   156,   156,   156,   157,   157,   158,   158,
     158,   159,   161,   160,   163,   162,   164,   164,   165,   165,
     165,   167,   166,   168,   168,   169,   170,   172,   173,   171,
     174,   175,   175,   176,   177,   177,   179,   178,   178,   180,
     180,   180,   180,   180,   180,   180,   180,   180,   180,   180,
     180,   180,   181,   181,   181,   182,   182,   182,   182,   183,
     183,   183,   183,   184,   184,   184,   185,   186,   186,   186,
     186,   186,   186,   186,   187
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     3,     0,     0,     0,     0,    11,     0,
       0,     5,     0,     3,     0,     2,     1,     0,     2,     0,
       0,     0,     0,     7,     0,     0,     5,     1,     0,     2,
       3,     0,     0,     5,     1,     3,     0,     4,     0,     6,
       0,     3,     0,     3,     1,     1,     1,     1,     1,     0,
       3,     0,     5,     0,     0,     5,     3,     2,     0,     2,
       1,     0,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     7,     0,     3,     0,     4,     1,
       0,     1,     1,     1,     0,     0,     7,     0,     0,     9,
       4,     1,     0,     1,     1,     1,     0,     0,     9,     0,
       0,     0,    11,     3,     1,     1,     2,     1,     1,     1,
       1,     2,     0,     3,     0,     6,     3,     1,     2,     2,
       0,     0,     6,     1,     0,     1,     3,     0,     0,     5,
       3,     1,     3,     3,     2,     1,     0,     4,     1,     1,
       2,     2,     3,     3,     3,     3,     3,     3,     2,     3,
       3,     3,     3,     3,     1,     3,     3,     3,     1,     4,
       4,     4,     1,     3,     1,     0,     1,     3,     1,     1,
       1,     1,     1,     1,     2
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     0,     0,     1,     4,     3,    12,     9,     5,    28,
       0,    45,    44,    46,    47,    10,    24,     0,    17,     0,
       0,    40,    29,    31,     6,    16,     0,    11,    25,    58,
       0,     0,    19,    15,     0,    34,    28,     0,    41,     0,
      43,    36,    32,     0,     7,    19,    30,     0,    26,    48,
     169,   172,   173,   171,   170,     0,     0,     0,     0,   168,
      57,   138,   139,   154,   158,   162,     0,     0,     0,     0,
      20,    61,    18,    35,   165,    53,     0,     0,     0,   168,
     148,     0,   140,   141,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    56,     0,
      38,    33,    21,     0,   127,     0,     0,    84,    87,     0,
       0,    96,    61,   135,    14,    60,    62,    63,    64,    65,
      66,    67,    69,    68,    70,    71,     0,    72,    48,   166,
       0,   164,     0,    50,     0,     0,   167,     0,   144,   145,
     146,   147,   149,   150,   142,   143,   151,   152,   153,   155,
     156,   157,     0,    37,     0,     4,   131,     0,     0,     0,
       0,     0,     0,     0,   174,    92,     0,     0,     0,    59,
     134,   161,     0,    51,   159,   160,   137,    55,     0,    22,
     130,     0,   128,     0,   114,     0,   112,     0,    61,    93,
       0,    91,    94,    95,    99,     0,   133,     0,     8,   163,
       0,    39,     0,   132,     0,    73,     0,     0,     0,   111,
      60,     0,     0,     0,     0,    13,    53,    23,   129,    80,
     120,    85,   113,     0,     0,     0,     0,    52,    61,    83,
      77,    79,    81,    82,   120,   115,   117,    92,    90,     0,
     100,     0,    60,     0,    75,    74,     0,     0,     0,   119,
     118,    86,    88,     0,    97,     0,    80,   116,   125,     0,
       0,     0,   101,     0,    78,    76,   121,   126,    89,     0,
      98,    61,     0,   124,    61,   104,   102,   105,   123,   122,
      60,     0,   107,   109,   110,   103,   108,   106
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,     5,     6,    10,    32,    71,     8,     9,
      19,   168,    24,    44,    45,   102,   155,   202,    15,    20,
      36,    16,    25,    31,    69,    34,    42,    67,   154,    22,
      29,    30,    17,    59,    75,   133,   200,    40,   152,    38,
     166,   189,   116,   219,   245,   256,   230,   231,   117,   161,
     237,   118,   162,   261,   190,   191,   119,   165,   263,   120,
     213,   253,   269,   276,   281,   282,   192,   193,   208,   121,
     206,   235,   236,   249,   271,   279,   259,   250,   122,   158,
     204,   123,   157,   124,   125,   126,    81,    61,    62,    63,
      64,   130,   131,    65,   127
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -218
static const yytype_int16 yypact[] =
{
    -218,    12,    26,  -218,  -218,  -218,   -45,  -218,  -218,    89,
     -31,  -218,  -218,  -218,  -218,  -218,   -30,    83,    63,    24,
      36,     8,  -218,  -218,    63,  -218,    83,  -218,  -218,    23,
      42,   101,   105,  -218,    -4,  -218,    89,   121,  -218,   121,
    -218,  -218,    53,   147,  -218,   105,  -218,    83,  -218,   -55,
    -218,  -218,  -218,  -218,  -218,    91,    92,   121,    10,    75,
    -218,  -218,   160,   -82,  -218,  -218,    77,    90,   165,    93,
    -218,   508,  -218,  -218,   168,    95,    64,    64,   108,  -218,
     -12,   111,  -218,  -218,    10,    10,    10,    10,    10,    10,
      10,    10,    10,    10,    10,    10,    10,    10,   107,   121,
    -218,  -218,  -218,   168,  -218,   120,   122,  -218,  -218,   123,
     128,  -218,   508,  -218,    28,  -218,  -218,  -218,  -218,  -218,
    -218,  -218,  -218,  -218,  -218,  -218,   130,  -218,   119,  -218,
     -49,  -218,   121,  -218,   132,   133,  -218,   121,   -12,   -12,
     -12,   -12,   -12,   -12,   -12,   -12,   -12,   -82,   -82,  -218,
    -218,  -218,    42,  -218,   134,  -218,  -218,     6,   121,   121,
     168,   136,   232,    74,  -218,   232,   341,    64,   138,  -218,
    -218,  -218,   168,  -218,  -218,  -218,  -218,  -218,   121,  -218,
    -218,   168,  -218,   141,  -218,   121,  -218,   137,   232,  -218,
     163,  -218,  -218,  -218,  -218,   151,  -218,   152,  -218,  -218,
     169,  -218,   156,  -218,   164,  -218,   173,   175,   181,  -218,
      52,   249,   153,   121,   184,  -218,    95,  -218,  -218,   324,
     187,  -218,  -218,   189,   121,   185,   121,  -218,   324,  -218,
     201,  -218,  -218,  -218,   187,  -218,    80,   232,  -218,   194,
    -218,   204,    76,   249,  -218,  -218,   190,   261,   199,  -218,
    -218,  -218,  -218,   121,  -218,   208,   324,  -218,  -218,   205,
     508,   211,  -218,   212,  -218,  -218,  -218,  -218,  -218,   214,
    -218,   508,   416,   433,   249,  -218,  -218,  -218,  -218,  -218,
      79,   157,  -218,  -218,  -218,  -218,  -218,  -218
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -218,  -218,  -218,   143,  -218,  -218,  -218,  -218,  -218,  -218,
    -218,  -218,  -218,   248,  -218,  -218,  -218,  -218,   265,  -218,
    -218,  -218,   281,  -218,  -218,  -218,  -218,  -218,  -218,   -20,
    -218,  -218,   -11,   -36,  -218,    88,  -218,   155,  -218,  -218,
     -66,   -70,  -218,  -218,  -218,  -218,  -217,    72,  -218,  -218,
    -218,  -218,  -218,  -218,   -53,   110,  -218,  -218,  -218,  -218,
    -218,  -218,  -218,  -218,  -218,    41,   280,   306,  -218,  -218,
    -218,   100,  -218,  -218,  -218,  -218,  -218,  -218,  -218,  -218,
    -218,  -218,  -218,  -218,   161,   -37,  -218,   113,   188,    60,
     -72,  -218,   166,   -73,  -218
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -137
static const yytype_int16 yytable[] =
{
      60,   115,    66,   134,   135,   114,    35,    26,    95,    96,
      97,   243,     3,    26,    49,    50,    51,    52,    53,    54,
      78,    74,    79,   149,   150,   151,   -49,    73,   171,     4,
     172,     7,    49,    50,    51,    52,    53,    54,   129,   265,
      79,    79,   115,    18,   169,    55,    56,   -27,    79,    79,
      79,    79,    79,    79,    79,    79,    79,    79,    79,    79,
      79,    79,   153,    55,    56,   103,   104,   156,   128,    50,
      51,    52,    53,    54,    46,    47,    93,    94,    49,    50,
      51,    52,    53,    54,   180,   181,    57,    21,   105,   -42,
     106,   107,   108,   109,   197,   173,   169,   167,   110,   111,
     176,    27,   112,    37,    57,    41,   113,    11,    12,    55,
      56,    13,   195,    23,    58,    28,    14,    43,   210,   -93,
     -93,   182,   183,    39,   184,    49,    50,    51,    52,    53,
      54,    79,    68,    11,    12,   211,   129,    13,   247,   248,
      57,   201,    14,   -83,   -83,   203,  -108,  -108,   207,   229,
      57,    70,   113,   147,   148,  -136,    55,    56,   242,    98,
      58,    49,    50,    51,    52,    53,    54,    76,    77,   100,
      99,   101,   128,   229,    82,    83,   132,    79,    84,    85,
      86,    87,    88,    89,   251,   136,   229,   239,   -54,   241,
     267,   137,    55,    56,   103,   104,   159,    57,   160,   163,
     -49,   115,   275,   169,   280,   273,   164,    58,   170,   174,
     175,   286,   185,   198,   178,   209,   262,   105,   205,   106,
     107,   108,   109,   214,   186,   187,   212,   110,   111,   224,
     215,   112,   285,    57,   217,   113,    49,    50,    51,    52,
      53,    54,   218,    58,    90,    91,    80,    92,    93,    94,
     220,   216,   221,    49,    50,    51,    52,    53,    54,   222,
     226,   234,   244,   240,   238,   257,   258,    55,    56,   103,
     104,   252,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   254,   260,   264,    55,    56,   103,   104,   266,   268,
     270,   272,   105,    72,   106,   107,   108,   109,   179,   186,
     187,    48,   110,   111,   227,    33,   188,   177,    57,   105,
     113,   106,   107,   108,   109,   255,   186,   187,    58,   110,
     111,   223,   287,   112,   194,    57,   225,   113,    49,    50,
      51,    52,    53,    54,   246,    58,     0,     0,   199,     0,
       0,     0,     0,     0,     0,    49,    50,    51,    52,    53,
      54,     0,     0,     0,     0,     0,     0,     0,     0,    55,
      56,   103,   104,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    55,    56,   103,   104,
       0,     0,     0,     0,   105,     0,   106,   107,   108,   109,
       0,   186,   187,     0,   110,   111,     0,     0,   228,     0,
      57,   105,   113,   106,   107,   108,   109,     0,     0,     0,
      58,   110,   111,     0,     0,   112,   196,    57,     0,   113,
      49,    50,    51,    52,    53,    54,     0,    58,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    49,    50,    51,
      52,    53,    54,     0,     0,     0,     0,     0,     0,     0,
       0,    55,    56,   103,   104,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    55,    56,
     103,   104,     0,     0,     0,     0,   105,     0,   106,   107,
     108,   109,     0,     0,   187,     0,   110,   111,     0,     0,
     274,     0,    57,   105,   113,   106,   107,   108,   109,   232,
       0,   187,    58,   110,   111,     0,     0,   112,   232,    57,
       0,   113,    49,    50,    51,    52,    53,    54,     0,    58,
       0,     0,     0,   232,     0,   233,     0,     0,     0,     0,
       0,     0,     0,     0,   233,     0,   232,     0,     0,     0,
       0,     0,     0,    55,    56,   103,   104,     0,     0,   233,
       0,     0,   277,   278,   283,     0,     0,     0,     0,     0,
       0,   283,   233,     0,     0,     0,     0,     0,   105,     0,
     106,   107,   108,   109,     0,     0,     0,     0,   110,   111,
     284,     0,   112,     0,    57,     0,   113,   284,     0,     0,
       0,     0,     0,     0,    58
};

static const yytype_int16 yycheck[] =
{
      37,    71,    39,    76,    77,    71,    26,    18,    90,    91,
      92,   228,     0,    24,     4,     5,     6,     7,     8,     9,
      57,    76,    58,    95,    96,    97,    81,    47,    77,     3,
      79,    76,     4,     5,     6,     7,     8,     9,    74,   256,
      76,    77,   112,    74,   114,    35,    36,    77,    84,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    95,
      96,    97,    99,    35,    36,    37,    38,   103,     4,     5,
       6,     7,     8,     9,    78,    79,    88,    89,     4,     5,
       6,     7,     8,     9,    78,    79,    76,     4,    60,    81,
      62,    63,    64,    65,   167,   132,   166,    69,    70,    71,
     137,    77,    74,    80,    76,     4,    78,    44,    45,    35,
      36,    48,   165,    50,    86,    79,    53,    12,   188,    67,
      68,   158,   159,    81,   160,     4,     5,     6,     7,     8,
       9,   167,    79,    44,    45,   188,   172,    48,    58,    59,
      76,   178,    53,    67,    68,   181,    67,    68,   185,   219,
      76,     4,    78,    93,    94,    80,    35,    36,   228,    82,
      86,     4,     5,     6,     7,     8,     9,    76,    76,     4,
      80,    78,     4,   243,    14,    15,    81,   213,    18,    19,
      20,    21,    22,    23,   237,    77,   256,   224,    81,   226,
     260,    80,    35,    36,    37,    38,    76,    76,    76,    76,
      81,   271,   272,   273,   274,   271,    78,    86,    78,    77,
      77,   281,    76,    75,    80,    78,   253,    60,    77,    62,
      63,    64,    65,    72,    67,    68,    63,    70,    71,    76,
      78,    74,    75,    76,    78,    78,     4,     5,     6,     7,
       8,     9,    78,    86,    84,    85,    58,    87,    88,    89,
      77,    82,    77,     4,     5,     6,     7,     8,     9,    78,
      76,    74,    61,    78,    75,    75,     5,    35,    36,    37,
      38,    77,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    77,    83,    75,    35,    36,    37,    38,    83,    78,
      78,    77,    60,    45,    62,    63,    64,    65,   155,    67,
      68,    36,    70,    71,   216,    24,    74,   152,    76,    60,
      78,    62,    63,    64,    65,   243,    67,    68,    86,    70,
      71,   211,   281,    74,   163,    76,   213,    78,     4,     5,
       6,     7,     8,     9,   234,    86,    -1,    -1,   172,    -1,
      -1,    -1,    -1,    -1,    -1,     4,     5,     6,     7,     8,
       9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,
      36,    37,    38,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    35,    36,    37,    38,
      -1,    -1,    -1,    -1,    60,    -1,    62,    63,    64,    65,
      -1,    67,    68,    -1,    70,    71,    -1,    -1,    74,    -1,
      76,    60,    78,    62,    63,    64,    65,    -1,    -1,    -1,
      86,    70,    71,    -1,    -1,    74,    75,    76,    -1,    78,
       4,     5,     6,     7,     8,     9,    -1,    86,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     4,     5,     6,
       7,     8,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    35,    36,    37,    38,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,    36,
      37,    38,    -1,    -1,    -1,    -1,    60,    -1,    62,    63,
      64,    65,    -1,    -1,    68,    -1,    70,    71,    -1,    -1,
      74,    -1,    76,    60,    78,    62,    63,    64,    65,   219,
      -1,    68,    86,    70,    71,    -1,    -1,    74,   228,    76,
      -1,    78,     4,     5,     6,     7,     8,     9,    -1,    86,
      -1,    -1,    -1,   243,    -1,   219,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   228,    -1,   256,    -1,    -1,    -1,
      -1,    -1,    -1,    35,    36,    37,    38,    -1,    -1,   243,
      -1,    -1,   272,   273,   274,    -1,    -1,    -1,    -1,    -1,
      -1,   281,   256,    -1,    -1,    -1,    -1,    -1,    60,    -1,
      62,    63,    64,    65,    -1,    -1,    -1,    -1,    70,    71,
     274,    -1,    74,    -1,    76,    -1,    78,   281,    -1,    -1,
      -1,    -1,    -1,    -1,    86
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    94,    95,     0,     3,    96,    97,    76,   101,   102,
      98,    44,    45,    48,    53,   111,   114,   125,    74,   103,
     112,     4,   122,    50,   105,   115,   125,    77,    79,   123,
     124,   116,    99,   115,   118,   122,   113,    80,   132,    81,
     130,     4,   119,    12,   106,   107,    78,    79,   111,     4,
       5,     6,     7,     8,     9,    35,    36,    76,    86,   126,
     178,   180,   181,   182,   183,   186,   178,   120,    79,   117,
       4,   100,   106,   122,    76,   127,    76,    76,   178,   126,
     181,   179,    14,    15,    18,    19,    20,    21,    22,    23,
      84,    85,    87,    88,    89,    90,    91,    92,    82,    80,
       4,    78,   108,    37,    38,    60,    62,    63,    64,    65,
      70,    71,    74,    78,   133,   134,   135,   141,   144,   149,
     152,   162,   171,   174,   176,   177,   178,   187,     4,   126,
     184,   185,    81,   128,   186,   186,    77,    80,   181,   181,
     181,   181,   181,   181,   181,   181,   181,   182,   182,   183,
     183,   183,   131,   178,   121,   109,   126,   175,   172,    76,
      76,   142,   145,    76,    78,   150,   133,    69,   104,   134,
      78,    77,    79,   178,    77,    77,   178,   130,    80,    96,
      78,    79,   178,   178,   126,    76,    67,    68,    74,   134,
     147,   148,   159,   160,   177,   147,    75,   186,    75,   185,
     129,   178,   110,   126,   173,    77,   163,   178,   161,    78,
     134,   147,    63,   153,    72,    78,    82,    78,    78,   136,
      77,    77,    78,   148,    76,   180,    76,   128,    74,   134,
     139,   140,   159,   160,    74,   164,   165,   143,    75,   178,
      78,   178,   134,   139,    61,   137,   164,    58,    59,   166,
     170,   147,    77,   154,    77,   140,   138,    75,     5,   169,
      83,   146,   178,   151,    75,   139,    83,   134,    78,   155,
      78,   167,    77,   133,    74,   134,   156,   159,   159,   168,
     134,   157,   158,   159,   160,    75,   134,   158
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
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



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
	    /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

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
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 55 "x0.y"
    {lev --;;}
    break;

  case 4:
#line 61 "x0.y"
    {
		lev ++;
		dx = 3;
		levelReg[lev].tx0 = tx;
		table[tx].adr = cx;
		//printf("\ntx = %d cx = %d\n",tx,cx);
		gen(jmp,0,1);
		if(lev > LEVMAX)
			error(32);
		//printf("lev = %d i = %d idx = %d cx = %d\n",lev,levelReg[lev].tx0,table[levelReg[lev].tx0].adr,cx);
		(yyval.number) = cx;
		islit = 0;
		iscall = 0;
	;}
    break;

  case 5:
#line 76 "x0.y"
    {
		printf("call_cx=%d cx=%d\n",call_cx,cx);
		(yyval.number) = cx - call_cx - 1;
	;}
    break;

  case 6:
#line 82 "x0.y"
    {	
		if(islit == 1){
			(yyval.number) = cx;
			gen(jmp,0,0);
			islit = 0;
			//printf("\njmp\n");
		}
		else
			(yyval.number) = -1;
	;}
    break;

  case 7:
#line 93 "x0.y"
    {
		//printf("\nlev=%d i=%d idx=%d cx=%d\n",lev,levelReg[lev].tx0,table[levelReg[lev].tx0].adr,cx);
		code[table[levelReg[lev].tx0].adr].a = cx;
		table[levelReg[lev].tx0].adr = cx;
		//printf("i = %d cx = %d\n",levelReg[lev].tx0,cx);
		table[levelReg[lev].tx0].size = (struct cx_ins*)malloc(sizeof(struct cx_ins));
		(table[levelReg[lev].tx0].size)->sz = dx;
		(table[levelReg[lev].tx0].size)->next = NULL;
		levelReg[lev].cx0 = cx;
		gen(ini,0,dx);

		printf("\n<number>3=%d\n",(yyvsp[(3) - (7)].number));
		int temp = (yyvsp[(3) - (7)].number);
		int i = 0;
		while(temp - i > 0){
			gen(cpy, lev - table[proc_id].level,dx + 2 * i);
			i ++;
		}

		if(iscall == 1){
			iscall = 0;
		}
		if((yyvsp[(6) - (7)].number) != -1){
			gen(jmp,0,(yyvsp[(1) - (7)].number));
			code[(yyvsp[(6) - (7)].number)].a = cx;
		}
	;}
    break;

  case 9:
#line 126 "x0.y"
    {printf("\nfunction parenthheses\n"); ;}
    break;

  case 10:
#line 126 "x0.y"
    {printf("\n4444\n");;}
    break;

  case 11:
#line 127 "x0.y"
    { iscall = 1; ;}
    break;

  case 13:
#line 133 "x0.y"
    {gen(opr,0,20);;}
    break;

  case 14:
#line 134 "x0.y"
    {gen(opr,0,0);;}
    break;

  case 20:
#line 151 "x0.y"
    {
		call_cx = cx; 
		strcpy(id,(yyvsp[(2) - (2)].ident));
		enter(procedur,0);
		(yyval.number) = proc_id;
		proc_id = position(id);
	;}
    break;

  case 21:
#line 158 "x0.y"
    {levelReg[lev].dx0 = dx;;}
    break;

  case 22:
#line 160 "x0.y"
    {
		lev --;
		dx = levelReg[lev].dx0;
		proc_id = (yyvsp[(3) - (5)].number);
	;}
    break;

  case 24:
#line 169 "x0.y"
    {printf("\nhere1\n");;}
    break;

  case 25:
#line 169 "x0.y"
    {printf("\n,\n"); ;}
    break;

  case 27:
#line 171 "x0.y"
    {printf("end\n");;}
    break;

  case 29:
#line 178 "x0.y"
    {
		printf("\nin stat\n");
		if(dis == 0)
			genk(sto,lev - table[idx].level,table[idx].adr, idx);
		else
			genk(sto2,lev - table[idx].level,table[idx].adr, idx);
	;}
    break;

  case 31:
#line 193 "x0.y"
    {isconst = 1;;}
    break;

  case 32:
#line 195 "x0.y"
    {isconst = 0;;}
    break;

  case 36:
#line 206 "x0.y"
    {strcpy(id,(yyvsp[(1) - (1)].ident));;}
    break;

  case 37:
#line 208 "x0.y"
    {
		num = (yyvsp[(4) - (4)].number);
		enter(constant,num);
	;}
    break;

  case 38:
#line 214 "x0.y"
    {strcpy(id,(yyvsp[(3) - (3)].ident));;}
    break;

  case 39:
#line 216 "x0.y"
    {
		num = (yyvsp[(6) - (6)].number);
		enter(constant,num);
	;}
    break;

  case 40:
#line 224 "x0.y"
    {
		strcpy(id,(yyvsp[(1) - (1)].ident));
		switch(tp){
			case 'b':
				enter(boolean,0);
				break;
			case 'i':
				enter(integer,0);
				break;
			case 'c':
				enter(character,0);
				break;
			case 'f':
				enter(floatnum,0);
				break;
			default:
				error(40);
		}
		(yyval.number) = position(id);
	;}
    break;

  case 41:
#line 245 "x0.y"
    {
		islit = 1;
		idx = position(id);
		if((yyvsp[(3) - (3)].vartype) == '='){
			//printf("sto idx=%d\n",idx);
			genk(sto,lev - table[idx].level,table[idx].adr, (yyvsp[(2) - (3)].number));
		}
	;}
    break;

  case 42:
#line 255 "x0.y"
    {
		isarray = 1;
		printf("\nid = %s\n",id);
		strcpy(id,(yyvsp[(1) - (1)].ident));
	;}
    break;

  case 43:
#line 261 "x0.y"
    {
		switch(tp){
			case 'b':
				enter(boolean,dis);
				break;
			case 'i':
				enter(integer,dis);
				break;
			case 'c':
				enter(character,dis);
				break;
			case 'f':
				enter(floatnum,0);
				break;
			default:
				error(40);
		}
		isarray = 0;
		dis = 0;
	;}
    break;

  case 44:
#line 284 "x0.y"
    { tp = 'i'; ;}
    break;

  case 45:
#line 285 "x0.y"
    { tp = 'c'; ;}
    break;

  case 46:
#line 286 "x0.y"
    { tp = 'f'; ;}
    break;

  case 47:
#line 287 "x0.y"
    { tp = 'b'; ;}
    break;

  case 48:
#line 292 "x0.y"
    {
		int i;
		strcpy(id,(yyvsp[(1) - (1)].ident));
		i = position(id);
		idx = i;
		if(i == 0){
			error(35);
		}
		else{
		 	kind = table[i].kind;
		}
		dis = 0;
	;}
    break;

  case 49:
#line 305 "x0.y"
    {dis = 0;arridx = 0;strcpy(id,(yyvsp[(1) - (1)].ident));;}
    break;

  case 50:
#line 307 "x0.y"
    {
		int i = position(id);
		idx = i;
		printf("\narray idx = %d\n",idx);
		if(i == 0){
			error(35);
		}
		else{
		 	kind = table[i].kind;
		}
		printf("dis = %d\n",dis);
	;}
    break;

  case 51:
#line 323 "x0.y"
    { 
	 	 if(arridx > 0)
			 gen(opr,0,2);
		 int i = position(id);
		 printf("\nread or write id = %s\n",id);
		 int j = 0,num;
		 struct SZ* temp = table[i].size;

		 for(j = 0;j < arridx;j ++){
		 	if(temp == NULL)
		 		error(41);	//数组访问越界
		 	temp = temp->next;
		 }	
		 if(temp == NULL){
			error(44);
		 }
		 else{
		 	if(temp->next != NULL){
			 	printf("lit\n");
				num = temp->sz;
			 	gen(lit,0,num);
				gen(opr,0,4);
			}
		 }
		 arridx ++;
	 ;}
    break;

  case 52:
#line 351 "x0.y"
    {
		int i = position(id);
		idx = i;
		if(i == 0)
			error(35);
		else{
		 	kind = table[i].kind;
		}
		if(dis == 0){
			dis = (yyvsp[(2) - (5)].number);
		}
		else{
			dis = (yyvsp[(2) - (5)].number)*dis;
		}
	;}
    break;

  case 54:
#line 371 "x0.y"
    {	
		printf("\ndecarray id = %s\n",id);
		int i = position(id);
		idx = i;
		if(i == 0)
			error(35);
		else{
		 	kind = table[i].kind;
		}
		if(dis == 0){
			dis = (yyvsp[(2) - (3)].number);
		}
		else{
			dis = (yyvsp[(2) - (3)].number)*dis;
		}
		struct SZ* p = table[i].size,*temp,*q;
		temp = (struct SZ*)malloc(sizeof(struct SZ));
		temp->sz = (yyvsp[(2) - (3)].number);
		temp->next = NULL;
		if(p == NULL){
			table[i].size = temp;
		}
		else{
			while(p != NULL){
				q = p;
				p = p->next;
			}
			q->next = temp;
		}
		//printf("sz=%d\n",$<number>2);
	;}
    break;

  case 56:
#line 404 "x0.y"
    {
		int i = position(id);
		idx = i;
		if(i == 0)
			error(35);
		else{
		 	kind = table[i].kind;
		}
		if(dis == 0)
			dis = (yyvsp[(2) - (3)].number);
		else
			dis = (yyvsp[(2) - (3)].number)*dis;
		struct SZ* p = table[i].size,*temp,*q;
		temp = (struct SZ*)malloc(sizeof(struct SZ));
		temp->sz = (yyvsp[(2) - (3)].number);
		temp->next = NULL;
		if(p == NULL)
			table[i].size = temp;
		else{
			while(p != NULL){
				q = p;
				p = p->next;
			}
			q->next = temp;
		}
		q = table[i].size;
		while(q != NULL){
			q = q->next;
		}
		//printf("sz=%d\n",$<number>2);
	;}
    break;

  case 57:
#line 439 "x0.y"
    {
		(yyval.vartype) = '=';
	;}
    break;

  case 58:
#line 443 "x0.y"
    {
		(yyval.vartype) = 'N';
	;}
    break;

  case 69:
#line 463 "x0.y"
    {gen(opr,0,15);;}
    break;

  case 73:
#line 472 "x0.y"
    {
	 	(yyval.number) = cx;
		gen(jpc,0,0);
	 ;}
    break;

  case 74:
#line 478 "x0.y"
    {
	 	code[(yyvsp[(5) - (7)].number)].a = cx;
	 ;}
    break;

  case 75:
#line 485 "x0.y"
    {
	 	cx2 = cx;
	 	gen(jmp,0,0);
	 	code[cx1].a = cx;
	 ;}
    break;

  case 76:
#line 491 "x0.y"
    {
	 	code[cx2].a = cx;
	 ;}
    break;

  case 84:
#line 513 "x0.y"
    {(yyval.number) = cx;;}
    break;

  case 85:
#line 515 "x0.y"
    {
 	 	(yyval.number) = cx;
 		gen(jpc,0,0);
 		bcx = 0;
	 	ccx = 0;
 	 ;}
    break;

  case 86:
#line 522 "x0.y"
    {
 	 	gen(jmp,0,(yyvsp[(2) - (7)].number));
 	 	code[(yyvsp[(6) - (7)].number)].a = cx;
 	 	if(bcx > 0){
 	 		code[bcx].a = cx;
 	 		bcx = 0;
 	 	}
 	 	if(ccx > 0){
 	 		code[ccx].a = (yyvsp[(2) - (7)].number);
 	 		ccx = 0;
 	 	}
 	 ;}
    break;

  case 87:
#line 538 "x0.y"
    {
	 	(yyval.number) = cx;
	 ;}
    break;

  case 88:
#line 543 "x0.y"
    {
	 	gen(jpc,0,0);
	 	gen(jmp, 0,(yyvsp[(2) - (7)].number));
	 	code[cx-2].a = cx;
	 	if(bcx > 0){
 	 		code[bcx].a = cx;
 	 		bcx = 0;
 	 	}
 	 	if(ccx > 0){
 	 		code[ccx].a = (yyvsp[(2) - (7)].number);
 	 		ccx = 0;
 	 	}
	 ;}
    break;

  case 96:
#line 573 "x0.y"
    {(yyval.number) = cx;;}
    break;

  case 97:
#line 577 "x0.y"
    {
	 	gen(jpc,0,(yyvsp[(2) - (7)].number));
	 	gen(jmp,0,cx+1);
	;}
    break;

  case 99:
#line 586 "x0.y"
    {
	 	(yyval.number) = cx;
	 ;}
    break;

  case 100:
#line 590 "x0.y"
    {
	 	(yyval.number) = cx;
	 	gen(jpc,0,0);
	 	gen(jmp,0,0);
	 ;}
    break;

  case 101:
#line 596 "x0.y"
    {
	 	gen(jmp,0,(yyvsp[(4) - (8)].number));
	 	code[(yyvsp[(7) - (8)].number)+1].a = cx;
	 	bcx = 0;
	 	ccx = 0;
	 ;}
    break;

  case 102:
#line 604 "x0.y"
    {
	 	gen(jmp,0,(yyvsp[(7) - (11)].number) + 2);
	 	code[(yyvsp[(7) - (11)].number)].a = cx;
	 	if(bcx > 0){
		 	code[bcx].a = cx;
		 	bcx = 0;
	 	}
	 	if(ccx > 0){
	 		code[ccx].a = (yyvsp[(7) - (11)].number) + 2;
	 		ccx = 0;
	 	}
	 ;}
    break;

  case 111:
#line 637 "x0.y"
    {
		bcx = cx;
		printf("\nbcx=%d\n",bcx);
		gen(jmp,0,0);
	;}
    break;

  case 112:
#line 646 "x0.y"
    {
		ccx = cx;
		gen(jmp,0,0);
	;}
    break;

  case 114:
#line 655 "x0.y"
    {
		cx2 = cx;
		gen(lod,lev - table[idx + dis].level,table[idx + dis].adr);
	;}
    break;

  case 117:
#line 667 "x0.y"
    {
		struct cx_ins* temp = (yyvsp[(1) - (1)].cx_table),* tt;
		while(temp->next != NULL){
			tt = temp;
			temp = temp->next;
			free(tt);
			//printf("num=%d\n",temp->adr);
			code[temp->adr].a = cx;
		}
	;}
    break;

  case 119:
#line 682 "x0.y"
    {	
		if(bcx > 0){
			if((yyval.cx_table) == NULL){
				(yyval.cx_table) = (struct cx_ins *)malloc(sizeof(struct cx_ins));
				(yyval.cx_table)->adr = 0;
				(yyval.cx_table)->next = NULL;	
			}
			struct cx_ins * temp,* node;
			node = (struct cx_ins *)malloc(sizeof(struct cx_ins));
			node->next = NULL;
			node->adr = cx-1;
			temp = (yyval.cx_table);
			while(temp->next != NULL)
				temp = temp->next;
			temp->next = node;
			code[bcx].a = cx;
			bcx = 0;
		}
	;}
    break;

  case 121:
#line 706 "x0.y"
    {	
		gen(opr,0,7);
		(yyval.number) = cx;
		gen(jpc,0,0);
	;}
    break;

  case 122:
#line 712 "x0.y"
    {
		code[(yyvsp[(4) - (6)].number)].a = cx;
	;}
    break;

  case 125:
#line 724 "x0.y"
    {gen(lit,0,(yyvsp[(1) - (1)].number));;}
    break;

  case 127:
#line 733 "x0.y"
    {printf("write_stat\n");;}
    break;

  case 128:
#line 733 "x0.y"
    {printf("expression\n");;}
    break;

  case 129:
#line 734 "x0.y"
    {	
		 switch(kind){
		 	case integer:
		 		gen(opr,0,14);
		 		break;
		 	case character:
				gen(opr,1,14);
		 		break;
		 	case floatnum:
		 		gen(opr,2,14);
		 		break;
		 	case constant:
				gen(opr,0,14);
		 		break;
		 	case boolean:
		 		gen(opr,3,14);
		 		break;
		 	default:
		 		error(38);
		 		break;
		 }
	 ;}
    break;

  case 131:
#line 765 "x0.y"
    {	
	 	switch(kind){
	 		case integer:
	 			gen(opr,0,16);
	 			break;
	 		case character:
	 			gen(opr,1,16);
	 			break;
	 		case floatnum:
	 			gen(opr,2,16);
	 			break;
	 		case boolean:
	 			gen(opr,3,16);
	 			break;
	 		default:
	 			error(37);
	 			break;
	 	}
	 	if(dis == 0)
			genk(sto,lev - table[idx].level,table[idx].adr, idx);
		else
			genk(sto2,lev - table[idx].level,table[idx].adr, idx);
	 ;}
    break;

  case 132:
#line 789 "x0.y"
    {	
	 	switch(kind){
	 		case integer:
	 			gen(opr,0,16);
	 			break;
	 		case character:
	 			gen(opr,1,16);
	 			break;
	 		case floatnum:
	 			gen(opr,2,16);
	 			break;
	 		case boolean:
	 			gen(opr,3,16);
	 			break;
	 		default:
	 			error(36);
	 			break;
	 	}
	 	if(dis == 0)
			genk(sto,lev - table[idx].level,table[idx].adr, idx);
		else
			genk(sto2,lev - table[idx].level,table[idx].adr, idx);
	 ;}
    break;

  case 136:
#line 825 "x0.y"
    {
		if(kind != integer && kind != character && kind != floatnum && kind != boolean){
			error(12);
			idx = 0;
		}
		(yyval.number) = idx;
	 ;}
    break;

  case 137:
#line 833 "x0.y"
    {
		int i;
		if((yyvsp[(2) - (4)].number) != 0){
			i = (yyvsp[(2) - (4)].number);
			if(dis == 0)
				genk(sto,lev - table[i].level,table[i].adr, (yyvsp[(2) - (4)].number));
			else
				genk(sto2,lev - table[i].level,table[i].adr, (yyvsp[(2) - (4)].number));
		}
	 ;}
    break;

  case 140:
#line 849 "x0.y"
    {
	 	gen(lit,0,1);
	 	gen(opr,0,2);
	 	if(dis == 0)
			genk(sto,lev - table[idx].level,table[idx].adr, idx);
		else
			genk(sto2,lev - table[idx].level,table[idx].adr, idx);
	 ;}
    break;

  case 141:
#line 858 "x0.y"
    {
	 	gen(lit,0,1);
	 	gen(opr,0,3);
	 	if(dis == 0)
			genk(sto,lev - table[idx].level,table[idx].adr, idx);
		else
			genk(sto2,lev - table[idx].level,table[idx].adr, idx);
	 ;}
    break;

  case 142:
#line 867 "x0.y"
    { gen(opr,0,12); ;}
    break;

  case 143:
#line 869 "x0.y"
    { gen(opr,0,10); ;}
    break;

  case 144:
#line 871 "x0.y"
    { gen(opr,0,13); ;}
    break;

  case 145:
#line 873 "x0.y"
    { gen(opr,0,11); ;}
    break;

  case 146:
#line 875 "x0.y"
    { gen(opr,0,8); ;}
    break;

  case 147:
#line 877 "x0.y"
    { gen(opr,0,9); ;}
    break;

  case 148:
#line 879 "x0.y"
    { gen(opr,0,21); ;}
    break;

  case 149:
#line 881 "x0.y"
    { gen(opr,0,22); ;}
    break;

  case 150:
#line 883 "x0.y"
    { gen(opr,0,23); ;}
    break;

  case 151:
#line 885 "x0.y"
    { gen(opr,0,18); ;}
    break;

  case 152:
#line 891 "x0.y"
    {gen(opr,0,2);;}
    break;

  case 153:
#line 893 "x0.y"
    {gen(opr,0,3);;}
    break;

  case 155:
#line 899 "x0.y"
    {gen(opr,0,4);;}
    break;

  case 156:
#line 901 "x0.y"
    {gen(opr,0,5);;}
    break;

  case 157:
#line 903 "x0.y"
    {gen(opr,0,17);;}
    break;

  case 159:
#line 909 "x0.y"
    {gen(lit,0,2);
	gen(opr,0,17);;}
    break;

  case 160:
#line 912 "x0.y"
    {
		gen(opr,0,20);	
	;}
    break;

  case 161:
#line 917 "x0.y"
    {
		int i;
		strcpy(id,(yyvsp[(1) - (4)].ident));
		i = position(id);

		printf("here\n");
		if(i == 0)
			error(11);
		else{
			if(table[i].kind == procedur){
				gen(cal,lev - table[i].level,table[i].adr);
			}
			else
				error(15);
		}
		printf("here\n");
	;}
    break;

  case 166:
#line 946 "x0.y"
    {	
	 	if(dis == 0)
			gen(lod,lev - table[idx].level,table[idx].adr);
		else
			gen(lod2,lev - table[idx].level,table[idx].adr);
	;}
    break;

  case 168:
#line 957 "x0.y"
    {
	 	switch(kind){
	 		case constant:
	 			gen(lit,0,byte2int(table[idx+dis].val));
	 			break;
	 		case integer:
	 			if(dis == 0)
	 				gen(lod,lev - table[idx].level,table[idx].adr);
	 			else
	 				gen(lod2,lev - table[idx].level,table[idx].adr);
	 			break;
	 		case character:
	 			if(dis == 0)
	 				gen(lod,lev - table[idx].level,table[idx].adr);
	 			else
	 				gen(lod2,lev - table[idx].level,table[idx].adr);
	 			break;
	 		case floatnum:
	 			if(dis == 0)
	 				gen(lod,lev - table[idx].level,table[idx].adr);
	 			else
	 				gen(lod2,lev - table[idx].level,table[idx].adr);
	 			break;
	 		case  boolean:
	 			if(dis == 0)
	 				gen(lod,lev - table[idx].level,table[idx].adr);
	 			else
	 				gen(lod2,lev - table[idx].level,table[idx].adr);
	 			break;
	 		case procedur:
	 			error(21);
	 			break;
	 	}
	 ;}
    break;

  case 169:
#line 992 "x0.y"
    {
	 	int num;
	 	num = (yyvsp[(1) - (1)].number);
	 	if(num > AMAX){
	 		error(31);
	 		num = 0;
	 	}
	 	if(isconst == 0 && isarray == 0){
			gen(lit,0,num);
		}
	 ;}
    break;

  case 170:
#line 1004 "x0.y"
    {
	 	if(isconst == 0 && isarray == 0){
			gen(lit,1, byte2int(char2byte((yyvsp[(1) - (1)].character))));
		}
	 ;}
    break;

  case 171:
#line 1010 "x0.y"
    {
	 	float num;
	 	num = (yyvsp[(1) - (1)].floatnum);
	 	if(num > AMAX){
	 		error(31);
	 		num = 0;
	 	}
	 	if(isconst == 0 && isarray == 0){
			gen(lit,2, byte2int(float2byte(num)));
		}
	 ;}
    break;

  case 172:
#line 1022 "x0.y"
    { 
	 	if(isconst == 0 && isarray == 0){
	 		gen(lit,3,1);
	 	}
	 ;}
    break;

  case 173:
#line 1028 "x0.y"
    {
	 	if(isconst == 0 && isarray == 0){
	 		gen(lit,3,0);
	 	}
	 ;}
    break;

  case 174:
#line 1037 "x0.y"
    { gen(ext,0,0); ;}
    break;


/* Line 1267 of yacc.c.  */
#line 2876 "x0.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
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
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 1040 "x0.y"


extern char yytext[];
extern int column;

yyerror(char *s){
	err++;
	printf("%s in line %d\n",s,line);
}

void print(){
	printf("\ntable:\n");
	for(int i = 1;i <= tx;i++){
		printf("%5d %10s ",i,table[i].name);
		if(table[i].isval == 1){
			if(table[i].kind == integer)
				printf("%6d\t",byte2int(table[i].val));
			else if(table[i].kind == character)
				printf("%6c\t",byte2char(table[i].val));
			else if(table[i].kind == floatnum)
				printf("%6f\t",byte2char(table[i].val));
			else if(table[i].kind == boolean){
				if(byte2int(table[i].val) == 0)
					printf(" false\t");
				else
					printf("  true\t");
			}
		}
		else
			printf("  null\t");
		printf("%5d  %5d \t",table[i].level,table[i].adr);
		struct SZ *temp = table[i].size;
		if(temp == NULL)
			printf("0");
		while(temp != NULL){
			printf("%d\t",temp->sz);
			temp = temp->next;
		}
		printf("\n");
	}
}

int main(int argc, char** argv)
{
	if(argc != 2){
		printf("argc of command is not 2!");
		return 0;
	}
	if((fa1 = fopen("fa1.txt","w")) == NULL){
		printf("Cann't open file!\n");
		exit(0);
	}
	strcpy(fname,argv[1]);
	if((fin=fopen(fname,"r"))==NULL){
		printf("Cann't open file according to given filename\n");
		exit(0);
	}
	redirectInput(fin);
	//printf("List object code?[y/n]");
	//scanf("%s",fname);
	fname[0] = 'y';
	fprintf(fa1,"\nList object code?\n");
	if(fname[0] == 'y')
		listswitch = t;
	else
		listswitch = f;
	err = 0;
	cx = 0;
	if((fa=fopen("fa.txt","w")) == NULL){
		printf("Cann't open fa.txt file!\n");
		exit(0);
	}
	if((fa2=fopen("fa2.txt","w")) == NULL){
		printf("Cann't open fa2.txt file!\n");
		exit(0);
	}
	yyparse();
	fclose(fa);
	fclose(fa1);

	listcode();
	interpret();
	print();
	if(err != 0)
		printf("%d errors in PL/0 program\n",err);
	fclose(fin);
	return 0;
}
