/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/network-recovery-pathways/
 * Runtime: 249ms (64.82%)
 */

class Solution {
private:
  inline static constexpr long long INF = 1e18;
public:
  int findMaxPathScore(const vector<vector<int>>& edges, const vector<bool>& online, const long long k) {
    const auto n = online.size();

    vector<vector<pair<int, int>>> graph(n);
    for (const auto& edge : edges) {
      if (online[edge[0]] && online[edge[1]]) {
        graph[edge[0]].push_back({edge[1], edge[2]});
      }
    }

    vector<long long> dist(n);
    using Node = pair<long long, int>;
    priority_queue<Node, vector<Node>, greater<Node>> pq;

    auto dijkstra = [&](const int low) {
      ranges::fill(dist, INF);
      dist[0] = 0;

      pq.push({0, 0});

      while (!pq.empty()) {
        const auto [d, u] = pq.top();
        pq.pop();

        if (u == n - 1) {
          while (!pq.empty()) {
            pq.pop();
          }
          return d <= k;
        }

        if (dist[u] < d) {
          continue;
        }

        for (const auto [v, cost]: graph[u]) {
          if (cost < low) {
            continue;
          }
          if (dist[v] > d + cost) {
            dist[v] = d + cost;
            pq.push({dist[v], v});
          }
        }
      }

      return false;
    };

    int l = 0;
    int r = 1e9 + 1;

    while (l < r) {
      const int mid = (l + r) >> 1;
      if (dijkstra(mid)) {
        l = mid + 1;
      } else {
        r = mid;
      }
    }

    return l - 1;
  }
};
