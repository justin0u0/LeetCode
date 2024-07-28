/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/second-minimum-time-to-reach-destination/
 * Runtime: 349ms (99.50%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
    vector<vector<int>> graph(n);
    for (const auto& e : edges) {
      graph[e[0] - 1].emplace_back(e[1] - 1);
      graph[e[1] - 1].emplace_back(e[0] - 1);
    }

    queue<int> q;
    q.push(0);

    vector<pair<int, int>> dist(n, {INT_MAX, INT_MAX});
    dist[0].first = 0;

    for (int d = 1; !q.empty(); ++d) {
      int sz = q.size();
      while (sz--) {
        int u = q.front();
        q.pop();

        for (int v : graph[u]) {
          auto& [d1, d2] = dist[v];
          if (d1 > d) {
            d1 = d;
            q.push(v);
          } else if (d1 != d && d2 > d) {
            d2 = d;
            q.push(v);
          }
        }
      }
    }

    int t = 0;
    for (int i = 0; i < dist[n - 1].second; ++i) {
      if ((t / change) & 1) {
        t += (change - t % change);
      }
      t += time;
    }
    return t;
  }
};
