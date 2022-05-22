/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/palindromic-substrings/
 * Runtime: 18ms
 */

class Solution {
public:
  int countSubstrings(string& s) {
    int n = (int)s.length();
    vector<vector<bool>> dp(n + 1, vector<bool>(n, false));

    int answer = n;
    for (int i = n - 1; i >= 0; --i) {
      dp[i][i] = true;
      dp[i + 1][i] = true;

      for (int j = i + 1; j < n; ++j) {
        if (s[i] == s[j] && dp[i + 1][j - 1]) {
          dp[i][j] = true;
          ++answer;
        }
      }
    }

    return answer;
  }
};
