/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/ones-and-zeroes/
 * Runtime: 227ms
 */

class Solution {
public:
  int findMaxForm(vector<string>& strs, int m, int n) {
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -0x3f3f3f3f));
    dp[0][0] = 0;

    for (const string& s : strs) {
      int x = 0;
      int y = 0;
      for (const char& c : s) {
        if (c == '0') {
          ++x;
        } else {
          ++y;
        }
      }

      for (int i = m; i >= x; --i) {
        for (int j = n; j >= y; --j) {
          dp[i][j] = max(dp[i][j], dp[i - x][j - y] + 1);
        }
      }
    }

    int answer = 0;
    for (int i = 0; i <= m; ++i) {
      for (int j = 0; j <= n; ++j) {
        answer = max(answer, dp[i][j]);
      }
    }

    return answer;
  }
};
