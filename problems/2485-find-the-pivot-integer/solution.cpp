/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/find-the-pivot-integer/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int pivotInteger(int n) {
    int l = 1;
    int r = n;
    while (l <= r) {
      int mid = (l + r) >> 1;
      int ls = ((1 + mid) * mid) >> 1;
      int rs = ((mid + n) * (n - mid + 1)) >> 1;
      if (ls == rs) {
        return mid;
      }
      if (ls < rs) {
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    return -1;
  }
};
