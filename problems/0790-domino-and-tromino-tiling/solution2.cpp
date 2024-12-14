/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/domino-and-tromino-tiling/
 * Runtime: 0ms (100.00%)
 */

class Solution {
private:
  const unsigned int mod = 1e9 + 7;
public:
  int numTilings(int n) {
    // Let dp[i] be the number of ways to tile an 2 * n board.
    //
    // dp[i]
    // = 2 * (dp[0] + dp[1] + .. + dp[i - 3]) + dp[i - 1] + dp[i - 2]
    // = 2 * (dp[0] + dp[1] + .. + dp[i - 1]) - dp[i - 1] - dp[i - 2]
    // = 2 * (dp[0] + dp[1] + .. + dp[i - 1]) - (2 * (dp[0] + dp[1] + .. + dp[i - 2]) - dp[i - 2] - dp[i - 3]) - dp[i - 2]
    // = 2 * dp[i - 1] + dp[i - 2] + dp[i - 3] - dp[i - 2]
    // = 2 * dp[i - 1] + dp[i - 3]
    if (n == 1) {
      return 1;
    }

    unsigned int dp1 = 1; // dp[i - 1]
    unsigned int dp2 = 1; // dp[i - 2]
    unsigned int dp3 = 0; // dp[i - 3]

    for (int i = 2; i <= n; ++i) {
      int next = (dp1 << 1) + dp3;
      dp3 = dp2;
      dp2 = dp1;
      dp1 = next % mod;
    }
    return dp1;
  }
};
