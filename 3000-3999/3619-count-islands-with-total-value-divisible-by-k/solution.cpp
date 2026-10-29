/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/count-islands-with-total-value-divisible-by-k/
 * Runtime: 35ms (57.01%)
 */

class Solution {
public:
  int countIslands(vector<vector<int>>& grid, const int k) {
    const int m = grid.size();
    const int n = grid[0].size();

    const int dx[] = {1, -1, 0, 0};
    const int dy[] = {0, 0, 1, -1};
    auto dfs = [&](this auto&& self, int x, int y) -> int {
      int sum = grid[x][y];
      grid[x][y] = 0;

      for (int i = 0; i < 4; ++i) {
        const int x2 = x + dx[i];
        const int y2 = y + dy[i];
        if (x2 < 0 || x2 >= m || y2 < 0 || y2 >= n || grid[x2][y2] == 0) {
          continue;
        }
        sum = (sum + self(x2, y2)) % k;
      }

      return sum;
    };

    int count = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] > 0 && dfs(i, j) % k == 0) {
          ++count;
        }
      }
    }

    return count;
  }
};
