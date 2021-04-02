#include<stdio.h>
void PrintInBinary(int decimal)
{
	int i,shifted;
	for(i=(sizeof(int)*2)-1; i>=0; i--)
	{
		shifted=decimal >> i;
		if(shifted&1)
		{
			printf("1");
		}
		else 
		{
			printf("0");
		}
	}
}
int Concatenate(int part1,int part2,int part3,int part4)
{
	int number=part1;
	number=(number<<8)|part2;
	number=(number<<8)|part3;
	number=(number<<8)|part4;
	return number;
}
int UnsetBit(int MSK1_PART)
{
	int i,shift,one=0,zero=0,bitClear,partShift=MSK1_PART,partClear=MSK1_PART;
	for(i=(sizeof(int)*2)-1; i>=0; i--)
	{
		shift=partShift >> i;
		if(shift&1)
		{
			one=1;
			if(!(zero^1))
			{
				bitClear=i;
				one=2;
				break;
			}
		}
		else 
		{
			zero=1;
		}
	}
	if(!(one^2))
	{
		while(bitClear>=0)
		{
			partClear &= ~(1<<bitClear);
			bitClear--;
		}
	}
	return partClear;
}
int NoAlternativeOrder(int MSK1_PART)
{
	int i,shift,one=0,zero=0,ok=1,partShift=MSK1_PART;
	for(i=(sizeof(int)*2)-1; i>=0; i--)
	{
		shift=partShift >> i;
		if(shift&1)
		{
			one=1;
			if(!(zero^1))
			{
				one=2;
			}
		}
		else 
		{
			zero=1;
		}
	}
	if(!(one^2))
	{
		ok=0;
	}
	return ok;
}

