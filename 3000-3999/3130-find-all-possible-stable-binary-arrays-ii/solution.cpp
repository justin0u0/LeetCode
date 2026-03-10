/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/find-all-possible-stable-binary-arrays-ii/
 * Runtime: 455ms (47.94%)
 */

class Solution {
private:
  const int mod = 1e9 + 7;

  int dp[1002][1002][2];
  int row[1002][1002];
  int col[1002][1002];
public:
  int numberOfStableArrays(int zero, int one, int limit) {
    // dp[i][j][0]
    //  = sum{dp[i][k][1]}, j - k <= limit
    // dp[i][j][1]
    //  = sum{dp[k][j][0]}, i - k <= limit

    memset(dp, 0, sizeof(dp));
    memset(row, 0, sizeof(row));
    memset(col, 0, sizeof(col));
    dp[1][1][0] = 1;
    dp[1][1][1] = 1;
    row[1][1] = 1;
    col[1][1] = 1;

    for (int i = 1; i <= zero + 1; ++i) {
      for (int j = 1; j <= one + 1; ++j) {
        if (i == 1 && j == 1) {
          continue;
        }
        dp[i][j][0] = (row[i][j - 1] - row[i][max(0, j - 1 - limit)] + mod) % mod;
        dp[i][j][1] = (col[j][i - 1] - col[j][max(0, i - 1 - limit)] + mod) % mod;
        row[i][j] = (row[i][j - 1] + dp[i][j][1]) % mod;
        col[j][i] = (col[j][i - 1] + dp[i][j][0]) % mod;
      }
    }

    return (dp[zero + 1][one + 1][0] + dp[zero + 1][one + 1][1]) % mod;
  }
};
