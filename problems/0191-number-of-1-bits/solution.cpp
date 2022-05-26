/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/number-of-1-bits/
 * Runtime: 0ms
 */

class Solution {
public:
  int hammingWeight(uint32_t n) {
    return __builtin_popcount(n);
  }
};
