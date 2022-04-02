/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/valid-palindrome-ii/
 * Runtime: 56ms
 */

class Solution {
private:
  bool check(string& s, int l, int r) {
    while (l < r) {
      if (s[l] != s[r]) {
        return false;
      }

      ++l;
      --r;
    }

    return true;
  }
public:
  bool validPalindrome(string& s) {
    int l = 0;
    int r = (int)s.length() - 1;

    while (l < r) {
      if (s[l] != s[r]) {
        return check(s, l + 1, r) || check(s, l, r - 1);
      }

      ++l;
      --r;
    }

    return true;
  }
};
