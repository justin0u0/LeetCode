/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimum-speed-to-arrive-on-time/
 * Runtime: 280ms (89.93%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

#define INF 10000001

class Solution {
public:
  int minSpeedOnTime(const vector<int>& dist, const double hour) {
    int l = 1, r = INF;
    const int n = (int)dist.size() - 1;
    while (l < r) {
      const int mid = (l + r) >> 1;

      int total = 0;
      for (int i = 0; i < n; ++i) {
        total += (dist[i] - 1) / mid + 1;
      }
      if (total + (double)dist.back() / mid <= hour) {
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
