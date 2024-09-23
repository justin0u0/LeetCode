/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/teemo-attacking/
 * Runtime: 14ms (97.53%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  int findPoisonedDuration(const vector<int>& timeSeries, const int duration) {
    int total = duration;
    int prev = timeSeries[0];
    for (int t : timeSeries) {
      total += min(duration, t - prev);
      prev = t;
    }
    return total;
  }
};
