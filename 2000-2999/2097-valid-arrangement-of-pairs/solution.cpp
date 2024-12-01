/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/valid-arrangement-of-pairs/
 * Runtime: 1817ms (20.93%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
    const int n = pairs.size();

    unordered_map<int, int> ind;
    unordered_map<int, int> outd;
    unordered_map<int, queue<int>> graph;
    for (const auto& p : pairs) {
      ++ind[p[0]];
      ++outd[p[1]];
      graph[p[0]].push(p[1]);
    }

    int start = pairs[0][0];
    for (auto [k, v] : ind) {
      if (v == outd[k] + 1) {
        start = k;
      }
    }

    vector<int> result;
    result.reserve(n + 1);

    function<void(int)> dfs = [&](int s) {
      while (!graph[s].empty()) {
        int e = graph[s].front();
        graph[s].pop();
        dfs(e);
      }
      result.emplace_back(s);
    };
    dfs(start);

    reverse(result.begin(), result.end());

    for (int i = 0; i < n; i++) {
      pairs[i][0] = result[i];
      pairs[i][1] = result[i + 1];
    }
    return pairs;
  }
};
