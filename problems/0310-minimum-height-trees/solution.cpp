/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimum-height-trees/
 * Runtime: 132ms (38.20%)
 */

class Solution {
public:
  vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
    vector<vector<int>> graph(n);
    for (const auto& e : edges) {
      graph[e[0]].emplace_back(e[1]);
      graph[e[1]].emplace_back(e[0]);
    }

    vector<int> dp1(n, 0);
    vector<int> dp2(n, 0);
    function<int(int, int)> dfs1 = [&](int u, int pa) {
      int& m1 = dp1[u];
      int& m2 = dp2[u];
      for (int v : graph[u]) {
        if (v == pa) {
          continue;
        }
        int d = dfs1(v, u) + 1;
        if (d > m1) {
          m2 = m1;
          m1 = d;
        } else if (d > m2) {
          m2 = d;
        }
      }
      return m1;
    };
    dfs1(0, 0);

    vector<int> height(n, 0);
    function<void(int, int, int)> dfs2 = [&](int u, int pa, int maxd) {
      height[u] = max(dp1[u], maxd);
      for (int v : graph[u]) {
        if (v == pa) {
          continue;
        }
        if (dp1[u] == dp1[v] + 1) {
          dfs2(v, u, max(maxd, dp2[u]) + 1);
        } else {
          dfs2(v, u, max(maxd, dp1[u]) + 1);
        }
      }
    };
    dfs2(0, 0, 0);

    int minh = *min_element(height.begin(), height.end());
    vector<int> answer;
    for (int i = 0; i < n; ++i) {
      if (height[i] == minh) {
        answer.emplace_back(i);
      }
    }
    return answer;
  }
};
