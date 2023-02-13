#include<stdio.h>

int clock(int hour, int minutes, int x) 
{
	int actualHour = 0;
	
	while(hour>0)
	{
		if(minutes-x<0)
		{
			minutes = 60-x;
			hour = hour-2;
			actualHour++;
		}
		else
		{
			minutes = minutes-x;
			hour = hour-1;
			actualHour++; 
		}
	}
	return actualHour;
}

const char* testFunction(int hour, int minutes, int x, int expectedResult) 
{
    if(clock(hour,minutes,x)==expectedResult)
        return "Pass";
    else   
        return "Not pass";
}

int main()
{
	printf("Test Cases:\n");
    printf("\nIndicated Time\tActual Result\tExpected Result\tTest Case");
	printf("\n9:20\t\t%d\t\t8\t\t%s",clock(9,20,10),testFunction(9,20,10,8));
	printf("\n12:30\t\t%d\t\t10\t\t%s",clock(12,30,15),testFunction(12,30,15,10));
	printf("\n8:45\t\t%d\t\t7\t\t%s",clock(8,45,15),testFunction(8,45,15,7));
	printf("\n10:30\t\t%d\t\t9\t\t%s",clock(10,30,10),testFunction(10,30,10,9));
}

