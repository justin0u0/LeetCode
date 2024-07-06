/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/pass-the-pillow/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int passThePillow(int n, int time) {
    if ((time / (n - 1)) & 1) {
      // n, n-1, ..., 2
      return n - time % (n - 1);
    }

    // 1, 2, ..., n-1
    return time % (n - 1) + 1;
  }
};
