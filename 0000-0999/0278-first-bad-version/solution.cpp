/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/first-bad-version/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int firstBadVersion(int n) {
    int l = 1;
    int r = n;
    while (l <= r) {
      int mid = l + ((r - l) >> 1);
      if (isBadVersion(mid)) {
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
    return r + 1;
  }
};
