/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimum-score-triangulation-of-polygon/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int minScoreTriangulation(const vector<int>& values) {
    const int n = values.size();
    vector<vector<int>> dp(n, vector<int>(n + 1, INT_MAX));

    for (int i = n - 1; i >= 0; --i) {
      dp[i][i] = 0;
      dp[i][i + 1] = 0;
      for (int j = i + 1; j < n; ++j) {
        for (int k = i + 1; k < j; ++k) {
          dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + values[i] * values[j] * values[k]);
        }
      }
    }
    return dp[0][n - 1];
  }
};
