/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/magic-squares-in-grid/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int numMagicSquaresInside(vector<vector<int>>& grid) {
    const int n = grid.size();
    const int m = grid[0].size();

    function<bool(int, int)> check = [&](int x, int y) {
      if (grid[x][y] != 5) {
        return false;
      }
      if (grid[x - 1][y - 1] + grid[x + 1][y + 1] != 10) {
        return false;
      }
      if (grid[x - 1][y + 1] + grid[x + 1][y - 1] != 10) {
        return false;
      }
      for (int d = -1; d < 2; ++d) {
        if (grid[x + d][y - 1] + grid[x + d][y] + grid[x + d][y + 1] != 15) {
          return false;
        }
        if (grid[x - 1][y + d] + grid[x][y + d] + grid[x + 1][y + d] != 15) {
          return false;
        }
      }

      vector<bool> vis(9, false);
      for (int dx = -1; dx < 2; ++dx) {
        for (int dy = -1; dy < 2; ++dy) {
          const int g = grid[x + dx][y + dy];
          if (g < 1 || g > 9 || vis[g]) {
            return false;
          }
          vis[g] = true;
        }
      }
      return true;
    };

    int answer = 0;
    for (int i = 1; i < n - 1; ++i) {
      for (int j = 1; j < m - 1; ++j) {
        if (check(i, j)) {
          ++answer;
        }
      }
    }
    return answer;
  }
};
