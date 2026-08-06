/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/smallest-divisible-digit-product-i/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int smallestNumber(int n, int t) {
    for (int i = n; ; ++i) {
      int mul = 1;
      for (int x = i; x > 0; x /= 10) {
        mul *= x % 10;
        if (mul % t == 0) {
          return i;
        }
      }
    }
    return 0;
  }
};
