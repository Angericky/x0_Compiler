%{
	#include "code.h"
	#include "type.h"
	#include <sys/malloc.h>
	int isconst = 0;
	int isarray = 0;
	int arridx=0;
	int islit=0;
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
	char var;
	char *op;
	struct cx_ins *cx_table;
}

%token MAIN
%token <ident> ID
%token <number> NUM

%token STRING_LITERAL SIZEOF CONSTANT PROCEDURE
%token PTR_OP INC_OP DEC_OP LEFT_OP RIGHT_OP LE_OP GE_OP EQ_OP NE_OP
%token AND_OP OR_OP MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN
%token SUB_ASSIGN LEFT_ASSIGN RIGHT_ASSIGN AND_ASSIGN
%token XOR_ASSIGN OR_ASSIGN TYPE_NAME
%token ODD_EVAL SQRT

%token READ WRITE
%token TYPEDEF EXTERN STATIC AUTO REGISTER
%token <var> CHAR SHORT INT LONG SIGNED UNSIGNED FLOAT DOUBLE CONST VOLATILE VOID
%token STRUCT UNION ENUM ELLIPSIS

%token CASE DEFAULT IF ELSE SWITCH WHILE DO FOR GOTO CONTINUE BREAK RETURN EXIT REPEAT UNTIL CALL
%type <number> var expression simple_expr declaration_id_list declaration_list declaration_stat
%type <var> type definition_stat
%type <cx_table> case_stat_list

%start program
%%

program :
	{lev--;}
	 MAIN 
	 block
	;

block :
	{
		lev++;
		dx=3;
		levelReg[lev].tx0=tx;
		table[tx].adr=cx;
		gen(jmp,0,1);
		if(lev>LEVMAX)
			error(32);
		$<number>$=cx;
		islit=0;
	}
	function_parentheses
	 '{' 
	declaration_list
	{	
		if(islit==1){
			$<number>$=cx;
			gen(jmp,0,0);
			islit=0;
		}
		else
			$<number>$=-1;
	}
	proc_dec_list
	{
		code[table[levelReg[lev].tx0].adr].a=cx;
		table[levelReg[lev].tx0].adr=cx;

		table[levelReg[lev].tx0].size=(struct cx_ins*)malloc(sizeof(struct cx_ins));
		(table[levelReg[lev].tx0].size)->sz=dx;
		(table[levelReg[lev].tx0].size)->next=NULL;
		levelReg[lev].cx0=cx;
		gen(ini,0,dx);
		if($<number>5!=-1){
			gen(jmp,0,$<number>1);
			code[$<number>5].a=cx;
		}
	}
	{printf("here5");}
	statement_list
	{printf("here1");}
	return_stat
	'}'
	;

function_parentheses :
	'(' parameter_list  ')' 
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
		strcpy(id,$2);
		enter(procedur,0);
	}
	{levelReg[lev].dx0=dx;}
	block
	{lev--;
	dx=levelReg[lev].dx0;}
	';'
	;

parameter_list :
    parameter_stat
	| parameter_stat
	',' 
	parameter_list
	|
	;

parameter_stat :
	type declaration_id_list
	;

declaration_stat :
	type 
	declaration_id_list
	';'
	| 
	CONST 
	{isconst=1;}
	constdec_id_list
	{isconst=0;}
	';'
	;


