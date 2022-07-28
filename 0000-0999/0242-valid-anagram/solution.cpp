/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/valid-anagram/
 * Runtime: 8ms
 */

class Solution {
public:
  bool isAnagram(string s, string t) {
    int cnt[26] = {0};
    for (const char& c : s) {
      ++cnt[c - 'a'];
    }
    for (const char& c : t) {
      --cnt[c - 'a'];
    }

    for (int i = 0; i < 26; ++i) {
      if (cnt[i] != 0) {
        return false;
      }
    }

    return true;
  }
};
