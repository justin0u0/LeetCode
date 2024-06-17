/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/sum-of-square-numbers/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  bool judgeSquareSum(unsigned int c) {
    for (unsigned int x = 0; x * x <= c; ++x) {
      unsigned int y = sqrt(c - x * x);
      if (x * x + y * y == c) {
        return true;
      }
    }
    return false;
  }
};
