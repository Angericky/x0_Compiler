#include "stdio.h"

unsigned char* char2byte(char value){
	unsigned char* byte;
	byte = (unsigned char*)malloc(sizeof(char));
	*byte = value - 128;
	return byte;
}
unsigned char* int2byte(int value){
	unsigned char* byte;
	byte = (unsigned char*)malloc(sizeof(int));
	int i;
	for(i = 0;i < sizeof(int);i ++){
		byte[3 - i] = (value >> (24 - i * 8));
	}
	return byte;
}
unsigned char* float2byte(float value){
	unsigned char* byte;
	byte = (unsigned char*)malloc(sizeof(float));
	unsigned char* pdata = (unsigned char *)&value;
	int i;
	for(i = 0;i < sizeof(float);i ++){
		byte[i] = *pdata++;
	}
	return byte;
}
char byte2char(unsigned char* byte){
	char value = byte[0] + 128;
	return value;
}
int byte2int(unsigned char* byte){
	int value = 0,temp = 0, mask = 0xff, i;
	for(i = 3;i > -1;i --){
		value <<= 8;
		temp = byte[i] & mask;
		value |= temp;
	}
	return value;
}
float byte2float(unsigned char* byte){
	float value = 0;
	void *pf = &value;
	int i;
	for(i = 0;i < 4;i ++){
		*((unsigned char *)pf+i) = *(byte + i);
	}
	return value;
}