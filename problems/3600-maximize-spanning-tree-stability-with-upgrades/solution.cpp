/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/maximize-spanning-tree-stability-with-upgrades/
 * Runtime: 112ms (60.41%)
 */

class Solution {
private:
  int pa[100001];

  int find(int x) {
    if (pa[x] == x) {
      return x;
    }
    return (pa[x] = find(pa[x]));
  }
public:
  int maxStability(int n, vector<vector<int>>& edges, int k) {
    sort(edges.begin(), edges.end(), [&](const auto& l, const auto& r) {
      return l[3] > r[3] || (l[3] == r[3] && l[2] > r[2]);
    });

    for (int i = 0; i < n; ++i) {
      pa[i] = i;
    }

    int low = INT_MAX;
    if (edges.front()[3] != 1) {
      low = 0;
    }

    vector<int> cands;
    int left = n - 1;

    for (const auto& edge : edges) {
      const int u = find(edge[0]);
      const int v = find(edge[1]);

      if (edge[3] == 1) {
        if (u == v) {
          return -1;
        }
        pa[u] = v;
        low = edge[2];
        --left;
      } else if (u != v) {
        pa[u] = v;
        cands.emplace_back(edge[2]);
        --left;
      }
    }
    if (left != 0) {
      return -1;
    }

    reverse(cands.begin(), cands.end());
    for (int& cand : cands) {
      if (k > 0) {
        --k;
        cand *= 2;
      }
    }
    if (cands.empty()) {
      return low;
    }
    int res = *min_element(cands.begin(), cands.end());
    if (low == 0) {
      return res;
    }

    return min(low, res);
  }
};
