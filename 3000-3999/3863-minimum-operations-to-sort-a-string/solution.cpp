/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimum-operations-to-sort-a-string/
 * Runtime: 14ms (61.95%)
 */

class Solution {
public:
  int minOperations(const string& s) {
    char minCh = 'z';
    char maxCh = 'a';
    char prev = 0;
    bool sorted = true;
    int cnt[128] = {0};
    for (char c : s) {
      if (prev > c) {
        sorted = false;
      }
      prev = c;
      minCh = min(minCh, c);
      maxCh = max(maxCh, c);
      ++cnt[c];
    }

    if (sorted) {
      return 0;
    }
    if (s.length() <= 2) {
      return -1;
    }
    if (s[0] == minCh || s.back() == maxCh) {
      return 1;
    }
    if (s[0] == maxCh && s.back() == minCh && cnt[maxCh] == 1 && cnt[minCh] == 1) {
      return 3;
    }
    return 2;
  }
};
