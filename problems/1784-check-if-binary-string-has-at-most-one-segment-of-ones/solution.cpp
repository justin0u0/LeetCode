/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/check-if-binary-string-has-at-most-one-segment-of-ones/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  bool checkOnesSegment(const string& s) {
    for (int i = 0; i + 1 < s.length(); ++i) {
      if (s[i] == '0' && s[i] != s[i + 1]) {
        return false;
      }
    }
    return true;
  }
};
