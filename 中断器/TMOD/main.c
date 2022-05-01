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
	TMOD=0x01;              //���巽ʽ2��Ϊ16λ����������TMOD
	TH0=(65536-45872)/256; //װ��ֵΪ11.0592M����ʱ50ms��Ϊ45872.
	TL0=(65536-45872)%256;
	EA=1;                  //��ȫ���жϣ������жϹ��ܡ���IE
	ET0=1;                //��T0�жϡ���IE
	TR0=1;                //������ʱ��0������TCON
	while(1);
}

void T0_time() interrupt 1       
{
	TH0=(65536-45872)/256; //��װ��ֵ
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