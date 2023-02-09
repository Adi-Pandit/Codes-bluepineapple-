let num = 999999999;
let digitArray = [];
let oneToNine = ['one','two','three','four','five','six','seven','eight','nine'];
let tensPlace = ['twenty','thirty','fourty','fifty','sixty','seventy','eighty','ninety'];
let tenToNineteen = ['ten','eleven','twelve','thirteen','fourteen','fifteen','sixteen','seventeen','eighteen','nineteen'];

let numberOfDigits = 0;
let numberInWord = '';

while(num>0) {
    digitArray.push(num%10);
    num = Math.trunc(num/10);
    numberOfDigits++;
}
console.log(numberOfDigits);
console.log(digitArray);
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
console.log(numberInWord);  
