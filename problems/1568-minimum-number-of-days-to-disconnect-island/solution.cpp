/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimum-number-of-days-to-disconnect-island/
 * Runtime: 4ms (96.43%)
 */

class Solution {
public:
  int minDays(vector<vector<int>>& grid) {
    const int n = grid.size();
    const int m = grid[0].size();

    const int dx[] = {1, -1, 0, 0};
    const int dy[] = {0, 0, 1, -1};
    vector<int> vis(n * m, 0);
    int dfscnt = 0;
    int cuts = 0;

    function<int(int, int)> dfs = [&](int u, int pa) {
      ++dfscnt;
      vis[u] = dfscnt;
      int lowu = dfscnt;

      const int x = u / m;
      const int y = u % m;

      int children = 0;
      bool cut = false;

      for (int i = 0; i < 4; ++i) {
        const int x2 = x + dx[i];
        const int y2 = y + dy[i];
        if (x2 < 0 || x2 >= n || y2 < 0 || y2 >= m || grid[x2][y2] == 0) {
          continue;
        }

        const int v = x2 * m + y2;
        if (vis[v] == 0) {
          int lowv = dfs(v, u);
          ++children;
          lowu = min(lowu, lowv);

          if (pa != -1 && lowv >= vis[u]) {
            cut = true;
          }
        } else if (v != pa) {
          lowu = min(lowu, vis[v]);
        }
      }

      if (pa == -1 && children > 1) {
        cut = true;
      }
      if (cut) {
        ++cuts;
      }

      return lowu;
    };

    int lands = 0;
    int islands = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (grid[i][j] == 0) {
          continue;
        }
        ++lands;
        const int u = i * m + j;
        if (!vis[u]) {
          dfs(u, -1);
          ++islands;
        }
      }
    }
    if (islands != 1) {
      return 0;
    }
    if (cuts != 0) {
      return 1;
    }
    if (lands == 1) {
      return 1;
    }
    return 2;
  }
};
