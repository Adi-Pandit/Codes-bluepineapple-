function getAsciiValue(character) {
    let asciiValue = character.charCodeAt(0);
    return asciiValue;
}

function getBinaryConversion(number) {
    let binaryConversion = []
    while(number>0) {
        let remainder = number%2;
        number = Math.trunc(number/2); 
        binaryConversion.push(remainder);
    }
    return binaryConversion;
}

function getDecimalConversion(binaryConversion) {
    let sum = 0;
    for(let i=0; i<binaryConversion.length; i++) {
        sum += Math.pow(2,i)*binaryConversion[i];
    }
    return sum;
}

function flipBit(character, offset) {
    let asciiValue = getAsciiValue(character);
    let binaryConversion = getBinaryConversion(asciiValue);
    if(offset<=binaryConversion.length && offset>=0) {
        if(binaryConversion[offset-1]==0)
            binaryConversion[offset-1]=1;
        else if(binaryConversion[offset-1]==1)
            binaryConversion[offset-1]=0;
        return String.fromCharCode(getDecimalConversion(binaryConversion));
    }
    else
        return false; 
}

function testFunction(character, offset, expectedResult) {
    if(flipBit(character, offset)===expectedResult)
        return 'Pass';
    else    
        return 'Not pass'; 
}

console.log('Test Cases:');
console.log('\nCharacter\tOffset\tActual Result\tExpected Result\tTest Case');
console.log('A'+'\t\t'+5+'\t'+flipBit('A', 5)+'\t\tQ'+'\t\t'+testFunction('A', 5, 'Q'));
console.log('a'+'\t\t'+3+'\t'+flipBit('a', 3)+'\t\te'+'\t\t'+testFunction('a', 3, 'e'));
console.log('A'+'\t\t'+10+'\t'+flipBit('A', 10)+'\t\t'+false+'\t\t'+testFunction('A', 10, false));
console.log('empty char'+'\t'+5+'\t'+flipBit(' ', 5)+'\t\t0'+'\t\t'+testFunction(' ', 5, '0'));
console.log('Z'+'\t\t'+4+'\t'+flipBit('Z', 4)+'\t\tR'+'\t\t'+testFunction('Z', 4, 'R'));

