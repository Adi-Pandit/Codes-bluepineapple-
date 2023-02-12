function CalculateOccuranceOfDigit(num) {
    let occuranceOfDigit = [0,0,0,0,0,0,0,0,0,0];

    if(num==0) 
        occuranceOfDigit[0] = 1;
    else if(num<0)
        num = -num;
    
    while(num>0) {
        occuranceOfDigit[num%10]++;
        num = Math.trunc(num/10);
    }
    return occuranceOfDigit;
}

function testFunction(num, expectedResult) {
    let actualResult = CalculateOccuranceOfDigit(num);
    for(let i=0; i<actualResult.length; i++) {
        if(actualResult[i]!=expectedResult[i])
            return 'Not pass';
    }
    return 'Pass';
}

console.log('Test Cases:');
console.log('\nNumber\t\tTest Case');
console.log(123456789+'\t'+testFunction(123456789, [0,1,1,1,1,1,1,1,1,1]));
console.log(123456780+'\t'+testFunction(123456780, [1,1,1,1,1,1,1,1,1,0]));
console.log(2233557799+'\t'+testFunction(2233557799, [0,0,2,2,0,2,0,2,0,2]));
console.log(-234234234+'\t'+testFunction(-234234234, [0,0,3,3,3,0,0,0,0,0]));
console.log(0+'\t\t'+testFunction(0, [1,0,0,0,0,0,0,0,0,0]));
