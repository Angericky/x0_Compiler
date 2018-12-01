D			[0-9]
L			[a-zA-Z_]
H			[a-fA-F0-9]
E			[Ee][+-]?{D}+
FS			(f|F|l|L)
IS			(u|U|l|L)*

%{
	#include "x0.tab.h"
	int line = 0;
	void count();
	int yywrap(void);
	void yyerror(char *);
	void redirectInput(FILE*);
	void comment();
	void comment_inline();
	#include "string.h"
%}

%%
"/*"			{ count(); comment(); }
"//"			{ count(); comment_inline();}
"&&"			{ count(); return(AND_OP); }
"||"			{ count(); return(OR_OP); }
"auto"			{ count(); return(AUTO); }
"boolean"			{ count();
				  yylval.vartype = 'b';
				  return(BOOLEAN);
				}
"break"			{ count(); return(BREAK); }
"call"			{ count(); return(CALL); }
"case"			{ count(); return(CASE); }
"char"			{ count();
				  yylval.vartype = 'c';
				  return(CHAR);
				}
"const"			{ count();
				  yylval.vartype = 't';
				  return(CONST);
				}
"continue"		{ count(); return(CONTINUE); }
"default"		{ count(); return(DEFAULT); }
"do"			{ count(); return(DO); }
"double"		{ count(); return(DOUBLE); }
"else"			{ count(); return(ELSE); }
"enum"			{ count(); return(ENUM); }
"extern"		{ count(); return(EXTERN); }
"false"			{ count(); return(FALSE); }
"float"			{ count();
				  yylval.vartype = 'f';
				  return(FLOAT);
				}
"for"			{ count(); return(FOR); }
"goto"			{ count(); return(GOTO); }
"if"			{ count(); return(IF); }
"int"			{ count();
				  yylval.vartype = 'i';
				  return(INT);
				}
"long"			{ count(); return(LONG); }
"main"			{ count(); return(MAIN); }
"ODD"			{ count(); return(ODD_EVAL); }
"read"			{ count(); return(READ);}
"register"		{ count(); return(REGISTER); }
"repeat"		{ count(); return(REPEAT); }
"return"		{ count(); return(RETURN); }
"sqrt"			{ count(); return(SQRT); }
"static"		{ count(); return(STATIC); }
"struct"		{ count(); return(STRUCT); }
"switch"		{ count(); return(SWITCH); }
"true"			{ count(); return(TRUE); }
"typedef"		{ count(); return(TYPEDEF); }
"union"			{ count(); return(UNION); }
"unsigned"		{ count(); return(UNSIGNED); }
"until"			{ count(); return(UNTIL); }
"void"			{ count(); return(VOID); }
"volatile"		{ count(); return(VOLATILE); }
"while"			{ count(); return(WHILE); }
"write"			{ count(); return(WRITE);}
"exit"			{ count(); return(EXIT); }
"procedure"		{ count(); return(PROCEDURE);}

"..."			{ count(); return(ELLIPSIS); }
">>="			{ count(); return(RIGHT_ASSIGN); }
"<<="			{ count(); return(LEFT_ASSIGN); }
"+="			{ count(); return(ADD_ASSIGN); }
"-="			{ count(); return(SUB_ASSIGN); }
"*="			{ count(); return(MUL_ASSIGN); }
"/="			{ count(); return(DIV_ASSIGN); }
"%="			{ count(); return(MOD_ASSIGN); }
"&="			{ count(); return(AND_ASSIGN); }
"^="	 	    { count(); return(XOR_ASSIGN); }
"|="			{ count(); return(OR_ASSIGN); }
">>"			{ count(); return(RIGHT_OP); }
"<<"			{ count(); return(LEFT_OP); }
"++"			{ count(); return(INC_OP); }
"--"			{ count(); return(DEC_OP); }
"<="			{ count(); return(LE_OP); }
">="			{ count(); return(GE_OP); }
"=="			{ count(); return(EQ_OP); }
"!="			{ count(); return(NE_OP); }
";"			{ count(); return(';'); }
"%"			{ count(); return('%'); }
("{"|"<call%")		{ count(); return('{'); }
("}"|"%>")		{ count(); return('}'); }
","			{ count(); return(','); }
":"			{ count(); return(':'); }
"="			{ count(); return('='); }
"("			{ count(); return('('); }
")"			{ count(); return(')'); }
("["|"<:")		{ count(); return('['); }
("]"|":>")		{ count(); return(']'); }
"."			{ count(); return('.'); }
"&"			{ count(); return('&'); }
"!"			{ count(); return('!'); }
"~"			{ count(); return('~'); }
"-"			{ count(); return('-'); }
"+"			{ count(); return('+'); }
"*"			{ count(); return('*'); }
"/"			{ count(); return('/'); }
"<"			{ count(); return('<'); }
">"			{ count(); return('>'); }
"^"			{ count(); return('^'); }
"|"			{ count(); return('|'); }
"?"			{ count(); return('?'); }

{L}({L}|{D})*		{ count();
						yylval.ident=(char *)malloc(strlen(yytext)+1);
						strcpy(yylval.ident,yytext);
						return(ID);
					}

0[xX]{H}+{IS}?		{ count();
					  return(NUM);
					}

\'.\'			{ count();
					yylval.character = yytext[1];
					return(CHARACTER);
				}

{D}+\.{D}+		{ count();
				  yylval.floatnum = atof(yytext);
				  return(FLOATNUM);
				}

0{D}+{IS}?		{ count(); return(NUM); }
{D}+{IS}?		{ count();
	yylval.number = atoi(yytext);
	return(NUM); }
L?'(\\.|[^\\'])+'	{ count(); return(CONSTANT); }

{D}+{E}{FS}?		{ count(); return(CONSTANT); }
{D}*"."{D}+({E})?{FS}?	{ count(); return(CONSTANT); }
{D}+"."{D}*({E})?{FS}?	{ count(); return(CONSTANT); }

L?\"(\\.|[^\\"])*\"	{ count(); return(STRING_LITERAL); }

[\n]		{count();line++;}
[ \t\v\f]		{ count(); }
.			{ yyerror("unknown character"); }

%%

int yywrap(void)
{
	return(1);
}

void redirectInput(FILE* input){
	yyin = input;
}

int yygetchar(void){
	int ret;
	ret=getc(yyin);
	printf("%c",ret);
	return ret;
}

void comment()
{
	char c, c1;

loop:
	while ((c = input()) != '*' && c != 0);
		putchar(c);

	putchar(c);

	if ((c1 = input()) != '/' && c != 0)
	{
		unput(c1);
		goto loop;
	}

	if (c != 0)
		putchar(c1);

}

void comment_inline(){
	char c,c1;

	while((c = input()) != '\n' && c != 0);
		//putchar(c);

}

int column = 0;

void count()
{
	int i;

	for (i = 0; yytext[i] != '\0'; i++)
		if (yytext[i] == '\n')
			column = 0;
		else if (yytext[i] == '\t')
			column += 8 - (column % 8);
		else
			column++;
	ECHO;
}


int check_type()
{
/*
* pseudo code --- this is what it should check
*
*	if (yytext == type_name)
*		return(TYPE_NAME);
*
*	return(IDENTIFIER);
*/

/*
*	it actually will only return IDENTIFIER
*/

    return 0;
}