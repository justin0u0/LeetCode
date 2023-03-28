/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimum-cost-for-tickets/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int mincostTickets(vector<int>& days, vector<int>& costs) {
    int maxDays = days.back();
    vector<int> dp(maxDays + 1, INT_MAX);
    dp[0] = 0;

    int j = 0;
    for (int i = 1; i <= maxDays; ++i) {
      if (days[j] != i) {
        dp[i] = dp[i - 1];
      } else {
        dp[i] = min(dp[i - 1] + costs[0], min(dp[max(0, i - 7)] + costs[1], dp[max(0, i - 30)] + costs[2]));
        ++j;
      }
    }
    return dp[maxDays];
  }
};
