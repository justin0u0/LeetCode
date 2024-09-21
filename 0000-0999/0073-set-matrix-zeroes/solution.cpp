/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/set-matrix-zeroes/
 * Runtime: 7ms (83.90%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  void setZeroes(vector<vector<int>>& matrix) {
    const int n = matrix.size();
    const int m = matrix[0].size();

    // First record if the first row/column should be set to zero.
    bool col0 = false;
    bool row0 = false;
    for (int i = 0; i < n; ++i) {
      if (matrix[i][0] == 0) {
        col0 = true;
      }
    }
    for (int i = 0; i < m; ++i) {
      if (matrix[0][i] == 0) {
        row0 = true;
      }
    }

    // Use the first row/column to record if the row/column should be set to zero.
    for (int i = 1; i < n; ++i) {
      for (int j = 1; j < m; ++j) {
        if (matrix[i][j] == 0) {
          matrix[i][0] = 0;
          matrix[0][j] = 0;
        }
      }
    }

    for (int i = 1; i < n; ++i) {
      if (matrix[i][0] == 0) {
        for (int j = 0; j < m; ++j) {
          matrix[i][j] = 0;
        }
      }
    }
    for (int i = 1; i < m; ++i) {
      if (matrix[0][i] == 0) {
        for (int j = 0; j < n; ++j) {
          matrix[j][i] = 0;
        }
      }
    }
    if (col0) {
      for (int i = 0; i < n; ++i) {
        matrix[i][0] = 0;
      }
    }
    if (row0) {
      for (int i = 0; i < m; ++i) {
        matrix[0][i] = 0;
      }
    }
  }
};
