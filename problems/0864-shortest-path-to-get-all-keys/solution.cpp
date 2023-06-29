/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/shortest-path-to-get-all-keys/
 * Runtime: 26ms (94.88%)
 */

class Solution {
private:
  bool vis[30][30][1<<6];
  const int dx[4] = {0, 0, 1, -1};
  const int dy[4] = {1, -1, 0, 0};
public:
  int shortestPathAllKeys(const vector<string>& grid) {
    memset(vis, 0, sizeof(vis));

    int n = grid.size();
    int m = grid[0].size();

    queue<pair<pair<int, int>, int>> q;

    int keys = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (grid[i][j] == '@') {
          q.push({{i, j}, 0});
          vis[i][j][0] = true;
        } else if (islower(grid[i][j])) {
          ++keys;
        }
      }
    }

    for (int dist = 0; !q.empty(); ++dist) {
      int sz = q.size();
      while (sz--) {
        auto [xy, k] = q.front();
        q.pop();

        if (__builtin_popcount(k) == keys) {
          return dist;
        }

        for (int i = 0; i < 4; ++i) {
          int newx = xy.first + dx[i];
          int newy = xy.second + dy[i];

          if (newx < 0 || newy < 0 || newx >= n || newy >= m || grid[newx][newy] == '#') {
            continue;
          }

          if (isupper(grid[newx][newy])) {
            int l = 1 << (grid[newx][newy] - 'A');
            if ((l | k) != k) {
              continue;
            }
          }

          int newk = k;
          if (islower(grid[newx][newy])) {
            newk |= (1 << (grid[newx][newy] - 'a'));
          }

          if (vis[newx][newy][newk]) {
            continue;
          }

          q.push({{newx, newy}, newk});
          vis[newx][newy][newk] = true;
        }
      }
    }

    return -1;
  }
};
