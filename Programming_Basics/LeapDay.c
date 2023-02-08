// Online C compiler to run C program online
#include <stdio.h>

int ValidateDate(int day, int month, int year)
{
	int daysArray[] = {31,28,31,30,31,30,31,31,30,31,30,31};
	int leapDayArray[] = {31,29,31,30,31,30,31,31,30,31,30,31};

	if(year>0)
	{
		if(month>0 && month<=12)
		{
			if(day>=1 && day<=leapDayArray[month-1] && (year%4==0) && ((year%400==0) || (year%100!=0)))
				return 1;
			else if(day>=1 && day<=daysArray[month-1])
				return 1;
			else	
				return 0;
		}
		else
			return 0;
	}
	else
		return 0;
}

int CheckLeapDay(int day, int month, int year) 
{
    if((year%4==0) && ((year%400==0) || (year%100!=0)) && (month==2) && (day==29)) 
        return 1;
    else
        return 0;
}

int TestCases(int day, int month, int year, int ExpectedResult)
{
	if(ValidateDate(day,month,year)==ExpectedResult && CheckLeapDay(day,month,year)==ExpectedResult)
		printf("\nTest case successful for %d/%d/%d",day,month,year);
	else	
		printf("\nTest case unsuccessful for %d/%d/%d",day,month,year);
}

int main() 
{
	TestCases(29,02,2022,0);
	TestCases(29,02,2024,1);
	TestCases(29,02,2026,0);
	TestCases(29,02,2028,1);
	TestCases(29,02,2030,0);
}
