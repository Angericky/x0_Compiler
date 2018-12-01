#include "table.h"
#include "math.h"
#include "ctype.h"
#define CXMAX 200

int cx,cx1,cx2,cx3,cx4;		/*cx是数组code的索引*/
int temp;
int bcx,ccx;
int err;		/*错误计数器*/

enum fct{lit,opr,lod,lod2,cpy,sto,sto2,cal,ini,jmp,jpc,ext};

char *mnemonic[12]={"lit","opr","lod","lod2","cpy","sto","sto2","cal","ini","jmp","jpc","ext"};

FILE *fa;
FILE *fa1,*fa2;
FILE *fin,*fout;
char fname[AL];

enum listswitcher{f,t};
enum listswitcher listswitch;

struct instruction{
	enum fct f;			/*指令名*/
	int l;				/*级差*/
	int a;				/*操作数*/
	enum object kind;
	int idx;
};
struct instruction code[CXMAX+1];		/*指令码*/

struct stack{
	unsigned char* data;
	enum object kind;
};

extern int line;

void error(int n){
	printf("***");
	fputs("***",fa1);
	printf("error%d",n);
	fprintf(fa1,"error%d",n);
	yyerror("");
}

void gen(enum fct x,int y,int z)
{
	if(cx > CXMAX)
		printf("program too long! cx = %d",cx);
	code[cx].f = x;
	code[cx].l = y;
	code[cx].a = z;
	cx ++;
}

void genk(enum fct x,int y,int z,int idx)
{
	if(cx > CXMAX)
		printf("program too long! cx = %d",cx);
	code[cx].f = x;
	code[cx].l = y;
	code[cx].a = z;
	code[cx].idx = idx;
	code[cx].kind = table[idx].kind;
	cx ++;
}

void listcode( )			/*列出三代码指令表*/
{
	printf("\npcode:\n");
	int i;
	if(listswitch == t){
		for(i = 0;i <= cx-1;i ++){
			printf("%5d\t%5s\t%3d\t%3d\n",i,mnemonic[(int)code[i].f],code[i].l,code[i].a);
			fprintf(fa,"%5d %5s	%3d	%3d\n",i,mnemonic[(int)code[i].f],code[i].l,code[i].a);
			}
		}	
}

int base(int l,int b,struct stack s[STACKSIZE])
{
	int b1;
	b1 = b;
	while(l > 0){
		b1 = byte2int(s[b1].data);
		l = l - 1;
	}
	return b1;
}

