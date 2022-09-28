// find the factorial of a positive integer
// user input
const number = parseInt(prompt('Enter a positive integer: '));

// checking if number is negative returns Error
if (number < 0) {
    console.log('Error! Factorial for negative number does not exist.');
}

// if number = 0
else if (number === 0) {
    console.log(`The factorial of ${number} is 1.`);
}

// if number is positive then
else {
    let factor = 1;
    for (i = 1; i <= number; i++) {
        factor *= i;
    }

    //Factorial Output
    console.log(`The factorial of ${number} is ${factor}.`);
}