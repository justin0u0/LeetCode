/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/count-the-number-of-special-characters-ii/
 * Runtime: 66ms (77.25%)
 */

class Solution {
public:
  int numberOfSpecialChars(const string& word) {
    vector<bool> vis(128, false);
    vector<bool> ok(128, true);
    for (char c : word) {
      vis[c] = true;
      if (c >= 'a' && c <= 'z' && vis[c ^ 32]) {
        ok[c] = false;
      }
    }

    int count = 0;
    for (int c = 0; c < 26; ++c) {
      if (vis[c + 'a'] && vis[c + 'A'] && ok[c + 'a']) {
        ++count;
      }
    }
    return count;
  }
};
