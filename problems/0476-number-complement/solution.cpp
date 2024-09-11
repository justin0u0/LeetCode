/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/number-complement/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int findComplement(int num) {
    unsigned mask = ~0;
    while (mask & num) {
      mask <<= 1;
    }
    return ~mask ^ num;
  }
};
