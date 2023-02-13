#include<stdio.h>
#include<string.h>
#include<Math.h>

char numberInWords[] = "";

char* NumberToWords(long long int num)
{
    int arrayOfDigits[15];
    int i = 0;
    int noOfDigits = 0;
    int j;
    
    if(num==0)
        printf("zero");

    char oneToNine[9][10] = {"one ","two ","three ","four ","five ","six ","seven ","eight ","nine "};
    char twentyToNinety[8][10] = {"twenty ","thirty ","fourty ","fifty ","sixty ","seventy ","eighty ","ninety "};
    char tenToNineteen[10][10] = {"ten ","eleven ","twenty ","thirteen ","fourteen ","fifteen ","sixteen ","seventeen ","eighteen ","nineteen "};

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
            strcat(numberInWords,tenToNineteen[choice-10]);
            if(noOfDigits==5)
            {
                strcat(numberInWords,"thousand ");
                noOfDigits=noOfDigits-2;
                j--;
                continue;
            }
            else if(noOfDigits==7)
            {
                strcat(numberInWords,"lakh ");
                noOfDigits=noOfDigits-2;
                j--;
                continue;
            }
            else if(noOfDigits==9)
            {
                strcat(numberInWords,"crore ");
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
                strcat(numberInWords,oneToNine[choice-1]);
                strcat(numberInWords,"arab ");
                noOfDigits--;
                break;

            case 9:
                strcat(numberInWords,twentyToNinety[choice-2]);
                if(arrayOfDigits[j]!=0 && arrayOfDigits[j-1]==0)
                    strcat(numberInWords,"crore ");
                noOfDigits--;
                break;

            case 8:
                strcat(numberInWords,oneToNine[choice-1]);
                strcat(numberInWords,"crore ");
                noOfDigits--;
                break;
            
            case 7:
                strcat(numberInWords,twentyToNinety[choice-2]);
                if(arrayOfDigits[j]!=0 && arrayOfDigits[j-1]==0)
                    strcat(numberInWords,"lakh ");
                noOfDigits--;
                break;

            case 6:
                strcat(numberInWords,oneToNine[choice-1]);
                strcat(numberInWords,"lakh ");
                noOfDigits--;
                break;

            case 5:
                strcat(numberInWords,twentyToNinety[choice-2]);
                if(arrayOfDigits[j]!=0 && arrayOfDigits[j-1]==0)
                    strcat(numberInWords,"thousand ");
                noOfDigits--;
                break;

            case 4:
                strcat(numberInWords,oneToNine[choice-1]);
                strcat(numberInWords,"thousand ");
                noOfDigits--;
                break;

            case 3:
                strcat(numberInWords,oneToNine[choice-1]);
                strcat(numberInWords,"hundred ");
                if(arrayOfDigits[j-1]!=0 || arrayOfDigits[j-2]!=0)
                    strcat(numberInWords,"and ");
                noOfDigits--;
                break;

            case 2:
                strcat(numberInWords,twentyToNinety[choice-2]);
                noOfDigits--;
                break;

            case 1:
                strcat(numberInWords,oneToNine[choice-1]);
                noOfDigits--;
                break;
        }
    }
    return numberInWords;
}

char* testFunction(int num, char expectedResult[])
{
    if(strcmp(NumberToWords(num),expectedResult)==0)
        return "Pass";
    else    
        return "Not pass";
}

int main()
{
    int num = 0;
    char *actualResult;
    char expectedResult[3][100] = {"one ","eleven ","one hundred and eleven "};

    printf("\nTest cases:");
    for(int i=1; i<=3; i++)
    {
        num = 10*num + 1;
        printf("\n\nTC0%d:",(i));
        printf("\nNumber: %d",num);
        actualResult = NumberToWords(num);
        printf("\nActual result: %s",actualResult);  
        numberInWords[0] = '\0';
        printf("\nExpected result: %s",expectedResult[i-1]);
        printf("\nTest case: %s",testFunction(num,expectedResult[i-1]));
        numberInWords[0] = '\0';
    }
}