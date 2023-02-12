function isPalindrome(str) {
    for(let i=0,j=str.length-1; i<j; i++,j--) {
        if(str[i]!=str[j]) {
            return false;
        }     
    }
    return true;
}

function testFunction(str, expectedResult) {
    if(isPalindrome(str)===expectedResult)
        return 'Pass';
    else    
        return 'Not pass';
}

console.log('Test Cases:');
console.log('\nString\t\tActual Result\tExpected Result\tTest Case');
console.log('ABCBA'+'\t\t'+isPalindrome('ABCBA')+'\t\t'+true+'\t\t'+testFunction('ABCBA', true));
console.log('12321'+'\t\t'+isPalindrome('12321')+'\t\t'+true+'\t\t'+testFunction('12321', true));
console.log('ABCCBA'+'\t\t'+isPalindrome('ABCCBA')+'\t\t'+true+'\t\t'+testFunction('ABCCBA', true));
console.log('ABCDBA'+'\t\t'+isPalindrome('ABCDBA')+'\t\t'+false+'\t\t'+testFunction('ABCDBA', false));
console.log('empty str'+'\t'+isPalindrome(' ')+'\t\t'+true+'\t\t'+testFunction(' ', true));


