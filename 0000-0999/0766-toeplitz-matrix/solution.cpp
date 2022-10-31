/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/toeplitz-matrix/
 * Runtime: 17ms (88.89%)
 */

class Solution {
public:
  bool isToeplitzMatrix(vector<vector<int>>& matrix) {
    unordered_map<int, int> diagonals;
    int n = matrix.size();
    int m = matrix[0].size();
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        auto it = diagonals.find(i - j);
        if (it != diagonals.end() && it->second != matrix[i][j]) {
          return false;
        }
        diagonals.emplace(i - j, matrix[i][j]);
      }
    }

    return true;
  }
};
