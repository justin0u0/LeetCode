/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/domino-and-tromino-tiling/
 * Runtime: 0ms (100.00%)
 */

class Solution {
private:
  const int mod = 1e9 + 7;
public:
  int numTilings(int n) {
    if (n == 1) {
      return 1;
    }

    int dp2 = 1; // dp[i-2]
    int dp1 = 2; // dp[i-1]
    int sum = 1; // dp[i-3] + dp[i-4] + ...
    for (int i = 2; i < n; ++i) {
      int dp = ((dp2 + dp1) % mod + (sum << 1) % mod) % mod;
      sum = (sum + dp2) % mod;
      dp2 = dp1;
      dp1 = dp;
    }

    return dp1;
  }
};
