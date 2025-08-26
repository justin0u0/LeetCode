/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/maximum-area-of-longest-diagonal-rectangle/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
    int maxd = 0;
    int area = 0;
    for (const auto& dim : dimensions) {
      const int d = dim[0] * dim[0] + dim[1] * dim[1];
      if (d > maxd) {
        maxd = d;
        area = dim[0] * dim[1];
      } else if (d == maxd) {
        area = max(area, dim[0] * dim[1]);
      }
    }
    return area;
  }
};
