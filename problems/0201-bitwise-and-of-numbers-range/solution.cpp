/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/bitwise-and-of-numbers-range/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int rangeBitwiseAnd(const int left, const int right) {
    unsigned int msb = 1;
    while (msb <= (right >> 1)) {
      msb <<= 1;
    }
    
    int answer = 0;
    while (msb != 0 && (msb & left) == (msb & right)) {
      answer |= (msb & left);
      msb >>= 1;
    }
    return answer;
  }
};
