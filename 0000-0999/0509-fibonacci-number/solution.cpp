/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/fibonacci-number/
 * Runtime: 0ms
 */

class Solution {
public:
  int fib(int n) {
    if (n <= 1) {
      return n;
    }

    int x = 0, y = 1;
    for (int i = 2; i <= n; ++i) {
      int next = x + y;
      x = y;
      y = next;
    }

    return y;
  }
};
