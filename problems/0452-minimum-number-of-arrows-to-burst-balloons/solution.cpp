/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/
 * Runtime: 452ms
 * Time Complexity: O(NlogN)
 * Description: Greedy
 */

class Solution {
private:
  static bool comparator(const vector<int>& a, const vector<int>& b) {
    return (a[1] < b[1]);
  }
public:
  int findMinArrowShots(vector<vector<int>>& points) {
    sort(points.begin(), points.end(), Solution::comparator);

    int shoots = 1;
    int maxX = points[0][1];
    for (vector<int>& point : points) {
      if (point[0] > maxX) {
        ++shoots;
        maxX = point[1];
      }
    }

    return shoots;
  }
};
