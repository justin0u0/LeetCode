/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/
 * Runtime: 344ms (92.54%)
 */

class Solution {
private:
  int solve(const vector<vector<pair<int, bool>>>& graph, int u, int pa) {
    int reverses = 0;
    for (const auto& [v, rev]: graph[u]) {
      if (v != pa) {
        if (rev) {
          ++reverses;
        }
        reverses += solve(graph, v, u);
      }
    }
    return reverses;
  }
public:
  int minReorder(int n, vector<vector<int>>& connections) {
    vector<vector<pair<int, bool>>> graph(n);
    for (const vector<int>& e : connections) {
      graph[e[0]].emplace_back(e[1], true);
      graph[e[1]].emplace_back(e[0], false);
    }

    return solve(graph, 0, -1);
  }
};
