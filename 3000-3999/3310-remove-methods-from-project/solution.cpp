/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/remove-methods-from-project/
 * Runtime: 173ms (70.34%)
 */

class Solution {
public:
  vector<int> remainingMethods(const int n, const int k, const vector<vector<int>>& invocations) {
    vector<vector<int>> graph(n);
    for (const auto& edge : invocations) {
      graph[edge[0]].emplace_back(edge[1]);
    }

    vector<bool> sus(n, false);
    auto dfs = [&](this auto&& self, int u) -> void {
      sus[u] = true;
      for (int v : graph[u]) {
        if (!sus[v]) {
          self(v);
        }
      }
    };
    dfs(k);

    vector<int> res;
    for (int u = 0; u < n; ++u) {
      if (!sus[u]) {
        res.emplace_back(u);
        for (int v : graph[u]) {
          if (sus[v]) {
            res.resize(n);
            ranges::iota(res, 0);
            return res;
          }
        }
      }
    }
    return res;
  }
};
