/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/score-after-flipping-matrix/
 * Runtime: 0ms (100.00%)
 */

class Solution {
public:
  int matrixScore(vector<vector<int>>& grid) {
    const int n = grid.size();
    const int m = grid[0].size();
    for (int i = 0; i < n; ++i) {
      if (grid[i][0] == 0) {
        for (int j = 0; j < m; ++j) {
          grid[i][j] ^= 1;
        }
      }
    }
    int score = 0;
    for (int j = 0; j < m; ++j) {
      int bits = 0;
      for (int i = 0; i < n; ++i) {
        if (grid[i][j] == 1) {
          ++bits;
        }
      }
      score += max(bits, n - bits) * (1 << (m - j - 1));
    }
    return score;
  }
};
