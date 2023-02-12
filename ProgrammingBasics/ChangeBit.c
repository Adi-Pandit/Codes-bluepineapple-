#include<stdio.h>
#include<Math.h>

void flipBit(int num, int offset)
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
	printf("\nNumber after flipping bit: %d ",sum);
	printf("\nCharacter after flipping bit: %c ",sum);
}

int main()
{
	char character;
	int num;
	printf("\nEnter Character: ");
	scanf("%c",&character);

	printf("Enter offset number: ");
	scanf("%d",&num);

	flipBit(character, num);
}
