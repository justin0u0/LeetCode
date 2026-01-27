/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimum-cost-path-with-edge-reversals/
 * Runtime: 236ms (74.52%)
 */

class Solution {
private:
  const int inf = 0x3f3f3f3f;
public:
  int minCost(const int n, const vector<vector<int>>& edges) {
    vector<vector<pair<int, int>>> graph(n);
    for (const auto& e : edges) {
      const int u = e[0];
      const int v = e[1];
      const int w = e[2];
      graph[u].push_back({v, w});
      graph[v].push_back({u, w * 2});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});

    vector<int> dist(n, inf);
    dist[0] = 0;

    while (!pq.empty()) {
      const auto [d, u] = pq.top();
      pq.pop();

      if (dist[u] > d) {
        continue;
      }
      
      for (const auto [v, w] : graph[u]) {
        if (dist[v] > d + w) {
          dist[v] = d + w;
          pq.push({dist[v], v});
        }
      }
    }

    if (dist[n - 1] == inf) {
      return -1;
    }
    return dist[n - 1];
  }
};
