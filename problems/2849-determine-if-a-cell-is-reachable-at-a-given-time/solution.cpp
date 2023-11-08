/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/determine-if-a-cell-is-reachable-at-a-given-time/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
    int minSteps = abs(sx - fx) + abs(sy - fy) - min(abs(sx - fx), abs(sy - fy));
    return minSteps == 0 ? (t != 1) : minSteps <= t;
  }
};
