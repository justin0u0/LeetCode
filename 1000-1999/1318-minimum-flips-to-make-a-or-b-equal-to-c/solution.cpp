/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int minFlips(int a, int b, int c) {
    int flips = 0;
    for (unsigned int i = 1; i <= (1 << 30); i <<= 1) {
      int x = a & i;
      int y = b & i;
      int z = c & i;

      if ((x | y) != z) {
        ++flips;
        if (z == 0 && x != 0 && y != 0) {
          ++flips;
        }
      }
    }
    return flips;
  }
};
