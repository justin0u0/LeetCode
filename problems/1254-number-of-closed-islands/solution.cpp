/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/number-of-closed-islands/
 * Runtime: 8ms (94.63%)
 */

class Solution {
private:
  const int dx[4] = {1, -1, 0, 0};
  const int dy[4] = {0, 0, 1, -1};
  int n, m;

  bool dfs(vector<vector<int>>& grid, int x, int y) {
    grid[x][y] = 1;

    bool closed = true;
    for (int i = 0; i < 4; ++i) {
      int newx = x + dx[i];
      int newy = y + dy[i];
      if (newx < 0 || newy < 0 || newx >= n || newy >= m) {
        closed = false;
        continue;
      }
      if (grid[newx][newy] == 1) {
        continue;
      }

      closed &= dfs(grid, newx, newy);
    }

    return closed;
  }
public:
  int closedIsland(vector<vector<int>>& grid) {
    n = grid.size();
    m = grid[0].size();

    int answer = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (grid[i][j] == 0 && dfs(grid, i, j)) {
          ++answer;
        }
      }
    }
    return answer;
  }
};
