/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/difference-between-ones-and-zeros-in-row-and-column/
 * Runtime: 178ms (92.18%)
 */

const static auto _ = []() {
  cin.tie(nullptr)->sync_with_stdio(false);
  return nullptr;
}();

class Solution {
public:
  vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
    const int n = grid.size();
    const int m = grid[0].size();
    vector<int> rows(n, 0);
    vector<int> cols(m, 0);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (grid[i][j] == 1) {
          ++rows[i];
          ++cols[j];
        }
      }
    }
    const int x = n + m;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        grid[i][j] = (rows[i] << 1) + (cols[j] << 1) - x;
      }
    }
    return grid;
  }
};
