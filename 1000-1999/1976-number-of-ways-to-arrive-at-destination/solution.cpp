/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/
 * Runtime: 4ms (86.38%)
 */

class Solution {
public:
  int countPaths(int n, vector<vector<int>>& roads) {
    vector<vector<pair<int, int>>> graph(n);
    for (const auto& edge : roads) {
      graph[edge[0]].push_back({edge[1], edge[2]});
      graph[edge[1]].push_back({edge[0], edge[2]});
    }

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, 0});

    vector<long long> dist(n, 1e12);
    dist[0] = 0;

    while (!pq.empty()) {
      auto [d, u] = pq.top();
      pq.pop();

      if (dist[u] < d) {
        continue;
      }

      for (auto [v, w] : graph[u]) {
        if (dist[v] > d + w) {
          dist[v] = d + w;
          pq.push({d + w, v});
        }
      }
    }

    const int mod = 1e9 + 7;

    vector<int> ways(n, 0);
    ways[0] = 1;

    pq.push({0, 0});
    while (!pq.empty()) {
      auto [d, u] = pq.top();
      pq.pop();

      for (auto [v, w] : graph[u]) {
        if (dist[v] == d + w) {
          if (ways[v] == 0) {
            pq.push({dist[v], v});
          }
          ways[v] = (ways[v] + ways[u]) % mod;
        }
      }
    }
    return ways[n - 1];
  }
};
