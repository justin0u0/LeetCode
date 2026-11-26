/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/stone-removal-game/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  bool canAliceWin(int n) {
    bool ans = false;
    for (int i = 10; i > 0; --i) {
      if (n < i) {
        return ans;
      }
      n -= i;
      ans ^= 1;
    }
    return ans;
  }
};
