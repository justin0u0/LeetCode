/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/
 * Runtime: 15ms (79.06%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
private:
  struct Grid {
    int i;
    int j;
    int dist;

    bool operator<(const Grid& rhs) const {
      return dist > rhs.dist;
    }
  };
public:
  int minCost(const vector<vector<int>>& grid) {
    const int n = grid.size();
    const int m = grid[0].size();

    vector<vector<int>> dist(n, vector<int>(m, 0x3f3f3f3f));
    dist[0][0] = 0;

    priority_queue<Grid> pq;
    pq.push({0, 0, 0});

    const int di[] = {0, 0, 1, -1};
    const int dj[] = {1, -1, 0, 0};

    while (!pq.empty()) {
      Grid u = pq.top();
      pq.pop();

      if (u.i == n - 1 && u.j == m - 1) {
        return u.dist;
      }

      if (dist[u.i][u.j] < u.dist) {
        continue;
      }

      const int dir = grid[u.i][u.j] - 1;
      for (int i = 0; i < 4; ++i) {
        Grid v{u.i + di[i], u.j + dj[i], u.dist + 1};
        if (v.i < 0 || v.i >= n || v.j < 0 || v.j >= m) {
          continue;
        }
        if (i == dir) {
          v.dist = u.dist;
        }

        if (dist[v.i][v.j] > v.dist) {
          dist[v.i][v.j] = v.dist;
          pq.push(v);
        }
      }
    }

    return -1;
  }
};
