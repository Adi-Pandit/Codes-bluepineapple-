let character = 'A';
let offset = 5;

let asciiValue = character.charCodeAt(0);
let binaryConversion = []

while(asciiValue>0) {
    let remainder = asciiValue%2;
    asciiValue = Math.trunc(asciiValue/2); 
    binaryConversion.push(remainder);
}

if(offset>binaryConversion.length) {
    let extraBit = offset-binaryConversion.length;
    for(let i=0; i<extraBit; i++) {
        binaryConversion.push(0);
    }
    binaryConversion.push(1); 
} else if(offset<binaryConversion.length) {
    if(binaryConversion[offset-1]==0)
        binaryConversion[offset-1]=1;
    else if(binaryConversion[offset-1]==1)
        binaryConversion[offset-1]=0;
}

let sum = 0;
for(let i=0; i<binaryConversion.length; i++) {
    sum += Math.pow(2,i)*binaryConversion[i];
}

//console.log(binaryConversion);
console.log(String.fromCharCode(sum));

