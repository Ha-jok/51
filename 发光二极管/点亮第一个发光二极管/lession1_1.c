#include<reg52.h>
//位定义

sbit d7=P1^7;
//主函数
//特点，无返回值，无参数
void main()
{
	P1=0x8f;
	while(1);
	
}