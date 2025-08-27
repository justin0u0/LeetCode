/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/length-of-longest-v-shaped-diagonal-segment/
 * Runtime: 173ms (86.10%)
 */

class Solution {
private:
  int dp[4][501][501]; // longest 0,2 alternative sequences in 4 directions
public:
  int lenOfVDiagonal(const vector<vector<int>>& grid) {
    const int n = grid.size();
    const int m = grid[0].size();

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (grid[i][j] != 1) {
          for (int k = 0; k < 4; ++k) {
            dp[k][i][j] = 1;
          }
        }
      }
    }

    for (int i = 1; i < n; ++i) {
      for (int j = 1; j < m; ++j) {
        if (grid[i][j] != 1 && grid[i][j] != grid[i - 1][j - 1]) {
          dp[0][i][j] = dp[0][i - 1][j - 1] + 1;
        }
      }
    }
    for (int i = 1; i < n; ++i) {
      for (int j = m - 2; j >= 0; --j) {
        if (grid[i][j] != 1 && grid[i][j] != grid[i - 1][j + 1]) {
          dp[1][i][j] = dp[1][i - 1][j + 1] + 1;
        }
      }
    }
    for (int i = n - 2; i >= 0; --i) {
      for (int j = m - 2; j >= 0; --j) {
        if (grid[i][j] != 1 && grid[i][j] != grid[i + 1][j + 1]) {
          dp[2][i][j] = dp[2][i + 1][j + 1] + 1;
        }
      }
    }
    for (int i = n - 2; i >= 0; --i) {
      for (int j = 1; j < m; ++j) {
        if (grid[i][j] != 1 && grid[i][j] != grid[i + 1][j - 1]) {
          dp[3][i][j] = dp[3][i + 1][j - 1] + 1;
        }
      }
    }

    auto hasStart = [&](const int i, const int j, const int dir, const int dist) {
      const int d = dist - 1;
      switch (dir) {
        case 0:
          return i - dist >= 0 && j - dist >= 0 && grid[i - dist][j - dist] == 1 && grid[i - d][j - d] == 2;
        case 1:
          return i - dist >= 0 && j + dist < m && grid[i - dist][j + dist] == 1 && grid[i - d][j + d] == 2;
        case 2:
          return i + dist < n && j + dist < m && grid[i + dist][j + dist] == 1 && grid[i + d][j + d] == 2;
        case 3:
          return i + dist < n && j - dist >= 0 && grid[i + dist][j - dist] == 1 && grid[i + d][j - d] == 2;
      }
      return false;
    };

    int len = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (grid[i][j] == 1) {
          len = max(len, 1);
          continue;
        }
        for (int k = 0; k < 4; ++k) {
          if (hasStart(i, j, k, dp[k][i][j])) {
            len = max(len, dp[k][i][j] + max(1, dp[(k + 3) % 4][i][j]));
          }
        }
      }
    }
    return len;
  }
};
