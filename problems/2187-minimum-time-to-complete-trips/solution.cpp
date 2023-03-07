/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimum-time-to-complete-trips/
 * Runtime: 244ms (96.44%)
 */

class Solution {
public:
  long long minimumTime(vector<int>& time, int totalTrips) {
    long long l = 1;
    long long r = 1e15;
    while (l < r) {
      long long mid = (l + r) >> 1;
      long long total = 0;
      for (const int& t : time) {
        total += mid / t;
        if (total >= totalTrips) {
          break;
        }
      }
      if (total >= totalTrips) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }
    return r;
  }
};
