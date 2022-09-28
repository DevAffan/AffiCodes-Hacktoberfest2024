// Generate fibonacci series up to Given terms

// take input from the user
const number = parseInt(prompt('Enter the number of terms: '));
let num1 = 0, num2 = 1, nextTerm;

console.log('Fibonacci Series:');

for (let i = 1; i <= number; i++) {
    console.log(num1);
    nextTerm = num1 + num2;
    num1 = num2;
    num2 = nextTerm;
}