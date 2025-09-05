/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimum-operations-to-make-the-integer-zero/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int makeTheIntegerZero(long long num1, long long num2) {
    for (int i = 1; ; ++i) {
      num1 -= num2;
      if (num1 < i) {
        return -1;
      }

      if (__builtin_popcountl(num1) <= i) {
        return i;
      }
    }
    return -1;
  }
};
