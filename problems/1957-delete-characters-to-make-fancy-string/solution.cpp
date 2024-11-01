/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/delete-characters-to-make-fancy-string/
 * Runtime: 8ms (98.70%)
 */

class Solution {
public:
  string makeFancyString(string& s) {
    int j = 0;
    for (int i = 0; i < s.length(); ++i) {
      if (j >= 2 && s[i] == s[j - 1] && s[i] == s[j - 2]) {
        continue;
      }
      s[j++] = s[i];
    }

    s.resize(j);
    return s;
  }
};
