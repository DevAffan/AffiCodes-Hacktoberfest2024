#include <iostream>
#include <vector>
using namespace std;

// Function to perform backtracking for generating subsets
void backtrack(vector<int>& nums, vector<vector<int>>& result, vector<int>& current, int start) {
    result.push_back(current); // Add the current subset to the result
    for (int i = start; i < nums.size(); i++) {
        current.push_back(nums[i]); // Include nums[i] in the current subset
        backtrack(nums, result, current, i + 1); // Recurse for the next elements
        current.pop_back(); // Backtrack to explore other subsets
    }
}

// Function to generate all subsets of nums
vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> current;
    backtrack(nums, result, current, 0);
    return result;
}

// Function to print the subsets
void printSubsets(const vector<vector<int>>& subsets) {
    for (const auto& subset : subsets) {
        cout << "[ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "]\n";
    }
}

int main() {
    // Input: a vector of integers
    vector<int> nums;
    int n, input;
    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> input;
        nums.push_back(input);
    }

    // Generate subsets
    vector<vector<int>> allSubsets = subsets(nums);

    // Print the subsets
    cout << "Subsets:\n";
    printSubsets(allSubsets);

    return 0;
}
