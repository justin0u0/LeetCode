/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/largest-magic-square/
 * Runtime: 27ms (56.69%)
 */

class Solution {
public:
  int largestMagicSquare(const vector<vector<int>>& grid) {
    const int n = grid.size();
    const int m = grid[0].size();
    vector<vector<int>> rows(n, vector<int>(m + 1, 0));
    vector<vector<int>> cols(m, vector<int>(n + 1, 0));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        rows[i][j + 1] = rows[i][j] + grid[i][j];
        cols[j][i + 1] = cols[j][i] + grid[i][j];
      }
    }

    function<bool(int, int, int, int)> check = [&](int i, int j, int k, int t) {
      int d1 = 0;
      int d2 = 0;
      for (int l = 0; l < k; ++l) {
        if (rows[i + l][j + k] - rows[i + l][j] != t) {
          return false;
        }
        if (cols[j + l][i + k] - cols[j + l][i] != t) {
          return false;
        }
        d1 += grid[i + l][j + l];
        d2 += grid[i + l][j + k - l - 1];
      }
      return d1 == t && d2 == t;
    };

    int res = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        for (int k = 0; i + k <= n && j + k <= m; ++k) {
          const int target = rows[i][j + k] - rows[i][j];
          if (check(i, j, k, target)) {
            res = max(res, k);
          }
        }
      }
    }
    return res;
  }
};
