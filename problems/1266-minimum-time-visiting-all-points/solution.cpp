/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimum-time-visiting-all-points/
 * Runtime: 6ms (68.54%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  int minTimeToVisitAllPoints(const vector<vector<int>>& points) {
    int answer = 0;
    for (int i = 1; i < points.size(); ++i) {
      const int dx = abs(points[i][0] - points[i - 1][0]);
      const int dy = abs(points[i][1] - points[i - 1][1]);
      answer += dx + dy - min(dx, dy);
    }
    return answer;
  }
};
