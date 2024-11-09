/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimum-array-end/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  long long minEnd(int n, int x) {
    // To make the bitwise AND result equals to `x`, numbers should have bits
    // set at the same position of `x`, and other bits do not matter.
    //
    // So the minimum possible value of nums[n - 1] is to filling the binary
    // of `n - 1` using only unset bits of `x`.
    //
    // For example 1, x = 4 = (100)b, then we fill `n - 1 = 2 = (10)b to all
    // unset bits, which becomes (110)b = 6.

    --n;

    long long res = x;
    for (long long mask = 1; n != 0; mask <<= 1) {
      if (res & mask) {
        continue;
      }
      if (n & 1) {
        res |= mask;
      }
      n >>= 1;
    }
    
    return res;
  }
};
