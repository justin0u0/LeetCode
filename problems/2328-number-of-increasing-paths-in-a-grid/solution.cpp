/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/number-of-increasing-paths-in-a-grid/
 * Runtime: 236ms (98.45%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
private:
  const int mod = 1e9 + 7;

  int n, m;

  int dp[1000][1000];
  int dx[4] = {0, 0, 1, -1};
  int dy[4] = {1, -1, 0, 0};

  int solve(const vector<vector<int>>& grid, int x, int y) {
    int& d = dp[x][y];
    if (d != 0) {
      return d;
    }

    d = 1;
    for (int i = 0; i < 4; ++i) {
      int newx = x + dx[i];
      int newy = y + dy[i];
      if (newx < 0 || newy < 0 || newx >= n || newy >= m || grid[newx][newy] <= grid[x][y]) {
        continue;
      }

      d += solve(grid, newx, newy);
      if (d >= mod) {
        d -= mod;
      }
    }

    return d;
  }
public:
  int countPaths(vector<vector<int>>& grid) {
    n = grid.size();
    m = grid[0].size();

    int sum = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        sum += solve(grid, i, j);
        if (sum >= mod) {
          sum -= mod;
        }
      }
    }
    return sum;
  }
};
