/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/stone-game-iv/
 * Runtime: 37ms
 * Description:
 *  dp(n) is true if Alice(starts first) win.
 *
 *  So ∀ j * j <= i, if dp(i - j * j) are all true, represents that
 *  Alice is guarantee to lose.
 *
 *  So dp(i) = false if ∀ j * j <= i, dp(i - j * j) = true,
 *  else dp(i) = true.
 */
class Solution {
public:
  bool winnerSquareGame(int n) {
    vector<bool> dp(n + 1);
    dp[0] = false;

    for (int i = 1; i <= n; ++i) {
      dp[i] = false;

      for (int j = 1; j * j <= i; ++j) {
        if (!dp[i - j * j]) {
          dp[i] = true;
          break;
        }
      }
    }

    return dp[n];
  }
};
