/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/shortest-bridge/
 * Runtime: 43ms (92.16%)
 */

class Solution {
private:
  int dx[4] = {0, 0, 1, -1};
  int dy[4] = {1, -1, 0, 0};

  int n;

  void dfs(int x, int y, vector<vector<int>>& grid, queue<pair<int, int>>& q) {
    q.push({x, y});
    for (int i = 0; i < 4; ++i) {
      int newx = x + dx[i];
      int newy = y + dy[i];
      if (newx < 0 || newy < 0 || newx >= n || newy >= n || grid[newx][newy] != 1) {
        continue;
      }
      grid[newx][newy] = -1;
      dfs(newx, newy, grid, q);
    }
  }
public:
  int shortestBridge(vector<vector<int>>& grid) {
    n = grid.size();

    queue<pair<int, int>> q;
    for (int i = 0; q.empty() && i < n; ++i) {
      for (int j = 0; q.empty() && j < n; ++j) {
        if (grid[i][j] == 1) {
          grid[i][j] = -1;
          dfs(i, j, grid, q);
        }
      }
    }

    for (int dist = 0; !q.empty(); ++dist) {
      int sz = q.size();
      while (sz--) {
        auto [x, y] = q.front();
        q.pop();

        for (int i = 0; i < 4; ++i) {
          int newx = x + dx[i];
          int newy = y + dy[i];
          if (newx < 0 || newy < 0 || newx >= n || newy >= n || grid[newx][newy] == -1) {
            continue;
          }

          if (grid[newx][newy] == 1) {
            return dist;
          }

          grid[newx][newy] = -1;
          q.push({newx, newy});
        }
      }
    }

    return -1;
  }
};
