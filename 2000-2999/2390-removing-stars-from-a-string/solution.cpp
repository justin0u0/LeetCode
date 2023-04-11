/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/removing-stars-from-a-string/
 * Runtime: 75ms (90.85%)
 */

class Solution {
public:
  string removeStars(string &s) {
    int j = 0;
    for (int i = 0; i < s.length(); ++i) {
      if (s[i] == '*') {
        --j;
      } else {
        s[j] = s[i];
        ++j;
      }
    }
    s.resize(j);
    return s;
  }
};
