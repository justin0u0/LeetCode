/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/smallest-number-with-all-set-bits/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int smallestNumber(int n) {
    for (int i = 1; ; ++i) {
      if ((1 << i) > n) {
        return (1 << i) - 1;
      }
    }
    return -1;
  }
};
