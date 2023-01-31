import java.io.*;
import java.util.Hashtable;

public class DateDifference
{
    public static boolean LeapYear(int year)
    {
        if((year%4)==0 && ((year%400)==0 || (year%100)!=0))
            return true;
        else    
            return false;
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
        System.out.print("Start date: "+sDay+"/"+sMonth+"/"+sYear);

        System.out.println("\n\nEnter details of end date: ");
        System.out.print("Enter Day: ");
        int eDay = Integer.parseInt(br.readLine());
        System.out.print("Enter Month: ");
        int eMonth = Integer.parseInt(br.readLine());
        System.out.print("Enter Year: ");
        int eYear = Integer.parseInt(br.readLine());
        System.out.print("End date: "+eDay+"/"+eMonth+"/"+eYear);

        Hashtable<Integer,Integer> monthDays = new Hashtable<Integer,Integer>();
        monthDays.put(1,31);
        monthDays.put(2,28);
        monthDays.put(3,31);
        monthDays.put(4,30);
        monthDays.put(5,31);
        monthDays.put(6,30);
        monthDays.put(7,31);
        monthDays.put(8,31);
        monthDays.put(9,30);
        monthDays.put(10,31);
        monthDays.put(11,30);
        monthDays.put(12,31);

        System.out.println("\nMonth and days: "+monthDays);
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
                dayDifference += monthDays.get(sMonth)-sDay;
                sMonth++;
                while(sMonth<eMonth)
                {
                    dayDifference += monthDays.get(sMonth);
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
            dayDifference += monthDays.get(sMonth)-sDay;
            if(LeapYear(sYear) && sMonth<=2)
                dayDifference += 1;
            sMonth++;
            while(sMonth<=12)
            {
                dayDifference += monthDays.get(sMonth);
                sMonth++;
            }
            sYear++;
            dayDifference += (eYear-sYear)*365;
            int month=1;
            while(month<eMonth)
            {
                dayDifference += monthDays.get(month);
                month++;
            }
            dayDifference += eDay;
            if(LeapYear(eYear) && month>2)
                dayDifference += 1;
        }
        System.out.println("Days: "+dayDifference);
    }
    //Aditya 
}