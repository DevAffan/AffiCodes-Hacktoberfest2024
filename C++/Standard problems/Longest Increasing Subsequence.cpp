#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to calculate the length of the longest increasing subsequence
int lengthOfLIS(vector<int>& nums) {
    if (nums.empty()) return 0;
    vector<int> dp(nums.size(), 1);
    int maxLength = 1;
    
    for (int i = 1; i < nums.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        maxLength = max(maxLength, dp[i]);
    }
    
    return maxLength;
}

int main() {
    // Input array
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    
    // Call the lengthOfLIS function and print the result
    int result = lengthOfLIS(nums);
    cout << "Length of the longest increasing subsequence: " << result << endl;
    
    return 0;
}
