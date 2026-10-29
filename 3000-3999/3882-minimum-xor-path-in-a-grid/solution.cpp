/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimum-xor-path-in-a-grid/
 * Runtime: 465ms (50.41%)
 */

class Solution {
public:
  int minCost(const vector<vector<int>>& grid) {
    const int m = grid.size();
    const int n = grid[0].size();
    const int k = 1024;

    vector<vector<vector<bool>>> dp(m, vector<vector<bool>>(n, vector<bool>(k, 0)));
    dp[0][0][grid[0][0]] = 1;

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (i == 0 && j == 0) {
          continue;
        }
        for (int o = 0; o < k; ++o) {
          if (i > 0 && dp[i - 1][j][o]) {
            dp[i][j][o ^ grid[i][j]] = true;
          }
          if (j > 0 && dp[i][j - 1][o]) {
            dp[i][j][o ^ grid[i][j]] = true;
          }
        }
      }
    }

    for (int o = 0; o < k; ++o) {
      if (dp[m - 1][n - 1][o]) {
        return o;
      }
    }
    return -1;
  }
};
