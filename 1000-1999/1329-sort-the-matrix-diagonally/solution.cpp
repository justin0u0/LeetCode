/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/sort-the-matrix-diagonally/
 * Runtime: 11ms
 */

class Solution {
public:
  vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
    unordered_map<int, priority_queue<int, vector<int>, greater<int>>> box;
    int n = mat.size();
    int m = mat[0].size();
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        box[i - j].emplace(mat[i][j]);
      }
    }

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        mat[i][j] = box[i - j].top();
        box[i - j].pop();
      }
    }

    return mat;
  }
};
