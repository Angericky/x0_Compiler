%{
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
%}

%union{
	char *ident;
	int number;
	float floatnum;
	char character;
	char vartype;
	char *op;
	struct cx_ins *cx_table;
}

%token MAIN
%token <ident> ID
%token <number> NUM TRUE FALSE
%token <floatnum> FLOATNUM
%token <character> CHARACTER

%token STRING_LITERAL CONSTANT PROCEDURE
%token PTR_OP INC_OP DEC_OP LEFT_OP RIGHT_OP LE_OP GE_OP EQ_OP NE_OP
%token AND_OP OR_OP MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN
%token SUB_ASSIGN LEFT_ASSIGN RIGHT_ASSIGN AND_ASSIGN
%token XOR_ASSIGN OR_ASSIGN TYPE_NAME
%token ODD_EVAL SQRT

%token READ WRITE
%token TYPEDEF EXTERN STATIC AUTO REGISTER
%token <vartype> CHAR INT LONG UNSIGNED FLOAT DOUBLE CONST VOLATILE VOID BOOLEAN
%token STRUCT UNION ENUM ELLIPSIS

%token CASE DEFAULT IF ELSE SWITCH WHILE DO FOR GOTO CONTINUE BREAK RETURN EXIT REPEAT UNTIL CALL
%type <number> var expression simple_expr declaration_id_list declaration_list declaration_stat
%type <vartype> type definition_stat
%type <cx_table> case_stat_list

%start program
%%

program :
	{lev --;}
	 MAIN 
	 block
	;

block :
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
		$<number>$ = cx;
		islit = 0;
		iscall = 0;
	}
	function_parentheses
	{
		printf("call_cx=%d cx=%d\n",call_cx,cx);
		$<number>$ = cx - call_cx - 1;
	}
	 '{' 
	declaration_list
	{	
		if(islit == 1){
			$<number>$ = cx;
			gen(jmp,0,0);
			islit = 0;
			//printf("\njmp\n");
		}
		else
			$<number>$ = -1;
	}
	proc_dec_list
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

		printf("\n<number>3=%d\n",$<number>3);
		int temp = $<number>3;
		int i = 0;
		while(temp - i > 0){
			gen(cpy, lev - table[proc_id].level,dx + 2 * i);
			i ++;
		}

		if(iscall == 1){
			iscall = 0;
		}
		if($<number>6 != -1){
			gen(jmp,0,$<number>1);
			code[$<number>6].a = cx;
		}
	}
	statement_list
	return_stat
	'}'
	;

function_parentheses :
	'(' {printf("\nfunction parenthheses\n"); } parameter_list  {printf("\n4444\n");} ')' 
	{ iscall = 1; }
	|
	;

return_stat :
	RETURN  factor
	';' {gen(opr,0,20);}
	| {gen(opr,0,0);}
	;

declaration_list :
	declaration_list declaration_stat
	| declaration_stat
	|
	;

proc_dec_list :
	proc_dec_stat proc_dec_list
	|
	;

proc_dec_stat :
	PROCEDURE
	ID
	{
		call_cx = cx; 
		strcpy(id,$2);
		enter(procedur,0);
		$<number>$ = proc_id;
		proc_id = position(id);
	}
	{levelReg[lev].dx0 = dx;}
	block
	{
		lev --;
		dx = levelReg[lev].dx0;
		proc_id = $<number>3;
	}
	';'
	;

parameter_list :
	parameter_stat {printf("\nhere1\n");} ',' {printf("\n,\n"); }
	parameter_list
	| parameter_stat {printf("end\n");}
	|
	;


parameter_stat :
	type declaration_id
	{
		printf("\nin stat\n");
		if(dis == 0)
			genk(sto,lev - table[idx].level,table[idx].adr, idx);
		else
			genk(sto2,lev - table[idx].level,table[idx].adr, idx);
	} 
	;

declaration_stat :
	type 
	declaration_id_list
	';'
	| 
	CONST 
	{isconst = 1;}
	constdec_id_list
	{isconst = 0;}
	';'
	;

declaration_id_list :
	declaration_id
	| declaration_id_list ',' declaration_id
	;
 
constdec_id_list :
	ID
	{strcpy(id,$1);}
	'=' expression
	{
		num = $4;
		enter(constant,num);
	}
	| constdec_id_list ','
	ID
	{strcpy(id,$3);}
	'=' expression
	{
		num = $6;
		enter(constant,num);
	}
	;

