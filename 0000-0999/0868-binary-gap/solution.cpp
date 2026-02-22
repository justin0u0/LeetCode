/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/binary-gap/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int binaryGap(int n) {
    int last = INT_MAX;
    int gap = 0;
    for (int i = 0; n != 0; ++i) {
      if (n & 1) {
        gap = max(gap, i - last);
        last = i;
      }
      n >>= 1;
    }
    return gap;
  }
};
