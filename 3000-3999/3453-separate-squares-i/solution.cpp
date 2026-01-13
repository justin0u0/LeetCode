/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/separate-squares-i/
 * Runtime: 112ms (51.16%)
 */

class Solution {
public:
  double separateSquares(const vector<vector<int>>& squares) {
    double l = 0;
    double r = 1e9 + 1;

    while (r - l > 9e-6) {
      double mid = (l + r) / 2.0;
      double area = 0; // above - below
      for (const auto& s : squares) {
        if (mid <= s[1]) {
          area += (double)s[2] * s[2];
        } else if (mid >= s[1] + s[2]) {
          area -= (double)s[2] * s[2];
        } else {
          area += (double)s[2] * ((s[1] + s[2] - mid) - (mid - s[1]));
        }
      }

      if (area < 1e-6) {
        r = mid;
      } else {
        l = mid;
      }
    }
    return r;
  }
};
