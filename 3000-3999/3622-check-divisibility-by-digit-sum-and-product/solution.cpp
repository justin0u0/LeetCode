/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/check-divisibility-by-digit-sum-and-product/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  bool checkDivisibility(int n) {
    int sum = 0;
    int mul = 1;
    for (int x = n; x > 0; x /= 10) {
      sum += x % 10;
      mul *= x % 10;
    }
    return n % (sum + mul) == 0;
  }
};
