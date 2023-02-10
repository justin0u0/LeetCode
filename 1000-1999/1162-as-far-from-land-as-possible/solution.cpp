/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/as-far-from-land-as-possible/
 * Runtime: 58ms (93.66%)
 */

class Solution {
private:
  int dx[4] = {0, 0, 1, -1};
  int dy[4] = {1, -1, 0, 0};
public:
  int maxDistance(vector<vector<int>>& grid) {
    queue<pair<int, int>> q;
    int n = grid.size();
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == 1) {
          q.push({i, j});
        }
      }
    }

    if (q.empty() || q.size() == n * n) {
      return -1;
    }

    int dist;
    for (dist = 0; !q.empty(); ++dist) {
      int sz = q.size();
      while (sz--) {
        auto [x, y] = q.front();
        q.pop();
        for (int i = 0; i < 4; ++i) {
          int newx = x + dx[i];
          int newy = y + dy[i];
          if (newx < 0 || newy < 0 || newx >= n || newy >= n || grid[newx][newy] == 1) {
            continue;
          }

          grid[newx][newy] = 1;
          q.push({newx, newy});
        }
      }
    }

    return dist - 1;
  }
};
