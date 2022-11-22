/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/perfect-squares/
 * Runtime: 261ms (65.87%)
 */

class Solution {
public:
  int numSquares(int n) {
    vector<int> dp(n + 1, 0x3f3f3f3f);
    dp[0] = 0;
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j * j <= i; ++j) {
        dp[i] = min(dp[i], dp[i - j * j] + 1);
      }
    }
    return dp[n];
  }
};
