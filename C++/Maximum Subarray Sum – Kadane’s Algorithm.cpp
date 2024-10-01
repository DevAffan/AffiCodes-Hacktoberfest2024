// C++ Program for Maximum Subarray Sum using Kadane's Algorithm

#include <bits/stdc++.h>
using namespace std;

// Function to find the maximum subarray sum using Kadane's Algorithm
int maxSubarraySum(vector<int> &arr) {
    // Initialize the result (maximum subarray sum found so far)
    // and the maximum sum of the subarray ending at the current index.
    int res = arr[0];        // `res` stores the maximum sum we have encountered so far
    int maxEnding = arr[0];   // `maxEnding` stores the maximum sum of the subarray ending at the current index

    // Loop through the array starting from the second element (i = 1)
    for (int i = 1; i < arr.size(); i++) {
        // Update maxEnding by taking the maximum of two choices:
        // 1. Extend the previous subarray by adding arr[i] to maxEnding.
        // 2. Start a new subarray with arr[i] as the only element.
        maxEnding = max(maxEnding + arr[i], arr[i]);

        // Update the result if the new subarray sum (maxEnding) is larger than the previous maximum
        res = max(res, maxEnding);
    }

    // Return the overall maximum subarray sum found
    return res;
}

int main() {
    // Example array for testing
    vector<int> arr = {2, 3, -8, 7, -1, 2, 3};

    // Output the maximum subarray sum
    cout << "Maximum Subarray Sum: " << maxSubarraySum(arr) << endl;

    return 0;
}


//output 11

//Time Complexity: O(n), since we are traversing the array only one time.
//Auxiliary Space: O(1)


/*

The idea of Kadane’s algorithm is to traverse over the array from left to right and for each element, find the maximum sum among all subarrays ending at that element. The result will be the maximum of all these values. 


But, the main issue is how to calculate maximum sum among all the subarrays ending at an element in O(1) time?


To calculate the maximum sum of subarray ending at current element, say maxEnding, we can use the maximum sum ending at the previous element. So for any element, we have two choices:


Choice 1: Extend the maximum sum subarray ending at the previous element by adding the current element to it. If the maximum subarray sum ending at the previous index is positive, then it is always better to extend the subarray.
Choice 2: Start a new subarray starting from the current element. If the maximum subarray sum ending at the previous index is negative, it is always better to start a new subarray from the current element.
This means that maxEnding at index i = max(maxEnding at index (i – 1) + arr[i], arr[i]) and the maximum value of maxEnding at any index will be our answer. 


Illustration:

*/