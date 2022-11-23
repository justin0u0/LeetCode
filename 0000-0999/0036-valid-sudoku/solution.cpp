/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/valid-sudoku/
 * Runtime: 24ms (91.37%)
 */

class Solution {
public:
  bool isValidSudoku(vector<vector<char>>& board) {
    vector<vector<bool>> rows(9, vector<bool>(9, false));
    vector<vector<bool>> cols(9, vector<bool>(9, false));
    vector<vector<bool>> blocks(9, vector<bool>(9, false));
    for (int i = 0; i < 9; ++i) {
      for (int j = 0; j < 9; ++j) {
        if (board[i][j] != '.') {
          int cell = board[i][j] - '1';
          int b = (i / 3) * 3 + j / 3;
          if (rows[i][cell] || cols[j][cell] || blocks[b][cell]) {
            return false;
          }

          rows[i][cell] = true;
          cols[j][cell] = true;
          blocks[b][cell] = true;
        }
      }
    }

    return true;
  }
};
