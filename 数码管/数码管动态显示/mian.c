#include<reg52.h>
#define uint unsigned int

unsigned char code table[]={
    0x3f,0x06,0x5b,0x4f,
    0x66,0x6d,0x7d,0x07,
    0x7f,0x6f,0x77,0x7c,
    0x39,0x5e,0x79,0x71
};
void delayms(uint);

sbit dula=P2^6;
sbit wela=P2^7;

void main()
{
	uint i;
	wela=1;
	P0=0xcf;
	wela=0;
	for(i=0;i<16;i++)
	{
		dula=1;
		P0=table[i];
		dula=0;
		delayms(500);
	}
}
	
	
void delayms(uint xms)
{
	uint i,j;
	for(i=0;i<xms;i++)
		for(j=0;j<110;j++);
}