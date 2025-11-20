/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/set-intersection-size-at-least-two/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int intersectionSizeTwo(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(), [&](const auto& a, const auto& b) {
      if (a[1] == b[1]) {
        return a[0] > b[0];
      }
      return a[1] < b[1];
    });

    int count = 0;

    // start, end: last 2 points added
    int start = -1;
    int end = -1;
    for (const auto& interval : intervals) {
      const int left = interval[0];
      const int right = interval[1];
      if (left > end) {
        // contains 0 point for this interval, add the last 2 points in this interval
        count += 2;
        start = right - 1;
        end = right;
      } else if (left > start) {
        // contains 1 point (end) for this interval, add the last 1 point in this interval
        count += 1;
        start = end;
        end = right;
      }
    }
    return count;
  }
};
