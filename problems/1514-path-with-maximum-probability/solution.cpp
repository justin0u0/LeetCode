/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/path-with-maximum-probability/
 * Runtime: 193ms (93.16%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  double maxProbability(int n, const vector<vector<int>>& edges, const vector<double>& succProb, int start, int end) {
    priority_queue<pair<double, int>> pq;
    pq.push({1, start});

    vector<double> prob(n, 0);
    prob[start] = 1;

    vector<vector<pair<int, double>>> graph(n);
    for (int i = 0; i < edges.size(); ++i) {
      auto& e = edges[i];
      graph[e[0]].emplace_back(e[1], succProb[i]);
      graph[e[1]].emplace_back(e[0], succProb[i]);
    }

    while (!pq.empty()) {
      auto [pu, u] = pq.top();
      pq.pop();

      if (prob[u] != pu) {
        continue;
      }

      for (const auto [v, s] : graph[u]) {
        double pv = pu * s;
        if (pv > prob[v]) {
          prob[v] = pv;
          pq.push({pv, v});
        }
      }
    }

    return prob[end];
  }
};
