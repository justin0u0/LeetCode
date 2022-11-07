/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/maximum-69-number/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int maximum69Number(int num) {
    for (int base = 1e3; base > 0; base /= 10) {
      if ((num / base) % 10 == 6) {
        num += 3 * base;
        return num;
      }
    }

    return num;
  }
};
