#include <iostream>
using namespace std;

int main() {
    // Declare three 2D arrays: 'a' for the first matrix, 'b' for the second matrix, 
    // and 'result' to store the result of their multiplication
    int a[10][10], b[10][10], result[10][10];
    int r1, c1, r2, c2;

    // Get the number of rows and columns for the first matrix
    cout << "Enter rows and columns for first matrix: ";
    cin >> r1 >> c1;
    
    // Get the number of rows and columns for the second matrix
    cout << "Enter rows and columns for second matrix: ";
    cin >> r2 >> c2;

    // Check if matrix multiplication is possible (columns of first matrix must equal rows of second matrix)
    if (c1 != r2) {
        cout << "Matrix multiplication not possible!" << endl;
        return 0;
    }

    // Input elements for the first matrix 'a'
    cout << "Enter elements of matrix A:" << endl;
    for (int i = 0; i < r1; ++i)
        for (int j = 0; j < c1; ++j)
            cin >> a[i][j];

    // Input elements for the second matrix 'b'
    cout << "Enter elements of matrix B:" << endl;
    for (int i = 0; i < r2; ++i)
        for (int j = 0; j < c2; ++j)
            cin >> b[i][j];

    // Initialize the result matrix with 0s
    for (int i = 0; i < r1; ++i)
        for (int j = 0; j < c2; ++j)
            result[i][j] = 0;

    // Perform matrix multiplication
    // Multiply rows of 'a' by columns of 'b' and store the result in the 'result' matrix
    for (int i = 0; i < r1; ++i)
        for (int j = 0; j < c2; ++j)
            for (int k = 0; k < c1; ++k)
                result[i][j] += a[i][k] * b[k][j];

    // Display the resultant matrix after multiplication
    cout << "Resultant matrix:" << endl;
    for (int i = 0; i < r1; ++i) {
        for (int j = 0; j < c2; ++j)
            cout << result[i][j] << " ";  // Print each element
        cout << endl;  // Newline after each row
    }

    return 0;
}
