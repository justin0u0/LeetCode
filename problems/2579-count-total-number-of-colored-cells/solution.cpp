/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/count-total-number-of-colored-cells/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  long long coloredCells(long long n) {
    return 1 + ((n * (n - 1)) << 1);
  }
};
