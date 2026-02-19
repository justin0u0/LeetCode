/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/count-binary-substrings/
 * Runtime: 1ms (75.38%)
 */

class Solution {
public:
  int countBinarySubstrings(const string& s) {
    int last = 0;
    int count = 1;
    int res = 0;
    for (int i = 1; i < s.length(); ++i) {
      if (s[i] != s[i - 1]) {
        res += min(last, count);
        last = count;
        count = 1;
      } else {
        ++count;
      }
    }
    return res + min(last, count);
  }
};
