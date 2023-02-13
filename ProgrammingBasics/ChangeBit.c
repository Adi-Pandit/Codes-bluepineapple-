#include<stdio.h>
#include<Math.h>

int flipBit(int num, int offset)
{
	int remainder;
	int BinaryArray[100] = {0};
	int i=0;
	while(num>0)
	{
		remainder = num%2;
		num = num/2;
		BinaryArray[i++] = remainder;
	}
	
	if(BinaryArray[offset-1]==1)
		BinaryArray[offset-1]=0;
	else
		BinaryArray[offset-1]=1;
		
	int sum=0;
	for(i=0; i<(sizeof(BinaryArray)/sizeof(BinaryArray[0])); i++)
	{
		sum += ((int)pow(2,i))*BinaryArray[i];
	}
	return sum;
}

const char* testFunction(char character, int offset, int expectedResult) 
{
    if((char)flipBit(character,offset)==expectedResult)
        return "Pass";
    else   
        return "Not pass";
}

int main()
{
	/*char character;
	int num;
	printf("\nEnter Character: ");
	scanf("%c",&character);

	printf("Enter offset number: ");
	scanf("%d",&num);

	flipBit(character, num);*/

	printf("Test Cases:\n");
	printf("\nCharacter\tOffset\tExpected Result\tActual Result\tTest Case");
	printf("\nA\t\t5\t%c\t\tQ\t\t%s",flipBit('A',5),testFunction('A',5,'Q'));
	printf("\na\t\t3\t%c\t\te\t\t%s",flipBit('a',3),testFunction('a',3,'e'));
	printf("\nZ\t\t4\t%c\t\tR\t\t%s",flipBit('Z',4),testFunction('Z',4,'R'));
}
