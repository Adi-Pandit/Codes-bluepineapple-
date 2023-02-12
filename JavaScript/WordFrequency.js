const fs = require("fs");

fs.readFile("JavaScript/Test.txt", (err, data) => {
    if (err) throw err;
    console.log(data.toString());

    let words = data.toString().replace(/[^a-zA-Z0-9 ]/g, '').split(' ');
    console.log(words);

    dictOfWords = {'for':4,'is':10,'of':55,'in':14,'great':1,'with':6,'epic':2,'the':65,'and':29};

    let count = 0;
    console.log('Test Cases:');
    console.log('\nWord\tActual Result\tExpected Result\tTest Case');
    for(let word in dictOfWords) {
        for(let i=0; i<words.length; i++) {
            if(word==words[i])
                count++;
        }
        if(count==dictOfWords[word])
            console.log(word+'\t'+count+'\t\t'+dictOfWords[word]+'\t\t'+'Pass');
        else    
            console.log(word+'\t'+count+'\t\t'+dictOfWords[word]+'\t\t'+'Not pass');
        count = 0;
    }
});