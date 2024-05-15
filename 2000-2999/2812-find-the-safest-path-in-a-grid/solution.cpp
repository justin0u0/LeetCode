/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/find-the-safest-path-in-a-grid/
 * Runtime: 287ms (98.72%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  int maximumSafenessFactor(vector<vector<int>>& grid) {
    const int n = grid.size();
    queue<pair<int, int>> q;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == 1) {
          grid[i][j] = 0;
          q.push({i, j});
        } else {
          grid[i][j] = -1;
        }
      }
    }

    const int di[] = {1, -1, 0, 0};
    const int dj[] = {0, 0, 1, -1};
    for (int safe = 1; !q.empty(); ++safe) {
      int sz = q.size();
      while (sz--) {
        auto [i, j] = q.front();
        q.pop();
        for (int k = 0; k < 4; ++k) {
          int i2 = i + di[k];
          int j2 = j + dj[k];
          if (i2 >= 0 && i2 < n && j2 >= 0 && j2 < n && grid[i2][j2] == -1) {
            grid[i2][j2] = safe;
            q.push({i2, j2});
          }
        }
      }
    }

    priority_queue<pair<int, pair<int, int>>> pq;
    pq.push({grid[0][0], {0, 0}});
    vector<vector<int>> dp(n, vector<int>(n, -1));
    dp[0][0] = grid[0][0];
    while (!pq.empty()) {
      auto [safe, pos] = pq.top();
      auto [i, j] = pos;
      pq.pop();
      if (i == n - 1 && j == n - 1) {
        return safe;
      }
      if (safe != dp[i][j]) {
        continue;
      }
      for (int k = 0; k < 4; ++k) {
        int i2 = i + di[k];
        int j2 = j + dj[k];
        if (i2 >= 0 && i2 < n && j2 >= 0 && j2 < n) {
          int s2 = min(safe, grid[i2][j2]);
          if (s2 > dp[i2][j2]) {
            dp[i2][j2] = s2;
            pq.push({s2, {i2, j2}});
          }
        }
      }
    }
    return -1;
  }
};
