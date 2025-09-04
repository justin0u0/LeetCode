/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/find-closest-person/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int findClosest(int x, int y, int z) {
    const int d1 = abs(x - z);
    const int d2 = abs(y - z);
    if (d1 == d2) {
      return 0;
    }
    if (d1 < d2) {
      return 1;
    }
    return 2;
  }
};
