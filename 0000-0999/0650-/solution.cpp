/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/2-keys-keyboard/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int minSteps(int n) {
    int base = 1;
    int x = 1;
    int steps = 0;
    while (x != n) {
      if (n % x == 0) {
        ++steps;
        base = x;
      }
      x += base;
      ++steps;
    }
    return steps;
  }
};
