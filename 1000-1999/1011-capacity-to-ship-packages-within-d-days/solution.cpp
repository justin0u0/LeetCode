/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
 * Runtime: 42ms (95.21%)
 */

class Solution {
private:
  inline bool check(const vector<int>& weights, int cap, int days) {
    int d = 1;
    int sum = 0;
    for (const int& w : weights) {
      if (w > cap) {
        return false;
      }
      if (sum + w > cap) {
        if (d == days) {
          return false;
        }
        ++d;
        sum = w;
      } else {
        sum += w;
      }
    }

    return true;
  }
public:
  int shipWithinDays(const vector<int>& weights, int days) {
    int l = 0;
    int r = accumulate(weights.begin(), weights.end(), 0);
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (check(weights, mid, days)) {
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
    return r + 1;
  }
};
