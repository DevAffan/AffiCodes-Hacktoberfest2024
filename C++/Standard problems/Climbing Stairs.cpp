#include <iostream>
using namespace std;

// Function to calculate the number of ways to climb stairs
int climbStairs(int n) {
    if (n == 1) return 1;
    int first = 1, second = 2;
    for (int i = 3; i <= n; i++) {
        int third = first + second;
        first = second;
        second = third;
    }
    return second;
}

int main() {
    // Test cases
    int n;

    // Input for the number of steps
    cout << "Enter the number of steps: ";
    cin >> n;

    // Call the climbStairs function and print the result
    int result = climbStairs(n);
    cout << "Number of distinct ways to climb " << n << " steps: " << result << endl;

    return 0;
}
