/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "Compiler.y" /* yacc.c:339  */

  /*_____Definition section_____literal c++ code between single "%"_____*/

  /*Necesary imports*/
    #include <stdio.h>
    #include <iostream>
    #include <string.h>
    #include <bitset>
    #include <vector>
    #include <map>
    #include <stdlib.h>
    #include <algorithm>
    #include <cstdlib>
    #include <fstream>
    #include <list>

    

    //C++ definitions
    std::fstream fs; //stream instruction file
    std::string final_message="Compiler success";
    int memCount=0; // memory instruction count initialized
    std::string line;

    int yylex();  //call to invoke lexer, returns token
    extern int yylineno; //line number counter

    /*Define different ARM instructions structures*/
    void encondig_instruccion(std::string op,std::string rs,std::string rs2,std::string rd); // op rs,rs2,rd
    void encondig_instruccion1(std::string op,std::string rs,std::string rd,std::string immen); //op rs,rd,immen
    void encondig_instruccion2(std::string op,std::string rs,std::string rd); // op rs,rd
    void encondig_instruccion3(std::string op,std::string rs,std::string imme); //op rs,immen
    void encondig_instruccion4(std::string op,std::string rd,std::string rs,std::string rs2,int type); //op rd,rs,rs2,type
    void encondig_instruccion5(std::string op,std::string immen); //op rs,immen
    
    /*Other definitions*/
    std::string regtobin(std::string r); // parse register to binary data
    std::string immtobin(std::string in,int type,std::string rs); // parse immediate to binary
    int text_memory=0x00000000; //memory reference start for text
    bool repeat_flag=false; //flag to know if repeat instruction
    std::list <std::string> instlist; //list of instructions to repeat
    void yyerror(std::string S); // define error function


#line 111 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    addition = 258,
    subtra = 259,
    multiple = 260,
    comp = 261,
    load = 262,
    store = 263,
    mv = 264,
    xorop = 265,
    circularleft = 266,
    circularright = 267,
    linealleft = 268,
    linealright = 269,
    brepeat = 270,
    erepeat = 271,
    reg = 272,
    immediate = 273,
    commentary = 274,
    number = 275
  };
#endif
/* Tokens.  */
#define addition 258
#define subtra 259
#define multiple 260
#define comp 261
#define load 262
#define store 263
#define mv 264
#define xorop 265
#define circularleft 266
#define circularright 267
#define linealleft 268
#define linealright 269
#define brepeat 270
#define erepeat 271
#define reg 272
#define immediate 273
#define commentary 274
#define number 275

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 46 "Compiler.y" /* yacc.c:355  */

  char* id;
  int num;

#line 196 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 213 "y.tab.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   33

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  25
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  4
/* YYNRULES -- Number of rules.  */
#define YYNRULES  27
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  38

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   275

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      21,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,    22,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    23,     2,    24,     2,     2,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    62,    62,    63,    64,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "addition", "subtra", "multiple", "comp",
  "load", "store", "mv", "xorop", "circularleft", "circularright",
  "linealleft", "linealright", "brepeat", "erepeat", "reg", "immediate",
  "commentary", "number", "'\\n'", "','", "'['", "']'", "$accept", "line",
  "instruccion", "operation", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,    10,    44,    91,    93
};
# endif

#define YYPACT_NINF -20

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-20)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -20,     0,   -20,   -20,   -20,   -20,   -20,   -20,   -20,   -20,
     -20,   -20,   -20,   -20,   -20,   -20,   -20,   -20,   -19,     4,
      13,   -20,   -20,   -20,    -5,   -20,     3,    -4,   -20,     7,
      15,     5,   -20,   -20,    10,   -20,    -2,   -20
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     1,    13,    14,    15,    16,    17,    19,    18,
      20,    21,    22,    23,    24,    25,    26,    27,     0,     0,
       0,     3,    12,     2,     0,    11,     0,     5,     6,     0,
       0,     0,    10,     7,     0,     8,     0,     9
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -20,   -20,   -20,   -20
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,    19,    20
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
       2,     3,    21,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    26,    30,    18,
      27,    28,    37,    22,    31,    23,    29,    34,    36,    35,
      24,    25,    32,    33
};

