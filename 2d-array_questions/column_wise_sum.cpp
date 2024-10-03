#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int m, n;
    cout << "Enter the number of rows and columns: ";
    cin >> m >> n;

    vector<vector<int>> arr(m, vector<int>(n));

    // Taking input
    cout << "Enter elements: ";
    for (int i = 0; i < m; i++) // Iterate over rows
    {
        for (int j = 0; j < n; j++) // Iterate over columns
        {
            cin >> arr[i][j];
        }
    }

    // Calculate and output column-wise sum
    for (int j = 0; j < n; j++) // Iterate over columns
    {
        int sum = 0;                // Reset sum for each column
        for (int i = 0; i < m; i++) // Iterate over rows
        {
            sum += arr[i][j]; // Add the element to the column sum
        }

        // Output each element in the column along with the sum
        for (int i = 0; i < m; i++) // Iterate over rows for output
        {
            cout << arr[i][j] << " "; // Print each element in the column
        }

        cout << "-> sum for column " << j + 1 << " is: " << sum << endl;
    }
}
