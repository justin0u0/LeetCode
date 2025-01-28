/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/maximum-number-of-fish-in-a-grid/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int findMaxFish(vector<vector<int>>& grid) {
    const int n = grid.size();
    const int m = grid[0].size();

    function<int(int, int)> dfs = [&](int x, int y) {
      if (x < 0 || x >= n || y < 0 || y >= m || grid[x][y] == 0) {
        return 0;
      }

      const int g = grid[x][y];
      grid[x][y] = 0;
      return dfs(x - 1, y) + dfs(x + 1, y) + dfs(x, y - 1) + dfs(x, y + 1) + g;
    };

    int mx = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (grid[i][j] != 0) {
          mx = max(mx, dfs(i, j));
        }
      }
    }
    return mx;
  }
};
