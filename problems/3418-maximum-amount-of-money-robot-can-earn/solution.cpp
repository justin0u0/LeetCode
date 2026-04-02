/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/maximum-amount-of-money-robot-can-earn/
 * Runtime: 99ms (86.38%)
 */

class Solution {
private:
  int dp[502][502][3];
public:
  int maximumAmount(vector<vector<int>>& coins) {
    const int m = coins.size();
    const int n = coins[0].size();

    memset(dp, 0xc0c0c0c0, sizeof(dp));

    dp[0][1][0] = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        dp[i + 1][j + 1][0] = max(dp[i + 1][j][0], dp[i][j + 1][0]) + coins[i][j];
        dp[i + 1][j + 1][1] = max(
          max(dp[i + 1][j][1], dp[i][j + 1][1]) + coins[i][j],
          max(dp[i + 1][j][0], dp[i][j + 1][0]) + max(coins[i][j], 0)
        );
        dp[i + 1][j + 1][2] = max(
          max(dp[i + 1][j][2], dp[i][j + 1][2]) + coins[i][j],
          max(dp[i + 1][j][1], dp[i][j + 1][1]) + max(coins[i][j], 0)
        );
      }
    }

    return max(dp[m][n][0], max(dp[m][n][1], dp[m][n][2]));
  }
};
