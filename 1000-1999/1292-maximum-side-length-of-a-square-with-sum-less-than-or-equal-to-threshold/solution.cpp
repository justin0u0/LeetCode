/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/maximum-side-length-of-a-square-with-sum-less-than-or-equal-to-threshold/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int maxSideLength(const vector<vector<int>>& mat, const int threshold) {
    const int n = mat.size();
    const int m = mat[0].size();

    int res = 0;
    vector<vector<int>> sum(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        sum[i + 1][j + 1] = sum[i + 1][j] + sum[i][j + 1] - sum[i][j] + mat[i][j];
        
        for (int k = res; k <= min(i, j); ++k) {
          if (sum[i + 1][j + 1] - sum[i + 1][j - k] - sum[i - k][j + 1] + sum[i - k][j - k] <= threshold) {
            res = max(res, k + 1);
          } else {
            break;
          }
        }
      }
    }
    return res;
  }
};
