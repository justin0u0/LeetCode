/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/find-eventual-safe-states/
 * Runtime: 138ms (99.81%)
 */

const auto static _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
private:
  bool dfs(const vector<vector<int>>& graph, vector<int>& safe, int u) {
    int& res = safe[u];
    if (res != -1) {
      return res;
    }

    res = false;
    for (const int v : graph[u]) {
      if (!dfs(graph, safe, v)) {
        return res;
      }
    }

    res = true;
    return res;
  }
public:
  vector<int> eventualSafeNodes(const vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> safe(n, -1);
    vector<int> answer;
    answer.reserve(n);
    for (int i = 0; i < n; ++i) {
      if (dfs(graph, safe, i)) {
        answer.emplace_back(i);
      }
    }
    return answer;
  }
};
