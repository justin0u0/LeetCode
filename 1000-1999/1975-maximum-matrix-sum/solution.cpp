/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/maximum-matrix-sum/
 * Runtime: 0ms (100.00%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  long long maxMatrixSum(const vector<vector<int>>& matrix) {
    const int n = matrix.size();

    long long sum = 0;
    bool neg = 0;
    int mn = INT_MAX;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        const int x = abs(matrix[i][j]);
        mn = min(mn, x);
        sum += x;
        if (matrix[i][j] < 0) {
          neg ^= 1;
        }
      }
    }
    if (neg) {
      return sum - mn - mn;
    }
    return sum;
  }
};
