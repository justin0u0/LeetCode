/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/map-of-highest-peak/
 * Runtime: 64ms (90.29%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
    const int n = isWater.size();
    const int m = isWater[0].size();

    vector<vector<int>> vis(n, vector<int>(m, -1));

    queue<pair<int, int>> q;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (isWater[i][j] == 1) {
          q.push({i, j});
          vis[i][j] = 0;
        }
      }
    }

    const int dx[] = {1, -1, 0, 0};
    const int dy[] = {0, 0, 1, -1};
    for (int height = 1; !q.empty(); ++height) {
      size_t sz = q.size();
      while (sz--) {
        const auto [x, y] = q.front();
        q.pop();
  
        for (int i = 0; i < 4; ++i) {
          const int x2 = x + dx[i];
          const int y2 = y + dy[i];
          if (x2 < 0 || x2 >= n || y2 < 0 || y2 >= m || vis[x2][y2] != -1) {
            continue;
          }
          vis[x2][y2] = height;
          q.push({x2, y2});
        }
      }
    }
    
    return vis;
  }
};
