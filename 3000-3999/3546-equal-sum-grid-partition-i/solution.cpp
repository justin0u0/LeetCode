/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/equal-sum-grid-partition-i/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  bool canPartitionGrid(const vector<vector<int>>& grid) {
    const int m = grid.size();
    const int n = grid[0].size();

    long long total = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        total += grid[i][j];
      }
    }

    long long row = 0;
    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        row += grid[i][j];
      }
      if (row + row == total) {
        return true;
      }
    }

    long long col = 0;
    for (int j = 0; j < n; ++j) {
      for (int i = 0; i < m; ++i) {
        col += grid[i][j];
      }
      if (col + col == total) {
        return true;
      }
    }

    return false;
  }
};
