/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/satisfiability-of-equality-equations/
 * Runtime: 3ms (96.94%)
 */

class Solution {
private:
  class DJS {
  private:
    int* pa;
  public:
    DJS(size_t size) : pa(new int[size]) {
      for (int i = 0 ; i < size; ++i) {
        pa[i] = i;
      }
    }

    ~DJS() {
      delete[] pa;
    }

    int findset(int x) {
      if (pa[x] == x) {
        return x;
      }

      return (pa[x] = findset(pa[x]));
    }

    void merge(int x, int y) {
      int fx = findset(pa[x]);
      int fy = findset(pa[y]);
      pa[fx] = fy;
    }
  };
public:
  bool equationsPossible(vector<string>& equations) {
    DJS djs(26);

    for (const string& e : equations) {
      if (e[1] == '=') {
        const int u = e[0] - 'a';
        const int v = e[3] - 'a';
        djs.merge(u, v);
      }
    }

    for (const string& e : equations) {
      if (e[1] == '!') {
        const int u = e[0] - 'a';
        const int v = e[3] - 'a';
        if (djs.findset(u) == djs.findset(v)) {
          return false;
        }
      }
    }

    return true;
  }
};
