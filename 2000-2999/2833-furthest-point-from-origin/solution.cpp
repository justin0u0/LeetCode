/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/furthest-point-from-origin/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int furthestDistanceFromOrigin(const string& moves) {
    int dist = 0;
    int mov = 0;
    for (char c : moves) {
      if (c == 'L') {
        ++dist;
      } else if (c == 'R') {
        --dist;
      } else {
        ++mov;
      }
    }

    if (dist < 0) {
      return -dist + mov;
    }
    return dist + mov;
  }
};
