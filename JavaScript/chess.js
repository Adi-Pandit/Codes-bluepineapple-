let knightRowPosition = 'b';
let knightColumnPosition = 2;
let queenRowPosition = 'f';
let queenColumnPosition = 6;

//Condition Checking For Valid Position of Queen and Knight
if(knightRowPosition<'a' || knightRowPosition>'h') {
    console.log("Wrong position entered for knight");
    return;
} else if(knightColumnPosition<1 || knightColumnPosition>8) {
    console.log("Wrong position entered for knight");
    return;
} else if(queenRowPosition<'a' || queenRowPosition>'h') {
    console.log("Wrong position entered for queen");
    return;
} else if(queenColumnPosition<1 || queenColumnPosition>8) {
    console.log("Wrong position entered for queen");
    return;
} else if(queenRowPosition==knightRowPosition && queenColumnPosition==knightColumnPosition) {
    console.log("Both knight and queen cannot be placed on same place");
    return;
}

//Coverting row position into numerical values for easy computation
let rowMapping = { 'a': 1, 'b': 2, 'c': 3, 'd': 4, 'e': 5, 'f': 6, 'g': 7, 'h': 8, };

knightRowPosition = rowMapping[knightRowPosition];
queenRowPosition = rowMapping[queenRowPosition];

let Qrow = queenRowPosition;
let Qcol = queenColumnPosition;
let Krow = knightRowPosition;
let Kcol = knightColumnPosition;

let flag = 0;

//Code for queen attacks knight or not

if(knightColumnPosition==queenColumnPosition || knightRowPosition==queenRowPosition) {
    console.log('Queen can attack knight');
    flag=1;
} else if(queenRowPosition<knightRowPosition) {
    for(let i=0; i<Krow-Qrow; i++) {
        if(queenColumnPosition<knightColumnPosition) {
            queenRowPosition++;
            queenColumnPosition++; 
        } else if(queenColumnPosition>knightColumnPosition) {
            queenRowPosition++;
            queenColumnPosition--;
        }
        if(knightRowPosition===queenRowPosition && knightColumnPosition===queenColumnPosition) {
            console.log('Queen can attack knight');
            flag=1;
            break; 
        }
    }
} else if(queenRowPosition>knightRowPosition) {
    for(let i=0; i<Qrow-Krow; i++) {
        if(queenColumnPosition<knightColumnPosition) {
            queenRowPosition--;
            queenColumnPosition++;
        }
        else if(queenColumnPosition>knightColumnPosition) {
            queenRowPosition--;
            queenColumnPosition--;
        }
        if(knightRowPosition===queenRowPosition && knightColumnPosition===queenColumnPosition) {
            console.log('Queen can attack knight');
            flag=1;
            break; 
        }
    }
}

//Code for knight attacks queen or not
if(Qrow==knightRowPosition-2 && Qcol==knightColumnPosition-1) {
    console.log('Knight can attack Queen');
    flag=1;
} else if(Qrow==knightRowPosition+2 && Qcol==knightColumnPosition-1) {
    console.log('Knight can attack Queen');
    flag=1;
} else if(Qrow==knightRowPosition-2 && Qcol==knightColumnPosition+1) {
    console.log('Knight can attack Queen');
    flag=1;
} else if(Qrow==knightRowPosition+2 && Qcol==knightColumnPosition+1) {
    console.log('Knight can attack Queen');
    flag=1;
} else if(Qrow==knightRowPosition-1 && Qcol==knightColumnPosition+2) {
    console.log('Knight can attack Queen');
    flag=1;
} else if(Qrow==knightRowPosition-1 && Qcol==knightColumnPosition-2) {
    console.log('Knight can attack Queen');
    flag=1;
} else if(Qrow==knightRowPosition+1 && Qcol==knightColumnPosition+2) {
    console.log('Knight can attack Queen');
    flag=1;
} else if(Qrow==knightRowPosition+1 && Qcol==knightColumnPosition-2) {
    console.log('Knight can attack Queen');
    flag=1;
}

//Code for no one attack each other
if(flag==0) {
    console.log("No one attack each other");
}
