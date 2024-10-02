#include <iostream>
#include <vector>
#include <algorithm> // for std::lower_bound
using namespace std;

int longestIncreasingSubsequence(const vector<int>& nums) {
    vector<int> lis; // This will store the smallest tail for all increasing subsequences

    for (int num : nums) {
        // Use binary search to find the index of the smallest number >= num
        auto it = lower_bound(lis.begin(), lis.end(), num);
        
        // If num is larger than all elements in lis, it extends the largest subsequence
        if (it == lis.end()) {
            lis.push_back(num);
        } else {
            // Otherwise, replace the found index with num
            *it = num;
        }
    }

    // The size of lis will be the length of the longest increasing subsequence
    return lis.size();
}

int main() {
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    int length = longestIncreasingSubsequence(nums);
    cout << "Length of Longest Increasing Subsequence: " << length << endl;
    return 0;
}
