function NumberOfDigits(num) {
    let count = 0;
    while(num>0) {
        num = Math.trunc(num/10);
        count++;
    }
    console.log(count);
}
let num = 12345321;
NumberOfDigits(num);
