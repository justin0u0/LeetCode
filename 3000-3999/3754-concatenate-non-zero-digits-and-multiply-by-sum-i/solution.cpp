/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/concatenate-non-zero-digits-and-multiply-by-sum-i/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  long long sumAndMultiply(const int n) {
    int sum = 0;
    int num = 0;
    for (int base = 1e9; base > 0; base /= 10) {
      const auto d = n / base % 10;
      if (d != 0) {
        num = num * 10 + d;
        sum += d;
      }
    }
    return (long long)num * sum;
  }
};
