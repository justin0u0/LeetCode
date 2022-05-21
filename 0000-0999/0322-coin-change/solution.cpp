/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/coin-change/
 * Runtime: 74ms
 */

class Solution {
private:
  const int INF = 0x3f3f3f3f;
public:
  int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, INF);
    dp[0] = 0;

    for (const int& coin : coins) {
      for (int i = coin; i <= amount; ++i) {
        dp[i] = min(dp[i], dp[i - coin] + 1);
      }
    }

    if (dp[amount] == INF) {
      return -1;
    }

    return dp[amount];
  }
};
