/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/merge-intervals/
 * Runtime: 16ms (92.41%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
private:
  const static int maxN = 10000;

  int sweepline[maxN + 1];
  bool point[maxN + 1];
public:
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    memset(sweepline, 0, sizeof(sweepline));
    memset(point, false, sizeof(point));
    for (const auto& x : intervals) {
      ++sweepline[x[0]];
      --sweepline[x[1]];
      point[x[0]] = true;
      point[x[1]] = true;
    }

    intervals.clear();
    int start = -1;
    int sum = 0;
    for (int i = 0; i <= maxN; ++i) {
      sum += sweepline[i];
      if (sum > 0 && start == -1) {
        start = i;
      } else if (sum == 0 && start != -1) {
        intervals.push_back({start, i});
        start = -1;
      } else if (sum == 0 && point[i]) {
        intervals.push_back({i, i});
      }
    }
    return intervals;
  }
};
