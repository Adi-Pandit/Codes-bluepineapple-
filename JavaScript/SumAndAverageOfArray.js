function sum(arrayOfNumbers, len) {
    if(len==0) 
        return arrayOfNumbers[0];
    else    
        return arrayOfNumbers[len]+sum(arrayOfNumbers,--len);
}

let arr = [1,2,3,4,5,6,7,8,9];
let Sum = sum(arr,arr.length-1);
console.log('Sum: '+Sum);
console.log('Average: '+Sum/arr.length);