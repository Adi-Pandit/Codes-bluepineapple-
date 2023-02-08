#include<stdio.h>

int main()
{
	int x;
	printf("Enter value of x (x is minutes clock run faster per hour): ");
	scanf("%d",&x);
	
	int hour,minutes;
	printf("Enter hour and minutes in (hh:mm): ");
	scanf("%d:%d",&hour,&minutes);

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
	printf("Actual Hour: %d",actualHour);
}