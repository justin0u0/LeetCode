/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/maximum-difference-between-even-and-odd-frequency-i/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int maxDifference(const string& s) {
    int cnt[128] = {0};
    for (char c : s) {
      ++cnt[c];
    }

    int mxo = 0;
    int mne = 100;
    for (char c = 'a'; c <= 'z'; ++c) {
      if (cnt[c] & 1) {
        mxo = max(mxo, cnt[c]);
      } else if (cnt[c] != 0) {
        mne = min(mne, cnt[c]);
      }
    }
    return mxo - mne;
  }
};
