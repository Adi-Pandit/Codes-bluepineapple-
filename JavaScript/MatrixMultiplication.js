function matrixMultiplication(Ar,Ac,Br,Bc,matrixA,matrixB) {
    if(Ac==Br) {
        let result = new Array(Ar);
        for(let i=0; i<Bc; i++) {
            result[i] = new Array(Bc);
        }

        for(let i=0; i<Ar; i++) {
			for(let j=0; j<Ac; j++) {
				result[i][j] = 0;
				for(let k=0; k<Bc; k++) {
					result[i][j] += matrixA[i][k]*matrixB[k][j]; 
				}
			}
		}
        return result;
        /*for(let i=0; i<Ar; i++) {
            for(let j=0; j<Bc; j++) {
                console.log(result[i][j]);
            }
        }*/
    } else {
        return false;
    }
}

function testFunction(Ar,Ac,Br,Bc,matrixA,matrixB,expectedResult) {
    let actualResult = matrixMultiplication(Ar,Ac,Br,Bc,matrixA,matrixB);
    for(let i=0; i<Ar; i++) {
        for(let j=0; j<Bc; j++) {
            if(actualResult[i][j]!=expectedResult[i][j])
                return 'Not Pass';
            else    
                return 'Pass';
        }
    }
}

console.log('Test Cases:');

let Ar=3,Ac=3,Br=3,Bc=3;
let matrixA = [[1,2,3],[2,3,4],[3,4,5]];
let matrixB = [[2,3,4],[3,4,5],[4,5,6]];
let expectedResult = [[20,26,32],[29,38,47],[38,50,62]];
console.log('\nTC01:');
console.log('Matrix A:')
for(let i=0; i<Ar; i++) {
    console.log(matrixA[i]);
}
console.log('Matrix B:');
for(let i=0; i<Ar; i++) {
    console.log(matrixB[i]);
}
console.log('Actual Result:');
let actualResult = matrixMultiplication(Ar,Ac,Br,Bc,matrixA,matrixB);
for(let i=0; i<Ar; i++) {
    console.log(actualResult[i]);
}
console.log('Expected Result: ');
for(let i=0; i<Ar; i++) {
    console.log(expectedResult[i]);
}
console.log('Test Case: '+testFunction(Ar,Ac,Br,Bc,matrixA,matrixB,expectedResult));

Ar=Ac=Br=Bc=2;
matrixA = [[1,2],[3,4]];
matrixB = [[2,3],[4,5]];
expectedResult = [[10,13],[22,29]];
console.log('\nTC02:');
console.log('Matrix A:')
for(let i=0; i<Ar; i++) {
    console.log(matrixA[i]);
}
console.log('Matrix B:');
for(let i=0; i<Ar; i++) {
    console.log(matrixB[i]);
}
console.log('Actual Result:');
actualResult = matrixMultiplication(Ar,Ac,Br,Bc,matrixA,matrixB);
for(let i=0; i<Ar; i++) {
    console.log(actualResult[i]);
}
console.log('Expected Result: ');
for(let i=0; i<Ar; i++) {
    console.log(expectedResult[i]);
}
console.log('Test Case: '+testFunction(Ar,Ac,Br,Bc,matrixA,matrixB,expectedResult));
