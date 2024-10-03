#include <iostream>
#include <vector>

using namespace std;

vector<int> wavePrint(vector<vector<int>> arr, int nRows, int mCols)
{
    vector<int> ans;
    for (int j = 0; j < mCols; j++)
    {
        if (j % 2 == 1)
        {
            // Odd column index: bottom to top traversal
            for (int i = nRows - 1; i >= 0; i--)
            {
                ans.push_back(arr[i][j]);
            }
        }
        else
        {
            // Even column index: top to bottom traversal
            for (int i = 0; i < nRows; i++)
            {
                ans.push_back(arr[i][j]);
            }
        }
    }
    return ans;
}

int main()
{
    // Example input
    vector<vector<int>> arr = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};

    int nRows = arr.size();
    int mCols = arr[0].size();

    // Calling wavePrint function
    vector<int> result = wavePrint(arr, nRows, mCols);

    // Output the result
    for (int val : result)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
