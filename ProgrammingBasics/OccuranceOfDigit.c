#include<stdio.h>

int DigitOccuranceArray[10] = {0};

int* OccuranceOfDigit(int num)
{
	int remainder;		
	while(num>0)
	{
		remainder = num%10;
		DigitOccuranceArray[remainder]++;
		num = num/10;
	}
	return DigitOccuranceArray;
}

char* testFunction(int num, int expectedResult[])
{
	int i;
	int *actualResult = OccuranceOfDigit(num);
	for(i=0; i<10; i++) 
	{
		if(actualResult[i]!=expectedResult[i])
			return "Not pass";
	}
	return "Pass";
}

int main()
{
	int num[3] = {123,12345,1234567};
	int expectedResult[3][10] = {{0,1,1,1,0,0,0,0,0,0},{0,1,1,1,1,1,0,0,0,0},{0,1,1,1,1,1,1,1,0,0}};
	int i,j;

	printf("\nTest Cases: ");
	printf("\n\nNumber\t\tTest case");

	for(i=0; i<3; i++)
	{
		printf("\n%d\t\t%s",num[i],testFunction(num[i],expectedResult[i]));
		for(j=0; j<10; j++)
		{
			DigitOccuranceArray[j] = 0;
		}
	}
}
