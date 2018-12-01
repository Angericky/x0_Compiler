#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "type.h"
//#include "stdbool.h"

#define TXMAX 100	/*名字表容量*/
#define AL 100		/*读入文件的最大长度*/
#define LEVMAX 10	/*最大允许过程嵌套声明层数*/
#define AMAX 2047	/*地址上届*/
#define STACKSIZE 500

int lev = 0;
int tx = 0;
int dx = 0;
int num;
int dis = 0;
int proc_id = 0;		/*当前函数在table中的idx*/

char id[AL];

enum object{constant, boolean, integer, character, floatnum, procedur};
enum object kind;
int idx = 0;

void error(int);

struct SZ
{
    int sz;
    struct SZ* next;
};

struct table1{
	char name[AL];	/*名字*/
	enum object kind;	/*类型*/
	int level,adr;		/*所处层，地址，需要分配的数据区空间*/
	unsigned char* val;    		/*数值*/
	struct SZ *size;
	int isval;
};
struct table1 table[TXMAX+1];	/*名字表*/

struct levelReg1{
	int dx0;
	int tx0;
	int cx0;
};
struct levelReg1 levelReg[LEVMAX+1];

void enter(enum object k,int num){
	tx = tx + 1;
	strcpy(table[tx].name,id);
	table[tx].kind = k;
	printf("\nkind=%d\n",k);
	switch(k)
		{
		case constant:
			if(num > AMAX){
				error(31);
				num = 0;
			}
			table[tx].val = byte2int(num);
			break;
		case boolean:
			table[tx].level = lev;
			table[tx].adr = dx;
			table[tx].isval = 0;
			dx ++;
			for(int i = 1;i < num;i ++){		/*数组*/
				tx = tx + 1;
				strcpy(table[tx].name,id);
				table[tx].level = lev;
				table[tx].adr = dx;
				table[tx].kind = k;
				table[tx].isval = 0;
				dx ++;
			}
		case integer:
			table[tx].level = lev;
			table[tx].adr = dx;
			dx ++;
			table[tx].isval = 0;
			for(int i = 1;i < num;i ++){		/*数组*/
				tx = tx + 1;
				strcpy(table[tx].name,id);
				table[tx].level = lev;
				table[tx].adr = dx;
				table[tx].kind = k;
				table[tx].isval = 0;
				dx ++;
			}
			break;
		case character:
			table[tx].level = lev;
			table[tx].adr = dx;
			table[tx].isval = 0;
			dx ++;
			for(int i = 1;i < num;i ++){		/*数组*/
				tx = tx + 1;
				strcpy(table[tx].name,id);
				table[tx].level = lev;
				table[tx].adr = dx;
				table[tx].kind = k;
				table[tx].isval = 0;
				dx ++;
			}
			break;
		case floatnum:
			table[tx].level = lev;
			table[tx].adr = dx;
			table[tx].isval = 0;
			dx ++;
			for(int i = 1;i < num;i ++){		/*数组*/
				tx = tx + 1;
				strcpy(table[tx].name,id);
				table[tx].level = lev;
				table[tx].adr = dx;
				table[tx].kind = k;
				table[tx].isval = 0;
				dx ++;
			}			
			break;
		case procedur:
			table[tx].level = lev;
			table[tx].isval = 0;
			break;
		}
}


int position(char id[10])
{
	int i;
	strcpy(table[0].name,id);
	//i = proc_id > 1 ? proc_id + 1 : 1;
	i = 1;
	while(strcmp(table[i].name,id) != 0 && i <= tx)
		i ++;

	return i;
}

int position_proc(int adr)
{
	int i;
	for(i = 1; i <= tx ;i ++)
		if(table[i].adr == adr)
			break;
	return i;
}
