/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/power-of-three/
 * Runtime: 24ms
 */

class Solution {
public:
  bool isPowerOfThree(int n) {
    return (n > 0) && (1162261467 % n == 0);
  }
};

