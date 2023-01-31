#include<stdio.h>

int PerfectNumber(int num)
{
	int sum = 0;
	int i;
	for(i=1; i<=num/2; i++)
	{
		if(num%i==0)
			sum += i;
	}
	if(sum==num)
		return 1;
	else
		return 0;
}

void PerfectNumberTestCase(int lastNumber, int expectedResult[])
{
	int i,j;
	int sizeOfExpectedResultArray = sizeof(expectedResult)/sizeof(expectedResult[0]); 
	int actualResult[sizeOfExpectedResultArray];
	for(i=1,j=0; i<=lastNumber,j<sizeOfExpectedResultArray; i++)
	{
		if(PerfectNumber(i))
		{
			actualResult[j] = i;
			j++;
		}
	}
	
	int flag=0;
	for(i=0; i<sizeOfExpectedResultArray; i++)
	{
		if(actualResult[i]!=expectedResult[i])
		{
			printf("\nTest case failed");
			flag=1;
			break;
		}
	}
	if(flag==0)
		printf("\nTest case successful for range 1 to %d",lastNumber);
}

int main()
{
	int lastNumber;
	printf("\nEnter last number of range: ");
	scanf("%d",&lastNumber);

	int i;
	printf("\nPerfect number from range 1 to %d are\n",lastNumber);
	for(i=1; i<=lastNumber; i++)
	{
		if(PerfectNumber(i))
			printf("%d ",i);			
	}
	printf("\n");
	
	int ExpectedResultFromRange1to100[] = {6,28};
	PerfectNumberTestCase(100, ExpectedResultFromRange1to100);
	
	int ExpectedResultFromRange1to1000[] = {6,28,496};
	PerfectNumberTestCase(1000, ExpectedResultFromRange1to1000);
	
	int ExpectedResultFromRange1to10000[] = {6,28,496,8182};
	PerfectNumberTestCase(10000, ExpectedResultFromRange1to10000);
}


