/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/increment-submatrices-by-one/
 * Runtime: 39ms (51.71%)
 */

class Solution {
public:
  vector<vector<int>> rangeAddQueries(const int n, const vector<vector<int>>& queries) {
    vector<vector<int>> mat(n, vector<int>(n, 0));
    for (const auto& q : queries) {
      for (int i = q[0]; i <= q[2]; ++i) {
        ++mat[i][q[1]];
        if (q[3] + 1 < n) {
          --mat[i][q[3] + 1];
        }
      }
    }
    for (int i = 0; i < n; ++i) {
      int sum = 0;
      for (int j = 0; j < n; ++j) {
        sum += mat[i][j];
        mat[i][j] = sum;
      }
    }
    return mat;
  }
};
