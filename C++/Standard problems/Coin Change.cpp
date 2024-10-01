#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to calculate the fewest number of coins to make the given amount
int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;
    
    for (int i = 1; i <= amount; i++) {
        for (int coin : coins) {
            if (i >= coin) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }
    
    return dp[amount] == amount + 1 ? -1 : dp[amount];
}

int main() {
    // Example input
    vector<int> coins = {1, 2, 5}; // coin denominations
    int amount;
    
    // Input the target amount
    cout << "Enter the amount: ";
    cin >> amount;
    
    // Call the coinChange function and print the result
    int result = coinChange(coins, amount);
    if (result == -1) {
        cout << "It's not possible to make up the amount with the given coins." << endl;
    } else {
        cout << "Fewest number of coins needed: " << result << endl;
    }
    
    return 0;
}
