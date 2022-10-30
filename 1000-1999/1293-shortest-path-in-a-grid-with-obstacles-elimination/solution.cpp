/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/
 * Runtime: 21ms (94.40%)
 */

class Solution {
private:
  const int dx[4] = {1, -1, 0, 0};
  const int dy[4] = {0, 0, 1, -1};
public:
  int shortestPath(vector<vector<int>>& grid, int k) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n, vector<int>(m, INT_MAX));
    queue<tuple<int, int, int>> q;
    queue<tuple<int, int, int>> qNext;

    vis[0][0] = true;
    q.push(make_tuple(0, 0, 0));

    for (int d = 0; !q.empty(); ++d) {
      while (!q.empty()) {
        auto [x, y, z] = q.front();
        q.pop();

        if (x == n - 1 && y == m - 1) {
          return d;
        }

        for (int i = 0; i < 4; ++i) {
          int newx = x + dx[i];
          int newy = y + dy[i];
          if (newx < 0 || newy < 0 || newx >= n || newy >= m) {
            continue;
          }

          int newz = z + (grid[newx][newy] == 1);
          if (newz > k || newz >= vis[newx][newy]) {
            continue;
          }

          vis[newx][newy] = newz;
          qNext.push(make_tuple(newx, newy, newz));
        }
      }
      swap(q, qNext);
    }

    return -1;
  }
};
