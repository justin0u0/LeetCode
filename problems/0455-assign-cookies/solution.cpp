/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/assign-cookies/
 * Runtime: 12ms (99.35%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    int n = g.size();
    int m = s.size();
    
    int j = 0;
    for (int i = 0; i < n; ++i) {
      while (j < m && s[j] < g[i]) {
        ++j;
      }
      if (j == m) {
        return i;
      }
      ++j;
    }
    return n;
  }
};
