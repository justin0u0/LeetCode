/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/divide-intervals-into-minimum-number-of-groups/
 * Runtime: 176ms (99.77%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  int minGroups(vector<vector<int>>& intervals) {
    const int n = intervals.size();

    vector<pair<int, int>> points;
    points.reserve(n << 1);
    for (const auto& interval : intervals) {
      points.push_back({interval[0], -1});
      points.push_back({interval[1], 1});
    }
    sort(points.begin(), points.end());

    int count = 0;
    int groups = 0;
    for (const auto [_, x] : points) {
      count -= x;
      groups = max(groups, count);
    }
    return groups;
  }
};
