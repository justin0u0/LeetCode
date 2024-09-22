/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/nim-game/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  bool canWinNim(int n) {
    return (n & 3) != 0;
  }
};
