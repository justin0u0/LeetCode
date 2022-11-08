/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/make-the-string-great/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  string makeGood(string& s) {
    int l = 0;
    for (const char& c : s) {
      if (l != 0 && abs(c - s[l - 1]) == 32) {
        --l;
      } else {
        s[l++] = c;
      }
    }

    return s.substr(0, l);
  }
};
