/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/out-of-boundary-paths/
 * Runtime: 9ms
 * Time Complexity: O(NMK). Where N, M is the grid size and K is the maximum moves.
 * Description:
 *  dp(k, i, j) is the number of paths to move from the starting position to the (i, j) using exactly k steps.
 */

class Solution {
private:
  int dp[52][52][52];
  const int mod = 1e9 + 7;
public:
  int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
    dp[0][startRow + 1][startColumn + 1] = 1;
    for (int k = 0; k < maxMove; ++k) {
      for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
          int cur = dp[k][i][j];
          dp[k + 1][i - 1][j] = (dp[k + 1][i - 1][j] + cur) % mod;
          dp[k + 1][i + 1][j] = (dp[k + 1][i + 1][j] + cur) % mod;
          dp[k + 1][i][j - 1] = (dp[k + 1][i][j - 1] + cur) % mod;
          dp[k + 1][i][j + 1] = (dp[k + 1][i][j + 1] + cur) % mod;
        }
      }
    }

    int answer = 0;
    for (int k = 1; k <= maxMove; ++k) {
      for (int i = 1; i <= m; ++i) {
        answer = (answer + (dp[k][i][0] + dp[k][i][n + 1]) % mod) % mod;
      }
      for (int j = 1; j <= n; ++j) {
        answer = (answer + (dp[k][0][j] + dp[k][m + 1][j]) % mod) % mod;
      }
    }
    return answer;
  }
};
