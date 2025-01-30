/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/divide-nodes-into-the-maximum-number-of-groups/
 * Runtime: 114ms (94.54%)
 */

class Solution {
public:
  int magnificentSets(const int n, const vector<vector<int>>& edges) {
    // Grouping exists if and only if there is a valid bipartite graphing.
    //
    // BFS from each node to find the largest number of groups for each
    // connected component.

    vector<vector<int>> graph(n + 1);
    for (const auto& edge : edges) {
      graph[edge[0]].emplace_back(edge[1]);
      graph[edge[1]].emplace_back(edge[0]);
    }

    vector<int> colors(n + 1, -1);
    function<bool(int)> dfs = [&](int u) {
      for (int v : graph[u]) {
        if (colors[u] == colors[v]) {
          return false;
        }
        if (colors[v] == -1) {
          colors[v] = colors[u] ^ 1;
          if (!dfs(v)) {
            return false;
          }
        }
      }
      return true;
    };

    int color = 0;
    for (int i = 1; i <= n; ++i) {
      if (colors[i] == -1) {
        colors[i] = color;
        if (!dfs(i)) {
          return -1;
        }
        color += 2;
      }
    }

    const int m = color >> 1;
    vector<vector<int>> components(m);
    for (int i = 1; i <= n; ++i) {
      components[colors[i] >> 1].emplace_back(i);
    }

    vector<int> vis(n + 1, 0);
    queue<int> q;

    int groups = 0;
    int bfsn = 0;
    for (const auto& c : components) {
      int mxg = 0;
      for (int s : c) {
        ++bfsn;
        vis[s] = bfsn;
        q.push(s);

        int dist;
        for (dist = 0; !q.empty(); ++dist) {
          int sz = q.size();
          while (sz--) {
            int u = q.front();
            q.pop();
  
            for (int v : graph[u]) {
              if (vis[v] == bfsn) {
                continue;
              }
              vis[v] = bfsn;
              q.push(v);
            }
          }
        }

        mxg = max(mxg, dist);
      }

      groups += mxg;
    }

    return groups;
  }
};
