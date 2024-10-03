#include <iostream>
#include <vector>
#include <limits.h> // Include limits.h for INT_MIN
using namespace std;

int largestrowsum(vector<vector<int>> &arr, int m, int n, int &rowIndex)
{
    int maxi = INT_MIN;
    for (int i = 0; i < m; i++)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            sum += arr[i][j];
        }
        if (sum > maxi)
        {
            maxi = sum;
            rowIndex = i; // Store the index of the row with the largest sum
        }
    }
    return maxi; // Return the maximum sum
}

int main()
{
    int m, n;
    cout << "Enter the number of rows and columns: ";
    cin >> m >> n;
    cout << "Enter elements:" << endl;
    vector<vector<int>> arr(m, vector<int>(n));

    // For taking input
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    // For output
    cout << "The matrix is:" << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }

    int rowIndex = -1;                               // To keep track of the row with the largest sum
    int maxSum = largestrowsum(arr, m, n, rowIndex); // Call the function

    // Print the maximum sum and the row index
    cout << "Maximum sum is " << maxSum << " at row index " << rowIndex + 1 << endl;

    return 0;
}
