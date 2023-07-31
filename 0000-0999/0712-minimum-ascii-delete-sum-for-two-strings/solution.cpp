/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/
 * Runtime: 18ms (95.31%)
 * Time Complexity: O(N^2)
 * Space Complexity: O(N^2)
 */

class Solution {
private:
  int dp[1002][1002];
public:
  int minimumDeleteSum(const string& s1, const string& s2) {
    int n = s1.length();
    int m = s2.length();
    dp[0][0] = 0;
    for (int i = 0; i < n; ++i) {
      dp[i + 1][0] = dp[i][0] + s1[i];
    }
    for (int j = 0; j < m; ++j) {
      dp[0][j + 1] = dp[0][j] + s2[j];
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (s1[i] == s2[j]) {
          dp[i + 1][j + 1] = dp[i][j];
        } else {
          dp[i + 1][j + 1] = min(dp[i][j + 1] + s1[i], dp[i + 1][j] + s2[j]);
        }
      }
    }
    return dp[n][m];
  }
};
