/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/remove-max-number-of-edges-to-keep-graph-fully-traversable/
 * Runtime: 495ms (97.83%)
 */

class Solution {
private:
  int pa1[100010];
  int pa2[100010];

  int find(int* pa, int x) {
    if (pa[x] == x) {
      return x;
    }
    return (pa[x] = find(pa, pa[x]));
  }

  inline int solve(const vector<vector<int>>& edges, int type, int* pa) {
    int count = 0;
    for (const vector<int>& e : edges) {
      if (e[0] != type) {
        continue;
      }

      int fx = find(pa, e[1]);
      int fy = find(pa, e[2]);
      if (fx != fy) {
        pa[fx] = fy;
        ++count;
      }
    }

    return count;
  }
public:
  int maxNumEdgesToRemove(int n, const vector<vector<int>>& edges) {
    for (int i = 1; i <= n; ++i) {
      pa1[i] = i;
    }

    int count = solve(edges, 3, pa1);
    if (count == n - 1) {
      return (int)edges.size() - count;
    }

    for (int i = 1; i <= n; ++i) {
      pa2[i] = pa1[i];
    }

    int count1 = solve(edges, 1, pa1);
    if (count1 + count != n - 1) {
      return -1;
    }
    int count2 = solve(edges, 2, pa2);
    if (count2 + count != n - 1) {
      return -1;
    }

    return (int)edges.size() - count - count1 - count2;
  }
};
