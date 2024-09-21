/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/longest-common-prefix/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  string longestCommonPrefix(const vector<string>& strs) {
    size_t len = INT_MAX;
    for (const auto& s : strs) {
      len = min(len, s.length());
    }

    string res = "";
    for (int i = 0; i < len; ++i) {
      for (const auto& s : strs) {
        if (s[i] != strs[0][i]) {
          return res;
        }
      }
      res += strs[0][i];
    }
    return res;
  }
};
