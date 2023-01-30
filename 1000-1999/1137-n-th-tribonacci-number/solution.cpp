/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/n-th-tribonacci-number/
 * Runtime: 0ms (100.00%)
 */

class Solution {
private:
  vector<int> dp;
public:
  int tribonacci(int n) {
    if (dp.empty()) {
      dp = vector<int>{0, 1, 1};
    }

    for (int i = dp.size(); i <= n; ++i) {
      dp.emplace_back(dp[i - 1] + dp[i - 2] + dp[i - 3]);
    }
    return dp[n];
  }
};
