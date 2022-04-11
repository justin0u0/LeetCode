/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/shift-2d-grid/
 * Runtime: 12ms
 */

class Solution {
public:
  vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
    int n = (int)grid.size();
    int m = (int)grid[0].size();
    vector<vector<int>> answer(n, vector<int>(m));

    int x = ((n * m - k % (n * m)) % (n * m)) / m;
    int y = ((n * m - k % (n * m)) % (n * m)) % m;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        answer[i][j] = grid[x][y];
        if (y == m - 1) {
          y = 0;
          if (x == n - 1) {
            x = 0;
          } else {
            ++x;
          }
        } else {
          ++y;
        }
      }
    }

    return answer;
  }
};
