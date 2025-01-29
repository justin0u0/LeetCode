/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/redundant-connection/
 * Runtime: 0ms (100.00%)
 */

class Solution {
private:
  int pa[1001];

  int find(int x) {
    if (pa[x] == x) {
      return x;
    }
    return (pa[x] = find(pa[x]));
  }
public:
  vector<int> findRedundantConnection(const vector<vector<int>>& edges) {
    const int n = edges.size();
    for (int i = 1; i <= n; ++i) {
      pa[i] = i;
    }

    for (const auto& edge : edges) {
      const int u = find(edge[0]);
      const int v = find(edge[1]);
      if (u == v) {
        return edge;
      }
      pa[u] = v;
    }
    return {};
  }
};
