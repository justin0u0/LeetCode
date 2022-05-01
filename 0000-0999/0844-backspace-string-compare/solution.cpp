/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/backspace-string-compare/
 * Runtime: 0ms
 */

class Solution {
private:
  int findNext(string& s, int i) {
    int skips = 0;
    for (i = i - 1; i >= 0 && (s[i] == '#' || skips != 0); --i) {
      if (s[i] == '#') {
        ++skips;
      } else {
        --skips;
      }
    }

    return i;
  }
public:
  bool backspaceCompare(string& s, string& t) {
    int i = (int)s.length();
    int j = (int)t.length();
    while (i >= 0 && j >= 0) {
      i = findNext(s, i);
      j = findNext(t, j);
      if (i >= 0 && j >= 0 && s[i] != t[j]) {
        return false;
      }
    }

    return (i < 0 && j < 0);
  }
};
