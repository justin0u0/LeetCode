/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/maximum-number-of-non-overlapping-palindrome-substrings/
 * Runtime: 205ms (36.91%)
 */

class Solution {
public:
  int maxPalindromes(const string& s, const int k) {
    const int n = s.length();

    // pal[i][j]: true if s[i:j] is palindrome, false otherwise
    vector<vector<bool>> pal(n + 1, vector<bool>(n, false));

    for (int i = n - 1; i >= 0; --i) {
      pal[i][i] = true;
      pal[i + 1][i] = true;
      for (int j = i + 1; j < n; ++j) {
        pal[i][j] = pal[i + 1][j - 1] && s[i] == s[j];
      }
    }

    // dp[i]: maximum number of substrings for s[0:i) ends with a palindrome
    vector<int> dp(n + 1, 0);
    dp[0] = 0;

    for (int i = 0; i < n; ++i) {
      dp[i + 1] = dp[i];
      for (int j = i - k + 1; j >= 0; --j) {
        if (pal[j][i]) {
          dp[i + 1] = max(dp[i + 1], dp[j] + 1);
        }
      }
    }

    return dp[n];
  }
};
