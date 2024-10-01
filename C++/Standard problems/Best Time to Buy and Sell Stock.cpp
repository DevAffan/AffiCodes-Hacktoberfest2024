#include<bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to calculate maximum profit
int maxProfit(vector<int>& prices) {
    int minPrice = INT_MAX, maxProfit = 0;
    for (int price : prices) {
        minPrice = min(minPrice, price);
        maxProfit = max(maxProfit, price - minPrice);
    }
    return maxProfit;
}

int main() {
    // Example vector of stock prices
    vector<int> prices = {7, 1, 5, 3, 6, 4};

    // Call the maxProfit function and print the result
    int result = maxProfit(prices);
    cout << "Maximum Profit: " << result << endl;

    return 0;
}
