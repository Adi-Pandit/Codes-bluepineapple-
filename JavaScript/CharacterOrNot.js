function isCharacter(character) {
    if(character.length===1 && character.match('[a-zA-Z]')) {
        return true;
    }
    return false;
}

let character = 'A';
console.log(isCharacter(character));