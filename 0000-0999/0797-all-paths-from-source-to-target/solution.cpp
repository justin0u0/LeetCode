/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/all-paths-from-source-to-target/
 * Runtime: 13ms (80.29%)
 */

class Solution {
private:
  vector<vector<int>> paths;
  vector<int> box;
  void dfs(vector<vector<int>>& G, int u) {
    box.emplace_back(u);
    if (u == (int)G.size() - 1) {
      paths.emplace_back(box);
      box.pop_back();
      return;
    }
    for (auto v: G[u]) dfs(G, v);
    box.pop_back();
  }
public:
  vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
    dfs(graph, 0);
    return paths;
  }
};
