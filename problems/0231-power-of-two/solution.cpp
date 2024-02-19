/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/power-of-two/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  bool isPowerOfTwo(int n) {
    if (n <= 0) {
      return false;
    }
    return (n & (n - 1)) == 0;
  }
};
