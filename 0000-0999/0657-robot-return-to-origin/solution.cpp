/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/robot-return-to-origin/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  bool judgeCircle(const string& moves) {
    int x = 0;
    int y = 0;
    for (char m : moves) {
      if (m == 'U') {
        ++x;
      } else if (m == 'D') {
        --x;
      } else if (m == 'L') {
        ++y;
      } else if (m == 'R') {
        --y;
      }
    }
    return x == 0 && y == 0;
  }
};
