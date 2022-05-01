#include<reg52.h>
#define uint unsigned int

void main()
{
	uint i,j,temp;
	P1=0xff;
	temp=0;
	while(1)
	{	if(P1==0x00)
		{
			P1=0xff;
		}
		if(temp>16)
		{
			temp=0;
		}
		for(i=0;i<1000;i++)
			for(j=0;j<110;j++);
		if(temp<8)
		{
			P1=P1<<1;
		}
		else
		{
			P1=P1>>1;
		}
		temp++;
		for(i=0;i<250;i++)
			for(j=0;j<110;j++);
				
	}
}

