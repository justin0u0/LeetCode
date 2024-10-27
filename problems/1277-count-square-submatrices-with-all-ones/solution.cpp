/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/count-square-submatrices-with-all-ones/
 * Runtime: 4ms (69.14%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
private:
  int sum[305][305];
public:
  int countSquares(vector<vector<int>>& matrix) {
    const int n = matrix.size();
    const int m = matrix[0].size();
    sum[0][0] = 0;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        sum[i + 1][j + 1] = sum[i + 1][j] + sum[i][j + 1] - sum[i][j] + matrix[i][j];
      }
    }

    int answer = 0;
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        for (int k = 1; k <= min(i, j); ++k) {
          if (sum[i][j] - sum[i][j - k] - sum[i - k][j] + sum[i - k][j - k] == k * k) {
            ++answer;
          } else {
            break;
          }
        }
      }
    }
    return answer;
  }
};
