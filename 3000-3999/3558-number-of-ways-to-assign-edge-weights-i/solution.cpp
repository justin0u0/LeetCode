/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/number-of-ways-to-assign-edge-weights-i/
 * Runtime: 280ms (69.13%)
 */

class Solution {
private:
  const int mod = 1e9 + 7;
public:
  int assignEdgeWeights(const vector<vector<int>>& edges) {
    const int n = edges.size() + 1;
    vector<vector<int>> graph(n + 1);
    for (const auto& e : edges) {
      graph[e[0]].emplace_back(e[1]);
      graph[e[1]].emplace_back(e[0]);
    }

    auto dfs = [&](this auto&& self, int u, int pa) -> int {
      int d = 0;
      for (int v : graph[u]) {
        if (v != pa) {
          d = max(d, self(v, u));
        }
      }
      return d + 1;
    };

    int depth = dfs(1, 0);
    long long res = 1;
    for (int i = 2; i < depth; ++i) {
      res = (res << 1) % mod;
    }
    return res;
  }
};
