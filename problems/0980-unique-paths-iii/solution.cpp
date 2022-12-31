/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/unique-paths-iii/
 * Runtime: 0ms (100.00%)
 */

class Solution {
private:
  int n;
  int m;

  const int inf = 0x3f3f3f3f;
  const int dx[4] = {0, 0, 1, -1};
  const int dy[4] = {1, -1, 0, 0};

  int ex;
  int ey;

  vector<vector<bool>> vis;

  int dfs(const vector<vector<int>>& grid, int x, int y, int steps) {
    if (abs(ex - x) + abs(ey - y) > steps) {
      return 0;
    }

    if (grid[x][y] == 2 && steps == 0) {
      return 1;
    }

    int total = 0;

    for (int i = 0; i < 4; ++i) {
      int newx = x + dx[i];
      int newy = y + dy[i];
      if (newx < 0 || newy < 0 || newx >= n || newy >= m
        || grid[newx][newy] == -1 || vis[newx][newy]) {
        continue;
      }

      vis[newx][newy] = true;
      total += dfs(grid, newx, newy, steps - 1);
      vis[newx][newy] = false;
    }

    return total;
  }
public:
  int uniquePathsIII(vector<vector<int>>& grid) {
    n = grid.size();
    m = grid[0].size();

    int sx;
    int sy;
    int steps = n * m;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (grid[i][j] == -1) {
          --steps;
        } else if (grid[i][j] == 1) {
          sx = i;
          sy = j;
        } else if (grid[i][j] == 2) {
          ex = i;
          ey = j;
        } 
      }
    }

    vis = vector<vector<bool>>(n, vector<bool>(m, false));
    vis[sx][sy] = true;

    return dfs(grid, sx, sy, steps - 1);
  }
};
