/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/reorganize-string/
 * Runtime: 0ms (100.00%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  string reorganizeString(string& s) {
    int n = s.length();
    int cnt[26] = {0};
    int target = 0;
    for (const char c : s) {
      if (++cnt[c - 'a'] > cnt[target]) {
        target = c - 'a';
      }
    }
    if (cnt[target] > (n + 1) / 2) {
      return "";
    }
    int idx = 0;
    while (cnt[target] != 0) {
      s[idx] = target + 'a';
      idx += 2;
      --cnt[target];
    }
    for (int i = 0; i < 26; ++i) {
      while (cnt[i] != 0) {
        if (idx >= n) {
          idx = 1;
        }
        s[idx] = i + 'a';
        idx += 2;
        --cnt[i];
      }
    }
    return s;
  }
};
