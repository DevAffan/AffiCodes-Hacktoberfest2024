#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();
        int maxcount = -1, index = -1;

        // Iterate over each row
        for (int i = 0; i < n; i++)
        {
            int countrow = 0; // Initialize countrow for each row

            // Count the number of 1s in the current row
            for (int j = 0; j < m; j++)
            {
                countrow += mat[i][j]; // Since mat[i][j] is either 0 or 1, just add it
            }

            // Update maxcount and index if this row has more 1s
            if (countrow > maxcount)
            {
                maxcount = countrow;
                index = i;
            }
        }

        // Return the index of the row and the maximum number of 1s
        return {index, maxcount};
    }
};

// Main function to test the rowAndMaximumOnes function
int main()
{
    Solution sol;

    // Example matrix
    vector<vector<int>> matrix = {
        {0, 1, 1},
        {1, 1, 1},
        {0, 0, 0}};

    // Call the function and get the result
    vector<int> result = sol.rowAndMaximumOnes(matrix);

    // Print the result
    cout << "Row with maximum 1s: " << result[0] << endl;
    cout << "Number of 1s in that row: " << result[1] << endl;

    return 0;
}
