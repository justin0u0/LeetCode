/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/maximize-the-number-of-target-nodes-after-connecting-trees-i/
 * Runtime: 202ms (56.22%)
 */

class Solution {
public:
  vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
    const int m = edges2.size() + 1;
    vector<vector<int>> graph2(m);
    for (const auto& e : edges2) {
      graph2[e[0]].emplace_back(e[1]);
      graph2[e[1]].emplace_back(e[0]);
    }

    int most = 0;
    vector<int> vis2(m, -1);
    for (int i = 0; i < m; ++i) {
      queue<int> q;
      vis2[i] = i;
      q.push(i);

      int t = 0;
      for (int j = 0; j < k && !q.empty(); ++j) {
        size_t sz = q.size();
        while (sz--) {
          const int u = q.front();
          q.pop();
          ++t;
          for (int v : graph2[u]) {
            if (vis2[v] != i) {
              vis2[v] = i;
              q.push(v);
            }
          }
        }
      }
      most = max(most, t);
    }

    const int n = edges1.size() + 1;
    vector<vector<int>> graph1(n);
    for (const auto& e : edges1) {
      graph1[e[0]].emplace_back(e[1]);
      graph1[e[1]].emplace_back(e[0]);
    }

    vector<int> target(n, most);
    vector<int> vis1(n, -1);
    for (int i = 0; i < n; ++i) {
      queue<int> q;
      vis1[i] = i;
      q.push(i);

      for (int j = 0; j <= k && !q.empty(); ++j) {
        size_t sz = q.size();
        while (sz--) {
          const int u = q.front();
          q.pop();

          ++target[i];

          for (int v : graph1[u]) {
            if (vis1[v] != i) {
              vis1[v] = i;
              q.push(v);
            }
          }
        }
      }
    }

    return target;
  }
};