declaration_id_list :
	ID 
	{
		strcpy(id,$1);
		switch(tp){
			case 'i':
				enter(interger,0);
				break;
			case 'c':
				enter(character,0);
				break;
			default:
				error(40);
		}
	}
	definition_stat
	{
		islit=1;
		idx=position(id);
		if($3=='='){
			gen(sto,lev-table[idx].level,table[idx].adr);
		}
	}
	| declaration_id_list ',' ID
	{
		strcpy(id,$3);
		switch(tp){
			case 'i':
				enter(interger,0);
				break;
			case 'c':
				enter(character,0);
				break;
			default:
				error(40);
		}
	}
	definition_stat
	{
		islit=1;
		idx=position(id);
		if($5=='='){
			gen(sto,lev-table[idx].level,table[idx].adr);
		}
	}
	| 
	ID 
	{
		isarray=1;
		printf("\nid=%s\n",id);
		strcpy(id,$1);
	}
	decarraylist
	{
		
		switch(tp){
			case 'i':
				enter(interger,dis);
				break;
			case 'c':
				enter(character,dis);
				break;
			default:
				error(40);
		}
		isarray=0;
		dis=0;
	}
	| declaration_id_list ',' ID {isarray=1;}
	decarraylist
	{
		strcpy(id,$3);
		switch(tp){
			case 'i':
				enter(interger,dis);
				break;
			case 'c':
				enter(character,dis);
				break;
			default:
				error(40);
		}
		isarray=0;
		dis=0;
	}
	| 
constdec_id_list :
	ID
	{strcpy(id,$1);}
	'=' expression
	{
		num=$4;
		enter(constant,num);
	}
	| constdec_id_list ','
	ID
	{strcpy(id,$3);}
	'=' expression
	{
		num=$6;
		enter(constant,num);
	}
	;

type :
	INT {tp='i';}
	| CHAR {tp='c';}
	;

var :
	ID 
	{
		int i;
		strcpy(id,$1);
		i=position(id);
		idx=i;
		if(i==0){
			error(35);
		}
		else{
		 	kind=table[i].kind;
		}
		dis=0;
	}
	| ID {dis=0;arridx=0;strcpy(id,$1);} 
	arraylist
	{
		int i=position(id);
		idx=i;
		if(i==0){
			error(35);
		}
		else{
		 	kind=table[i].kind;
		}
	}
	;

arraylist :
	 '['  expression
	 { 
	 	 if(arridx>0)
			 gen(opr,0,2);
		 int i=position(id);
		 printf("\nread or write id=%s\n",id);
		 int j=0,num;
		 struct SZ* temp=table[i].size;

		 for(j=0;j<arridx;j++){
		 	if(temp==NULL)
		 		error(41);	//数组访问越界
		 	temp=temp->next;
		 }	
		 if(temp==NULL){
			error(44);
		 }
		 else{
		 	if(temp->next!=NULL){
			 	printf("lit\n");
				num=temp->sz;
			 	gen(lit,0,num);
				gen(opr,0,4);
			}
		 }
		 arridx++;
		
	 }
	 ']' 
	 arraylist
	 {
	 	
		int i=position(id);
		idx=i;
		if(i==0)
			error(35);
		else{
		 	kind=table[i].kind;
		}
		if(dis==0){
			dis=$<number>2;
		}
		else
			dis=$<number>2*dis;
	}
	| 
	;

decarraylist :
	 '[' expression ']' 
	{	
		int i=position(id);
		idx=i;
		if(i==0)
			error(35);
		else{
		 	kind=table[i].kind;
		}
		if(dis==0){
			dis=$<number>2;
		}
		else
			dis=$<number>2*dis;
		struct SZ* p=table[i].size,*temp,*q;
		temp=(struct SZ*)malloc(sizeof(struct SZ));
		temp->sz=$<number>2;
		temp->next=NULL;
		if(p==NULL){
			table[i].size=temp;
		}
		else{
			while(p!=NULL){
				q=p;
				p=p->next;
			}
			q->next=temp;
		}
	} 
	decarraylist
	| '[' expression ']'
	{
		int i=position(id);
		idx=i;
		if(i==0)
			error(35);
		else{
		 	kind=table[i].kind;
		}
		if(dis==0)
			dis=$<number>2;
		else
			dis=$<number>2*dis;
		struct SZ* p=table[i].size,*temp,*q;
		temp=(struct SZ*)malloc(sizeof(struct SZ));
		temp->sz=$<number>2;
		temp->next=NULL;
		if(p==NULL)
			table[i].size=temp;
		else{
			while(p!=NULL){
				q=p;
				p=p->next;
			}
			q->next=temp;
		}
		q=table[i].size;
		while(q!=NULL){
			q=q->next;
		}
	}
	;

