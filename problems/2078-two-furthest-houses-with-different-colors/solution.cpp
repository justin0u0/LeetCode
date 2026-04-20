/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/two-furthest-houses-with-different-colors/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int maxDistance(const vector<int>& colors) {
    int j = 0;
    int dist = 0;
    for (int i = 0; i < colors.size(); ++i) {
      if (j == 0 && colors[i] != colors[0]) {
        j = i;
      }
      if (colors[i] != colors[0]) {
        dist = i;
      } else if (j > 0) {
        dist = max(dist, i - j);
      }
    }
    return dist;
  }
};
