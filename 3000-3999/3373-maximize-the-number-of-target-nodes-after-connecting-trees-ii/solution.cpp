/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/maximize-the-number-of-target-nodes-after-connecting-trees-ii/
 * Runtime: 1880ms (5.44%)
 */

class Solution {
private:
  void colors(const vector<vector<int>>& edges, vector<int>& color, array<int, 2>& count) {
    const int n = edges.size() + 1;
    vector<vector<int>> graph(n);
    for (const auto& e : edges) {
      graph[e[0]].emplace_back(e[1]);
      graph[e[1]].emplace_back(e[0]);
    }

    function<void(int)> dfs = [&](int u) {
      for (int v : graph[u]) {
        if (color[v] == -1) {
          color[v] = color[u] ^ 1;
          ++count[color[v]];
          dfs(v);
        }
      }
    };
    color[0] = 0;
    ++count[0];
    dfs(0);
  }
public:
  vector<int> maxTargetNodes(const vector<vector<int>>& edges1, const vector<vector<int>>& edges2) {
    const int n = edges1.size() + 1;
    vector<int> color1(n, -1);
    array<int, 2> count1;
    colors(edges1, color1, count1);

    const int m = edges2.size() + 1;
    vector<int> color2(m, -1);
    array<int, 2> count2;
    colors(edges2, color2, count2);

    vector<int> target(n, max(count2[0], count2[1]));
    for (int i = 0; i < n; ++i) {
      target[i] += count1[color1[i]];
    }
    return target;
  }
};
