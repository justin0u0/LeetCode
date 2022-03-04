/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/champagne-tower/
 * Runtime: 20ms
 */

class Solution {
public:
  double champagneTower(int poured, int query_row, int query_glass) {
    vector<vector<double>> dp(query_row + 1, vector<double>(100, 0));

    dp[0][0] = poured;
    for (int i = 0; i <= query_row; ++i) {
      for (int j = 0; j <= i; ++j) {
        double& sum = dp[i][j];
        if (j && dp[i - 1][j - 1] >= 1) {
          sum += (dp[i - 1][j - 1] - 1) / 2.0;
        }
        if (j != i && dp[i - 1][j] >= 1) {
          sum += (dp[i - 1][j] - 1) / 2.0;
        }
      }
    }

    if (dp[query_row][query_glass] >= 1.0) {
      return 1.0;
    }

    return dp[query_row][query_glass];
  }
};
