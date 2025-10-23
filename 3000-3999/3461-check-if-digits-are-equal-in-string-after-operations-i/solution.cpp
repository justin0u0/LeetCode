/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/check-if-digits-are-equal-in-string-after-operations-i/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  bool hasSameDigits(string s) {
    for (char c : s) {
      c -= '0';
    }
    for (int i = s.length() - 1; i >= 2; --i) {
      for (int j = 0; j < i; ++j) {
        s[j] = (s[j] + s[j + 1]) % 10; 
      }
    }
    return s[0] == s[1];
  }
};
