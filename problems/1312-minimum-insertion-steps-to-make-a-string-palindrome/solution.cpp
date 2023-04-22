/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/
 * Runtime: 28ms (96.44%)
 */

class Solution {
public:
  int minInsertions(const string& s) {
    // dp(i,j): minimum steps to make s[i:j] palindrome
    //  dp(i,j) = dp(i+1,j-1) if s[i] == s[j]
    //    [mbadm -> bad]
    //  dp(i,j) = min{dp(i+1,j), dp(i,j-1)} if s[i] != s[j]
    //    [bad -> badb -> ad] or [bad -> dbad -> ba]
    //
    // We can reduce 2D array with:
    //   cur(j) = dp(i,j)
    //   pre(j) = dp(i+1,j)
    int n = s.size();
    vector<int> cur(n + 1);
    vector<int> pre(n + 1);
    for (int i = n - 1; i >= 0; --i) {
      cur[i] = 0;
      pre[i] = 0;
      for (int j = i + 1; j < n; ++j) {
        if (s[i] == s[j]) {
          cur[j] = pre[j - 1];
        } else {
          cur[j] = min(pre[j], cur[j - 1]) + 1;
        }
      }
      swap(cur, pre);
    }
    return pre[n - 1];
  }
};

