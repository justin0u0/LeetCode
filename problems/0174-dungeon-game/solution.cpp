/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/dungeon-game/
 * Runtime: 4ms (93.52%)
 */

class Solution {
public:
  int calculateMinimumHP(vector<vector<int>>& dungeon) {
    int n = dungeon.size();
    int m = dungeon[0].size();

    // the least HP needed
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0x3f3f3f3f));
    dp[n][m - 1] = 1;
    for (int i = n - 1; i >= 0; --i) {
      for (int j = m - 1; j >= 0; --j) {
        dp[i][j] = max(min(dp[i][j + 1], dp[i + 1][j]) - dungeon[i][j], 1);
      }
    }
    return dp[0][0];
  }
};
