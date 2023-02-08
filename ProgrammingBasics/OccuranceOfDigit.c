#include<stdio.h>

void OccuranceOfDigit(int num)
{
	int DigitOccuranceArray[10] = {0};
	int remainder;		
	while(num>0)
	{
		remainder = num%10;
		DigitOccuranceArray[remainder]++;
		num = num/10;
	}
	int i;
	for(i=0; i<10; i++)
	{
		printf("\nOccurance of digit %d is %d",i,DigitOccuranceArray[i]);
	}
}

int main()
{
	int num;
	printf("Enter number: ");
	scanf("%d",&num);
	
	OccuranceOfDigit(num);
}
