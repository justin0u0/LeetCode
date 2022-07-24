/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/search-a-2d-matrix-ii/
 * Runtime: 95ms
 */

class Solution {
public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int row = 0;
    int col = matrix[0].size() - 1;
    while (row < matrix.size() && col >= 0) {
      const int& val = matrix[row][col];
      if (val == target) {
        return true;
      }
      if (val < target) {
        ++row;
      } else {
        --col;
      }
    }

    return false;
  }
};
