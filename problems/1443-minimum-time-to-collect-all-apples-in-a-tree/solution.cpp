/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/
 * Runtime: 171ms (97.32%)
 */

class Solution {
private:
  class Solver {
  private:
    const int n;
    const vector<vector<int>>& graph;
    const vector<bool>& hasApple;

  public:
    Solver(const int n, const vector<vector<int>>& graph, const vector<bool>& hasApple)
      : n(n), graph(graph), hasApple(hasApple) {}

    int dfs(int u, int pa) {
      int sum = 0;
      for (const int& v : graph[u]) {
        if (v != pa) {
          sum += dfs(v, u);
        }
      }

      if (hasApple[u] || sum != 0) {
        ++sum;
      }

      return sum;
    }
  };
public:
  int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
    vector<vector<int>> graph(n);
    for (const vector<int>& e : edges) {
      graph[e[0]].emplace_back(e[1]);
      graph[e[1]].emplace_back(e[0]);
    }

    Solver s(n, graph, hasApple);
    return max(0, s.dfs(0, -1) - 1) << 1;
  }
};
