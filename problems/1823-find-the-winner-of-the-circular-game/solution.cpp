/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/find-the-winner-of-the-circular-game/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int findTheWinner(int n, int k) {
    int j = 0;
    for (int i = 1; i <= n; ++i) {
      j = (j + k) % i;
    }
    return j + 1;
  }
};
