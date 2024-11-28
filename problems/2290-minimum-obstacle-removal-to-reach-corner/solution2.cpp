/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimum-obstacle-removal-to-reach-corner/
 * Runtime: 52ms (100.00%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  int minimumObstacles(vector<vector<int>>& grid) {
    // 0-1 BFS works for graph with all edges weight either 0 or 1.
    //
    // For 0-weight edge, push to the front of the deque; otherwise,
    // push to th back of the deque.

    const int n = grid.size();
    const int m = grid[0].size();

    const int dx[] = {1, -1, 0, 0};
    const int dy[] = {0, 0, 1, -1};

    deque<pair<int, int>> dq;
    dq.push_back({0, 0});
    grid[0][0] = -1;

    for (int dist = 0; !dq.empty(); ++dist) {
      int size = dq.size();
      while (size--) {
        auto [x, y] = dq.front();
        dq.pop_front();

        if (x == n - 1 && y == m - 1) {
          return dist;
        }

        for (int i = 0; i < 4; ++i) {
          const int x2 = x + dx[i];
          const int y2 = y + dy[i];
          if (x2 < 0 || x2 >= n || y2 < 0 || y2 >= m || grid[x2][y2] == -1) {
            continue;
          }

          if (grid[x2][y2] == 0) {
            dq.push_front({x2, y2});
            ++size;
          } else {
            dq.push_back({x2, y2});
          }
          grid[x2][y2] = -1;
        }
      }
    }

    return -1;
  }
};
