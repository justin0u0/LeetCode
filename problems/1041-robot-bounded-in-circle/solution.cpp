/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/robot-bounded-in-circle/
 * Runtime: 0ms
 * Description:
 *  Calculate the displacement of each direction, if the robot runs in circle
 *  then after 4 rounds of instruction the X-direction displacement should be
 *  0 and the Y-direction displacement should also be equals 0 too.
 */

class Solution {
public:
  bool isRobotBounded(string instructions) {
    int total[4] = {0};

    int cur = 0;
    for (int i = 0; i < 4; ++i) {
      for (char inst : instructions) {
        switch (inst) {
          case 'L':
            cur = (cur + 1) % 4;
            break;
          case 'R':
            cur = (cur + 3) % 4;
            break;
          case 'G':
            ++total[cur];
            break;
        }
      }
    }

    return (total[0] == total[2] && total[1] == total[3]);
  }
};
