/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/first-unique-character-in-a-string/
 * Runtime: 18ms
 */

class Solution {
public:
  int firstUniqChar(string s) {
    int cnt[128] = {0};
    for (const char& c : s) {
      ++cnt[c];
    }
    for (int i = 0; i < s.length(); ++i) {
      if (cnt[s[i]] == 1) {
        return i;
      }
    }

    return -1;
  }
};
