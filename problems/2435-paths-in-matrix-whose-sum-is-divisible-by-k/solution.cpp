/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/paths-in-matrix-whose-sum-is-divisible-by-k/
 * Runtime: 203ms (84.60%)
 */

class Solution {
private:
  const int mod = 1e9 + 7;
public:
  int numberOfPaths(const vector<vector<int>>& grid, const int k) {
    const int n = grid.size();
    const int m = grid[0].size();
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(m + 1, vector<int>(k, 0)));

    dp[0][1][0] = 1;
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        const int num = grid[i - 1][j - 1] % k;
        for (int o = 0; o < k; ++o) {
          dp[i][j][(o + num) % k] = (dp[i - 1][j][o] + dp[i][j - 1][o]) % mod;
        }
      }
    }

    return dp[n][m][0];
  }
};
