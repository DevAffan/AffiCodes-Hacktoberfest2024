#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to merge overlapping intervals
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    if (intervals.empty()) return {};
    
    // Sort intervals by the starting value
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> merged;
    
    for (const auto& interval : intervals) {
        if (merged.empty() || merged.back()[1] < interval[0]) {
            merged.push_back(interval);
        } else {
            merged.back()[1] = max(merged.back()[1], interval[1]);
        }
    }
    
    return merged;
}

// Function to print the intervals
void printIntervals(const vector<vector<int>>& intervals) {
    for (const auto& interval : intervals) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;
}

int main() {
    // Input: a vector of intervals
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    
    // Call the merge function
    vector<vector<int>> result = merge(intervals);
    
    // Print the merged intervals
    cout << "Merged intervals: ";
    printIntervals(result);
    
    return 0;
}
