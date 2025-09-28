/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/largest-triangle-area/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  double largestTriangleArea(const vector<vector<int>>& points) {
    const int n = points.size();

    int maxArea = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        for (int k = j + 1; k < n; ++k) {
          const int area = (abs(
            points[i][0] * points[j][1] +
            points[j][0] * points[k][1] +
            points[k][0] * points[i][1] -
            points[i][1] * points[j][0] -
            points[j][1] * points[k][0] -
            points[k][1] * points[i][0]
          ));
          maxArea = max(maxArea, area);
        }
      }
    }
    return maxArea / 2.0;
  }
};
