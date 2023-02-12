function isCharacter(character) {
    if(character.length===1 && character.match('[a-zA-Z]')) {
        return true;
    }
    return false;
}

function testCase(character, expectedResult) {
    if(isCharacter(character)===expectedResult)
        console.log(`Test Case Sucessful for ${character}`);
    else    
        console.log(`Test Case Unsucessful for ${character}`);
}
 
testCase('A',true);
testCase('5',false);