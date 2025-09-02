/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/find-the-number-of-ways-to-place-people-i/
 * Runtime: 9ms (61.48%)
 */

class Solution {
public:
  int numberOfPairs(vector<vector<int>>& points) {
    const int n = points.size();
    int pairs = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (i == j || points[i][0] > points[j][0] || points[i][1] < points[j][1]) {
          continue;
        }
        bool ok = true;
        for (int k = 0; k < n; ++k) {
          if (i != k && j != k &&
            points[i][0] <= points[k][0] && points[k][0] <= points[j][0] &&
            points[i][1] >= points[k][1] && points[k][1] >= points[j][1]) {
            ok = false;
            break;
          }
        }
        if (ok) {
          ++pairs;
        }
      }
    }
    return pairs;
  }
};
