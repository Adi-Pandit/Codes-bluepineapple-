function isCharacter(character) {
    if(character.length===1 && character.match('[a-zA-Z]')) {
        return true;
    }
    return false;
}

function testFunction(character, expectedResult) {
    if(isCharacter(character)===expectedResult)
        return 'Pass';
    else    
        return 'Not pass';
}

console.log('Test Cases:');
console.log('\nCharacter\tActual Result\tExpected Result\tTest Case');
console.log('A\t\t'+isCharacter('A')+'\t\t'+true+'\t\t'+testFunction('A', true));
console.log('5\t\t'+isCharacter('5')+'\t\t'+false+'\t\t'+testFunction('5', false));
console.log('AB\t\t'+isCharacter('AB')+'\t\t'+false+'\t\t'+testFunction('AB', false));
console.log('empty char\t'+isCharacter(' ')+'\t\t'+false+'\t\t'+testFunction(' ', false));
console.log('#\t\t'+isCharacter('#')+'\t\t'+false+'\t\t'+testFunction('#', false));
