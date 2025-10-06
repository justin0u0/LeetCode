/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/swim-in-rising-water/
 * Runtime: 11ms (40.20%)
 */

class Solution {
public:
  int swimInWater(const vector<vector<int>>& grid) {
    const int n = grid.size();
    int l = grid[0][0];
    int r = n * n;

    const int dx[] = {0, 0, 1, -1};
    const int dy[] = {1, -1, 0, 0};

    function<bool(int)> check = [&](const int cap) {
      queue<pair<int, int>> q;
      q.push({0, 0});

      vector<vector<bool>> vis(n, vector<bool>(n, false));
      vis[0][0] = true;

      while (!q.empty()) {
        const auto [x, y] = q.front();
        q.pop();

        if (x == n - 1 && y == n - 1) {
          return true;
        }

        for (int i = 0; i < 4; ++i) {
          const int x2 = x + dx[i];
          const int y2 = y + dy[i];

          if (x2 < 0 || x2 >= n || y2 < 0 || y2 >= n || vis[x2][y2] || grid[x2][y2] > cap) {
            continue;
          }

          q.push({x2, y2});
          vis[x2][y2] = true;
        }
      }

      return false;
    };

    while (l < r) {
      const int mid = (l + r) >> 1;
      if (check(mid)) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }

    return r;
  }
};
