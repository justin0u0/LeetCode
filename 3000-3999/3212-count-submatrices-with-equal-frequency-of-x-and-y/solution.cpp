/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/count-submatrices-with-equal-frequency-of-x-and-y/
 * Runtime: 47ms (75.61%)
 */

class Solution {
public:
  int numberOfSubmatrices(vector<vector<char>>& grid) {
    const int m = grid.size();
    const int n = grid[0].size();

    vector<vector<int>> sum(m + 1, vector<int>(n + 1, 0));
    int res = 0;

    for (int i = 0; i < m; ++i) {
      for (int j = 0; j < n; ++j) {
        if (grid[i][j] == 'X') {
          sum[i + 1][j + 1] = sum[i + 1][j] + sum[i][j + 1] - sum[i][j] + 1;
        } else if (grid[i][j] == 'Y') {
          sum[i + 1][j + 1] = sum[i + 1][j] + sum[i][j + 1] - sum[i][j] - 1;
        } else {
          sum[i + 1][j + 1] = sum[i + 1][j] + sum[i][j + 1] - sum[i][j];
        }

        if (grid[i][j] == 'X' ||
          (i > 0 && grid[i - 1][j] == 1) ||
          (j > 0 && grid[i][j - 1] == 1)) {
          grid[i][j] = 1;
        }

        if (grid[i][j] == 1 && sum[i + 1][j + 1] == 0) {
          ++res;
        }
      }
    }

    return res;
  }
};
