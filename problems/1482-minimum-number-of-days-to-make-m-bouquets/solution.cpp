/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/
 * Runtime: 78ms (97.49%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  int minDays(vector<int>& bloomDay, int m, int k) {
    const int INF = 1e9 + 1;
    int l = 0;
    int r = INF;
    while (l < r) {
      int mid = (l + r) >> 1;

      int total = 0;
      int adj = 0;
      for (int day : bloomDay) {
        if (day <= mid) {
          ++adj;
        } else {
          total += adj / k;
          adj = 0;
        }
      }
      total += adj / k;

      if (total >= m) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }
    if (r == INF) {
      return -1;
    }
    return r;
  }
};
