/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/unique-binary-search-trees/
 * Runtime: 0ms (100.00%)
 */

class Solution {
private:
  static array<int, 20> numBSTs;
public:
  int numTrees(int n) {
    return numBSTs[n];
  }
};

array<int, 20> Solution::numBSTs = []() {
  // dp[n] = dp[0] * dp[n - 1] + dp[1] * dp[n - 2] + ... + dp[n - 1] * dp[0]

  array<int, 20> dp{1};
  for (int i = 1; i < 20; ++i) {
    for (int j = 0; j < i; ++j) {
      dp[i] += dp[j] * dp[i - j - 1];
    }
  }
  return dp;
}();
