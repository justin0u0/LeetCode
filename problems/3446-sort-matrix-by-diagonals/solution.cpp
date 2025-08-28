/**
 * Author: justin0u0<mail@justin0u0.com>
 * Problem: https://leetcode.com/problems/sort-matrix-by-diagonals/
 * Runtime: 2ms (94.03%)
 */

class Solution {
public:
  vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
    const int n = grid.size();

    for (int i = 0; i <= n; ++i) {
      vector<int> arr;
      for (int j = i; j < n; ++j) {
        arr.emplace_back(grid[j][j - i]);
      }
      sort(arr.begin(), arr.end(), greater<int>());
      for (int j = i; j < n; ++j) {
        grid[j][j - i] = arr[j - i];
      }
    }

    for (int i = 1; i <= n; ++i) {
      vector<int> arr;
      for (int j = 0; j + i < n; ++j) {
        arr.emplace_back(grid[j][j + i]);
      }
      sort(arr.begin(), arr.end());
      for (int j = 0; j + i < n; ++j) {
        grid[j][j + i] = arr[j];
      }
    }
    return grid;
  }
};
