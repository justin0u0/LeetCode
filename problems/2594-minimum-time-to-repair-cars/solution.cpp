/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimum-time-to-repair-cars/
 * Runtime: 16ms (90.77%)
 */

class Solution {
public:
  long long repairCars(vector<int>& ranks, int cars) {
    long long l = 0;
    long long r = 1e14 + 1;
    while (l < r) {
      long long mid = (l + r) >> 1;

      int c = 0;
      for (const int r : ranks) {
        c += (int)sqrt(mid / r);
        if (c >= cars) {
          break;
        }
      }
      if (c >= cars) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }
    return r;
  }
};
