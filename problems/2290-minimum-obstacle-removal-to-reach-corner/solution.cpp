/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimum-obstacle-removal-to-reach-corner/
 * Runtime: 231ms (77.16%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
private:
  struct Node {
    int x;
    int y;
    int dist;

    bool operator<(const Node& rhs) const {
      return dist > rhs.dist;
    }
  };
public:
  int minimumObstacles(vector<vector<int>>& grid) {
    const int n = grid.size();
    const int m = grid[0].size();

    vector<vector<int>> dist(n, vector<int>(m, 0x3f3f3f3f));
    dist[0][0] = 0;

    priority_queue<Node> pq;
    pq.push({0, 0, 0});

    const int dx[] = {1, -1, 0, 0};
    const int dy[] = {0, 0, 1, -1};
    while (!pq.empty()) {
      Node u = pq.top();
      pq.pop();

      if (u.x == n - 1 && u.y == m - 1) {
        return u.dist;
      }

      if (dist[u.x][u.y] > u.dist) {
        continue;
      }

      for (int i = 0; i < 4; ++i) {
        const int x = u.x + dx[i];
        const int y = u.y + dy[i];
        if (x < 0 || x >= n || y < 0 || y >= m) {
          continue;
        }

        const int d = u.dist + (grid[x][y] == 1);
        if (d < dist[x][y]) {
          dist[x][y] = d;
          pq.push({x, y, d});
        }
      }
    }

    return -1;
  }
};
