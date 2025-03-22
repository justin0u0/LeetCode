/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/count-the-number-of-complete-components/
 * Runtime: 36ms (79.58%)
 */

class Solution {
public:
  int countCompleteComponents(const int n, const vector<vector<int>>& edges) {
    vector<vector<bool>> has(n, vector<bool>(n, false));
    for (const auto& edge : edges) {
      has[edge[0]][edge[1]] = true;
      has[edge[1]][edge[0]] = true;
    }

    vector<bool> vis(n, false);
    vector<int> comp;

    function<void(int)> dfs = [&](int u) {
      vis[u] = true;
      comp.emplace_back(u);
      for (int v = 0; v < n; ++v) {
        if (has[u][v] && !vis[v]) {
          dfs(v);
        }
      }
    };

    int complete = 0;
    for (int i = 0; i < n; ++i) {
      if (!vis[i]) {
        comp.clear();
        dfs(i);

        bool ok = true;
        for (int u : comp) {
          for (int v : comp) {
            if (u != v && !has[u][v]) {
              ok = false;
            }
          }
        }
        if (ok) {
          ++complete;
        }
      }
    }

    return complete;
  }
};