static const yytype_uint8 yycheck[] =
{
       0,     1,    21,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    22,    22,    19,
      17,    18,    24,    19,    17,    21,    23,    22,    18,    24,
      17,    18,    17,    18
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    26,     0,     1,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    19,    27,
      28,    21,    19,    21,    17,    18,    22,    17,    18,    23,
      22,    17,    17,    18,    22,    24,    18,    24
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    25,    26,    26,    26,    27,    27,    27,    27,    27,
      27,    27,    27,    27,    28,    28,    28,    28,    28,    28,
      28,    28,    28,    28,    28,    28,    28,    28
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     3,     3,     0,     4,     4,     6,     6,     8,
       6,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
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
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
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
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
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
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 5:
#line 67 "Compiler.y" /* yacc.c:1646  */
    {encondig_instruccion2((yyvsp[-3].id),(yyvsp[-2].id),(yyvsp[0].id));}
#line 1306 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 68 "Compiler.y" /* yacc.c:1646  */
    {encondig_instruccion3((yyvsp[-3].id),(yyvsp[-2].id),(yyvsp[0].id));}
#line 1312 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 69 "Compiler.y" /* yacc.c:1646  */
    {encondig_instruccion1((yyvsp[-5].id),(yyvsp[-2].id),(yyvsp[-4].id),(yyvsp[0].id));}
#line 1318 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 70 "Compiler.y" /* yacc.c:1646  */
    {encondig_instruccion4((yyvsp[-5].id),(yyvsp[-4].id),(yyvsp[-1].id),"",1);}
#line 1324 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 71 "Compiler.y" /* yacc.c:1646  */
    {encondig_instruccion4((yyvsp[-7].id),(yyvsp[-6].id),(yyvsp[-3].id),(yyvsp[-1].id),3);}
#line 1330 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 72 "Compiler.y" /* yacc.c:1646  */
    {encondig_instruccion((yyvsp[-5].id),(yyvsp[-4].id),(yyvsp[-2].id),(yyvsp[0].id));}
#line 1336 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 73 "Compiler.y" /* yacc.c:1646  */
    {encondig_instruccion5((yyvsp[-1].id),(yyvsp[0].id));}
#line 1342 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 74 "Compiler.y" /* yacc.c:1646  */
    {;}
#line 1348 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 75 "Compiler.y" /* yacc.c:1646  */
    {yyerror("instruccion not supported");}
#line 1354 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 79 "Compiler.y" /* yacc.c:1646  */
    {;}
#line 1360 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 80 "Compiler.y" /* yacc.c:1646  */
    {;}
#line 1366 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 81 "Compiler.y" /* yacc.c:1646  */
    {;}
#line 1372 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 82 "Compiler.y" /* yacc.c:1646  */
    {;}
#line 1378 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 83 "Compiler.y" /* yacc.c:1646  */
    {;}
#line 1384 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 84 "Compiler.y" /* yacc.c:1646  */
    {;}
#line 1390 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 85 "Compiler.y" /* yacc.c:1646  */
    {;}
#line 1396 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 86 "Compiler.y" /* yacc.c:1646  */
    {;}
#line 1402 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 87 "Compiler.y" /* yacc.c:1646  */
    {;}
#line 1408 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 88 "Compiler.y" /* yacc.c:1646  */
    {;}
#line 1414 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 89 "Compiler.y" /* yacc.c:1646  */
    {;}
#line 1420 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 90 "Compiler.y" /* yacc.c:1646  */
    {;}
#line 1426 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 91 "Compiler.y" /* yacc.c:1646  */
    {;}
#line 1432 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 92 "Compiler.y" /* yacc.c:1646  */
    {;}
#line 1438 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1442 "y.tab.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



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
                      yytoken, &yylval);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 95 "Compiler.y" /* yacc.c:1906  */


extern int yyparse();
extern FILE *yyin; //file used as input
std::string ruta=""; //where the file to read is located

