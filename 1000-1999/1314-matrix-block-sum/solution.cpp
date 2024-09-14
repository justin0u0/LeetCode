/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/matrix-block-sum/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
    const int n = mat.size();
    const int m = mat[0].size();
    vector<vector<int>> sum(n + 1, vector<int>(m + 1, 0));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        sum[i + 1][j + 1] = sum[i + 1][j] + sum[i][j + 1] - sum[i][j] + mat[i][j];
      }
    }

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        mat[i][j] = sum[min(i + k + 1, n)][min(j + k + 1, m)]
          - sum[max(i - k, 0)][min(j + k + 1, m)]
          - sum[min(i + k + 1, n)][max(j - k, 0)]
          + sum[max(i - k, 0)][max(j - k, 0)];
      }
    }
    return mat;
  }
};
