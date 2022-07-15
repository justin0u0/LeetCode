/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/max-area-of-island/
 * Runtime: 11ms
 */

class Solver {
private:
  int n;
  int m;
  vector<vector<int>>& grid;
  const int dx[4] = {1, -1, 0, 0};
  const int dy[4] = {0, 0, 1, -1};

  int dfs(int x, int y) {
    grid[x][y] = 0;

    int sum = 1;
    for (int i = 0; i < 4; ++i) {
      int newx = x + dx[i];
      int newy = y + dy[i];
      if (newx < 0 || newy < 0 || newx >= n || newy >= m || grid[newx][newy] == 0) {
        continue;
      }

      sum += dfs(newx, newy);
    }

    return sum;
  }
public:
  Solver(vector<vector<int>>& grid)
    : n(grid.size()), m(grid[0].size()), grid(grid) {}

  int solve() {
    int answer = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (grid[i][j]) {
          answer = max(answer, dfs(i, j));
        }
      }
    }

    return answer;
  }
};

class Solution {
public:
  int maxAreaOfIsland(vector<vector<int>>& grid) {
    Solver solver(grid);

    return solver.solve();
  }
};
