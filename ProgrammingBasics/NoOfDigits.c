#include<stdio.h>
#include<Math.h>

int NumberOfDigits(int num) 
{
    int count = 0;
    if(num==0)
        return 1;
    else if(num<0)
        num = -num;
    while(num>0) 
    {
        num = num/10;
        count++;
    }
    return count;
}

const char* testFunction(int num, int expectedResult) 
{
    if(NumberOfDigits(num)==expectedResult)
        return "Pass";
    else   
        return "Not pass";
}

int main() 
{
    int num = 0;
    int i;
    printf("Test Cases:\n");
    printf("\nNumber\tActual Result\tExpected Result\tTest Case");
    printf("\n%d\t%d\t\t1\t\t%s",num,NumberOfDigits(num),testFunction(num, 1));
    for(i=0; i<5; i++) {
        num = (int)pow(10,i)+num;
        printf("\n%d\t%d\t\t%d\t\t%s",num,NumberOfDigits(num),(i+1),testFunction(num, (i+1)));
    }
    num = -12345;
    printf("\n%d\t%d\t\t%d\t\t%s",num,NumberOfDigits(num),5,testFunction(num, 5));
}