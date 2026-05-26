/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/count-the-number-of-special-characters-i/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int numberOfSpecialChars(const string& word) {
    vector<bool> vis(128, false);
    for (char c : word) {
      vis[c] = true;
    }
    int count = 0;
    for (char c = 0; c <= 26; ++c) {
      if (vis[c + 'a'] && vis[c + 'A']) {
        ++count;
      }
    }
    return count;
  }
};
