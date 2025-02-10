/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/clear-digits/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  string clearDigits(string& s) {
    int j = 0;
    for (int i = 0; i < s.length(); ++i) {
      if (s[i] >= 'a' && s[i] <= 'z') {
        s[j++] = s[i];
      } else {
        --j;
      }
    }
    return s.substr(0, j);
  }
};
