
let root = {
    value : 10,
    N1 : {
        value : 5,
        N3 : {
            value : 2
        }
    },
    N2 : {
        value : 7,
        N4 : {
            value : 6
        },
        N5 : {
            value : 3
        }
    }
}
console.log("Root: "+root.value);
console.log("N1: "+root.N1.value);
console.log("N2: "+root.N2.value);
console.log("N3: "+root.N1.N3.value);
console.log("N4: "+root.N2.N4.value);
console.log("N5: "+root.N2.N5.value);
console.log(root.N1.N5);
