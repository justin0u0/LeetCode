/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/coin-change-ii/
 * Runtime: 0ms (100.00%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
private:
  int dp[5001];
public:
  int change(int amount, vector<int>& coins) {
    dp[0] = 1;
    for (const int c : coins) {
      for (int i = c; i <= amount; ++i) {
        dp[i] += dp[i - c];
      }
    }
    return dp[amount];
  }
};
