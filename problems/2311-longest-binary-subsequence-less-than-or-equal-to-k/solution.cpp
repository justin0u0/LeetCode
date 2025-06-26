/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/longest-binary-subsequence-less-than-or-equal-to-k/
 * Runtime: 3ms (30.69%)
 */

class Solution {
public:
  int longestSubsequence(const string& s, int k) {
    const int n = s.length();

    string t = "";
    while (k != 0) {
      t.push_back((k & 1) + '0');
      k >>= 1;
    }
    reverse(t.begin(), t.end());
    const int m = t.length();

    int zeros = 0;
    int longest = min(m - 1, n);
    for (int i = 0; i < n; ++i) {
      int l = 0;
      for (int j = i; j < n; ++j) {
        if (s[j] < t[l]) {
          l += n - j;
          break;
        }
        if (s[j] == t[l]) {
          ++l;
        }
      }
      longest = max(longest, zeros + min(l, m));

      if (s[i] == '0') {
        ++zeros;
      }
    }
    return longest;
  }
};
