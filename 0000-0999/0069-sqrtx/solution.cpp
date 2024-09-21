/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/sqrtx/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int mySqrt(int x) {
    unsigned l = 0;
    unsigned r = 1 << 16;
    while (l < r) {
      unsigned mid = (l + r) >> 1;
      if (mid * mid <= x) {
        l = mid + 1;
      } else {
        r = mid;
      }
    }
    return l - 1;
  }
};
