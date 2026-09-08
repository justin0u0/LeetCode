/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/count-commas-in-range/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int countCommas(const int n) {
    return max(0, n - 999);
  }
};