//Instruccion op rd,rs,rm
void encondig_instruccion(std::string op,std::string rs,std::string rs2,std::string rd){
  std::string binIns="0000"; //Condition always
  text_memory+=0x4; // incrementa contador de instrucciones en 4 debido a la alineacion
  if(op.compare("Add")==0 || op.compare("ADD")==0 || op.compare("add")==0){
    binIns+="0001"; // Op code for add
    binIns+="000000000000"; // bit of reg or imm operation + empty bits if necessary
    binIns+=regtobin(rs);
    binIns+=regtobin(rs2);
    binIns+=regtobin(rd);
    if(!repeat_flag){
      fs<<binIns<<'\n';
    }
    else{
      instlist.push_back(binIns);
    }
    
  }else if(op.compare("Sub")==0 || op.compare("sub")==0 || op.compare("SUB")==0){
    binIns+="0010"; // Op code for sub
    binIns+="000000000000"; // bit of reg or imm operation + empty bits if necessary
    binIns+=regtobin(rs);
    binIns+=regtobin(rs2);
    binIns+=regtobin(rd);
    if(!repeat_flag){
      fs<<binIns<<'\n';
    }
    else{
      instlist.push_back(binIns);
    }
  }else if(op.compare("Mul")==0 || op.compare("MUL")==0 || op.compare("mul")==0){
    binIns+="0011"; // Op code for mul
    binIns+="000000000000"; // bit of reg or imm operation + empty bits if necessary
    binIns+=regtobin(rs);
    binIns+=regtobin(rs2);
    binIns+=regtobin(rd);
    if(!repeat_flag){
      fs<<binIns<<'\n';
    }
    else{
      instlist.push_back(binIns);
    }
  }
  else if(op.compare("Xor")==0 || op.compare("XOR")==0 || op.compare("xor")==0){
    binIns+="0000"; // Op code for xor
    binIns+="000000000000"; // bit of reg or imm operation + empty bits if necessary
    binIns+=regtobin(rs);
    binIns+=regtobin(rs2);
    binIns+=regtobin(rd);
    if(!repeat_flag){
      fs<<binIns<<'\n';
    }
    else{
      instlist.push_back(binIns);
    }
  }
  else{
    std::cout<< "Error at read instruccion: Format mnemonic R,R,R only support Add,Sub,Mult,Xor"<<'\n';
  }
}

//intruccion  op rd,rs,#imme
void encondig_instruccion1(std::string op,std::string rs,std::string rd,std::string immen){
  std::string binIns="0000";
  text_memory+=0x4;
  if(op.compare("Add")==0 || op.compare("ADD")==0 || op.compare("add")==0){

    binIns+="0001"; // Op code for add
    binIns+="10000000"; // bit of reg or imm operation + empty bits if necessary
    std::string r=regtobin(rd);
    binIns+=r;
    binIns+=regtobin(rs);
    binIns+=immtobin(immen,1,r);
    if(!repeat_flag){
      fs<<binIns<<'\n';
    }
    else{
      instlist.push_back(binIns);
    }
  }
  else if(op.compare("Sub")==0 || op.compare("sub")==0 || op.compare("SUB")==0){
    binIns+="0010"; // Op code for add
    binIns+="10000000"; // bit of reg or imm operation + empty bits if necessary
    std::string r=regtobin(rd);
    binIns+=r;
    binIns+=regtobin(rs);
    binIns+=immtobin(immen,1,r);
    if(!repeat_flag){
      fs<<binIns<<'\n';
    }
    else{
      instlist.push_back(binIns);
    }
  }else if(op.compare("Mul")==0 || op.compare("MUL")==0 || op.compare("mul")==0){
    binIns+="0011"; // Op code for mul
    binIns+="10000000"; // bit of reg or imm operation + empty bits if necessary
    std::string r=regtobin(rd);
    binIns+=r;
    binIns+=regtobin(rs);
    binIns+=immtobin(immen,1,r);
    if(!repeat_flag){
      fs<<binIns<<'\n';
    }
    else{
      instlist.push_back(binIns);
    }
  }
  else if(op.compare("Xor")==0 || op.compare("XOR")==0 || op.compare("xor")==0){
    binIns+="0000"; // Op code for xor
    binIns+="10000000"; // bit of reg or imm operation + empty bits if necessary
    std::string r=regtobin(rd);
    binIns+=r;
    binIns+=regtobin(rs);
    binIns+=immtobin(immen,1,r);
    if(!repeat_flag){
      fs<<binIns<<'\n';
    }
    else{
      instlist.push_back(binIns);
    }
  }
  else{
    std::cout<< "Error at read instruccion: format mnemonic R,R,Imm only support cmp,mov,up"<<'\n';
  }
}

//Instruccion op rd,rs
void encondig_instruccion2(std::string op,std::string rs,std::string rd){
  std::string binIns="0000";
  text_memory+=0x4;
  if(op.compare("cmp")==0 || op.compare("CMP")==0 || op.compare("Cmp")==0){
    binIns+="0100"; // Op code for cmp
    binIns+="0000000000000000"; // empty bits if necessary
    binIns+=regtobin(rs);
    binIns+=regtobin(rd);
    if(!repeat_flag){
      fs<<binIns<<'\n';
    }
    else{
      instlist.push_back(binIns);
    }
  }else if(op.compare("mov")==0 || op.compare("MOV")==0 || op.compare("Mov")==0){
    binIns+="0101"; // Op code for cmp
    binIns+="0000000000000000"; // empty bits if necessary
    binIns+=regtobin(rs);
    binIns+=regtobin(rd);
    if(!repeat_flag){
      fs<<binIns<<'\n';
    }
    else{
      instlist.push_back(binIns);
    }
  }
  else{
    std::cout<< "Error at read instruccion: format mnemonic R,R only support cmp,mov"<<'\n';
  }
}

