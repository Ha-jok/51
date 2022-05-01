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

//����U1��U2����ˣ���ADC0804RD,WR����
sbit dula=P2^6;
sbit wela=P2^7;
sbit adrd=P3^7;
sbit adwr=P3^6;
sbit u3=P2^5;

//��ʱ����
void delayms(uint xms)
{
	uint i,j;
	for(i=0;i<xms;i++)
		for(j=0;j<110;j++);
}
//�������ʾ����
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


//������
void main()
{
	uchar bai,shi,ge,a,i;
	//��CSADΪ��
	u3=1;
	P1=0xff;
	u3=0;
	wela=1;
	P0=0x7f;
	wela=0;
	
	while(1)
	{

		//����A/Dת�������в���
		adwr=1;
		_nop_();
		adwr=0;
		_nop_();
		adwr=1;


		//��������ʱ��ͨ����ʾ
		for(i=0;i<10;i++)
		{
			display(bai,shi,ge);
		}
		//��ȡP1�ڣ�ȫ����Ϊ1
		P1=0xff;
		//ѡͨADCS
		adrd=1;
		_nop_();
		adrd=0;
		_nop_();
		//��ȡ����
		a=P1;
		_nop_();
		adrd=1;
		//��������
		bai=a/100;
		shi=a%100/10;
		ge=a%10;
	}
}
