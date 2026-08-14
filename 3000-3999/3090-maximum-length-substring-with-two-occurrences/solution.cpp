/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/maximum-length-substring-with-two-occurrences/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int maximumLengthSubstring(const string& s) {
    int cnt[128] = {0};

    int maxl = 0;
    int j = 0;
    for (int i = 0; i < s.length(); ++i) {
      ++cnt[s[i]];
      while (cnt[s[i]] > 2) {
        --cnt[s[j]];
        ++j;
      }
      maxl = max(maxl, i - j + 1);
    }
    return maxl;
  }
};
