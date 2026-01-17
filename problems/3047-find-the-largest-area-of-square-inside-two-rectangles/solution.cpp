/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/find-the-largest-area-of-square-inside-two-rectangles/
 * Runtime: 70ms (85.12%)
 */

class Solution {
public:
  long long largestSquareArea(const vector<vector<int>>& bottomLeft, const vector<vector<int>>& topRight) {
    const int n = bottomLeft.size();
    long long area = 0;
    for (int i = 0; i < n; ++i) {
      const int x1 = bottomLeft[i][0];
      const int y1 = bottomLeft[i][1];
      const int x2 = topRight[i][0];
      const int y2 = topRight[i][1];
      for (int j = i + 1; j < n; ++j) {
        const int overlapX = min(x2, topRight[j][0]) - max(x1, bottomLeft[j][0]);
        const int overlapY = min(y2, topRight[j][1]) - max(y1, bottomLeft[j][1]);
        if (overlapX > 0 && overlapY > 0) {
          const long long len = min(overlapX, overlapY);
          area = max(area, len * len);
        }
      }
    }
    return area;
  }
};
