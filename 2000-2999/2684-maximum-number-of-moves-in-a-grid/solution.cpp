/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/maximum-number-of-moves-in-a-grid/
 * Runtime: 8ms (86.96%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  int maxMoves(vector<vector<int>>& grid) {
    const int rows = grid.size();
    const int cols = grid[0].size();
    vector<vector<bool>> ok(rows, vector<bool>(cols, 0));
    for (int i = 1; i < cols; ++i) {
      bool ok = false;

      if (grid[0][i] > min(grid[0][i - 1], grid[1][i - 1])) {
        ok = true;
      } else {
        grid[0][i] = INT_MAX;
      }
      if (grid[rows - 1][i] > min(grid[rows - 1][i - 1], grid[rows - 2][i - 1])) {
        ok = true;
      } else {
        grid[rows - 1][i] = INT_MAX;
      }

      for (int j = 1; j < rows - 1; ++j) {
        if (grid[j][i] > min(min(grid[j - 1][i - 1], grid[j][i - 1]), grid[j + 1][i - 1])) {
          ok = true;
        } else {
          grid[j][i] = INT_MAX;
        }
      }
      if (!ok) {
        return i - 1;
      }
    }
    return cols - 1;
  }
};
