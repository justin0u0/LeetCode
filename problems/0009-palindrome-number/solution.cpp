/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/palindrome-number/
 * Runtime: 3ms (93.45%)
 */


class Solution {
public:
  bool isPalindrome(int x) {
    if (x < 0) {
      return false;
    }

    int base = 1;
    while (base <= min(x / 10, (int)1e9 - 1)) {
      base *= 10;
    }

    for (int i = 1; i < base; i *= 10) {
      if ((x / i) % 10 != (x / base) % 10) {
        return false;
      }
      base /= 10;
    }
    return true;
  }
};
