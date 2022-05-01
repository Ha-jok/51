#include<reg52.h>
#include<intrins.h>
#define uchar unsigned char
#define uint unsigned int


unsigned char code table[]={
    0x3f,0x06,0x5b,0x4f,
    0x66,0x6d,0x7d,0x07,
    0x7f,0x6f,0x77,0x7c,
    0x39,0x5e,0x79,0x71
};

//定义U1，U2锁存端，和ADC0804RD,WR引脚
sbit dula=P2^6;
sbit wela=P2^7;
sbit adrd=P3^7;
sbit adwr=P3^6;
sbit u3=P2^5;

//延时函数
void delayms(uint xms)
{
	uint i,j;
	for(i=0;i<xms;i++)
		for(j=0;j<110;j++);
}
//数码管显示函数
void display(uchar bai,uchar shi,uchar ge)
{
	dula=1;
	P0=table[bai];
	dula=0;
	P0=0xff;
	wela=1;
	P0=0x7e;
	wela=0;
	delayms(5);
	
	dula=1;
	P0=table[shi];
	dula=0;
	P0=0xff;
	wela=1;
	P0=0x7d;
	wela=0;
	delayms(5);
	
	dula=1;
	P0=table[ge];
	dula=0;
	P0=0x7f;
	wela=1;
	P0=0x7b;
	wela=0;
	delayms(5);
	
}


//主程序
void main()
{
	uchar bai,shi,ge,a,i;
	//置CSAD为低
	u3=1;
	P1=0xff;
	u3=0;
	wela=1;
	P0=0x7f;
	wela=0;
	
	while(1)
	{

		//启动A/D转换，进行采样
		adwr=1;
		_nop_();
		adwr=0;
		_nop_();
		adwr=1;


		//启动后延时，通过显示
		for(i=0;i<10;i++)
		{
			display(bai,shi,ge);
		}
		//读取P1口，全部赋为1
		P1=0xff;
		//选通ADCS
		adrd=1;
		_nop_();
		adrd=0;
		_nop_();
		//读取数据
		a=P1;
		_nop_();
		adrd=1;
		//解析数据
		bai=a/100;
		shi=a%100/10;
		ge=a%10;
	}
}
