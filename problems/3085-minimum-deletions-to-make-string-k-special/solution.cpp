/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimum-deletions-to-make-string-k-special/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int minimumDeletions(const string& word, const int k) {
    int count[128] = {0};
    for (char c : word) {
      ++count[c];
    }

    vector<int> freq;
    int total = 0;
    for (char c = 'a'; c <= 'z'; ++c) {
      if (count[c] != 0) {
        freq.emplace_back(count[c]);
        total += count[c];
      }
    }

    sort(freq.begin(), freq.end());
    const int m = freq.size();

    int del = INT_MAX;
    int d = 0;
    int r = 0;
    int l = 0;
    for (int i = 0; i < m; ++i) {
      while (r < m && freq[r] - freq[i] <= k) {
        total -= freq[r];
        ++r;
      }
      while (l < i && freq[l] < freq[i]) {
        d += freq[l];
        ++l;
      }
      del = min(del, d + total - (freq[i] + k) * (m - r));
    }
    return del;
  }
};
