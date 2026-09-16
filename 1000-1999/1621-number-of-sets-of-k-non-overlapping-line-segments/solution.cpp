/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/number-of-sets-of-k-non-overlapping-line-segments/
 * Runtime: 12ms (71.96%)
 */

class Solution {
public:
  int numberOfSets(const int n, const int k) {
    const int mod = 1e9 + 7;

    // dp[i][j]: number of ways to draw j segments from points 0~i
    //  = dp[i-1][j] + dp[i-1][j-1] + dp[i-2][j-1] + ... + dp[0][j-1]
    //  = dp[i-1][j] + sum[j-1]
    //
    // as dp[i] only transit from dp[i-1], reduce from 2D to 1D
    vector<int> dp(k + 1, 0);
    vector<int> sum(k + 1, 0);

    dp[0] = 1;
    sum[0] = 1;

    for (int i = 1; i < n; ++i) {
      for (int j = k; j > 0; --j) {
        dp[j] = (dp[j] + sum[j - 1]) % mod;
        sum[j] = (sum[j] + dp[j]) % mod;
      }
      ++sum[0]; // dp[i][0] += 1
    }

    return dp[k];
  }
};
