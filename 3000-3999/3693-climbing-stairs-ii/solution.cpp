/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/climbing-stairs-ii/
 * Runtime: 5ms (93.42%)
 */

class Solution {
public:
  int climbStairs(const int n, const vector<int>& costs) {
    vector<int> dp(3, 0);
    for (int i = 0; i < n; ++i) {
      int best = INT_MAX;
      for (int j = 0; j < 3; ++j) {
        best = min(best, dp[j] + (j + 1) * (j + 1));
      }
      dp[2] = dp[1];
      dp[1] = dp[0];
      dp[0] = best + costs[i];
    }
    return dp[0];
  }
};
