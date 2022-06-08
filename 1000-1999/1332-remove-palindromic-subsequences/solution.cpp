/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/remove-palindromic-subsequences/
 * Runtime: 0ms
 */

class Solution {
public:
  int removePalindromeSub(string s) {
    int n = (int)s.length();
    for (int i = 0; i < n / 2; ++i) {
      if (s[i] != s[n - i - 1]) {
        return 2;
      }
    }

    return 1;
  }
};
