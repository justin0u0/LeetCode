/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimum-cost-path-with-teleportations/
 * Runtime: 2062ms (29.13%)
 */

class Solution {
private:
  struct Node {
    int x;
    int y;
    int t;
    int d;

    bool operator<(const Node& rhs) const {
      return d > rhs.d;
    }
  };

  const int inf = 0x3f3f3f3f;
public:
  int minCost(vector<vector<int>>& grid, int k) {
    const int m = grid.size();
    const int n = grid[0].size();

    vector<tuple<int, int, int>> nodes;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        nodes.push_back({grid[i][j], i, j});
      }
    }
    sort(nodes.begin(), nodes.end());

    priority_queue<Node> pq;
    pq.push({0, 0, 0, 0});
    
    vector<vector<vector<int>>> dist(m, vector<vector<int>>(n, vector<int>(k + 1, inf)));
    dist[0][0][0] = 0;

    // In Dijkstra, the distance(cost) is non-decreasing.
    // For the same number of teleportation used, there is no need to teleport
    // to the same cell twice as the earlier is just better.
    vector<int> cursor(k + 1, 0);

    while (!pq.empty()) {
      const auto u = pq.top();
      pq.pop();

      if (u.x == m - 1 && u.y == n - 1) {
        return u.d;
      }
      if (dist[u.x][u.y][u.t] < u.d) {
        continue;
      }

      // right
      if (u.y + 1 < n && dist[u.x][u.y + 1][u.t] > u.d + grid[u.x][u.y + 1]) {
        dist[u.x][u.y + 1][u.t] = u.d + grid[u.x][u.y + 1];
        pq.push({u.x, u.y + 1, u.t, dist[u.x][u.y + 1][u.t]});
      }
      // down
      if (u.x + 1 < m && dist[u.x + 1][u.y][u.t] > u.d + grid[u.x + 1][u.y]) {
        dist[u.x + 1][u.y][u.t] = u.d + grid[u.x + 1][u.y];
        pq.push({u.x + 1, u.y, u.t, dist[u.x + 1][u.y][u.t]});
      }
      // tel
      if (u.t == k) {
        continue;
      }
      for (int& i = cursor[u.t]; i < nodes.size(); ++i) {
        const auto [vc, vx, vy] = nodes[i];
        if (vc > grid[u.x][u.y]) {
          break;
        }
        if (dist[vx][vy][u.t + 1] > u.d) {
          dist[vx][vy][u.t + 1] = u.d;
          pq.push({vx, vy, u.t + 1, u.d});
        }
      }
    }

    return -1;
  }
};
