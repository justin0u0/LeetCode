/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/count-operations-to-obtain-zero/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int countOperations(int num1, int num2) {
    int ops = 0;
    while (num1 != 0 && num2 != 0) {
      if (num1 < num2) {
        swap(num1, num2);
      }
      ops += num1 / num2;
      num1 %= num2;
    }
    return ops;
  }
};
