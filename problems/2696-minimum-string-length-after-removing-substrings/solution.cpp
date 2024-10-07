/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimum-string-length-after-removing-substrings/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int minLength(string& s) {
    int i = -1;
    for (char c : s) {
      if (i != -1 && ((c == 'B' && s[i] == 'A') || (c == 'D' && s[i] == 'C'))) {
        --i;
      } else {
        s[++i] = c;
      }
    }
    return i + 1;
  }
};
