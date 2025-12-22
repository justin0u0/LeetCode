/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/delete-columns-to-make-sorted-iii/
 * Runtime: 4ms (57.44%)
 */

class Solution {
public:
  int minDeletionSize(const vector<string>& strs) {
    const int n = strs.size();
    const int m = strs[0].size();
    vector<int> dp(m, 1);
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < i; ++j) {
        bool ok = true;
        for (int k = 0; k < n; ++k) {
          if (strs[k][j] > strs[k][i]) {
            ok = false;
            break;
          }
        }
        if (ok) {
          dp[i] = max(dp[i], dp[j] + 1);
        }
      }
    }

    int res = INT_MAX;
    for (int i = 0; i < m; ++i) {
      res = min(res, m - dp[i]);
    }
    return res;
  }
};
