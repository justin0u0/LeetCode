/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimum-length-of-string-after-deleting-similar-ends/
 * Runtime: 11ms (99.66%)
 */

class Solution {
public:
  int minimumLength(const string& s) {
    int i = 0;
    int j = s.length() - 1;
    while (i < j && s[i] == s[j]) {
      char c = s[i];
      while (i <= j && s[i] == c) {
        ++i;
      }
      while (i <= j && s[j] == c) {
        --j;
      }
    }
    return j - i + 1;
  }
};
