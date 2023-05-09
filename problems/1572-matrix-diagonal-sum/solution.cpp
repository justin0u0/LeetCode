/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/matrix-diagonal-sum/
 * Runtime: 8ms (97.16%)
 */

const static auto _ = []() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  return nullptr;
}();

class Solution {
public:
  int diagonalSum(vector<vector<int>>& mat) {
    int n = mat.size();
    int sum = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        if (i - j == 0 || i + j == n - 1) {
          sum += mat[i][j];
        }
      }
    }
    return sum;
  }
};
