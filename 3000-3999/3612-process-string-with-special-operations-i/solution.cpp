/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/process-string-with-special-operations-i/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  string processStr(const string& s) {
    string res;
    for (char c : s) {
      if (c == '*') {
        if (!res.empty()) {
          res.pop_back();
        }
      } else if (c == '#') {
        res += res;
      } else if (c == '%') {
        ranges::reverse(res);
      } else {
        res += c;
      }
    }
    return res;
  }
};
