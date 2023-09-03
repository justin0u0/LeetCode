/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/reverse-integer/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int reverse(int x) {
    if (x == INT_MIN) {
      return 0;
    }
    if (x < 0) {
      return -reverse(-x);
    }
    int res = 0;
    while (x != 0) {
      if (INT_MAX / 10 < res) {
        return 0;
      }
      res = res * 10;
      if (INT_MAX - x % 10 < res) {
        return 0;
      }
      res += x % 10;
      x /= 10;
    }
    return res;
  }
};
