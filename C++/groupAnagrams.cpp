/**
 * * Leetcode 49: Group Anagrams
 * Approach by string hashing:
 * A rolling string hash is a technique used to compute a hash value for a
 * string in a way that allows for efficient updates when characters are added
 * or removed We use primes and multiply them for each character’s value.
 * /\/\/\
 * TO learn more you can view
 * https://cp-algorithms.com/string/string-hashing.html
 * \/\/\/
 * Here, the logic is that the hash value of each anagram will be the same,
 * because they have the same characters just in different places, however as
 * the algorithm works by multiplying characters and multiplication is
 * associative it works out to the same result We use 26 primes for the 26
 * alphabets
 */

#include <bits/stdc++.h>
using namespace std;

const int primes[] = { 2,  3,  5,  7,  11, 13, 17, 19, 23, 29, 31, 37,  41, 43,
                       47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103 };
vector<vector<string>> groupAnagrams(vector<string> &strs) {
  unordered_map<long, vector<string>> mp;
  for (const string &s : strs) {
    long prod = 1;
    for (char ch : s)
      prod *= primes[ch - 'a'];
    mp[prod].push_back(s);
  }
  vector<vector<string>> ans;
  for (const auto &pair : mp)
    ans.push_back(pair.second);
  return ans;
}

int main() {
  vector<string> strs = { "eat", "tea", "tan", "ate", "nat", "bat" };
  vector<vector<string>> groupedAnagrams = groupAnagrams(strs);
  for (const auto &group : groupedAnagrams) {
    cout << "[ ";
    for (const auto &str : group)
      cout << str << " ";
    cout << "]\n";
  }
  return 0;
}

// Output
// [ bat ]
// [ tan nat ]
// [ eat tea ate ]

/**
 * Other approach you can use are character hashing (Requires a helper function)
 * or sorting like this
 vector<vector<string>> group(vector<string>& strs) {
  unordered_map<string, vector<string>> mp;
  for(auto x : strs) {
    string word = x;
    sort(word.begin(), word.end());
    mp[word].push_back(x);
  }
  vector<vector<string>> ans;
  for(auto x : mp) ans.push_back(x.second);
  return ans;
}
 */