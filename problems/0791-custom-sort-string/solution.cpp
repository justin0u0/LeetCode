/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/custom-sort-string/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  string customSortString(const string& order, string& s) {
    int cnt[128] = {0};
    for (char c : s) {
      ++cnt[c];
    }
    auto it = s.begin();
    for (char c : order + "abcdefghijklmnopqrstuvwxyz") {
      while (cnt[c] != 0) {
        *it = c;
        ++it;
        --cnt[c];
      }
    }
    return s;
  }
};
