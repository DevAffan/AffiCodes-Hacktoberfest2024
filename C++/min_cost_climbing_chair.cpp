#include <vector>
#include <iostream>
using namespace std;

/*LeetCode 746
You are given an integer array cost where cost[i] is the cost of ith step on a staircase. Once you pay the cost, you can either climb one or two steps.

You can either start from the step with index 0, or the step with index 1.

Return the minimum cost to reach the top of the floor

Example 1:

Input: cost = [10,15,20]
Output: 15
Explanation: You will start at index 1.
- Pay 15 and climb two steps to reach the top.
The total cost is 15.


Example 2:

Input: cost = [1,100,1,1,1,100,1,1,100,1]
Output: 6
Explanation: You will start at index 0.
- Pay 1 and climb two steps to reach index 2.
- Pay 1 and climb two steps to reach index 4.
- Pay 1 and climb two steps to reach index 6.
- Pay 1 and climb one step to reach index 7.
- Pay 1 and climb two steps to reach index 9.
- Pay 1 and climb one step to reach the top.
The total cost is 6.
*/

int minCostClimbingStairs(vector<int>& cost) {
    int dp[cost.size()];
    for(std::size_t i = 0; i < cost.size(); ++i) dp[i]=0;
    
    // minimum cost to reach stairs 1 and 2
    dp[0] = cost[0]; 
    dp[1] = cost[1];
    
    for (int i = 2; i < cost.size(); i++) {
        dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
    }
    return min(dp[cost.size() - 1], dp[cost.size() - 2]);
}

int main(int argc, char **argv) {
  vector<int> example_1{10, 15, 20};
  vector<int> example_2{1,100,1,1,1,100,1,1,100,1};

  for(const auto& num:example_1)
    std::cout << num <<" ";
  std::cout << std::endl;
  std::cout << "Minimum cost climbing stars is "<< minCostClimbingStairs(example_1) <<std::endl;
  for(const auto& num:example_1)
    std::cout << num <<" ";
  std::cout << std::endl;
  
  std::cout << "Minimum cost climbing stars is "<< minCostClimbingStairs(example_2) <<std::endl;
  return 0;
}