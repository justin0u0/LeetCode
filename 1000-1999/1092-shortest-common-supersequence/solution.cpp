/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/shortest-common-supersequence/
 * Runtime: 18ms (96.44%)
 */

class Solution {
private:
  int dp[1001][1001];
public:
  string shortestCommonSupersequence(const string& str1, const string& str2) {
    const int n = str1.length();
    const int m = str2.length();

    for (int i = 0; i < n; ++i) {
      dp[i][0] = i;
    }
    for (int i = 0; i < m; ++i) {
      dp[0][i] = i;
    }

    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        if (str1[i - 1] == str2[j - 1]) {
          dp[i][j] = dp[i - 1][j - 1];
        } else {
          dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
        }
      }
    }

    string s = "";
    int i = n - 1;
    int j = m - 1;
    while (i >= 0 || j >= 0) {
      if (i < 0) {
        s += str2[j];
        --j;
      } else if (j < 0) {
        s += str1[i];
        --i;
      } else if (str1[i] == str2[j]) {
        s += str1[i];
        --i;
        --j;
      } else if (dp[i][j + 1] < dp[i + 1][j + 1]) {
        s += str1[i];
        --i;
      } else {
        s += str2[j];
        --j;
      }
    }
    reverse(s.begin(), s.end());
    return s;
  }
};
