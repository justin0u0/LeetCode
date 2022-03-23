/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/broken-calculator/
 * Runtime: 0ms
 */

class Solution {
public:
  int brokenCalc(int startValue, int target) {
    int count = 0;
    while (target > startValue) {
      if (target & 1) {
        ++target;
      } else {
        target >>= 1;
      }
      ++count;
    }

    return count + (startValue - target);
  }
};

