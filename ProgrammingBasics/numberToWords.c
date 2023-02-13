#include<stdio.h>

int NumberToWords(long long int num)
{
    int arrayOfDigits[15];
    int i = 0;
    int noOfDigits = 0;
    int j;
    
    if(num==0)
        printf("zero");

    char oneToNine[9][5] = {"one","two","three","four","five","six","seven","eight","nine"};
    char twentyToNinety[8][10] = {"twenty","thirty","fourty","fifty","sixty","seventy","eighty","ninety"};
    char tenToNineteen[10][10] = {"ten","eleven","twenty","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};

    while(num>0)
    {
        arrayOfDigits[i++] = num%10;
        num = num/10;
        noOfDigits++;
    }
    for(int j=i-1; j>=0; j--)
    {
        int choice;
        if((noOfDigits==2 && arrayOfDigits[j]==1) || (noOfDigits==5 && arrayOfDigits[j]==1) || (noOfDigits==7 && arrayOfDigits[j]==1) || (noOfDigits==9 && arrayOfDigits[j]==1))
        {
            choice = arrayOfDigits[j]*10+arrayOfDigits[j-1];  
            printf("%s ",tenToNineteen[choice-10]);
            if(noOfDigits==5)
            {
                printf("thousand ");
                noOfDigits=noOfDigits-2;
                j--;
                continue;
            }
            else if(noOfDigits==7)
            {
                printf("lakh ");
                noOfDigits=noOfDigits-2;
                j--;
                continue;
            }
            else if(noOfDigits==9)
            {
                printf("crore ");
                noOfDigits=noOfDigits-2;
                j--;
                continue;
            }
            else
                break; 
        }
        else
        {
            choice = arrayOfDigits[j];
        }
        switch(noOfDigits)
        {
            case 10:
                printf("%s arab ",oneToNine[choice-1]);
                noOfDigits--;
                break;

            case 9:
                printf("%s ",twentyToNinety[choice-2]);
                if(arrayOfDigits[j]!=0 && arrayOfDigits[j-1]==0)
                    printf("crore ");
                noOfDigits--;
                break;

            case 8:
                printf("%s crore ",oneToNine[choice-1]);
                noOfDigits--;
                break;
            
            case 7:
                printf("%s ",twentyToNinety[choice-2]);
                if(arrayOfDigits[j]!=0 && arrayOfDigits[j-1]==0)
                    printf("lakh ");
                noOfDigits--;
                break;

            case 6:
                printf("%s lakh ",oneToNine[choice-1]);
                noOfDigits--;
                break;

            case 5:
                printf("%s ",twentyToNinety[choice-2]);
                if(arrayOfDigits[j]!=0 && arrayOfDigits[j-1]==0)
                    printf("thousand ");
                noOfDigits--;
                break;

            case 4:
                printf("%s thousand ",oneToNine[choice-1]);
                noOfDigits--;
                break;

            case 3:
                printf("%s hundred ",oneToNine[choice-1]);
                if(arrayOfDigits[j-1]!=0 || arrayOfDigits[j-2]!=0)
                    printf("and ");
                noOfDigits--;
                break;

            case 2:
                printf("%s ",twentyToNinety[choice-2]);
                noOfDigits--;
                break;

            case 1:
                printf("%s",oneToNine[choice-1]);
                noOfDigits--;
                break;
        }
    }
}



int main()
{
    long long int num;
    printf("\nEnter number : ");
    scanf("%lld",&num);
    NumberToWords(num);  
}