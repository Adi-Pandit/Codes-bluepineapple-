import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class DateDifference
{
    public static boolean LeapYear(int year)
    {
        if((year%4)==0 && ((year%400)==0 || (year%100)!=0))
            return true;
        else    
            return false;
    }

    public static boolean DateValidation(int day, int month, int year)
    {
        int arrOfDay[] = {31,28,31,30,31,30,31,31,30,31,30,31};
        if(LeapYear(year))
            arrOfDay[1] = 29;
        if(year>0 && month>0 && month<=12 && day>0 && day<=arrOfDay[month-1])
            return true;
        else 
            return false;
    }

    public static void DifferenceBetweenTwoDates(int sDay, int sMonth, int sYear, int eDay, int eMonth, int eYear)
    {
        int monthDays[] = {31,28,31,30,31,30,31,31,30,31,30,31};
        int dayDifference = 0;
        if(eYear==sYear)
        {  
            if(eMonth==sMonth)
            {
                if(eDay==sDay)
                {
                    dayDifference = 0;
                }
                else if(eDay<sDay)
                {
                    System.out.println("Invalid Last Date");
                }
                else 
                {
                    dayDifference = eDay-sDay;
                }
            }
            else if(eMonth<sMonth)
            {
                System.out.println("Invalid Last Date");
            }
            else 
            {
                dayDifference += monthDays[sMonth-1]-sDay;
                sMonth++;
                while(sMonth<eMonth)
                {
                    dayDifference += monthDays[sMonth-1];
                    sMonth++;
                }
                if(LeapYear(eYear) && eMonth>2)
                    dayDifference += 1;
                dayDifference += eDay;
            }
        }
        else if(eYear<sYear)
        {
            System.out.println("Invalid Last Date");
        }
        else 
        {
            dayDifference += monthDays[sMonth-1]-sDay;
            if(LeapYear(sYear) && sMonth<=2)
                dayDifference += 1;
            sMonth++;
            while(sMonth<=12)
            {
                dayDifference += monthDays[sMonth-1];
                sMonth++;
            }
            sYear++;
            dayDifference += (eYear-sYear)*365;
            int month=1;
            while(month<eMonth)
            {
                dayDifference += monthDays[month-1];
                month++;
            }
            dayDifference += eDay;
            if(LeapYear(eYear) && month>2)
                dayDifference += 1;
        }
        System.out.println("\nDifference Between Two Dates: "+dayDifference);
    }

    public static void main(String args[]) throws IOException
    {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        System.out.println("Enter details of start date: ");
        System.out.print("Enter Day: ");
        int sDay = Integer.parseInt(br.readLine());
        System.out.print("Enter Month: ");
        int sMonth = Integer.parseInt(br.readLine());
        System.out.print("Enter Year: ");
        int sYear = Integer.parseInt(br.readLine());
        if(!DateValidation(sDay, sMonth, sYear))
        {
            System.out.println("\nStart date: "+sDay+"/"+sMonth+"/"+sYear+" is invalid");
            System.exit(0);
        }
        System.out.print("Start date: "+sDay+"/"+sMonth+"/"+sYear);

        System.out.println("\n\nEnter details of end date: ");
        System.out.print("Enter Day: ");
        int eDay = Integer.parseInt(br.readLine());
        System.out.print("Enter Month: ");
        int eMonth = Integer.parseInt(br.readLine());
        System.out.print("Enter Year: ");
        int eYear = Integer.parseInt(br.readLine());
        if(!DateValidation(eDay, eMonth, eYear))
        {
            System.out.println("\nEnd date: "+eDay+"/"+eMonth+"/"+eYear+" is invalid");
            System.exit(0);
        }
        System.out.print("End date: "+eDay+"/"+eMonth+"/"+eYear);

        DifferenceBetweenTwoDates(sDay,sMonth,sYear,eDay,eMonth,eYear);
    }
}