/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/delete-columns-to-make-sorted-ii/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int minDeletionSize(const vector<string>& strs) {
    const int n = strs.size();
    const int m = strs[0].size();

    int dels = 0;
    vector<bool> less(n, false);
    for (int i = 0; i < m; ++i) {
      bool del = false;
      for (int j = 1; j < n; ++j) {
        if (!less[j] && strs[j - 1][i] > strs[j][i]) {
          del = true;
        }
      }
      if (!del) {
        for (int j = 1; j < n; ++j) {
          if (strs[j - 1][i] < strs[j][i]) {
            less[j] = true;
          }
        }
      }
      dels += del;
    }
    return dels;
  }
};
