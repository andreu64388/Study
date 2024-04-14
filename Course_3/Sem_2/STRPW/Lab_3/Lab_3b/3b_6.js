
const calculateSquare=(number)=> {
    return new Promise((resolve, reject) => {
        setTimeout(() => {
            if (typeof number !== 'number') {
                reject(new Error('Invalid input, please provide a valid number'));
            } else {
                resolve(number * number);
            }
        }, 1000);
    });
}

const calculateCube=(number)=> {
    return new Promise((resolve, reject) => {
        setTimeout(() => {
            if (typeof number !== 'number') {
                reject(new Error('Invalid input, please provide a valid number'));
            } else {
                resolve(number * number * number);
            }
        }, 2000);
    });
}


const calculateFourthPower=(number)=> {
    return new Promise((resolve, reject) => {
        setTimeout(() => {
            if (typeof number !== 'number') {
                reject(new Error('Invalid input, please provide a valid number'));
            } else {
                resolve(number * number * number * number);
            }
        }, 3000);
    });
}


const inputNumber = 3;

Promise.race([
    calculateSquare(inputNumber),
    calculateCube(inputNumber),
    calculateFourthPower(inputNumber)
])
    .then((result) => {
        console.log('First resolved result:', result);
    })
    .catch((error) => {
        console.error('Error:', error.message);
    });


Promise.any([
    calculateSquare(inputNumber),
    calculateCube(inputNumber),
    calculateFourthPower(inputNumber)
])
    .then((result) => {
        console.log('First resolved result using Promise.any():', result);
    })
    .catch((error) => {
        console.error('Error:', error.message);
    });
