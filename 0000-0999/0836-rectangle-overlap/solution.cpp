/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/rectangle-overlap/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  bool isRectangleOverlap(const vector<int>& rec1, const vector<int>& rec2) {
    // two intervals [a,b], [c,d] under x-axis is
    // - non overlap if:  (b<=c||d<=a)
    // - overlap:    if: !(b<=c||d<=a) -> (b>c&&d>a)

    return rec1[2] > rec2[0] && rec2[2] > rec1[0]
      && rec1[3] > rec2[1] && rec2[3] > rec1[1];
  }
};
