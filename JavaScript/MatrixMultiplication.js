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

        for(let i=0; i<Ar; i++) {
            for(let j=0; j<Bc; j++) {
                console.log(result[i][j]);
            }
        }
    } else {
        console.log('Matrix Multiplication Not Possible');
    }
}

let Ar=3;
let Ac=3;
let Br=3;
let Bc=3;

let matrixA = [[1,2,3],[2,3,4],[3,4,5]];
let matrixB = [[2,3,4],[3,4,5],[4,5,6]];

matrixMultiplication(Ar,Ac,Br,Bc,matrixA,matrixB);