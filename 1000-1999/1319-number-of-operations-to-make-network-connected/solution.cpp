/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/number-of-operations-to-make-network-connected/
 * Runtime: 106ms (95.82%)
 */

class Solution {
private:
  class DJS {
  private:
    vector<int> pa;
  public:
    int components;

    DJS(int n) : pa(vector<int>(n)), components(n) {
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
        --components;
      }
    }
  };
public:
  int makeConnected(int n, vector<vector<int>>& connections) {
    if (connections.size() < n - 1) {
      return -1;
    }

    DJS d(n);
    for (const vector<int>& c : connections) {
      d.merge(c[0], c[1]);
    }
    return d.components - 1;
  }
};