void interpret()
{
	int p = 0;
	int b = 1;
	int t = 0;
	int idx1,idx2;
	enum object k1, k2;
	struct instruction i;
	struct stack s[STACKSIZE];
	printf("********Start compiling x0 language.*********\n");
 	fprintf(fa1,"********Start compiling x0 language.*********\n");
	s[0].data = int2byte(0);
	s[1].data = int2byte(0);
	s[2].data = int2byte(0);
	s[3].data = int2byte(0);
	do{
		//printf("   %d  %2d %s %5d %5d\n",t,p,mnemonic[(int)code[p].f],code[p].l,code[p].a);
		//printf("s[t]=%d",byte2int(s[t]));
		i = code[p];
		p = p + 1;
		switch(i.f){
			case lit:								/*将常数取到栈顶*/
				t = t + 1;
				switch(i.l){
					case 0:
						s[t].data = int2byte(i.a);
						s[t].kind = integer;
						break;
					case 1:
						s[t].data = char2byte(byte2char(int2byte(i.a)));
						s[t].kind = character;
						break;
					case 2:
						s[t].data = float2byte(byte2float(int2byte(i.a)));
						s[t].kind = floatnum;
						break;
					case 3:
						s[t].data = int2byte(i.a);
						s[t].kind = boolean;
						break;
				}
				break;
			case opr:
				switch(i.a){
					case 0:							/*无返回值跳出结构体*/
						t = b - 1;
						p = byte2int(s[t + 3].data);
						b = byte2int(s[t + 2].data);
						break;
					case 20:						/*有返回值跳出结构体*/
						s[b] = s[t];
						t = b - 1;
						p = byte2int(s[t + 3].data);
						b = byte2int(s[t + 2].data);
						t ++;
						break;
					case 1:  						 /*取负*/
						if(s[t].kind == integer)
							s[t].data = int2byte(-byte2int(s[t].data));
						else if(s[t].kind == floatnum)
							s[t].data = float2byte(-byte2float(s[t].data));
						else 
							error(52);
						break;
					case 2:							/*相加*/
						t = t - 1;
						k1 = s[t].kind ,k2 = s[t + 1].kind;
						if(k1 == integer && k2 == integer)
							s[t].data = int2byte(byte2int(s[t].data) + byte2int(s[t + 1].data));
						else if(k1 == floatnum && k2 == floatnum)
							s[t].data = float2byte(byte2float(s[t].data) + byte2float(s[t + 1].data));
						else if(k1 == integer && k2 == floatnum){
							s[t].data = float2byte((float)byte2int(s[t].data) + byte2float(s[t + 1].data));
							s[t].kind = floatnum;
						}
						else if(k1 == floatnum && k2 == integer){
							s[t].data = float2byte((float)byte2int(s[t + 1].data) + byte2float(s[t].data));
							s[t].kind = floatnum;
						}
						else
							error(52);
						//printf("+ s[t]=%d\n",s[t]);
						break;
					case 3:							/*相减*/
						t = t - 1;
						k1 = s[t].kind;
						k2 = s[t + 1].kind;
						if(k1 == integer && k2 == integer)
							s[t].data = int2byte(byte2int(s[t].data) - byte2int(s[t + 1].data));
						else if(k1 == floatnum && k2 == floatnum)
							s[t].data = float2byte(byte2float(s[t].data) - byte2float(s[t + 1].data));
						else if(k1 == integer && k2 == floatnum){
							s[t].data = float2byte((float)byte2int(s[t].data) - byte2float(s[t + 1].data));
							s[t].kind = floatnum;
						}
						else if(k1 == floatnum && k2 == integer){
							s[t].data = float2byte(byte2float(s[t].data) - (float)byte2int(s[t + 1].data));
							s[t].kind = floatnum;
						}
						else
							error(52);
						break;
					case 4:							/*相乘*/
						t = t - 1;
						k1 = s[t].kind;
						k2 = s[t + 1].kind;
						//printf("* s[t]=%d\n",s[t]);
						if(k1 == integer && k2 == integer)
							s[t].data = int2byte(byte2int(s[t].data) * byte2int(s[t + 1].data));
						else if(k1 == floatnum && k2 == floatnum)
							s[t].data = float2byte(byte2float(s[t].data) * byte2float(s[t + 1].data));
						else if(k1 == integer && k2 == floatnum){
							s[t].data = float2byte((float)byte2int(s[t].data) * byte2float(s[t + 1].data));
							s[t].kind = floatnum;
						}
						else if(k1 == floatnum && k2 == integer){
							s[t].data = float2byte(byte2float(s[t].data) * (float)byte2int(s[t + 1].data));
							s[t].kind = floatnum;
						}
						else
							error(52);
						break;
					case 5:							/*相除*/
						t = t - 1;
						k1 = s[t].kind;
						k2 = s[t + 1].kind;
						if(k1 == integer && k2 == integer)
							s[t].data = int2byte(byte2int(s[t].data) / byte2int(s[t + 1].data));
						else if(k1 == floatnum && k2 == floatnum)
							s[t].data = float2byte(byte2float(s[t].data) / byte2float(s[t + 1].data));
						else if(k1 == integer && k2 == floatnum){
							s[t].data = float2byte((float)byte2int(s[t].data) / byte2float(s[t + 1].data));
							s[t].kind = floatnum;
						}
						else if(k1 == floatnum && k2 == integer){
							s[t].data = float2byte(byte2float(s[t].data) / (float)byte2int(s[t + 1].data));
							s[t].kind = floatnum;
						}
						else
							error(52);
						break;
					case 6:							/*判断奇偶*/
						if(byte2int(s[t].data) % 2 == 0)
							s[t].data = int2byte(0);
						else
							s[t].data = int2byte(1);
						break;
					case 7:							/*进行switch case中的判断*/
						if(byte2int(s[t - 1].data) == byte2int(s[t].data))
							s[t].data = int2byte(1);
						else
							s[t].data = int2byte(0);
						break;
					case 8:							/*判断两个变量值是否相等*/
						t = t - 1;
						if(byte2int(s[t].data) == byte2int(s[t + 1].data))
							s[t].data = int2byte(1);
						else
							s[t].data = int2byte(0);
						break;
					case 9:							/*判断是否不相等*/
						t = t - 1;
						if(byte2int(s[t].data) == byte2int(s[t + 1].data))
							s[t].data = int2byte(0);
						else
							s[t].data = int2byte(1);
						break;
					case 10:						/*判断是否小于*/
						t --;
						if(byte2int(s[t].data) < byte2int(s[t + 1].data))
							s[t].data = int2byte(1);
						else
							s[t].data = int2byte(0);
						break;
					case 11:						/*判断是否大于等于*/
						t --;
						if(byte2int(s[t].data) >= byte2int(s[t + 1].data))
							s[t].data = int2byte(1);
						else
							s[t].data = int2byte(0);
						break;
					case 12:						/*判断是否大于*/
						t = t - 1;
						if(byte2int(s[t].data) > byte2int(s[t + 1].data))
							s[t].data = int2byte(1);
						else
							s[t].data = int2byte(0);
						break;
					case 13:						/*判断是否小于等于*/
						t = t - 1;
						if(byte2int(s[t].data) <= byte2int(s[t + 1].data))
							s[t].data = int2byte(1);
						else
							s[t].data = int2byte(0);
						break;
					case 14:						/*输出变量值*/
						switch(i.l){
							case 0:
								printf("%d",byte2int(s[t].data));
								fprintf(fa2,"%d",byte2int(s[t].data));
								break;
							case 1:
								printf("%c",byte2char(s[t].data));
								fprintf(fa2,"%c",byte2char(s[t].data));
								break;
							case 2:
								printf("%f",byte2float(s[t].data));
								fprintf(fa2,"%f",byte2float(s[t].data));
								break;
							case 3:
								if(byte2int(s[t].data) == 0)
									printf("false");
								else if(byte2int(s[t].data) == 1)
									printf("true");
								break;			
							default:
								error(52);
						}
						t = t - 1;
						break;
					case 15:							/*打印换行符*/
						printf("\n");
						fprintf(fa2,"\n");
						break;
					case 16:							/*输入变量值*/
						t = t + 1;
						printf("?");
						fprintf(fa2,"?");
						int num;
						char c;
						float f;
						char str[10];
						enum object k;
						switch(i.l){
							case 0:							
								scanf("%d",&num);
								fprintf(fa2,"%d",num);
								s[t].data = int2byte(num);
								k = integer;
								s[t].kind = k;
								//printf("opr num=%d\n",byte2int(s[t].data));
								break;
							case 1:
								scanf("%c",&c);
								while(isspace((char)c))
									scanf("%c",&c);
								fprintf(fa2,"%c",c);
								s[t].data = char2byte(c);
								k = character;
								s[t].kind = k;
								break;
							case 2:
								scanf("%f",&f);
								fprintf(fa2,"%f",f);
								s[t].data = float2byte(f);
								k = floatnum;
								s[t].kind = k;
								break;
							case 3:
								scanf("%s",str);
								fprintf(fa2,"%s",str);
								if(strcmp(str, "false") == 0)
									s[t].data = int2byte(0);
								else if(strcmp(str, "true") == 0)
									s[t].data = int2byte(1);
								break;
							default:
								error(51);
						}
						break;	
					case 17:							/*取余*/
						t = t - 1;
						if(s[t].kind == integer && s[t + 1].kind == integer)
							s[t].data = int2byte(byte2int(s[t].data) % byte2int(s[t + 1].data));
						else
							error(54);
						break;
					case 18:							/*取逆*/
						t = t - 1;
						if(s[t].kind == integer && s[t + 1].kind == integer)
							s[t].data = int2byte(byte2int(s[t].data) ^ byte2int(s[t + 1].data));
						else 
							error(54);
						break;
					case 19:							/*求平方根*/
						if(s[t].kind == integer){
							if(byte2int(s[t].data) < 0)
								error(50);
							s[t].data = int2byte((int)sqrt(byte2int(s[t].data)));
						}
						else
							error(54);
						break;
					case 21:							/*not操作*/
						if(s[t].kind == boolean){
							if(byte2int(s[t].data) == 0)
								s[t].data = int2byte(1);
							else if(byte2int(s[t].data) == 1)
								s[t].data = int2byte(0);
						}
						else
							error(55);
						break;
					case 22:							/*and操作*/
						t = t - 1;
						if(s[t].kind == boolean && s[t + 1].kind == boolean){
							if(byte2int(s[t].data) == 1 && byte2int(s[t + 1].data) == 1)
								s[t].data = int2byte(1);
							else
								s[t].data = int2byte(0);
						}
						else
							error(55);
						break;
					case 23:
						t = t - 1;
						if(s[t].kind == boolean && s[t + 1].kind == boolean){
							if(byte2int(s[t].data) == 0 && byte2int(s[t + 1].data) == 0)
								s[t].data = int2byte(0);
							else
								s[t].data = int2byte(1);
						}
						else
							error(55);
						break;
				}
				break;	
			case lod:						/*将变量的值取到栈顶*/
				t = t + 1;
				//printf("lod data=%d\n",byte2int(s[base(i.l,b,s) + i.a].data));
				idx1 = t;
				idx2 = base(i.l,b,s) + i.a;
				s[idx1].data = s[idx2].data;
				s[idx1].kind = s[idx2].kind;
				//printf("lod s[t]=%d i.l=%d b=%d i.a=%d base(i.l,b,s)=%d\n",byte2int(s[t].data),i.l,b,i.a,base(i.l,b,s));
				break;
			case lod2:						/*将数组中的某个值值取到栈顶*/
				idx1 = t;
				//printf("lod2 adr=%d t=%d base=%d i.a=%d\n",byte2int(s[t].data),t,base(i.l,b,s),i.a);
				if(s[t - 1].kind == integer)
					idx2 = base(i.l,b,s) + i.a + byte2int(s[t].data);
				else if(s[t - 1].kind == floatnum)
					idx2 = base(i.l,b,s) + i.a + (int)byte2float(s[t].data);
				s[idx1].data = s[idx2].data;
				s[idx1].kind = s[idx2].kind;
				//printf("%c\n",byte2char(s[idx2].data));
				break;
			case cpy:
				t = t + 1;
				s[t].data = s[t - i.a - 1].data;
				s[t].kind = s[t - i.a - 1].kind;
				//printf("cp prevt=%d data=%d\n", t-i.a - 1,byte2int(s[t].data));
				break;
			case sto:						/*将栈顶值存进变量*/
				//printf("sto \n");
				idx1 = base(i.l,b,s) + i.a;
				s[idx1].kind = i.kind;
				if(s[t].data == NULL)
					idx2 = base(1,t,s);
				else
					idx2 = t;
				
				//printf("k=%d k2=%d\n",i.kind,s[idx2].kind);
				if(s[idx1].kind == s[idx2].kind)
					s[idx1].data = s[idx2].data;
				else if(s[idx1].kind == integer && s[idx2].kind == floatnum)
					s[idx1].data = int2byte((int)byte2float(s[idx2].data));
				else if(s[idx2].kind == floatnum && s[idx2].kind == integer)
					s[idx1].data = float2byte((float)byte2int(s[idx2].data));
				else
					error(53);
				table[i.idx].val = s[idx1].data;
				table[i.idx].isval = 1;
				t = t - 1;
				break;
			case sto2:						/*将栈顶值存进数组*/
				//printf("adr=%d\n",byte2int(s[t - 1].data));
				if(s[t - 1].kind == integer)
					idx1 = base(i.l,b,s) + i.a + byte2int(s[t - 1].data);
				else if(s[t - 1].kind == floatnum)
					idx1 = base(i.l,b,s) + i.a + (int)byte2float(s[t - 1].data);
				s[idx1].kind = i.kind;

				idx2 = t;
				if(s[idx1].kind == s[idx2].kind)
					s[idx1].data = s[idx2].data;
				else if(s[idx1].kind == integer && s[idx2].kind == floatnum)
					s[idx1].data = int2byte((int)byte2float(s[idx2].data));
				else if(s[idx1].kind == floatnum && s[idx2].kind == integer)
					s[idx1].data = float2byte((float)byte2int(s[idx2].data));
				else
					error(53);
				if(s[t - 1].kind == integer){
					table[i.idx + byte2int(s[t - 1].data)].val = s[idx1].data;
					table[i.idx + byte2int(s[t - 1].data)].isval = 1;
				}
				else if(s[t - 1].kind == floatnum){
					table[i.idx + (int)byte2float(s[t - 1].data)].val = s[idx1].data;
					table[i.idx + byte2int(s[t - 1].data)].isval = 1;
				}
				//printf("sto2 t=%d base=%d s[t]=%d\n",t,byte2int(s[t - 1].data),byte2int(s[t].data));
				t = t - 2;
				break;
			case cal:						/*调用过程*/
				//printf("b=%d i.l=%d p=%d\n",b,i.l,p);
				s[t + 1].data = int2byte(base(i.l,b,s));
				s[t + 1].kind = integer;
				s[t + 2].data = int2byte(b);
				s[t + 2].kind = integer;
				s[t + 3].data = int2byte(p);
				s[t + 3].kind = integer;
				b = t + 1;
				p = i.a;
				break;
			case ini:
				t = t + i.a;
				break;
			case jmp:						/*无条件跳转*/
				p = i.a;
				break;
			case jpc:						/*不相等跳转*/
				if(byte2int(s[t].data) == 0){
					p = i.a;
				}
				t = t - 1;
				break;
			case ext:						/* exit */
				exit(0);
				break;
			}
		}while(p != 0);
		printf("\n******End compiling x0 language.********\n");
		fprintf(fa1,"\n******End compiling x0 language.********\n");
		fclose(fa2);
}