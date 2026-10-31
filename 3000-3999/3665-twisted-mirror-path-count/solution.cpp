/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/twisted-mirror-path-count/
 * Runtime: 56ms (89.17%)
 */

class Solution {
public:
  int uniquePaths(const vector<vector<int>>& grid) {
    const int m = grid.size();
    const int n = grid[0].size();
    const int mod = 1e9 + 7;

    vector<int> up(n, 0);
    vector<int> left(n, 0);

    up[0] = 1;

    for (int i = 0; i < m; ++i) {
      if (i > 0) {
        for (int j = 0; j < n; ++j) {
          if (grid[i - 1][j] == 0) {
            // up[i][j] = up[i - 1][j] + left[i - 1][j]
            up[j] = (up[j] + left[j]) % mod;
          } else {
            // up[i][j] = left[i - 1][j]
            up[j] = left[j];
          }
        }
      }

      for (int j = 1; j < n; ++j) {
        if (grid[i][j - 1] == 0) {
          // left[i][j] = left[i][j - 1] + up[i][j - 1]
          left[j] = (left[j - 1] + up[j - 1]) % mod;
        } else {
          // left[i][j] = up[i][j - 1]
          left[j] = up[j - 1];
        }
      }
    }

    return (up[n - 1] + left[n - 1]) % mod;
  }
};
