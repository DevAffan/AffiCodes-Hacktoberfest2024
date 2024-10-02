#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

// Function to calculate the length of the longest substring without repeating characters
int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> charIndex;
    int maxLength = 0, start = 0;
    
    for (int i = 0; i < s.size(); i++) {
        if (charIndex.count(s[i])) {
            start = max(start, charIndex[s[i]] + 1);
        }
        charIndex[s[i]] = i;
        maxLength = max(maxLength, i - start + 1);
    }
    
    return maxLength;
}

int main() {
    // Input string
    string s;
    cout << "Enter a string: ";
    cin >> s;
    
    // Call the lengthOfLongestSubstring function and print the result
    int result = lengthOfLongestSubstring(s);
    cout << "Length of the longest substring without repeating characters: " << result << endl;
    
    return 0;
}
