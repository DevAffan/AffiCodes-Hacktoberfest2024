#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int coinchange(int idx, int target, vector<int>& coins, vector<vector<int>>& dp) {
        if (idx == 0) {
            return target % coins[idx] == 0;
        }

        if (dp[idx][target] != -1) {
            return dp[idx][target];
        }

        int nottake = coinchange(idx - 1, target, coins, dp);
        int take = 0;

        if (target >= coins[idx]) {
            take = coinchange(idx, target - coins[idx], coins, dp);
        }

        dp[idx][target] = nottake + take;
        return dp[idx][target];
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        return coinchange(n - 1, amount, coins, dp);
    }
};

int main() {
    Solution solution;
    int amount, n;
    cin >> amount;


    cin >> n;

    vector<int> coins(n);

    for (int i = 0; i < n; ++i) {
        cin >> coins[i];
    }


    int result = solution.change(amount, coins);
    cout << result << endl;

    return 0;
}
