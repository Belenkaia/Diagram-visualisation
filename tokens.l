
D			[0-9]
L			[a-zA-Z_]
H			[a-fA-F0-9]
E			[Ee][+-]?{D}+
FS			(f|F|l|L)
IS			(u|U|l|L)*

%{
#include <string>
#include "common.h"
#include "parser.hpp"

#define SAVE_TOKEN yylval.string = new std::string(yytext, yyleng)
#define TOKEN(t) (yylval.token = t)

%}

%option noyywrap

%%

" "+					;
"\t"					;
"\n"					line_num++; 		

"PROGR"					return TOKEN(TPROGR			);
"TACT"					return TOKEN(TTACT			);
"CONST"					return TOKEN(TCONST			);
"ENUM"					return TOKEN(TENUM			);
"PROC"					return TOKEN(TPROC			);
"FROM"					return TOKEN(TFROM			);
"STATE"					return TOKEN(TSTATE			);
"SWITCH"				return TOKEN(TSWITCH		);
"CASE"					return TOKEN(TCASE			);
"BREAK"					return TOKEN(TBREAK			);
"IF"					return TOKEN(TIF			);
"ELSE"					return TOKEN(TELSE			);
"START"					return TOKEN(TSTART			);
"STOP"					return TOKEN(TSTOP			);
"ERROR"					return TOKEN(TERROR			);
"RESTART"				return TOKEN(TRESTART		);
"LOOP"					return TOKEN(TLOOP			);
"SET"					return TOKEN(TSET			);
"NEXT"					return TOKEN(TNEXT			);
"RESET"					return TOKEN(TRESET			);
"TIMEOUT"				return TOKEN(TTIMEOUT		);
"IN"					return TOKEN(TIN			);
"IS"					return TOKEN(TIS			);
"ACTIVE"				return TOKEN(TACTIVE		);
"INACTIVE"				return TOKEN(TINACTIVE		);

"INPUT"					{SAVE_TOKEN;return TINPUT;		}
"OUTPUT"				{SAVE_TOKEN;return TOUTPUT;		}
"LOCAL"					{SAVE_TOKEN;return TLOCAL;		}
"FOR"					{SAVE_TOKEN;return TFOR;		}
"ALL"					{SAVE_TOKEN;return TALL;		}

"BOOL"					{SAVE_TOKEN;return TBOOL;		}
"VOID"					{SAVE_TOKEN;return TVOID;		}
"FLOAT"					{SAVE_TOKEN;return TFLOAT;		}
"DOUBLE"				{SAVE_TOKEN;return TDOUBLE;		}
"SIGNED"				{SAVE_TOKEN;return TSIGNED;		}
"UNSIGNED"				{SAVE_TOKEN;return TUNSIGNED;	}
"SHORT"					{SAVE_TOKEN;return TSHORT;		}
"LONG"					{SAVE_TOKEN;return TLONG;		}
"INT"					{SAVE_TOKEN;return TINT;		}

{L}({L}|{D})*			{SAVE_TOKEN; return TIDENTIFIER	;}

0[xX]{H}+{IS}?			{SAVE_TOKEN; return TICONST; /*hex*/}
0{D}+{IS}?				{SAVE_TOKEN; return TICONST; /*oct*/}
{D}+{IS}?				{SAVE_TOKEN; return TICONST; /*dec*/}

{D}+{E}{FS}?			{SAVE_TOKEN; return TFCONST; }
{D}*"."{D}+({E})?{FS}?	{SAVE_TOKEN; return TFCONST; }
{D}+"."{D}*({E})?{FS}?	{SAVE_TOKEN; return TFCONST; }

";"						 			return TSEMIC		;
"{"									return TLBRACE		;
"}"									return TRBRACE		;
"("									return TLPAREN		;
")"									return TRPAREN		;
"["									return TLBRACKET	;
"]"									return TRBRACKET	;
":"									return TCOLON		;

"="						{SAVE_TOKEN; return TASSGN		;}
","						{SAVE_TOKEN; return TCOMMA		;}
"."						{SAVE_TOKEN; return TPERIOD		;}
"&"						{SAVE_TOKEN; return TAND		;}
"!"						{SAVE_TOKEN; return TNOT		;}
"~"						{SAVE_TOKEN; return TTILDE		;}
"-"						{SAVE_TOKEN; return TMINUS		;}
"+"						{SAVE_TOKEN; return TPLUS		;}
"*"						{SAVE_TOKEN; return TMUL		;}
"/"						{SAVE_TOKEN; return TDIV		;}
"%"						{SAVE_TOKEN; return TPERC		;}
"<"						{SAVE_TOKEN; return TLT			;}
">"						{SAVE_TOKEN; return TGT			;}
"^"						{SAVE_TOKEN; return TXOR		;}
"|"						{SAVE_TOKEN; return TOR			;}
"?"						{SAVE_TOKEN; return TQMARK		;}
"=="                    {SAVE_TOKEN; return TEQ			;}
"!="                    {SAVE_TOKEN; return TNEQ		;}
"<="                    {SAVE_TOKEN; return TLE			;}
">="                    {SAVE_TOKEN; return TGE			;}
"++"					{SAVE_TOKEN; return TINC		;}
"--"					{SAVE_TOKEN; return TDEC		;}
">>"					{SAVE_TOKEN; return TRSHIFT		;}
"<<"					{SAVE_TOKEN; return TLSHIFT		;}
"||"					{SAVE_TOKEN; return TLOR		;}
"&&"					{SAVE_TOKEN; return TLAND		;}
">>="					{SAVE_TOKEN; return TR_ASSGN	;}
"<<="					{SAVE_TOKEN; return TL_ASSGN	;}
"+="					{SAVE_TOKEN; return TPLUS_ASSGN	;}
"-="					{SAVE_TOKEN; return TMINUS_ASSGN;}
"*="					{SAVE_TOKEN; return TSTAR_ASSGN	;}
"/="					{SAVE_TOKEN; return TDIV_ASSGN	;}
"%="					{SAVE_TOKEN; return TPERC_ASSGN	;}
"&="					{SAVE_TOKEN; return TAND_ASSGN	;}
"^="					{SAVE_TOKEN; return TXOR_ASSGN	;}
"|="					{SAVE_TOKEN; return TOR_ASSGN	;}
										   
.                       printf("Unknown token \n"); yyterminate();
										   
%%										   

