/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/cheapest-flights-within-k-stops/
 * Runtime: 16ms (98.14%)
 */

class Solution {
public:
  int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    ++k;

    vector<vector<pair<int, int>>> graph(n);
    for (const vector<int>& f : flights) {
      graph[f[0]].emplace_back(f[1], f[2]);
    }

    queue<pair<int, int>> q;
    q.push({src, 0});

    vector<int> minCost(n, INT_MAX);
    minCost[src] = 0;

    while (k--) {
      int qs = q.size();
      while (qs--) {
        auto [u, uCost] = q.front();
        q.pop();

        for (const auto& [v, vCost] : graph[u]) {
          int& cost = minCost[v];
          if (cost > uCost + vCost) {
            cost = uCost + vCost;
            q.push({v, cost});
          }
        }
      }
    }

    return (minCost[dst] == INT_MAX) ? -1 : minCost[dst];
  }
};