void Task0(int IP1_1,int IP1_2,int IP1_3,int IP1_4,int MSK_2)
{
	printf("-0 %d.%d.%d.%d/%d\n",IP1_1,IP1_2,IP1_3,IP1_4,MSK_2);
}
void Task2(int MSK1_1,int MSK1_2,int MSK1_3,int MSK1_4)
{
	printf("-2 %o.%o.%o.%o ",MSK1_1,MSK1_2,MSK1_3,MSK1_4);
	printf("%X.%X.%X.%X\n",MSK1_1,MSK1_2,MSK1_3,MSK1_4);
}
void Task3(int IP1_1,int IP1_2,int IP1_3,int IP1_4,int MSK2_1,int MSK2_2,int MSK2_3,int MSK2_4)
{
	int RE_1,RE_2,RE_3,RE_4;
	RE_1= IP1_1 & MSK2_1;
	RE_2= IP1_2 & MSK2_2;
	RE_3= IP1_3 & MSK2_3;
	RE_4= IP1_4 & MSK2_4;
	printf("-3 %d.%d.%d.%d\n",RE_1,RE_2,RE_3,RE_4);
}
void Task4(int IP1_1,int IP1_2,int IP1_3,int IP1_4,int MSK2_1,int MSK2_2,int MSK2_3,int MSK2_4)
{
	int BC_1,BC_2,BC_3,BC_4;
	BC_1=IP1_1|~MSK2_1;
	BC_2=IP1_2|~MSK2_2;
	BC_3=IP1_3|~MSK2_3;
	BC_4=IP1_4|~MSK2_4;
	printf("-4 %d.%d.%d.%d\n",BC_1,BC_2,BC_3,BC_4);
}
void Task5(int IP1_1,int IP1_2,int IP2_1,int IP2_2,int IP1_3,int IP2_3,int IP1_4,int IP2_4,int MSK2)
{
	int IP1,IP2,number=32-MSK2;
	IP1=Concatenate(IP1_1,IP1_2,IP1_3,IP1_4);
	IP2=Concatenate(IP2_1,IP2_2,IP2_3,IP2_4);
	IP1=IP1>>number;
	IP2=IP2>>number;
	if(!(IP1^IP2))
	{
		printf("-5 DA\n");
	}
	else
	{
		printf("-5 NU\n");
	}
}
int Task6(int MSK1_1,int MSK1_2,int MSK1_3,int MSK1_4)
{
	int part1,part2,part3,part4,MSK1_OK;
	part1=NoAlternativeOrder(MSK1_1);
	part2=NoAlternativeOrder(MSK1_2);
	part3=NoAlternativeOrder(MSK1_3);
	part4=NoAlternativeOrder(MSK1_4);
	if(!(part1^1) && !(part2^1) && !(part3^1 ) && !(part4^1))
	{
		printf("-6 DA\n");
		MSK1_OK=1;
	}
	else 
	{
		printf("-6 NU\n");
		MSK1_OK=0;
	}
	return MSK1_OK;
}
void Task7(int MSK1_OK,int MSK1_1,int MSK1_2,int MSK1_3,int MSK1_4)
{
	if (!(MSK1_OK^1))
	{
		printf("-7 %d.%d.%d.%d\n",MSK1_1,MSK1_2,MSK1_3,MSK1_4);
	}
	else
	{
		int part1,part2,part3,part4;
		int part1_clear=MSK1_1;
		int part2_clear=MSK1_2;
		int part3_clear=MSK1_3;
		int part4_clear=MSK1_4;
		part1=NoAlternativeOrder(MSK1_1);
		part2=NoAlternativeOrder(MSK1_2);
		part3=NoAlternativeOrder(MSK1_3);
		part4=NoAlternativeOrder(MSK1_4);
		if(part1^1)
		{	
			part1_clear=UnsetBit(MSK1_1);
		}
		
		if(part2^1)
		{
			part2_clear=UnsetBit(MSK1_2);
		}
		if(part3^1)
		{
			part3_clear=UnsetBit(MSK1_3);
		}
		if (part4^1)
		{
			part4_clear=UnsetBit(MSK1_4);
		}
		printf("-7 %d.%d.%d.%d\n",part1_clear,part2_clear,part3_clear,part4_clear);
	} 
}
void Task8(int IP1_1,int IP1_2,int IP1_3,int IP1_4)
{	
	printf("-8 ");
	PrintInBinary(IP1_1);
	printf(".");
	PrintInBinary(IP1_2);
	printf(".");
	PrintInBinary(IP1_3);
	printf(".");
	PrintInBinary(IP1_4);
}
int main()
{
	int set,i,j,index[500],k=0;
	int MSK1_1,MSK1_2,MSK1_3,MSK1_4,MSK1_OK;
	int MSK2,MSK2_1,MSK2_2,MSK2_3,MSK2_4;
	int IP1_1,IP1_2,IP1_3,IP1_4;
	int IP2_1,IP2_2,IP2_3,IP2_4;
	int N,NET_1,NET_2,NET_3,NET_4,NET_5;
	scanf("%d",&set);
	for(i=1;i<=set;i++)
	{
		scanf("%d.%d.%d.%d",&MSK1_1,&MSK1_2,&MSK1_3,&MSK1_4);
		scanf("%d",&MSK2);
		scanf("%d.%d.%d.%d",&IP1_1,&IP1_2,&IP1_3,&IP1_4);
		scanf("%d.%d.%d.%d",&IP2_1,&IP2_2,&IP2_3,&IP2_4);
		scanf("%d",&N);
		for(j=0;j<N;j++)
		{
			scanf("%d.%d.%d.%d/%d",&NET_1,&NET_2,&NET_3,&NET_4,&NET_5);
			int NET,IP2,zero=32-NET_5;
			NET=Concatenate(NET_1,NET_2,NET_3,NET_4);
			IP2=Concatenate(IP2_1,IP2_2,IP2_3,IP2_4);
			NET=NET>>zero;
			IP2=IP2>>zero;
			if(!(NET^IP2))
			{
				index[j]=j;
			}
			else
			{
				index[j]=-1;
			}
		}
		printf("%d\n",i); //set
		Task0(IP1_1,IP1_2,IP1_3,IP1_4,MSK2);
		//Task1
		int number=0,zeros=32-MSK2,onebyte=255;
		k=0;
		while(k < MSK2)
		{
		number |= 1 << k;
		k++;
		}
		number=number << zeros;
		MSK2_1=(number>>24)&onebyte;
		MSK2_2=(number>>16)&onebyte;
		MSK2_3=(number>>8)&onebyte;
		MSK2_4=(number)&onebyte;
		printf("-1 %d.%d.%d.%d\n",MSK2_1,MSK2_2,MSK2_3,MSK2_4);
		Task2(MSK1_1,MSK1_2,MSK1_3,MSK1_4);
		Task3(IP1_1,IP1_2,IP1_3,IP1_4,MSK2_1,MSK2_2,MSK2_3,MSK2_4);
		Task4(IP2_1,IP2_2,IP2_3,IP2_4,MSK2_1,MSK2_2,MSK2_3,MSK2_4);
		Task5(IP1_1,IP1_2,IP2_1,IP2_2,IP1_3,IP2_3,IP1_4,IP2_4,MSK2);
		MSK1_OK=Task6(MSK1_1,MSK1_2,MSK1_3,MSK1_4);
		Task7(MSK1_OK,MSK1_1,MSK1_2,MSK1_3,MSK1_4);
		Task8(IP1_1,IP1_2,IP1_3,IP1_4);
		//TASK 9
		printf("\n-9 ");
		for(k=0;k<N;k++)
		{
		
			if(index[k]==-1)
			{
				continue;
			}
			else 
			{
				printf("%d ",index[k]);
			}
		}
		printf("\n");	
	}
	return 0;
}