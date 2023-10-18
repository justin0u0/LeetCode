/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/parallel-courses-iii/
 * Runtime: 261ms (100.00%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
    vector<int> dp(n, 0);
    vector<vector<int>> graph(n);
    for (const auto& e : relations) {
      graph[e[0] - 1].emplace_back(e[1] - 1);
    }
    
    function<int(int)> dfs = [&](int u) {
      if (dp[u] != 0) {
        return dp[u];
      }

      int last = 0;
      for (const int v : graph[u]) {
        last = max(last, dfs(v));
      }

      last += time[u];

      return (dp[u] = last);
    };

    int answer = 0;
    for (int i = 0; i < n; ++i) {
      answer = max(answer, dfs(i));
    }
    return answer;
  }
};
