function NumberOfDigits(num) {
    let count = 0;
    if(num==0)
        return 1;
    else if(num<0)
        num = -num;
    while(num>0) {
        num = Math.trunc(num/10);
        count++;
    }
    return count;
}

function testFunction(num, expectedResult) {
    if(NumberOfDigits(num)===expectedResult)
        return 'Pass';
    else    
        return 'Not pass';
}

let num = 0;
console.log('Test Cases:');
console.log('\nNumber\tActual Result\tExpected Result\tTest Case');
console.log(num+'\t'+NumberOfDigits(num)+'\t\t'+1+'\t\t'+testFunction(num, 1));
for(let i=0; i<5; i++) {
    num = Math.pow(10,i) + num;
    console.log(num+'\t'+NumberOfDigits(num)+'\t\t'+(i+1)+'\t\t'+testFunction(num, i+1));
}
console.log(-12345+'\t'+NumberOfDigits(-12345)+'\t\t'+5+'\t\t'+testFunction(-12345, 5));
