/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended-ii/
 * Runtime: 394ms (18.48%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  int maxValue(vector<vector<int>>& events, int k) {
    sort(events.begin(), events.end(), [](const auto& lhs, const auto& rhs) {
      return (lhs[1] < rhs[1]) || (lhs[1] == rhs[1] && lhs[0] < rhs[0]);
    });

    vector<int> times;
    times.reserve(events.size() * 2 + 1);
    for (const auto& e : events) {
      times.emplace_back(e[0]);
      times.emplace_back(e[1]);
    }
    sort(times.begin(), times.end());
    times.resize(unique(times.begin(), times.end()) - times.begin());
    for (auto& e : events) {
      int e0 = e[0], e1 = e[1];
      e[0] = lower_bound(times.begin(), times.end(), e[0]) - times.begin() + 1;
      e[1] = lower_bound(times.begin(), times.end(), e[1]) - times.begin() + 1;
    }

    int n = times.size() + 1;
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));

    int j = 0;
    int m = events.size();
    for (int i = 1; i <= n; ++i) {
      dp[i] = dp[i - 1];
      
      for (; j < m; ++j) {
        auto& e = events[j];
        if (e[1] > i) {
          break;
        }

        for (int l = 1; l <= k; ++l) {
          int& d = dp[e[1]][l];
          d = max(d, dp[e[0] - 1][l - 1] + e[2]);
        }
      }
    }

    return *max_element(dp[n].begin(), dp[n].end());
  }
};
