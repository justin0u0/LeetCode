/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/redistribute-characters-to-make-all-strings-equal/
 * Runtime: 7ms (95.72%)
 */

class Solution {
public:
  bool makeEqual(vector<string>& words) {
    int cnt[26] = {0};
    for (auto& word : words) {
      for (char c : word) {
        ++cnt[c - 'a'];
      }
    }
    const int n = words.size();
    for (int i = 0; i < 26; ++i) {
      if (cnt[i] % n != 0) {
        return false;
      }
    }
    return true;
  }
};
