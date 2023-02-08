#include<stdio.h>

int NumberToWords(long long int num)
{
    int arrayOfDigits[15];
    int i = 0;
    int noOfDigits = 0;
    int j;
    if(num==0)
        printf("zero");
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
            switch(choice)
            {
                case 10:
                    printf("ten ");
                    break;
                case 11:
                    printf("eleven ");
                    break;
                case 12:
                    printf("twelve ");
                    break;
                case 13:
                    printf("thirteen ");
                    break;
                case 14:
                    printf("fourteen ");
                    break;
                case 15:
                    printf("fifteen ");
                    break;
                case 16:
                    printf("sixteen ");
                    break;
                case 17:
                    printf("seventeen ");
                    break;
                case 18:
                    printf("eighteen ");
                    break;
                case 19:
                    printf("nineteen ");
                    break;
            }
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
                switch(choice)
                {
                    case 1:
                        printf("one arab ");
                        break;
                    case 2:
                        printf("two arab ");
                        break;
                    case 3:
                        printf("three arab ");
                        break;
                    case 4:
                        printf("four arab ");
                        break;
                    case 5:
                        printf("five arab ");
                        break;
                    case 6:
                        printf("six arab ");
                        break;
                    case 7:
                        printf("seven arab ");
                        break;
                    case 8:
                        printf("eight arab ");
                        break;
                    case 9:
                        printf("nine arab ");
                        break;
                }
                noOfDigits--;
                break;

            case 9:
                switch(choice)
                {
                    case 2:
                        printf("twenty ");
                        break;
                    case 3:
                        printf("thirty ");
                        break;
                    case 4:
                        printf("fourty ");
                        break;
                    case 5:
                        printf("fifty ");
                        break;
                    case 6:
                        printf("sixty ");
                        break;
                    case 7:
                        printf("seventy ");
                        break;
                    case 8:
                        printf("eighty ");
                        break;
                    case 9:
                        printf("ninety ");
                        break;
                }
                if(arrayOfDigits[j]!=0 && arrayOfDigits[j-1]==0)
                    printf("crore ");
                noOfDigits--;
                break;

            case 8:
                switch(choice)
                {
                    case 1:
                        printf("one crore ");
                        break;
                    case 2:
                        printf("two crore ");
                        break;
                    case 3:
                        printf("three crore ");
                        break;
                    case 4:
                        printf("four crore ");
                        break;
                    case 5:
                        printf("five crore ");
                        break;
                    case 6:
                        printf("six crore ");
                        break;
                    case 7:
                        printf("seven crore ");
                        break;
                    case 8:
                        printf("eight crore ");
                        break;
                    case 9:
                        printf("nine crore ");
                        break;
                }
                noOfDigits--;
                break;
            
            case 7:
                switch(choice)
                {
                    case 2:
                        printf("twenty ");
                        break;
                    case 3:
                        printf("thirty ");
                        break;
                    case 4:
                        printf("fourty ");
                        break;
                    case 5:
                        printf("fifty ");
                        break;
                    case 6:
                        printf("sixty ");
                        break;
                    case 7:
                        printf("seventy ");
                        break;
                    case 8:
                        printf("eighty ");
                        break;
                    case 9:
                        printf("ninety ");
                        break;
                }
                if(arrayOfDigits[j]!=0 && arrayOfDigits[j-1]==0)
                    printf("lakh ");
                noOfDigits--;
                break;

            case 6:
                switch(choice)
                {
                    case 1:
                        printf("one lakh ");
                        break;
                    case 2:
                        printf("two lakh ");
                        break;
                    case 3:
                        printf("three lakh ");
                        break;
                    case 4:
                        printf("four lakh ");
                        break;
                    case 5:
                        printf("five lakh ");
                        break;
                    case 6:
                        printf("six lakh ");
                        break;
                    case 7:
                        printf("seven lakh ");
                        break;
                    case 8:
                        printf("eight lakh ");
                        break;
                    case 9:
                        printf("nine lakh ");
                        break;
                }
                noOfDigits--;
                break;

            case 5:
                switch(choice)
                {
                    case 2:
                        printf("twenty ");
                        break;
                    case 3:
                        printf("thirty ");
                        break;
                    case 4:
                        printf("fourty ");
                        break;
                    case 5:
                        printf("fifty ");
                        break;
                    case 6:
                        printf("sixty ");
                        break;
                    case 7:
                        printf("seventy ");
                        break;
                    case 8:
                        printf("eighty ");
                        break;
                    case 9:
                        printf("ninety ");
                        break;
                }
                if(arrayOfDigits[j]!=0 && arrayOfDigits[j-1]==0)
                    printf("thousand ");
                noOfDigits--;
                break;

            case 4:
                switch(choice)
                {
                    case 1:
                        printf("one thousand ");
                        break;
                    case 2:
                        printf("two thousand ");
                        break;
                    case 3:
                        printf("three thousand ");
                        break;
                    case 4:
                        printf("four thousand ");
                        break;
                    case 5:
                        printf("five thousand ");
                        break;
                    case 6:
                        printf("six thousand ");
                        break;
                    case 7:
                        printf("seven thousand ");
                        break;
                    case 8:
                        printf("eight thousand ");
                        break;
                    case 9:
                        printf("nine thousand ");
                        break;
                }
                noOfDigits--;
                break;

            case 3:
                switch(choice)
                {
                    case 1:
                        printf("one hundred ");
                        break;
                    case 2:
                        printf("two hundred ");
                        break;
                    case 3:
                        printf("three hundred ");
                        break;
                    case 4:
                        printf("four hundred ");
                        break;
                    case 5:
                        printf("five hundred ");
                        break;
                    case 6:
                        printf("six hundred ");
                        break;
                    case 7:
                        printf("seven hundred ");
                        break;
                    case 8:
                        printf("eight hundred ");
                        break;
                    case 9:
                        printf("nine hundred ");
                        break;
                }
                if(arrayOfDigits[j-1]!=0 || arrayOfDigits[j-2]!=0)
                    printf("and ");
                noOfDigits--;
                break;

            case 2:
                switch(choice)
                {
                    case 2:
                        printf("twenty ");
                        break;
                    case 3:
                        printf("thirty ");
                        break;
                    case 4:
                        printf("fourty ");
                        break;
                    case 5:
                        printf("fifty ");
                        break;
                    case 6:
                        printf("sixty ");
                        break;
                    case 7:
                        printf("seventy ");
                        break;
                    case 8:
                        printf("eighty ");
                        break;
                    case 9:
                        printf("ninety ");
                        break;
                }
                noOfDigits--;
                break;

            case 1:
                switch(choice)
                {
                    case 1:
                        printf("one");
                        break;
                    case 2:
                        printf("two");
                        break;
                    case 3:
                        printf("three");
                        break;
                    case 4:
                        printf("four");
                        break;
                    case 5:
                        printf("five");
                        break;
                    case 6:
                        printf("six");
                        break;
                    case 7:
                        printf("seven");
                        break;
                    case 8:
                        printf("eight");
                        break;
                    case 9:
                        printf("nine");
                        break;
                }
        }
    }
}

void 

int main()
{
    long long int num;
    printf("\nEnter number : ");
    scanf("%lld",&num);
    NumberToWords(num);  

    for()
}