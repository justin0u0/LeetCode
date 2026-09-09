/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/count-commas-in-range-ii/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  long long countCommas(const long long n) {
    return max(0LL, n - 999)
      + max(0LL, n - 999'999)
      + max(0LL, n - 999'999'999)
      + max(0LL, n - 999'999'999'999LL)
      + max(0LL, n - 999'999'999'999'999LL);
  }
};
