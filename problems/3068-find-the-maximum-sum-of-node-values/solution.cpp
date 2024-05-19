/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/find-the-maximum-sum-of-node-values/
 * Runtime: 204ms (37.33%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  long long maximumValueSum(const vector<int>& nums, const int k, const vector<vector<int>>& edges) {
    const int n = nums.size();
    vector<vector<int>> graph(n);
    for (const auto& e : edges) {
      graph[e[0]].emplace_back(e[1]);
      graph[e[1]].emplace_back(e[0]);
    }

    const int inf = 0x3f3f3f3f;

    function<pair<long long, long long>(int, int)> dfs = [&](int u, int pa) -> pair<long long, long long> {
      long long ue = 0;     // pick even number of edges
      long long uo = -inf;  // pick odd number of edges
      for (int v : graph[u]) {
        if (v == pa) {
          continue;
        }

        auto [ve, vo] = dfs(v, u);

        long long te = ue;
        long long to = uo;
        // not pick
        long long np = max(ve, vo);
        // pick
        long long p = max(ve - nums[v] + (nums[v] ^ k), vo - (nums[v] ^ k) + nums[v]);
        ue = max(te + np, to + p);
        uo = max(te + p, to + np);
      }
      return {ue + nums[u], uo + (nums[u] ^ k)};
    };
    auto [e, o] = dfs(0, -1);
    return max(e, o);
  }
};