declaration_id :
	ID 
	{
		strcpy(id,$1);
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
		$<number>$ = position(id);
	}
	definition_stat
	{
		islit = 1;
		idx = position(id);
		if($3 == '='){
			//printf("sto idx=%d\n",idx);
			genk(sto,lev - table[idx].level,table[idx].adr, $<number>2);
		}
	}
	|
	ID 
	{
		isarray = 1;
		printf("\nid = %s\n",id);
		strcpy(id,$1);
	}
	decarraylist
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
	}
	;

type :
	INT { tp = 'i'; }
	| CHAR { tp = 'c'; }
	| FLOAT { tp = 'f'; }
	| BOOLEAN { tp = 'b'; }
	;

var :
	ID 
	{
		int i;
		strcpy(id,$1);
		i = position(id);
		idx = i;
		if(i == 0){
			error(35);
		}
		else{
		 	kind = table[i].kind;
		}
		dis = 0;
	}
	| ID {dis = 0;arridx = 0;strcpy(id,$1);} 
	arraylist
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
	}
	;

arraylist :
	 '['  expression
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
	 }
	 ']' 
	 arraylist
	 {
		int i = position(id);
		idx = i;
		if(i == 0)
			error(35);
		else{
		 	kind = table[i].kind;
		}
		if(dis == 0){
			dis = $<number>2;
		}
		else{
			dis = $<number>2*dis;
		}
	}
	| 
	;

decarraylist :
	 '[' expression ']' 
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
			dis = $<number>2;
		}
		else{
			dis = $<number>2*dis;
		}
		struct SZ* p = table[i].size,*temp,*q;
		temp = (struct SZ*)malloc(sizeof(struct SZ));
		temp->sz = $<number>2;
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
	} 
	decarraylist
	| '[' expression ']'
	{
		int i = position(id);
		idx = i;
		if(i == 0)
			error(35);
		else{
		 	kind = table[i].kind;
		}
		if(dis == 0)
			dis = $<number>2;
		else
			dis = $<number>2*dis;
		struct SZ* p = table[i].size,*temp,*q;
		temp = (struct SZ*)malloc(sizeof(struct SZ));
		temp->sz = $<number>2;
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
	}
	;

definition_stat:
	'=' expression 
	{
		$$ = '=';
	}
	|
	{
		$$ = 'N';
	}
	;

statement_list :
	statement_list statement
	| statement
	| 
	;

statement :
	if_stat 
	| while_stat
	| do_while_stat
	| repeat_until_stat
	| for_stat
	| switch_case_stat
	| read_stat
	| write_stat 
	{gen(opr,0,15);}
	| compound_stat
	| expression_stat 
	| exit_stat
	;


if_stat :
	 IF '(' expression ')'
	 {
	 	$<number>$ = cx;
		gen(jpc,0,0);
	 }
	 if_statement_list
	 ELSE_stat
	 {
	 	code[$<number>5].a = cx;
	 }
	 ;

ELSE_stat:
	 ELSE 
	 {
	 	cx2 = cx;
	 	gen(jmp,0,0);
	 	code[cx1].a = cx;
	 }
	 if_statement_list
	 {
	 	code[cx2].a = cx;
	 }
	 |
	 ;

if_statement_list:
	'{'
		if_statement_list if_statement
	'}'
	| if_statement
	|
	;

if_statement:
	break_stat
	| continue_stat 
	| statement
	;

while_stat :
 	 WHILE
 	 {$<number>$ = cx;} 
 	 '(' expression ')' 
 	 {
 	 	$<number>$ = cx;
 		gen(jpc,0,0);
 		bcx = 0;
	 	ccx = 0;
 	 }
 	 do_statement_list
 	 {
 	 	gen(jmp,0,$<number>2);
 	 	code[$<number>6].a = cx;
 	 	if(bcx > 0){
 	 		code[bcx].a = cx;
 	 		bcx = 0;
 	 	}
 	 	if(ccx > 0){
 	 		code[ccx].a = $<number>2;
 	 		ccx = 0;
 	 	}
 	 }
 	 ;

