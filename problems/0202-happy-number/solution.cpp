/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/happy-number/
 * Runtime: 0ms (100.00%)
 */

class Solution {
private:
  inline int next(int x) {
    int y = 0;
    while (x != 0) {
      y += (x % 10) * (x % 10);
      x /= 10;
    }
    return y;
  }
public:
  bool isHappy(int n) {
    int slow = n;
    int fast = n;
    do {
      slow = next(slow);
      fast = next(next(fast));
    } while (slow != fast);
    return slow == 1;
  }
};
