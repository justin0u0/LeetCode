/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/number-of-nodes-in-the-sub-tree-with-the-same-label/
 * Runtime: 587ms (85.19%)
 */

class Solution {
private:
  class Solver {
  private:
    int n;
    const vector<vector<int>>& graph;
    const string& labels;

    const int numLabels = 26;
  public:
    vector<vector<int>> labelsCount;

    Solver(int n, const vector<vector<int>>& graph, const string& labels)
      : n(n), graph(graph), labels(labels), labelsCount(n, vector<int>(numLabels, 0)) {}
    
    void dfs(int u, int pa) {
      labelsCount[u][labels[u] - 'a'] = 1;
      for (const int& v : graph[u]) {
        if (v != pa) {
          dfs(v, u);
        }
      }
      if (pa != -1) {
        for (int i = 0; i < numLabels; ++i) {
          labelsCount[pa][i] += labelsCount[u][i];
        }
      }
    }
  };
public:
  vector<int> countSubTrees(int n, vector<vector<int>>& edges, string& labels) {
    vector<vector<int>> graph(n);
    for (const vector<int>& e : edges) {
      graph[e[0]].emplace_back(e[1]);
      graph[e[1]].emplace_back(e[0]);
    }

    Solver s(n, graph, labels);
    s.dfs(0, -1);

    vector<int> answer(n);
    for (int i = 0; i < n; ++i) {
      answer[i] = s.labelsCount[i][labels[i] - 'a'];
    }
    return answer;
  }
};
