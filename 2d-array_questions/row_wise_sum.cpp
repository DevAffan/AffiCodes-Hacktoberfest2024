#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int m, n;
    cout << "Enter the number of rows and columns:";
    cin >> m >> n;
    cout << "Enter elements:";
    vector<vector<int>> arr(m, vector<int>(n));
    int sum = 0;
    // for taking input
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    // for output
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
            sum += arr[i][j];
        }
        cout << "sum for index " << i + 1 << " is -> " << sum;
        cout << "\n";
    }
}