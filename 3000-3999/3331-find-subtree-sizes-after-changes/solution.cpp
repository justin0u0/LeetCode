/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/find-subtree-sizes-after-changes/
 * Runtime: 933ms (39.24%)
 */

class Solution {
public:
  vector<int> findSubtreeSizes(const vector<int>& parent, const string& s) {
    const int n = parent.size();

    vector<vector<int>> dp(n, vector<int>(128, -1));

    auto find = [&](this auto&& self, int u, const char c) {
      if (u == -1 || s[u] == c) {
        return u;
      }
      if (dp[u][c] != -1) {
        return dp[u][c];
      }
      return dp[u][c] = self(parent[u], c);
    };

    vector<int> newp = parent;
    for (int i = 1; i < n; ++i) {
      const int u = find(parent[i], s[i]);
      if (u != -1) {
        newp[i] = u;
      }
    }

    vector<vector<int>> graph(n);
    for (int i = 1; i < n; ++i) {
      graph[newp[i]].emplace_back(i);
    }

    vector<int> res(n);
    auto dfs = [&](this auto&& self, int u, int pa) -> int {
      int sz = 1;
      for (int v : graph[u]) {
        sz += self(v, u);
      }
      res[u] = sz;
      return sz;
    };
    dfs(0, -1);

    return res;
  }
};
