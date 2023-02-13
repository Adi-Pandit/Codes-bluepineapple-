#include<stdio.h>
#include<Math.h>

int NumberOfDigits(num) 
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

int testFunction(num, expectedResult) {
    if(NumberOfDigits(num)===expectedResult)
        return 1;
    else   
        return 0;
}

int main() 
{
    int num = 0;
    int i;
    printf("Test Cases:");
    printf("\nNumber\tActual Result\tExpected Result\tTest Case");
    printf("%d\t%d\t\t"+1+"\t\t"+testFunction(num, 1),num,NumberOfDigits(num);
    for(i=0; i<5; i++) {
        num = Math.pow(10,i) + num;
        printf(num+"\t"+NumberOfDigits(num)+"\t\t"+(i+1)+"\t\t"+testFunction(num, i+1));
    }
    printf("-12345\t"+NumberOfDigits(-12345)+"\t\t"+5+"\t\t"+testFunction(-12345, 5));
}