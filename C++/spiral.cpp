#include <iostream>
#include <vector>

using namespace std;

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> result;
    
    if(matrix.empty()) return result;
    
    int top = 0;
    int bottom = matrix.size() - 1;
    int left = 0;
    int right = matrix[0].size() - 1;
    
    while (top <= bottom && left <= right) {
        // Traverse from left to right across the top row
        for (int i = left; i <= right; i++) {
            result.push_back(matrix[top][i]);
        }
        top++;
        
        // Traverse down the right column
        for (int i = top; i <= bottom; i++) {
            result.push_back(matrix[i][right]);
        }
        right--;
        
        // Traverse from right to left across the bottom row (if still valid)
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                result.push_back(matrix[bottom][i]);
            }
            bottom--;
        }
        
        // Traverse up the left column (if still valid)
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                result.push_back(matrix[i][left]);
            }
            left++;
        }
    }
    
    return result;
}

int main() {
    int m, n;
    
    // Taking the number of rows and columns as input
    cout << "Enter number of rows (m): ";
    cin >> m;
    cout << "Enter number of columns (n): ";
    cin >> n;

    // Declaring the matrix
    vector<vector<int>> matrix(m, vector<int>(n));
    
    // Taking matrix elements as input
    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    // Get the elements in spiral order
    vector<int> result = spiralOrder(matrix);
    
    // Print the result in spiral order
    cout << "Spiral order of the matrix is: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
