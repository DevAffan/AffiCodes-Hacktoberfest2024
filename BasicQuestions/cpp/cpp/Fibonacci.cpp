#include <iostream>
using namespace std;

int main() {
    int n, t1 = 0, t2 = 1, nextTerm = 0;

    // Prompt user to enter the number of terms in the Fibonacci series
    cout << "Enter the number of terms: ";
    cin >> n;
    
    // Output the first two terms of the Fibonacci series
    cout << "Fibonacci Series: " << t1 << ", " << t2 << ", ";
    
    // Loop starts from the 3rd term to the nth term
    for(int i = 3; i <= n; ++i) {
        // Calculate the next term by adding the previous two terms
        nextTerm = t1 + t2;

        // Output the current term
        cout << nextTerm << ", ";

        // Update t1 and t2 to the next pair of terms in the sequence
        t1 = t2;
        t2 = nextTerm;
    }
    
    // Print a newline character at the end of the output
    cout << endl;
    
    return 0;
}
