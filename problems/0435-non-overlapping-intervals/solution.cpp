/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/non-overlapping-intervals/
 * Runtime: 425ms (95.06%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(), [](const auto& lhs, const auto& rhs) {
      return lhs[1] < rhs[1];
    });
    int count = 0;
    int last = INT_MIN;
    for (const auto& interval : intervals) {
      if (interval[0] < last) {
        ++count;
      } else {
        last = interval[1];
      }
    }
    return count;
  }
};
