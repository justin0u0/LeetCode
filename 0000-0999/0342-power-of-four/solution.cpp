/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/power-of-four/
 * Runtime: 0ms
 */

class Solution {
public:
  bool isPowerOfFour(int n) {
    return (n > 0) && ((n&(n-1)) == 0) && ((n&0x55555555) != 0);
  }
};