do_while_stat :
	 DO 
	 {
	 	$<number>$ = cx;
	 }
	 do_statement_list
	 WHILE '(' expression ')' 
	 {
	 	gen(jpc,0,0);
	 	gen(jmp, 0,$<number>2);
	 	code[cx-2].a = cx;
	 	if(bcx > 0){
 	 		code[bcx].a = cx;
 	 		bcx = 0;
 	 	}
 	 	if(ccx > 0){
 	 		code[ccx].a = $<number>2;
 	 		ccx = 0;
 	 	}
	 }
	 ';'
	 ;

do_statement_list :
	'{' do_statement_list do_statement '}'
	| do_statement
	|
	;

do_statement :
	statement
	| break_stat
	| continue_stat
	;

repeat_until_stat :
	REPEAT
	{$<number>$ = cx;}
	do_statement_list
	UNTIL
	'(' expression ')'
	{
	 	gen(jpc,0,$<number>2);
	 	gen(jmp,0,cx+1);
	}
	';'
	;

for_stat :
	 FOR '(' expression_stat 
	 {
	 	$<number>$ = cx;
	 }
	 simple_expr ';'  
	 {
	 	$<number>$ = cx;
	 	gen(jpc,0,0);
	 	gen(jmp,0,0);
	 }
	 expression
	 {
	 	gen(jmp,0,$<number>4);
	 	code[$<number>7+1].a = cx;
	 	bcx = 0;
	 	ccx = 0;
	 } 
	 ')'
	 for_operation
	 {
	 	gen(jmp,0,$<number>7 + 2);
	 	code[$<number>7].a = cx;
	 	if(bcx > 0){
		 	code[bcx].a = cx;
		 	bcx = 0;
	 	}
	 	if(ccx > 0){
	 		code[ccx].a = $<number>7 + 2;
	 		ccx = 0;
	 	}
	 }
	 ;

for_operation :
	'{' for_opstatlist '}'
	| statement
	| break_stat
	;

for_opstatlist:
	for_opstatlist for_opstat
	| for_opstat
	;

for_opstat:
	statement
	| break_stat
	| continue_stat
	;

break_stat :
	BREAK ';'
	{
		bcx = cx;
		printf("\nbcx=%d\n",bcx);
		gen(jmp,0,0);
	}
	;

continue_stat :
	CONTINUE
	{
		ccx = cx;
		gen(jmp,0,0);
	}
	';'
	;

switch_case_stat :
	SWITCH '(' var
	{
		cx2 = cx;
		gen(lod,lev - table[idx + dis].level,table[idx + dis].adr);
	}
	')'
	case_list
	;

case_list :
	'{' case_list '}'
	| 
	case_stat_list
	{
		struct cx_ins* temp = $1,* tt;
		while(temp->next != NULL){
			tt = temp;
			temp = temp->next;
			free(tt);
			//printf("num=%d\n",temp->adr);
			code[temp->adr].a = cx;
		}
	}
	;

case_stat_list :
	case_stat_list default_stat
	| case_stat_list case_stat 
	{	
		if(bcx > 0){
			if($$ == NULL){
				$$ = (struct cx_ins *)malloc(sizeof(struct cx_ins));
				$$->adr = 0;
				$$->next = NULL;	
			}
			struct cx_ins * temp,* node;
			node = (struct cx_ins *)malloc(sizeof(struct cx_ins));
			node->next = NULL;
			node->adr = cx-1;
			temp = $$;
			while(temp->next != NULL)
				temp = temp->next;
			temp->next = node;
			code[bcx].a = cx;
			bcx = 0;
		}
	}
	|
	;

case_stat :
	CASE case_num ':'
	{	
		gen(opr,0,7);
		$<number>$ = cx;
		gen(jpc,0,0);
	}
	statement_list case_break_stat
	{
		code[$<number>4].a = cx;
	}
	;

case_break_stat	:
	break_stat
	|
	;

case_num :
	NUM
	{gen(lit,0,$1);}
	;

default_stat :
	DEFAULT ':'
	statement
	;

write_stat : 
	 WRITE {printf("write_stat\n");} expression {printf("expression\n");} ';'
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
	 }
	 ;

read_stat :
	 READ
	  readVar  ';'
	 ;

readVar :
	 var
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
	 }
	 | readVar ',' var
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
	 }
	 ;

compound_stat : 
	 '{' statement_list '}'
	 ;

expression_stat : 
	 expression  ';' 
	 | ';'
	 ;

