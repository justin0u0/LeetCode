/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/check-if-there-is-a-valid-parentheses-string-path/
 * Runtime: 4ms (96.41%)
 */

class Solution {
public:
  bool hasValidPath(const vector<vector<char>>& grid) {
    const int m = grid.size();
    const int n = grid[0].size();
    constexpr int k = 101;

    if (grid[0][0] == ')') {
      return false;
    }

    vector<vector<bitset<k>>> dp(m, vector<bitset<k>>(n));
    dp[0][0].set(1);

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (j > 0) {
          if (grid[i][j] == '(') {
            dp[i][j] = dp[i][j - 1] << 1;
          } else {
            dp[i][j] = dp[i][j - 1] >> 1;
          }
        }
        if (i > 0) {
          if (grid[i][j] == '(') {
            dp[i][j] |= dp[i - 1][j] << 1;
          } else {
            dp[i][j] |= dp[i - 1][j] >> 1;
          }
        }
      }
    }

    return dp[m - 1][n - 1][0];
  }
};
