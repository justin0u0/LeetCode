/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/divisible-and-non-divisible-sums-difference/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int differenceOfSums(int n, int m) {
    int res = 0;
    for (int i = 1; i <= n; ++i) {
      if (i % m == 0) {
        res -= i;
      } else {
        res += i;
      }
    }
    return res;
  }
};
