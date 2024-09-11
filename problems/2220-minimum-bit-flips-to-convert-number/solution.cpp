/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimum-bit-flips-to-convert-number/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int minBitFlips(int start, int goal) {
    if (start > goal) {
      swap(start, goal);
    }

    unsigned b = 1;
    int flips = 0;
    for (unsigned b = 1; b <= goal; b <<= 1) {
      flips += !!((start & b) ^ (goal & b));
    }
    return flips;
  }
};
