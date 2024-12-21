/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/maximum-number-of-k-divisible-components/
 * Runtime: 160ms (34.18%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
    vector<vector<int>> graph(n);
    for (const auto& e : edges) {
      graph[e[0]].emplace_back(e[1]);
      graph[e[1]].emplace_back(e[0]);
    }

    int splits = 0;
    function<int(int, int)> dfs = [&](int u, int pa) {
      int sum = values[u] % k;
      for (int v : graph[u]) {
        if (v != pa) {
          sum = (sum + dfs(v, u)) % k;
        }
      }
      if (sum == 0) {
        ++splits;
      }
      return sum;
    };

    dfs(0, -1);
    return splits;
  }
};
