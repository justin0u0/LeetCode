/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/construct-the-minimum-bitwise-array-ii/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  vector<int> minBitwiseArray(vector<int>& nums) {
    // Except 2, all primes are odd numbers. So the last bit is always 1.
    // The minimize number `x` for `x OR (x + 1) == num` is to unset the
    // leftmost bit in the contiguous trailing `1`s.

    for (int& num : nums) {
      if (num == 2) {
        num = -1;
      } else {
        int mask = 1;
        while ((mask & num) != 0) {
          mask <<= 1;
        }
        mask >>= 1;
        num &= ~mask;
      }
    }
    return nums;
  }
};
