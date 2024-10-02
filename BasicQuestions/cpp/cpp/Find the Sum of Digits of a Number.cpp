#include <iostream>
using namespace std;

int main() {
    int num, sum = 0, remainder;

    // Prompt user to input an integer
    cout << "Enter an integer: ";
    cin >> num;
    
    // Loop to calculate the sum of digits
    while(num != 0) {
        remainder = num % 10; // Get the last digit
        sum += remainder;     // Add it to the sum
        num /= 10;            // Remove the last digit
    }
    
    // Output the result
    cout << "Sum of digits: " << sum << endl;
    return 0;
}
