function DateDifference(firstDate, lastDate) {
    var startDate = new Date(firstDate);
    var endDate = new Date(lastDate);

    var timeDifference = endDate.getTime() - startDate.getTime();

    if(timeDifference<0)
        return false;

    var dayDifference = timeDifference / (1000*60*60*24);

    return dayDifference;
}

function testFunction(firstDate, lastDate, expectedResult) {
    if(DateDifference(firstDate,lastDate)===expectedResult) 
        return 'Pass';
    else    
        return 'Not pass';
}

console.log('Test Cases:');
console.log('\nStart Date\tEnd Date\tActual Result\tExpected Result\tTest Case');
console.log('04/23/2000\t04/30/2000\t'+DateDifference('04/23/2000','04/30/2000')+'\t\t'+7+'\t\t'+testFunction('04/23/2000','04/30/2000',7));
console.log('02/25/2004\t03/25/2006\t'+DateDifference('02/25/2004','03/25/2006')+'\t\t'+759+'\t\t'+testFunction('02/25/2004','03/25/2006',759));
console.log('02/23/2000\t01/30/2004\t'+DateDifference('02/23/2000','01/30/2004')+'\t\t'+1437+'\t\t'+testFunction('02/23/2000','01/30/2004',1437));