#include<reg52.h>
#define uchar unsigned char
#define uint unsigned int

uchar code table[]="I LOVE ME!";
uchar code table1[]="HA-JOK.XYZ";

sbit lcden=P3^4;
sbit lcdrs=P3^5;
sbit dula=P2^6;
sbit wela=P2^7;
uchar num;

void delay (uint xms)
{
	uint x,y;
	for(x=0;x<xms;x++)
		for(y=0;y<110;y++);
}

void write_com(uchar com)
{
	lcdrs=0;
	P0=com;
	delay(5);
	lcden=1;
	delay(5);
	lcden=0;
}

void write_data (uchar date)
{
	lcdrs=1;
	P0=date;
	delay(5);
	lcden=1;
	delay(5);
	lcden=0;
}

void init()
{
	dula=0;
	wela=0;
	lcden=0;
	write_com(0x38);
	write_com(0x0c);
	write_com(0x06);
	write_com(0x01);
}

void main()
{
	init();
	write_com(0x80);
	for(num=0;num<10;num++)
	{
		write_data(table[num]);
		delay(5);
	}
	write_com(0x80+0x40);
	for(num=0;num<10;num++)
	{
		write_data(table1[num]);
		delay(5);
	}
	while(1);
}



