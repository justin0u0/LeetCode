/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/delete-operation-for-two-strings/
 * Runtime: 37ms
 */

class Solution {
public:
  int minDistance(string word1, string word2) {
    int n = (int)word1.length();
    int m = (int)word2.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    for (int i = 0; i <= n; ++i) {
      dp[i][0] = i;
    }
    for (int j = 0; j <= m; ++j) {
      dp[0][j] = j;
    }
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        if (word1[i - 1] == word2[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1];
        } else {
          dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
        }
      }
    }

    return dp[n][m];
  }
};
