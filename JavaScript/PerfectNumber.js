function isPerfectNumber(num) {
    let sum = 0;
    if(num<=0)
        return false;

    for(let i=1; i<=Math.trunc(num/2); i++) {
        if(num%i==0) {
            sum += i;
        }
    }
    if(sum==num)
        return true;
    else    
        return false;
}

function testFunction(num, expectedResult) {
    if(isPerfectNumber(num)===expectedResult)
        return 'Pass';
    else    
        return 'Not pass';
}

console.log('Test Cases:');
console.log('\nNumber\tActual Result\tExpected Result\tTest Case');
console.log(3+'\t'+isPerfectNumber(3)+'\t\t'+false+'\t\t'+testFunction(3, false));
console.log(6+'\t'+isPerfectNumber(6)+'\t\t'+true+'\t\t'+testFunction(6, true));
console.log(-9+'\t'+isPerfectNumber(-9)+'\t\t'+false+'\t\t'+testFunction(-9, false));
console.log(0+'\t'+isPerfectNumber(0)+'\t\t'+false+'\t\t'+testFunction(0, false));
console.log(28+'\t'+isPerfectNumber(28)+'\t\t'+true+'\t\t'+testFunction(28, true));








