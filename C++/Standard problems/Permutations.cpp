#include <iostream>
#include <vector>
using namespace std;

// Function to perform backtracking for permutations
void backtrack(vector<int>& nums, vector<vector<int>>& result, vector<int>& current, vector<bool>& used) {
    if (current.size() == nums.size()) {
        result.push_back(current);
        return;
    }
    for (int i = 0; i < nums.size(); i++) {
        if (used[i]) continue; // Skip used elements
        used[i] = true;
        current.push_back(nums[i]);
        backtrack(nums, result, current, used);
        current.pop_back();
        used[i] = false; // Backtrack
    }
}

// Function to generate permutations of nums
vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> current;
    vector<bool> used(nums.size(), false);
    backtrack(nums, result, current, used);
    return result;
}

// Function to print the permutations
void printPermutations(const vector<vector<int>>& permutations) {
    for (const auto& perm : permutations) {
        cout << "[ ";
        for (int num : perm) {
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

    // Generate permutations
    vector<vector<int>> permutations = permute(nums);

    // Print the permutations
    cout << "Permutations:\n";
    printPermutations(permutations);

    return 0;
}
