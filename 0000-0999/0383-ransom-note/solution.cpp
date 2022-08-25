/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/ransom-note/
 * Runtime: 11ms
 */

class Solution {
public:
  bool canConstruct(string& ransomNote, string& magazine) {
    int cnt[128] = {0};
    for (const char& c : magazine) {
      ++cnt[c];
    }
    for (const char& c : ransomNote) {
      --cnt[c];
      if (cnt[c] < 0) {
        return false;
      }
    }

    return true;
  }
};
