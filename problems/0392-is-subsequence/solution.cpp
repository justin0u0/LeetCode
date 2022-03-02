/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/is-subsequence/
 * Runtime: 0ms
 */

class Solution {
public:
  bool isSubsequence(string s, string t) {
    int n = (int)s.length();

    int i = 0;
    for (const char& c : t) {
      if (i < n && s[i] == c) ++i;
    }

    return (i == n);
  }
};
