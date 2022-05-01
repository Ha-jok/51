#include<reg52.h>
#define uint unsigned int

sbit dula=P2^6;
sbit wela=P2^7;

//定义数码管的数字

void main()
{
	//根据两个锁存器的1,11脚和P0口
	//依次进行锁存器组合P0口操作
	P0=0xc0;
	wela=0;
	P0=0x7f;
	dula=0;
	while(1);
}