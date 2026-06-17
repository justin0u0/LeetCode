/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/process-string-with-special-operations-ii/
 * Runtime: 18ms (95.40%)
 */

class Solution {
public:
  char processStr(string& s, long long k) {
    long long len = 0;
    int j = 0;
    for (int i = 0; i < s.length(); ++i) {
      const char c = s[i];
      if (c == '*') {
        len = max(0LL, len - 1);
      } else if (c == '#') {
        len <<= 1;
      } else if (c != '%') {
        ++len;
      }
      if (c != '*' || len > 0) {
        s[j++] = c;
      }
    }
    s.resize(j);

    if (k >= len) {
      return '.';
    }

    for (const char c : s | views::reverse) {
      if (c == '*') {
        ++len;
      } else if (c == '#') {
        len >>= 1;
        if (k >= len) {
          k -= len;
        }
      } else if (c == '%') {
        k = len - k - 1;
      } else {
        --len;
        if (len == k) {
          return c;
        }
      }
    }
    return '.';
  }
};
