/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/reachable-nodes-in-subdivided-graph/
 * Runtime: 23ms (91.59%)
 */

class Solution {
public:
  int reachableNodes(const vector<vector<int>>& edges, const int maxMoves, const int n) {
    vector<vector<pair<int, int>>> graph(n);
    for (const auto& e : edges) {
      graph[e[0]].push_back({e[1], e[2] + 1});
      graph[e[1]].push_back({e[0], e[2] + 1});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 0});

    vector<int> dist(n, 0x3f3f3f3f);
    dist[0] = 0;

    while (!pq.empty()) {
      auto [d, u] = pq.top();
      pq.pop();

      if (d > dist[u]) {
        continue;
      }

      for (auto [v, w] : graph[u]) {
        if (dist[v] > d + w) {
          dist[v] = d + w;
          pq.push({dist[v], v});
        }
      }
    }

    int nodes = 0;
    for (int i = 0; i < n; ++i) {
      if (dist[i] <= maxMoves) {
        ++nodes;
      }
    }
    for (const auto& e : edges) {
      nodes += min(e[2], max(0, maxMoves - dist[e[0]]) + max(0, maxMoves - dist[e[1]]));
    }
    return nodes;
  }
};
