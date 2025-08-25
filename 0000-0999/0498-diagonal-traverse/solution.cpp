/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/diagonal-traverse/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
    const int m = mat.size();
    const int n = mat[0].size();
    vector<int> res;
    res.reserve(m * n);
    for (int i = 0; i < m + n; ++i) {
      int lo;
      int hi;
      if (i & 1) {
        lo = max(0, i - n + 1);
        hi = min(i, m - 1);
      } else {
        lo = max(0, i - m + 1);
        hi = min(i, n - 1);
      }
      for (int j = lo; j <= hi; ++j) {
        if (i & 1) {
          res.emplace_back(mat[j][i - j]);
        } else {
          res.emplace_back(mat[i - j][j]);
        }
      }
    }
    return res;
  }
};
