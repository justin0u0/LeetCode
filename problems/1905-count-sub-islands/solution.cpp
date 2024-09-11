/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/count-sub-islands/
 * Runtime: 398ms (17.38%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
    const int n = grid1.size();
    const int m = grid1[0].size();
    const int dx[] = {1, -1, 0, 0};
    const int dy[] = {0, 0, 1, -1};

    function<bool(int, int)> dfs = [&](int x, int y) {
      grid2[x][y] = 0;

      bool ok = grid1[x][y] == 1;
      for (int i = 0; i < 4; ++i) {
        int x2 = x + dx[i];
        int y2 = y + dy[i];
        if (x2 < 0 || x2 >= n || y2 < 0 || y2 >= m || grid2[x2][y2] == 0) {
          continue;
        }

        ok &= dfs(x2, y2);
      }

      return ok;
    };

    int subIslands = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (grid2[i][j] == 1) {
          if (dfs(i, j)) {
            ++subIslands;
          }
        }
      }
    }
    return subIslands;
  }
};
