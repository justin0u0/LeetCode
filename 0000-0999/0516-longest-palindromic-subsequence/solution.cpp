/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/longest-palindromic-subsequence/
 * Runtime: 64ms (96.18%)
 */

class Solution {
public:
  int longestPalindromeSubseq(const string& s) {
    int n = s.size();
    vector<int> pre(n); // dp[i + 1][?]
    vector<int> cur(n); // dp[i][?]
    for (int i = n - 1; i >= 0; --i) {
      cur[i] = 1;

      for (int j = i + 1; j < n; ++j) {
        if (s[i] == s[j]) {
          cur[j] = pre[j - 1] + 2;
        } else {
          cur[j] = max(cur[j - 1], pre[j]);
        }
      }
      swap(pre, cur);
    }
    return pre[n - 1];
  }
};
