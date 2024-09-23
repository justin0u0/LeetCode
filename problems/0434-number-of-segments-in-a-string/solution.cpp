/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/number-of-segments-in-a-string/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int countSegments(const string& s) {
    bool gotc = false;
    int segs = 0;
    for (char c : s) {
      if (c != ' ') {
        gotc = true;
      } else if (gotc) {
        ++segs;
        gotc = false;
      }
    }
    return segs + gotc;
  }
};
