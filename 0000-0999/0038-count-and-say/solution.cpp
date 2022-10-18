/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/count-and-say/
 * Runtime: 17ms
 */

class Solution {
public:
  string countAndSay(int n) {
    string s = "1";
    if (n == 1) {
      return s;
    }

    for (int i = 1; i < n; ++i) {
      int m = s.length();
      int count = 1;
      string next;
      for (int j = 1; j < m; ++j) {
        if (s[j] == s[j - 1]) {
          ++count;
        } else {
          next.append(to_string(count));
          next.append(to_string(s[j - 1] - '0'));
          count = 1;
        }
      }

      next.append(to_string(count));
      next.append(to_string(s.back() - '0'));
      s = next;
    }

    return s;
  }
};
