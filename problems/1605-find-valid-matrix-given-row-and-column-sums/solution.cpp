/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/find-valid-matrix-given-row-and-column-sums/
 * Runtime: 34ms (78.10%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
    const int n = rowSum.size();
    const int m = colSum.size();

    vector<vector<int>> mat(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        const int s = min(rowSum[i], colSum[j]);
        mat[i][j] = s;
        rowSum[i] -= s;
        colSum[j] -= s;
      }
    }
    return mat;
  }
};