//Instruccion op rd,#imme
void encondig_instruccion3(std::string op,std::string rs,std::string imme){
  std::string binIns="0000";
  text_memory+=0x4;
  if(op.compare("cmp")==0 || op.compare("CMP")==0 || op.compare("Cmp")==0){
    binIns+="0100";
    binIns+="100000000000"; // empty bits if necessary
    std::string r=regtobin(rs);
    binIns+=r;
    binIns+=immtobin(imme,1,r);
    if(!repeat_flag){
      fs<<binIns<<'\n';
    }
    else{
      instlist.push_back(binIns);
    }
  }
  else if(op.compare("mov")==0 || op.compare("MOV")==0 || op.compare("Mov")==0){
    binIns+="0101";
    binIns+="100000000000"; // empty bits if necessary
    std::string r=regtobin(rs);
    binIns+=r;
    binIns+=immtobin(imme,1,r);
    if(!repeat_flag){
      fs<<binIns<<'\n';
    }
    else{
      instlist.push_back(binIns);
    }
  }
  else if(op.compare("csl")==0 || op.compare("CSL")==0 || op.compare("Csl")==0){
    binIns+="0110";
    binIns+="100000000000"; // empty bits if necessary
    std::string r=regtobin(rs);
    binIns+=r;
    binIns+=immtobin(imme,1,r);
    if(!repeat_flag){
      fs<<binIns<<'\n';
    }
    else{
      instlist.push_back(binIns);
    }
  }
  else if(op.compare("csr")==0 || op.compare("CSR")==0 || op.compare("Csr")==0){
    binIns+="0111";
    binIns+="100000000000"; // empty bits if necessary
    std::string r=regtobin(rs);
    binIns+=r;
    binIns+=immtobin(imme,1,r);
    if(!repeat_flag){
      fs<<binIns<<'\n';
    }
    else{
      instlist.push_back(binIns);
    }
    
  }
  else if(op.compare("lsl")==0 || op.compare("LSL")==0 || op.compare("Lsl")==0){
    binIns+="1000";
    binIns+="100000000000"; // empty bits if necessary
    std::string r=regtobin(rs);
    binIns+=r;
    binIns+=immtobin(imme,1,r);
    if(!repeat_flag){
      fs<<binIns<<'\n';
    }
    else{
      instlist.push_back(binIns);
    }
    
  }
  else if(op.compare("lsr")==0 || op.compare("LSR")==0 || op.compare("Lsr")==0){
    binIns+="1001";
    binIns+="100000000000"; // empty bits if necessary
    std::string r=regtobin(rs);
    binIns+=r;
    binIns+=immtobin(imme,1,r);
    if(!repeat_flag){
      fs<<binIns<<'\n';
    }
    else{
      instlist.push_back(binIns);
    }
  }
  else{
    std::cout<< "Error at read instruccion: format mnemonic R,Imm only support cmp,mov and shifts"<<'\n';
  }
}

