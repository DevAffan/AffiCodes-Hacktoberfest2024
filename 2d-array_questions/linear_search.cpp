#include <iostream>
#include <vector>
using namespace std;

// Function to check if the target element is present in the matrix
bool ispresent(vector<vector<int>> &arr, int target, int n, int m)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] == target)
            {
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int m, n;
    cout << "Enter the number of rows and columns: ";
    cin >> m >> n;

    vector<vector<int>> arr(m, vector<int>(n));

    // Taking input
    cout << "Enter the elements of the matrix:\n";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    // Displaying the matrix
    cout << "The matrix is:\n";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // Searching for the target element
    int target;
    cout << "Element to be searched-> ";
    cin >> target;

    // Check if the element is present in the matrix
    if (ispresent(arr, target, n, m))
    {
        cout << "Element present\n";
    }
    else
    {
        cout << "Element not present\n";
    }

    return 0;
}
