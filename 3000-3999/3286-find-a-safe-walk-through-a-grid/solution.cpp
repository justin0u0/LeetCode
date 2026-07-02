/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/find-a-safe-walk-through-a-grid/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  bool findSafeWalk(vector<vector<int>>& grid, const int health) {
    const int m = grid.size();
    const int n = grid[0].size();

    deque<tuple<int, int, int>> q;

    q.push_back({0, 0, grid[0][0]});
    grid[0][0] = -1;

    const int dx[] = {1, -1, 0, 0};
    const int dy[] = {0, 0, 1, -1};

    while (!q.empty()) {
      auto [x, y, d] = q.front();
      q.pop_front();

      if (x == m - 1 && y == n - 1) {
        return d < health;
      }

      for (int i = 0; i < 4; ++i) {
        const int x2 = x + dx[i];
        const int y2 = y + dy[i];
        if (x2 < 0 || x2 >= m || y2 < 0 || y2 >= n || grid[x2][y2] < 0) {
          continue;
        }

        if (grid[x2][y2] > 0) {
          q.push_back({x2, y2, d + 1});
        } else {
          q.push_front({x2, y2, d});
        }
        grid[x2][y2] = -1;
      }
    }

    return false;
  }
};
