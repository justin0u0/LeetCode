/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/maximum-path-score-in-a-grid/
 * Runtime: 1060ms (20.91%)
 */

class Solution {
public:
  int maxPathScore(const vector<vector<int>>& grid, const int k) {
    const int m = grid.size();
    const int n = grid[0].size();
    const int o = min((m + n) << 1, k + 1);

    vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(o, INT_MIN)));
    dp[0][0][0] = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        for (int l = 0; l < o; ++l) {
          int& d = dp[i][j][l];
          int cost = grid[i][j] > 0;
          if (i > 0 && l >= cost) {
            d = max(d, dp[i - 1][j][l - cost] + grid[i][j]);
          }
          if (j > 0 && l >= cost) {
            d = max(d, dp[i][j - 1][l - cost] + grid[i][j]);
          }
        }
      }
    }

    return max(*ranges::max_element(dp[m - 1][n - 1]), -1);
  }
};
