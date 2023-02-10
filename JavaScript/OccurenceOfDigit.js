
function CalculateOccuranceOfDigit(num) {
    let occuranceOfDigit = [0,0,0,0,0,0,0,0,0,0];

    while(num>0) {
        occuranceOfDigit[num%10]++;
        num = Math.trunc(num/10);
    }

    for(let i=0; i<occuranceOfDigit.length; i++) {
        console.log(`${i} appears for ${occuranceOfDigit[i]}`);
    }
}

let num = 1234567890;
CalculateOccuranceOfDigit(num);
