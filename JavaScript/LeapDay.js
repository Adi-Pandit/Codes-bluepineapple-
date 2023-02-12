function validateDate(day, month, year) {
	let daysArray = [31,28,31,30,31,30,31,31,30,31,30,31];
	let leapDayArray = [31,29,31,30,31,30,31,31,30,31,30,31];

	if(year>0) {
		if(month>0 && month<=12) {
			if(day>=1 && day<=leapDayArray[month-1] && (year%4==0) && ((year%400==0) || (year%100!=0)))
				return true;
			else if(day>=1 && day<=daysArray[month-1])
				return true;
			else	
				return false;
		} else
			return false;
    } else
		return false;
}

function isLeapDay(day, month, year){
    if(validateDate(day,month,year)) {
        if((year%4==0) && ((year%400==0) || (year%100!=0)) && (month==2) && (day==29)) 
            return true;
        else
            return false;
    } else  
        return false;
}

function testFunction(day, month, year, ExpectedResult)
{
	if(isLeapDay(day,month,year)===ExpectedResult)
		return 'Pass';
	else	
		return 'Not pass';
}

console.log('Test Cases:');
console.log('\nDate\t\tActual Result\tExpected Result\tTest Case');
console.log('29/02/2022\t'+isLeapDay(29,02,2022)+'\t\t'+false+'\t\t'+testFunction(29,02,2022, false));
console.log('29/02/2024\t'+isLeapDay(29,02,2024)+'\t\t'+true+'\t\t'+testFunction(29,02,2024, true));
console.log('29/02/2026\t'+isLeapDay(29,02,2026)+'\t\t'+false+'\t\t'+testFunction(29,02,2026, false));
console.log('29/02/2028\t'+isLeapDay(29,02,2028)+'\t\t'+true+'\t\t'+testFunction(29,02,2028, true));
console.log('29/02/2030\t'+isLeapDay(29,02,2030)+'\t\t'+false+'\t\t'+testFunction(29,02,2030, false));

