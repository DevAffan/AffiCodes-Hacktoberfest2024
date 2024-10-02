#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(int row1, int col1, int row2, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp) {
        int col2 = (row1 + col1) - row2;

        if (row1 >= grid.size() || row2 >= grid.size() || col1 >= grid[0].size() || col2 >= grid[0].size() ||
            grid[row1][col1] == -1 || grid[row2][col2] == -1) {
            return INT_MIN;
        }

        if (row1 == grid.size() - 1 && col1 == grid[0].size() - 1) {
            return grid[row1][col1];
        }

        if (dp[row1][col1][row2] != -1) {
            return dp[row1][col1][row2];
        }

        int cherries = 0;
        if (row1 == row2 && col1 == col2) {
            cherries += grid[row1][col1];
        } else {
            cherries += grid[row1][col1] + grid[row2][col2];
        }

        int hh = solve(row1, col1 + 1, row2, grid, dp);
        int vh = solve(row1 + 1, col1, row2, grid, dp);
        int vv = solve(row1 + 1, col1, row2 + 1, grid, dp);
        int hv = solve(row1, col1 + 1, row2 + 1, grid, dp);

        cherries += max({hh, vh, vv, hv});

        dp[row1][col1][row2] = cherries;

        return cherries;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n, -1)));
        int result = solve(0, 0, 0, grid, dp);
        return result == INT_MIN || result < 0 ? 0 : result;
    }
};

int main() {
    int n;
    cin >> n;

    vector<vector<int>> grid(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    Solution sol;
    int result = sol.cherryPickup(grid);
    cout << result << endl;

    return 0;
}
