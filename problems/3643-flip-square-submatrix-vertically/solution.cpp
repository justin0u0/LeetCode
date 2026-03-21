/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/flip-square-submatrix-vertically/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
    for (int i = x; i < x + k / 2; ++i) {
      for (int j = y; j < y + k; ++j) {
        swap(grid[i][j], grid[x + k - (i - x) - 1][j]);
      }
    }
    return grid;
  }
};
