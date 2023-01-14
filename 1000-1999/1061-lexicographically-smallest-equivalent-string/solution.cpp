/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/lexicographically-smallest-equivalent-string/
 * Runtime: 0ms (100.00%)
 */

class Solution {
private:
  int pa[128];

  int find(int x) {
    if (pa[x] == x) {
      return x;
    }
    return (pa[x] = find(pa[x]));
  }

  void merge(int x, int y) {
    int fx = find(x);
    int fy = find(y);
    if (fx > fy) {
      swap(fx, fy);
    }
    pa[fy] = fx;
  }
public:
  string smallestEquivalentString(string& s1, string& s2, string& baseStr) {
    for (int i = 0; i < 128; ++i) {
      pa[i] = i;
    }

    int n = s1.size();
    for (int i = 0; i < n; ++i) {
      merge(s1[i], s2[i]);
    }
    for (char& c : baseStr) {
      c = find(c);
    }
    return baseStr;
  }
};
