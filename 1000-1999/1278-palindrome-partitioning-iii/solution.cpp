/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/palindrome-partitioning-iii/
 * Runtime: 8ms (91.15%)
 * Time Complexity: O(N^2 * K)
 * Description:
 *  We can separate this problem into 2 steps:
 *  1. We want to know what is the minimum changes needed to make s[i:j] a palindrome,
 *     for each 0 <= i, j < n.
 *     We can solve this using an O(N^2) dp:
 *      Let dp(i, j) be the minimum changes needed to make s[i:j] a palindrome.
 *      Then, dp(i, j) = dp(i+1, j-1) + 1 if s[i] != s[j]
 *      else, dp(i, j) = dp(i+1, j-1).
 *  2. We want to know what is the minimum changes to make s[0:i] k palindromes.
 *    We can solve this using an O(K * N^2) dp:
 *      Let dp2(i, x) be the minimum changes needed to make s[0:i] x palindromes.
 *      Then, dp2(i, x) = dp2(j, x - 1) + dp(j + 1, i) for each 0 <= j < i.
 *      That is, the minimum changes to make s[0:i] x palindromes can be calculated
 *      by the minimum changes needed to make s[0:j] x-1 palindromes PLUS the minimum
 *      changes needed to make s[j+1][i] a palindrome.
 */

class Solution {
private:
  const int INF = 0x3f3f3f3f;
public:
  int palindromePartition(const string& s, int k) {
    int n = s.size();
    vector<vector<int>> dp(n + 1, vector<int>(n, INF));
    for (int i = n - 1; i >= 0; --i) {
      dp[i][i] = 0;
      dp[i + 1][i] = 0;
      for (int j = i + 1; j < n; ++j) {
        if (s[i] == s[j]) {
          dp[i][j] = dp[i + 1][j - 1];
        } else {
          dp[i][j] = dp[i + 1][j - 1] + 1;
        }
      }
    }

    vector<vector<int>> dp2(n, vector<int>(k, INF));
    dp2[0][0] = 0;
    for (int i = 1; i < n; ++i) {
      dp2[i][0] = dp[0][i];
      for (int x = 1; x < k; ++x) {
        int& d = dp2[i][x];
        for (int j = 0; j < i; ++j) {
          d = min(d, dp2[j][x - 1] + dp[j + 1][i]);
        }
      }
    }

    return dp2[n - 1][k - 1];
  }
};
