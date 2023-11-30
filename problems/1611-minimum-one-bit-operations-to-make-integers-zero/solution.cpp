/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimum-one-bit-operations-to-make-integers-zero/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int minimumOneBitOperations(int n) {
    unsigned mask = 1;
    while (mask < n) {
      mask <<= 1;
    }

    int answer = 0;
    while (n != 0) {
      while ((mask & n) == 0) {
        mask >>= 1;
      }
      // unset the left most bit then reverse the second left most bit
      n = n & (mask - 1) ^ (mask >> 1);
      answer += mask;
    }
    return answer;
  }
};

// 0000 -> 0001 -> 0011 -> 0010 -> 0110 -> 0111 -> 0101 -> 0100 -> 1100 -> 1101 -> 1111 -> 1110 -> 1010 -> 1011 -> 1001 -> 1000
//  0       1       2       3       4       5       6       7       8       9       10      11      12      13      14      15
//  0       1       3       2       6       7       5       4       10      11      15      14      12      13      9       8
