/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimum-cost-walk-in-weighted-graph/
 * Runtime: 21ms (68.18%)
 */

class Solution {
private:
  int pa[100001];
  int b[100001];

  int find(int x) {
    if (pa[x] == x) {
      return x;
    }
    return pa[x] = find(pa[x]);
  }
public:
  vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
    for (int i = 0; i < n; ++i) {
      pa[i] = i;
    }
    memset(b, 0x7fffffff, sizeof(b));

    for (const auto& edge : edges) {
      int u = find(edge[0]);
      int v = find(edge[1]);
      if (u != v) {
        pa[u] = v;
      }
    }

    for (const auto& edge : edges) {
      int p = find(edge[0]);
      b[p] &= edge[2];
    }

    vector<int> res;
    res.reserve(queries.size());
    for (const auto& query : queries) {
      int u = find(query[0]);
      int v = find(query[1]);
      if (u != v) {
        res.emplace_back(-1);
      } else {
        res.emplace_back(b[u]);
      }
    }
    return res;
  }
};
