/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimize-xor/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int minimizeXor(int num1, int num2) {
    unsigned answer = num1;
    unsigned target = __builtin_popcount(num2);
    unsigned cur = __builtin_popcount(num1);

    unsigned mask = 1;
    while (target < cur) {
      while ((mask & answer) == 0) {
        mask <<= 1;
      }
      answer &= (~mask);
      --cur;
    }

    mask = 1;
    while (target > cur) {
      while ((mask & answer) != 0) {
        mask <<= 1;
      }
      answer |= mask;
      ++cur;
    }

    return answer;
  }
};

