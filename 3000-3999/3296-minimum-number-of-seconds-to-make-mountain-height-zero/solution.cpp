/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimum-number-of-seconds-to-make-mountain-height-zero/
 * Runtime: 47ms (50.97%)
 */

class Solution {
public:
  long long minNumberOfSeconds(const int mountainHeight, const vector<int>& workerTimes) {
    long long l = 0;
    long long r = 1e18;
    while (l < r) {
      const long long time = (l + r) >> 1;

      int cut = 0;
      for (int t : workerTimes) {
        int l2 = 1;
        int r2 = 1e6;
        while (l2 < r2) {
          const int mid = (l2 + r2) >> 1;
          if ((long long)t * mid * (mid + 1) / 2 <= time) {
            l2 = mid + 1;
          } else {
            r2 = mid;
          }
        }
        cut += l2 - 1;
        if (cut >= mountainHeight) {
          break;
        }
      }

      if (cut >= mountainHeight) {
        r = time;
      } else {
        l = time + 1;
      }
    }
    return r;
  }
};
