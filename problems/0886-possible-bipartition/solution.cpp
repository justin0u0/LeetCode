/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/possible-bipartition/
 * Runtime: 226ms (88.19%)
 */

class Solution {
private:
  class Solver {
  private:
    int n;
    const vector<vector<int>>& graph;
    vector<int> color;
  public:
    Solver(int n, const vector<vector<int>>& graph)
      : n(n), graph(graph), color(n, 0) {}

    bool dfs(int u) {
      for (const int& v : graph[u]) {
        if (color[v] == color[u]) {
          return false;
        }
        if (!color[v]) {
          color[v] = 3 - color[u];
          if (!dfs(v)) {
            return false;
          }
        }
      }
      return true;
    }

    bool solve() {
      for (int i = 0; i < n; ++i) {
        if (!color[i]) {
          color[i] = 1;
          if (!dfs(i)) {
            return false;
          }
        }
      }
      return true;
    }
  };
public:
  bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
    vector<vector<int>> graph(n);
    for (const vector<int>& edge : dislikes) {
      graph[edge[0] - 1].emplace_back(edge[1] - 1);
      graph[edge[1] - 1].emplace_back(edge[0] - 1);
    }
    
    Solver s(n, graph);
    return s.solve();
  }
};
