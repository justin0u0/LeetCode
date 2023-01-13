/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/longest-path-with-different-adjacent-characters/
 * Runtime: 384ms (94.38%)
 */

class Solution {
private:
  class Solver {
  private:
    const vector<vector<int>>& graph;
    const string& labels;
  public:
    int longest;

    Solver(const vector<vector<int>>& graph, const string& labels)
      : graph(graph), labels(labels), longest(0) {}

    int solve(int u) {
      int lp = 0;   // longest path
      int slp = 0;  // second longest path
      for (const int& v : graph[u]) {
        int p = solve(v);
        if (labels[u] != labels[v]) {
          if (p > lp) {
            slp = lp;
            lp = p;
          } else if (p > slp) {
            slp = p;
          }
        }
      }

      longest = max(longest, 1 + lp + slp);
      return lp + 1;
    }
  };
public:
  int longestPath(vector<int>& parent, string& labels) {
    int n = labels.size();
    vector<vector<int>> graph(n);
    for (int i = 1; i < n; ++i) {
      graph[parent[i]].emplace_back(i);
    }

    Solver s(graph, labels);
    s.solve(0);
    return s.longest;
  }
};
