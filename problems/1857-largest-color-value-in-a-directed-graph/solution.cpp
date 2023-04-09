/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/largest-color-value-in-a-directed-graph/
 * Runtime: 571ms (89.74%)
 */

class Solution {
private:
  class Solver {
  private:
    int n;
    const string& colors;
    const vector<vector<int>>& graph;
    vector<vector<int>>& sum;
    vector<bool>& vis;
    vector<bool>& instack;

    bool dfs(int u) {
      vis[u] = true;
      instack[u] = true;
      for (const int& v : graph[u]) {
        if (!vis[v]) {
          // tree edge
          if (dfs(v)) {
            return true;
          }
        } else if (instack[v]) {
          // back edge
          return true;
        }
        for (int i = 0; i < 26; ++i) {
          sum[u][i] = max(sum[u][i], sum[v][i]);
        }
      }
      instack[u] = false;
      ++sum[u][colors[u] - 'a'];
      return false;
    }
  public:
    Solver(int n, const string& colors, const vector<vector<int>>& graph, vector<vector<int>>& sum, vector<bool>& vis, vector<bool>& instack) :
      n(n), colors(colors), graph(graph), sum(sum), vis(vis), instack(instack) {}

    int solve() {
      int answer = 0;
      for (int i = 0; i < n; ++i) {
        if (!vis[i]) {
          if (dfs(i)) {
            return -1;
          }
        }
        for (int j = 0; j < 26; ++j) {
          answer = max(answer, sum[i][j]);
        }
      }
      return answer;
    }
  };
public:
  int largestPathValue(const string& colors, const vector<vector<int>>& edges) {
    int n = colors.size();

    vector<vector<int>> graph(n);
    for (const vector<int>& e : edges) {
      graph[e[0]].emplace_back(e[1]);
    }
    vector<vector<int>> sum(n, vector<int>(26, 0));
    vector<bool> vis(n, false);
    vector<bool> instack(n, false);

    Solver s(n, colors, graph, sum, vis, instack);
    return s.solve();
  }
};
