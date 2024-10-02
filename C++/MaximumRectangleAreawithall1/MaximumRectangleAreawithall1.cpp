#include <bits/stdc++.h>
using namespace std;

// Function to find the largest rectangle area in a histogram
int largestRectangleArea(vector<int>& heights) {
    stack<int> st;  // Stack to store indices of histogram bars
    int maxArea = 0;  // Variable to store the maximum area
    int n = heights.size();  // Size of the histogram
    
    // Traverse all bars in the histogram
    for (int i = 0; i <= n; i++) {
        // If the current bar is smaller than the bar at the stack's top or we reached the end,
        // pop from the stack and calculate the area for the popped bar.
        while (!st.empty() && (i == n || heights[st.top()] >= heights[i])) {
            int height = heights[st.top()];  // Height of the popped bar
            st.pop();
            
            // Calculate width: if the stack is empty, the bar extends from the start
            // Else, it extends from the next smaller bar in the stack.
            int width;
            if (st.empty())
                width = i;
            else
                width = i - st.top() - 1;
            
            // Calculate the area with the popped bar as the smallest height
            maxArea = max(maxArea, height * width);
        }
        // Push the current index to the stack
        st.push(i);
    }
    return maxArea;
}

// Function to find the maximal area of a submatrix consisting of all 1's
int maximalAreaOfSubMatrixOfAll1(vector<vector<int>>& mat, int n, int m) {
    int maxArea = 0;  // Store the maximum area of the submatrix
    vector<int> height(m, 0);  // Vector to store heights for the histogram
    
    // Traverse each row of the matrix
    for (int i = 0; i < n; i++) {
        // Update the height vector based on the current row
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == 1)
                height[j]++;  // Increment height if the cell is 1
            else
                height[j] = 0;  // Reset height to 0 if the cell is 0
        }
        
        // Calculate the largest rectangle area for the current histogram row
        int area = largestRectangleArea(height);
        
        // Update the maximum area found so far
        maxArea = max(maxArea, area);
    }
    return maxArea;
}

int main() {
    // Input number of rows and columns
    int n, m;
    cout << "Enter the number of rows: ";
    cin >> n;
    cout << "Enter the number of columns: ";
    cin >> m;
    
    vector<vector<int>> mat(n, vector<int>(m));
    
    // Input the matrix values
    cout << "Enter the matrix elements (0 or 1):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
        }
    }
    
    // Find and print the maximum area of a submatrix consisting of all 1's
    int maxArea = maximalAreaOfSubMatrixOfAll1(mat, n, m);
    cout << "The maximum area is: " << maxArea << "\n";
    
    return 0;
}
