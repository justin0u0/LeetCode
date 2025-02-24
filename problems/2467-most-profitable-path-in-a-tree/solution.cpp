/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/most-profitable-path-in-a-tree/
 * Runtime: 264ms (19.91%)
 */

class Solution {
public:
  int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
    const int n = edges.size() + 1;
    vector<vector<int>> graph(n);
    for (const auto& e : edges) {
      graph[e[0]].emplace_back(e[1]);
      graph[e[1]].emplace_back(e[0]);
    }

    vector<int> dist(n, -1);
    dist[0] = 0;

    queue<int> q;
    q.push(0);
    while (!q.empty()) {
      int u = q.front();
      q.pop();

      for (int v : graph[u]) {
        if (dist[v] == -1) {
          dist[v] = dist[u] + 1;
          q.push(v);
        }
      }
    }

    vector<int> vis(n, -1);
    int b = bob;
    vis[b] = 0;
    for (int i = 1; b != 0; ++i) {
      for (int v : graph[b]) {
        if (dist[v] == dist[b] - 1) {
          b = v;
          break;
        }
      }
      vis[b] = i;
    }

    function<int(int, int)> dfs = [&](int u, int pre) {
      int profit = -1e9;
      bool ok = false;
      for (int v : graph[u]) {
        if (v != pre) {
          profit = max(profit, dfs(v, u));
          ok = true;
        }
      }
      if (!ok) {
        profit = 0;
      }

      if (vis[u] != -1 && vis[u] < dist[u]) {
        return profit;
      }
      if (vis[u] == dist[u]) {
        return profit + amount[u] / 2;
      }
      return profit + amount[u];
    };
    return dfs(0, -1);
  }
};
