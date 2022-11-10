/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/
 * Runtime: 20ms (90.52%)
 */

class Solution {
public:
  string removeDuplicates(string& s) {
    int l = 0;
    for (const char& c : s) {
      if (l > 0 && s[l - 1] == c) {
        --l;
      } else {
        s[l++] = c;
      }
    }

    return s.substr(0, l);
  }
};
