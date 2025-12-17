/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-v/
 * Runtime: 37ms (91.56%)
 */

class Solution {
private:
  const int INF = 1e9 + 7;
public:
  long long maximumProfit(const vector<int>& prices, const int k) {
    /*
      dp(i, j, t) maximum profit at ith day and completes j transactions
      - t = 0: in transaction with a buy
          dp(i, j, 0) = max{dp(i - 1, j, 2) - prices[i], dp(i - 1, j, 0)}
      - t = 1: in transaction with a sell
          dp(i, j, 1) = max{dp(i - 1, j, 2) + prices[i], dp(i - 1, j, 1)}
      - t = 2: transaction end
          dp(i, j, 2) = max{
            dp(i - 1, j - 1, 0) + prices[i],
            dp(i - 1, j - 1, 1) - prices[i],
            dp(i - 1, j, 2)
          }
    */
    const int n = prices.size();

    vector<vector<long long>> dp(k + 1, vector<long long>(3, -INF));
    dp[0][2] = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = k; j >= 0; --j) {
        const int prev = dp[j][2];
        dp[j][0] = max(dp[j][0], dp[j][2] - prices[i]);
        dp[j][1] = max(dp[j][1], dp[j][2] + prices[i]);
        if (j > 0) {
          dp[j][2] = max(dp[j][2], max(
            dp[j - 1][0] + prices[i],
            dp[j - 1][1] - prices[i]
          ));
        }
      }
    }

    long long res = 0;
    for (int i = 0; i <= k; ++i) {
      res = max(res, dp[i][2]);
    }
    return res;
  }
};
