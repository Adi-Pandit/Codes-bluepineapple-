#include<stdio.h>

int PalindromeFunction(char String[])
{
	int i,j;
	int flag=0;
	for(i=0,j=strlen(String)-1; i<j; i++,j--)
	{
		if(String[i]!=String[j])
		{
			return 0;
		}
	}
	return 1;
}

int PalindromeTestCases(char PalindromeTestCaseString[], int ExpectedResult)
{
	int i;
	if(PalindromeFunction(PalindromeTestCaseString)==ExpectedResult)
		printf("\nTest case sucessful for %s",PalindromeTestCaseString);
	else
		printf("\nTest case unsucessful for %s",PalindromeTestCaseString);
}

int main()
{
	char String[] = "";
	printf("Enter String: ");
	scanf("%s",String);
	
	if(PalindromeFunction(String))
		printf("Palindrome");
	else
		printf("Not Palindrome");
		
	PalindromeTestCases("A",1);
	PalindromeTestCases("AA",1);
	PalindromeTestCases("ABA",1);
	PalindromeTestCases("ABBA",1);
	PalindromeTestCases("ABCBA",1);
}
