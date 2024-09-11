/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/modify-graph-edge-weights/
 * Runtime: 2421ms (8.04%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
    const int inf = 0x3f3f3f3f;
    vector<vector<unsigned int>> dist(n, vector<unsigned int>(n, inf));
    for (const auto& e : edges) {
      if (e[2] != -1) {
        dist[e[0]][e[1]] = e[2];
        dist[e[1]][e[0]] = e[2];
      }
    }

    for (int i = 0; i < n; ++i) {
      dist[i][i] = 0;
    }

    for (int k = 0; k < n; ++k) {
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
          dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        }
      }
    }

    if (dist[source][destination] < target) {
      return vector<vector<int>>{};
    }

    for (auto& e : edges) {
      if (e[2] == -1) {
        int d = min(dist[source][e[0]] + dist[e[1]][destination],
          dist[source][e[1]] + dist[e[0]][destination]);
        e[2] = max(1, target - d);
        dist[e[0]][e[1]] = e[2];
        dist[e[1]][e[0]] = e[2];

        for (int i = 0; i < n; ++i) {
          for (int j = 0; j < n; ++j) {
            dist[i][j] = min(dist[i][j],
              min(dist[i][e[0]] + dist[e[1]][j], dist[i][e[1]] + dist[e[0]][j]) + e[2]);
          }
        }
      }
    }

    if (dist[source][destination] != target) {
      return vector<vector<int>>{};
    }
    return edges;
  }
};
