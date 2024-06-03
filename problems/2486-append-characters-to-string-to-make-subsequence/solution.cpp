/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/append-characters-to-string-to-make-subsequence/
 * Runtime: 11ms (95.86%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  int appendCharacters(const string& s, const string& t) {
    int i;
    int j = 0;
    for (i = 0; i < t.length(); ++i) {
      while (j < s.length() && s[j] != t[i]) {
        ++j;
      }
      if (j == s.length()) {
        break;
      }
      ++j;
    }
    return t.length() - i;
  }
};
