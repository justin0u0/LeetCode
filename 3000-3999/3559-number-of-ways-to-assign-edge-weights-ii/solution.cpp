/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/number-of-ways-to-assign-edge-weights-ii/
 * Runtime: 404ms (57.78%)
 */

class Solution {
private:
  inline static constexpr int N = 100000;
  inline static constexpr int mod = 1e9 + 7;

  inline static constexpr array<int, N> mul = []{
    // 0, 1, 2, 4, ...
    array<int, N> res{0, 1};
    for (int i = 2; i < N; ++i) { 
      res[i] = (res[i - 1] << 1) % mod;
    }
    return res;
  }();
public:
  vector<int> assignEdgeWeights(const vector<vector<int>>& edges, const vector<vector<int>>& queries) {
    const int n = edges.size() + 1;
    int m = 1;
    while ((1 << m) < n) {
      ++m;
    }

    vector<vector<int>> graph(n + 1);
    for (const auto& edge : edges) {
      graph[edge[0]].emplace_back(edge[1]);
      graph[edge[1]].emplace_back(edge[0]);
    }

    vector<int> height(n + 1);
    vector<vector<int>> parent(n + 1, vector<int>(m, 0));

    queue<pair<int, int>> q;
    q.push({1, 0});
    for (int h = 1; !q.empty(); ++h) {
      auto sz = q.size();
      while (sz--) {
        auto [u, pa] = q.front();
        q.pop();

        height[u] = h;
        parent[u][0] = pa;
        for (int i = 1; (1 << i) < height[u]; ++i) {
          parent[u][i] = parent[parent[u][i - 1]][i - 1];
        }

        for (int v : graph[u]) {
          if (v != pa) {
            q.push({v, u});
          }
        }
      }
    }

    auto dist = [&](int u, int v) {
      int sum = height[u] + height[v];

      // 1. jump to the same height
      if (height[u] < height[v]) {
        swap(u, v);
      }

      int d = height[u] - height[v];
      for (int i = m - 1; i >= 0; --i) {
        if (d & (1 << i)) {
          u = parent[u][i];
        }
      }

      if (u == v) {
        return sum - height[u] - height[v];
      }

      // 2. jump to the lca
      for (int i = m - 1; i >= 0; --i) {
        while (parent[u][i] != parent[v][i]) {
          u = parent[u][i];
          v = parent[v][i];
        }
      }

      // lca = parent[u][0] = parent[v][0]
      return sum - (height[parent[u][0]] << 1);
    };

    vector<int> res;
    res.reserve(queries.size());
    for (const auto& query : queries) {
      res.emplace_back(mul[dist(query[0], query[1])]);
    }
    return res;
  }
};
