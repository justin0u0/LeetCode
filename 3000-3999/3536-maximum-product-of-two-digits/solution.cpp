/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/maximum-product-of-two-digits/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int maxProduct(int n) {
    int m1 = 0;
    int m2 = 0;
    while (n > 0) {
      const auto d = n % 10;
      if (d > m1) {
        m2 = m1;
        m1 = d;
      } else if (d > m2) {
        m2 = d;
      }
      n /= 10;
    }
    return m1 * m2;
  }
};
