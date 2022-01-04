/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/complement-of-base-10-integer/
 * Runtime: 0ms
 */

class Solution {
public:
  int bitwiseComplement(int n) {
    if (!n) return 1;

    int m = n;

    int mask = 0;
    while (m) {
      mask = (mask << 1) | 1;
      m >>= 1;
    }
    
    return n ^ mask;
  }
};

