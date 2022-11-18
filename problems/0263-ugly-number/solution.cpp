/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/ugly-number/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  bool isUgly(int n) {
    if (n <= 0) {
      return false;
    }

    while (n % 3 == 0) {
      n /= 3;
    }
    while (n % 5 == 0) {
      n /= 5;
    }

    return (n & (n - 1)) == 0;
  }
};
