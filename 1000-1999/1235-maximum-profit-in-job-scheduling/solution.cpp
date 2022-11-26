/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/maximum-profit-in-job-scheduling/
 * Runtime: 118ms (98.05%)
 */

class Solution {
public:
  int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
    int n = startTime.size();
    int m = (n << 1);

    vector<pair<int, int>> times;
    times.reserve(m);
    for (int i = 0; i < n; ++i) {
      times.emplace_back(pair{startTime[i], i + 1});
      times.emplace_back(pair{endTime[i], -i - 1});
    }

    sort(times.begin(), times.end());

    vector<int> dp(m + 1, 0);
    vector<int> mp(n + 1);
    for (int i = 0; i < m; ++i) {
      const int idx = times[i].second;

      if (idx > 0) {
        dp[i + 1] = dp[i];
        mp[idx] = i + 1;
      } else {
        dp[i + 1] = max(dp[i], dp[mp[-idx]] + profit[-idx - 1]);
      }
    }

    return dp[m];
  }
};
