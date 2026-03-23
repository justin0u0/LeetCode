/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/maximum-non-negative-product-in-a-matrix/
 * Runtime: 0ms (100.00%)
 */

class Solution {
private:
  const int mod = 1e9 + 7;
public:
  int maxProductPath(vector<vector<int>>& grid) {
    const int m = grid.size();
    const int n = grid[0].size();

    vector<vector<pair<long long, long long>>> dp(m + 1, vector<pair<long long, long long>>(n + 1, {0, 0}));
    dp[0][1] = {1, 0};

    bool zero = false;

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        const long long val = abs(grid[i][j]);
        if (val == 0) {
          zero = true;
        }

        const long long pmax = max(dp[i][j + 1].first * val, dp[i + 1][j].first * val);
        const long long nmax = max(dp[i][j + 1].second * val, dp[i + 1][j].second * val);
        if (grid[i][j] >= 0) {
          dp[i + 1][j + 1] = {pmax, nmax};
        } else {
          dp[i + 1][j + 1] = {nmax, pmax};
        }
      }
    }

    if (dp[m][n].first == 0 && !zero) {
      return -1;
    }
    return dp[m][n].first % mod;
  }
};
