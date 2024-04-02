/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/isomorphic-strings/
 * Runtime: 4ms (78.16%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  bool isIsomorphic(const string& s, const string& t) {
    int s2t[128] = {0};
    int t2s[128] = {0};
    for (int i = 0; i < s.length(); ++i) {
      if (s2t[s[i]] != 0 && s2t[s[i]] != t[i]) {
        return false;
      }
      if (t2s[t[i]] != 0 && t2s[t[i]] != s[i]) {
        return false;
      }
      s2t[s[i]] = t[i];
      t2s[t[i]] = s[i];
    }
    return true;
  }
};
