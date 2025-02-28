/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimum-number-of-coins-for-fruits/
 * Runtime: 4ms (75.83%)
 */

class Solution {
public:
  int minimumCoins(const vector<int>& prices) {
    const int n = prices.size();
    if (n <= 2) {
      return prices[0];
    }

    // dp(i): minimum coins to buy prices[0] ~ prices[i] and pay for prices[i]
    //  = min(dp(j)) + prices[i] where (j + 1) * 2 >= i

    deque<pair<int, int>> dq{{2, prices[0]}}; // [j, dp[i]], increasing dp[i]

    int result = INT_MAX;
    for (int i = 1; i < n; ++i) {
      while (dq.front().first < i) {
        dq.pop_front();
      }

      int dp = dq.front().second + prices[i];
      while (!dq.empty() && dq.back().second > dp) {
        dq.pop_back();
      }

      const int j = (i + 1) << 1;
      dq.push_back({j, dp});

      if (j >= n) {
        result = min(result, dp);
      }
    }

    return result;
  }
};
