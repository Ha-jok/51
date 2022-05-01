#include<reg52.h>
#define uchar unsigned char
#define uint unsigned int
sbit led1=P1^0;
sbit dula=P2^6;
sbit wela=P2^7;
uchar num,i;
unsigned char code table[]={
    0x3f,0x06,0x5b,0x4f,
    0x66,0x6d,0x7d,0x07,
    0x7f,0x6f,0x77,0x7c,
    0x39,0x5e,0x79,0x71
};
void main()
{
	i=0;
	TMOD=0x01;              //定义方式2，为16位计数器——TMOD
	TH0=(65536-45872)/256; //装初值为11.0592M晶振定时50ms数为45872.
	TL0=(65536-45872)%256;
	EA=1;                  //打开全局中断，解锁中断功能——IE
	ET0=1;                //打开T0中断——IE
	TR0=1;                //启动定时器0；——TCON
	while(1);
}

void T0_time() interrupt 1       
{
	TH0=(65536-45872)/256; //重装初值
	TL0=(65536-45872)%256;
	num++;
	if(num==20)
	{
		num=0;
		P0=0xff;
		wela=1;
		P0=0xfe;
		wela=0;
		P0=0xff;
		dula=1;
		P0=table[i];
		i++;
		if(i>9)
		{
			i=0;
		}
		
	}
}