/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/maximum-number-of-points-with-cost/
 * Runtime: 117ms (99.73%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  long long maxPoints(vector<vector<int>>& points) {
    const int n = points.size();
    const int m = points[0].size();

    vector<long long> pre(m, 0);
    vector<long long> cur(m);
    for (int i = 0; i < n; ++i) {
      long long best = 1;
      for (int j = 0; j < m; ++j) {
        best = max(best - 1, pre[j]);
        cur[j] = best + points[i][j];
      }

      best = 1;
      for (int j = m - 1; j >= 0; --j) {
        best = max(best - 1, pre[j]);
        cur[j] = max(cur[j], best + points[i][j]);
      }

      swap(pre, cur);
    }

    return *max_element(pre.begin(), pre.end());
  }
};
