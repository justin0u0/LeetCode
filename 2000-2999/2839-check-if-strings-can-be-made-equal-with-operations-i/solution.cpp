/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/check-if-strings-can-be-made-equal-with-operations-i/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  bool canBeEqual(string s1, string s2) {
    int cnt[2][26] = {0};
    for (int i = 0; i < s1.length(); ++i) {
      ++cnt[i & 1][s1[i] - 'a'];
      --cnt[i & 1][s2[i] - 'a'];
    }
    for (int i = 0; i < 26; ++i) {
      if (cnt[0][i] != 0 || cnt[1][i] != 0) {
        return false;
      }
    }
    return true;
  }
};
