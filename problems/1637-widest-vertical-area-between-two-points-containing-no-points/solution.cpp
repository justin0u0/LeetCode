/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/widest-vertical-area-between-two-points-containing-no-points/
 * Runtime: 173ms (93.39%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  int maxWidthOfVerticalArea(vector<vector<int>>& points) {
    sort(points.begin(), points.end(), [](const auto& lhs, const auto& rhs) {
      return lhs[0] < rhs[0];
    });
    int answer = 0;
    for (int i = 1; i < points.size(); ++i) {
      answer = max(answer, points[i][0] - points[i - 1][0]);
    }
    return answer;
  }
};
