#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int row = matrix.size();
        int col = matrix[0].size();
        int low = 0, high = (row * col) - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            int r = mid / col, c = mid % col;
            if (matrix[r][c] == target)
            {
                return true;
            }
            else if (matrix[r][c] < target)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return false;
    }
};