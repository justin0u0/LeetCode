/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/shortest-path-with-alternating-colors/
 * Runtime: 11ms (99.36%)
 */

class Solution {
public:
  vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
    vector<vector<int>> dist(2, vector<int>(n, INT_MAX));
    dist[0][0] = 0;
    dist[1][0] = 0;

    vector<vector<vector<int>>> graph(2, vector<vector<int>>(n));
    for (const vector<int>& e : redEdges) {
      graph[0][e[0]].emplace_back(e[1]);
    }
    for (const vector<int>& e : blueEdges) {
      graph[1][e[0]].emplace_back(e[1]);
    }

    queue<pair<bool, int>> q;
    q.push({0, 0});
    q.push({1, 0});

    while (!q.empty()) {
      size_t qs = q.size();
      while (qs--) {
        auto [i, u] = q.front();
        q.pop();

        bool j = i ^ 1;
        for (const int& v : graph[i][u]) {
          if (dist[j][v] != INT_MAX) {
            continue;
          }

          dist[j][v] = dist[i][u] + 1;
          q.push({j, v});
        }
      }
    }

    for (int i = 0; i < n; ++i) {
      int& d = dist[0][i];
      d = min(d, dist[1][i]);
      if (d == INT_MAX) {
        d = -1;
      }
    }

    return dist[0];
  }
};
