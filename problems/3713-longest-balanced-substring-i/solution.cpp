/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/longest-balanced-substring-i/
 * Runtime: 47ms (96.24%)
 */

class Solution {
public:
  int longestBalanced(const string& s) {
    int freq[1001];

    int longest = 0;
    for (int i = 0; i < s.length(); ++i) {
      int cnt[26] = {0};
      int dist = 0;
      memset(freq, 0, sizeof(freq));
      for (int j = i; j >= 0; --j) {
        const int c = ++cnt[s[j] - 'a'];
        if (c == 1) {
          ++dist;
        }
        ++freq[c];
        --freq[c - 1];
        if (freq[c] == dist) {
          longest = max(longest, i - j + 1);
        }
      }
    }
    return longest;
  }
};
