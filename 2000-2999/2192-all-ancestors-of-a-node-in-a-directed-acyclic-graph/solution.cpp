/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/all-ancestors-of-a-node-in-a-directed-acyclic-graph/
 * Runtime: 95ms (93.19%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
    vector<vector<int>> g(n);
    for (const auto& e : edges) {
      g[e[0]].emplace_back(e[1]);
    }

    vector<vector<int>> ancestors(n);
    function<void(int, int)> dfs = [&](int u, int root) {
      for (int v : g[u]) {
        if (ancestors[v].empty() || ancestors[v].back() != root) {
          ancestors[v].emplace_back(root);
          dfs(v, root);
        }
      }
    };
    for (int i = 0; i < n; ++i) {
      dfs(i, i);
    }
    return ancestors;
  }
};