expression : 
	 var
	 {
		if(kind != integer && kind != character && kind != floatnum && kind != boolean){
			error(12);
			idx = 0;
		}
		$<number>$ = idx;
	 } 
	 '=' expression 
	 {
		int i;
		if($<number>2 != 0){
			i = $<number>2;
			if(dis == 0)
				genk(sto,lev - table[i].level,table[i].adr, $<number>2);
			else
				genk(sto2,lev - table[i].level,table[i].adr, $<number>2);
		}
	 }
	 | simple_expr
	 ;

simple_expr : 
	 additive_expr 
	 | additive_expr INC_OP
	 {
	 	gen(lit,0,1);
	 	gen(opr,0,2);
	 	if(dis == 0)
			genk(sto,lev - table[idx].level,table[idx].adr, idx);
		else
			genk(sto2,lev - table[idx].level,table[idx].adr, idx);
	 }
	 | additive_expr DEC_OP
	 {
	 	gen(lit,0,1);
	 	gen(opr,0,3);
	 	if(dis == 0)
			genk(sto,lev - table[idx].level,table[idx].adr, idx);
		else
			genk(sto2,lev - table[idx].level,table[idx].adr, idx);
	 }
	 | additive_expr '>' additive_expr
	 { gen(opr,0,12); }
	 | additive_expr '<' additive_expr
	 { gen(opr,0,10); }
	 | additive_expr LE_OP additive_expr
	 { gen(opr,0,13); }
	 | additive_expr GE_OP additive_expr
	 { gen(opr,0,11); }
	 | additive_expr EQ_OP additive_expr
	 { gen(opr,0,8); }
	 | additive_expr NE_OP additive_expr
	 { gen(opr,0,9); }
	 | '!' additive_expr
	 { gen(opr,0,21); }
	 | additive_expr AND_OP additive_expr
	 { gen(opr,0,22); }
	 | additive_expr OR_OP additive_expr
	 { gen(opr,0,23); }
	 | additive_expr '^' additive_expr
	 { gen(opr,0,18); }
	 ;


additive_expr :
	 additive_expr '+' term  
	 	{gen(opr,0,2);}
	 | additive_expr '-' term 
	 	{gen(opr,0,3);}
	 | term
	 ;

term :
	 term '*' function
	 	{gen(opr,0,4);}
	 | term '/' function
	 	{gen(opr,0,5);}
	 | term '%' function
	 	{gen(opr,0,17);}
	 | function
	 ;

function :
	ODD_EVAL '(' factor ')' 
	{gen(lit,0,2);
	gen(opr,0,17);}
	| SQRT '(' factor ')'
	{
		gen(opr,0,20);	
	}
	| ID '(' 
	call_value_list ')'
	{
		int i;
		strcpy(id,$1);
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
	}
	| factor
	;


call_value_list :
	  call_value_list ',' call_value_stat
	| call_value_stat
	|
	;

call_value_stat :
	var
	{	
	 	if(dis == 0)
			gen(lod,lev - table[idx].level,table[idx].adr);
		else
			gen(lod2,lev - table[idx].level,table[idx].adr);
	}
	;

factor :
	 '(' expression ')'
	 | var
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
	 }
	 | NUM
	 {
	 	int num;
	 	num = $1;
	 	if(num > AMAX){
	 		error(31);
	 		num = 0;
	 	}
	 	if(isconst == 0 && isarray == 0){
			gen(lit,0,num);
		}
	 }
	 | CHARACTER
	 {
	 	if(isconst == 0 && isarray == 0){
			gen(lit,1, byte2int(char2byte($1)));
		}
	 }
	 | FLOATNUM
	 {
	 	float num;
	 	num = $1;
	 	if(num > AMAX){
	 		error(31);
	 		num = 0;
	 	}
	 	if(isconst == 0 && isarray == 0){
			gen(lit,2, byte2int(float2byte(num)));
		}
	 }
	 | TRUE 
	 { 
	 	if(isconst == 0 && isarray == 0){
	 		gen(lit,3,1);
	 	}
	 }
	 | FALSE
	 {
	 	if(isconst == 0 && isarray == 0){
	 		gen(lit,3,0);
	 	}
	 }
	 ;

exit_stat:
	EXIT ';'
	{ gen(ext,0,0); }
	;

%%

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