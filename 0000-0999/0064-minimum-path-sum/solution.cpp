/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/minimum-path-sum/
 * Runtime: 7ms (90.29%)
 */

class Solution {
public:
  int minPathSum(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    for (int i = 1; i < n; ++i) {
      grid[i][0] += grid[i - 1][0];
    }
    for (int i = 1; i < m; ++i) {
      grid[0][i] += grid[0][i - 1];
    }
    for (int i = 1; i < n; ++i) {
      for (int j = 1; j < m; ++j) {
        grid[i][j] += min(grid[i - 1][j], grid[i][j - 1]);
      }
    }
    return grid[n - 1][m - 1];
  }
};
