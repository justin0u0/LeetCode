/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/detect-cycles-in-2d-grid/
 * Runtime: 25ms (67.59%)
 */

class Solution {
private:
  const inline static array<int, 4> dx{1, -1, 0, 0};
  const inline static array<int, 4> dy{0, 0, 1, -1};
public:
  bool containsCycle(vector<vector<char>>& grid) {
    const int m = grid.size();
    const int n = grid[0].size();

    auto dfs = [&](this auto&& self, const int x, const int y, const int px, const int py) -> bool {
      const char c = grid[x][y];
      grid[x][y] = -grid[x][y];

      for (int i = 0; i < 4; ++i) {
        const int x2 = x + dx[i];
        const int y2 = y + dy[i];
        if (x2 < 0 || x2 >= m || y2 < 0 || y2 >= n) {
          continue;
        }
        if ((x2 != px || y2 != py) && grid[x2][y2] == -c) {
          return true;
        }
        if (grid[x2][y2] == c && self(x2, y2, x, y)) {
          return true;
        }
      }
      return false;
    };

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] > 0 && dfs(i, j, -1, -1)) {
          return true;
        }
      }
    }
    return false;
  }
};
