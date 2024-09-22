/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/valid-perfect-square/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  bool isPerfectSquare(int num) {
    unsigned l = 1;
    unsigned r = 50000;
    while (l < r) {
      const unsigned mid = (l + r) >> 1;
      const unsigned x = mid * mid;

      if (x == num) {
        return true;
      }
      if (x > num) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }
    return false;
  }
};
