/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/range-sum-query-2d-immutable/
 * Runtime: 497ms
 */

class NumMatrix {
private:
  vector<vector<int>> sum;
public:
  NumMatrix(vector<vector<int>>& matrix) {
    int n = (int)matrix.size();
    int m = (int)matrix[0].size();
    sum = vector<vector<int>>(n + 1, vector<int>(m + 1, 0));

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        sum[i + 1][j + 1] = sum[i + 1][j] + sum[i][j + 1] - sum[i][j] + matrix[i][j];
      }
    }
  }

  int sumRegion(int row1, int col1, int row2, int col2) {
    return sum[row2 + 1][col2 + 1] - sum[row1][col2 + 1] - sum[row2 + 1][col1] + sum[row1][col1];
  }
};
