/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/critical-connections-in-a-network/
 * Runtime: 669ms
 */

class Solution {
private:
  void dfs(int u, int idx, vector<vector<int>>& graph, vector<int>& pa, vector<int>& vis, vector<int>& low) {
    vis[u] = ++idx;
    low[u] = idx;

    for (const int& v : graph[u]) {
      if (vis[v] == -1) {
        pa[v] = u;
        dfs(v, idx, graph, pa, vis, low);
        low[u] = min(low[u], low[v]);
      } else if (v != pa[u]) {
        low[u] = min(low[u], low[v]);
      }
    }
  }
public:
  vector<vector<int>> criticalConnections(int n, vector<vector<int>>& edges) {
    vector<vector<int>> graph(n);
    for (const vector<int>& edge : edges) {
      graph[edge[0]].emplace_back(edge[1]);
      graph[edge[1]].emplace_back(edge[0]);
    }

    vector<int> vis(n, -1);
    vector<int> low(n, 0x3f3f3f3f);
    vector<int> pa(n, -1);
    dfs(0, 0, graph, pa, vis, low);

    vector<vector<int>> cutEdges;
    for (int i = 0; i < n; ++i) {
      if (pa[i] != -1 && vis[i] == low[i]) {
        vector<int> cutEdge{pa[i], i};
        cutEdges.emplace_back(cutEdge);
      }
    }
    return cutEdges;
  }
};
