/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/divide-two-integers/
 * Runtime: 0ms
 */

class Solution {
public:
  int divide(int dividend, int divisor) {
    long long ans = dividend / (1.0 * divisor);
    if (ans > INT_MAX) {
      return INT_MAX;
    }
    if (ans < INT_MIN) {
      return INT_MIN;
    }

    return ans;
  }
};

