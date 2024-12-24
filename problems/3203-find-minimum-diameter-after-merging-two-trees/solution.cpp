/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/find-minimum-diameter-after-merging-two-trees/
 * Runtime: 1357ms (8.72%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
private:
  pair<int, int> farest(const vector<vector<int>>& graph, const int start) {
    int res;
    int maxd = 0;
    function<void(int, int, int)> dfs = [&](int u, int pa, int d) {
      if (d > maxd) {
        maxd = d;
        res = u;
      }
      for (int v : graph[u]) {
        if (v != pa) {
          dfs(v, u, d + 1);
        }
      }
    };
    dfs(start, -1, 0);
    return {res, maxd};
  }

  int diameter(const vector<vector<int>>& edges) {
    const int n = edges.size() + 1;
    vector<vector<int>> graph(n);
    for (const auto& e : edges) {
      graph[e[0]].emplace_back(e[1]);
      graph[e[1]].emplace_back(e[0]);
    }

    return farest(graph, farest(graph, 0).first).second;
  }
public:
  int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
    const int d1 = diameter(edges1);
    const int d2 = diameter(edges2);
    return max((d1 + 1) / 2 + (d2 + 1) / 2 + 1, max(d1, d2));
  }
};
