/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/stone-game/
 * Runtime: 14ms (22.56%)
 */

class Solution {
public:
  bool stoneGame(vector<int>& piles) {
    // dp(i, j) maximum alice-bob stones
    //   max{
    //    dp(i+2,j)   + piles[i]-piles[i+1]
    //    dp(i+1,j-1) + abs(piles[i]-piles[j])
    //    dp(i,j-2)   + piles[j]-piles[j-1]
    //   }

    const auto n = piles.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = n - 1; i >= 0; --i) {
      for (int j = i + 1; j < n; ++j) {
        int best = 0;
        if (i + 2 < n) {
          best = max(best, dp[i + 2][j] + piles[i] - piles[i + 1]);
        }
        if (j - 2 >= 0) {
          best = max(best, dp[i][j - 2] + piles[j] - piles[j - 1]);
        }
        if (i + 1 < n && j - 1 >= 0) {
          best = max(best, dp[i + 1][j - 1] + abs(piles[i] - piles[j]));
        }
        dp[i][j] = best;
      }
    }
    return dp[0][n - 1] > 0;
  }
};
