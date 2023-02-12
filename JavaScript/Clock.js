function Clock(indicatedHour, indicatedMin, extraTime) {
    let actualHour = 0;
    let actualMin = 0;
    let hour = 0;

    if(indicatedHour<0 || indicatedMin<0)
        return false;

    while(actualHour<indicatedHour) {
        if((actualMin+extraTime)<60) {
            actualHour++;
            actualMin += extraTime;
            hour++;
        } else if((actualMin+extraTime)>=60) {
            actualHour += 2;
            actualMin = (actualMin+extraTime)-60;
            hour++;
        }
    }
    return hour;
}

function testFunction(indicatedHour, indicatedMin, extraTime, expectedResult)
{
	if(Clock(indicatedHour, indicatedMin, extraTime)===expectedResult)
		return 'Pass';
	else	
		return 'Not pass';
}

console.log('Test Cases:');
console.log('\nIndicated Time\tActual Result\tExpected Result\tTest Case');
console.log('9:20\t\t'+Clock(9, 20, 10)+'\t\t'+8+'\t\t'+testFunction(9, 20, 10, 8));
console.log('12:30\t\t'+Clock(12, 30, 15)+'\t\t'+10+'\t\t'+testFunction(12, 30, 15, 10));
console.log('-12:30\t\t'+Clock(-12, 30, 15)+'\t\t'+false+'\t\t'+testFunction(-12, 30, 15, false));

