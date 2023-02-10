function isPalindrome(str) {
    for(let i=0,j=str.length-1; i<j; i++,j--) {
        if(str[i]!=str[j]) {
            return false;
        }     
    }
    return true;
}

let str = 'ABCDBA'
if(isPalindrome(str))
    console.log("Palindrome");
else    
    console.log("Not Palindrome");


