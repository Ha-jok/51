#include<reg52.h>
#define uint unsigned int

sbit dula=P2^6;
sbit wela=P2^7;

//��������ܵ�����

void main()
{
	//����������������1,11�ź�P0��
	//���ν������������P0�ڲ���
	P0=0xc0;
	wela=0;
	P0=0x7f;
	dula=0;
	while(1);
}