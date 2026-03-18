/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/count-submatrices-with-top-left-element-and-sum-less-than-k/
 * Runtime: 4ms (98.88%)
 */

class Solution {
public:
  int countSubmatrices(const vector<vector<int>>& grid, const int k) {
    const int m = grid.size();
    const int n = grid[0].size();

    int count = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        int& sum = grid[i][j];
        if (i > 0) {
          sum += grid[i - 1][j];
        }
        if (j > 0) {
          sum += grid[i][j - 1];
        }
        if (i > 0 && j > 0) {
          sum -= grid[i - 1][j - 1];
        }
        if (sum <= k) {
          ++count;
        }
      }
    }

    return count;
  }
};
