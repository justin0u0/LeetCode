/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/game-of-life/
 * Runtime: 0ms
 */

class Solution {
public:
  void gameOfLife(vector<vector<int>>& board) {
    int n = (int)board.size();
    int m = (int)board[0].size();
    int di[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dj[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        for (int k = 0; k < 8; ++k) {
          int newi = i + di[k];
          int newj = j + dj[k];
          if (newi < 0 || newj < 0 || newi >= n || newj >= m) {
            continue;
          }

          int& val = board[newi][newj];
          if (board[i][j] > 0) {
            if (val <= 0) {
              --val;
            } else {
              ++val;
            }
          }
        }
      }
    }

    for (vector<int>& row : board) {
      for (int& val : row) {
        if (val == -3 || val == 3 || val == 4) {
          val = 1;
        } else {
          val = 0;
        }
      }
    }
  }
};
