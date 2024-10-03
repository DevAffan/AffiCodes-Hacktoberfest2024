#include <iostream>
#include <vector>
using namespace std;

class Solution
{
private:
    // Function to find the lower bound of 'x' in the sorted array 'arr'
    int lowerbound(vector<int> &arr, int n, int x)
    {
        int low = 0, high = n - 1;
        int ans = n; // Initialize answer to n (out of bounds)

        // Binary search for the lower bound
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (arr[mid] >= x)
            {
                ans = mid; // Update the answer
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }

public:
    // Function to find the row with the maximum number of 1s
    vector<int> rowAndMaximumOnes(vector<vector<int>> &mat)
    {
        int n = mat.size();    // Number of rows
        int m = mat[0].size(); // Number of columns
        int count_max = -1, index = -1;

        // Iterate through each row
        for (int i = 0; i < n; i++)
        {
            // Find the number of 1s in the current row using lowerbound
            int count = m - lowerbound(mat[i], m, 1);

            // Update if the current row has more 1s
            if (count > count_max)
            {
                count_max = count;
                index = i;
            }
        }

        // Return the index of the row and the maximum number of 1s
        return {index, count_max};
    }
};

// Main function to test the rowAndMaximumOnes function
int main()
{
    Solution sol;

    // Example matrix
    vector<vector<int>> matrix = {
        {0, 0, 0},
        {0, 1, 1},
        {1, 1, 1}};

    // Call the function and get the result
    vector<int> result = sol.rowAndMaximumOnes(matrix);

    // Print the result
    cout << "Row with maximum 1s: " << result[0] << endl;
    cout << "Number of 1s in that row: " << result[1] << endl;

    return 0;
}
