/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/binary-number-with-alternating-bits/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  bool hasAlternatingBits(int n) {
    int last = -1;
    while (n != 0) {
      if ((n & 1) == last) {
        return false;
      }
      last = (n & 1);
      n >>= 1;
    }
    return true;
  }
};
