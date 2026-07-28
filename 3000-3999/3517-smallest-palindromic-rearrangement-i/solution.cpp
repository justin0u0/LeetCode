/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/smallest-palindromic-rearrangement-i/
 * Runtime: 4ms (100.00%)
 */

class Solution {
public:
  string smallestPalindrome(string& s) {
    const auto n = s.length();

    int cnt[128] = {0};
    for (char c : s) {
      ++cnt[c];
    }

    int i = 0;
    char left = 0;
    for (char c = 'a'; c <= 'z'; ++c) {
      while (cnt[c] > 1) {
        s[i++] = c;
        s[n - i] = c;
        cnt[c] -= 2;
      }
      if (cnt[c] > 0) {
        left = c;
      }
    }
    if (left > 0) {
      s[i] = left;
    }
    return s;
  }
};
