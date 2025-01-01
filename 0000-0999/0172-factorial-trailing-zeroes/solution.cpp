/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/factorial-trailing-zeroes/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int trailingZeroes(int n) {
    int zeros = 0;
    int x = 5;
    while (x <= n) {
      zeros += n / x;
      x *= 5;
    }
    return zeros;
  }
};
