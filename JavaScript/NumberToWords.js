function NumberToWords(num) {
    let digitArray = [];
    let oneToNine = ['one','two','three','four','five','six','seven','eight','nine'];
    let tensPlace = ['twenty','thirty','fourty','fifty','sixty','seventy','eighty','ninety'];
    let tenToNineteen = ['ten','eleven','twelve','thirteen','fourteen','fifteen','sixteen','seventeen','eighteen','nineteen'];

    let numberOfDigits = 0;
    let numberInWord = '';

    if(num<0) {
        numberInWord = 'minus ';
        num = -num;
    }

    while(num>0) {
        digitArray.push(num%10);
        num = Math.trunc(num/10);
        numberOfDigits++;
    }
    for(let i=digitArray.length-1; i>=0; i--) {
        if(numberOfDigits==2 && digitArray[i]==1) {
            numberInWord += tenToNineteen[digitArray[i-1]];
            numberOfDigits -= 2;
            i--;
        } else if(numberOfDigits==5 && digitArray[i]==1) {
            numberInWord += tenToNineteen[digitArray[i-1]]+' thousand ';
            numberOfDigits -= 2;
            i--;
        } else if(numberOfDigits==7 && digitArray[i]==1) {
            numberInWord += tenToNineteen[digitArray[i-1]]+' lakh ';
            numberOfDigits -= 2;
            i--;
        } else if(numberOfDigits==9 && digitArray[i]==1) {
            numberInWord += tenToNineteen[digitArray[i-1]]+' crore ';
            numberOfDigits -= 2;
            i--;
        } else {
            switch(numberOfDigits)
            {
                case 1:
                    if(oneToNine[digitArray[i]-1])
                        numberInWord += oneToNine[digitArray[i]-1]+' ';
                    numberOfDigits--;
                    break;
                
                case 2:
                    if(tensPlace[digitArray[i]-2])
                        numberInWord += tensPlace[digitArray[i]-2]+' ';
                    numberOfDigits--;
                    break;
                
                case 3:
                    if(oneToNine[digitArray[i]-1]) 
                        numberInWord += oneToNine[digitArray[i]-1]+' hundred ';
                    if(digitArray[i-1]!=0 || digitArray[i-2]!=0) 
                            numberInWord += 'and ';
                    numberOfDigits--;
                    break;
                
                case 4:
                    if(oneToNine[digitArray[i]-1])
                        numberInWord += oneToNine[digitArray[i]-1]+' thousand ';
                    numberOfDigits--;
                    break;
                
                case 5:
                    if(tensPlace[digitArray[i]-2]) {
                        numberInWord += tensPlace[digitArray[i]-2]+' ';
                        if(digitArray[i-1]==0)
                            numberInWord += tensPlace[digitArray[i]-2]+' thousand ';
                    }
                    numberOfDigits--;
                    break;

                case 6:
                    if(oneToNine[digitArray[i]-1])
                        numberInWord += oneToNine[digitArray[i]-1]+' lakh ';
                    numberOfDigits--;
                    break;
                
                case 7:
                    if(tensPlace[digitArray[i]-2]) {
                        numberInWord += tensPlace[digitArray[i]-2]+' ';
                        if(digitArray[i-1]==0)
                            numberInWord += tensPlace[digitArray[i]-2]+' lakh ';
                    }
                    numberOfDigits--;
                    break;
                
                case 8:
                    if(oneToNine[digitArray[i]-1])
                        numberInWord += oneToNine[digitArray[i]-1]+' crore ';
                    numberOfDigits--;
                    break;
                
                case 9:
                    if(tensPlace[digitArray[i]-2]) {
                        numberInWord += tensPlace[digitArray[i]-2]+' ';
                        if(digitArray[i-1]==0)
                            numberInWord += tensPlace[digitArray[i]-2]+' crore ';
                    }
                    numberOfDigits--;
                    break;
            }
        }
    }
    return numberInWord.trim();
}

let num1 = 9999999;
console.log(NumberToWords(num1));  

function testFunction(num, expectedResult) {
    if(NumberToWords(num)===expectedResult)
        return 'Pass';
    else    
        return 'Not pass';
}

let num = 9;
let expectedResult = 'nine';
console.log('Test Cases:');
console.log('\nTC01:');
console.log('Number: '+num);
console.log('Actual Result: '+NumberToWords(num));
console.log('Expected Result: '+expectedResult);
console.log('Test Case: '+testFunction(num, expectedResult));

num = 999;
expectedResult = 'nine hundred and ninety nine';
console.log('\nTC02:');
console.log('Number: '+num);
console.log('Actual Result: '+NumberToWords(num));
console.log('Expected Result: '+expectedResult);
console.log('Test Case: '+testFunction(num, expectedResult));

num = 99999;
expectedResult = 'ninety nine thousand nine hundred and ninety nine';
console.log('\nTC03:');
console.log('Number: '+num);
console.log('Actual Result: '+NumberToWords(num));
console.log('Expected Result: '+expectedResult);
console.log('Test Case: '+testFunction(num, expectedResult));

num = -9999999
expectedResult = 'minus ninety nine lakh ninety nine thousand nine hundred and ninety nine';
console.log('\nTC04:');
console.log('Number: '+num);
console.log('Actual Result: '+NumberToWords(num));
console.log('Expected Result: '+expectedResult);
console.log('Test Case: '+testFunction(num, expectedResult));