definition_stat:
	'=' expression 
	{
		$$='=';
	}
	|
	{
		$$='N';
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
	 	cx1=cx;
		gen(jpc,0,0);
	 }
	 if_statement_list
	 ELSE_stat
	 {
	 	code[cx1].a = cx;
	 }
	 ;

ELSE_stat:
	 ELSE 
	 {
	 	cx2=cx;
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
 	 {$<number>$=cx;} 
 	 '(' expression ')' 
 	 {
 	 	$<number>$=cx;
 		gen(jpc,0,0);
 		bcx=0;
	 	ccx=0;
 	 }
 	 do_statement_list
 	 {
 	 	gen(jmp,0,$<number>2);
 	 	code[$<number>6].a=cx;
 	 	if(bcx>0){
 	 		code[bcx].a=cx;
 	 		bcx=0;
 	 	}
 	 	if(ccx>0){
 	 		code[ccx].a=$<number>2;
 	 		ccx=0;
 	 	}
 	 }
 	 ;

do_while_stat :
	 DO 
	 {$<number>$=cx;}
	 do_statement_list
	 WHILE '(' expression ')' 
	 {
	 	gen(jpc,0,0);
	 	gen(jmp,0,$<number>2);
	 	code[cx-2].a=cx;
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
	{ $<number>$=cx; }
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
	 	$<number>$=cx;
	 }
	 simple_expr ';'  
	 {
	 	$<number>$=cx;
	 	gen(jpc,0,0);
	 	gen(jmp,0,0);
	 }
	 expression
	 {
	 	gen(jmp,0,$<number>4);
	 	code[$<number>7+1].a=cx;
	 	bcx=0;
	 	ccx=0;
	 } 
	 ')'
	 for_operation
	 {
	 	gen(jmp,0,$<number>7+2);
	 	code[$<number>7].a=cx;
	 	if(bcx>0){
		 	code[bcx].a=cx;
		 	bcx=0;
	 	}
	 	if(ccx>0){
	 		code[ccx].a=$<number>7+2;
	 		ccx=0;
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
		bcx=cx;
		gen(jmp,0,0);
	}
	;

continue_stat :
	CONTINUE
	{
		ccx=cx;
		gen(jmp,0,0);
	}
	';'
	;

switch_case_stat :
	SWITCH '(' var
	{
		cx2=cx;
		gen(lod,lev-table[idx+dis].level,table[idx+dis].adr);
	}
	')'
	case_list
	;

case_list :
	'{' case_list '}'
	| 
	case_stat_list
	{
		struct cx_ins* temp=$1,* tt;
		while(temp->next!=NULL){
			tt=temp;
			temp=temp->next;
			free(tt);
			code[temp->adr].a=cx;
		}
	}
	;

case_stat_list :
	case_stat_list default_stat
	| case_stat_list case_stat 
	{	
		if(bcx > 0){
			if($$==NULL){
				$$=(struct cx_ins *)malloc(sizeof(struct cx_ins));
				$$->adr=0;
				$$->next = NULL;	
			}
			struct cx_ins * temp,* node;
			node=(struct cx_ins *)malloc(sizeof(struct cx_ins));
			node->next=NULL;
			node->adr=cx-1;
			temp=$$;
			while(temp->next!=NULL)
				temp=temp->next;
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
		$<number>$=cx;
		gen(jpc,0,0);
	}
	statement_list case_break_stat
	{
		code[$<number>4].a=cx;
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
	 WRITE  expression  ';'
	 {	
		 switch(kind){
		 	case interger:
		 		gen(opr,0,14);
		 		break;
		 	case character:
				gen(opr,1,14);
		 		break;
		 	case constant:
				gen(opr,0,14);
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
	 		case interger:
	 			gen(opr,0,16);
	 			break;
	 		case character:
	 			gen(opr,1,16);
	 			break;
	 		default:
	 			error(37);
	 			break;
	 	}
	 	if(dis==0)
			gen(sto,lev-table[idx].level,table[idx].adr);
		else
			gen(sto2,lev-table[idx].level,table[idx].adr);
	 }
	 | readVar ',' var
	 {	
	 	switch(kind){
	 		case interger:
	 			gen(opr,0,16);
	 			break;
	 		case character:
	 			gen(opr,1,16);
	 			break;
	 		default:
	 			error(36);
	 			break;
	 	}
	 	if(dis==0)
			gen(sto,lev-table[idx].level,table[idx].adr);
		else
			gen(sto2,lev-table[idx].level,table[idx].adr);
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
		if(kind!=interger&&kind!=character){
			error(12);
			idx=0;
		}
		$<number>$=idx;
	 } 
	 '=' expression 
	 {
		int i;
		if($<number>2!=0){
			i=$<number>2;
			if(dis==0)
				gen(sto,lev-table[i].level,table[i].adr);
			else
				gen(sto2,lev-table[i].level,table[i].adr);
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
	 	if(dis==0)
			gen(sto,lev-table[idx].level,table[idx].adr);
		else
			gen(sto2,lev-table[idx].level,table[idx].adr);
	 }
	 | additive_expr DEC_OP
	 {
	 	gen(lit,0,1);
	 	gen(opr,0,3);
	 	if(dis==0)
			gen(sto,lev-table[idx].level,table[idx].adr);
		else
			gen(sto2,lev-table[idx].level,table[idx].adr);
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
	 | additive_expr '^' additive_expr
	 {
	 	gen(opr,0,18);
	 }
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
	| ID '(' call_value_stat ')'
	{
		int i;
		strcpy(id,$1);
		i=position(id);
		if(i==0)
			error(11);
		else{
			if(table[i].kind==procedur){
				gen(cal,lev-table[i].level,table[i].adr);
			}
			else
				error(15);
		}
	}
	| factor
	;

call_value_stat :
	call_value_stat ',' factor
	| factor
	;

factor :
	 '(' expression ')'
	 | var
	 {
	 	switch(kind){
	 		case constant:
	 			gen(lit,0,table[idx+dis].val);
	 			break;
	 		case interger:
	 			if(dis==0)
	 				gen(lod,lev-table[idx].level,table[idx].adr);
	 			else
	 				gen(lod2,lev-table[idx].level,table[idx].adr);
	 			break;
	 		case character:
	 			gen(lod,lev-table[idx+dis].level,table[idx+dis].adr);
	 			break;
	 		case procedur:
	 			error(21);
	 			break;
	 	}
	 }
	 | NUM
	 {
	 	int num;
	 	num=$1;
	 	if(num>AMAX){
	 		error(31);
	 		num=0;
	 	}
	 	if(isconst==0&&isarray==0){
			gen(lit,0,num);
		}
	 }
	 ;

exit_stat:
	EXIT ';'
	{gen(ext,0,0);}
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
		printf("%5d %10s %5d %5d %5d ",i,table[i].name,table[i].level,table[i].val,table[i].adr);
		struct SZ *temp = table[i].size;
		while(temp != NULL){
			printf("%d\t",temp->sz);
			temp=temp->next;
		}
		printf("\n");
	}
}

int main(int argc, char** argv)
{
	if(argc!=2){
		printf("argc of command is not 2!");
		return 0;
	}
	if((fa1=fopen("fa1.txt","w"))==NULL){
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
	fname[0]='y';
	fprintf(fa1,"\nList object code?\n");
	if(fname[0]=='y')
		listswitch=true;
	else
		listswitch=false;
	err=0;
	cx=0;
	if((fa=fopen("fa.txt","w"))==NULL){
		printf("Cann't open fa.txt file!\n");
		exit(0);
	}
	if((fa2=fopen("fa2.txt","w"))==NULL){
		printf("Cann't open fa2.txt file!\n");
		exit(0);
	}
	yyparse();
	fclose(fa);
	fclose(fa1);
	listcode();
	interpret();
	print();
	
	if(err!=0)
		printf("%d errors in PL/0 program\n",err);
	fclose(fin);
	return 0;
}
