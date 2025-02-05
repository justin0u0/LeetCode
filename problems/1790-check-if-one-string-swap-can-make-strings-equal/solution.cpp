/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  bool areAlmostEqual(const string& s1, const string& s2) {
    const int n = s1.length();
    bool ok = true;
    int diff = 0;
    pair<char, char> p{0, 0};
    for (int i = 0; i < n; ++i) {
      if (s1[i] != s2[i]) {
        if (p == pair<char, char>{0, 0}) {
          p = {s1[i], s2[i]};
        } else if (p == pair<char, char>{s2[i], s1[i]}) {
          ok = true;
        } else {
          return false;
        }
        ++diff;
      }
    }
    return diff == 0 || (diff == 2 && ok);
  }
};
