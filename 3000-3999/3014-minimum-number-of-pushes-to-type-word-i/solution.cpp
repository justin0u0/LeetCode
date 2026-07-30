/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-i/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int minimumPushes(const string& word) {
    int cnt[128] = {0};
    for (char c : word) {
      ++cnt[c];
    }
    sort(cnt + 'a', cnt + 'z' + 1, greater<int>());

    int pushes = 0;
    for (char c = 'a'; c <= 'z'; ++c) {
      pushes += cnt[c] * ((c - 'a') / 8 + 1);
    }
    return pushes;
  }
};
