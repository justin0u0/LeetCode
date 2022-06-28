/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/
 * Runtime: 45ms
 */

class Solution {
public:
  int minDeletions(string s) {
    int cnt[26] = {0};
    for (const char c : s) {
      ++cnt[c - 'a'];
    }

    sort(cnt, cnt + 26, greater<int>());

    int freq = cnt[0];
    int sum = 0;
    for (int i = 0; i < 26; ++i) {
      if (cnt[i] > freq) {
        sum += cnt[i] - freq;
      } else {
        freq = cnt[i];
      }

      if (freq != 0) {
        --freq;
      }
    }

    return sum;
  }
};