//intruccion op rd,[rs,rm]
//op rd,[rs,#imme] (post index and offset)
void encondig_instruccion4(std::string op,std::string rd,std::string rs,std::string rs2,int type){
  std::string binIns="0000";
  text_memory+=0x4;
  if(op.compare("ldr")==0 || op.compare("Ldr")==0 || op.compare("LDR")==0){
    if(type==1){ //op rd,[r]
      binIns+="1010";
      binIns+="0100000000000000"; // empty bits if necessary
      binIns+=regtobin(rs);
      binIns+=regtobin(rd);
      if(!repeat_flag){
        fs<<binIns<<'\n';
      }
      else{
        instlist.push_back(binIns);
      }
    }else if(type==3){ //op rd,[r,imm]
      if(rs2.find("-")==std::string::npos){ //neg imm
        binIns+="1010";
        binIns+="11000000"; // empty bits if necessary
        binIns+=regtobin(rs);
        binIns+=regtobin(rd);
        binIns+=immtobin(rs2,1,"");
        if(!repeat_flag){
          fs<<binIns<<'\n';
        }
        else{
          instlist.push_back(binIns);
        }
      }else{ //pos imm
        rs2.erase(1,1);
        binIns+="1010";
        binIns+="11000000"; // empty bits if necessary
        binIns+=regtobin(rs);
        binIns+=regtobin(rd);
        binIns+=immtobin(rs2,1,"");
        if(!repeat_flag){
          fs<<binIns<<'\n';
        }
        else{
          instlist.push_back(binIns);
        }
      }
    }
  }else if(op.compare("str")==0 || op.compare("Str")==0 || op.compare("STR")==0){
    if(type==1){ //op rd,[r]
      binIns+="1011";
      binIns+="0100000000000000"; // empty bits if necessary
      binIns+=regtobin(rs);
      binIns+=regtobin(rd);
      if(!repeat_flag){
        fs<<binIns<<'\n';
      }
      else{
        instlist.push_back(binIns);
      }
    }else if(type==3){ //op rd,[r,imm]
      if(rs2.find("-")==std::string::npos){
        binIns+="1011";
        binIns+="11000000"; // empty bits if necessary
        binIns+=regtobin(rs);
        binIns+=regtobin(rd);
        binIns+=immtobin(rs2,1,"");
        if(!repeat_flag){
          fs<<binIns<<'\n';
        }
        else{
          instlist.push_back(binIns);
        }
      }else{
        rs2.erase(1,1);
        binIns+="1011";
        binIns+="11000000"; // empty bits if necessary
        binIns+=regtobin(rs);
        binIns+=regtobin(rd);
        binIns+=immtobin(rs2,1,"");
        if(!repeat_flag){
          fs<<binIns<<'\n';
        }
        else{
          instlist.push_back(binIns);
        }
      }
    }
  }
  else{
    std::cout<< "Error at store/read instruccion: not supported instruction"<<'\n';
  }
}

//Instruccion op #imme
void encondig_instruccion5(std::string op,std::string imme){
  std::string binIns="0000";
  text_memory+=0x4;
  if(op.compare("brt")==0 || op.compare("BRT")==0 || op.compare("Brt")==0){
    repeat_flag = true;
  }
  else if(op.compare("ert")==0 || op.compare("ERT")==0 || op.compare("Ert")==0){
    repeat_flag = false;
    std::string str1= imme.substr(1);
    int imm = std::stoi(str1);
    for(int i = 0 ; i < imm ; i++){
      std::list <std::string> templist = instlist; 
      int size = templist.size();
      for(int j = 0 ; j < size; j++){
        text_memory+=0x4;
        std::string temp1 = templist.front();
        templist.pop_front();
        fs<<temp1<<'\n';
      }
    }
  }
  else{
    std::cout<< "Error at read instruccion: format mnemonic Imm only support repeat operation"<<'\n';
  }
}

//Conversion del numero de registro a binario
std::string regtobin(std::string r){
  r.erase(0,1); //erase 'r'
  std::string bin=std::bitset<4>(atoi(r.c_str())).to_string(); //set 4 bits for number of 'r'
  return bin;
}

//Se guarda el inmediato en binario
//Type= De que tamaño sera el inmediato
std::string immtobin(std::string in,int type,std::string rs){
  in.erase(0,1);
  int x=0;
  if(in.find("0x")==std::string::npos){
    x=strtol(in.c_str(),NULL,10);
  }else{
    x=strtol(in.c_str(),NULL,16);
  }
  if(type==1){
    if(x<4096){
      std::string bin=std::bitset<8>(x).to_string();
      return bin;
    }
  }
}

void yyerror(std::string S){
  final_message="Compiler failed";
  std::cout << S <<" at line: "<<yylineno<<'\n';
  yyclearin;
  exit(0);
}

int main(void) {

  std::cout<<"Ruta del archivo a compilar"<<'\n';
  fs.open ("text_out.txt", std::ios::out | std::ios::trunc); //Intrucciones
  std::cin>>ruta;
  FILE *myfile = fopen(ruta.c_str(), "r");

	//se verifica si es valido
	if (!myfile) {
		std::cout << "No es posible abrir el archivo" << std::endl;
		return -1;
	}

	yyin = myfile;
	do {
		yyparse(); // start yacc
	} while (!feof(yyin)); //condition of finish
  

  fs.close();
  std::cout<<final_message<<'\n';
  for(int i=0;i<100;++i);
}
