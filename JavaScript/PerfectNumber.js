function isPerfectNumber(num) {
    let sum = 0;
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
let num = 13;
if(isPerfectNumber(num)) 
    console.log('Perfect Number');
else    
    console.log('Not Perfect Number');







