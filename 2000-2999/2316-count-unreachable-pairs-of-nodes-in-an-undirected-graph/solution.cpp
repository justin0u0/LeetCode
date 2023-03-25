/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/
 * Runtime: 448ms (98.63%)
 */

class Solution {
private:
  class DJS {
  public:
    vector<int> pa;
    vector<int> sz;

    DJS(int n) : pa(vector<int>(n)), sz(vector<int>(n, 1)) {
      for (int i = 0; i < n; ++i) {
        pa[i] = i;
      }
    }

    int find(int x) {
      if (pa[x] == x) {
        return x;
      }
      pa[x] = find(pa[x]);
      return pa[x];
    }

    void merge(int x, int y) {
      x = find(x);
      y = find(y);
      if (x != y) {
        pa[x] = y;
        sz[y] += sz[x];
      }
    }
  };
public:
  long long countPairs(int n, vector<vector<int>>& edges) {
    DJS d(n);
    for (const vector<int>& e : edges) {
      d.merge(e[0], e[1]);
    }
    int nodes = 0;
    long long answer = 0;
    for (int i = 0; i < n; ++i) {
      if (d.pa[i] == i) {
        answer += 1LL * nodes * d.sz[i];
        nodes += d.sz[i];
      }
    }
    return answer;
  }
};
